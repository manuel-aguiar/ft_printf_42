/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_csdiu_perc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaria-d <mmaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:03:55 by manuel            #+#    #+#             */
/*   Updated: 2023/04/13 20:48:02 by mmaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* ----- DELETE ---*/
static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	putcountint(int nb)
{
	char	str[11];
	char	print;
	int		i;
	char	sign;

	sign = 1;
	i = sizeof(str);
	if (nb < 0)
		sign = -1;
	if (nb == 0)
		str[--i] = '0';
	while (nb != 0)
	{
		print = nb % 10;
		if (print < 0)
			print *= -1;
		str[--i] = print + '0';
		nb /= 10;
	}
	if (sign == -1)
		str[--i] = '-';
	return (write(1, &str[i], sizeof(str) - i));
}

int	putcountunint(unsigned int nb)
{
	char	str[11];
	int		i;

	i = sizeof(str);
	if (nb == 0)
		str[--i] = '0';
	while (nb != 0)
	{
		str[--i] = (nb % 10) + '0';
		nb /= 10;
	}
	return (write(1, &str[i], sizeof(str) - i));
}

int	putcountstr(char *str)
{
	return (write(1, str, ft_strlen(str)));
}

int	putcountchar(char c)
{
	return (write(1, &c, 1));
}
