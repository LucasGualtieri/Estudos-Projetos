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

ArrayList cEquipedWeapon;
ArrayList arrayWeaponAccuracy;

public APLRes AskPluginLoad2(Handle myself, bool late, char[] error, int err_max)
{
    lateloaded = late;
}

public void OnPluginStart()
{
	cEquipedWeapon = new ArrayList(5);
	arrayWeaponAccuracy = new ArrayList(5);
	
	weapon_accuracy_nospread = FindConVar("weapon_accuracy_nospread");
	weapon_accuracy_nospread.Flags &= ~FCVAR_REPLICATED;
	
	cEquipedWeapon.PushString("weapon_ak47");
	arrayWeaponAccuracy.Push(Pow(73.1, 2.0));
	cEquipedWeapon.PushString("weapon_sg556");
	arrayWeaponAccuracy.Push(Pow(71.4, 2.0));
	cEquipedWeapon.PushString("weapon_m4a1");
	arrayWeaponAccuracy.Push(Pow(76.5, 2.0));
	cEquipedWeapon.PushString("weapon_m4a1_silencer");
	arrayWeaponAccuracy.Push(Pow(76.5, 2.0));
	cEquipedWeapon.PushString("weapon_aug");
	arrayWeaponAccuracy.Push(Pow(74.8, 2.0));
    
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
    PrintToChat(client, "Teste: %i", item_def_index);
}

public void PostThink(int client)
{
    if(IsPlayerAlive(client))
    {
    	char[] weaponAccuracy = new char[64];
    	GetClientWeapon(client, weaponAccuracy, 64);
    	
        float velocity[3];
        GetEntPropVector(client, Prop_Data, "m_vecVelocity", velocity);
        bool nospread;
        
        bool haveIndex = cEquipedWeapon.FindString(weaponAccuracy) != -1 ? true : false;
        
        int weaponIndex = cEquipedWeapon.FindString(weaponAccuracy);
        if(StrContains(weaponAccuracy, "m4a1", false) != -1)
        {
    		weaponIndex  = 2;
		}
		float accuracyThreshold = haveIndex ? arrayWeaponAccuracy.Get(weaponIndex) : 00.00;
        
        //float accuracyThreshold = arrayWeaponAccuracy.Get(cEquipedWeapon.FindString(weaponAccuracy));
        PrintHintText(client, "%f", accuracyThreshold);
        
        //PrintToChatAll("id: %i", cEquipedWeapon.FindString("weapon_m4a1"));
        /*if(cEquipedWeapon.FindString("weapon_ak47") == 0)
        {
        	accuracyThreshold = Pow(73.1, 2.0);
        	PrintToChatAll("weapon_ak47");
        }
        if(cEquipedWeapon.FindString("weapon_sg556") == 1)
        {
        	accuracyThreshold = Pow(71.4, 2.0);
        	PrintToChatAll("weapon_sg556");
        }
        if(cEquipedWeapon.FindString("weapon_m4a1") == 2)
        {
        	accuracyThreshold = Pow(76.5, 2.0);
        	PrintToChatAll("weapon_m4a1");
        }
        if(cEquipedWeapon.FindString("weapon_m4a1_silencer") == 3)
        {
        	accuracyThreshold = Pow(76.5, 2.0);
        	PrintToChatAll("weapon_m4a1_silencer");
        }
        if(cEquipedWeapon.FindString("weapon_aug") == 4)
        {
        	accuracyThreshold = Pow(74.8, 2.0);
        	PrintToChatAll("weapon_aug");
        }*/
        
        if(cEquipedWeapon.FindString(weaponAccuracy) != -1)
        {
        	nospread = (velocity[0]*velocity[0]+velocity[1]*velocity[1]) < accuracyThreshold; //70.0^2 - should probably be based off held weapon
       	}
       	else
       	{
       		nospread = false;
       	}
       	
       	//PrintHintText(client, "Weapon: %s", weaponAccuracy);
        
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