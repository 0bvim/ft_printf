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

void	print_var(t_element *info, va_list ap, int *len, const char *fmt)
{
	if (info->type == 0x63)
	{
		ft_putchar(va_arg(ap, int));
	}
	else if (info->type == 0x73)
	{
		ft_putstr(va_arg(ap, char *));
	}
	else if (info->type == 0x64 || info->type == 0x69)
	{
		ft_putnbr(va_arg(ap, int));
	}
}
