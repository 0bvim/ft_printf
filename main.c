/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 02:33:48 by vde-frei          #+#    #+#             */
/*   Updated: 2023/08/31 02:33:48 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
//#include "../ft_printf/includes/ft_printf.h"
#include "./includes/ft_printf_bonus.h"

int	main(void)
{
	int	ft;
	int	stdio;
//	void	*ptr = (void *)1;
	ft_printf("ft_printf: ");
	ft = ft_printf(" %#x ", 0);	
	printf("X\n___printf: ");
	stdio = printf(" %#x ", 0);
	if (ft == stdio)
		printf("X\nSame return values.");
	else
	{
		printf("X\ndifference in return values.\n");
		printf("returned: %d\noriginal: %d\n", ft, stdio);
	}
	return (0);
}
