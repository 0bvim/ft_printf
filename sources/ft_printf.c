/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 05:15:07 by vde-frei          #+#    #+#             */
/*   Updated: 2023/08/29 09:08:51 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	va_get(const char *fmt, va_list ap);
static void	get_element(const char **fmt, t_element *element, va_list ap);
static int	put_var(t_element element, va_list ap);
int	ft_printf(const char *fmt, ...)
{
	int		len;
	va_list	ap;

	len = 0;
	if (fmt == NULL)
		return (0);
	va_start(ap, fmt);
	len = va_get(fmt, ap);
	va_end(ap);
	return (len);
}

static int	va_get(const char *fmt, va_list ap)
{
	int			len;
	t_element	element;

	len = 0;
	while (*fmt != '\0')
	{
		if (*fmt == 0x25)
		{
			fmt++;
			element.flags = 0;
			element.width = 0;
			element.precision = -1;
			get_element(&fmt, &element, ap);
			len += put_var(element, ap);
		}
		else
		{
			write(1, fmt++, 1);
			len += 1;
		}
	}
	return (len);
}

static int	put_var(t_element element, va_list ap)
{
	int	len;

	len = 0;
}

static void	get_element(const char **fmt, t_element *element, va_list ap)
{
	while (!ft_istype(**fmt))
	{
		write(1, "YES\n", 5);
		(*fmt)++;
	}
	element->type = *(*fmt)++;
}

int	main(void)
{
	char	*str;

	str = "print this too";
	ft_printf("test %s!!! string !!!", str);
	return (0);
}
