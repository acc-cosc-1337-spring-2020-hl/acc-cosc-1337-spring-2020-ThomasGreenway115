#include "vector.h"
#include<iostream>
#include<vector>
using std::vector;
int square(int n)
{
	return n * n;
}

int main()
{
	Vector v1(3);
	for (size_t i = 0; i < v1.Size(); ++i)
	{
		std::cout << v1[i] << "\n";
	}
	
	return 0;

	
}
