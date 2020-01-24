#include <iostream>
#include <cmath>

using namespace std;
int TARGET = 20;
  
int gcd(int a, int b) { 
    if (a < b) return gcd(b, a); 
    if (a % b == 0) return b; 
    return gcd(b, a % b); 
}

int powermod(int a, int e, int m) {
	if (e == 0) return 1;
	if (e % 2 == 0)
		return (powermod(a, e/2, m)*powermod(a, e/2, m)) % m;
	else
		return (((powermod(a, e/2, m)*powermod(a, e/2, m)) % m) * a) % m;
}
  
bool fermatTest(int n) { 
    for (int b = 2; b < n; b++) { 
        if (gcd(b, n) == 1)
            if (powermod(b, n-1, n) != 1) 
                return false; 
    } 
    return true; 
} 
  
bool checkCarmichael(int current) { 
	int bound = sqrt(current);
    for (int i = 2; i < bound; i++) { 
        if (current % i == 0)
        	return true;
    } 
    return false; 
} 

int main(int argc, char const *argv[]) {
	int carmichaels[TARGET];
	int current = 2;
	cout << endl;
	for (int i = 0; i < TARGET; i++) {
		while (current++) {
			if (fermatTest(current) && checkCarmichael(current)) {
				carmichaels[i] = current;
				cout << "Carmichael No. " << i+1 << "\t-\t" << current << endl;
				break;
			}
		}
	}
    return 0; 
}