/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:53:55 by vde-frei          #+#    #+#             */
/*   Updated: 2023/09/13 19:05:34 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

static int	ft_putstr_spc(char *str, int len, int spaces, t_element *info);

int	ft_putstrb(char *str, t_element *info)
{
	int		len;
	int		spaces;
	char	*doppel;

	doppel = str;
	if (str == NULL)
	{
		if (info->precision != -1 && info->precision < 6)
			doppel = "";
		else
			doppel = NULL_STR;
	}
	len = ft_strlenb(doppel);
	if (info->precision != -1 && info->precision < len)
		len = info->precision;
	spaces = info->width - len;
	if (spaces > 0)
		return (ft_putstr_spc(doppel, len, spaces, info));
	write(1, doppel, len);
	return (len);
}

static int	ft_putstr_spc(char *str, int len, int spaces, t_element *info)
{
	if (!(info->flags & MINUS))
		print_spaces(spaces, ' ');
	write(1, str, len);
	if (info->flags & MINUS)
		print_spaces(spaces, ' ');
	return (info->width);
}
