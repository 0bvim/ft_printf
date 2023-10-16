/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:44:30 by vde-frei          #+#    #+#             */
/*   Updated: 2023/10/16 15:10:58 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_atoi(const char **fmt)
{
	int	number;

	number = 0;
	while (is_digitb(**fmt))
		number = (number * 10) + (*(*fmt)++ - '0');
	return (number);
}
