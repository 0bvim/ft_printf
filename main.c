/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 02:33:48 by vde-frei          #+#    #+#             */
/*   Updated: 2023/09/14 12:31:50 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf_bonus.h"
#include <limits.h>
#include <stdio.h>

int	main(void)
{
	int	ft;
	int	stdio;
	int	a;

	a = 8;
	//	void	*ptr = (void *)1;
	ft_printf("ft_printf: ");
	ft = ft_printf("%3.4d\n", 1);
	printf("\n___printf: ");
	stdio = printf("%3.4d\n", 1);
	if (ft == stdio)
		printf("X\nSame return (values.");
	else
	{
		printf("X\ndifference in return (values.\n");
		printf("returned: %d\noriginal: %d\n", ft, stdio);
	}
	return (0);
}
