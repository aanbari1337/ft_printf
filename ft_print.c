/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanbari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 20:51:58 by aanbari           #+#    #+#             */
/*   Updated: 2020/01/19 20:43:11 by aanbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print(t_tab *tab)
{
	while (tab->copy[tab->i])
	{
		if (tab->copy[tab->i] == '%')
		{
			tab->width = 0;
			tab->precision = -1;
			ft_initializ(tab);
			tab->len = ft_traite(tab);
		}
		else
		{
			ft_putchar(tab->copy[tab->i]);
			tab->len++;
		}
		tab->i++;
	}
	return (tab->len);
}
