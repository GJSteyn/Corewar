# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/30 06:27:18 by wseegers          #+#    #+#              #
#    Updated: 2018/09/10 06:51:12 by wseegers         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libcore.a
CC = clang
CFLAGS = -Wall -Wextra -Werror
INC := -I include

F_IO_SRC = f_feedf.c f_initf.c f_openf.c f_readf.c f_writef.c f_stdio.c\
		   f_next_line.c f_skip_line.c f_closef.c
F_IO = $(addprefix f_io/, $(F_IO_SRC))

F_MATH_SRC = f_abs.c  f_max.c  f_min.c f_quadratic_discriminant.c\
			 f_quadratic_solve.c
F_MATH = $(addprefix f_math/, $(F_MATH_SRC))

F_MEMORY_SRC = f_membzero.c f_memchr.c f_memcpy.c f_memmove.c f_rawmemchr.c\
			   f_memalloc.c f_memccpy.c f_memcmp.c f_memdel.c f_memset.c\
			   f_ptrdiff.c f_memrev.c f_swapptr.c
F_MEMORY = $(addprefix f_memory/, $(F_MEMORY_SRC))

F_PRINT_SRC = f_print_char.c f_print_nbr.c  f_print_str.c pf_handle_str.c\
			  f_printf.c pf_get_tag.c pf_parse_tag.c pf_init_tag.c\
			  pf_nbrtostr.c pf_wctostr.c pf_wstrtostr.c f_vdprintf.c\
			  pf_handle_int1.c f_putchar.c pf_buffer.c pf_handle_char.c\
			  pf_handle_int2.c pf_get_width_prec.c f_fprintf.c
F_PRINT = $(addprefix f_print/, $(F_PRINT_SRC))

F_STRING_SRC = f_strcmp.c f_strdel.c f_strdup.c f_strlcat.c f_strlen.c\
			   f_strnew.c f_strnlen.c f_strccpy.c f_strresize.c f_strncpy.c\
			   f_strchr.c f_islower.c f_toupper.c f_isspace.c f_isblank.c\
			   f_atoi.c f_strtol.c f_isdigit.c f_strcpy.c f_strjoin.c\
			   f_strstr.c f_strncmp.c f_itoa_base.c f_striter.c f_strsplit.c\
			   f_strarrdel.c f_isdigits.c f_strcjoin.c f_atof.c f_strrchar.c\
			   f_strsub.c f_isupper.c f_isalpha.c f_isalnum.c f_strtrim.c
F_STRING = $(addprefix f_string/, $(F_STRING_SRC))

F_CNTL_SRC = f_exit.c
F_CNTL = $(addprefix f_cntl/, $(F_CNTL_SRC))

CORE_SRC = f_atol.c f_isspace_notnewl.c f_little_to_big_endian.c \
		   f_big_to_little_endian.c f_dynamicstring.c op.c
CORE = $(addprefix core/, $(CORE_SRC))

S_VECTOR_SRC = vector_add.c vector_create.c vector_free.c vector_get.c\
			   vector_init.c vector_remove.c vector_resize.c vector_set.c
S_VECTOR = $(addprefix s_vector/, $(S_VECTOR_SRC))

OBJ_LIST = $(patsubst %.c, %.o, $(F_IO) $(F_MATH) $(F_MEMORY) $(F_PRINT)\
				$(F_STRING) $(F_CNTL) $(S_VECTOR) $(CORE))
BIN_PATH = bin
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
