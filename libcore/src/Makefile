# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/30 06:27:18 by pstubbs           #+#    #+#              #
#    Updated: 2018/08/29 09:58:55 by kmarchan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME= libcore.a

# CORE_SRC = f_isspace.c f_memalloc.c f_strlen.c f_bzero.c 
# CORE = $(addprefix src/, $(CORE_SRC))
# OBJ_LIST = $(CORE:.c = .o)

# $(NAME):
# 	gcc -Wall -Werror -Wextra -c $(CORE)
# 	ar -rc $(NAME) $(OBJ_LIST)
# 	ranlib $(NAME)

# all:	$(NAME)

# clean :
# 	rm -rf *.o

# fclean : clean
# 	rm -f $(NAME)

# re : fclean all

NAME = libcore.a
CC = clang
CFLAGS = -Wall -Wextra -Werror -I includes/
SR = f_bzero.c f_isspace.c f_memalloc.c f_strlen.c
SRC := $(addprefix src/, $(SR:.c=.d))

O_PATH = ./bin/
OBJ := $(addprefix $(O_PATH), $(SR:.c=.o))
DEP := $(addprefix $(O_PATH), $(SR:.c=.d))

all: $(NAME)

$(NAME) : $(OBJ)
	ar rc $@ $?
	ranlib $(NAME)

$(O_PATH)%.o : %.c
	@mkdir -p $(O_PATH)
	$(CC) $(CFLAGS) -MMD -c $< -o $@

-include $(DEP)

$(SO_PATH)%.o : %.c
	@mkdir -p $(SO_PATH)
	$(CC) $(CFLAGS) -fpic -c $< -o $@

clean :
	rm -rf $(O_PATH)

fclean : clean
	rm -f $(NAME)

re : fclean all
