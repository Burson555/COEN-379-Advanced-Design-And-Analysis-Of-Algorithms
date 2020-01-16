#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	cout << "Hello, Beautiful Life!" << endl;
	cout << time(0) << endl;
	int x = 1;
	int y = x;
	x++;
	cout << x << endl;
	cout << y << endl;
	int aa = 
				666;
	cout << aa << endl;

	typedef int feet;
	feet haha = 520;
	cout << haha << endl;

	enum color { red, green, blue, grey, black, purple} c;
	c = purple;
	cout << c << endl;

	enum color_B { pink, violet=-5, yellow } d;
	d = yellow;
	cout << d << endl;

	return 0;
}