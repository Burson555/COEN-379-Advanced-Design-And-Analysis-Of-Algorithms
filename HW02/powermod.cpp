#include <iostream>

using namespace std;

int powermod(int a, int e, int m);

int main(int argc, char const *argv[])
{
	cout << powermod(13, 5, 17) << endl;
	cout << powermod(29, 11, 23) << endl;

	return 0;
}

int powermod(int a, int e, int m) {
	if (e == 0)
		return 1;
	if (e % 2 == 0)
		return (powermod(a, e/2, m)*powermod(a, e/2, m)) % m;
	else
		return (((powermod(a, e/2, m)*powermod(a, e/2, m)) % m) * a) % m;
}