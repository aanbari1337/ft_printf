/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanbari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 20:31:18 by aanbari           #+#    #+#             */
/*   Updated: 2020/01/19 21:46:25 by aanbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_tab
{
	va_list		param;
	char		*copy;
	char		treat[5];
	char		flags;
	char		*spec;
	int			i;
	int			width;
	int			len;
	int			precision;
}				t_tab;

int				ft_printf(const char *format, ...);
t_tab			*ft_initializ(t_tab *tab);
t_tab			*ft_flags(t_tab *tab);
t_tab			*ft_width(t_tab *tab);
t_tab			*ft_precision(t_tab *tab);
t_tab			*ft_specifier(t_tab *tab);
t_tab			*ft_display_s(t_tab *tab);
t_tab			*ft_display_c(t_tab *tab);
t_tab			*ft_display_x(t_tab *tab);
void			ft_display_x1(unsigned int p);
void			ft_display_x2(unsigned int p);
t_tab			*ft_display_p(t_tab *tab);
t_tab			*ft_display_u(t_tab *tab);
t_tab			*ft_display_di(t_tab *tab);
t_tab			*ft_display_per(t_tab *tab);
int				ft_print_hex(unsigned int p, t_tab *tab);
int				put_int1(char *str, t_tab *tab);
int				put_u1(char *str, t_tab *tab);
int				ft_abs(int n);
int				ft_print(t_tab *tab);
int				ft_traite(t_tab *tab);
t_tab			*ft_display(t_tab *tab);
int				ft_space(int n);
int				ft_zero(int n);
int				ft_max(int a, int b);
void			ft_putchar(char c);
void			ft_putstr(char *s);
char			*ft_itoa(int nbr);
char			*ft_itoa_u(unsigned int nbr);
int				ft_strlen(const char *str);
int				len_hex(unsigned int p);
int				n_to_hex(unsigned int p, t_tab *tab);
void			ft_putstr_rev(char *tab, int len);

#endif
