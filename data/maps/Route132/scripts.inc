Route132_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route132_OnTransition
	map_script MAP_SCRIPT_ON_RESUME,Route132_OnResume
	.byte 0

Route132_OnTransition:
	special GetTimeOfDay
	goto_if_eq VAR_RESULT, 0, Route132_OnTransition_Day
	goto_if_eq VAR_RESULT, 1, Route132_OnTransition_Twilight
	goto_if_eq VAR_RESULT, 2, Route132_OnTransition_Night
	end

Route132_OnTransition_Day:
	setvar VAR_TIMEOFDAY, 0
	end

Route132_OnTransition_Twilight:
	setvar VAR_TIMEOFDAY, 1
	end

Route132_OnTransition_Night:
	setvar VAR_TIMEOFDAY, 2
	end

Route132_OnResume:
	special GetTimeOfDay
	goto_if_eq VAR_RESULT, 0, Route132_OnResume_Day
	goto_if_eq VAR_RESULT, 1, Route132_OnResume_Twilight
	goto_if_eq VAR_RESULT, 2, Route132_OnResume_Night
	end	

Route132_OnResume_Day:
	setvar VAR_TIMEOFDAY, 0
	end

Route132_OnResume_Twilight:
	setvar VAR_TIMEOFDAY, 1
	end

Route132_OnResume_Night:
	setvar VAR_TIMEOFDAY, 2
	end

Route132_EventScript_Gilbert::
	trainerbattle_single TRAINER_GILBERT, Route132_Text_GilbertIntro, Route132_Text_GilbertDefeat
	msgbox Route132_Text_GilbertPostBattle, MSGBOX_AUTOCLOSE
	end

Route132_EventScript_Dana::
	trainerbattle_single TRAINER_DANA, Route132_Text_DanaIntro, Route132_Text_DanaDefeat
	msgbox Route132_Text_DanaPostBattle, MSGBOX_AUTOCLOSE
	end

Route132_EventScript_Ronald::
	trainerbattle_single TRAINER_RONALD, Route132_Text_RonaldIntro, Route132_Text_RonaldDefeat
	msgbox Route132_Text_RonaldPostBattle, MSGBOX_AUTOCLOSE
	end

Route132_EventScript_Kiyo::
	trainerbattle_single TRAINER_KIYO, Route132_Text_KiyoIntro, Route132_Text_KiyoDefeat
	msgbox Route132_Text_KiyoPostBattle, MSGBOX_AUTOCLOSE
	end

Route132_EventScript_Paxton::
	trainerbattle_single TRAINER_PAXTON, Route132_Text_PaxtonIntro, Route132_Text_PaxtonDefeat
	msgbox Route132_Text_PaxtonPostBattle, MSGBOX_AUTOCLOSE
	end

Route132_EventScript_Darcy::
	trainerbattle_single TRAINER_DARCY, Route132_Text_DarcyIntro, Route132_Text_DarcyDefeat
	msgbox Route132_Text_DarcyPostBattle, MSGBOX_AUTOCLOSE
	end

Route132_EventScript_Jonathan::
	trainerbattle_single TRAINER_JONATHAN, Route132_Text_JonathanIntro, Route132_Text_JonathanDefeat
	msgbox Route132_Text_JonathanPostBattle, MSGBOX_AUTOCLOSE
	end

Route132_EventScript_Makayla::
	trainerbattle_single TRAINER_MAKAYLA, Route132_Text_MakaylaIntro, Route132_Text_MakaylaDefeat
	msgbox Route132_Text_MakaylaPostBattle, MSGBOX_AUTOCLOSE
	end

