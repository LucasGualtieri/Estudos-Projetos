#include <sourcemod>
#include <sdktools>

#pragma semicolon 1
#pragma newdecls required

public Plugin myinfo =
{
	name = "Studying",
	author = "Lucas",
	description = "Kicks Bots Automagically",
	version = "1.0",
	url = "forums.alliedmods.net"
}

//int teste = 1;

public void OnPluginStart()
{
	RegConsoleCmd("sm_marreco1", Command_Test1, "Prints text to chat"); 
	
}

public Action Command_Test1(int client, int args)
{
	//teste++;
	
	//if(teste > 1)
	//{
	//	ServerCommand("weapon_accuracy_nospread 1");
	//}
	
	//int fVelocity[3];
	//GetEntPropFloat(client, Prop_Data, "m_vecVelocity", fVelocity);
	//ReplyToCommand(client, "%d", fVelocity);
	
	//float fVelocity[3];
	//GetEntPropVector(client, Prop_Data, "m_vecVelocity", fVelocity);
	//ReplyToCommand(client, "%d", fVelocity);
	//fVelocity[2] = 1750.0;
	
	//float speeD = GetEntPropFloat(client, Prop_Data, "m_vecVelocity");
	//int mult;
	//GetEntPropVector(client, Prop_Data, "m_vecVelocity", mult);
	//ReplyToCommand(client, "%d", mult);
	//float currentspeed = SquareRoot(Pow(fVelocity[0],2.0)+Pow(fVelocity[1],2.0));
	
	
	//ReplyToCommand(client, "TESTANDO MARRECO%d", teste);
	
	float fVelocity[3];
	GetEntPropVector(client, Prop_Data, "m_vecAbsVelocity", fVelocity);
	ReplyToCommand(client, "X: %.2f / Y: %.2f / Z: %.2f", fVelocity[0], fVelocity[1], fVelocity[2]);
	
	//Isso é pitagoras pra ter um valor unico
	float trueSpeed2 = fVelocity[0] * fVelocity[0];
	float trueSpeed3 = fVelocity[1] * fVelocity[1];
	float trueSpeed1 = trueSpeed2 + trueSpeed3;
	float trueSpeed = SquareRoot(trueSpeed1);
	//Isso é o reply da velocidade de verdade
	ReplyToCommand(client, "%.2f", trueSpeed);
	
	//Esse é o coração do plugin
	if(trueSpeed > 73.1 || fVelocity[2] != 0)
	{
		ServerCommand("weapon_accuracy_nospread 0");
		ReplyToCommand(client, "weapon_accuracy_nospread 0");
	}
	else
	{
		ServerCommand("weapon_accuracy_nospread 1");
		ReplyToCommand(client, "weapon_accuracy_nospread 1");
	}	
	return Plugin_Handled;
}