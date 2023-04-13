/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:03:55 by manuel            #+#    #+#             */
/*   Updated: 2023/03/22 19:03:55 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# define HEXS "0123456789abcdef"
# define HEXB "0123456789ABCDEF"
# define HEXLEN 16
# define FLAGS "cspdiuxX%"
# include <stdarg.h>

#include <unistd.h>    /* DELETE */
#include <limits.h>    /* DELETE */
/* include libft */


/* ---- ft_printf.c ---- */
int	ft_printf(const char *str, ...);
int	printformat(va_list ptr, char flag);


/* ---- print_pxX.c ---- */
int	putcountaddr(void *address);
int	putcounthex(unsigned int nb, char *base);

/* ---- print_csdiu_perc.c ---- */
int	putcountint(int nb);
int	putcountunint(unsigned int nb);
int	putcountstr(char *str);
int	putcountchar(char c);

#endif
