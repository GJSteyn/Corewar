# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/30 06:27:18 by pstubbs           #+#    #+#              #
#    Updated: 2018/09/01 12:59:53 by wseegers         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libcore.a
CC = clang
CFLAGS = -Wall -Wextra -Werror
INC := -I include

CORE_SRC = f_bzero.c f_isspace.c f_memalloc.c f_strlen.c f_atol.c f_isdigit.c \
		f_little_to_big_endian.c f_big_to_little_endian.c f_dynamicstring.c \
		f_isspace_notnewl.c f_strsub.c f_strchr.c op.c f_strcmp.c f_strncpy.c \
		f_putstr_err.c
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
