# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttwycros <ttwycros@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/03 23:57:37 by ttwycros          #+#    #+#              #
#    Updated: 2021/12/04 00:03:45 by ttwycros         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIST =	ft_printf.c			utils.c

HEADER = ft_printf.h

COMPILER = gcc

FLAGS = -Wall -Wextra -Werror -I$(HEADER)

OBJS = $(patsubst %.c,%.o,$(LIST))

.PHONY : all clean fclean re

all: $(NAME)

$(NAME) : $(OBJS) $(HEADER)
	make -C libft/
	ar rcs $(NAME) $?
%.o : %.c $(HEADER)
	$(COMPILER) $(FLAGS) -c $< -o $@
norm : 
	norminette
clean :
	rm -f $(OBJS)
	@make clean -C libft/
fclean : clean
	rm -f $(NAME)
	@make fclean -C libft/
re : fclean all