/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 22:07:04 by vde-frei          #+#    #+#             */
/*   Updated: 2023/09/24 06:06:34 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

static int	len_base_nbr(size_t nbr, int base_len, t_element *info);
static char	*putnbr_base(size_t nb, int len, char *base, t_element *info);
static void	find_prefix(char *str, int *min, t_element *info);

void	ft_putnbr_baseb(unsigned long nbr, int *len, char *base,
		t_element *info)
{
	int		base_len;
	int		lenght;
	char	*str;

	base_len = ft_strlenb(base);
	lenght = len_base_nbr(nbr, base_len, info);
	str = putnbr_base(nbr, lenght, base, info);
	if (str == NULL)
		return ;
	print_nbr(str, lenght, len, info);
	free(str);
}

static char	*putnbr_base(size_t nb, int len, char *base, t_element *info)
{
	char	*str;
	int		min_len;
	int		base_len;

	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	base_len = ft_strlenb(base);
	min_len = 0;
	if ((info->flags & HASH) && nb != 0)
		find_prefix(str, &min_len, info);
	str[len] = '\0';
	while (min_len < len)
	{
		str[--len] = base[nb % base_len];
		nb /= base_len;
	}
	return (str);
}

static void	find_prefix(char *str, int *min, t_element *info)
{
	++*min;
	if (info->type == 'x' || info->type == 'p')
		ft_strcpy(str, HEX_L_PREFIX, ++(*min));
	if (info->type == 'X')
		ft_strcpy(str, HEX_U_PREFIX, ++(*min));
}

static int	len_base_nbr(size_t nbr, int base_len, t_element *info)
{
	int	len;
	int	pre_len;

	if (nbr == 0 && info->precision == 0)
		return (0);
	pre_len = 0;
	if ((info->flags & HASH) && nbr != 0)
		pre_len += 2 * (info->type != 'o');
	len = 0;
	if (nbr == 0)
		len++;
	while (nbr != 0)
	{
		nbr /= base_len;
		len++;
	}
	if (info->precision >= len)
		return (info->precision + pre_len);
	if (info->precision == -1 && !(info->flags & MINUS) && (info->flags & ZERO)
		&& info->width > len + pre_len)
		return (info->width);
	return (len + pre_len);
}
