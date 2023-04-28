#include <sourcemod>
#include <sdktools>
#include <sdkhooks>

#pragma semicolon 1
#pragma newdecls required

ConVar hConVar_NoSpread;

public Plugin myinfo =
{
	name = "Accuracy Correction",
	author = "Lucas",
	description = "Perfect Accuracy while bellow 33.4% of max weapon move speed",
	version = "1.0",
	url = "forums.alliedmods.net"
}

bool AlteredClients[MAXPLAYERS + 1];
float fVelocity[3];
int trueSpeed;

public void OnPluginStart()
{
    HookEvent("weapon_fire", Event_PreFire, EventHookMode_Pre);
    HookEvent("weapon_fire", Event_PostFire);
}

public Action Event_PreFire(Event event, const char[] name, bool dontBroadcast)
{
//............................GETTING THE SPEED................................
	int client = GetClientOfUserId(event.GetInt("userid"));
	GetEntPropVector(client, Prop_Data, "m_vecVelocity", fVelocity);
	trueSpeed = SquareRoot( Pow(fVelocity[0], 2.0) + Pow(fVelocity[1], 2.0));
//............................GETTING THE SPEED................................
	
  	if(trueSpeed > 73.1 || fVelocity[2] != 0)
  	{
    	ServerCommand("weapon_accuracy_nospread 0");
	    AlteredClients[client] = true;
  	}
  	else
  	{
  		ServerCommand("weapon_accuracy_nospread 1");
	    AlteredClients[client] = false;
  	}
  	return Plugin_Handled;
}

public void Event_PostFire(Event event, const char[] name, bool dontBroadcast)
{
  int client = GetClientOfUserId(event.GetInt("userid"));
  if(AlteredClients[client] == true)
  {
    // Remove the attribute.
    AlteredClients[client] = false;
  }
}








/*
float fVelocity[3];
int trueSpeed;
public void OnPluginStart()
{
    HookEvent("weapon_fire", Event_weapon_fire, EventHookMode_Pre);
}

public void OnGameFrame()
{
	int client = 1;
    GetEntPropVector(client, Prop_Data, "m_vecVelocity", fVelocity);
	trueSpeed = SquareRoot( Pow(fVelocity[0], 2.0) + Pow(fVelocity[1], 2.0));
	PrintHintText(client, "Speed: %d", RoundFloat(trueSpeed));
}
 
public Action Event_weapon_fire(Event event, const char[] name, bool dontBroadcast)
{	
	int id = event.GetInt("userid");
	int client = GetClientOfUserId(id);
	
	if(trueSpeed > 73.1 || fVelocity[2] != 0)
	{
		ServerCommand("weapon_accuracy_nospread 0");
		PrintToChat(client, "weapon_accuracy_nospread 0");
	}
	else
	{
		ServerCommand("weapon_accuracy_nospread 1");
		PrintToChat(client, "weapon_accuracy_nospread 1");
	}
	return Plugin_Handled;
}*/