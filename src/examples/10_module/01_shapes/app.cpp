//cpp
#include"app.h"
#include<iostream>
void display(int n)

{

	if (n == 0)

	{

		std::cout << "base case\n";

		return;

	}



	std::cout << "load stack\n";

	display(n - 1);

	std::cout << "unload stack\n";

}