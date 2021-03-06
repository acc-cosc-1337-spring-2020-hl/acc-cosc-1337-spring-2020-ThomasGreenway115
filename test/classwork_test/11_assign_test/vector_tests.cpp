#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "vector.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test class copy w stack variables")
{
	Vector<int> v1(5);
	Vector<int> v2 = v1;
	v1[2] = 0;
	REQUIRE(v1.Size() == v2.Size());

}
TEST_CASE("Test class copy w heap variables")
{
	Vector<int> v1(3);
	Vector<int> v2 = v1;

	REQUIRE(v1.Size() == v2.Size());
	
	v1[1] = 5;
	REQUIRE(v1[1] != v2[1]);
}

TEST_CASE("Test class copy w 2 instances of vector")
{
	Vector<double> v1(3);
	Vector<double> v2(3);
	v2 = v1;
	v1[1] = 1;

	REQUIRE(v1[1] != v2[1]);
	REQUIRE(v1[1] == 1);
	REQUIRE(v1[1] == 0);
}
TEST_CASE("Test vector capacity with reserve function call")
{
	Vector<int> v(3);
	REQUIRE(v.Capacity() == 3);
	v.Reserve(6);
	REQUIRE(v.Capacity() == 6);
}
TEST_CASE("Test vector resize value copied and initialized")
{
	Vector<int> v(3);
	v[1] = 1;
	v.Resize(6);
	REQUIRE(v[0] == 1);
	REQUIRE(v[1] == 2);
	REQUIRE(v[2] == 3);
	REQUIRE(v[3] == 0);
	REQUIRE(v[4] == 0);
	REQUIRE(v[5] == 0);
	
}

TEST_CASE("Test vector pushback with our default constructor")
{
	Vector <double> v;
	v.Push_Back(5);

	REQUIRE(v.Capacity() == 8);
	REQUIRE(v[0] == 5);

}
