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
    weapon_accuracy_nospread = FindConVar("weapon_accuracy_nospread");
    weapon_accuracy_nospread.Flags &= ~FCVAR_REPLICATED;
    
    if(lateloaded)
    {
        for(int i = 1; i <= MaxClients; i++)
        {
            if(IsClientInGame(i))
            {
                OnClientPutInServer(i);
            }
        }
    }
}

public void OnClientPutInServer(int client)
{
    if(!IsFakeClient(client))
    {
        //SDKHook(client, SDKHook_WeaponSwitchPost, WeaponSwitchPost);
        SDKHook(client, SDKHook_PostThink, PostThink);
        
        weapon_accuracy_nospread.ReplicateToClient(client, "0");
        
#if defined REPLICATE_VALUE
        replicated_nospread[client] = false;
#endif
    }
}

public void PostThink(int client)
{
    if(IsPlayerAlive(client))
    {
        float velocity[3];
        GetEntPropVector(client, Prop_Data, "m_vecVelocity", velocity);
        
        bool nospread = (velocity[0]*velocity[0]+velocity[1]*velocity[1]) < 4900.0; //70.0^2 //should probably be based off held weapon
                                                                                    
        //change convar on the server for the simulation of this player
        weapon_accuracy_nospread.BoolValue = nospread;
        
        if(GetSpeed(client) > 70)
  		{
	    	SendConVarValue(weapon_accuracy_nospread, "0");
  		}
  		else
  		{
	  		SendConVarValue(client, weapon_accuracy_nospread, "1");
  		}
        
		#if defined REPLICATE_VALUE
        //only replicate to the client if they've got the wrong value
        if(nospread != replicated_nospread[client])
        {
            weapon_accuracy_nospread.ReplicateToClient(client, nospread ? "1" : "0");
            replicated_nospread[client] = nospread;
        }
    }#endif
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

