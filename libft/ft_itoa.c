/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:24:25 by gvardaki          #+#    #+#             */
/*   Updated: 2023/04/11 08:49:29 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int i)
{
	if (i / 10 == 0)
		return (1);
	else
		return (ft_intlen(i / 10) + 1);
}

char	*ft_itoa(int n)
{
	char	*a;
	int		ilen;
	long	nl;

	nl = n;
	ilen = ft_intlen(nl);
	if (nl < 0)
		ilen++;
	a = malloc(ilen + 1);
	if (!a)
		return (0);
	if (nl == 0)
		a[0] = '0';
	if (nl < 0)
	{
		a[0] = '-';
		nl *= -1;
	}
	a[ilen] = '\0';
	while (ilen > 0 && nl > 0)
	{
		a[--ilen] = ((nl % 10) + '0');
		nl = nl / 10;
	}
	return (a);
}
