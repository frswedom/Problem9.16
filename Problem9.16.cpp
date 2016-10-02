#include <stdint.h>
#include <iostream>

using namespace std;

uint32_t mwc()
{
	static uint32_t x = 123456789L, y = 362436069L, z = 77465321L, c = 13579L;
	uint64_t t;
	t = 916905990LL * x + c;
	x = y; y = z;
	c = (t >> 32);
	return z = (t & 0xffffffff);
}
uint32_t x128()
{
	static uint32_t x = 123456789L, y = 362436069L, z = 521288629L, w = 88675123L;
	uint32_t t;
	t = (x ^ (x << 11));
	x = y; y = z; z = w;
	return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}
double uniform(double a, double b)
{
	return a + (b - a)*mwc() / UINT32_MAX;
}
/*
int main()
{
	unsigned count = 0, inside = 0;
	const unsigned countMax = 10000000;
	while (count < countMax)
	{
		double x = uniform(-2, 2);
		double y = uniform(0, 3);
		if ((9 * x*x + 4 * y*y) < 36)
		{
			double z = uniform(0, 3);
			if (z < y)
				inside++;
		}
		count++;
	}
	cout << inside << '\n';
	cout << 36. * inside / countMax << '\n';
	cout << "Exact: 12";
	return 0;
}
*/
int main()
{
	cout.precision(15);
	int count = 0, inside = 0;
	const int countMax = 10000;
	const double totalVolume = 48.;
	while (count < countMax)
	{
		double x = uniform(0, 2);
		double y = uniform(-2, 2);
		if ((x*x + y*y) <= 4.)
		{
			double z = uniform(0, 6);
			if (x + y + z <= 4.)
				inside++;
		}
		count++;
	}
	cout << inside << '\n';
	cout << totalVolume * inside / countMax << '\n';
	cout << "Exact: 19.7994078953850\n";
	cout << 19.7994078953850 - totalVolume * inside / countMax;
	return 0;
}
