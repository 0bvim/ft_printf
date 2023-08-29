/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 05:07:17 by vde-frei          #+#    #+#             */
/*   Updated: 2023/08/29 08:29:30 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* libs */
# include <sys/types.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libraries/libft/includes/libft.h"

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

/* structs */

typedef struct s_elements
{
	unsigned char	flags;
	int		width;
	int		precision;
	char		type;
}			t_element;

/* functions */
int	ft_printf(const char *form, ...);

/* aux functions */
int	ft_istype(char c);

#endif /* FT_PRINTF */
