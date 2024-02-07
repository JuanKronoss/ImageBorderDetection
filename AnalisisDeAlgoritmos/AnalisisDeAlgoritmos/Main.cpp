#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using std::cout;
using std::vector;
using std::find;
using std::max;

vector<unsigned int> results{};

vector<int> prices{ 0,1,5,8,9,10,17,17,20,24,30 };

unsigned int Fibo(unsigned long n)
{
	if (results[n] != NULL)
	{
		return results[n];
	}

	else if (n <= 1)
	{
		results[n] = n;
		return n;
	}

	else
	{
		//long unsigned int result1 = Fibo(n - 1);
		//long unsigned int result2 = Fibo(n - 2);
		//long unsigned int result = result1 + result2;

		results[n] = Fibo(n - 1) + Fibo(n - 2);

		return results[n];
	}
}


int NaiveFibonacci(int nesimo)
{	
	if (nesimo <= 1)
	{
		return nesimo;
	}
	else
	{
		return (NaiveFibonacci(nesimo - 1) + NaiveFibonacci(nesimo - 2));
	}
}


int CutRod(int n)
{
	if (n == 0)
	{
		return 0;
	}

	int q = std::numeric_limits<int>::min();

	for (int i = 1; i <= n; ++i)
	{
		q = max(q, prices[i] + CutRod(n - i));
	}

	return q;
}


int main()
{
	unsigned int n_Fibonacci = 100;
	
	//cout << "\n" << NaiveFibonacci(10) << "\n";

	//results.resize(n_Fibonacci + 1);
	//cout << "\n" << Fibo(n_Fibonacci) << "\n";

	int nRod = 4;
	cout << CutRod(nRod);

	return 0;
}