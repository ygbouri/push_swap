# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ygbouri <ygbouri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/04 23:39:11 by ygbouri           #+#    #+#              #
#    Updated: 2022/04/13 22:49:20 by ygbouri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC = ft_printf.c ft_putstr.c ft_putchar.c ft_putnbr.c ft_strleng.c \
	  ft_affichhexa.c ft_count_nbr.c ft_count_nbr_hexa.c \
	  ft_affichhexaupper.c ft_affichhexa_p.c
OBJ = $(SRC:.c=.o)

CC = gcc

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

HEADER = ft_printf.h

all : $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -c $<

$(NAME) : $(OBJ) $(HEADER)
	@ar -rc $(NAME) $(OBJ)

clean :
	@rm -f $(OBJ) $(OBJB)

fclean : clean
	@rm -f $(NAME)

re : fclean all
