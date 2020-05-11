//
#ifndef MY_VECTOR_H
#define MY_VECTOR_H
#include<vector>
using std::vector;
template<typename T>
class Vector
{
public:
	Vector();
	Vector(size_t sz);
	Vector(const Vector& v);//copy constructor-RULE OF 3 - c++98
	Vector<T>& operator=(const Vector<T>& v);//copy assignment-RULE OF 3 -c++98
	Vector(Vector&& v); //move constructor - RULE OF 5 C++ 11
	Vector<T>& operator=(Vector<T>&& v);//move assignment - RULE OF 5 C++11
	size_t Size()const { return size; }
	T& operator[](int i) { return nums[i]; }
	T& operator[](int i) const { return nums[i]; }
	void Reserve(size_t new_allocation);
	size_t Capacity()const { return space; }
	void Resize(size_t new_size);
	void Push_Back(T value);
	~Vector();//destructor-RULE OF 3
private:
	/*
	Tracks space ready to use
	*/
	size_t size;
	/*
	Track reserved space
	*/
	size_t space{ 0 };
	/*
	Initial reserve default size
	*/
	const int RESERVE_DEFAULT_SIZE{ 8 };
	/*
	Size multiplier
	*/
	const int RESERVE_SIZE_MULTIPLIER{ 2 };

	T* nums;
};


#endif // !MY_VECTOR_H
void use_vector();
Vector<int> get_vector();