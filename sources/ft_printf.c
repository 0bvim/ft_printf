/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 05:15:07 by vde-frei          #+#    #+#             */
/*   Updated: 2023/08/28 00:52:43 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *sym, ...)
{
	va_list	ap;
	int	len;
	char	*str;

	va_start(ap, sym);
	len = 0;
	str = NULL;
	while (*sym)
	{
		if (*sym == 37)
		{
			sym++;
			//create function to put sym
		}
	}
	return (0);
}
