@ Interact with cuttable tree
EventScript_CutTree:: @ 82906BB
	lockall
	//goto_if_unset FLAG_BADGE01_GET, EventScript_CheckTreeCantCut
	checkitem ITEM_CUT, 1
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_CheckTreeCantCut
	//setfieldeffectargument 0, ITEM_CUT //might be unneccesary
	setvar VAR_0x8000, ITEM_CUT
	//bufferpartymonnick 0, VAR_RESULT
	//buffermovename 1, MOVE_CUT
	msgbox Text_WantToCut, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_CancelCut
	//msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
	dofieldeffect FLDEFF_USE_CUT_ON_TREE
	waitstate
	goto EventScript_CutTreeDown
	end

@ Use cut from party menu
EventScript_UseCut:: @ 8290705
	lockall
	dofieldeffect FLDEFF_USE_CUT_ON_TREE
	waitstate
	goto EventScript_CutTreeDown
	end

EventScript_CutTreeDown:: @ 8290710
	applymovement VAR_LAST_TALKED, Movement_CutTreeDown
	waitmovement 0
	removeobject VAR_LAST_TALKED
	releaseall
	end

Movement_CutTreeDown: @ 829071F
	cut_tree
	step_end

EventScript_CheckTreeCantCut:: @ 8290721
	msgbox Text_CantCut, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelCut:: @ 829072B
	closemessage
	releaseall
	end

Text_WantToCut: @ 829072E
	.string "This tree looks like it can be\n"
	.string "chopped down!\p"
	.string "Would you like to chop\n"
	.string "it with the Sharp Axe?$"

Text_MonUsedFieldMove: @ 8290771
	.string "{STR_VAR_1} used {STR_VAR_2}!$"

Text_CantCut: @ 829077D
	.string "This tree looks like it can be\n"
	.string "chopped down!$"

@ Interact with smashable rock
EventScript_RockSmash:: @ 82907A6
	lockall
	//goto_if_unset FLAG_BADGE03_GET, EventScript_CantSmashRock
	checkitem ITEM_ROCK_SMASH, 1
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_CantSmashRock
	setvar VAR_0x8000, ITEM_ROCK_SMASH
	//setfieldeffectargument 0, ITEM_ROCK_SMASH
	//bufferpartymonnick 0, VAR_RESULT
	//buffermovename 1, MOVE_ROCK_SMASH
	msgbox Text_WantToSmash, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_CancelSmash
	//msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
	dofieldeffect FLDEFF_USE_ROCK_SMASH
	waitstate
	goto EventScript_SmashRock
	end

@ Use rock smash from party menu
EventScript_UseRockSmash:: @ 82907F0
	lockall
	dofieldeffect FLDEFF_USE_ROCK_SMASH
	waitstate
	goto EventScript_SmashRock
	end

EventScript_SmashRock:: @ 82907FB
	applymovement VAR_LAST_TALKED, Movement_SmashRock
	waitmovement 0
	removeobject VAR_LAST_TALKED
	specialvar VAR_RESULT, TryUpdateRusturfTunnelState
	compare VAR_RESULT, TRUE
	goto_if_eq EventScript_EndSmash
	special RockSmashWildEncounter
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_EndSmash
	waitstate
	releaseall
	end

EventScript_EndSmash:: @ 8290829
	releaseall
	end

Movement_SmashRock: @ 829082B
	rock_smash_break
	step_end

EventScript_CantSmashRock:: @ 829082D
	msgbox Text_CantSmash, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelSmash:: @ 8290837
	closemessage
	releaseall
	end

Text_WantToSmash: @ 829083A
	.string "This rock appears to be breakable.\n"
	.string "Would you like to use the Pickaxe?$"

Text_CantSmash: @ 829087F
	.string "It's a hard rock, but a strong tool\n"
	.string "may be able to smash it..$"

EventScript_StrengthBoulder:: @ 82908BA
	lockall
	//goto_if_unset FLAG_BADGE04_GET, EventScript_CantStrength
	goto_if_set FLAG_SYS_USE_STRENGTH, EventScript_CheckActivatedBoulder
	checkitem ITEM_STRENGTH, 1
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_CantStrength
	setvar VAR_0x8000, ITEM_STRENGTH
	//setfieldeffectargument 0, VAR_RESULT
	msgbox Text_WantToStrength, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_CancelStrength
	closemessage
	dofieldeffect FLDEFF_USE_STRENGTH
	waitstate
	goto EventScript_ActivateStrength
	end

EventScript_UseStrength:: @ 82908FD
	lockall
	dofieldeffect FLDEFF_USE_STRENGTH
	waitstate
	goto EventScript_ActivateStrength
	end

EventScript_ActivateStrength:: @ 8290908
	setflag FLAG_SYS_USE_STRENGTH
	//msgbox Text_MonUsedStrength, MSGBOX_DEFAULT Eliminate HMS
	releaseall
	end

EventScript_CantStrength:: @ 8290915
	msgbox Text_CantStrength, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CheckActivatedBoulder:: @ 829091F
	msgbox Text_StrengthActivated, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelStrength:: @ 8290929
	closemessage
	releaseall
	end

Text_WantToStrength: @ 829092C
	.string "It's a big boulder, but you\n"
	.string "may be able to push it aside.\p"
	.string "Would you like to use \n"
	.string "the Golden Gauntlets?$"

Text_MonUsedStrength: @ 829098C
	.string "{STR_VAR_1} used STRENGTH!\p"
	.string "{STR_VAR_1}'s STRENGTH made it\n"
	.string "possible to move boulders around!$"

Text_CantStrength: @ 82909D6
	.string "It's a big boulder, but with the\n"
	.string "right equipment you \p"
	.string "may be able to push it aside.$"

Text_StrengthActivated: @ 8290A16
	.string "The Golden Gauntlets made \n"
	.string "it possible to move\p"
	.string "big boulders around.$"

EventScript_UseWaterfall:: @ 8290A49
	lockall
	checkitem ITEM_WATERFALL, 1
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_CantWaterfall
	setvar VAR_0x8000, ITEM_WATERFALL
	//bufferpartymonnick 0, VAR_RESULT
	//setfieldeffectargument 0, ITEM_WATERFALL
	msgbox Text_WantToWaterfall, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_EndWaterfall
	//msgbox Text_MonUsedWaterfall, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_WATERFALL
	goto EventScript_EndWaterfall

EventScript_CannotUseWaterfall:: @ 8290A83
	lockall

EventScript_CantWaterfall:: @ 8290A84
	msgbox Text_CantWaterfall, MSGBOX_DEFAULT

EventScript_EndWaterfall:: @ 8290A8C
	releaseall
	end

Text_CantWaterfall: @ 8290A8E
	.string "A wall of water is crashing down with\n"
	.string "a mighty roar.$"

Text_WantToWaterfall: @ 8290AC3
	.string "It's a large waterfall.\p"
	.string "Would you like to climb it\n"
	.string "with the Inner Tube Propeller?$"

Text_MonUsedWaterfall: @ 8290AFC
	.string "{STR_VAR_1} used WATERFALL.$"

EventScript_UseDive:: @ 8290B0F
	lockall
	checkitem ITEM_DIVE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_CantDive
	setvar VAR_0x8000, ITEM_DIVE
	//bufferpartymonnick 0, VAR_RESULT
	//setfieldeffectargument 0, ITEM_DIVE
	//setfieldeffectargument 1, 1
	msgbox Text_WantToDive, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_EndDive
	//msgbox Text_MonUsedDive, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_DIVE
	goto EventScript_EndDive
	end

EventScript_CantDive:: @ 8290B4E
	msgbox Text_CantDive, MSGBOX_DEFAULT
	releaseall
	end

EventScript_EndDive:: @ 8290B58
	releaseall
	end

EventScript_UseDiveUnderwater:: @ 8290B5A
	lockall
	checkitem ITEM_DIVE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_CantSurface
	setvar VAR_0x8000, ITEM_DIVE
	//bufferpartymonnick 0, VAR_RESULT
	//setfieldeffectargument 0, ITEM_DIVE
	//setfieldeffectargument 1, 1
	msgbox Text_WantToSurface, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_EndSurface
	//msgbox Text_MonUsedDive, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_DIVE
	goto EventScript_EndSurface
	end

EventScript_CantSurface:: @ 8290B99
	lockall
	msgbox Text_CantSurface, MSGBOX_DEFAULT
	goto EventScript_EndSurface
	end

EventScript_EndSurface:: @ 8290BA8
	releaseall
	end

Text_CantDive: @ 8290BAA
	.string "The sea is deep here. You\n"
	.string "may be able to go underwater.$"

Text_WantToDive: @ 8290BE8
	.string "The sea is deep here.\p"
	.string "Would you like to dive down\n"
	.string "with your Scuba Gear?$"

Text_MonUsedDive: @ 8290C1A
	.string "{STR_VAR_1} used DIVE.$"

Text_CantSurface: @ 8290C28
	.string "Light is filtering down from above.\n"
	.string "You may be able to resurface.$"

Text_WantToSurface: @ 8290C6E
	.string "Light is filtering down from above.\n"
	.string "Would you like to resurface?$"

EventScript_FailSweetScent:: @ 8290CAE
	msgbox Text_FailSweetScent, MSGBOX_SIGN
	end

Text_FailSweetScent: @ 8290CB7
	.string "Looks like there's nothing here…$"
