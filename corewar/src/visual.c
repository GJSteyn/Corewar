/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 08:00:07 by kmarchan          #+#    #+#             */
/*   Updated: 2018/09/07 12:13:48 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <curses.h>
#include <time.h>
#include 

void	print_logo()
{
	int i;
	int fd;
	char *buff;

	i = 3;
	if ((buff = f_get_line ("corewar_ascii.txt", O_RDONLY)) < 0)
	{
		mvprintw(i ,65 * 3, "WRONG FILE");
		exit(0);
	}
	lseek(fd, AT_CODE, SEEK_SET);
	{
		mvprintw(i ,65 * 3, "%s\n", buff);
		i++;
	}

}

int		visual(void)//t_vis *vis)
{
	int l;
	int c;
	int i;
	i = -1;
	c = 2;
	l = 2;

	initscr();
	// getmaxx(stdscr);
	while (++i < MEM_SIZE)
	{
		if (i % 64 == 0)
		{
			printw("\n");
			l++;
			c = 2;
		}
		if (g_env.memory[i] > 0)
		{
			mvprintw(l, c, "%.2hhx", g_env.memory[i]);
			c += 3;
		}
		else
		{
			mvprintw(l, c, "__ ");
			c += 3;
		}
	}
	print_logo();
	// mvprintw(2,65 * 3, "      __________________");
	// mvprintw(3,65 * 3, "     /\\  ______________ \\");
	// mvprintw(4,65 * 3, "    /::\\ \\ZZZZZZZZZZZZ/\\ \\");
	// mvprintw(5,65 * 3, "   /:/\\.\\ \\        /:/\\:\\ \\");
	// mvprintw(6,65 * 3, "  /:/Z/\\:\\ \\      /:/Z/\\:\\ \\");
	// mvprintw(7,65 * 3, " /:/Z/__\\:\\ \\____/:/Z/  \\:\\ \\");
	// mvprintw(8,65 * 3, "/:/Z/____\\:\\ \\___\\/Z/    \\:\\ \\");
	// mvprintw(9,65 * 3, "\\:\\ \\ZZZZZ\\:\\ \\ZZ/\\ \\     \\:\\ \\");
	// mvprintw(10,65 * 3, " \\:\\ \\     \\:\\ \\ \\:\\ \\     \\:\\ \\");
	// mvprintw(11,65 * 3, "  \\:\\ \\     \\:\\ \\_\\;\\_\\_____\\;\\ \\");
	// mvprintw(12,65 * 3, "   \\:\\ \\     \\:\\_________________\\");
	// mvprintw(13,65 * 3, "    \\:\\ \\    /:/ZZZZZZZZZZZZZZZZZ/");
	// mvprintw(14,65 * 3, "     \\:\\ \\  /:/Z/    \\:\\ \\  /:/Z/");
	// mvprintw(15,65 * 3, "      \\:\\ \\/:/Z/      \\:\\ \\/:/Z/");
	// mvprintw(16,65 * 3, "       \\:\\/:/Z/________\\;\\/:/Z/");
	// mvprintw(17,65 * 3, "        \\::/Z/_______itz__\\/Z/");
	// mvprintw(18,65 * 3, "         \\/ZZZZZZZZZZZZZZZZZ/");
	refresh();
	usleep(100000000);
	// endwin();
	return (1);
}
