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
	size_t Size()const { return size; }
	int& operator[](int i) { return nums[i]; }
	int& operator[](int i) const { return nums[i]; }
	~Vector();//destructor
private:
	size_t size;
	int* nums;
};


#endif // !MY_VECTOR_H
void use_vector();
Vector get_vector();