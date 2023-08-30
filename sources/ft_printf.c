/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 05:15:07 by vde-frei          #+#    #+#             */
/*   Updated: 2023/08/30 01:47:00 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	get_element(const char *fmt, va_list ap);

int	ft_printf(const char *fmt, ...)
{
	int		len;
	va_list	ap;

	len = 0;
	if (fmt == NULL)
		return (0);
	va_start(ap, fmt);
	/* len = implement function to get element */
	/* implement function to print variables */
	va_end(ap);
	return (len);
}

static int	get_element(const char *fmt, va_list ap)
{
	/* I really need to rest now... cya... */
}
