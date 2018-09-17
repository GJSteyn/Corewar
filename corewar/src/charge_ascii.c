/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charge_ascii.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 08:19:15 by kmarchan          #+#    #+#             */
/*   Updated: 2018/09/17 08:18:48 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "visualiser.h"
#include "corewar.h"

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

void					charge(void)
{
	int i;

	i = 0;
	cha_(0);
	rge(6);
}
