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

#include "../includes/ft_printf_bonus.h"

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

void	ft_putnbr_base(long nbr, int *len, char *base, int nbase)
{
	if (nbr < 0)
	{
		nbr *= -1;
		*len += write(STDOUT_FILENO, "-", sizeof(char));
	}
	if (nbr < nbase)
	{
		*len += ft_putchar(base[nbr]);
	}
	else
	{
		ft_putnbr_base(nbr / nbase, len, base, nbase);
		ft_putnbr_base(nbr % nbase, len, base, nbase);
	}
}

void	ft_put_pointer(size_t ptr, int *len, char *base, int nbase)
{
	if (!ptr || ptr == 0)
	{
		*len += ft_putstr(NULL_PTR);
		return ;
	}
	*len += ft_putstr(HEX_L_PREFIX);
	if (ptr < (size_t)nbase)
	{
		*len += ft_putchar(base[ptr]);
	}
	else
	{
		ft_putnbr_base(ptr / nbase, len, base, nbase);
		ft_putnbr_base(ptr % nbase, len, base, nbase);
	}
}
