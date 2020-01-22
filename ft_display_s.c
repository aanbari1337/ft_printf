/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanbari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 20:46:09 by aanbari           #+#    #+#             */
/*   Updated: 2020/01/19 20:42:08 by aanbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_display1(char *str, t_tab *tab)
{
	if (tab->treat[0] == 'q')
		tab->len += ft_space(tab->width - ft_strlen(str));
	if (tab->treat[0] == '0')
		tab->len += ft_zero(tab->width - ft_strlen(str));
	ft_putstr(str);
	if (tab->treat[0] == '-')
		tab->len += ft_space(tab->width - ft_strlen(str));
	tab->len += ft_strlen(str);
	return (tab->len);
}

static int		ft_display2(char *str, t_tab *tab)
{
	int len;

	if (ft_abs(tab->precision) > ft_strlen(str))
		len = ft_strlen(str);
	else
		len = ft_abs(tab->precision);
	if (tab->treat[0] == 'q' && tab->width > len)
		tab->len += ft_space(tab->width - len);
	if (tab->treat[0] == '0' && tab->width > len)
		tab->len += ft_zero(tab->width - len);
	write(1, str, len);
	if (tab->treat[0] == '-' && tab->width > len)
		tab->len += ft_space(tab->width - len);
	tab->len += len;
	return (tab->len);
}

t_tab			*ft_display_s(t_tab *tab)
{
	char	*s;

	s = va_arg(tab->param, char *);
	if (s == NULL)
		s = "(null)";
	if (tab->precision == -1)
		tab->len = ft_display1(s, tab);
	else
	{
		if (tab->precision == 0)
		{
			if (tab->width != 0)
			{
				if (tab->treat[0] == '0')
					tab->len += ft_zero(tab->width);
				else
					tab->len += ft_space(tab->width);
			}
		}
		else
			tab->len = ft_display2(s, tab);
	}
	return (tab);
}
