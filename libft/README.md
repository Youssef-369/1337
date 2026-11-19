*This project has been created as part of the 42 curriculum by yel-bour.*

# Libft

## Description

Libft is a C library that reimplements a collection of standard C library functions and adds useful string, memory, output, and linked-list utilities. The goal is to understand how common low-level functions work, practise dynamic memory management, and build reusable functions for later C projects.

The library is built as a static archive named `libft.a`. Its public declarations are collected in `libft.h`.

## Contents

### Part 1 — Libc functions

- **Character classification:** `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`
- **String length and character conversion:** `ft_strlen`, `ft_toupper`, `ft_tolower`
- **Memory operations:** `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`
- **String operations:** `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`
- **Conversion and allocation:** `ft_atoi`, `ft_calloc`, `ft_strdup`

### Part 2 — Additional functions

- **String construction and transformation:** `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`, `ft_strmapi`, `ft_striteri`
- **Output to a file descriptor:** `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`

### Part 3 — Linked lists

The library defines `t_list`, a singly linked-list node containing a `void *content` pointer and a `next` pointer.

- **Creation and insertion:** `ft_lstnew`, `ft_lstadd_front`, `ft_lstadd_back`
- **Traversal and inspection:** `ft_lstsize`, `ft_lstlast`, `ft_lstiter`, `ft_lstmap`
- **Deletion and cleanup:** `ft_lstdelone`, `ft_lstclear`

## Instructions

### Requirements

- A C compiler available as `cc`
- `make`
- `ar`, to create the static library

### Build the library

Run these commands from the repository root:

```sh
make
```

This creates `libft.a`.

Remove object files while keeping the library:

```sh
make clean
```

Remove object files and the library:

```sh
make fclean
```

Rebuild from scratch:

```sh
make re
```

### Use the library in another C program

Include the header in your source file:

```c
#include "libft.h"
```

Compile a program against the library from the repository root:

```sh
cc -Wall -Wextra -Werror main.c -I. -L. -lft -o program
```

Then run it:

```sh
./program
```

Replace `main.c` with your own source file. The `-I.` option lets the compiler find `libft.h`; `-L.` and `-lft` tell the linker to use `libft.a`.

## Technical notes

- The source files and `libft.h` belong at the root of the repository, as required by the project subject.
- The library is compiled with `-Wall -Wextra -Werror`.
- `make` builds the archive from object files and does not rebuild unchanged object files unnecessarily.
- Dynamically allocated strings, arrays, and linked-list content must be released by the caller or by the relevant cleanup function when no longer needed.

## Resources

- The **Libft subject (version 19.2)** provided by 42.
- The C library manual pages available on the development system, such as `man strlen`, `man memcpy`, `man memmove`, `man calloc`, and `man strdup`.
- The POSIX manual pages, especially `man 2 write`, for learning how
  system calls such as `write()` work.
- The [cppreference C language reference](https://en.cppreference.com/w/c)
  and compiler diagnostics from `cc -Wall -Wextra -Werror` to understand
  C concepts and identify compilation problems.

### Use of AI

AI assistance was used to discuss C concepts.
