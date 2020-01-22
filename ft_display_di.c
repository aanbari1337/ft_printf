/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_di.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanbari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:32:38 by aanbari           #+#    #+#             */
/*   Updated: 2020/01/19 20:58:21 by aanbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		cas_moin(char *str, t_tab *tab)
{
	if (tab->treat[0] == 'q' && tab->width > ft_strlen(str))
	{
		tab->len += ft_space(tab->width - ft_strlen(str));
		tab->len += write(1, str, ft_strlen(str));
	}
	if (tab->treat[0] == '0' && tab->width > ft_strlen(str))
	{
		tab->len += write(1, "-", 1);
		tab->len += ft_zero(tab->width - ft_strlen(str));
		tab->len += write(1, str + 1, ft_strlen(str + 1));
	}
	if (tab->treat[0] == '-' && tab->width > ft_strlen(str))
	{
		tab->len += write(1, str, ft_strlen(str));
		tab->len += ft_space(tab->width - ft_strlen(str));
	}
	if (tab->width <= ft_strlen(str))
		tab->len += write(1, str, ft_strlen(str));
	return (tab->len);
}

static int		put_int(int a, t_tab *tab)
{
	char *str;

	str = ft_itoa(a);
	if (str[0] == '-')
	{
		tab->len = cas_moin(str, tab);
		free(str);
		return (tab->len);
	}
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

static int		print_zero(int a, t_tab *tab)
{
	char *str;

	str = ft_itoa(a);
	if (tab->precision == -1)
		tab->len = put_int(a, tab);
	else
	{
		if (tab->precision == 0)
		{
			if (tab->width != 0)
				tab->len += ft_space(tab->width);
		}
		else
			tab->len = put_int1(str, tab);
	}
	free(str);
	return (tab->len);
}

static int		prec_zero(t_tab *tab, char *str, int a)
{
	if (tab->width == 0)
		tab->len += write(1, str, ft_strlen(str));
	else
	{
		(tab->treat[0] == '0') ? tab->treat[0] = 'q' : 1;
		tab->len = put_int(a, tab);
	}
	return (tab->len);
}

t_tab			*ft_display_di(t_tab *tab)
{
	char	*str;
	int		a;

	a = va_arg(tab->param, int);
	str = ft_itoa(a);
	if (a == 0)
		tab->len = print_zero(a, tab);
	else
	{
		if (tab->precision == -1)
			tab->len = put_int(a, tab);
		else
		{
			if (tab->precision == 0)
				tab->len = prec_zero(tab, str, a);
			else
				tab->len = put_int1(str, tab);
		}
	}
	free(str);
	return (tab);
}
