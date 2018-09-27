# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/27 10:21:42 by pstubbs           #+#    #+#              #
#    Updated: 2018/09/27 10:22:12 by pstubbs          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Corewars

all: $(NAME)

$(NAME) :
	make -C libcore/
	make -C asm/
	# make -C corewar/

clean:
	make clean -C asm/
	make clean -C libcore/
	# make clean  -C corewar/
	

fclean: clean
	make fclean -C asm/
	make fclean -C libcore/
	# make fclean  -C corewar/

re: fclean all
