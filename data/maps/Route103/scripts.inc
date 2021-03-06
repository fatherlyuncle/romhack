.set LOCALID_RIVAL, 2

Route103_MapScripts:: @ 81EC38E
	map_script MAP_SCRIPT_ON_TRANSITION, Route103_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route103_OnLoad
	.byte 0

Route103_OnTransition: @ 81EC399
	call Common_EventScript_SetupRivalGfxId
	call ProfBirch_EventScript_UpdateLocation
	end

Route103_OnLoad: @ 81EC3A4
	call_if_set FLAG_SYS_GAME_CLEAR, Route103_EventScript_OpenAlteringCave
	end

Route103_EventScript_OpenAlteringCave:: @ 81EC3AE
	setmetatile 45, 5, METATILE_General_CaveEntrance_Top, 1
	setmetatile 45, 6, METATILE_General_CaveEntrance_Bottom, 0
	return

Route103_EventScript_Rival:: @ 81EC3C1
	lockall
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Route103_EventScript_RivalMay
	compare VAR_RESULT, FEMALE
	goto_if_eq Route103_EventScript_RivalBrendan
	end

Route103_EventScript_RivalMay:: @ 81EC3DA
	msgbox Route103_Text_MayRoute103Pokemon, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_FIELD13, 1
	applymovement 2, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	msgbox Route103_Text_MayLetsBattle, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_RIVAL_ROUTE103
	switch VAR_UNUSED_0x8014
	case 0, Route103_EventScript_Normal
	case 1, Route103_EventScript_Fighting
	case 2, Route103_EventScript_Flying
	case 3, Route103_EventScript_Poison
	case 4, Route103_EventScript_Ground
	case 5, Route103_EventScript_Rock
	case 6, Route103_EventScript_Bug
	case 7, Route103_EventScript_Ghost
	case 8, Route103_EventScript_Steel
	case 10, Route103_EventScript_Fire
	case 11, Route103_EventScript_Water
	case 12, Route103_EventScript_Grass
	case 13, Route103_EventScript_Electric
	case 14, Route103_EventScript_Psychic
	case 15, Route103_EventScript_Ice
	case 16, Route103_EventScript_Dragon
	case 17, Route103_EventScript_Dark
	case 18, Route103_EventScript_Fairy
	end

Route103_EventScript_RivalBrendan:: @ 81EC434
	msgbox Route103_Text_BrendanRoute103Pokemon, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_BOY_SUP, 1
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	msgbox Route103_Text_BrendanLetsBattle, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_RIVAL_ROUTE103
	switch VAR_UNUSED_0x8014
	case 0, Route103_EventScript_Normal
	case 1, Route103_EventScript_Fighting
	case 2, Route103_EventScript_Flying
	case 3, Route103_EventScript_Poison
	case 4, Route103_EventScript_Ground
	case 5, Route103_EventScript_Rock
	case 6, Route103_EventScript_Bug
	case 7, Route103_EventScript_Ghost
	case 8, Route103_EventScript_Steel
	case 10, Route103_EventScript_Fire
	case 11, Route103_EventScript_Water
	case 12, Route103_EventScript_Grass
	case 13, Route103_EventScript_Electric
	case 14, Route103_EventScript_Psychic
	case 15, Route103_EventScript_Ice
	case 16, Route103_EventScript_Dragon
	case 17, Route103_EventScript_Dark
	case 18, Route103_EventScript_Fairy
	end

Route103_EventScript_StartMayBattleFighting::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_FIGHTING, Route103_Text_MayDefeated
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleFlying::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_FLYING, Route103_Text_MayDefeated
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattlePoison::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_POISON, Route103_Text_MayDefeated
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleGround::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_GROUND, Route103_Text_MayDefeated
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleRock::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_ROCK, Route103_Text_MayDefeated
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleBug::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_BUG, Route103_Text_MayDefeated
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleGhost::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_GHOST, Route103_Text_MayDefeated
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleSteel::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_STEEL, Route103_Text_MayDefeated
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleFire:: @ 81EC48E
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TREECKO, Route103_Text_MayDefeated
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleWater:: @ 81EC49E
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TORCHIC, Route103_Text_MayDefeated
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleGrass:: @ 81EC4AE
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_MUDKIP, Route103_Text_MayDefeated
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleElectric::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_ELECTRIC, Route103_Text_MayDefeated
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattlePsychic::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_PSYCHIC, Route103_Text_MayDefeated
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleIce::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_ICE, Route103_Text_MayDefeated
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleDragon::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_DRAGON, Route103_Text_MayDefeated
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleDark::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_DARK, Route103_Text_MayDefeated
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleFairy::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_FAIRY, Route103_Text_MayDefeated
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartBrendanBattleFighting::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_FIGHTING, Route103_Text_BrendanDefeated
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleFlying::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_FLYING, Route103_Text_BrendanDefeated
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattlePoison::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_POISON, Route103_Text_BrendanDefeated
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleGround::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_GROUND, Route103_Text_BrendanDefeated
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleRock::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_ROCK, Route103_Text_BrendanDefeated
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleBug::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_BUG, Route103_Text_BrendanDefeated
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleGhost::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_GHOST, Route103_Text_BrendanDefeated
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleSteel::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_STEEL, Route103_Text_BrendanDefeated
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleFire:: @ 81EC48E
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TREECKO, Route103_Text_BrendanDefeated
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleWater:: @ 81EC49E
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TORCHIC, Route103_Text_BrendanDefeated
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleGrass:: @ 81EC4AE
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_MUDKIP, Route103_Text_BrendanDefeated
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleElectric::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_ELECTRIC, Route103_Text_BrendanDefeated
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattlePsychic::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_PSYCHIC, Route103_Text_BrendanDefeated
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleIce::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_ICE, Route103_Text_BrendanDefeated
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleDragon::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_DRAGON, Route103_Text_BrendanDefeated
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleDark::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_DARK, Route103_Text_BrendanDefeated
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleFairy::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_FAIRY, Route103_Text_BrendanDefeated
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_AfterMayBattle:: @ 81EC4EE
	msgbox Route103_Text_MayTimeToHeadBack, MSGBOX_DEFAULT
	goto Route103_EventScript_RivalExit
	end

Route103_EventScript_AfterBrendanBattle:: @ 81EC4FC
	msgbox Route103_Text_BrendanTimeToHeadBack, MSGBOX_DEFAULT
	goto Route103_EventScript_RivalExit
	end

Route103_EventScript_RivalExit:: @ 81EC50A
	closemessage
	switch VAR_FACING
	case DIR_SOUTH, Route103_EventScript_RivalExitFacingSouth
	case DIR_NORTH, Route103_EventScript_RivalExitFacingNorth
	case DIR_WEST, Route103_EventScript_RivalExitFacingEastOrWest
	case DIR_EAST, Route103_EventScript_RivalExitFacingEastOrWest
	end

Route103_EventScript_RivalExitFacingNorth:: @ 81EC53D
	applymovement OBJ_EVENT_ID_PLAYER, Route103_Movement_WatchRivalExitFacingNorth
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExitFacingNorth1
	waitmovement 0
	playse SE_DANSA
	applymovement LOCALID_RIVAL, Route103_EventScript_RivalExitFacingNorth2
	waitmovement 0
	goto Route103_EventScript_RivalEnd
	end

Route103_EventScript_RivalExitFacingEastOrWest:: @ 81EC561
	applymovement OBJ_EVENT_ID_PLAYER, Route103_Movement_WatchRivalExitFacingEastOrWest
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit1
	waitmovement 0
	playse SE_DANSA
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit2
	waitmovement 0
	goto Route103_EventScript_RivalEnd
	end

Route103_EventScript_RivalExitFacingSouth:: @ 81EC585
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit1
	waitmovement 0
	playse SE_DANSA
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit2
	waitmovement 0
	goto Route103_EventScript_RivalEnd
	end

Route103_EventScript_RivalEnd:: @ 81EC5A2
	removeobject LOCALID_RIVAL
	setvar VAR_BIRCH_LAB_STATE, 4
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
	setflag FLAG_DEFEATED_RIVAL_ROUTE103
	setvar VAR_OLDALE_RIVAL_STATE, 1
	clearflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

Route103_Movement_RivalExitFacingNorth1: @ 81EC5BE
	walk_left
	walk_down
	step_end

Route103_EventScript_RivalExitFacingNorth2: @ 81EC5C1
	jump_2_down
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route103_Movement_WatchRivalExitFacingNorth: @ 81EC5C8
	delay_16
	delay_4
	walk_in_place_fastest_left
	delay_16
	walk_in_place_fastest_down
	step_end

Route103_Movement_RivalExit1: @ 81EC5CE
	walk_down
	step_end

Route103_Movement_RivalExit2: @ 81EC5D0
	jump_2_down
	delay_16
	walk_down
	walk_down
	walk_down
	step_end

Route103_Movement_WatchRivalExitFacingEastOrWest: @ 81EC5D6
	delay_16
	walk_in_place_fastest_down
	step_end

Route103_EventScript_Boy:: @ 81EC5D9
	msgbox Route103_Text_ShouldHaveBroughtPotion, MSGBOX_NPC
	end

Route103_EventScript_Man:: @ 81EC5E2
	msgbox Route103_Text_ShortcutToOldale, MSGBOX_NPC
	end

Route103_EventScript_RouteSign:: @ 81EC5EB
	msgbox Route103_Text_RouteSign, MSGBOX_SIGN
	end

Route103_EventScript_Daisy:: @ 81EC5F4
	trainerbattle_single TRAINER_DAISY, Route103_Text_DaisyIntro, Route103_Text_DaisyDefeated
	msgbox Route103_Text_DaisyPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Amy:: @ 81EC60B
	trainerbattle_double TRAINER_AMY_AND_LIV_1, Route103_Text_AmyIntro, Route103_Text_AmyDefeated, Route103_Text_AmyNotEnoughPokemon, Route102_EventScript_AmyRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route102_EventScript_AmyRematch
	msgbox Route103_Text_AmyPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_AmyRegisterMatchCallAfterBattle:: @ 81EC63A
	msgbox Route103_Text_AmyLivRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_AMY_AND_LIV_1
	release
	end

Route102_EventScript_AmyRematch:: @ 81EC653
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Route103_Text_AmyRematchIntro, Route103_Text_AmyRematchDefeated, Route103_Text_AmyRematchNotEnoughPokemon
	msgbox Route103_Text_AmyRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Liv:: @ 81EC66E
	trainerbattle_double TRAINER_AMY_AND_LIV_1, Route103_Text_LivIntro, Route103_Text_LivDefeated, Route103_Text_LivNotEnoughPokemon, Route102_EventScript_LivRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route102_EventScript_LivRematch
	msgbox Route103_Text_LivPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_LivRegisterMatchCallAfterBattle:: @ 81EC69D
	msgbox Route103_Text_AmyLivRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_AMY_AND_LIV_1
	release
	end

Route102_EventScript_LivRematch:: @ 81EC6B6
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Route103_Text_LivRematchIntro, Route103_Text_LivRematchDefeated, Route103_Text_LivRematchNotEnoughPokemon
	msgbox Route103_Text_LivRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Andrew:: @ 81EC6D1
	trainerbattle_single TRAINER_ANDREW, Route103_Text_AndrewIntro, Route103_Text_AndrewDefeated
	msgbox Route103_Text_AndrewPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Miguel:: @ 81EC6E8
	trainerbattle_single TRAINER_MIGUEL_1, Route103_Text_MiguelIntro, Route103_Text_MiguelDefeated, Route102_EventScript_MiguelRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route103_EventScript_MiguelRematch
	msgbox Route103_Text_MiguelPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_EventScript_MiguelRegisterMatchCallAfterBattle:: @ 81EC714
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route103_Text_MiguelRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_MIGUEL_1
	release
	end

Route103_EventScript_MiguelRematch:: @ 81EC733
	trainerbattle_rematch TRAINER_MIGUEL_1, Route103_Text_MiguelRematchIntro, Route103_Text_MiguelRematchDefeated
	msgbox Route103_Text_MiguelRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Marcos:: @ 81EC74A
	trainerbattle_single TRAINER_MARCOS, Route103_Text_MarcosIntro, Route103_Text_MarcosDefeated
	msgbox Route103_Text_MarcosPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Rhett:: @ 81EC761
	trainerbattle_single TRAINER_RHETT, Route103_Text_RhettIntro, Route103_Text_RhettDefeated
	msgbox Route103_Text_RhettPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Pete:: @ 81EC778
	trainerbattle_single TRAINER_PETE, Route103_Text_PeteIntro, Route103_Text_PeteDefeated
	msgbox Route103_Text_PetePostBattle, MSGBOX_AUTOCLOSE
	end

Route103_Text_MayRoute103Pokemon: @ 81EC7A6
	.string "MAY: Let's see… The POKéMON found\n"
	.string "on ROUTE 103 include…$"

Route103_Text_MayLetsBattle: @ 81EC7DE
	.string "Oh, hi, {PLAYER}{KUN}!\p"
	.string "…Oh, I see, my dad gave you\n"
	.string "a POKéMON as a gift.\p"
	.string "Since we're here, let's have a quick\n"
	.string "battle!\p"
	.string "I'll give you a taste of what being\n"
	.string "a TRAINER is like.$"

Route103_Text_MayDefeated: @ 81EC881
	.string "Wow! That's great!\n"
	.string "{PLAYER}{KUN}, you're pretty good!$"

Route103_Text_MayTimeToHeadBack: @ 81EC8AE
	.string "MAY: I think I know why my dad has\n"
	.string "an eye out for you now.\p"
	.string "I mean, you just got that POKéMON,\n"
	.string "but it already likes you.\p"
	.string "You might be able to befriend any\n"
	.string "kind of POKéMON easily.\p"
	.string "Well, it's time to head back to\n"
	.string "the LAB.$"

Route103_Text_BrendanRoute103Pokemon: @ 81EC989
	.string "BRENDAN: Okay, so it's this one and\n"
	.string "that one that live on ROUTE 103…$"

Route103_Text_BrendanLetsBattle: @ 81EC9CE
	.string "Hey, it's {PLAYER}!\p"
	.string "…Oh, yeah, Dad gave you a POKéMON.\p"
	.string "Since we're here, how about a little\n"
	.string "battle?\p"
	.string "I'll teach you what being a TRAINER's\n"
	.string "about!$"

Route103_Text_BrendanDefeated: @ 81ECA59
	.string "Huh, {PLAYER}, you're not too shabby.$"

Route103_Text_BrendanTimeToHeadBack: @ 81ECA79
	.string "BRENDAN: I think I get it.\n"
	.string "I think I know why my dad has his eye\l"
	.string "out for you now.\p"
	.string "Look, your POKéMON already likes you,\n"
	.string "even though you just got it.\p"
	.string "{PLAYER}, I get the feeling that you\n"
	.string "could befriend any POKéMON with ease.\p"
	.string "We should head back to the LAB.$"

Route103_Text_ShouldHaveBroughtPotion: @ 81ECB73
	.string "My POKéMON is staggeringly tired…\n"
	.string "I should have brought a POTION…$"

Route103_Text_ShortcutToOldale: @ 81ECBB5
	.string "If you cross the sea from here,\n"
	.string "it'll be a shortcut to OLDALE TOWN.\p"
	.string "Fufufu, that's useful, isn't it?$"

Route103_EventScript_Normal::
	goto Route103_EventScript_FightingCheck
	return

Route103_EventScript_Fighting::
	random 3
	switch VAR_RESULT
	case 0, Route103_EventScript_FlyingCheck
	case 1, Route103_EventScript_PsychicCheck
	case 2, Route103_EventScript_FairyCheck
	return

Route103_EventScript_Flying::
	random 3
	switch VAR_RESULT
	case 0, Route103_EventScript_RockCheck
	case 1, Route103_EventScript_ElectricCheck
	case 2, Route103_EventScript_IceCheck
	return

Route103_EventScript_Poison::
	random 2
	switch VAR_RESULT
	case 0, Route103_EventScript_GroundCheck
	case 1, Route103_EventScript_PsychicCheck
	return

Route103_EventScript_Ground::
	random 3
	switch VAR_RESULT
	case 0, Route103_EventScript_WaterCheck
	case 1, Route103_EventScript_GrassCheck
	case 2, Route103_EventScript_IceCheck
	return

Route103_EventScript_Rock::
	random 5
	switch VAR_RESULT
	case 0, Route103_EventScript_FightingCheck
	case 1, Route103_EventScript_GroundCheck
	case 2, Route103_EventScript_SteelCheck
	case 3, Route103_EventScript_WaterCheck
	case 4, Route103_EventScript_GrassCheck
	return

Route103_EventScript_Bug::
	random 3
	switch VAR_RESULT
	case 0, Route103_EventScript_FlyingCheck
	case 1, Route103_EventScript_RockCheck
	case 2, Route103_EventScript_FireCheck
	return

Route103_EventScript_Ghost::
	random 2
	switch VAR_RESULT
	case 0, Route103_EventScript_GhostCheck
	case 1, Route103_EventScript_DarkCheck
	return

Route103_EventScript_Steel::
	random 3
	switch VAR_RESULT
	case 0, Route103_EventScript_FightingCheck
	case 1, Route103_EventScript_GroundCheck
	case 2, Route103_EventScript_FireCheck
	return

Route103_EventScript_Fire::
	random 3
	switch VAR_RESULT
	case 0, Route103_EventScript_GroundCheck
	case 1, Route103_EventScript_RockCheck
	case 2, Route103_EventScript_WaterCheck
	return

Route103_EventScript_Water::
	random 2
	switch VAR_RESULT
	case 0, Route103_EventScript_GrassCheck
	case 1, Route103_EventScript_ElectricCheck
	return

Route103_EventScript_Grass::
	random 5
	switch VAR_RESULT
	case 0, Route103_EventScript_FlyingCheck
	case 1, Route103_EventScript_PoisonCheck
	case 2, Route103_EventScript_BugCheck
	case 3, Route103_EventScript_FireCheck
	case 4, Route103_EventScript_IceCheck
	return

Route103_EventScript_Electric::
	goto Route103_EventScript_GroundCheck
	return

Route103_EventScript_Psychic::
	random 3
	switch VAR_RESULT
	case 0, Route103_EventScript_BugCheck
	case 1, Route103_EventScript_GhostCheck
	case 2, Route103_EventScript_DarkCheck
	return

Route103_EventScript_Ice::
	random 4
	switch VAR_RESULT
	case 0, Route103_EventScript_FightingCheck
	case 1, Route103_EventScript_RockCheck
	case 2, Route103_EventScript_SteelCheck
	case 3, Route103_EventScript_FireCheck
	return

Route103_EventScript_Dragon::
	random 3
	switch VAR_RESULT
	case 0, Route103_EventScript_IceCheck
	case 1, Route103_EventScript_DragonCheck
	case 2, Route103_EventScript_FairyCheck
	return

Route103_EventScript_Dark::
	random 3
	switch VAR_RESULT
	case 0, Route103_EventScript_FightingCheck
	case 1, Route103_EventScript_BugCheck
	case 2, Route103_EventScript_FairyCheck
	return

Route103_EventScript_Fairy::
	random 2
	switch VAR_RESULT
	case 0, Route103_EventScript_PoisonCheck
	case 1, Route103_EventScript_SteelCheck
	return

Route103_EventScript_FightingCheck::
	setvar VAR_STARTER_MON, 1
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Route103_EventScript_StartMayBattleFighting
	compare VAR_RESULT, FEMALE
	goto_if_eq Route103_EventScript_StartBrendanBattleFighting
	return

Route103_EventScript_FlyingCheck::
	setvar VAR_STARTER_MON, 2
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Route103_EventScript_StartMayBattleFlying
	compare VAR_RESULT, FEMALE
	goto_if_eq Route103_EventScript_StartBrendanBattleFlying
	return

Route103_EventScript_PoisonCheck::
	setvar VAR_STARTER_MON, 3
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Route103_EventScript_StartMayBattlePoison
	compare VAR_RESULT, FEMALE
	goto_if_eq Route103_EventScript_StartBrendanBattlePoison
	return

Route103_EventScript_GroundCheck::
	setvar VAR_STARTER_MON, 4
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Route103_EventScript_StartMayBattleGround
	compare VAR_RESULT, FEMALE
	goto_if_eq Route103_EventScript_StartBrendanBattleGround
	return

Route103_EventScript_RockCheck::
	setvar VAR_STARTER_MON, 5
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Route103_EventScript_StartMayBattleRock
	compare VAR_RESULT, FEMALE
	goto_if_eq Route103_EventScript_StartBrendanBattleRock
	return

Route103_EventScript_BugCheck::
	setvar VAR_STARTER_MON, 6
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Route103_EventScript_StartMayBattleBug
	compare VAR_RESULT, FEMALE
	goto_if_eq Route103_EventScript_StartBrendanBattleBug
	return

Route103_EventScript_GhostCheck::
	setvar VAR_STARTER_MON, 7
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Route103_EventScript_StartMayBattleGhost
	compare VAR_RESULT, FEMALE
	goto_if_eq Route103_EventScript_StartBrendanBattleGhost
	return

Route103_EventScript_SteelCheck::
	setvar VAR_STARTER_MON, 8
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Route103_EventScript_StartMayBattleSteel
	compare VAR_RESULT, FEMALE
	goto_if_eq Route103_EventScript_StartBrendanBattleSteel
	return

Route103_EventScript_FireCheck::
	setvar VAR_STARTER_MON, 10
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Route103_EventScript_StartMayBattleFire
	compare VAR_RESULT, FEMALE
	goto_if_eq Route103_EventScript_StartBrendanBattleFire
	return

Route103_EventScript_WaterCheck::
	setvar VAR_STARTER_MON, 11
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Route103_EventScript_StartMayBattleWater
	compare VAR_RESULT, FEMALE
	goto_if_eq Route103_EventScript_StartBrendanBattleWater
	return

Route103_EventScript_GrassCheck::
	setvar VAR_STARTER_MON, 12
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Route103_EventScript_StartMayBattleGrass
	compare VAR_RESULT, FEMALE
	goto_if_eq Route103_EventScript_StartBrendanBattleGrass
	return

Route103_EventScript_ElectricCheck::
	setvar VAR_STARTER_MON, 13
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Route103_EventScript_StartMayBattleElectric
	compare VAR_RESULT, FEMALE
	goto_if_eq Route103_EventScript_StartBrendanBattleElectric
	return

Route103_EventScript_PsychicCheck::
	setvar VAR_STARTER_MON, 14
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Route103_EventScript_StartMayBattlePsychic
	compare VAR_RESULT, FEMALE
	goto_if_eq Route103_EventScript_StartBrendanBattlePsychic
	return

Route103_EventScript_IceCheck::
	setvar VAR_STARTER_MON, 15
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Route103_EventScript_StartMayBattleIce
	compare VAR_RESULT, FEMALE
	goto_if_eq Route103_EventScript_StartBrendanBattleIce
	return

Route103_EventScript_DragonCheck::
	setvar VAR_STARTER_MON, 16
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Route103_EventScript_StartMayBattleDragon
	compare VAR_RESULT, FEMALE
	goto_if_eq Route103_EventScript_StartBrendanBattleDragon
	return

Route103_EventScript_DarkCheck::
	setvar VAR_STARTER_MON, 17
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Route103_EventScript_StartMayBattleDark
	compare VAR_RESULT, FEMALE
	goto_if_eq Route103_EventScript_StartBrendanBattleDark
	return

Route103_EventScript_FairyCheck::
	setvar VAR_STARTER_MON, 18
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Route103_EventScript_StartMayBattleFairy
	compare VAR_RESULT, FEMALE
	goto_if_eq Route103_EventScript_StartBrendanBattleFairy
	return

Route103_Text_RouteSign: @ 81ECC1A
	.string "ROUTE 103\n"
	.string "{DOWN_ARROW} OLDALE TOWN$"

Route103_EventScript_Isabelle:: @ 81EC78F
	trainerbattle_single TRAINER_ISABELLE, Route103_Text_IsabelleIntro, Route103_Text_IsabelleDefeated
	msgbox Route103_Text_IsabellePostBattle, MSGBOX_AUTOCLOSE
	end
