Route108_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route108_OnTransition
	map_script MAP_SCRIPT_ON_RESUME,Route108_OnResume
	.byte 0

Route108_OnTransition:
	special GetTimeOfDay
	goto_if_eq VAR_RESULT, 0, Route108_OnTransition_Day
	goto_if_eq VAR_RESULT, 1, Route108_OnTransition_Twilight
	goto_if_eq VAR_RESULT, 2, Route108_OnTransition_Night
	end

Route108_OnTransition_Day:
	setvar VAR_TIMEOFDAY, 0
	end

Route108_OnTransition_Twilight:
	setvar VAR_TIMEOFDAY, 1
	end

Route108_OnTransition_Night:
	setvar VAR_TIMEOFDAY, 2
	end

Route108_OnResume:
	special GetTimeOfDay
	goto_if_eq VAR_RESULT, 0, Route108_OnResume_Day
	goto_if_eq VAR_RESULT, 1, Route108_OnResume_Twilight
	goto_if_eq VAR_RESULT, 2, Route108_OnResume_Night
	end	

Route108_OnResume_Day:
	setvar VAR_TIMEOFDAY, 0
	end

Route108_OnResume_Twilight:
	setvar VAR_TIMEOFDAY, 1
	end

Route108_OnResume_Night:
	setvar VAR_TIMEOFDAY, 2
	end

Route108_EventScript_Jerome::
	trainerbattle_single TRAINER_JEROME, Route108_Text_JeromeIntro, Route108_Text_JeromeDefeated
	msgbox Route108_Text_JeromePostBattle, MSGBOX_AUTOCLOSE
	end

Route108_EventScript_Matthew::
	trainerbattle_single TRAINER_MATTHEW, Route108_Text_MatthewIntro, Route108_Text_MatthewDefeated
	msgbox Route108_Text_MatthewPostBattle, MSGBOX_AUTOCLOSE
	end

Route108_EventScript_Tara::
	trainerbattle_single TRAINER_TARA, Route108_Text_TaraIntro, Route108_Text_TaraDefeated
	msgbox Route108_Text_TaraPostBattle, MSGBOX_AUTOCLOSE
	end

Route108_EventScript_Missy::
	trainerbattle_single TRAINER_MISSY, Route108_Text_MissyIntro, Route108_Text_MissyDefeated
	msgbox Route108_Text_MissyPostBattle, MSGBOX_AUTOCLOSE
	end

Route108_EventScript_Carolina::
	trainerbattle_single TRAINER_CAROLINA, Route108_Text_CarolinaIntro, Route108_Text_CarolinaDefeated
	msgbox Route108_Text_CarolinaPostBattle, MSGBOX_AUTOCLOSE
	end

Route108_EventScript_Cory::
	trainerbattle_single TRAINER_CORY_1, Route108_Text_CoryIntro, Route108_Text_CoryDefeated, Route108_EventScript_CoryRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route108_EventScript_CoryRematch
	msgbox Route108_Text_CoryPostBattle, MSGBOX_DEFAULT
	release
	end

Route108_EventScript_CoryRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route108_Text_CoryRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CORY_1
	release
	end

Route108_EventScript_CoryRematch::
	trainerbattle_rematch TRAINER_CORY_1, Route108_Text_CoryRematchIntro, Route108_Text_CoryRematchDefeated
	msgbox Route108_Text_CoryRematchPostBattle, MSGBOX_AUTOCLOSE
	end

