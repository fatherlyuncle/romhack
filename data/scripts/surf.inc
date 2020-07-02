EventScript_UseSurf:: @ 8271EA0
	checkitem ITEM_SURF, 1
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_EndUseSurf
	setitemarg ITEM_SURF
	//bufferpartymonnick 0, VAR_RESULT  Replace HM with Item
	//setfieldeffectargument 0, ITEM_SURF
	lockall
	msgbox gText_WantToUseSurf, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_ReleaseUseSurf
	//msgbox gText_PlayerUsedSurf, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_SURF
	
EventScript_ReleaseUseSurf:: @ 8271ED5
	special DrawWholeMapView
	releaseall
	
EventScript_EndUseSurf:: @ 8271ED6
	end
