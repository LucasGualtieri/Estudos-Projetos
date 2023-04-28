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

public void OnGameFrame()
{
	int client = 1;
	float fVelocity[3];
	GetEntPropVector(client, Prop_Data, "m_vecVelocity", fVelocity);
	float trueSpeed = SquareRoot(Pow(fVelocity[0],2.0)+Pow(fVelocity[1],2.0));
	PrintHintText(client, "%.2f", trueSpeed);
	
	if(trueSpeed > 73.1 || fVelocity[2] != 0)
	{
		ServerCommand("weapon_accuracy_nospread 0");
	}
	else
	{
		ServerCommand("weapon_accuracy_nospread 1");
	}
}