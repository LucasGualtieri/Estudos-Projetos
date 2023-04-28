#include <biblioteca_c.h>

void printMsgPt(int clientID, int args) {
	printf("Test"); // Show print just to who called
}

void smCommand(void (*callbackFunction)(int, int)) {
	int whoeverCalledID = 1, args;
	callbackFunction(whoeverCalledID, args);
}

int main() {

	smCommand(printMsgPt); // sm_printname or !printname

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}