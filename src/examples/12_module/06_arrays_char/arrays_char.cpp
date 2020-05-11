//cpp
#include"arrays_char.h"
#include<iostream>
void use_char_array()
{
	char letter = 'a';
	char name[] = "John";
	std::cout << name << "\n";
}

void use_char_array_w_size()
{
	const int SIZE = 5;
	char name[SIZE] = "Mary";
	name[4] = '\0';
	std::cout << name << "\n\n";

	for (int i = 0; name[i] != '\0'; ++i)
	{
		std::cout << name[i] << "\n";
	}
}

