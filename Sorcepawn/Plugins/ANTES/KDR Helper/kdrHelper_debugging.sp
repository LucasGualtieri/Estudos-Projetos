#include <sdkhooks>

#pragma newdecls required
#pragma semicolon 1

public Plugin myinfo = 
{
    name = "KDR Helper",
	author = "Lucas",
	description = "Helps you keep a targeted KDR",
	version = "1.0",
	url = "forums.alliedmods.net"
};

float targetKDR [MAXPLAYERS + 1];
float deficitKDR0 [MAXPLAYERS + 1];
float deficitKDR1 [MAXPLAYERS + 1];
float KDR [MAXPLAYERS + 1];
int kills [MAXPLAYERS + 1];
int deaths [MAXPLAYERS + 1];
bool pluginToggle [MAXPLAYERS + 1];

public void OnPluginStart()
{
    for(int i = 1; i <= MaxClients; i++)
    {
        if(IsClientInGame(i))
        {
            OnClientPutInServer(i);
        }
    }
    HookEvent("player_death", player_death);
    RegConsoleCmd("sm_kdr", PluginToggle, "Toggles plugin on/off");
    RegConsoleCmd("sm_target", targetFunction, "Sets the desired KDR target");
}

public void OnClientPutInServer(int client)
{
    if(!IsFakeClient(client))
    {
    	kills[client] = 0;
    	deaths[client] = 0;
    	targetKDR[client] = 1.0;
    	KDR[client] = 0.0;
    	deficitKDR0[client] = 0.0;
    	deficitKDR1[client] = 0.0;
    	pluginToggle[client] = false;
    }
}

public Action PluginToggle(int client, int args)
{
	if(pluginToggle[client])
	{
		pluginToggle[client] = false;
		ReplyToCommand(client, "KDR Helper disabled!");
	}
	else
	{
		kills[client] = GetClientFrags(client);
		deaths[client] = GetClientDeaths(client);
		pluginToggle[client] = true;
		ReplyToCommand(client, "KDR Helper enabled!");
	}
	return Plugin_Handled;
}

public Action targetFunction(int client, int args)
{
	//https://wiki.alliedmods.net/Commands_(SourceMod_Scripting) //Adding Server Commands
    char arg[128];
    char full[256];
 
    GetCmdArgString(full, sizeof(full));
 
    for (int i = 1; i <= args; i++)
    {
        GetCmdArg(i, arg, sizeof(arg));
    }
    targetKDR[client] = StringToFloat(arg);
    ReplyToCommand(client, "Targeted KDR: %.2f", targetKDR[client]);
 
    return Plugin_Handled;
}

public Action player_death(Event event, const char[] name, bool dontBroadcast)
{
	int client = 1;
	if(pluginToggle[client])
	{
		int attacker = GetClientOfUserId(GetEventInt(event, "attacker"));
		int victim = GetClientOfUserId(GetEventInt(event, "userid"));
	
		if(attacker > 0)
		{
			kills[attacker]++;
			deficitKDR0[attacker] = deaths[attacker] * targetKDR[attacker];
			deficitKDR1[attacker] = deficitKDR0[attacker] - kills[attacker];
			
			PrintHintText(attacker, "KDR DEFICIT: %.2f", (deficitKDR1[attacker] * -1));
		}
	
		else if(victim == attacker)
		{
			//PrintToChatAll("Morreu");
		}
		if(victim > 0)
		{
			deaths[victim]++;
			deficitKDR0[victim] = deaths[victim] * targetKDR[victim];
			deficitKDR1[victim] = deficitKDR0[victim] - kills[victim];
			
			PrintHintText(victim, "KDR DEFICIT: %.2f", (deficitKDR1[victim] * -1));
		}
		return Plugin_Continue;
		}
	else
	{
		return Plugin_Handled;
	}
}
