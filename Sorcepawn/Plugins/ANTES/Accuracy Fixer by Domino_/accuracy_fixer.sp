#include <sdkhooks>

#pragma newdecls required
#pragma semicolon 1

public Plugin myinfo = 
{
    name = "Accuracy Correction",
	author = "domino_ and Henrik",
	description = "Perfect Accuracy while bellow 34% of weapon max move speed",
	version = "1.6",
	url = "forums.alliedmods.net"
};

//#define REPLICATE_VALUE

ConVar weapon_accuracy_nospread = null;

#if defined REPLICATE_VALUE
bool replicated_nospread[MAXPLAYERS+1] = {false, ...};
#endif

bool lateloaded = false;

float accuracyThreshold[MAXPLAYERS + 1];
bool isPoolWeapon[MAXPLAYERS + 1];
int playerCurFov[MAXPLAYERS + 1];
int currWeaponID[MAXPLAYERS + 1];

float accuracyDic[61];


public APLRes AskPluginLoad2(Handle myself, bool late, char[] error, int err_max)
{
    lateloaded = late;
}

public void OnPluginStart()
{
	accuracyDic[60]  = Pow(76.5, 2.0);
	accuracyDic[7] = Pow(73.1, 2.0);
	accuracyDic[16]  = Pow(76.5, 2.0);
	accuracyDic[39]  = Pow(71.4, 2.0);
	accuracyDic[8]  = Pow(74.8, 2.0);

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
    	currWeaponID[client] = 00;
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
    playerCurFov[client] = 90;
    currWeaponID[client] = item_def_index;
    
    accuracyThreshold[client] = 00.00;
    isPoolWeapon[client] = false;
    
    if(item_def_index == 60 
    	|| item_def_index == 7
    	|| item_def_index == 16
    	|| item_def_index == 39
    	|| item_def_index == 8) {
		isPoolWeapon[client] = true;
		accuracyThreshold[client] = accuracyDic[item_def_index];
	}
    
}



public void PostThink(int client)
{
    if(IsPlayerAlive(client))
    {
    	
    	int currentWeaponID = currWeaponID[client];
    	
    	//Parte que controla o se o jogador está scopado enquanto usa a Krieg ou a AUG
    	playerCurFov[client] = (GetEntProp(client, Prop_Data, "m_iFOV") > 0) ? GetEntProp(client, Prop_Data, "m_iFOV") : 90;
    	bool isScooped = playerCurFov[client] < GetEntProp(client, Prop_Data, "m_iDefaultFOV");
    	
    	if(isScooped) {
    		accuracyThreshold[client] = 2601.0;
    	}
    	else if(currentWeaponID == 60 
    	|| currentWeaponID == 7
    	|| currentWeaponID == 16
    	|| currentWeaponID == 39
    	|| currentWeaponID == 8) {
			accuracyThreshold[client] = accuracyDic[currentWeaponID];
		}else {
    		accuracyThreshold[client] = 00.00;
    	}//--------------------------------------------------------------------------------------------------------
    	
        float velocity[3];
        GetEntPropVector(client, Prop_Data, "m_vecVelocity", velocity);
        bool nospread;		
        
        if(isPoolWeapon[client])
        {
        	nospread = (velocity[0]*velocity[0]+velocity[1]*velocity[1]) < accuracyThreshold[client] && velocity[2] == 0; //70.0^2 - should probably be based off held weapon
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

//PrintHintText(client, "%f", accuracyThreshold[client]);
//PrintHintText(client, "%f", accuracyThreshold);
//PrintHintText(client, "%f %f %i", accuracyThreshold[client], velocity[0]*velocity[0]+velocity[1]*velocity[1], nospread ? 1 : 0);