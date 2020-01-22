/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanbari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 20:35:35 by aanbari           #+#    #+#             */
/*   Updated: 2020/01/19 20:57:42 by aanbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*ft_flags(t_tab *tab)
{
	while (tab->copy[tab->i] == '-' || tab->copy[tab->i] == '0')
	{
		if (tab->copy[tab->i] == '-')
			tab->treat[0] = '-';
		if (tab->copy[tab->i] == '0' && tab->treat[0] == 'q')
			tab->treat[0] = '0';
		tab->i++;
	}
	if (tab->copy[tab->i] == '*')
	{
		tab->treat[1] = '*';
		tab->i++;
	}
	return (tab);
}
