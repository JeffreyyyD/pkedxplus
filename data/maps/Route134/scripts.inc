Route134_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route124_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route134_OnResume
	.byte 0

Route134_OnTransition:
	special GetTimeOfDay
	goto_if_eq VAR_RESULT, 0, Route134_OnTransition_Day
	goto_if_eq VAR_RESULT, 1, Route134_OnTransition_Twilight
	goto_if_eq VAR_RESULT, 2, Route134_OnTransition_Night
	end	

Route134_OnTransition_Day:
	setvar VAR_TIMEOFDAY, 0
	end

Route134_OnTransition_Twilight:
	setvar VAR_TIMEOFDAY, 1
	end

Route134_OnTransition_Night:
	setvar VAR_TIMEOFDAY, 2
	end

Route134_OnResume:
	special GetTimeOfDay
	goto_if_eq VAR_RESULT, 0, Route134_OnResume_Day
	goto_if_eq VAR_RESULT, 1, Route134_OnResume_Twilight
	goto_if_eq VAR_RESULT, 2, Route134_OnResume_Night
	end	

Route134_OnResume_Day:
	setvar VAR_TIMEOFDAY, 0
	setdivewarp MAP_UNDERWATER_ROUTE134, 8, 6
	end

Route134_OnResume_Twilight:
	setvar VAR_TIMEOFDAY, 1
	setdivewarp MAP_UNDERWATER_ROUTE134, 8, 6
	end

Route134_OnResume_Night:
	setvar VAR_TIMEOFDAY, 2
	setdivewarp MAP_UNDERWATER_ROUTE134, 8, 6
	end

Route134_EventScript_Jack::
	trainerbattle_single TRAINER_JACK, Route134_Text_JackIntro, Route134_Text_JackDefeat
	msgbox Route134_Text_JackPostBattle, MSGBOX_AUTOCLOSE
	end

Route134_EventScript_Laurel::
	trainerbattle_single TRAINER_LAUREL, Route134_Text_LaurelIntro, Route134_Text_LaurelDefeat
	msgbox Route134_Text_LaurelPostBattle, MSGBOX_AUTOCLOSE
	end

Route134_EventScript_Alex::
	trainerbattle_single TRAINER_ALEX, Route134_Text_AlexIntro, Route134_Text_AlexDefeat
	msgbox Route134_Text_AlexPostBattle, MSGBOX_AUTOCLOSE
	end

Route134_EventScript_Aaron::
	trainerbattle_single TRAINER_AARON, Route134_Text_AaronIntro, Route134_Text_AaronDefeat
	msgbox Route134_Text_AaronPostBattle, MSGBOX_AUTOCLOSE
	end

Route134_EventScript_Hitoshi::
	trainerbattle_single TRAINER_HITOSHI, Route134_Text_HitoshiIntro, Route134_Text_HitoshiDefeat
	msgbox Route134_Text_HitoshiPostBattle, MSGBOX_AUTOCLOSE
	end

Route134_EventScript_Hudson::
	trainerbattle_single TRAINER_HUDSON, Route134_Text_HudsonIntro, Route134_Text_HudsonDefeat
	msgbox Route134_Text_HudsonPostBattle, MSGBOX_AUTOCLOSE
	end

Route134_EventScript_Reyna::
	trainerbattle_single TRAINER_REYNA, Route134_Text_ReynaIntro, Route134_Text_ReynaDefeat
	msgbox Route134_Text_ReynaPostBattle, MSGBOX_AUTOCLOSE
	end

Route134_EventScript_Marley::
	trainerbattle_single TRAINER_MARLEY, Route134_Text_MarleyIntro, Route134_Text_MarleyDefeat
	msgbox Route134_Text_MarleyPostBattle, MSGBOX_AUTOCLOSE
	end

Route134_EventScript_Kelvin::
	trainerbattle_single TRAINER_KELVIN, Route134_Text_KelvinIntro, Route134_Text_KelvinDefeat
	msgbox Route134_Text_KelvinPostBattle, MSGBOX_AUTOCLOSE
	end

