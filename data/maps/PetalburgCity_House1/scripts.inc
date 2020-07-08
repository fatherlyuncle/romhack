PetalburgCity_House1_MapScripts:: @ 8207799
	.byte 0

PetalburgCity_House1_EventScript_Man:: @ 820779A
	lock
	faceplayer
	msgbox PetalburgCity_House1_Text_Trade_YesNo, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq PetalburgCity_House1_Trade_Declined
	msgbox PetalburgCity_House1_Text_Trade_Confirm, MSGBOX_NPC	
	call PetalburgCity_House1_Trade
	compare VAR_RESULT, 0
	goto_if_eq PetalburgCity_House1_Trade_Declined
	goto PetalburgCity_House1_Trade_Done
	end

PetalburgCity_House1_EventScript_Woman:: @ 82077A3
	msgbox PetalburgCity_House1_Text_GoOnAdventure, MSGBOX_NPC
	end

PetalburgCity_House1_Text_Trade: @ 82077AC
	.string "GodDAMN Im just rocketing!\p"
	.string "Monster dooks out of my\n"
	.string "doo-doo ASS!!$"
	
PetalburgCity_House1_Trade::
	special ChooseMonForTrade
	waitstate
	lock
	faceplayer
	return

PetalburgCity_House1_Text_Trade_Confirm:
	.string "Really?? I can haz?\p"

PetalburgCity_House1_Text_Trade_YesNo:
	.string "Plz give pkmn.\p"

PetalburgCity_House1_Trade_Declined::
	msgbox PetalburgCity_House1_Text_Trade_Declined, MSGBOX_NPC
	release
	end
	
PetalburgCity_House1_Text_Trade_Declined:
	.string "Damn u suck..\p"

PetalburgCity_House1_Trade_Done::
	msgbox PetalburgCity_House1_Text_Trade_Done, MSGBOX_NPC
	release
	end

PetalburgCity_House1_Text_Trade_Done:
	.string "WAit I dont want\n"
	.string "THIS!? U keep it.$"

PetalburgCity_House1_Text_GoOnAdventure: @ 82077FB
	.string "Sigh…\p"
	.string "I wish I could go on an adventure\n"
	.string "with some POKéMON…\p"
	.string "Crawl through some damp grass…\n"
	.string "Climb rocky, rugged mountains…\p"
	.string "Cross the raging seas…\n"
	.string "Wander about in dark caves…\p"
	.string "And, sometimes, even get a little\n"
	.string "homesick…\p"
	.string "It must be fabulous to travel!$"

