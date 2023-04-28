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

float vel[3];

public void OnPluginStart()
{
	HookEvent("weapon_fire", Event_weapon_fire, EventHookMode_Pre);
}

public Action Event_weapon_fire(Event event, const char[] name, bool dontBroadcast)
{
	int client = GetClientOfUserId(event.GetInt("userid"));
	PrintToChat(client, "Speed: %.2f", GetSpeed(client));
}

public void OnGameFrame()
{
	int client = 1;
	GetSpeed(client);
	PrintHintText(client, "Speed: %.2f", GetSpeed(client));

  	if(GetSpeed(client) > 70)
  	{
    	//SendConVarValue(client, hConVar_NoSpread, "0");
    	ServerCommand("weapon_accuracy_nospread 0");
  	}
  	else
  	{
  		//SendConVarValue(client, hConVar_NoSpread, "0");
  		ServerCommand("weapon_accuracy_nospread 1");
  	}
}

stock float GetSpeed(int client)
{
	GetEntPropVector(client, Prop_Data, "m_vecVelocity", vel);
	return SquareRoot(vel[0] * vel[0] + vel[1] * vel[1]);
}