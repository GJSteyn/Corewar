# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/30 06:27:18 by pstubbs           #+#    #+#              #
#    Updated: 2018/09/05 04:33:03 by gsteyn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libcore.a
CC = clang
CFLAGS = -Wall -Wextra -Werror
INC := -I include

CORE_SRC = f_bzero.c f_isspace.c f_memalloc.c f_strlen.c f_atol.c f_isdigit.c \
			f_strcmp.c f_strncpy.c f_strchr.c f_strsub.c f_strnew.c \
			f_little_to_big_endian.c f_big_to_little_endian.c f_dynamicstring.c \
			f_isspace_notnewl.c f_putstr_err.c op.c
CORE = $(addprefix src/, $(CORE_SRC))

OBJ_LIST = $(patsubst %.c, %.o, $(CORE))
BIN_PATH = obj
BIN = $(addprefix $(BIN_PATH)/, $(OBJ_LIST))
DEP := $(BIN:%.o=%.d)

all : $(NAME)

$(NAME) : $(BIN)
	ar rc $@ $?
	ranlib $@

$(BIN_PATH)/%.o :  %.c
	@mkdir -p $(BIN_PATH)
	@mkdir -p $(addprefix $(BIN_PATH)/,$(dir $<))
	$(CC) $(CFLAGS) $(INC) -MMD -c $< -o $@

-include $(DEP)

clean :
	rm -rf $(BIN_PATH)

fclean : clean
	rm -f $(NAME)

re : fclean all
