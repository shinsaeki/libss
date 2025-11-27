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
