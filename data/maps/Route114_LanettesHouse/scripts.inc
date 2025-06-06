Route114_LanettesHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_LanettesHouse_OnTransition
	.byte 0

Route114_LanettesHouse_OnTransition:
	setflag FLAG_LANDMARK_LANETTES_HOUSE
	end

Route114_LanettesHouse_EventScript_Lanette::
	lock
	faceplayer
	call_if_unset FLAG_ENABLE_SHIP_SOUTHERN_ISLAND, Route114_LanettesHouse_EventScript_CheckPostgame
	goto_if_set FLAG_RECEIVED_CANDY_LANETTE, Route114_LanettesHouse_EventScript_DailyUpgrade
	setflag FLAG_SYS_PC_LANETTE
	msgbox Route114_LanettesHouse_Text_EverythingClutteredKeepThis, MSGBOX_DEFAULT
	giveitem ITEM_MELTAN_CANDY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowNoRoomForDecor
	setflag FLAG_RECEIVED_CANDY_LANETTE
	setflag FLAG_DAILY_LANETTE_UPGRADE
	release
	end

Route114_LanettesHouse_EventScript_DailyUpgrade::
	goto_if_set FLAG_DAILY_LANETTE_UPGRADE, Route114_LanettesHouse_EventScript_OfferAdvice
	msgbox Route114_LanettesHouse_Text_FoundThisWhileCleaning, MSGBOX_DEFAULT
	giveitem ITEM_UP_GRADE
	setflag FLAG_DAILY_LANETTE_UPGRADE
	release
	end

Route114_LanettesHouse_Text_FoundThisWhileCleaning:
	.string "LANETTE: Oh, {PLAYER}!\p"
	.string "While I was organizing my\n"
	.string "house, I found this old tech.\p"
	.string "I don't have a use for it, so\n"
	.string "why don't you take it?$"

Route114_LanettesHouse_EventScript_CheckPostgame::
	goto_if_set FLAG_IS_CHAMPION, Route114_LanettesHouse_EventScript_GiveTicket
	return


Route114_LanettesHouse_EventScript_GiveTicket::
	msgbox Route114_LanettesHouse_Text_GotThisTicket, MSGBOX_DEFAULT
	giveitem ITEM_EON_TICKET
	setflag FLAG_ENABLE_SHIP_SOUTHERN_ISLAND
	setvar VAR_DISTRIBUTE_EON_TICKET, 0
	release
	end

Route114_LanettesHouse_Text_GotThisTicket:
	.string "LANETTE: Hey {PLAYER}!\p"
	.string "I got this ticket from my\n"
	.string "my friend in KANTO...\p"
	.string "I'm not really one for\n"
	.string "ferry rides, though.\p"
	.string "Why don't you go instead?$"


Route114_LanettesHouse_EventScript_OfferAdvice::
	msgbox Route114_LanettesHouse_Text_OrganizeYourBoxes, MSGBOX_DEFAULT
	release
	end

Route114_LanettesHouse_EventScript_Notebook::
	lockall
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage2
	msgbox Route114_LanettesHouse_Text_ClosedTheNotebook, MSGBOX_DEFAULT
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage2::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage3
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage3::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage3, MSGBOX_DEFAULT
	return

Route114_LanettesHouse_EventScript_PC::
	msgbox Route114_LanettesHouse_Text_EmailFromBill, MSGBOX_SIGN
	end

Route114_LanettesHouse_Text_EverythingClutteredKeepThis:
	.string "LANETTE: Oh! {PLAYER}{KUN}!\p"
	.string "I'm sorry everything is so cluttered…\n"
	.string "When I get engrossed in research,\l"
	.string "things end up this way…\p"
	.string "I was trying to clean things up a\n"
	.string "little, and I found this strange\l"
	.string "CANDY. I don't remember buying it…\p"
	.string "Why don't you keep it in exchange for\n"
	.string "keeping this a secret?$"


Route114_LanettesHouse_Text_OrganizeYourBoxes:
	.string "May I offer advice about my POKéMON\n"
	.string "Storage System?\p"
	.string "You should organize your BOXES so you\n"
	.string "can tell which POKéMON are in them.$"

Route114_LanettesHouse_Text_ResearchNotesPage1:
	.string "It's LANETTE's research notes.\n"
	.string "There's information about BOXES.\p"
	.string "Design BOXES to hold 30 POKéMON each.\p"
	.string "Each TRAINER should be able to store\n"
	.string "420 POKéMON on the PC system.\p"
	.string "Keep reading?$"

Route114_LanettesHouse_Text_ResearchNotesPage2:
	.string "A marking system should be added to\n"
	.string "make POKéMON easier to organize.\p"
	.string "The name and wallpaper design of each\n"
	.string "BOX will be made changeable to please\l"
	.string "the stored POKéMON.\p"
	.string "Keep reading?$"

Route114_LanettesHouse_Text_ResearchNotesPage3:
	.string "When storing a POKéMON, it should be\n"
	.string "sent to the BOX inspected last.\p"
	.string "If that BOX is full, the received\n"
	.string "POKéMON is stored in the next BOX.\p"
	.string "In other words, when a BOX is examined,\n"
	.string "it is automatically selected as the BOX\l"
	.string "to which POKéMON are sent.$"

Route114_LanettesHouse_Text_ClosedTheNotebook:
	.string "{PLAYER} closed the notebook.$"

Route114_LanettesHouse_Text_EmailFromBill:
	.string "There's an e-mail from someone on\n"
	.string "the PC.\p"
	.string "“… … … … … … …\p"
	.string "“Your Storage System offers more\n"
	.string "convenience than mine.\p"
	.string "“It has a lot of user-friendly features\n"
	.string "that make it fun and useful, too.\p"
	.string "“It makes me proud that I played\n"
	.string "a part in its development.\p"
	.string "“Here's hoping that you'll continue\n"
	.string "research in Storage Systems.\p"
	.string "“From BILL\n"
	.string "… … … … … … … …”$"

