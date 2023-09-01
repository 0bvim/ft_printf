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
	char	test_char;
	char	test_char1[13] = "Stete te amo";
	int	number = 0;
	int	number1 = 0;


	test_char = 'a';
	number = printf("Libc: %c\noi %s\nnbr: %d and\n%i\n", test_char, test_char1, number, number1);
	number1 = ft_printf("MyPf: %c\noi %s\nnbr: %d and\n%i\n", test_char, test_char1, number, number1);
	printf("Libc: %c\noi %s\nnbr: %d and\n%i\n", test_char, test_char1, number, number1);
	ft_printf("MyPf: %c\noi %s\nnbr: %d and\n%i\n", test_char, test_char1, number, number1);
	return 0;
}
