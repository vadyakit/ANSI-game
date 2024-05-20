#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include "Drawer.h"
#include "ResourceLoader.h"
#include "SpritePack.h"
#include "Player.h"
#include <windows.h>
#include <conio.h>
using namespace std;

void f(HWND hwnd, UINT uMsg, UINT timerId, DWORD dwTime)
{
	cout << "fdgdfg";
}

int main() {

	Player player;
	Drawer drawer;
	//SpritePack sprites;
	
	
	while (true) {
		//drawer.Draw(player);
		Sleep(30);
		//drawer.ClearConsole();
		//system("cls");
	}	
}