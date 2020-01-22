/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_int1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanbari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 16:56:04 by aanbari           #+#    #+#             */
/*   Updated: 2020/01/19 21:10:18 by aanbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_i_p_q(char *str, t_tab *tab)
{
	if (str[0] == '-')
	{
		tab->len += ft_space(tab->width - ft_max(ft_strlen(str + 1),
					tab->precision) - 1);
		tab->len += write(1, "-", 1);
		tab->len += ft_zero(tab->precision - ft_strlen(str + 1));
		tab->len += write(1, str + 1, ft_strlen(str + 1));
		return (tab->len);
	}
	tab->len += ft_space(tab->width - ft_max(ft_strlen(str), tab->precision));
	tab->len += ft_zero(tab->precision - ft_strlen(str));
	tab->len += write(1, str, ft_strlen(str));
	return (tab->len);
}

static int		ft_i_p_m(char *str, t_tab *tab)
{
	if (str[0] == '-')
	{
		tab->len += write(1, "-", 1);
		tab->len += ft_zero(tab->precision - ft_strlen(str + 1));
		tab->len += write(1, str + 1, ft_strlen(str + 1));
		tab->len += ft_space(tab->width - ft_max(ft_strlen(str + 1),
					tab->precision) - 1);
		return (tab->len);
	}
	tab->len += ft_zero(tab->precision - ft_strlen(str));
	tab->len += write(1, str, ft_strlen(str));
	tab->len += ft_space(tab->width - ft_max(ft_strlen(str), tab->precision));
	return (tab->len);
}

int				put_int1(char *str, t_tab *tab)
{
	if (tab->treat[0] == 'q' || tab->treat[0] == '0')
		return (ft_i_p_q(str, tab));
	if (tab->treat[0] == '-')
		return (ft_i_p_m(str, tab));
	return (tab->len);
}
