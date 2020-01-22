/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanbari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 21:28:29 by aanbari           #+#    #+#             */
/*   Updated: 2020/01/19 21:30:55 by aanbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_u(unsigned int a, t_tab *tab)
{
	char	*str;

	str = ft_itoa_u(a);
	if (tab->treat[0] == 'q' && tab->width > ft_strlen(str))
		tab->len += ft_space(tab->width - ft_strlen(str));
	if (tab->treat[0] == '0' && tab->width > ft_strlen(str))
		tab->len += ft_zero(tab->width - ft_strlen(str));
	tab->len += write(1, str, ft_strlen(str));
	if (tab->treat[0] == '-' && tab->width > ft_strlen(str))
		tab->len += ft_space(tab->width - ft_strlen(str));
	free(str);
	return (tab->len);
}

static int	print_zero_u(unsigned int a, t_tab *tab)
{
	char	*str;

	str = ft_itoa_u(a);
	if (tab->precision == -1)
		tab->len = put_u(a, tab);
	else
	{
		if (tab->precision == 0)
		{
			if (tab->width != 0)
				tab->len += ft_space(tab->width);
		}
		else
			tab->len = put_u1(str, tab);
	}
	free(str);
	return (tab->len);
}

static int	prec_zero_u(t_tab *tab, char *str, unsigned int a)
{
	if (tab->width == 0)
		tab->len += write(1, str, ft_strlen(str));
	else
	{
		(tab->treat[0] == '0') ? tab->treat[0] = 'q' : 1;
		tab->len = put_u(a, tab);
	}
	return (tab->len);
}

t_tab		*ft_display_u(t_tab *tab)
{
	char			*str;
	unsigned int	a;

	a = va_arg(tab->param, unsigned int);
	str = ft_itoa_u(a);
	if (a == 0)
		tab->len = print_zero_u(a, tab);
	else
	{
		if (tab->precision == -1)
			tab->len = put_u(a, tab);
		else
		{
			if (tab->precision == 0)
				tab->len = prec_zero_u(tab, str, a);
			else
				tab->len = put_u1(str, tab);
		}
	}
	free(str);
	return (tab);
}
