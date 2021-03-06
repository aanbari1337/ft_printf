/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanbari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 13:12:44 by aanbari           #+#    #+#             */
/*   Updated: 2020/01/19 21:09:21 by aanbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len_hex(unsigned int p)
{
	int i;

	i = 0;
	if (p == 0)
		return (1);
	while (p)
	{
		p /= 16;
		i++;
	}
	return (i);
}
