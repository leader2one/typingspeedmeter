//author: Javokhirbek Jurakhodjaev

#include <iostream>
#include <string>
#include <iomanip>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <ctime>
#include <windows.h>
#include <fstream>

using namespace std;
void open()
{
	system("start text.txt ");
	system("start timer.exe");
}
int main()
{
	HWND wh = GetConsoleWindow();

	MoveWindow(wh, 200, 300, 900, 400, TRUE);//size and screen location of window
	system("COLOR F0");
	string  m = "", s = "DEAR USER Welcome to the Typing Speed Meter\n Now the text and timer will pop up and you can start typing after pressing mouse on this window again ", t = "If you think of the jobs robots could never do, you would probably put doctors and teachers at the top of the list. It's easy to imagine robot cleaners and factory workers, but some jobs need human connection and creativity.";
	ofstream text;
	text.open("text.txt");
	int i, error = 0;
	char k[300];
	cout << setfill(' ') << setw(40) << endl;

	for (int i = 0; i < s.size(); i++)

	{
		if (i == 9)
		{
			cout << setfill(' ') << setw(30) << endl;
		}
		cout << s[i];
		Sleep(100);
	}

	text << "If you think of the jobs robots could never do, you would probably put doctors and teachers at the top of the list.\nIt's easy to imagine robot cleaners and factory workers, but some jobs need human connection and creativity.";
	text.close();
	Sleep(2000);
	open();
	cout << "\n\n\n\n\n\n\n";
	cout << setfill(' ') << setw(60) << ">> START <<" << endl;
	Sleep(2000);

	clock_t timer;
	timer = clock(); //get time
	system("CLS"); // clear screen
	i = 0;

	while (i < t.size())
	{
	rew:
		k[i] = _getche();
		if (k[i] != t[i])
		{
			system("CLS");
			cout << m;
			error++;
			goto rew;
		}
		else{
			m += k[i];
			i++;
		}
	}

	timer = clock() - timer; //time passed till now in milliseconds
	cout << "\n\nNumber of errors - >" << error << endl;
	double time = timer / 1000;
	cout << "\nYou spent " << time << " seconds to type " << i << " character" << endl;
	cout << "\nYour avarage speed is " << setprecision(2) << fixed << i / time << " characters per seconds\n" << endl;

	system("pause");
	return 0;
}
