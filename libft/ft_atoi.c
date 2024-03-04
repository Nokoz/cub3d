/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:22:14 by gvardaki          #+#    #+#             */
/*   Updated: 2023/04/17 16:26:13 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static const char	*skip_zero(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == '0')
		i++;
	return (str + i);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;
	int	i;

	if (!str)
		return (0);
	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= (-1);
		i++;
	}
	str = skip_zero(str + i);
	i = 0;
	while (ft_isdigit(str[i]))
		res = res * 10 + str[i++] - 48;
	if (i <= 19)
		return (res * sign);
	else
		return (-1);
}
