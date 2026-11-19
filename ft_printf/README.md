*This project has been created as part of the 42 curriculum by yel-bour.*

# ft_printf

## Description

`ft_printf` is a C library that recreates the mandatory conversion behavior of
`printf`. It supports `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, and `%%`.
It returns the number of characters written, or `-1` when an output operation
or an unsupported/incomplete conversion fails.

## Instructions

Build the static library:

```sh
make
```

Clean object files:

```sh
make clean
```

Remove object files and the library:

```sh
make fclean
```

Rebuild:

```sh
make re
```

Link the library into a program:

```sh
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o test
```

## Supported conversions

| Conversion | Behavior |
| --- | --- |
| `%c` | Print one character |
| `%s` | Print a string; a null pointer is displayed as `(null)` |
| `%p` | Print a pointer in hexadecimal |
| `%d`, `%i` | Print a signed decimal integer |
| `%u` | Print an unsigned decimal integer |
| `%x` | Print lowercase hexadecimal |
| `%X` | Print uppercase hexadecimal |
| `%%` | Print a percent sign |

## Algorithm and data structures

The implementation scans the format string from left to right. Ordinary
characters are written directly. When it encounters `%`, it reads the next
character and dispatches to the matching conversion function. A `va_list`
provides each argument in sequence.

Each conversion routine writes its result directly with `write()` and returns
the number of characters written. The main routine accumulates these counts.
The integer and hexadecimal routines use recursive digit output: they first
print the higher-order digits, then the final digit. Signed integer output
converts the input to `long` before taking its magnitude, which safely handles
`INT_MIN` on the target platform. The hexadecimal output helper accepts an
unsigned long long, allowing it to serve both `%x`/`%X` and pointer output.

## Resources and AI usage

Resources:
- The `printf(3)` manual page.
- The `stdarg(3)` manual page.
- The `write(2)` manual page.
- The C language documentation for variadic functions.

AI was used as a learning and debugging aid to review project structure,
explain variadic arguments and formatting behavior, and identify build and
linking issues. The implementation should be reviewed, tested, and understood
by the student before evaluation.
