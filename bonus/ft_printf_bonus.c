/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 05:15:07 by vde-frei          #+#    #+#             */
/*   Updated: 2023/09/04 13:41:57 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

static void	get_0x25(const char *fmt, int *len, va_list ap);
static void	verify_flags(int *len, va_list ap, t_element *info, const char *fmt);

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

	if (!fmt)
		return ;
	info = malloc(sizeof(t_element));
	while (*fmt != '\0')
	{
		if (*fmt == 0x25)
		{
			fmt++;
			info->flags = 0;
			info->width = 0;
			info->precision = 0;
			info->type = *fmt;
			verify_flags(len, ap, info, fmt);
			fmt++;
			if (ft_is_bonus(info->type))
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
	if (ft_istype(info->type))
	{
		print_var(info, ap, len);
	}
	else if (ft_is_bonus(info->type))
	{
		if (info->type == '#')
		{
			fmt++;
			print_bonus(info, ap, len, fmt);
			fmt++;
		}
	}
}
