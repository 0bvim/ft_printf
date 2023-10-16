![ft_printf](../../../42-project-badges/blob/main/covers/cover-ft_printf-bonus.png)
# ft_printf

### The goal of this project is recode printf(). Here I learn mainly about using a variadic arguments.

## HOW USE IT?
> First, clone repository with your the way you prefer
```bash
$ gh repo clone vinicius-f-pereira/ft_printf
```
`or`
```
$ git clone git@github.com:vinicius-f-pereira/ft_printf.git
```
`or`
```
$ git clone https://github.com/vinicius-f-pereira/ft_printf.git
```
### Now you need to build libftprintf.a
```bash
$ cd ft_printf
$ make```
`or`
```bash
make bonus
```

### You need of a `main.c` file with path do header and compile it with static library
> The recipe to compile executable
```bash
$ cc main.c libftprintf.a -Iincludes -o ft_printf
$ ./ft_printf
```

> Here's a boilerplate of a `main.c`
```c
#include "ft_printf.h"
/* #include "ft_printf_bonus.h" */

/**
 * This header is to use if you compile bonus (make bonus)
 * After do this project I let mandatory and bonus part handling specifiers and flags
 * so you'll not 'see' difference between both.
 * But, mandatory handle only specifiers below, and bonus handle some flags too.
 * to know more about specifiers, RTFM!!!
 */

int  main(void)
{
  ft_printf("You can use it with following flags:\
      \n%c: print character \
		  \n%s: print string \
		  \n%d: print signed numbers \
		  \n%i: print signed numbers \
		  \n%u: print unsigned numbers\
		  \n%x: print hexadecimal lower case \
		  \n%X: print hexadecimal upper case \
		  \n%p: print pointer address\n", 'a', "string", -1, 0, 1, 1020, 2030, "address");
  return (0); 
}
```
