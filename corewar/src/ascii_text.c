/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 09:19:59 by kmarchan          #+#    #+#             */
/*   Updated: 2018/09/17 12:42:36 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "visualiser.h"

#define SLP	(500000)

void				dot_dot(void)
{
	int i;

	i = 7;
	mvprintw(Y_CHAMP + i++, FOV2 - (3 / 2), ".o.");
	mvprintw(Y_CHAMP + i++, FOV2 - (3 / 2), "`\"'");
	refresh();
	usleep(SLP);
	i = 11;
	mvprintw(Y_CHAMP + i++, FOV2 - (3 / 2), ".o.");
	mvprintw(Y_CHAMP + i++, FOV2 - (3 / 2), "`\"'");
	refresh();
	usleep(SLP);
}

void				ready(void)
{
	int i;

	i = 0;
	mvprintw(Y_CHAMP + i++, FOV2 - (37 / 2), "XX\"\"Yb XXXXXX"
	"    db    XXXXb.  Yb  dP");
	mvprintw(Y_CHAMP + i++, FOV2 - (37 / 2), "XX__dP XX__    "
	" dPYb    XI  Yb  YbdP");
	mvprintw(Y_CHAMP + i++, FOV2 - (37 / 2), "XX\"Yb  XX\"\" "
	"   dP__Yb   XI  dY   XP");
	mvprintw(Y_CHAMP + i++, FOV2 - (37 / 2), "XX  Yb XXXXXX dP"
	"\"\"\"\"Yb XXXXY\"   dP");
	refresh();
	usleep(SLP);
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
	usleep(SLP);
	dot_dot();
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
