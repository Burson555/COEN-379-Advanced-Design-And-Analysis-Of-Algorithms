#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char const *argv[])
{
	int a;
	int b;
	int *c;
	c = (int*) malloc(sizeof(int));
	char haha[99];

	cout << "Give me 3 integers: " << endl;
	cin >> a >> b >> *c;
	cin >> haha;

	cout << *c << b << a << endl;
	cout << haha << endl;
	
	return 0;
}