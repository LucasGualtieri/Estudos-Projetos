#include <sourcemod>
#include <sdktools>
#include <sdkhooks>

#pragma semicolon 1
#pragma newdecls required

public Plugin myinfo =
{
	name = "Accuracy Correction",
	author = "Lucas",
	description = "Perfect Accuracy while bellow 33.4% of max weapon move speed",
	version = "1.0",
	url = "forums.alliedmods.net"
}

float fVelocity[3];

public void OnPluginStart()
{
    HookEvent("weapon_fire", Event_PreFire, EventHookMode_Pre);
}

public Action Event_PreFire(Event event, const char[] name, bool dontBroadcast)
{
	int client = 1;
	GetEntPropVector(client, Prop_Data, "m_vecVelocity", fVelocity);
	PrintToChat(client, "Speed: %.2f", fVelocity[2]);
}