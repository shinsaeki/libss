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

