/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanbari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 21:05:35 by aanbari           #+#    #+#             */
/*   Updated: 2020/01/19 21:23:12 by aanbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int p, t_tab *tab)
{
	if (tab->treat[0] == 'q' && tab->width > len_hex(p))
		tab->len += ft_space(tab->width - len_hex(p));
	if (tab->treat[0] == '0' && tab->width > len_hex(p))
		tab->len += ft_zero(tab->width - len_hex(p));
	n_to_hex(p, tab);
	tab->len += len_hex(p);
	if (tab->treat[0] == '-' && tab->width > len_hex(p))
		tab->len += ft_space(tab->width - len_hex(p));
	return (tab->len);
}
