#include <sdkhooks>

#pragma newdecls required
#pragma semicolon 1

public Plugin myinfo = 
{
    name = "Accuracy Correction",
	author = "domino_ and Henrik",
	description = "Perfect Accuracy while bellow 34% of max weapon move speed",
	version = "1.3",
	url = "forums.alliedmods.net"
};

//#define REPLICATE_VALUE

ConVar weapon_accuracy_nospread = null;

#if defined REPLICATE_VALUE
bool replicated_nospread[MAXPLAYERS+1] = {false, ...};
#endif

bool lateloaded = false;

int accuracyThreshold[MAXPLAYERS + 1];
int isPoolWeapon[MAXPLAYERS + 1];


public APLRes AskPluginLoad2(Handle myself, bool late, char[] error, int err_max)
{
    lateloaded = late;
}

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

public void OnPluginEnd()
{
    weapon_accuracy_nospread.Flags |= FCVAR_REPLICATED;
    weapon_accuracy_nospread.BoolValue = false;
}

public void OnClientPutInServer(int client)
{
    if(!IsFakeClient(client))
    {
    	accuracyThreshold[client] = 00.00;
    	isPoolWeapon[client] = false;
        SDKHook(client, SDKHook_WeaponSwitchPost, WeaponSwitchPost);
        SDKHook(client, SDKHook_PostThink, PostThink);
        //SDKHook(client, SDKHook_WeaponCanUse, WeaponScoped);
        
        weapon_accuracy_nospread.ReplicateToClient(client, "0");
        
#if defined REPLICATE_VALUE
        replicated_nospread[client] = false;
#endif
    }
}


public void WeaponScoped(int client, int weapon)
{
    int isWeaponScoped = GetEntProp(client, Prop_Send, "m_bIsScoped");
}

public void WeaponSwitchPost(int client, int weapon)
{
    int item_def_index = GetEntProp(weapon, Prop_Send, "m_iItemDefinitionIndex");
    
    accuracyThreshold[client] = 00.00;
    
    if(item_def_index == 60) {
		accuracyThreshold[client] = Pow(76.5, 2.0); //M4a1 silence
		isPoolWeapon[client] = true;
	}
	
	if(item_def_index == 7) {
		accuracyThreshold[client] = Pow(73.1, 2.0); //ak47
		isPoolWeapon[client] = true;
	}
	
	if(item_def_index == 16) {
		accuracyThreshold[client] = Pow(76.5, 2.0); // m4a1
		isPoolWeapon[client] = true;
	}
	
	if(item_def_index == 39) {
		accuracyThreshold[client] = Pow(71.4, 2.0); // sg556
		isPoolWeapon[client] = true;
	}
	
	if(item_def_index == 8) {
		accuracyThreshold[client] = Pow(74.8, 2.0); // aug
		isPoolWeapon[client] = true;
	}
}



public void PostThink(int client, int weapon)
{
    if(IsPlayerAlive(client))
    {    	
        float velocity[3];
        GetEntPropVector(client, Prop_Data, "m_vecVelocity", velocity);
        bool nospread;		
        
        PrintHintText(client, "%f", accuracyThreshold[client]);
        
        if(isPoolWeapon[client])
        {
        	nospread = (Pow(velocity[0],2.0) + Pow(velocity[1],2.0)) < accuracyThreshold[client] && velocity[2] == 0; //70.0^2 - should probably be based off held weapon
       	}
       	else
       	{
       		nospread = false;
       	}
       	//PrintHintText(client, "Speed: %f", velocity[0] * velocity[0] + velocity[1] * velocity[1]);
       	
        //change convar on the server for the simulation of this player
        weapon_accuracy_nospread.BoolValue = nospread;
        
		#if defined REPLICATE_VALUE
        //only replicate to the client if they've got the wrong value
        if(nospread != replicated_nospread[client])
        {
            weapon_accuracy_nospread.ReplicateToClient(client, nospread ? "1" : "0");
            replicated_nospread[client] = nospread;
        }
		#endif
    }
}