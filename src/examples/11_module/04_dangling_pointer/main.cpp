#include "dangling_pointer.h"
#include<iostream>
int main() 
{
	int* ptr_num = new int(5);
	int* ptr = ptr_num;
	std::cout << *ptr;
	delete ptr_num;
	std::cout << *ptr;
	ptr_num = nullptr;

	return 0;
}