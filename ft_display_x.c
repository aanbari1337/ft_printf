/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_xX.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanbari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 16:28:57 by aanbari           #+#    #+#             */
/*   Updated: 2020/01/19 21:39:49 by aanbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_print_hex1(unsigned int p, t_tab *tab)
{
	int len;

	len = 0;
	if (tab->treat[0] == '0' || tab->treat[0] == 'q')
	{
		len += ft_space(tab->width - ft_max(ft_abs(tab->precision),
					len_hex(p)));
		len += ft_zero(tab->precision - len_hex(p));
		n_to_hex(p, tab);
	}
	if (tab->treat[0] == '-')
	{
		len += ft_zero(tab->precision - len_hex(p));
		n_to_hex(p, tab);
		len += ft_space(tab->width - ft_max(ft_abs(tab->precision),
					len_hex(p)));
	}
	tab->len += len_hex(p) + len;
	return (tab->len);
}

static int		ft_put_zero(int p, t_tab *tab)
{
	if (tab->precision == -1)
		tab->len = ft_print_hex(p, tab);
	else
	{
		if (tab->precision == 0)
		{
			if (tab->width != 0)
				tab->len += ft_space(tab->width);
		}
		else
			tab->len = ft_print_hex1(p, tab);
	}
	return (tab->len);
}

t_tab			*ft_display_x(t_tab *tab)
{
	unsigned int	p;

	p = va_arg(tab->param, unsigned int);
	(p == 0) ? tab->len = ft_put_zero(p, tab) : 1;
	if (p != 0)
	{
		(tab->precision == -1) ? tab->len = ft_print_hex(p, tab) : 1;
		if (tab->precision != -1)
		{
			if (tab->precision == 0)
			{
				if (tab->width == 0)
					tab->len += n_to_hex(p, tab) + len_hex(p);
				else
				{
					(tab->treat[0] == '0') ? tab->treat[0] = 'q' : 1;
					tab->len = ft_print_hex(p, tab);
				}
			}
			(tab->precision != 0) ? tab->len = ft_print_hex1(p, tab) : 1;
		}
	}
	return (tab);
}
