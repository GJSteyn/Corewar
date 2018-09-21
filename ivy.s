# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ivy.s                                              :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/21 11:05:32 by pstubbs           #+#    #+#              #
#    Updated: 2018/09/21 11:05:35 by pstubbs          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.name "Ivy"
.comment "Based off bot 'The Imp' from A. K. Dewdney in the original 1984 Scientific American article"

start:	live %-1
	 ld	%0, r1

fork1:	fork %10
	ld	%-1, r1

jump: zjmp %:start

