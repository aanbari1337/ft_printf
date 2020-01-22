/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanbari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 20:38:38 by aanbari           #+#    #+#             */
/*   Updated: 2020/01/19 13:18:34 by aanbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*ft_width(t_tab *tab)
{
	if (tab->treat[1] == '*')
		tab->width = va_arg(tab->param, int);
	else
	{
		while (tab->copy[tab->i] >= '0' && tab->copy[tab->i] <= '9')
		{
			tab->width = tab->width * 10 + tab->copy[tab->i] - '0';
			tab->i++;
		}
	}
	if (tab->width < 0)
	{
		tab->width = ft_abs(tab->width);
		tab->treat[0] = '-';
	}
	return (tab);
}
