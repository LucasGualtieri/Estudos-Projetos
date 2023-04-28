#include <sourcemod>
#include <sdktools>
#include <sdkhooks>

#pragma semicolon 1
#pragma newdecls required

ConVar hConVar_NoSpread;

public Plugin myinfo =
{
	name = "Accuracy Correction",
	author = "Lucas",
	description = "Perfect Accuracy while bellow 33.4% of max weapon move speed",
	version = "1.0",
	url = "forums.alliedmods.net"
}

float fVelocity[3];
int trueSpeed;
ConVar hConVar_NoSpread;

public void OnPluginStart()
{
    hConVar_NoSpread = FindConVar("weapon_accuracy_nospread");
	SetConVarInt(hConVar_NoSpread, 0);
	
	for (int i = 1; i <= MaxClients; i++)
	{
		if (IsClientInGame(i))
		{
			OnClientPutInServer(i);
		}
	}
	
	HookEvent("weapon_fire", OnWeaponFire, EventHookMode_Pre);
}

public Action OnWeaponFire(Event event, const char[] name, bool dontBroadcast)
{
	int client = GetClientOfUserId(GetEventInt(event, "userid"));

	if (client == 0)
	{
		return;
	}

	char sWeapon[32];
	GetEventString(event, "weapon", sWeapon, sizeof(sWeapon));

	if (bDropShotEnabled[client] && GetEntProp(client, Prop_Send, "m_bIsScoped") || FindStringInArray(hWeaponsArray_NoSpread, sWeapon) != -1)
	{
		SetConVarInt(hConVar_NoSpread, 1);
		RequestFrame(Frame_DisableNoSpread);
	}
}

public void Frame_DisableNoSpread(any data)
{
	SetConVarInt(hConVar_NoSpread, 0);
}

public void OnClientPutInServer(int client)
{
	if (IsFakeClient(client))
	{
		return;
	}

	bDropShotEnabled[client] = false;
	SendConVarValue(client, hConVar_NoSpread, "0");

	SDKHook(client, SDKHook_PostThinkPost, OnPostThinkPost);
	SDKHook(client, SDKHook_OnTakeDamage, OnTakeDamage);
	SDKHook(client, SDKHook_WeaponSwitchPost, OnWeaponSwitchPost);

	SDKHook(client, SDKHook_Touch, OnTouch);
}














 OLHAR ISSO COM MAIS CALMA, PODE SER UMA OPCAO VIAVEL PARA O PROGRAMA
//new ActiveWeapon = GetEntPropEnt(client, Prop_Send, "m_hActiveWeapon");
//SetEntPropFloat(ActiveWeapon, Prop_Send, "m_fAccuracyPenalty", 5.0); 




public Action OnGameFrame()
{
	int client = 1;
	GetEntPropVector(client, Prop_Data, "m_vecVelocity", vel);
	trueSpeed = SquareRoot(vel[0] * vel[0] + vel[1] * vel[1]);
	PrintHintText(client, "Speed: %.2f", trueSpeed);

  	if(trueSpeed <= 73.1)
  	{
    	SendConVarValue(client, hConVar_NoSpread, "1");
  	}
  	else
  	{
  		SendConVarValue(client, hConVar_NoSpread, "0");
  	}
}