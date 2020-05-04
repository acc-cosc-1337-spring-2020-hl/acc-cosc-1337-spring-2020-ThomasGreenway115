#include "vector.h"
#include "vector.h"
#include "vector.h"
#include "vector.h"
#include<iostream>
/*
Allocated dynamic memory
*/
template<typename T>
Vector<T>::Vector(): size{0},nums{nullptr}, space{0}
{

}
template<typename T>
Vector<T>::Vector(size_t sz):size{sz}, nums{new T[sz]}, space{sz}
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
template<typename T>
Vector<T>::Vector(const Vector<T> & v) : size{ v.size }, nums{ new T[v.size] }
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
template<typename T>
Vector<T> & Vector<T>::operator=(const Vector<T> & v)
{
	if (this == &v)
	{
		return *this;
	}

	if (v.size <= space)
	{
		for (size_t i = 0; i < v.size; i++)
		{
			nums[i] = v.nums[i];
		}
		size = v.size;
		return *this;
	}

	T* temp = new T[v.size];
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
template<typename T>
Vector<T>::Vector(Vector<T> && v) : size{ v.size }, nums{ v.nums }
{
	delete nums;
	nums = v.nums;
	size = v.size;
	v.nums = nullptr;
	v.size = 0;
}

template<typename T>
Vector<T> & Vector<T>::operator=(Vector<T> && v)
{
	delete nums;
	nums = v.nums;
	size = v.size;
	v.nums = nullptr;
	v.size = 0;

	return *this;
}
template<typename T>
void Vector<T>::Reserve(size_t new_allocation)
{
	if (new_allocation <= space)
	{
		return;
	}
	T* temp = new T[new_allocation];
	for (size_t i = 0; i < size; ++i)
	{
		temp[i] = nums[i];
	}
	delete[] nums;
	nums = temp;

	space = new_allocation;
}
template<typename T>
void Vector<T>::Resize(size_t new_size)
{
	Reserve(new_size);

	for (size_t i = 0; i < new_size; ++i)
	{
		nums[i] = 0;
	}
}
template<typename T>
void Vector<T>::Push_Back(T value)
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
template<typename T>
Vector<T>::~Vector()
{
	std::cout << "Release memory\n\n";
	delete[] nums;
}
template class Vector<int>;
template class Vector<double>;
void use_vector()
{
	Vector<int> v(3);
}

Vector<int> get_vector()
{
	Vector<int> v(3);
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

