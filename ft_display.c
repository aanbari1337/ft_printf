/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanbari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 20:55:01 by aanbari           #+#    #+#             */
/*   Updated: 2020/01/19 21:43:46 by aanbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*ft_display(t_tab *tab)
{
	if (tab->treat[3] == 's')
		ft_display_s(tab);
	if (tab->treat[3] == 'c')
		ft_display_c(tab);
	if (tab->treat[3] == 'x' || tab->treat[3] == 'X')
		ft_display_x(tab);
	if (tab->treat[3] == 'p')
		ft_display_p(tab);
	if (tab->treat[3] == 'u')
		ft_display_u(tab);
	if (tab->treat[3] == 'd' || tab->treat[3] == 'i')
		ft_display_di(tab);
	if (tab->treat[3] == '%')
		ft_display_per(tab);
	return (tab);
}
