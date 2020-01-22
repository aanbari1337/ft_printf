/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanbari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 23:19:32 by aanbari           #+#    #+#             */
/*   Updated: 2020/01/21 17:16:03 by aanbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		len_p(unsigned long p, t_tab *tab)
{
	int i;

	i = 0;
	if (p == 0 && tab->precision == -1)
		return (3);
	while (p)
	{
		p /= 16;
		i++;
	}
	return (i + 2);
}

static void		ft_display_p2(unsigned long p)
{
	if (p >= 16)
		ft_display_p2(p / 16);
	p = p % 16;
	p += p < 10 ? '0' : 'a' - 10;
	write(1, &p, 1);
}

static int		ft_display_p0(unsigned long p, t_tab *tab)
{
	if (tab->treat[0] == 'q' && tab->width > len_p(p, tab))
		tab->len += ft_space(tab->width - len_p(p, tab));
	write(1, "0x", 2);
	tab->len += len_p(p, tab);
	if (tab->treat[0] == '-' && tab->width > len_p(p, tab))
		tab->len += ft_space(tab->width - len_p(p, tab));
	return (tab->len);
}

static int		ft_display_p1(unsigned long p, t_tab *tab)
{
	if (tab->treat[0] == 'q' && tab->width > len_p(p, tab))
		tab->len += ft_space(tab->width - len_p(p, tab));
	write(1, "0x", 2);
	ft_display_p2(p);
	tab->len += len_p(p, tab);
	if (tab->treat[0] == '-' && tab->width > len_p(p, tab))
		tab->len += ft_space(tab->width - len_p(p, tab));
	return (tab->len);
}

t_tab			*ft_display_p(t_tab *tab)
{
	unsigned long	p;

	p = va_arg(tab->param, unsigned long);
	if (p == 0 && tab->precision == 0)
		tab->len = ft_display_p0(p, tab);
	else if (tab->precision == -1 || tab->precision == 0)
		tab->len = ft_display_p1(p, tab);
	return (tab);
}
