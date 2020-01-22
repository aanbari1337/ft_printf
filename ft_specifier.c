/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanbari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 20:41:49 by aanbari           #+#    #+#             */
/*   Updated: 2019/12/24 20:42:40 by aanbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*ft_specifier(t_tab *tab)
{
	int i;

	i = 0;
	while (tab->spec[i])
	{
		if (tab->spec[i] == tab->copy[tab->i])
			tab->treat[3] = tab->copy[tab->i];
		i++;
	}
	return (tab);
}
