#!/bin/bash

DEF_ASM="./bots/Default_asm"
CHL_ASM="../asm"

DECOR="default_cor_files/"
CHCOR="challenger_cor_files/"

mkdir $DECOR
mkdir $CHCOR

YEL="\x1B[33m"
NRM="\x1B[0m"
RED="\x1B[31m"

function output_broken_bot() {
	echo -n -e "Default    asm: Bot:|\x1B[32m "
	echo -n $1
	echo -n -e " \x1B[0m| :"
	echo -n -e $YEL
	$DEF_ASM bots/$1
	echo -n -e $NRM
	echo -n -e "Challenger asm: Bot:|\x1B[32m "
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
	echo -n -e "Challenger asm: Bot:|\x1B[32m "
	echo -n $1
	echo -n -e " \x1B[0m| :"
	$CHL_ASM bots/$1
	echo -n -e $RED
	mv bots/$2 $CHCOR
	cmp $DECOR$2 $CHCOR$2
	echo -n -e $NRM
	echo ""
}

BOTS="Backward.s"
BOTC="Backward.cor"
output_broken_bot $BOTS

BOTS="barriere.s"
BOTC="barriere.cor"
output_bot $BOTS $BOTC

BOTS="Car.s"
BOTC="Car.cor"
output_bot $BOTS $BOTC

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

BOTS="slider2.s"
BOTC="slider2.cor"
output_bot $BOTS $BOTC

BOTS="Survivor.s"
BOTC="Survivor.cor"
output_broken_bot $BOTS $BOTC

BOTS="tdc2.s"
BOTC="tdc2.cor"
output_broken_bot $BOTS $BOTC

BOTS="tdc3.s"
BOTC="tdc3.cor"
output_broken_bot $BOTS $BOTC

BOTS="tdc4.s"
BOTC="tdc4.cor"
output_broken_bot $BOTS $BOTC

BOTS="Torpille.s"
BOTC="Torpille.cor"
output_broken_bot $BOTS $BOTC

BOTS="toto.s"
BOTC="toto.cor"
output_bot $BOTS $BOTC

BOTS="_.s"
BOTC="_.cor"
output_bot $BOTS $BOTC

BOTS="_honeybadger.s"
BOTC="_honeybadger.cor"
output_bot $BOTS $BOTC

BOTS="Asombra.s"
BOTC="Asombra.cor"
output_bot $BOTS $BOTC

BOTS="big_feet.s"
BOTC="big_feet.cor"
output_bot $BOTS $BOTC

BOTS="casimir.s"
BOTC="casimir.cor"
output_bot $BOTS $BOTC

BOTS="champ.s"
BOTC="champ.cor"
output_bot $BOTS $BOTC

BOTS="corelol.s"
BOTC="corelol.cor"
output_bot $BOTS $BOTC

BOTS="darksasuke.s"
BOTC="darksasuke.cor"
output_bot $BOTS $BOTC

BOTS="doge.s"
BOTC="doge.cor"
output_bot $BOTS $BOTC

BOTS="dubo.s"
BOTC="dubo.cor"
output_bot $BOTS $BOTC

BOTS="gedeon.s"
BOTC="gedeon.cor"
output_bot $BOTS $BOTC

BOTS="justin_bee.s"
BOTC="justin_bee.cor"
output_bot $BOTS $BOTC

BOTS="Kappa.s"
BOTC="Kappa.cor"
output_bot $BOTS $BOTC

BOTS="littlepuppy.s"
BOTC="littlepuppy.cor"
output_bot $BOTS $BOTC

BOTS="live.s"
BOTC="live.cor"
output_bot $BOTS $BOTC

BOTS="loose.s"
BOTC="loose.cor"
output_bot $BOTS $BOTC

BOTS="Machine-gun.s"
BOTC="Machine-gun.cor"
output_bot $BOTS $BOTC

BOTS="mandragore.s"
BOTC="mandragore.cor"
output_bot $BOTS $BOTC

BOTS="MarineKing.s"
BOTC="MarineKing.cor"
output_bot $BOTS $BOTC

BOTS="meowluigi.s"
BOTC="meowluigi.cor"
output_bot $BOTS $BOTC

BOTS="Misaka_Mikoto.s"
BOTC="Misaka_Mikoto.cor"
output_bot $BOTS $BOTC

BOTS="Rainbow_dash.s"
BOTC="Rainbow_dash.cor"
output_bot $BOTS $BOTC

BOTS="salamahenagalabadoun.s"
BOTC="salamahenagalabadoun.cor"
output_bot $BOTS $BOTC

BOTS="sam_2.0.s"
BOTC="sam_2.0.cor"
output_bot $BOTS $BOTC

BOTS="skynet.s"
BOTC="skynet.cor"
output_bot $BOTS $BOTC

BOTS="terminator.s"
BOTC="terminator.cor"
output_bot $BOTS $BOTC

BOTS="THUNDER.s"
BOTC="THUNDER.cor"
output_bot $BOTS $BOTC

BOTS="ultimate-surrender.s"
BOTC="ultimate-surrender.cor"
output_bot $BOTS $BOTC

BOTS="Varimathras.s"
BOTC="Varimathras.cor"
output_bot $BOTS $BOTC

BOTS="Wall.s"
BOTC="Wall.cor"
output_bot $BOTS $BOTC

BOTS="youforkmytralala.s"
BOTC="youforkmytralala.cor"
output_bot $BOTS $BOTC

BOTS="Douceur_power.s"
BOTC="Douceur_power.cor"
output_bot $BOTS $BOTC

BOTS="Explosive_kitty.s"
BOTC="Explosive_kitty.cor"
output_bot $BOTS $BOTC

BOTS="gateau.s"
BOTC="gateau.cor"
output_bot $BOTS $BOTC

BOTS="Kittystrophic.s"
BOTC="Kittystrophic.cor"
output_bot $BOTS $BOTC

BOTS="mise_a_jour_windows95.s"
BOTC="mise_a_jour_windows95.cor"
output_bot $BOTS $BOTC

BOTS="overwatch.s"
BOTC="overwatch.cor"
output_bot $BOTS $BOTC

BOTS="run_Kitty_RUN.s"
BOTC="run_Kitty_RUN.cor"
output_bot $BOTS $BOTC

BOTS="ultima.s"
BOTC="ultima.cor"
output_bot $BOTS $BOTC

BOTS="bee_gees.s"
BOTC="bee_gees.cor"
output_bot $BOTS $BOTC

BOTS="bigzork.s"
BOTC="bigzork.cor"
output_bot $BOTS $BOTC

BOTS="fluttershy.s"
BOTC="fluttershy.cor"
output_bot $BOTS $BOTC

BOTS="helltrain.s"
BOTC="helltrain.cor"
output_bot $BOTS $BOTC

BOTS="turtle.s"
BOTC="turtle.cor"
output_bot $BOTS $BOTC

BOTS="zork.s"
BOTC="zork.cor"
output_bot $BOTS $BOTC
