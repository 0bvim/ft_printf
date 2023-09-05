/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 07:52:32 by vde-frei          #+#    #+#             */
/*   Updated: 2023/09/04 13:31:47 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

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

int	ft_is_bonus(char f)
{
	if (f == 0x23 || f == 0x2B || f == 0x2D || f == 0x2E || f == 0x30
		|| f == 0x20)
		return (1);
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	if (n != 0)
	{
		while (s1[index] && (s1[index] == s2[index]) && index < n - 1)
			index++;
		return ((unsigned char)s1[index] - (unsigned char)s2[index]);
	}
	return (0);
}
