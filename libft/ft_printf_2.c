/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:36:17 by gvardaki          #+#    #+#             */
/*   Updated: 2023/06/05 10:30:14 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_hexa(unsigned int n, int *ret, int maj)
{
	char	*hexa;

	if (maj == 0)
		hexa = "0123456789abcdef";
	else
		hexa = "0123456789ABCDEF";
	if (n > 0xf)
		ft_print_hexa(n / 16, ret, maj);
	ft_putchar(hexa[n % 16]);
	*ret += 1;
}

void	ft_print_int(int n, int *ret)
{
	long	nbr;

	nbr = n;
	if (n < 0)
	{
		ft_putchar('-');
		nbr *= -1;
		*ret += 1;
	}
	ft_print_nbr(nbr, ret);
}

void	ft_print_nbr(unsigned int n, int *ret)
{
	if (n > 9)
		ft_print_nbr(n / 10, ret);
	ft_putchar((n % 10) + 48);
	*ret += 1;
}

void	ft_print_ptr_2(unsigned long n, int *ret)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (n > 0xf)
		ft_print_ptr_2(n / 16, ret);
	ft_putchar(hexa[n % 16]);
	*ret += 1;
}

void	ft_print_ptr(unsigned long n, int *ret)
{
	ft_putstr_fd("0x", 1);
	*ret += 2;
	ft_print_ptr_2(n, ret);
}
