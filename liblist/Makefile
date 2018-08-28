# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/30 06:27:18 by wseegers          #+#    #+#              #
#    Updated: 2018/08/28 14:29:00 by pstubbs          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = liblist.a
CC = clang
CFLAGS = -Wall -Wextra -Werror
INC := -I include

F_MATH_SRC = f_abs.c
F_MATH = $(addprefix src/support/f_math/, $(F_MATH_SRC))

F_MEMORY_SRC = f_membzero.c f_memcpy.c f_memalloc.c f_memccpy.c f_memdel.c f_memset.c 
F_MEMORY = $(addprefix src/support/f_memory/, $(F_MEMORY_SRC))

F_STRING_SRC = f_strdel.c f_strdup.c f_strlen.c \
			   f_strnew.c f_strcpy.c f_strcjoin.c
F_STRING = $(addprefix src/support/f_string/, $(F_STRING_SRC))

list_SRC = list_append.c list_create.c list_node_create.c\
			 list_clear.c list_init.c list_pop.c list_insert.c\
			 list_getnode.c list_rot.c list_get.c list_find.c\
			 list_func_find.c list_copy.c list_mergesort.c list_to_str.c
list = $(addprefix src/, $(list_SRC))

OBJ_LIST = $(patsubst %.c, %.o, $(F_MATH) $(F_MEMORY) $(F_STRING) $(list))
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
