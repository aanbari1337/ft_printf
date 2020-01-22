/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanbari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 23:06:17 by aanbari           #+#    #+#             */
/*   Updated: 2020/01/19 20:13:21 by aanbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_tab(char *str, long long int nb, int i)
{
	if (nb < 10)
		str[i] = '0' + nb;
	else
	{
		ft_tab(str, nb / 10, i - 1);
		str[i] = '0' + (nb % 10);
	}
}

static char	*ft_allo(int c, int nbr)
{
	char	*str;

	if (nbr < 0)
	{
		if (!(str = malloc(c + 3)))
			return (NULL);
		str[0] = '-';
		str[c + 2] = '\0';
	}
	else
	{
		if (!(str = malloc(c + 2)))
			return (NULL);
		str[c + 1] = '\0';
	}
	return (str);
}

char		*ft_itoa_u(unsigned int nbr)
{
	long long int	nb;
	int				range;
	int				c;
	char			*str;

	nb = nbr;
	range = 1;
	c = 0;
	while ((nb / range) >= 10)
	{
		range = range * 10;
		c++;
	}
	if (!(str = ft_allo(c, nbr)))
		return (NULL);
	ft_tab(str, nb, c);
	return (str);
}
