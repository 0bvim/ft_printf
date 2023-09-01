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

int main(int argc, char *argv[])
{
	char	test_char1[13] = "Stete te amo";
	char	test_char = 'a';
	int		number1 = 0;
	int		number = printf("Libc: %c\n%s\n%d\n%i\n", test_char, test_char1, number, number1);
	number1 = ft_printf("MyPf: %c\n%s\n%d\n%i\n", test_char, test_char1, number, number1);
	printf("\n---------------------------\n");
	printf("Original %d\nFalcie %d\n", number, number1);
	return 0;
}
