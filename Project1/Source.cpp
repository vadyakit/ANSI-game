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

void* vptr;

class A {

public:
	int x, y;
	A() { x = 555; y = 666; }
};

void f() {
	A a;
	vptr = &a;
}

int main() {

	A a;
	vptr = &a.x;
	
	//f();
	//cout << (*static_cast<A*>(vptr)).x;
	
}