# libss
libss is a lightweight, educational C library that re-implements core parts of the C standard library (libc) — including string utilities, memory operations, and character helpers — from scratch. The project focuses on clarity, portability, and understanding how low-level routines actually work beneath libc.

This project is created and maintained by **Shintaro Saeki**, primarily for:
- Understanding low-level libc internals
- System programming practice
- Embedded or freestanding development environments
- Anyone who wants to know "what is really happening under the hood"

## Features
- Implemented **only in pure ANSI C (C89/C99)** — no external dependencies
- Re-implements key parts of libc:
  - `strlen`, `strcmp`, `strcpy`, …
  - `memset`, `memcpy`, `memmove`
  - `isdigit`, `isalpha`, `toupper`…
- Clean, minimal, readable implementation
- Optional unit tests (CUnit)
- Builds into a static library: `libss.a`
- Simple & modular folder structure

## Project Structure
```
libss/
│
├── include/
│   └── libss.h
│
├── src/
│   ├── strlen.c
│   ├── strcpy.c
│   ├── strcmp.c
│   ├── strchr.c
│   ├── memset.c
│   ├── memcpy.c
│   ├── memmove.c
│   ├── isalpha.c
│   ├── isdigit.c
│   └── …
│
├── tests/
│   └── test_libss.c
│
├── Makefile
└── README.md
```

## Additional Functions
The additional functions are a collection of higher-level utilities that extend the basic features of the C standard library.  
They include string manipulation (substring, join, trim, split), memory allocation helpers, character mapping functions, and tools for converting or duplicating data.  
These functions are not direct re-implementations of libc, but provide convenient operations built on top of your base library, enabling more expressive and practical use of strings and memory in C programming.

### **`ss_substr`**

**Prototype**
```c
char *ss_substr(char const *s, unsigned int start, size_t len);
```

**Parameters**
- `s`  
  The original string from which the substring will be created.
- `start`  
  The starting index of the substring within `s`.
- `len`  
  The maximum length of the substring to be allocated.

**Return value**
- A newly allocated substring.
- `NULL` if the allocation fails.

**External functions**
- `malloc`

**Description**  
Allocates (with `malloc`) and returns a substring from the string `s`.  
The substring begins at index `start` and has a maximum size of `len`.

If `start` is greater than or equal to the length of `s`, an empty string (`""`) is returned.  
If `len` exceeds the remaining characters in `s`, only the available portion is copied.

### **`ss_strjoin`**

**Prototype**
```c
char *ss_strjoin(char const *s1, char const *s2);
```

**Parameters**
- `s1`  
  The prefix string.
- `s2`  
  The suffix string.

**Return value**
- The newly allocated string resulting from the concatenation of `s1` and `s2`.
- `NULL` if the memory allocation fails.

**External functions**
- `malloc`

**Description**  
Allocates (using `malloc`) and returns a new string, which is the result of the concatenation of `s1` and `s2`.

The new string consists of all characters of `s1` followed by all characters of `s2`.  
Both input strings must be valid null-terminated strings.  
If allocation fails, `NULL` is returned.

### **`ss_strtrim`**

**Prototype**
```c
char *ss_strtrim(char const *s1, char const *set);
```

**Parameters**
- `s1`  
  The string to be trimmed.

- `set`  
  The set of characters to remove from both the beginning and the end of `s1`.

**Return value**
- The newly allocated trimmed string.
- `NULL` if the memory allocation fails.

**External functions**
- `malloc`

**Description**  
Allocates (using `malloc`) and returns a copy of the string `s1`,  
with all characters appearing in the set `set` removed from both the start and the end of the string.

Characters in `set` are removed **repeatedly** from the beginning and the end until a character not in `set` is encountered.

If `s1` consists entirely of characters from `set`, an empty string (`""`) is returned.

### **`ss_split`**

**Prototype**
```c
char **ss_split(char const *s, char c);
```

**Parameters**
- `s`  
  The string to be split.

- `c`  
  The delimiter character used to split the string.

**Return value**
- A dynamically allocated **NULL-terminated array of strings**,  
  where each element is one of the substrings obtained by splitting `s` at occurrences of `c`.
- `NULL` if memory allocation fails.

**External functions**
- `malloc`  
- `free`

**Description**  
`ss_split` splits the string `s` into separate substrings using the delimiter `c`.  
Each substring is newly allocated with `malloc`, and the result is returned as a  
`NULL`-terminated array of pointers.

Consecutive delimiters are treated as a single separator.  
If `s` begins or ends with the delimiter, the resulting array **does not contain empty strings** at those positions.

Example: splitting `"  hello world  "` by `' '` results in:
```
["hello", "world", NULL]
```

The caller is responsible for freeing each allocated substring and the array itself.

### **`ss_itoa`**

**Prototype**
```c
char *ss_itoa(int n);
```

**Parameters**
- `n`  
  The integer value to convert into a string.

**Return value**
- A newly allocated string representing the integer `n`.
- `NULL` if memory allocation fails.

**External functions**
- `malloc`

**Description**  
`ss_itoa` converts the integer `n` into its textual representation and  
returns the result as a newly allocated null-terminated string.

The function handles:

- Positive numbers  
- Negative numbers  
- Zero  
- The minimum integer value (`INT_MIN`)  

Memory for the resulting string is allocated using `malloc`.  
The caller is responsible for freeing the returned string.

**Example**
```
ss_itoa(42)      → "42"
ss_itoa(-123)    → "-123"
ss_itoa(0)       → "0"
ss_itoa(-2147483648) → "-2147483648"
```
### **`ss_strmapi`**

**Prototype**
```c
char *ss_strmapi(char const *s, char (*f)(unsigned int, char));
```

**Parameters**
- `s`  
  The string on which to iterate.

- `f`  
  A function that takes:
  - the index of the character (`unsigned int`)
  - the character itself (`char`)
  
  and returns a new character.

**Return value**
- The newly allocated string resulting from the successive applications of `f`.
- `NULL` if memory allocation fails or if either argument is `NULL`.

**External functions**
- `malloc`

**Description**  
`ss_strmapi` applies the function `f` to every character of the string `s`.  
The index of each character is passed as the first argument to `f`,  
and the character itself as the second.

The result is a new string (allocated with `malloc`) in which each character  
is the value returned by `f` for the corresponding position in `s`.

This function does **not modify the original string**.  
It creates a transformed copy.

**Example**
```
char to_upper_even(unsigned int i, char c)
{
    if (i % 2 == 0)
        return ss_toupper(c);  // your library's toupper
    return c;
}

char *result = ss_strmapi("abcdef", to_upper_even);
// result -> "AbCdEf"
free(result);
```
### **`ss_striteri`**

**Prototype**
```c
void ss_striteri(char *s, void (*f)(unsigned int, char *));
```

**Parameters**
- `s`  
  The string on which to iterate.

- `f`  
  The function to apply to each character of `s`.  
  The function receives:
  - the character index (`unsigned int`)
  - a pointer to the character (`char *`), allowing in-place modification.

**Return value**
- None

**External functions**
- None

**Description**  
`ss_striteri` applies the function `f` to every character of the string `s`.

Unlike `ss_strmapi`, which **returns a new string**,  
`ss_striteri` modifies the string **in place**.

For each iteration:
- the current index is passed as the first argument  
- the address of the current character (`char *`) is passed as the second argument  
so that the callback can modify the string directly.

If `s` or `f` is `NULL`, the function does nothing.

**Example**
```
void to_upper_even(unsigned int i, char *c)
{
    if (i % 2 == 0)
        *c = ss_toupper(*c);  // modify original string
}

char str[] = "abcdef";
ss_striteri(str, to_upper_even);
// str → "AbCdEf"
```
### **`ss_putchar_fd`**

**Prototype**
```c
void ss_putchar_fd(char c, int fd);
```

**Parameters**
- `c`  
  The character to output.

- `fd`  
  The file descriptor on which to write.

**Return value**
- None

**External functions**
- `write`

**Description**  
`ss_putchar_fd` writes the character `c` to the file descriptor `fd`.

This function is typically used to print characters to standard output (`fd = 1`), standard error (`fd = 2`), or a file descriptor returned by `open()`.

If an invalid file descriptor is provided, the behavior is undefined (same as `write`).

**Example**
```c
ss_putchar_fd('A', 1);  // prints 'A' to stdout
```

### **`ss_putstr_fd`**

**Prototype**
```c
void ss_putstr_fd(char *s, int fd);
```

**Parameters**
- `s`  
  The string to output.

- `fd`  
  The file descriptor on which to write.

**Return value**
- None

**External functions**
- `write`

**Description**  
`ss_putstr_fd` outputs the string `s` to the file descriptor `fd`.

This function writes characters exactly as they appear in the string,  
stopping at the first null terminator (`'\0'`).  
No additional characters (such as newline) are added automatically.

If `s` is `NULL`, the function does nothing.

Common file descriptors:
- `1` → standard output (stdout)
- `2` → standard error (stderr)

**Example**
```c
ss_putstr_fd("Hello", 1);  // prints "Hello" to stdout
ss_putstr_fd("Error!", 2); // prints "Error!" to stderr
```
### **`ss_putendl_fd`**

**Prototype**
```c
void ss_putendl_fd(char *s, int fd);
```

**Parameters**
- `s`  
  The string to output.

- `fd`  
  The file descriptor on which to write.

**Return value**  
- None

**External functions**  
- `write`

**Description**  
`ss_putendl_fd` writes the string `s` to the given file descriptor `fd`,  
followed by a newline character (`'\n'`).

If `s` is `NULL`, the function does nothing (same behavior as many libft implementations).

**Example**
```c
ss_putendl_fd("Hello", 1);  // Output: Hello\n to stdout
ss_putendl_fd("Error!", 2); // Output: Error!\n to stderr
```


## Linked List Functions

The linked list functions form a collection of essential utilities for creating and manipulating singly linked lists.
They provide a lightweight data structure that stores sequences of dynamically allocated nodes, each containing a content pointer and a reference to the next element.

These functions allow you to create nodes, add them to the front or back of a list, traverse or transform the list, delete individual nodes, or clear an entire list safely.
They are not part of the standard C library, but they offer foundational data-structure capability that supports more advanced programming patterns such as stacks, queues, and iterator-style processing.

The linked-list utilities enable:
- simple creation of new nodes
- insertion at either the head or tail of a list
- iteration with user-defined callbacks
- deletion of nodes or entire lists with safe memory management
- transformation of lists into new lists via mapping functions

Together, these provide a minimal yet powerful toolkit for working with dynamic sequences of data in C.

