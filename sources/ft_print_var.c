/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_var.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 05:29:10 by vde-frei          #+#    #+#             */
/*   Updated: 2023/08/31 05:29:10 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_var(t_element *info, va_list ap, int *len, const char *fmt)
{
	if (info->type == 0x63)
	{
		ft_putchar(va_arg(ap, int));
	}
}
