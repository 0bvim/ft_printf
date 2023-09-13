/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei vde-frei@student.42sp.org.br      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 10:26:07 by vde-frei          #+#    #+#             */
/*   Updated: 2023/09/13 16:55:27 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void	print_nbr(char *str, int wlen, int *len, t_element *info)
{
	int	spaces;

	spaces = info->width - wlen;
	if (spaces > 0)
	{
		if (!(info->flags & MINUS))
			print_spaces(spaces, ' ');
		while (*str != '\0')
			*len += write(1, str++, 1);
		if (info->flags & MINUS)
			print_spaces(spaces, ' ');
		*len += spaces;
		return ;
		
	}
	while (*str != '\0')
		write (1, str++, 1);
	*len += wlen;
	return ;
}

unsigned char	ft_get_flags(char c)
{
	if (c == '-')
		return (MINUS);
	else if (c == '0')
		return (ZERO);
	else if (c == '+')
		return (PLUS);
	else if (c == ' ')
		return (SPACE);
	else
		return (HASH);
}
