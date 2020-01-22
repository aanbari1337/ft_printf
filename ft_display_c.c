/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanbari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 23:31:29 by aanbari           #+#    #+#             */
/*   Updated: 2020/01/19 21:21:50 by aanbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_display_c1(char c, t_tab *tab)
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

t_tab			*ft_display_c(t_tab *tab)
{
	char	c;

	c = (char)va_arg(tab->param, char *);
	if (tab->precision == -1 || tab->precision == 0)
		tab->len = ft_display_c1(c, tab);
	return (tab);
}
