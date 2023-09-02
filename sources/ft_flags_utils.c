/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 07:52:32 by vde-frei          #+#    #+#             */
/*   Updated: 2023/08/29 08:27:40 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_istype(char c)
{
	if (c == 0x58 || c == 0x63 || c == 0x64 || c == 0x69 || c == 0x70
		|| c == 0x73 || c == 0x75 || c == 0x78 || c == 0x25)
		return (1);
	return (0);
}

int	is_digit(int c)
{
	return (c >= 0x30 && c <= 0x39);
}

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}
