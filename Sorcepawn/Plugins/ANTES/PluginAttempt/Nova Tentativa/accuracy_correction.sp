#include <sourcemod>
#include <sdktools>

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

public void OnPluginStart()
{
	//RegConsoleCmd("sm_marreco", Command_Test1, "Prints text to chat");
}

float fVelocity[3];
float trueSpeed;

/*public Action Command_Test1(int client, int args)
{
	int i = 1;
    GetEntPropVector(i, Prop_Data, "m_vecVelocity", fVelocity);
	trueSpeed = SquareRoot( Pow(fVelocity[0], 2.0) + Pow(fVelocity[1], 2.0));
	PrintHintText(i, "Speed: %.2f ", trueSpeed);

	if(trueSpeed > 73.1 || fVelocity[2] != 0)
	{
		ServerCommand("weapon_accuracy_nospread 0");
		//PrintToChatAll("weapon_accuracy_nospread 0");
	}
	else
	{
		ServerCommand("weapon_accuracy_nospread 1");
		//PrintToChatAll("weapon_accuracy_nospread 1");
	}
}*/

public void OnGameFrame()
{
    int i = 1;
    GetEntPropVector(i, Prop_Data, "m_vecVelocity", fVelocity);
	trueSpeed = SquareRoot( Pow(fVelocity[0], 2.0) + Pow(fVelocity[1], 2.0));
	PrintHintText(i, "Speed: %.2f ", trueSpeed);

		
	if(trueSpeed > 73.1 || fVelocity[2] != 0)
	{
		ServerCommand("weapon_accuracy_nospread 0");
		//PrintToChatAll("weapon_accuracy_nospread 0");
	}
	else
	{
		ServerCommand("weapon_accuracy_nospread 1");
		//PrintToChatAll("weapon_accuracy_nospread 1");
	}
}
