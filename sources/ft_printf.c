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
#include <unistd.h>

static void	get_0x25(const char *fmt, int *len);

int	ft_printf(const char *fmt, ...)
{
	int		len;
	va_list	ap;

	len = 0;
	if (!fmt)
		return (0);
	va_start(ap, fmt);
	get_0x25(fmt, &len);	
	va_end(ap);
	return (len);
}

static void	get_0x25(const char *fmt, int *len)
{
	t_element	*info;

	if (!fmt)
		return ;
	while (*fmt != '\0')
	{
		if (*fmt == 0x25)
		{
			fmt++;
			info->type = *fmt;
			//implement another function to use va_arg and then another to print things
		}
		write(1, fmt, 1);
		fmt++;
		*len += 1;
	}
}
