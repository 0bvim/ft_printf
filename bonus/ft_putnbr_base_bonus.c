/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 22:07:04 by vde-frei          #+#    #+#             */
/*   Updated: 2023/09/13 16:15:24 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

static int	len_base_nbr(size_t nbr, int base_len, t_element *info);
static char	*putnbr_base(size_t nb, int len, char *base, t_element *info);

void	ft_putnbr_base(unsigned long nbr, int *len, char *base, t_element *info)
{
	int	base_len;
	int	lenght;
	char	*str;

	base_len = ft_strlenb(base);
	lenght = len_base_nbr(nbr, base_len, info);
	str = putnbr_base(nbr, lenght, base, info);
	if (str == NULL)
		return ;
	print_nbr(str, lenght, len, info);
	free(str);
}

static char	*putnbr_base(size_t nb, int len, char *base, t_element *info)
{
	return ("");
}

static int	len_base_nbr(size_t nbr, int base_len, t_element *info)
{
	return (0);
}
