# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/30 11:12:55 by kmarchan          #+#    #+#              #
#    Updated: 2018/09/10 11:07:53 by wseegers         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar
CC = clang
CFLAGS = -Wall -Wextra -Werror
INC1 := -I ../libcore/include/
INC2 := -I ../liblist/include/

LIB := -L ../libcore/ -l core -L ../liblist/ -l list 

CORE_SRC = main.c process_create.c load_bot.c debug_util.c op_function.c \
		   op_live.c op_sti.c op_and.c op_zjmp.c
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
