/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 05:07:17 by vde-frei          #+#    #+#             */
/*   Updated: 2023/09/14 15:10:18 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/**
 * libs used in this project
 * stdarg.h to use va_list and 'va_macros'
 * stdlib to use malloc and free in my struct
 * unistd.h to use write function
 */
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

/**
 * defines to make code more readable
 * and in to use less columns when write a code
 */
# define HEX_LW "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"
# define OCT_BASE "01234567"
# define DEC_BASE "0123456789"
# define NULL_PTR "(nil)"
# define NULL_STR "(null)"
# define HEX_L_PREFIX "0x"
# define HEX_U_PREFIX "0X"
# define OCT_PREFIX "0"

/**
 * struct to keep arguments and use 
 * throught functions.
 * This struct are fully used in bonus part
 * in mandatory part I use only 'type' variable.
 */

typedef struct s_elements
{
	unsigned char	flags;
	int				width;
	int				precision;
	char			type;
}					t_element;

/**
 * main function prototype
 * You can learn more how it works
 * reading about variadic functions and
 * man stdarg.h
 */
int					ft_printf(const char *form, ...);

/* flag and aux functions */
/**
 * @brief Count lenght of a string (Does not count NULL byte ('\0'))
 * @param a string (char *)
 * @return lenght of a string/num of bytes.
 * @note size_t is used as a return because
 * does not exist a negative string.
 */
size_t				ft_strlen(char *str);
/**
 * @brief Verify if is one of the following type:
 * @param c Type to be verified.
 * @param 'c' - Character.
 * @param 's' - String.
 * @param 'd' - Interger.
 * @param 'i' - Interger.
 * @param 'u' - Unsigned Interger.
 * @param 'p' - Abstract type (void *) "man void".
 * @param 'x' - Hexadecimal lower case.
 * @param 'X' - Hexadecimal upper case.
 * @param '%' - Check if is another '%' signal after a '%' signal.
 * @return Return True if is a type and False if not. (1 or 0).
 */
int					ft_istype(char c);
/**
 * @brief Verify if is a digit between '0' and '9'.
 * @param c to verify. It only verify ascii numbers.
 * @return Return True if is a type and False if not. (1 or 0).
 */
int					is_digit(int c);

/* print functions */
/**
 * @brief Print argument in STDOUT.
 * @param *info Pointer to a struct.
 * @param ap A pointer to a argument list (man stdargs.h)
 * @param *len A pointer to a interger.
 * @return Void Check specifier, format, print and count printed bytes.
 */
void				print_var(t_element *info, va_list ap, int *len);
/**
 * @brief Print a string in STDOUT.
 * @param *str A string.
 * @return Number of bytes printed.
 */
int					ft_putstr(char *str);
/**
 * @brief Print a character in STDOUT.
 * @param c A character.
 * @return Number of byte printed.
 */
int					ft_putchar(char c);
/**
 * @brief Receive number, base and print number according with the base.
 * @param nbr Number to format and print.
 * @param *len Point to a variable to count printed bytes.
 * @param *base Base to be converted.
 * @param nbase Lenght of base.
 * @return Number of byte printed in selected base.
 */
void				ft_putnbr_base(long nbr, int *len, char *base, int nbase);
/**
 * @brief Receive number, base and print in lower hexadecimal.
 * @param ptr Number to format and print.
 * @param *len Point to a variable to count printed bytes.
 * @param *base Base to be converted.
 * @param nbase Lenght of base.
 * @return Number of byte printed in selected base and print in hexadecimal lower case.
 */
void				ft_put_pointer(size_t ptr, int *len, char *base, int nbase);

#endif /* FT_PRINTF */
