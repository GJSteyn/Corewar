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

# BOTS="Car.s"
# BOTC="Car.cor"
# echo -n -e "Default    asm: Bot:|\x1B[32m "
# echo -n $BOTS
# echo -n -e " \x1B[0m| :"
# # echo -n -e $YEL
# $DEF_ASM bots/$BOTS
# # echo -n -e $NRM
# mv bots/$BOTC $DECOR
# echo -n -e "challanger asm: Bot:|\x1B[32m "
# echo -n $BOTS
# echo -n -e " \x1B[0m| :"
# # echo -n -e $YEL
# $CHL_ASM bots/$BOTS
# # echo -n -e $NRM
# mv bots/$BOTC $CHCOR
# echo ""


# # no output
# BOTS="Death.s"
# BOTC="Death.cor"
# echo -n -e "Default    asm: Bot:|\x1B[32m "
# echo -n $BOTS
# echo -n -e " \x1B[0m| :"
# echo -n -e $YEL
# $DEF_ASM bots/$BOTS
# echo -n -e $NRM
# # mv bots/$BOTC $DECOR
# echo -n -e "challanger asm: Bot:|\x1B[32m "
# echo -n $BOTS
# echo -n -e " \x1B[0m| :"
# echo -n -e $YEL
# $CHL_ASM bots/$BOTS
# echo -n -e $NRM
# # mv bots/$BOTC $CHCOR
# echo ""

# BOTS="ex.s"
# BOTC="ex.cor"
# echo -n -e "Default    asm: Bot:|\x1B[32m "
# echo -n $BOTS
# echo -n -e " \x1B[0m| :"
# # echo -n -e $YEL
# $DEF_ASM bots/$BOTS
# # echo -n -e $NRM
# mv bots/$BOTC $DECOR
# echo -n -e "challanger asm: Bot:|\x1B[32m "
# echo -n $BOTS
# echo -n -e " \x1B[0m| :"
# # echo -n -e $YEL
# $CHL_ASM bots/$BOTS
# # echo -n -e $NRM
# mv bots/$BOTC $CHCOR
# echo ""


# BOTS="Gagnant.s"
# BOTC="Gagnant.cor"
# echo -n -e "Default    asm: Bot:|\x1B[32m "
# echo -n $BOTS
# echo -n -e " \x1B[0m| :"
# # echo -n -e $YEL
# $DEF_ASM bots/$BOTS
# # echo -n -e $NRM
# mv bots/$BOTC $DECOR
# echo -n -e "challanger asm: Bot:|\x1B[32m "
# echo -n $BOTS
# echo -n -e " \x1B[0m| :"
# # echo -n -e $YEL
# $CHL_ASM bots/$BOTS
# # echo -n -e $NRM
# mv bots/$BOTC $CHCOR
# echo ""

# BOTS="jumper.s"
# BOTC="jumper.cor"
# echo -n -e "Default    asm: Bot:|\x1B[32m "
# echo -n $BOTS
# echo -n -e " \x1B[0m| :"
# # echo -n -e $YEL
# $DEF_ASM bots/$BOTS
# # echo -n -e $NRM
# mv bots/$BOTC $DECOR
# echo -n -e "challanger asm: Bot:|\x1B[32m "
# echo -n $BOTS
# echo -n -e " \x1B[0m| :"
# # echo -n -e $YEL
# $CHL_ASM bots/$BOTS
# # echo -n -e $NRM
# mv bots/$BOTC $CHCOR
# echo ""

# # no output
# echo -n -e "Default    asm: Bot:|\x1B[32m lde.s \x1B[0m| :"
# echo -n -e $YEL
# $DEF_ASM bots/lde.s
# echo -n -e $NRM
# echo -n -e "challanger asm: Bot:|\x1B[32m lde.s \x1B[0m| :"
# echo -n -e $YEL
# $CHL_ASM bots/lde.s
# echo -n -e $NRM
# echo ""

# echo ""
# echo -n -e "Default    asm: Bot:|\x1B[32m leeloo.s \x1B[0m| :"
# echo -n -e $YEL
# $DEF_ASM bots/leeloo.s
# echo -n -e $NRM
# echo -n -e "challanger asm: Bot:|\x1B[32m leeloo.s \x1B[0m| :"
# echo -n -e $YEL
# $CHL_ASM bots/leeloo.s
# echo -n -e $NRM
# echo ""


# BOTS="mat.s"
# BOTC="mat.cor"
# echo -n -e "Default    asm: Bot:|\x1B[32m "
# echo -n $BOTS
# echo -n -e " \x1B[0m| :"
# echo -n -e $YEL
# $DEF_ASM bots/$BOTS
# echo -n -e $NRM
# echo -n -e "challanger asm: Bot:|\x1B[32m "
# echo -n $BOTS
# echo -n -e " \x1B[0m| :"
# echo -n -e $YEL
# $CHL_ASM bots/$BOTS
# echo -n -e $NRM
# echo ""

# BOTS="maxidef.s"
# BOTC="maxidef.cor"
# echo -n -e "Default    asm: Bot:|\x1B[32m "
# echo -n $BOTS
# echo -n -e " \x1B[0m| :"
# $DEF_ASM bots/$BOTS
# mv bots/$BOTC $DECOR
# echo -n -e "challanger asm: Bot:|\x1B[32m "
# echo -n $BOTS
# echo -n -e " \x1B[0m| :"
# $CHL_ASM bots/$BOTS
# mv bots/$BOTC $CHCOR
# echo ""

# BOTS="mortel.s"
# BOTC="mortel.cor"
# echo -n -e "Default    asm: Bot:|\x1B[32m "
# echo -n $BOTS
# echo -n -e " \x1B[0m| :"
# # echo -n -e $YEL
# $DEF_ASM bots/$BOTS
# # echo -n -e $NRM
# mv bots/$BOTC $DECOR
# echo -n -e "challanger asm: Bot:|\x1B[32m "
# echo -n $BOTS
# echo -n -e " \x1B[0m| :"
# # echo -n -e $YEL
# $CHL_ASM bots/$BOTS
# # echo -n -e $NRM
# mv bots/$BOTC $CHCOR
# echo ""

# BOTS="new.s"
# BOTC="new.cor"
# echo -n -e "Default    asm: Bot:|\x1B[32m "
# echo -n $BOTS
# echo -n -e " \x1B[0m| :"
# echo -n -e $YEL
# $DEF_ASM bots/$BOTS
# echo -n -e $NRM
# # mv bots/$BOTC $DECOR
# echo -n -e "challanger asm: Bot:|\x1B[32m "
# echo -n $BOTS
# echo -n -e " \x1B[0m| :"
# echo -n -e $YEL
# $CHL_ASM bots/$BOTS
# echo -n -e $NRM
# # mv bots/$BOTC $CHCOR
# echo ""

# BOTS="Octobre_Rouge_v4.2.s"
# BOTC="Octobre_Rouge_v4.2.cor"
# echo -n -e "Default    asm: Bot:|\x1B[32m "
# echo -n $BOTS
# echo -n -e " \x1B[0m| :"
# # echo -n -e $YEL
# $DEF_ASM bots/$BOTS
# # echo -n -e $NRM
# mv bots/$BOTC $DECOR
# echo -n -e "challanger asm: Bot:|\x1B[32m "
# echo -n $BOTS
# echo -n -e " \x1B[0m| :"
# # echo -n -e $YEL
# $CHL_ASM bots/$BOTS
# # echo -n -e $NRM
# mv bots/$BOTC $CHCOR
# echo ""

# BOTS="sebc.s"
# BOTC="sebc.cor"
# echo -n -e "Default    asm: Bot:|\x1B[32m "
# echo -n $BOTS
# echo -n -e " \x1B[0m| :"
# echo -n -e $YEL
# $DEF_ASM bots/$BOTS
# echo -n -e $NRM
# # mv bots/$BOTC $DECOR
# echo -n -e "challanger asm: Bot:|\x1B[32m "
# echo -n $BOTS
# echo -n -e " \x1B[0m| :"
# echo -n -e $YEL
# $CHL_ASM bots/$BOTS
# echo -n -e $NRM
# # mv bots/$BOTC $CHCOR
# echo ""

# echo -e "\x1B[31m"

# cmp $DECOR$"barriere.cor" $CHCOR$"barriere.cor"
# cmp $DECOR$"Car.cor" $CHCOR$"Car.cor"
# cmp $DECOR$"ex.cor" $CHCOR$"ex.cor"
# cmp $DECOR$"Gagnant.cor" $CHCOR$"Gagnant.cor"
# cmp $DECOR$"jumper.cor" $CHCOR$"jumper.cor"
# cmp $DECOR$"maxidef.cor" $CHCOR$"maxidef.cor"
# cmp $DECOR$"mortel.cor" $CHCOR$"mortel.cor"
# cmp $DECOR$"Octobre_Rouge_v4.2.cor" $CHCOR$"Octobre_Rouge_v4.2.cor"

# echo -e "\x1B[0m"