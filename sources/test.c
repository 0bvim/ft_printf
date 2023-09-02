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

#include <stdio.h>
#include "../includes/ft_printf.h"

int	main(void)
{
	int	ft;
	int	stdio;
//	printf("\n");
//	ft_printf("%X", 11);
//	printf("\n");
//	int nbr = printf("%X", 11);
//	printf("\n\nint nbr: %X", nbr);
	ft_printf("ft_printf: ");
	ft = ft_printf("%s %d %c %i %u %x %X", "bombastic", 10, 'Y', 20, 1123, 921, -921);
	printf("X\n___printf: ");
	stdio = printf("%s %d %c %i %u %x %X", "bombastic", 10, 'Y', 20, 1123, 921, -921);
	if (ft == stdio)
		printf("X\nSame return values.");
	else
	{
		printf("X\ndifference in return values.\n");
		printf("returned: %d\noriginal: %d\n", ft, stdio);
	}
	return (0);
}
