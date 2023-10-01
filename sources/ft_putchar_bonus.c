/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:36:44 by vde-frei          #+#    #+#             */
/*   Updated: 2023/09/24 06:06:34 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

int	ft_putcharb(char c, t_element *info)
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

void	print_spaces(int spaces, char c)
{
	while (spaces--)
		write(1, &c, 1);
}
