/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_var_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei vde-frei@student.42sp.org.br      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 10:27:09 by vde-frei          #+#    #+#             */
/*   Updated: 2023/09/13 19:09:45 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void	print_varb(t_element *info, va_list ap, int *len)
{
	if (info->type == 0x63)
		*len += ft_putcharb(va_arg(ap, int), info);
	else if (info->type == 0x25)
		*len += write(STDOUT_FILENO, "%", sizeof(char));
	else if (info->type == 0x73)
		*len += ft_putstrb(va_arg(ap, char *), info);
	else if (info->type == 0x64 || info->type == 0x69 || info->type == 0x75)
	{
		if (info->type == 0x75)
			ft_putnbr_baseb(va_arg(ap, unsigned int), len, DEC_BASE, info);
		else
			ft_putnbrb(va_arg(ap, int), len, info);
	}
	else if (info->type == 0x78)
		ft_putnbr_baseb(va_arg(ap, unsigned int), len, HEX_LW, info);
	else if (info->type == 0x58)
		ft_putnbr_baseb(va_arg(ap, unsigned int), len, HEX_UP, info);
	else if (info->type == 0x70 || info->flags == HASH)
		ft_put_pointerb(va_arg(ap, void *), info, len);
}
