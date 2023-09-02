/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei vde-frei@student.42sp.org.br      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 10:26:07 by vde-frei          #+#    #+#             */
/*   Updated: 2023/08/31 10:26:07 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int	ft_putchar(char c)
{
	return (write(STDOUT_FILENO, &c, sizeof(char)));
}

int	ft_putstr(char *str)
{
	if (str == NULL)
		return (write (STDOUT_FILENO, NULL_STR, ft_strlen(NULL_STR)));
	return (write (STDOUT_FILENO, str, ft_strlen(str)));
}

void	ft_putnbr_base(long int number, int *len, char *base, int nbase)
{
//	printf("\nlen: %d", *len);
	if (number < 0)
	{
		number *= -1;
		*len += write(STDOUT_FILENO, "-", sizeof(char));
	}
	if (number < nbase)
	{
		*len += ft_putchar(base[number]);
	}
	else
	{
		ft_putnbr_base(number / nbase, len, base, nbase);
		ft_putnbr_base(number % nbase, len, base, nbase);
	}
}
