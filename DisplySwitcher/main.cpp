#include <Windows.h>
#include <string>
#include <iostream>

using namespace std;

#define MONITOR_ON -1
#define MONITOR_ENERGY_SAVING 1
#define MONITOR_OFF 2

void set_display_mode(int mode)
{
	HWND console = GetConsoleWindow();

	SendMessage(console, WM_SYSCOMMAND, SC_MONITORPOWER, mode);
}

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		return -1;
	}

	char* monitor_mode = argv[1];

	string mode_str = string(monitor_mode);

	if (mode_str == "on")
	{
		cout << "Turning display on" << endl;
		set_display_mode(MONITOR_ON);
	}
	else if(mode_str == "off")
	{
		cout << "Turning display off after 5 seconds" << endl;
		Sleep(5000);
		set_display_mode(MONITOR_OFF);
	}
	else if (mode_str == "blink")
	{
		cout << "Blink!" << endl;
		Sleep(3000);
		set_display_mode(MONITOR_OFF);
		Sleep(10000);
		set_display_mode(MONITOR_ON);
	}
}