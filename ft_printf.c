/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanbari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 20:16:42 by aanbari           #+#    #+#             */
/*   Updated: 2020/01/19 21:06:34 by aanbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_tab *tab;

	if (!(tab = malloc(sizeof(t_tab))))
		return (-1);
	tab->copy = (char *)format;
	tab = ft_initializ(tab);
	tab->len = 0;
	tab->i = 0;
	if (format)
	{
		va_start(tab->param, format);
		tab->len = ft_print(tab);
		va_end(tab->param);
	}
	free(tab);
	return (tab->len);
}
