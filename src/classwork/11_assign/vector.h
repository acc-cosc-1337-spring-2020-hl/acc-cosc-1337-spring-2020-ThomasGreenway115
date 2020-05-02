//
#ifndef MY_VECTOR_H
#define MY_VECTOR_H
#include<vector>
using std::vector;
class Vector
{
public:
	Vector(size_t sz);
	Vector(const Vector& v); 
	Vector& operator=(const Vector& v);
	Vector(Vector&& v);//move constructor
	Vector& operator=(Vector&& v);
	size_t Size()const { return size; }
	int& operator[](int i) { return nums[i]; }
	int& operator[](int i) const { return nums[i]; }
	void Reserve(size_t new_allocation);
	size_t Capacity()const { return space; }
	void Resize(size_t new_size);
	void Push_Back(int value);
	~Vector();//destructor

private:
	size_t size;
	size_t space{ 0 };
	int* nums;
	const int RESERVE_DEFAULT_SIZE{ 8 };
	const int RESERVE_SIZE_MULTIPLIER{ 2 };
};


#endif // !MY_VECTOR_H
void use_vector();
Vector get_vector();