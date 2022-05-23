# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ygbouri <ygbouri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/14 22:21:29 by ygbouri           #+#    #+#              #
#    Updated: 2022/05/20 16:55:30 by ygbouri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = push_swap.c push_swap_utils.c	push_swap_utils1.c push_swap_utils2.c\
		push_swap_utils3.c push_swap_utils4.c push_swap_utils5.c push_swap_utils6.c
		
		
OBJ = $(SRC:.c=.o)

SRCB = checker.c push_swap_utils.c push_swap_utils1.c\
		checker_utils.c push_swap_utils3.c\
		push_swap_utils4.c push_swap_utils5.c push_swap_utils6.c\
		get_next_line/get_next_line.c\
		get_next_line/get_next_line_utils.c\

OBJB = $(SRCB:.c=.o)

CC = @gcc

NAME = push_swap
NAMEB = checker
CFLAGS = -Wall -Wextra -Werror
PRINTF = ft_printf/libftprintf.a
PRINTF_DIR = ft_printf/
LIBFT = libft/libft.a 
LIBFT_DIR = libft/
HEADER = push_swap.h
all : $(NAME)

$(NAME) : $(OBJ) $(PRINTF) $(HEADER) $(LIBFT)
	@$(CC) $(CFLAGS) $(SRC) $(PRINTF) $(LIBFT) -o $(NAME) 
	@echo "done for push_swap"

$(PRINTF):
	@$(MAKE) -C $(PRINTF_DIR)
	@echo "done for PRINTF"

$(LIBFT):
	@$(MAKE) bonus -C $(LIBFT_DIR)
	@echo "done for LIBFT"

clean :
	@$(MAKE) clean -C $(PRINTF_DIR)
	@$(MAKE) clean -C $(LIBFT_DIR)
	@rm -rf $(OBJ) 
	@rm -rf $(OBJB) 
	@echo "clean"

fclean : clean
	@rm -rf $(NAME)
	@rm -rf $(NAMEB)
	@$(MAKE) fclean -C $(PRINTF_DIR)
	@$(MAKE) fclean -C $(LIBFT_DIR)

bonus : $(NAMEB)
$(NAMEB) : $(OBJB) $(PRINTF) $(HEADER) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJB) $(PRINTF) $(LIBFT) -o $(NAMEB)
	@echo "done for checker"

re : fclean all

PHONY: all clean fclean re 