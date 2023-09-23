/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:45:22 by vde-frei          #+#    #+#             */
/*   Updated: 2023/09/14 12:35:31 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

static void	putnbr(long nbr, int len, char *str, t_element *info);
static int	len_number(int nbr, t_element *info);

void	ft_putnbrb(int nbr, int *len, t_element *info)
{
	int		len_s;
	char	*str;

	len_s = len_number(nbr, info);
	str = malloc((len_s + 1) * sizeof(char));
	if (str == NULL)
		return ;
	putnbr(nbr, len_s, str, info);
	print_nbr(str, len_s, len, info);
	free(str);
}

static void	putnbr(long nbr, int len, char *str, t_element *info)
{
	int	min_len;

	min_len = (nbr < 0 || info->flags & (PLUS | SPACE));
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	else if (info->flags & PLUS)
		str[0] = '+';
	else if (info->flags & SPACE)
		str[0] = ' ';
	str[len] = '\0';
	while (min_len < len)
	{
		str[--len] = DEC_BASE[nbr % 10];
		nbr /= 10;
	}
}

static int	len_number(int nbr, t_element *info)
{
	int	len;
	int	neg;

	if (nbr == 0 && info->precision == 0)
		return (0);
	len = 0;
	neg = nbr < 0;
	if (neg || info->flags & (SPACE | PLUS))
		len++;
	if (nbr == 0)
		len++;
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	if (info->precision >= len)
		return (info->precision + (neg || info->flags & (SPACE & PLUS)));
	if (info->precision == -1 && !(info->flags & MINUS) && (info->flags & ZERO)
		&& info->width > len)
		return (info->width);
	return (len);
}
