/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 22:07:04 by vde-frei          #+#    #+#             */
/*   Updated: 2023/09/09 22:07:37 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

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
