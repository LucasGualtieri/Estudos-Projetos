#include <sdkhooks>

#pragma newdecls required
#pragma semicolon 1

public Plugin myinfo = 
{
    name = "Accuracy Correction",
	author = "Lucas",
	description = "Perfect Accuracy while bellow 33.4% of max weapon speed",
	version = "1.0",
	url = "forums.alliedmods.net"
};

//#define REPLICATE_VALUE

ConVar weapon_accuracy_nospread = null;

#if defined REPLICATE_VALUE
bool replicated_nospread[MAXPLAYERS+1] = {false, ...};
#endif

bool lateloaded = false;

int playerWeaponId[MAXPLAYERS + 1];


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
    	playerWeaponId[client] = 0;
        SDKHook(client, SDKHook_WeaponSwitchPost, WeaponSwitchPost);
        SDKHook(client, SDKHook_PostThink, PostThink);
        
        weapon_accuracy_nospread.ReplicateToClient(client, "0");
        
#if defined REPLICATE_VALUE
        replicated_nospread[client] = false;
#endif
    }
}


public void WeaponSwitchPost(int client, int weapon)
{
    int item_def_index = GetEntProp(weapon, Prop_Send, "m_iItemDefinitionIndex");
    
    playerWeaponId[client] = item_def_index;
    
}



public void PostThink(int client, int weapon)
{
    if(IsPlayerAlive(client))
    {
    	int weaponIndex = playerWeaponId[client];
    	//PrintHintText(client, "%i", weaponIndex);
    	
        float velocity[3];
        GetEntPropVector(client, Prop_Data, "m_vecVelocity", velocity);
        bool nospread;
        
        bool isPoolWeapon = false;
		float accuracyThreshold = 00.00;
		
		if(weaponIndex == 60) {
    		accuracyThreshold = Pow(76.5, 2.0); //M4a1 silence
    		isPoolWeapon = true;
    	}
    	
    	if(weaponIndex == 7) {
    		accuracyThreshold = Pow(73.1, 2.0); //ak47
    		isPoolWeapon = true;
    	}
    	
    	if(weaponIndex == 16) {
    		accuracyThreshold = Pow(76.5, 2.0); // m4a1
    		isPoolWeapon = true;
    	}
    	
    	if(weaponIndex == 39) {
    		accuracyThreshold = Pow(71.4, 2.0); // sg556
    		isPoolWeapon = true;
    	}
    	
    	if(weaponIndex == 8) {
    		accuracyThreshold = Pow(74.8, 2.0); // aug
    		isPoolWeapon = true;
    	}
        
        PrintHintText(client, "%f", accuracyThreshold);
        
        if(isPoolWeapon)
        {
        	nospread = (velocity[0]*velocity[0]+velocity[1]*velocity[1]) < accuracyThreshold; //70.0^2 - should probably be based off held weapon
       	}
       	else
       	{
       		nospread = false;
       	}
       	
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