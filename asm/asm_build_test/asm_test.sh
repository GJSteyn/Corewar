#!/bin/bash

DEF_ASM="./Default_asm"
CHL_ASM="./asm"

DECOR="default_cor_files/"
CHCOR="challenger_cor_files/"

YEL="\x1B[33m"
NRM="\x1B[0m"

function output_broken_bot() {
	echo -n -e "Default    asm: Bot:|\x1B[32m "
	echo -n $1
	echo -n -e " \x1B[0m| :"
	echo -n -e $YEL
	$DEF_ASM bots/$1
	echo -n -e $NRM
	echo -n -e "challanger asm: Bot:|\x1B[32m "
	echo -n $1
	echo -n -e " \x1B[0m| :"
	echo -n -e $YEL
	$CHL_ASM bots/$1
	echo -n -e $NRM
	echo ""
}

function output_bot() {
	echo -n -e "Default    asm: Bot:|\x1B[32m "
	echo -n $1
	echo -n -e " \x1B[0m| :"
	$DEF_ASM bots/$1
	mv bots/$2 $DECOR
	echo -n -e "challanger asm: Bot:|\x1B[32m "
	echo -n $1
	echo -n -e " \x1B[0m| :"
	$CHL_ASM bots/$1
	mv bots/$2 $CHCOR
	echo ""
}

#no output
BOTS="Backward.s"
BOTC="Backward.cor"
output_broken_bot $BOTS


BOTS="barriere.s"
BOTC="barriere.cor"
output_bot $BOTS $BOTC

BOTS="Car.s"
BOTC="Car.cor"
output_bot $BOTS $BOTC

# # no output
BOTS="Death.s"
BOTC="Death.cor"
output_broken_bot $BOTS

BOTS="ex.s"
BOTC="ex.cor"
output_bot $BOTS $BOTC

BOTS="Gagnant.s"
BOTC="Gagnant.cor"
output_bot $BOTS $BOTC


BOTS="jumper.s"
BOTC="jumper.cor"
output_bot $BOTS $BOTC

# # no output
BOTS="lde.s"
BOTC="lde.cor"
output_broken_bot $BOTS

echo ""
BOTS="leeloo.s"
BOTC="leeloo.cor"
output_broken_bot $BOTS $BOTC

BOTS="mat.s"
BOTC="mat.cor"
output_broken_bot $BOTS $BOTC


BOTS="maxidef.s"
BOTC="maxidef.cor"
output_bot $BOTS $BOTC


BOTS="mortel.s"
BOTC="mortel.cor"
output_bot $BOTS $BOTC

BOTS="new.s"
BOTC="new.cor"
output_broken_bot $BOTS


BOTS="Octobre_Rouge_v4.2.s"
BOTC="Octobre_Rouge_v4.2.cor"
output_bot $BOTS $BOTC

BOTS="sebc.s"
BOTC="sebc.cor"
output_broken_bot $BOTS

echo -e "\x1B[31m"

cmp $DECOR$"barriere.cor" $CHCOR$"barriere.cor"
cmp $DECOR$"Car.cor" $CHCOR$"Car.cor"
cmp $DECOR$"ex.cor" $CHCOR$"ex.cor"
cmp $DECOR$"Gagnant.cor" $CHCOR$"Gagnant.cor"
cmp $DECOR$"jumper.cor" $CHCOR$"jumper.cor"
cmp $DECOR$"maxidef.cor" $CHCOR$"maxidef.cor"
cmp $DECOR$"mortel.cor" $CHCOR$"mortel.cor"
cmp $DECOR$"Octobre_Rouge_v4.2.cor" $CHCOR$"Octobre_Rouge_v4.2.cor"

echo -e "\x1B[0m"