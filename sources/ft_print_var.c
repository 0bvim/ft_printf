/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_var.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei vde-frei@student.42sp.org.br      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 10:27:09 by vde-frei          #+#    #+#             */
/*   Updated: 2023/08/31 10:27:09 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_var(t_element *info, va_list ap, int *len)
{
	if (info->type == 0x63)
		*len += ft_putchar(va_arg(ap, int)); 
	else if (info->type == 0x73)
		*len += ft_putstr(va_arg(ap, char *));
	else if (info->type == 0x64 || info->type == 0x69 || info->type == 0x75)
	{
		if (info->type == 0x75)
			ft_putnbr_base(va_arg(ap, unsigned int), len, "0123456789", 10);
		else
			ft_putnbr_base(va_arg(ap, int), len, "0123456789", 10);
	}
	else if (info->type == 0x78 || info->type == 0x58)
	{
		if (info->type == 0x78)
			ft_putnbr_base(va_arg(ap, unsigned int), len, "0123456789abcdef", 16);
		else
			ft_putnbr_base(va_arg(ap, unsigned int), len, "0123456789ABCDEF", 16);
	}
	else
		ft_putnbr_base(va_arg(ap, unsigned int), len, "01234567", 8);
}
