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

int	ft_putchar(char c)
{
	return (write(STDOUT_FILENO, &c, sizeof(char)));
}

int	ft_putstr(char *str)
{
	return (write (STDOUT_FILENO, str, ft_strlen(str)));
}

void	ft_putnbr(long long int number, int *len)
{
	if (number < 0)
	{
		*len += write(STDOUT_FILENO, "-", sizeof(char));
		number *= -1;
	}
	if (number >= 10)
	{
		ft_putnbr(number / 10, len);
		ft_putnbr(number % 10, len);
	}
	else
		*len += ft_putchar(number + '0');
}

void	ft_put_u_nbr(unsigned long int number, int *len)
{
	if (number >= 10)
	{
		ft_putnbr(number / 10, len);
		ft_putnbr(number % 10, len);
	}
	else
		*len += ft_putchar(number + '0');
}
