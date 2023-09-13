/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:53:55 by vde-frei          #+#    #+#             */
/*   Updated: 2023/09/13 11:55:57 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.c"

int	ft_putstr(char *str)
{
	if (str == NULL)
		return (write (STDOUT_FILENO, NULL_STR, ft_strlenb(NULL_STR)));
	return (write (STDOUT_FILENO, str, ft_strlenb(str)));
}
