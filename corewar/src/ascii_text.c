/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 09:19:59 by kmarchan          #+#    #+#             */
/*   Updated: 2018/09/13 12:28:20 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "visualiser.h"

#define Y_CHAMP 30
#define FOV2	(64 * 3 / 2)

static void				cha_(int i)
{
	mvprintw(Y_CHAMP + i++, FOV2 - (58 / 2), "  dXXX   dX    Xb"
	"    dXXXXXb     dXXXXXb      dXXXXX    dXXX");
	mvprintw(Y_CHAMP + i++, FOV2 - (58 / 2), " dXXX\"  dXX    X"
	"Xb  dXXXXXXXb   dXXXYXXXb    dXXXXXP   dXXXP");
	mvprintw(Y_CHAMP + i++, FOV2 - (58 / 2), "dXX'    XXX    XX"
	"X  XXX   XXXb  XXX   `XXb  dXX'      dXX'  ");
	mvprintw(Y_CHAMP + i++, FOV2 - (58 / 2), "XXX     XXX    XX"
	"X  XXX    XXX  XXX    XXX  XXX       XXX   ");
	mvprintw(Y_CHAMP + i++, FOV2 - (58 / 2), "XXX     XXX XXXXX"
	"X  XXX XXXXXX  XXX    dXX  XXX       XXX   ");
	mvprintw(Y_CHAMP + i++, FOV2 - (58 / 2), "XXX     XXX  dXXX"
	"X  XXX  XXXXX  XXX   .XXX  XXX       XXXXXX");
	mvprintw(Y_CHAMP + i++, FOV2 - (58 / 2), "XXX     XXX    XX"
	"X  XXX    XXX  XXXxxdXXX   XXX       XXXXXP");
}

static void				rge(int i)
{
	mvprintw(Y_CHAMP + i++, FOV2 - (58 / 2), "XXX     XXX    XX"
	"X  XXX    XXX  XXXXYXYXb   XXX XXXX  XXX   ");
	mvprintw(Y_CHAMP + i++, FOV2 - (58 / 2), "XXb     XXX    XX"
	"X  XXX    XXX  XXX   `XXb  XXb `XXX  XXb   ");
	mvprintw(Y_CHAMP + i++, FOV2 - (58 / 2), "XXX.    XXX    XX"
	"X  XXX    XXX  XXX    XXX  XXX   XX  XXX.  ");
	mvprintw(Y_CHAMP + i++, FOV2 - (58 / 2), " XXXbX  XXX    XX"
	"X  XXX    XXX  XXX    XXX   XX_XXXX   XXXbX");
	mvprintw(Y_CHAMP + i++, FOV2 - (58 / 2), "  YXXP  XXX    XX"
	"X  XXX    XXX  XXX    XXX    Y~YXXY    YXXP");
	mvprintw(Y_CHAMP + i++, FOV2 - (58 / 2), "               XP"
	"          XP   XP                          ");
	mvprintw(Y_CHAMP + i++, FOV2 - (58 / 2), "               Y "
	"          Y    Y                           ");
}
void				dot_dot()
{
	int i;

	i = 6;
	mvprintw(Y_CHAMP + i++, FOV2 - (3 / 2), ".o.");
	mvprintw(Y_CHAMP + i++, FOV2 - (3 / 2), "`\"'");
	refresh();
	usleep(1500000);
	i = 10;
		// write (1, "\7", 1);
	mvprintw(Y_CHAMP + i++, FOV2 - (3 / 2), ".o.");
	mvprintw(Y_CHAMP + i++, FOV2 - (3 / 2), "`\"'");
	refresh();
	usleep(1500000);
}

void				ready(void)
{
	int i;

	i = 0;
	mvprintw(Y_CHAMP + i++, FOV2 - (37 / 2), "XX\"\"Yb XXXXXX    db    XXXXb.  Yb  dP");
	mvprintw(Y_CHAMP + i++, FOV2 - (37 / 2), "XX__dP XX__     dPYb    XI  Yb  YbdP");
	mvprintw(Y_CHAMP + i++, FOV2 - (37 / 2), "XX\"Yb  XX\"\"    dP__Yb   XI  dY   XP");
	mvprintw(Y_CHAMP + i++, FOV2 - (37 / 2), "XX  Yb XXXXXX dP\"\"\"\"Yb XXXXY\"   dP");
	refresh();
	usleep(1500000);
	dot_dot();
}



void				set(void)
{
	int i;

	i = 0;
	mvprintw(Y_CHAMP + i++, FOV2 - (20 / 2), ".dP\"YX XXXXXX XXXXXX");
	mvprintw(Y_CHAMP + i++, FOV2 - (20 / 2), "`Ybo.\" XX__     XX");
	mvprintw(Y_CHAMP + i++, FOV2 - (20 / 2), "o.`YXb XX\"\"     XX");
	mvprintw(Y_CHAMP + i++, FOV2 - (20 / 2), "XbodP' XXXXXX   XX");
	refresh();
	usleep(1500000);
	dot_dot();
}

void				charge(void)
{
	int i;

	i = 0;
	cha_(0);
	rge(6);
}

void				the_corewar(void)
{
	mvprintw(Y_CHAMP, FOV2 - (58 / 2), " dP\"\"bX  dP\"Yb  XX\"\"Y"
	"b XXXXXX Yb        dP    db    XX\"\"Yb");
	mvprintw(Y_CHAMP + 1, FOV2 - (58 / 2), "dP   `\" dP   Yb XX__d"
	"P XX__    Yb  db  dP    dPYb   XX__dP");
	mvprintw(Y_CHAMP + 2, FOV2 - (58 / 2), "Yb      Yb   dP XX\"Yb"
	"  XX\"\"     YbdPYbdP    dP__Yb  XX\"Yb");
	mvprintw(Y_CHAMP + 3, FOV2 - (58 / 2), " YboodP  YbodP  XX  Yb"
	" XXXXXX    YP  YP    dP\"\"\"\"Yb XX  Yb");
	refresh();
	usleep(1500000);
}

void				the_champions(void)
{
	mvprintw(Y_CHAMP, FOV2 - (96 / 2), "XXXXXX XX  XX XXXXXX      dP"
	"\"\"8b XX  XX    db    Xb    dX XX\"\"Yb XX  dP\"Yb  XXb XX .dP\"YX");
	mvprintw(Y_CHAMP + 1, FOV2 - (96 / 2), "  XX   XX  XX XX__       dP  "
	" `\" XX  XX   dPYb   XXb  dXX XX__dP XX dP   Yb XXYbXX `Ybo. ");
	mvprintw(Y_CHAMP + 2, FOV2 - (96 / 2), "  XX   XXXXXX XX\"\"       Yb  "
	"    XXXXXX  dP__Yb  XXYbdPXX XX\"\"\"  XX Yb   dP XX YXX o.`Y8b");
	mvprintw(Y_CHAMP + 3, FOV2 - (96 / 2), "  XX   XX  XX XXXXXX      Yboo"
	"dP XX  XX dP\"\"\"\"Yb XX YY XX XX     XX  YbodP  XX  YX XbodP'");
}
