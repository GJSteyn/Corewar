/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   authors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 08:22:07 by kmarchan          #+#    #+#             */
/*   Updated: 2018/09/14 11:36:18 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "visualiser.h"

static void		ws_gs(int i)
{
	mvprintw(Y_CHAMP + i++, FOV2 - (127 / 2), " db   dXb   db .dXXXX. dXXXXXb"
	" dXXXXXb  dXXXb  dXXXXXb dXXXXb. .dXXXX.        dXXXb  .dXXXX. dXXXXXXb "
	"dXXXXXb db    db dXb   db");
	mvprintw(Y_CHAMP + i++, FOV2 - (127 / 2), " XX   XXX   XX XX'  YP XX'    "
	" XX'     XX' YXb XX'     XX  `XD XX'  YP       XX' YXb XX'  YP `\"\"XX\""
	"\"' XX'     `Xb  dX' XXXo  XX");
	mvprintw(Y_CHAMP + i++, FOV2 - (127 / 2), " XX   XXX   XX `Xbo.   XXooooo"
	" XXooooo XX      XXooooo XXoobY' `Xbo.         XX      `Xbo.      XX    "
	"XXooooo  `XbdX'  XXVXo XX");
	mvprintw(Y_CHAMP + i++, FOV2 - (127 / 2), " YX   XXX   XX   `YXb. XX\"\"\""
	"\"\" XX\"\"\"\"\" XX  ooo XX\"\"\"\"\" XX`Xb     `YXb.       XX  ooo   `Y"
	"Xb.    XX    XX\"\"\"\"\"    XX    XX VXoXX");
	mvprintw(Y_CHAMP + i++, FOV2 - (127 / 2), " `Xb dX'Xb dX' db   XD XX.     "
	"XX.     XX. \"X\" XX.     XX `XX. db   XD       XX. \"X\" db   XD    XX  "
	"  XX.        XX    XX  VXXX");
	mvprintw(Y_CHAMP + i++, FOV2 - (127 / 2), "  `XbX' `XdX'  `XXXXY' YXXXXXP "
	"YXXXXXP  YXXXP  YXXXXXP XX   YD `XXXXY'        YXXXP  `XXXXY'    YP    YX"
	"XXXXP    YP    VP   VXP");
}

static void		ps_km(int i)
{
	mvprintw(Y_CHAMP + i++, FOV2 - (127 / 2), "dXXXXb. .dXXXX. dXXXXXXb db    "
	"db dXXXXb. dXXXXb. .dXXXX.    db   dD .XXb  dXX.  .dXb.  dXXXXb.  .oXXb. "
	"db   db  .dXb.  dXb   db");
	mvprintw(Y_CHAMP + i++, FOV2 - (127 / 2), "XX  `XD XX'  YP `\"\"XX\"\"' XX"
	"    XX XX  `XD XX  `XD XX'  YP    XX ,XP' XX'YbdP`XX dX' `Xb XX  `XD dXP "
	" YX XX   XX dX' `Xb XXXx  XX");
	mvprintw(Y_CHAMP + i++, FOV2 - (127 / 2), "XXxxdD  'Xbo.      XX    XX    "
	"XX XXoooY  XXoooY  'Xbo.      XX,XP   XX  XX  XX XXoooXX XXoobY' XP      "
	"XXoooXX XXoooXX XXVXx XX");
	mvprintw(Y_CHAMP + i++, FOV2 - (127 / 2), "XX\"\"\"     `YXb.    XX    XX "
	"   XX XX\"\"\"b. XX\"\"\"b.   `YXb.    XX`Xb   XX  XX  XX XX\"\"\"XX XX`X"
	"b   Xb      XX\"\"\"XX XX\"\"\"XX XX VXxXX ");
	mvprintw(Y_CHAMP + i++, FOV2 - (127 / 2), "XX      db   XD    XX    XXb  d"
	"XX XX   XD XX   XD db   XD    XX `XX. XX  XX  XX XX   XX XX `XX. YXb  dX "
	"XX   XX XX   XX XX  VXXX");
	mvprintw(Y_CHAMP + i++, FOV2 - (127 / 2), "XX      `XXXXY'    YP    \"YXXX"
	"XP' YXXXXP' YXXXXP' `XXXXY'    YP   YD YP  YP  YP YP   YP XX   YD  `YXXP'"
	" YP   YP YP   YP VP   VXP");
}

void			authors(void)
{
	int i;

	i = 37;
	wattron(stdscr, COLOR_PAIR(1));
	ws_gs(i);
	i = 44;
	ps_km(i);
	wattroff(stdscr, COLOR_PAIR(1));
}

