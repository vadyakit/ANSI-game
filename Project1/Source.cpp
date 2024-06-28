#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <queue>
#include <map>
#include <functional>
#include "Drawer.h"
#include "Event.h"
#include "ResourceLoader.h"
#include "SpritePack.h"
#include "Player.h"
#include <windows.h>
#include <conio.h>
using namespace std;

function<void(function<void(char key)> OnKeyDown, function<void(char key)> OnKeyUp)> KeyEventHandler;
function<void(function<void(vector<int[2]> Indexes)> OnCollision)> CollisionEventHandler;
function<void(function<void(unsigned duration)> OnTimer)> TimerEventHandler;

 

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