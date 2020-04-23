#include "vector.h"
#include<iostream>
/*
Allocated dynamic memory
*/
Vector::Vector(size_t sz):size{sz}, nums{new int[sz]}
{
	for (size_t i = 0; i < sz; ++i)
	{
		nums[i] = 0;
	}
}
/*
Set the new class size to the right-hand operand array size
Initialized a dynamic memory array of size elements
Inititalized all the elements to the value of the right-hand operand
*/
Vector::Vector(const Vector & v) : size{ v.size }, nums{ new int[v.size] }
{
	std::cout << "allocate memory\n";
	for (size_t i = 0; i < size; ++i)
	{
		nums[i] = v[i];
	}
}

/*
Allocated temporary memory of right-hand operand size
Initialized temp elements to right-hand operand elements' value
Deallocated created memory of this class
Copied temporary memory to this class (nums)
Set size to right-hand operand size
Return a dereferenced instance of this class
*/
Vector & Vector::operator=(const Vector & v)
{
	int* temp = new int[v.size];
	for (size_t i = 0; i < v.size; ++i)
	{
		temp[i] = v[i];
	}
	delete[]nums;
	nums = temp;
	size = v.size;

	return *this;
}

Vector::~Vector()
{
	std::cout << "Release memory\n\n";
	delete[] nums;
}

void use_vector()
{
	Vector v(3);
}