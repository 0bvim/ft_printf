/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 05:15:07 by vde-frei          #+#    #+#             */
/*   Updated: 2023/08/29 02:12:34 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	int va_get(const char *fmt, va_list ap);

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int	len;

	len = 0;
	if (fmt == NULL)
		return (0);
	va_start(ap, fmt);
	len = va_get(fmt, ap);
	va_end(ap);
	return (len);
}

static	int va_get(const char *fmt, va_list ap)
{
	int	len;
	t_element	element;

	len = 0;
	while (*fmt != '\0')
	{
		if (*fmt == 0x25)
		{
			fmt++;
			//do function to get element.
		}
		fmt++;
	}
	return (len);
}

int	main()
{
	char	*str = "print this too";
	ft_printf("test %t!!! string !!!", str);
	return (0);
}
