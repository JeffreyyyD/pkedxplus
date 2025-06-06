PacifidlogTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, PacifidlogTown_OnResume
	.byte 0

PacifidlogTown_OnTransition:
	special GetTimeOfDay
	goto_if_eq VAR_RESULT, 0, PacifidlogTown_OnTransition_Day
	goto_if_eq VAR_RESULT, 1, PacifidlogTown_OnTransition_Twilight
	goto_if_eq VAR_RESULT, 2, PacifidlogTown_OnTransition_Night
	end

PacifidlogTown_OnTransition_Day:
	setvar VAR_TIMEOFDAY, 0
	setflag FLAG_VISITED_PACIFIDLOG_TOWN
	end

PacifidlogTown_OnTransition_Twilight:
	setvar VAR_TIMEOFDAY, 1
	setflag FLAG_VISITED_PACIFIDLOG_TOWN
	end

PacifidlogTown_OnTransition_Night:
	setvar VAR_TIMEOFDAY, 2
	setflag FLAG_VISITED_PACIFIDLOG_TOWN
	end

PacifidlogTown_OnResume:
	special GetTimeOfDay
	goto_if_eq VAR_RESULT, 0, PacifidlogTown_OnResume_Day
	goto_if_eq VAR_RESULT, 1, PacifidlogTown_OnResume_Twilight
	goto_if_eq VAR_RESULT, 2, PacifidlogTown_OnResume_Night
	end	

PacifidlogTown_OnResume_Day:
	setvar VAR_TIMEOFDAY, 0
	setstepcallback STEP_CB_PACIFIDLOG_BRIDGE
	end

PacifidlogTown_OnResume_Twilight:
	setvar VAR_TIMEOFDAY, 1
	setstepcallback STEP_CB_PACIFIDLOG_BRIDGE
	end

PacifidlogTown_OnResume_Night:
	setvar VAR_TIMEOFDAY, 2
	setstepcallback STEP_CB_PACIFIDLOG_BRIDGE
	end

PacifidlogTown_EventScript_NinjaBoy::
	msgbox PacifidlogTown_Text_NeatHousesOnWater, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Girl::
	msgbox PacifidlogTown_Text_FastRunningCurrent, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Fisherman::
	msgbox PacifidlogTown_Text_SkyPillarTooScary, MSGBOX_NPC
	end

PacifidlogTown_EventScript_TownSign::
	msgbox PacifidlogTown_Text_TownSign, MSGBOX_SIGN
	end

PacifidlogTown_Text_FastRunningCurrent:
	.string "The sea between PACIFIDLOG and\n"
	.string "SLATEPORT has a fast-running tide.\p"
	.string "If you decide to SURF, you could end\n"
	.string "up swept away somewhere else.$"

PacifidlogTown_Text_NeatHousesOnWater:
	.string "See, isn't it neat?\n"
	.string "These houses are on water!\p"
	.string "I was born here!$"

PacifidlogTown_Text_SkyPillarTooScary:
	.string "The SKY PILLAR?\p"
	.string "…Oh, you must mean that tall, tall\n"
	.string "tower a little further out.\p"
	.string "If you asked me, I wouldn't climb it.\n"
	.string "It's too scary to get up that high.\p"
	.string "Life at sea level in PACIFIDLOG,\n"
	.string "that suits me fine.$"

PacifidlogTown_Text_TownSign:
	.string "PACIFIDLOG TOWN\p"
	.string "“Where the morning sun smiles upon\n"
	.string "the waters.”$"

