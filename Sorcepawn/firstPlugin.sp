#include <sdktools>
#include <sourcemod>

#pragma semicolon 1
#pragma newdecls required

#define MAX_PLAYER_NAME 64

public Plugin myinfo =
{
	name = "Printing your name in chat",
	author = "Lucas Gualtieri",
	description = "My First Plugin",
	version = "1.0",
	url = "github.com/LucasGualtieri"
};

public void OnPluginStart() { // Public/Global Forward
	RegConsoleCmd("sm_print_name", PrintClientName);
	RegConsoleCmd("sm_sum", SumOfTwoNumbers);
	RegConsoleCmd("sm_change_name", ChangeClientName);
}

// Fowards are functions that Sourcemod will call
// Natives are function that we call in our code

// Functions of type Action return Plugin_Handled! Always? I dunno...
public Action PrintClientName(int clientID, int numberOfArgs) { // Private Forward - Means that we have to register such forward ourselves
	if (numberOfArgs != 0) {
		// !print_name has 0 args, but !ban <name> <seconds> has two
		ReplyToCommand(clientID, "[LULU] Correct usage: sm_print_name"); // Native
		return Plugin_Handled;
	}

	char clientName[MAX_PLAYER_NAME];
	if (GetClientName(clientID, clientName, sizeof(clientName))) { // Native
		ReplyToCommand(clientID, "Your name is: %s", clientName); // Native
	} else {
		PrintToConsole(clientID, "Something went wrong!"); // Native
	}

	return Plugin_Handled;
}

public Action SumOfTwoNumbers(int clientID, int numberOfArgs) {
	if (numberOfArgs != 2) {
		ReplyToCommand(clientID, "[LULU] Correct usage: sm_sum <num1> <num2>"); // Native
		return Plugin_Handled;
	}

	const int maxLength = 10;
	char arg1[maxLength], arg2[maxLength];

	GetCmdArg(1, arg1, maxLength);
	GetCmdArg(2, arg2, maxLength);

	int num1 = StringToInt(arg1), num2 = StringToInt(arg2);

	ReplyToCommand(clientID, "[LULU] %d + %d = %d", num1, num2, num1 + num2);

	return Plugin_Handled;
}

public Action ChangeClientName(int clientID, int numberOfArgs) {
	if (numberOfArgs != 1) {
		ReplyToCommand(clientID, "[LULU] Correct usage: sm_change_name <\"new name\"> (quotes are optional for single names)"); // Native
		return Plugin_Handled;
	}

	char clientNewName[MAX_PLAYER_NAME];

	GetCmdArg(1, clientNewName, sizeof(clientNewName));

	SetClientName(clientID, clientNewName);

	return Plugin_Handled;
}