/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 05:15:07 by vde-frei          #+#    #+#             */
/*   Updated: 2023/09/11 14:58:01 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

static void	get_0x25(const char *fmt, int *len, va_list ap);
static void	verify_flags(int *len, va_list ap, t_element *info,
				const char *fmt);

int	ft_printf(const char *fmt, ...)
{
	int		len;
	va_list	ap;

	len = 0;
	if (!fmt)
		return (0);
	va_start(ap, fmt);
	get_0x25(fmt, &len, ap);
	va_end(ap);
	return (len);
}

static void	get_0x25(const char *fmt, int *len, va_list ap)
{
	t_element	*info;

	info = malloc(sizeof(t_element));
	while (*fmt != '\0')
	{
		if (*fmt == 0x25)
		{
			fmt++;
			info->flags = 0;
			info->width = 0;
			info->precision = 0;
			verify_flags(len, ap, info, fmt);
			fmt++;
		}
		else if (fmt)
		{
			*len += write(STDOUT_FILENO, fmt, sizeof(char));
			fmt++;
		}
	}
	free(info);
}

static void	verify_flags(int *len, va_list ap, t_element *info, const char *fmt)
{
	while (!ft_istypeb(*fmt))
	{
		if (ft_isflagb(*fmt))
			info->flags |= ft_get_flags(*(fmt)++);
		else if (ft_isdigit(*fmt))
			element->width = ft_atoi(fmt);
	}
	info->type = *fmt;
	print_var(info, ap, len);
}
