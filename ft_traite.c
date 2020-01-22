/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanbari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 20:53:28 by aanbari           #+#    #+#             */
/*   Updated: 2020/01/19 20:43:36 by aanbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_traite(t_tab *tab)
{
	tab->i++;
	ft_flags(tab);
	ft_width(tab);
	ft_precision(tab);
	ft_specifier(tab);
	ft_display(tab);
	return (tab->len);
}
