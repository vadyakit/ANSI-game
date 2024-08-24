#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <queue>
#include <map>
#include <functional>
//#include "Drawer.h"
#include "Event.h"
//#include "ResourceLoader.h"
//#include "SpritePack.h"
//#include "Player.h"
#include <windows.h>
#include <conio.h>
#include "Switcher.h"
#include <tuple>
using namespace std;

int main() {

	list<int> a{1,2,3,4,5,6,7};
	list<int>::iterator iter;
	iter = a.begin();
	cout << *iter;
	a.erase(a.begin());
	cout << *iter;
}