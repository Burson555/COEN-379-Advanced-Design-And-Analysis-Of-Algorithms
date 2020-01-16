// FRIST, we use elementary level algebra to find the maximum and minimum
// 		of the target function, e^(x+x^2), within the given range [-2, 2].
// 		The maximum is e^6 while x = 2.
// 		The minimum is e^(-1/4) while x = -1/2.
// 		We can see the result of the target function is always positive.
// 		This behavior largely simplifies the computation.
// SECOND, we generate one billion random double type pairs of [a, b],
// 		where -2<a<2 and 0<b<e^6.
// 		Then count those [a, b] that satisfies, b < e^(a+a^2).
// FINALLY, we divide the number counted by one billion 
// 		and multiply the result by area of all random pairs, 4*e^6.
// 		The multiplication result is an approximation of the integral.

#include <iostream>      /* printf */
#include <cmath>       /* exp */
#include <ctime>
using namespace std;

int main ()
{
	int num_iteration = pow(10, 9);
	int count = 0;
	double MAX = exp(6);

	srand(time(0));

	for (int i = 0; i < num_iteration; ++i) {
		double a = 4 * (rand()/(double)(RAND_MAX+1.)) - 2;
		double b = MAX * (rand()/(double)(RAND_MAX+1.));
		if (b <= exp(a+pow(a, 2)))
			count++;
	}

	cout << "The estimated integral result is: ";
	cout << (double)count/num_iteration*4*MAX << endl;

	return 0;
}