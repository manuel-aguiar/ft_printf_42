/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pxX.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaria-d <mmaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:03:55 by manuel            #+#    #+#             */
/*   Updated: 2023/04/13 21:20:43 by mmaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*stringaddr(unsigned long nb, char *str, int *len)
{
	if (nb == 0)
	{
		*str = HEXS[0];
		*len = 1;
		return (str);
	}
	while (nb != 0)
	{
		*str-- = HEXS[nb % HEXLEN];
		nb /= HEXLEN;
		(*len)++;
	}
	return (++str);
}

int	putcountaddr(void *address)
{
	unsigned long	addr;
	int				wordlen;
	char			str[18];
	char			*ptr;

	addr = (unsigned long)address;
	if (!addr)
	{
		return (putcountstr("(nil)"));
	}
	wordlen = 0;
	ptr = stringaddr(addr, (str + sizeof(str) - 1), &wordlen);
	*--ptr = 'x';
	*--ptr = '0';
	return (write(1, ptr, wordlen + 2));
}

static char	*stringhex(unsigned int nb, char *str, int *len, char *base)
{
	if (nb == 0)
	{
		*str = base[0];
		*len = 1;
		return (str);
	}
	while (nb != 0)
	{
		*str-- = base[nb % HEXLEN];
		nb /= HEXLEN;
		(*len)++;
	}
	return (++str);
}

int	putcounthex(unsigned int nb, char *base)
{
	int		wordlen;
	char	str[8];
	char	*ptr;

	wordlen = 0;
	ptr = stringhex(nb, (str + sizeof(str) - 1), &wordlen, base);
	return (write(1, ptr, wordlen));
}
