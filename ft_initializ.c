/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initializ.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanbari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 20:29:28 by aanbari           #+#    #+#             */
/*   Updated: 2020/01/19 20:42:35 by aanbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*ft_initializ(t_tab *tab)
{
	tab->spec = "%cspdiuxX";
	tab->treat[0] = 'q';
	tab->treat[1] = '\0';
	tab->treat[2] = '\0';
	tab->treat[3] = '\0';
	tab->treat[4] = '\0';
	return (tab);
}
