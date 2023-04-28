#include <sourcemod>
#include <sdktools>
#include <sdkhooks>

#pragma semicolon 1
#pragma newdecls required

public Plugin myinfo =
{
	name = "Accuracy Correction",
	author = "Lucas",
	description = "Perfect Accuracy while bellow 33.4% of max weapon speed",
	version = "1.0",
	url = "forums.alliedmods.net"
}

float fVelocity[3];
int trueSpeed;


public void OnPluginStart() 
{
	/*for (int i = 1; i <= MaxClients; i++)
	{
		if (IsClientInGame(i))
		{
			OnClientPutInServer(i);
		}
	}*/
	HookEvent("player_death", Event_PlayerDeath, EventHookMode_Pre);
	RegConsoleCmd("sm_marreco", Marreco, "Prints text to chat");
	RegConsoleCmd("sm_marreco1", Marreco1, "Prints text to chat");
}

public Action Event_PlayerDeath(Event event, const char[] name, bool dontBroadcast)
{
    if (event.GetBool("headshot"))
    {
        return Plugin_Handled;
    }
    return Plugin_Continue;
}

public Action Marreco(int client, int args)
{
	trueSpeed = 74;
}
public Action Marreco1(int client, int args)
{
	trueSpeed = 72;
}

/*public void OnClientPutInServer(int client)
{
    //SDKHook(client, SDKHook_PostThinkPost, OnClientThinkPost);
}*/

/*
public Action OnPlayerRunCmd(int client) //Its running every ms? Why?
{
	if(trueSpeed > 73)
	{
		ServerCommand("weapon_accuracy_nospread 0");
	}
	else
	{
		ServerCommand("weapon_accuracy_nospread 1");
	}
	return Plugin_Handled;
}

void SendDeathMessage(int attacker, int victim, const char[] weapon, bool headshot)
{
	Event event = CreateEvent("weapon_fire");
	if (event == null)
	    {
	        return;
	    }
}*/

/*public void OnGameFrame()
{
	int client = 1;
	OnClientThinkPost(client);
}

void OnClientThinkPost(int client)
{
	GetEntPropVector(client, Prop_Data, "m_vecVelocity", fVelocity);
	trueSpeed = SquareRoot( Pow(fVelocity[0], 2.0) + Pow(fVelocity[1], 2.0));
	PrintHintText(client, "Speed: %d ", RoundFloat(trueSpeed));
}*/