#include "vector.h"
#include "vector.h"
#include "vector.h"
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
/*
Use move source pointer
Point move source pointer to nothing

*/
Vector::Vector(Vector && v) : size{ v.size }, nums{ v.nums }
{
	delete nums;
	nums = v.nums;
	size = v.size;
	v.nums = nullptr;
	v.size = 0;
}


Vector & Vector::operator=(Vector && v)
{
	delete nums;
	nums = v.nums;
	size = v.size;
	v.nums = nullptr;
	v.size = 0;

	return *this;
}
void Vector::Reserve(size_t new_allocation)
{
	if (new_allocation <= space)
	{
		return;
	}
	int* temp = new int[new_allocation];
	for (size_t i = 0; i < size; ++i)
	{
		temp[i] = nums[i];
	}
	delete[] nums;
	nums = temp;

	space = new_allocation;
}

void Vector::Resize(size_t new_size)
{
	Reserve(new_size);

	for (size_t i = 0; i < new_size; ++i)
	{
		nums[i] = 0;
	}
}

void Vector::Push_Back(int value)
{
	if (space == 0)
	{
		Reserve(RESERVE_DEFAULT_SIZE);
	}
	else if (size == space) 
	{
		Reserve(space * RESERVE_SIZE_MULTIPLIER);
	}
	nums[size] = value;
	++size;
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

Vector get_vector()
{
	Vector v = Vector(3);
	return v;
}
/*
compare size to new allocation
Create temporary dynamic memory of new allocation size
Copy all current elements to temporary array
Delete current nums
set nums to new temporary dynamic array
Space to new allocation
*/

