# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/30 11:12:55 by kmarchan          #+#    #+#              #
#    Updated: 2018/09/09 16:47:48 by kmarchan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar
CC = clang
CFLAGS = -Wall -Wextra -Werror
INC1 := -I ../libcore/include/
INC2 := -I ../liblist/include/

LIB := -L. ../libcore/libcore.a ../liblist/liblist.a -lcurses

CORE_SRC = visual.c main.c process_create.c
CORE = $(addprefix src/, $(CORE_SRC))

OBJ_LIST = $(patsubst %.c, %.o, $(CORE))
BIN_PATH = obj
BIN = $(addprefix $(BIN_PATH)/, $(OBJ_LIST))
DEP := $(BIN:%.o=%.d)

all : $(NAME)

lib: 
	make re -C ../libcore/
	make re -C ../liblist/

$(NAME) : $(BIN)
	$(CC) $(CFLAGS) $(INC1) $(INC2) $(LIB) -o $@ $^ 

$(BIN_PATH)/%.o :  %.c
	@mkdir -p $(BIN_PATH)
	@mkdir -p $(addprefix $(BIN_PATH)/,$(dir $<))
	$(CC) $(CFLAGS) $(INC1) $(INC2) -MMD -c $< -o $@

-include $(DEP)

clean :
	rm -rf $(BIN_PATH)

fclean : clean
	rm -f $(NAME)

re : fclean all
