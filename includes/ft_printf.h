/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 05:07:17 by vde-frei          #+#    #+#             */
/*   Updated: 2023/10/16 16:54:12 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* libs */
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

/* defines */
# define HEX_LW "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"
# define DEC_BASE "0123456789"
# define NULL_PTR "(nil)"
# define NULL_STR "(null)"

# define HEX_L_PREFIX "0x"
# define HEX_U_PREFIX "0X"
# define OCT_PREFIX "0"

# define LONG_MAX_ 9223372036854775807L
# define LONG_MIN_ -9223372036854775808
# define LLONG_MAX_ 18446744073709551615U

/* masks to try bitmask/wise operators */
# define MINUS 0b000001
# define ZERO 0b000010
# define PLUS 0b010000
# define SPACE 0b001000
# define HASH 0b000100

/* my types */
typedef unsigned long long int	t_large;
/* structs */

typedef struct s_elements
{
	unsigned char				flags;
	int							width;
	int							precision;
	char						type;
}								t_element;

/* main function */
int								ft_printf(const char *form, ...);

/* flag and aux functions */
unsigned char					ft_get_flags(char c);
size_t							ft_strlenb(char *str);
int								ft_istypeb(char c);
int								is_digitb(int c);
int								ft_isflagb(char f);
int								ft_strncmp(const char *s1, const char *s2,
									size_t n);
int								ft_atoi(const char **fmt);
void							ft_strcpy(char *dest, char *source, int len);

/* print functions */
void							print_varb(t_element *info, va_list ap,
									int *len);
int								ft_putstrb(char *str, t_element *info);
int								ft_putcharb(char c, t_element *info);
void							ft_putnbr_baseb(unsigned long nbr, int *len,
									char *base, t_element *info);
void							ft_put_pointerb(void *ptr, t_element *info,
									int *len);
void							print_bonus(t_element *info, va_list ap,
									int *len, const char *fmt);
void							print_nbr(char *str, int wlen, int *len,
									t_element *info);
void							ft_putnbrb(int nbr, int *len, t_element *info);
void							print_spaces(int spaces, char c);

#endif /* FT_PRINTF */
