# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aanbari <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/18 13:01:52 by aanbari           #+#    #+#              #
#    Updated: 2020/01/19 21:44:32 by aanbari          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ft_abs.c \
		ft_itoa.c \
		ft_printf.c \
		ft_strlen.c \
		ft_display_c.c \
		ft_display_di.c \
		ft_display_p.c \
		ft_display_per.c \
		ft_display_s.c \
		ft_display_u.c \
		ft_display_x.c \
		ft_display.c \
		ft_flags.c \
		ft_initializ.c \
		ft_max.c \
		ft_precision.c \
		ft_print.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_space.c \
		ft_specifier.c \
		ft_traite.c \
		ft_width.c \
		ft_zero.c \
		put_int1.c \
		ft_display_x1.c \
		ft_putstr_rev.c \
		len_hex.c \
		n_to_hex.c \
		ft_print_hex.c \
		ft_itoa_u.c \
		put_u1.c \
		ft_display_x2.c \


OBJ = $(SRCS:.c=.o)

B_OBJ = $(B_SRCS:.c=.o)

CLEAR_LINE=\033[2K
BEGIN_LINE=\033[A

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus : all $(B_OBJ)
	ar rcs $(NAME) $(B_OBJ)

%.o : %.c
	@echo "$(CLEAR_LINE)create $@...`gcc -Wall -Wextra -Werror -c $< -o $@`$(BEGIN_LINE)"

clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean all

