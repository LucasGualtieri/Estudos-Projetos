#include <sourcemod>
#include <sdktools>
#define PLUGIN_VERSION "1.0"
Handle gs_Cvar_Enable = INVALID_HANDLE
Handle gs_Cvar_hegrenade = INVALID_HANDLE
Handle gs_Cvar_flashbang = INVALID_HANDLE
Handle gs_Cvar_smoke = INVALID_HANDLE
Handle gs_Cvar_molotov = INVALID_HANDLE
Handle gs_Cvar_decoy = INVALID_HANDLE

public Plugin myinfo = {
	name = "Grenades On Spawn",
	author = "Tair",
	description = "Gives Grenades On Spawn (Flash, Smoke, HeGrenade, Molotov)",
	version = "1.1",
	url = "www.sourcemod.net"
}

public OnPluginStart() {
	HookEvent("player_spawn", Event_PlayerSpawn);
	CreateConVar("sm_gs_version", PLUGIN_VERSION, "Version of the Plugin");
   gs_Cvar_Enable = CreateConVar("sm_gs_enabled", "1", "Enables or Disables the Plugin");
   gs_Cvar_molotov = CreateConVar("sm_gs_molotov", "1", "Enables or Disables Molotov");
   gs_Cvar_hegrenade = CreateConVar("sm_gs_hegrenade", "1", "Enables or Disables HeGrenade");
   gs_Cvar_flashbang = CreateConVar("sm_gs_flashbang", "1", "Enables or Disables Flashbang");
   gs_Cvar_smoke = CreateConVar("sm_gs_smoke", "1", "Enables or Disables Smoke Grenade");
   gs_Cvar_decoy = CreateConVar("sm_gs_decoy", "1", "Enables or Disables Decoy Grenade");
}

public Event_PlayerSpawn(Handle event, const String:name[], bool dontBroadcast) {
	new client = GetClientOfUserId(GetEventInt(event, "userid"));

   char grenadeNames[] {"weapon_molotov", "weapon_hegrenade", "weapon_flashbang", "weapon_smokegrenade", "weapon_decoy"};
   int gs_CvarArray[] = {gs_Cvar_molotov, gs_Cvar_hegrenade, gs_Cvar_flashbang, gs_Cvar_smoke, gs_Cvar_decoy};

	if (GetConVarInt(gs_Cvar_Enable)) {
		PrintToChat(client, "\x04[Gualtieri] \x03You've spawned with all the nades");
	
      for (int i = 0; i < 5; i++) {
         if (GetConVarInt(i)) {
            GivePlayerItem(client, gs_CvarArray[i])
         }
      }   
	}
}