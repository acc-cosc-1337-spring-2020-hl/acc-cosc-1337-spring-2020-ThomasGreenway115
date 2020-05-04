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
	Vector(const Vector& v); 
	Vector<T>& operator=(const Vector<T>& v);
	Vector(Vector&& v);//move constructor
	Vector<T>& operator=(Vector<T>&& v);
	size_t Size()const { return size; }
	T& operator[](int i) { return nums[i]; }
	T& operator[](int i) const { return nums[i]; }
	void Reserve(size_t new_allocation);
	size_t Capacity()const { return space; }
	void Resize(size_t new_size);
	void Push_Back(T value);
	~Vector();//destructor

private:
	size_t size;
	size_t space{ 0 };
	T* nums;
	const int RESERVE_DEFAULT_SIZE{ 8 };
	const int RESERVE_SIZE_MULTIPLIER{ 2 };
};


#endif // !MY_VECTOR_H
void use_vector();
Vector<int> get_vector();