/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanbari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 23:28:37 by aanbari           #+#    #+#             */
/*   Updated: 2020/01/19 20:21:06 by aanbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_zero(int n)
{
	int count;

	count = 0;
	if (n <= 0)
		return (0);
	else
	{
		while (n > 0)
		{
			write(1, "0", 1);
			n--;
			count++;
		}
	}
	return (count);
}