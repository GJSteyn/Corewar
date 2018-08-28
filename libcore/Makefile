# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/30 06:27:18 by pstubbs           #+#    #+#              #
#    Updated: 2018/08/28 17:33:51 by pstubbs          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libcore.a

CORE_SRC = src/f_isspace.c src/f_memalloc.c src/f_strlen.c src/f_bzero.c 
# CORE = $(addprefix src/, $(CORE_SRC))
OBJ_LIST = $(CORE:.c = .o)

$(NAME):
	gcc -Wall -Werror -Wextra -c $(CORE_SRC)
	ar -rc $(NAME) $(OBJ_LIST)
	ranlib $(NAME)

all:	$(NAME)

clean :
	rm -rf *.o

fclean : clean
	rm -f $(NAME)

re : fclean all
