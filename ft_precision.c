/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanbari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 20:40:01 by aanbari           #+#    #+#             */
/*   Updated: 2020/01/19 21:06:47 by aanbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*ft_precision(t_tab *tab)
{
	if (tab->copy[tab->i] == '.')
	{
		tab->precision = 0;
		tab->i++;
	}
	if (tab->copy[tab->i] == '*')
	{
		tab->treat[2] = '*';
		tab->i++;
	}
	if (tab->treat[2] == '*')
		tab->precision = va_arg(tab->param, int);
	else
	{
		while (tab->copy[tab->i] >= '0' && tab->copy[tab->i] <= '9')
		{
			tab->precision = tab->precision * 10 + tab->copy[tab->i] - '0';
			tab->i++;
		}
	}
	if (tab->precision < 0)
		tab->precision = -1;
	return (tab);
}
