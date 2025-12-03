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
```c
ss_itoa(42)      → "42"
ss_itoa(-123)    → "-123"
ss_itoa(0)       → "0"
ss_itoa(-2147483648) → "-2147483648"
```
