/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei vde-frei@student.42sp.org.br      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 10:26:07 by vde-frei          #+#    #+#             */
/*   Updated: 2023/09/13 11:14:41 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

int	ft_putchar(char c, t_element *info)
{
	int	spaces;

	spaces = info->width - 1;
	if (spaces > 0)
	{
		if (!(info->flags & MINUS))
			print_spaces(spaces, ' ');
		else if (info->flags & ZERO)
			print_spaces(spaces, '0');
		write(STDOUT_FILENO, &c, sizeof(char));
		if (info->flags & MINUS)
			print_spaces(spaces, ' ');
		return (info->width);
	}
	return (write(STDOUT_FILENO, &c, sizeof(char)));
}

int	ft_putstr(char *str)
{
	if (str == NULL)
		return (write (STDOUT_FILENO, NULL_STR, ft_strlenb(NULL_STR)));
	return (write (STDOUT_FILENO, str, ft_strlenb(str)));
}

void	print_nbr(char *str, int wlen, int *len, t_element *info)
{
	int	spaces;

	spaces = info->width - wlen;
	if (spaces > 0)
	{
		if (!(info->flags & MINUS))
			print_spaces(spaces, ' ');
		while (*str != '\0')
			*len += write(1, str++, 1);
		if (info->flags & MINUS)
			print_spaces(spaces, ' ');
		*len += spaces;
		return ;
		
	}
	while (*str != '\0')
		write (1, str++, 1);
	*len += wlen;
	return ;
}

void	ft_put_pointer(t_large ptr, int *len, char *base, int nbase)
{
	if (ptr == 0)
	{
		*len += ft_putstr(NULL_PTR);
		return ;
	}
	if (ptr - 1 > LONG_MAX_)
	{
		if (ptr != LLONG_MAX_)
		{
			*len += write(STDOUT_FILENO, "0", sizeof(char));
			return ;
		}
	}
	if (ft_strncmp(base, HEX_LW, ft_strlenb(base)) == 0 && ptr != 0)
		*len += ft_putstr(HEX_L_PREFIX);
	else if (ptr != 0)
		*len += ft_putstr(HEX_U_PREFIX);
	if (ptr < (size_t)nbase)
		*len += ft_putstr(&base[ptr]);
	else
	{
		ft_putnbr_base(ptr / nbase, len, base, nbase);
		ft_putnbr_base(ptr % nbase, len, base, nbase);
	}
}

unsigned char	ft_get_flags(char c)
{
	if (c == '-')
		return (MINUS);
	else if (c == '0')
		return (ZERO);
	else if (c == '+')
		return (PLUS);
	else if (c == ' ')
		return (SPACE);
	else
		return (HASH);
}
