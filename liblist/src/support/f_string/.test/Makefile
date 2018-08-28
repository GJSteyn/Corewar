# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/28 05:56:36 by wseegers          #+#    #+#              #
#    Updated: 2018/05/28 06:24:01 by wseegers         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
CFLAGS = -Wall -Wextra -Werror
INC := -I ../include -I ../../include

SRC := $(wildcard test_f_str*.c)
TESTS := $(SRC:test_%.c=run_%)
BIN := $(wildcard ../../bin/*.o)

all : $(TESTS)

run_% : test_%.c 
	$(CC) $(CFLAGS) $(INC) -o $@ $< $(BIN)

clean :
	@echo "Nothing to clean"

fclean :
	rm -f $(TESTS)
