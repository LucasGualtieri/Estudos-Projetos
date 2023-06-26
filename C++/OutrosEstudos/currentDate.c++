#include <biblioteca_cpp.h>

using namespace std;

int main() {

	time_t	   currentTime;
	struct tm* localTime;
	char	   date[100];

	// Get the current time
	currentTime = time(NULL);

	// Convert the current time to the local time
	localTime = localtime(&currentTime);

	// Format the date string
	strftime(date, sizeof(date), "%Y-%m-%d", localTime);

	// Print the date
	printf("Current date: %s\n", date);

	cout << "\n------- | FIM DO PROGRAMA | -------\n\n";
	return 0;
}