/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 05:07:17 by vde-frei          #+#    #+#             */
/*   Updated: 2023/09/07 09:18:21 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

/* libs */
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define TRUE liam
/* defines */
# define HEX_LW "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"
# define OCT_BASE "01234567"
# define DEC_BASE "0123456789"
# define NULL_PTR "(nil)"
# define NULL_STR "(null)"

# define HEX_L_PREFIX "0x"
# define HEX_U_PREFIX "0X"
# define OCT_PREFIX "0"

# define LONG_MAX_ 9223372036854775807
# define LONG_MIN_ 9223372036854775808
# define UINT_MAX_ 4294967295

/* masks to try bitmask/wise operators */
# define MINUS 0b000001
# define ZERO 0b000010
# define HASH 0b000100
# define SPACE 0b001000
# define PLUS 0b010000

/* my types */
typedef unsigned long long int	t_large;
/* structs */

typedef struct s_elements
{
	unsigned char	flags;
	int				width;
	int				precision;
	char			type;
}					t_element;

/* main function */
int					ft_printf(const char *form, ...);

/* flag and aux functions */
size_t				ft_strlen(char *str);
int					ft_istype(char c);
int					is_digit(int c);
int					ft_is_bonus(char f);
int					ft_strncmp(const char *s1,
						const char *s2, size_t n);

/* print functions */
void				print_var(t_element *info, va_list ap, int *len);
int					ft_putstr(char *str);
int					ft_putchar(char c);
void				ft_putnbr_base(long nbr, int *len, char *base, int nbase);
void				ft_put_pointer(t_large ptr, int *len, char *base,
						int nbase);
void				print_bonus(t_element *info, va_list ap, int *len,
						const char *fmt);

#endif /* FT_PRINTF */
