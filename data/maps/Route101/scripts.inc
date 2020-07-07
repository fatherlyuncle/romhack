Route101_MapScripts:: @ 81EBCBA
	map_script MAP_SCRIPT_ON_TRANSITION, Route101_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route101_OnFrame
	.byte 0

Route101_OnTransition: @ 81EBCC5
	call ProfBirch_EventScript_UpdateLocation
	end

Route101_OnFrame: @ 81EBCCB
	map_script_2 VAR_ROUTE101_STATE, 0, Route101_EventScript_HideMapNamePopup
	.2byte 0

Route101_EventScript_HideMapNamePopup:: @ 81EBCD5
	setflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_ROUTE101_STATE, 1
	end

Route101_EventScript_StartBirchRescue:: @ 81EBCDE
	lockall
	playbgm MUS_EVENT0, 1
	msgbox Route101_Text_HelpMe, MSGBOX_DEFAULT
	closemessage
	setobjectxy 2, 0, 15
	setobjectxy 4, 0, 16
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_EnterScene
	applymovement 2, Route101_Movement_BirchRunAway1
	applymovement 4, Route101_Movement_PoochyenaChase1
	waitmovement 0
	applymovement 4, Route101_Movement_PoochyenaChaseInCircles
	applymovement 2, Route101_Movement_BirchRunInCircles
	waitmovement 0
	applymovement 2, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	applymovement 4, Route101_Movement_PoochyenaFaceBirch
	applymovement 2, Route101_Movement_BirchFacePoochyena
	waitmovement 0
	msgbox Route101_Text_PleaseHelp, MSGBOX_DEFAULT
	closemessage
	setvar VAR_ROUTE101_STATE, 2
	releaseall
	end

Route101_EventScript_PreventExitSouth:: @ 81EBD4E
	lockall
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_PreventExitSouth
	waitmovement 0
	releaseall
	end

Route101_EventScript_PreventExitWest:: @ 81EBD64
	lockall
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_PreventExitWest
	waitmovement 0
	releaseall
	end

Route101_EventScript_PreventExitNorth:: @ 81EBD7A
	lockall
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_PreventExitNorth
	waitmovement 0
	releaseall
	end

Route101_Movement_PreventExitSouth: @ 81EBD90
	walk_up
	step_end

Route101_Movement_PreventExitWest: @ 81EBD92
	walk_right
	step_end

Route101_Movement_PreventExitNorth: @ 81EBD94
	walk_down
	step_end

Route101_Movement_PoochyenaChaseInCircles: @ 81EBD96
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	step_end

Route101_Movement_PoochyenaChase1: @ 81EBDB5
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	step_end

@ Leftover data? This command is unused.
	step_end

Route101_Movement_PoochyenaFaceBirch: @ 81EBDBD
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	step_end

Route101_Movement_EnterScene: @ 81EBDC2
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_in_place_fastest_left
	step_end

Route101_Movement_BirchRunInCircles: @ 81EBDC8
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Route101_Movement_BirchRunAway1: @ 81EBDE7
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	step_end

@ Leftover data? This command is unused.
	step_end

Route101_Movement_BirchFacePoochyena: @ 81EBDEF
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_in_place_fast_right
	step_end

Route101_Movement_Unused1: @ 81EBDF4
	walk_up
	walk_up
	step_end

Route101_Movement_Unused2: @ 81EBDF7
	walk_up
	walk_left
	walk_up
	step_end

Route101_EventScript_Youngster:: @ 81EBDFB
	msgbox Route101_Text_TakeTiredPokemonToPokeCenter, MSGBOX_NPC
	end

Route101_EventScript_Boy:: @ 81EBE04
	msgbox Route101_Text_WildPokemonInTallGrass, MSGBOX_NPC
	end

Route101_EventScript_RouteSign:: @ 81EBE0D
	msgbox Route101_Text_RouteSign, MSGBOX_SIGN
	end

Route101_EventScript_BirchsBag:: @ 81EBE16
	lock
	faceplayer
	msgbox Text_ChooseLetter, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_RESCUED_BIRCH
	scrollingmultichoice 0, 2, 3, 5, FALSE
	msgbox Text_ChoosePokemon, MSGBOX_DEFAULT
	switch VAR_RESULT
	callcase 0, Route101_Grass_Pokemon
	callcase 1, Route101_Fire_Pokemon
	callcase 2, Route101_Water_Pokemon
	callcase 3, Route101_Bug_Pokemon
	callcase 4, Route101_Normal_Pokemon
	callcase 5, Route101_Poison_Pokemon
	callcase 6, Route101_Flying_Pokemon
	callcase 7, Route101_Rock_Pokemon
	callcase 8, Route101_Ground_Pokemon
	callcase 9, Route101_Electric_Pokemon
	callcase 10, Route101_Fighting_Pokemon
	callcase 11, Route101_Steel_Pokemon
	callcase 12, Route101_Ice_Pokemon
	callcase 13, Route101_Dark_Pokemon
	callcase 14, Route101_Psychic_Pokemon
	callcase 15, Route101_Ghost_Pokemon
	callcase 16, Route101_Dragon_Pokemon
	callcase 17, Route101_Fairy_Pokemon
	closemessage
	special ChooseStarter
	waitmovement 0
	setvar VAR_STARTER_MON, 255
	setobjectxy OBJ_EVENT_ID_PLAYER, 6, 13
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	removeobject 4
	waitstate
	applymovement 2, Route101_Movement_BirchApproachPlayer
	waitmovement 0
	msgbox Route101_Text_YouSavedMe, MSGBOX_DEFAULT
	special HealPlayerParty
	setflag FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
	setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
	setvar VAR_BIRCH_LAB_STATE, 2
	setvar VAR_ROUTE101_STATE, 3
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq Route101_EventScript_HideMayInBedroom
	compare VAR_RESULT, FEMALE
	call_if_eq Route101_EventScript_HideBrendanInBedroom
	warp MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 255, 6, 5
	waitstate
	release
	end

Route101_EventScript_HideMayInBedroom:: @ 81EBE85
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	return

Route101_EventScript_HideBrendanInBedroom:: @ 81EBE89
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	return

Route101_Movement_BirchApproachPlayer: @ 81EBE8D
	walk_right
	step_end

Route101_Text_HelpMe: @ 81EBE8F
	.string "H-help me!$"

Route101_Text_PleaseHelp: @ 81EBE9A
	.string "Hello! You over there!\n"
	.string "Please! Help!\p"
	.string "In my BAG!\n"
	.string "There's a POKé BALL!$"

Route101_Text_DontLeaveMe: @ 81EBEDF
	.string "Wh-Where are you going?!\n"
	.string "Don't leave me like this!$"

Route101_Text_YouSavedMe: @ 81EBF12
	.string "PROF. BIRCH: Whew…\p"
	.string "I was in the tall grass studying wild\n"
	.string "POKéMON when I was jumped.\p"
	.string "You saved me.\n"
	.string "Thanks a lot!\p"
	.string "Oh?\p"
	.string "Hi, you're {PLAYER}{KUN}!\p"
	.string "This is not the place to chat, so come\n"
	.string "by my POKéMON LAB later, okay?$"

Route101_Text_TakeTiredPokemonToPokeCenter: @ 81EBFDD
	.string "If POKéMON get tired, take them to\n"
	.string "a POKéMON CENTER.\p"
	.string "There's a POKéMON CENTER in OLDALE\n"
	.string "TOWN right close by.$"

Route101_Text_WildPokemonInTallGrass: @ 81EC04A
	.string "Wild POKéMON will jump out at you in\n"
	.string "tall grass.\p"
	.string "If you want to catch POKéMON, you have\n"
	.string "to go into the tall grass and search.$"

Route101_Text_RouteSign: @ 81EC0C8
	.string "ROUTE 101\n"
	.string "{UP_ARROW} OLDALE TOWN$"

Route101_Grass_Pokemon:
	hidemonpic
	closemessage
	scrollingmultichoice 1, 2, 3, 5, TRUE
	compare VAR_RESULT, 0x7F
	goto_if_eq Route101_EventScript_BirchsBag
	GetStarterName
	showmonpic VAR_0x8002, 10, 3
	playmoncry VAR_0x8002, 0
	msgbox Text_YouSure, MSGBOX_YESNO
	compare VAR_RESULT, YES
	call_if_eq Route101_ImSure
	compare VAR_RESULT, NO
	goto_if_eq Route101_Grass_Pokemon
	return
	
Route101_Fire_Pokemon:
	hidemonpic
	closemessage
	scrollingmultichoice 2, 2, 3, 5, TRUE
	compare VAR_RESULT, 0x7F
	goto_if_eq Route101_EventScript_BirchsBag
	GetStarterName
	showmonpic VAR_0x8002, 10, 3
	playmoncry VAR_0x8002, 0
	msgbox Text_YouSure, MSGBOX_YESNO
	compare VAR_RESULT, YES
	call_if_eq Route101_ImSure
	compare VAR_RESULT, NO
	goto_if_eq Route101_Fire_Pokemon
	return
	
Route101_Water_Pokemon:
	hidemonpic
	closemessage
	scrollingmultichoice 3, 2, 3, 5, TRUE
	compare VAR_RESULT, 0x7F
	goto_if_eq Route101_EventScript_BirchsBag
	GetStarterName
	showmonpic VAR_0x8002, 10, 3
	playmoncry VAR_0x8002, 0
	msgbox Text_YouSure, MSGBOX_YESNO
	compare VAR_RESULT, YES
	call_if_eq Route101_ImSure
	compare VAR_RESULT, NO
	goto_if_eq Route101_Water_Pokemon
	return
	
Route101_Bug_Pokemon:
	hidemonpic
	closemessage
	scrollingmultichoice 4, 2, 3, 5, TRUE
	compare VAR_RESULT, 0x7F
	goto_if_eq Route101_EventScript_BirchsBag
	GetStarterName
	showmonpic VAR_0x8002, 10, 3
	playmoncry VAR_0x8002, 0
	msgbox Text_YouSure, MSGBOX_YESNO
	compare VAR_RESULT, YES
	call_if_eq Route101_ImSure
	compare VAR_RESULT, NO
	goto_if_eq Route101_Bug_Pokemon
	return
	
Route101_Normal_Pokemon:
	hidemonpic
	closemessage
	scrollingmultichoice 5, 2, 3, 5, TRUE
	compare VAR_RESULT, 0x7F
	goto_if_eq Route101_EventScript_BirchsBag
	GetStarterName
	showmonpic VAR_0x8002, 10, 3
	playmoncry VAR_0x8002, 0
	msgbox Text_YouSure, MSGBOX_YESNO
	compare VAR_RESULT, YES
	call_if_eq Route101_ImSure
	compare VAR_RESULT, NO
	goto_if_eq Route101_Normal_Pokemon
	return
	
Route101_Poison_Pokemon:
	hidemonpic
	closemessage
	scrollingmultichoice 6, 2, 3, 5, TRUE
	compare VAR_RESULT, 0x7F
	goto_if_eq Route101_EventScript_BirchsBag
	GetStarterName
	showmonpic VAR_0x8002, 10, 3
	playmoncry VAR_0x8002, 0
	msgbox Text_YouSure, MSGBOX_YESNO
	compare VAR_RESULT, YES
	call_if_eq Route101_ImSure
	compare VAR_RESULT, NO
	goto_if_eq Route101_Poison_Pokemon
	return

Route101_Flying_Pokemon:
	hidemonpic
	closemessage
	scrollingmultichoice 7, 2, 3, 5, TRUE
	compare VAR_RESULT, 0x7F
	goto_if_eq Route101_EventScript_BirchsBag
	GetStarterName
	showmonpic VAR_0x8002, 10, 3
	playmoncry VAR_0x8002, 0
	msgbox Text_YouSure, MSGBOX_YESNO
	compare VAR_RESULT, YES
	call_if_eq Route101_ImSure
	compare VAR_RESULT, NO
	goto_if_eq Route101_Flying_Pokemon
	return

Route101_Rock_Pokemon:
	hidemonpic
	closemessage
	scrollingmultichoice 8, 2, 3, 5, TRUE
	compare VAR_RESULT, 0x7F
	goto_if_eq Route101_EventScript_BirchsBag
	GetStarterName
	showmonpic VAR_0x8002, 10, 3
	playmoncry VAR_0x8002, 0
	msgbox Text_YouSure, MSGBOX_YESNO
	compare VAR_RESULT, YES
	call_if_eq Route101_ImSure
	compare VAR_RESULT, NO
	goto_if_eq Route101_Rock_Pokemon
	return
	
Route101_Ground_Pokemon:
	hidemonpic
	closemessage
	scrollingmultichoice 9, 2, 3, 5, TRUE
	compare VAR_RESULT, 0x7F
	goto_if_eq Route101_EventScript_BirchsBag
	GetStarterName
	showmonpic VAR_0x8002, 10, 3
	playmoncry VAR_0x8002, 0
	msgbox Text_YouSure, MSGBOX_YESNO
	compare VAR_RESULT, YES
	call_if_eq Route101_ImSure
	compare VAR_RESULT, NO
	goto_if_eq Route101_Ground_Pokemon
	return
	
Route101_Electric_Pokemon:
	hidemonpic
	closemessage
	scrollingmultichoice 10, 2, 3, 5, TRUE
	compare VAR_RESULT, 0x7F
	goto_if_eq Route101_EventScript_BirchsBag
	GetStarterName
	showmonpic VAR_0x8002, 10, 3
	playmoncry VAR_0x8002, 0
	msgbox Text_YouSure, MSGBOX_YESNO
	compare VAR_RESULT, YES
	call_if_eq Route101_ImSure
	compare VAR_RESULT, NO
	goto_if_eq Route101_Electric_Pokemon
	return
	
Route101_Fighting_Pokemon:
	hidemonpic
	closemessage
	scrollingmultichoice 11, 2, 3, 5, TRUE
	compare VAR_RESULT, 0x7F
	goto_if_eq Route101_EventScript_BirchsBag
	GetStarterName
	showmonpic VAR_0x8002, 10, 3
	playmoncry VAR_0x8002, 0
	msgbox Text_YouSure, MSGBOX_YESNO
	compare VAR_RESULT, YES
	call_if_eq Route101_ImSure
	compare VAR_RESULT, NO
	goto_if_eq Route101_Fighting_Pokemon
	return
	
Route101_Steel_Pokemon:
	hidemonpic
	closemessage
	scrollingmultichoice 12, 2, 3, 5, TRUE
	compare VAR_RESULT, 0x7F
	goto_if_eq Route101_EventScript_BirchsBag
	GetStarterName
	showmonpic VAR_0x8002, 10, 3
	playmoncry VAR_0x8002, 0
	msgbox Text_YouSure, MSGBOX_YESNO
	compare VAR_RESULT, YES
	call_if_eq Route101_ImSure
	compare VAR_RESULT, NO
	goto_if_eq Route101_Steel_Pokemon
	return
	
Route101_Ice_Pokemon:
	hidemonpic
	closemessage
	scrollingmultichoice 13, 2, 3, 5, TRUE
	compare VAR_RESULT, 0x7F
	goto_if_eq Route101_EventScript_BirchsBag
	GetStarterName
	showmonpic VAR_0x8002, 10, 3
	playmoncry VAR_0x8002, 0
	msgbox Text_YouSure, MSGBOX_YESNO
	compare VAR_RESULT, YES
	call_if_eq Route101_ImSure
	compare VAR_RESULT, NO
	goto_if_eq Route101_Ice_Pokemon
	return
	
Route101_Dark_Pokemon:
	hidemonpic
	closemessage
	scrollingmultichoice 14, 2, 3, 5, TRUE
	compare VAR_RESULT, 0x7F
	goto_if_eq Route101_EventScript_BirchsBag
	GetStarterName
	showmonpic VAR_0x8002, 10, 3
	playmoncry VAR_0x8002, 0
	msgbox Text_YouSure, MSGBOX_YESNO
	compare VAR_RESULT, YES
	call_if_eq Route101_ImSure
	compare VAR_RESULT, NO
	goto_if_eq Route101_Murkrow_Pokemon
	return
	
Route101_Psychic_Pokemon:
	hidemonpic
	closemessage
	scrollingmultichoice 15, 2, 3, 5, TRUE
	compare VAR_RESULT, 0x7F
	goto_if_eq Route101_EventScript_BirchsBag
	GetStarterName
	showmonpic VAR_0x8002, 10, 3
	playmoncry VAR_0x8002, 0
	msgbox Text_YouSure, MSGBOX_YESNO
	compare VAR_RESULT, YES
	call_if_eq Route101_ImSure
	compare VAR_RESULT, NO
	goto_if_eq Route101_Psychic_Pokemon
	return
	
Route101_Ghost_Pokemon:
	hidemonpic
	closemessage
	scrollingmultichoice 16, 2, 3, 5, TRUE
	compare VAR_RESULT, 0x7F
	goto_if_eq Route101_EventScript_BirchsBag
	GetStarterName
	showmonpic VAR_0x8002, 10, 3
	playmoncry VAR_0x8002, 0
	msgbox Text_YouSure, MSGBOX_YESNO
	compare VAR_RESULT, YES
	call_if_eq Route101_ImSure
	compare VAR_RESULT, NO
	goto_if_eq Route101_Ghost_Pokemon
	return
	
Route101_Dragon_Pokemon:
	hidemonpic
	closemessage
	scrollingmultichoice 17, 2, 3, 5, TRUE
	compare VAR_RESULT, 0x7F
	goto_if_eq Route101_EventScript_BirchsBag
	GetStarterName
	showmonpic VAR_0x8002, 10, 3
	playmoncry VAR_0x8002, 0
	msgbox Text_YouSure, MSGBOX_YESNO
	compare VAR_RESULT, YES
	call_if_eq Route101_ImSure
	compare VAR_RESULT, NO
	goto_if_eq Route101_Dragon_Pokemon
	return
	
Route101_Fairy_Pokemon:
	hidemonpic
	closemessage
	scrollingmultichoice 18, 2, 3, 5, TRUE
	compare VAR_RESULT, 0x7F
	goto_if_eq Route101_EventScript_BirchsBag
	GetStarterName
	showmonpic VAR_0x8002, 10, 3
	playmoncry VAR_0x8002, 0
	msgbox Text_YouSure, MSGBOX_YESNO
	compare VAR_RESULT, YES
	call_if_eq Route101_ImSure
	compare VAR_RESULT, NO
	goto_if_eq Route101_Fairy_Pokemon
	return
	
Text_ChooseLetter:
	.string "Choose the Type of the\n"
	.string "Starter Pokemon that you want.$"
	
Text_ChoosePokemon:
	.string "Choose which Pokemon you want.\n"
	.string "Press B to go back to prior list.$"

Text_YouSure:
	.string "Are you sure you want {STR_VAR_1}?$"
	
Route101_ImSure::
	hidemonpic
	copyvar VAR_RESULT, VAR_0x8001
	return
