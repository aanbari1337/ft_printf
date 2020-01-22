/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_per.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanbari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:38:23 by aanbari           #+#    #+#             */
/*   Updated: 2020/01/19 20:38:23 by aanbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_car(char c, t_tab *tab)
{
	if (tab->treat[0] == 'q')
		tab->len += ft_space(tab->width - 1);
	if (tab->treat[0] == '0')
		tab->len += ft_zero(tab->width - 1);
	ft_putchar(c);
	if (tab->treat[0] == '-')
		tab->len += ft_space(tab->width - 1);
	tab->len += 1;
	return (tab->len);
}

t_tab		*ft_display_per(t_tab *tab)
{
	char	c;

	c = '%';
	if (tab->precision == -1)
		tab->len = put_car(c, tab);
	else
	{
		if (tab->precision == 0)
		{
			if (tab->width == 0)
				tab->len += write(1, &c, 1);
			else
				tab->len = put_car(c, tab);
		}
		else
			tab->len = put_car(c, tab);
	}
	return (tab);
}
