/*
 * Author: Roderick "R.J." Montague (100701758)
 * Date: 05/01/2019
 * Description: a project that contains various utility functions
*/

// #include "Utils.h"
// #include "math/Vector.h"
// #include "Array.h"

#include "utils/UtilsToolsLib.h"
#include <iostream>

#include <random>
#include <ctime>

// print vector and print array
template<typename T, typename A>
void printVector(const std::vector<T, A>);
template<typename T>
void printArray(const T* arr, const unsigned int SIZE);

// randomization test
void randomTest();

// sort test
void sortTest();

// prints out a vector
template<typename T, typename A>
void printVector(const std::vector<T, A> vector)
{
	for (int i = 0; i < vector.size(); i++)
	{
		std::cout << vector[i];

		if (i + 1 < vector.size())
			std::cout << ", ";
	}
}

// does a randomization test
void randomTest()
{
	std::cout << "\nRandom Test\n***********" << std::endl;

	// integer tests
	{
		// temporary lower bound and upper bound
		int l = 0, u = 1;
		// include upper bound
		bool incU = true;
		
		// [0, 1] - include upper bound.
		l = 0;
		u = 1;
		incU = true;
		std::cout << "randInt(" << l << ", " << u << ", " << std::boolalpha << incU << ") = "
			<< util::rand::randInt(l, u, incU) << std::endl;

		// [-2,-1] - include upper bound.
		l = -2;
		l = -1;
		incU = true;
		std::cout << "randInt(" << l << ", " << u << ", " << std::boolalpha << incU << ") = "
			<< util::rand::randInt(l, u, incU) << std::endl;

		// [-, -] - both bounds are negative; upper bound is not included.
		l = -30;
		u = -5;
		incU = false;
		std::cout << "randInt(" << l << ", " << u << ", " << std::boolalpha << incU << ") = "
			<< util::rand::randInt(l, u, incU) << std::endl;

		// [-,+] - negative to positive; upper bound is not included.
		l = -50;
		u = 100;
		incU = false;

		std::cout << "randInt(" << l << ", " << u << ", " << std::boolalpha << incU << ") = "
			<< util::rand::randInt(l, u, incU) << std::endl;
	}

	std::cout << std::endl;

	// decimal tests
	{
		// temporary lower bound and upper bound
		double l = 0, u = 1;
		// include upper bound
		bool incU = true;

		// standard test; TODO: make function that provides additional decimal values.

		// decimal test (both have 4 places)
		l = 1.23;
		u = 2.91;
		incU = true;
		std::cout << "randDecimal(" << l << ", " << u << ", " << std::boolalpha << incU << ") = "
			<< util::rand::randDecimal(l, u, incU) << std::endl;

		// 
	}
}

// prints out a dynamic array.
template<typename T>
void printArray(const T* arr, const unsigned int SIZE)
{
	// pritns out all values from the list
	for (int i = 0; i < SIZE; i++)
	{
		std::cout << arr[i];

		if (i + 1 < SIZE)
			std::cout << ", ";
	}
}

// sort tester function
void sortTest()
{
	const int SIZE = 10;

	// the first list, which is a int vector.
	int list1[SIZE]{ 1, 7, 2, -1, 4, 3, 3, 9, 5, 10 };

	// the third list, which is a dynamic double array.
	double* list2 = new double[SIZE];

	for (int i = 0; i < SIZE; i++)
		list2[i] = SIZE - i;

	// the second list, which is a static float array.
	std::vector<float> list3;
	
	list3.push_back(1.24F);
	list3.push_back(3.64F);
	list3.push_back(1.13F);
	list3.push_back(5.55F);
	list3.push_back(2.14F);
	list3.push_back(2.14F);
	list3.push_back(0.144F);
	list3.push_back(0.943F);
	list3.push_back(11.02F);
	list3.push_back(14.0F);
		
	list3.resize(SIZE);


	// bubble sort
	{
		util::time::Timer t1, t2, t3;

		std::cout << "\nBefore Sort:" << std::endl;

		// printing the values before the sort.
		std::cout << "\nList1:";
		printArray<int>(list1, SIZE);
		
		std::cout << "\nList2: ";
		printArray<double>(list2, SIZE);

		std::cout << "\nList3: ";
		printVector(list3);
		
		std::cout << "\n\n";

		// runs sorting algorithms and times them.
		t1.start();
		util::sort::bubbleSort<int>(list1, SIZE);
		t1.stop();

		t2.start();
		util::sort::bubbleSort<double>(list2, SIZE);
		t2.stop();

		t3.start();
		util::sort::bubbleSort<float>(list3);
		t3.stop();

		std::cout << "\After Sort:" << std::endl;

		// printing the values after the sort.
		std::cout << "\nList1:";
		printArray<int>(list1, SIZE);
		std::cout << "\nTime (Milliseconds): " << t1.getDurationInMilliseconds() << std::endl;

		std::cout << "\nList2: ";
		printArray<double>(list2, SIZE);
		std::cout << "\nTime (Milliseconds): " << t2.getDurationInMilliseconds() << std::endl;

		std::cout << "\nList3: ";
		printVector(list3);
		std::cout << "\nTime (Milliseconds): " << t3.getDurationInMilliseconds() << std::endl;
	}

	std::cout << std::endl;
	delete[] list2;
}

int main()
{
	double dx = 1.242;
	float fx = 1.242F;
	std::cout << "Double: " << std::to_string(dx) << std::endl;
	std::cout << "Float: " << std::to_string(fx) << std::endl;

	// seeds the randomizer
	srand(time(0));

	using namespace util;
	using namespace util::math;

	randomTest();

	sortTest();

	system("pause");

	if (true)
	{
		Box3D x;
		x.position = Vec3(10, 5, 0);
		x.width = 30;
		x.height = 30;
		x.depth = 30;
		x.rotation = { 13, 2, -3 };

		x.rotationOrder[0] = 'x';
		x.rotationOrder[1] = 'y';
		x.rotationOrder[2] = 'z';

		Box3D y;
		y.position = Vec3(0.5, 4, 1);
		y.width = 35;
		y.height = 23;
		y.depth = 23;

		y.rotation = { 10, 1, -15 };
		y.rotationOrder[0] = 'z';
		y.rotationOrder[1] = 'x';
		y.rotationOrder[2] = 'y';

		std::cout << std::boolalpha << obbCollision(x, true, y, true) << std::endl;
	}
	std::vector<int*> testVector;
	int* tv1 = new int(4);
	testVector.push_back(new int(5));
	testVector.push_back(new int(2));
	testVector.push_back(new int(1));
	util::addToVector(testVector, tv1);
	util::addToVector(testVector, tv1);
	util::removeFromVector(testVector, tv1);

	
	std::cout << "PI: " << pi() << std::endl;
	std::cout << "PI (Double): " << pid() << std::endl;
	std::cout << "PI (Float): " << pif() << std::endl;
	std::cout << std::endl;

	std::string sti = "123";
	std::string std = "124.54";
	std::cout << "String '" + sti + "' to Int: " << convertString<int>(sti) << std::endl;
	std::cout << "String '" + std + "' to Double: " << convertString<double>(std) << std::endl;
	std::cout << "String '" + std + "' to Float: " << convertString<float>(std) << std::endl;

	std::cout << std::endl;

	util::math::Vec4 clrVec(12.0F, 252.0F, 129.0F, 9.0F);
	std::cout << "RGBA Int to Decimal (12, 252, 129, 9.0F) (alpha out of bounds): " << util::RGBAIntToDecimal(clrVec.x, clrVec.y, clrVec.z, clrVec.w).toString() << std::endl;
	clrVec = util::RGBAIntToDecimal(clrVec.x, clrVec.y, clrVec.z, clrVec.w);
	std::cout << "Converting it back: " << util::RGBADecimalToInt(clrVec).toString() << std::endl;
	std::cout << "RGBA Decimal to Int (0.5, 0.25, 1.9, 0.2F) (b out of bounds): " << util::RGBADecimalToInt(0.5F, 0.25F, 1.9F, 0.2F).toString() << std::endl;

	std::cout << std::endl;
	// STRING REPLACEMENT
	// Test 1
	std::string str_r1 = "How much wood would a woodchuck chuck if a woodchuck could chuck wood?";
	std::string str_r2 = "ice";
	std::cout << "Sentence: " + str_r1 << std::endl;
	std::cout << "Replacing \"wood\" with \"" + str_r2 + "\"." << std::endl;
	std::cout << "Result: " << util::replaceSubstring(str_r1, "wood", str_r2) << std::endl; // util::repl

	std::cout << std::endl;
	// Test 2
	str_r1 = "Hello! hello! Hello! hello! HELLO! HellO! hello! heLLO!";
	str_r2 = "Hey";
	std::cout << "Sentence: " + str_r1 << std::endl;
	std::cout << "Replacing \"hello\" (case sensitive) with \"" + str_r2 + "\"." << std::endl;
	std::cout << "Result: " << util::replaceSubstring(str_r1, "hello", str_r2) << std::endl; // util::repl

	// Test 3
	std::cout << "\nReplacing every instance of hello with" << str_r2 << ", regardless of the case (i.e. it's case insensitive)." << std::endl;
	std::cout << "Result: " << util::replaceSubstring(str_r1, "hello", str_r2, true) << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;
	util::math::Vec2 lvec1 = util::math::Vec2(2.0F, 8.0F);
	util::math::Vec2 lvec2 = util::math::Vec2(6.0F, 10.0F);

	std::cout << "lvec1: " << lvec1.toString() << std::endl;
	std::cout << "lvec2: " << lvec2.toString() << std::endl;
	std::cout << "t: 3/4" << std::endl;

	std::cout << "\nLERP: " << util::math::lerp(lvec1, lvec2, 0.75F).toString() << std::endl;
	std::cout << "lvec1 dotLength lvec2: " << lvec1.dotLength(lvec2, true) << std::endl;
	std::cout << "lvec1 dotAngle lvec2: " << lvec1.dotAngle(lvec2) << std::endl;
	std::cout << std::endl;

	std::cout << std::rand() << std::endl;

	util::math::Vec3 vec(3, 4, 0);
	// vec.normalize();

	// util::Mat2 x;
	// std::cout << x << std::endl;

	// std::cout << vec << std::endl;
	// std::cout << vec[1] << std::endl;

	util::math::Vec3 tempVec = util::math::rotateZ(vec, 20.0f, true);
	util::math::Vec2 tempVec2 = util::math::rotate(util::math::Vec2(vec.x, vec.y), 20.0F, true);

	if (tempVec.x == tempVec2.x && tempVec.y == tempVec2.y)
		std::cout << "success!" << std::endl;

	// std::cout << std::to_string(std::numeric_limits<float>::max()) << std::endl;
	// std::cout << std::to_string(std::numeric_limits<double>::max()) << std::endl;
	
	util::math::Mat2 m1(1, 3, 5, 6);
	util::math::Mat2 m2(3, 4, 9, 1);
	util::math::Mat2 m3 = m1;

	m3 += m2;

	std::cout << m3 << std::endl;

	util::math::Mat4 m4(3, 4, 1, 2, 5, 6, 7, 1, 3, 5, 5, 6, 1, 23, 4, 5);

	std::cout << m4.getDeterminant() << std::endl;

	std::cout << std::endl;

	util::math::Mat3 m5(1, 2, 3, 4, 5, 6, 7, 8, 9);
	std::cout << m5.getMinor(1, 0) << std::endl;

	std::cout << std::endl;

	util::math::Vec2 v1(5, 7);
	util::math::Vec2 v2(9, 0);


	// std::cout << util::Vec2(5, 7).dotLength(util::Vec2(9, 0), false) << std::endl;
	std::cout << acosf(v1.dot(v2) / (v1.length() * v2.length())) << std::endl;
	std::cout << v1.dotAngle(v2, false) << std::endl;

	std::cout << util::math::pi() << std::endl;


	util::math::Vec3 v3(1, 5, 2); // 90 degrees around the y-axis should return (-5, 1, 0)
	std::cout << "V3: (" << v3[0] << ", " << v3[1] << ", " << v3[2] << ") " << std::endl;
	util::math::Vec3 v4;
	util::math::Vec3 v5;

	// v4 = util::rotateZ(v3, 45, true);
	// v5 = util::rotateQuat(v3, 45, 'z', true);
	v4 = util::math::rotate(v3, 90.0F, 'y', true);
	v5 = util::math::rotateQuat(v3, 90.0F, 'y', true);

	std::cout << "R-M: " << v4 << std::endl;
	std::cout << "R-Q: " << v5 << std::endl;
	std::cout << "Rotation Test: " << std::boolalpha << (v4 == v5) << std::endl; // rounded they are the same. Without, there are slight decimal point differences.

	// std::cout << util::Vec3(1.0F, 0.0F, 0.0F).getNormalized() << std::endl;
	// v1.normalize();

	std::cout << std::endl;
	util::math::Vec4 v6;
	// std::cin >> v6;

	std::cout << v6 << std::endl;
	std::cout << std::endl;
	std::cout << "Quaternion Test" << std::endl;

	util::math::Quat quat(32, 42, 91, -13);
	std::cout << "Q Ostream: " << quat << std::endl;
	std::cout << "Q ToString: " << quat.toString() << std::endl;
	std::cout << "Manual: (" << quat[0] << ", " << quat[1] << ", " << quat[2] << ", " << quat[3] << ") " << std::endl;

	std::cout << "\nQuaternion Input" << std::endl;
	util::math::Quat q2;
	std::cin >> q2;
	std::cout << q2 << std::endl;

	std::cout << "Matrix input" << std::endl;
	util::math::Mat4 m6;
	std::cin >> m6;
	std::cout << m6 << std::endl;

//	// http://www.cplusplus.com/reference/limits/numeric_limits/
//// std::cout << std::numeric_limits<float>::max() << std::endl;
//// std::cout << std::to_string(std::numeric_limits<float>::min()) << std::endl;
//// std::cout << std::to_string(std::numeric_limits<float>::max()) << std::endl;
//
//	std::string str = "12345.0 test";
//	std::cout << "Is '" << str << "' an int? " << std::boolalpha << ustd::isInt(str) << std::endl;
//	std::cout << "Is '" << str.substr(0, 7) << "' an int? " << std::boolalpha << ustd::isInt(str.substr(0, 5)) << std::endl;
//
//	std::cout << "Is '" << str << "' a decimal? " << std::boolalpha << ustd::isInt(str) << std::endl;
//	std::cout << "Is '" << str.substr(0, 7) << "' a decimal? " << std::boolalpha << ustd::isInt(str.substr(0, 5)) << std::endl;
//
//	std::cout << std::endl;
//	// std::cout << std::to_string(util::Utils::randFloat()) << std::endl;
//
//	Quat q1 = Quat(2.0F, 3.5F, 4.2F, -9.4F);
//	Quat q2 = Quat(3.0F, -2.1F, 9.1F, 5.4F);
//
//	// std::cout << (q1 * q2).to_string() << std::endl;
//
//
//	float theta = 90;
//	float pi = 3.14159265359;
//
//	Quat q3 = Quat(cos(theta / 2 * (pi / 180)), Vec3(0, 0, 1) * sin(theta / 2 * (pi / 180)));
//	// Quat q3 = Quat(cos(0.785398), Vec3(0, 0, 1) * sin(0.785398));
//	Quat q4 = Quat(0, 1, 5, 2);
//
//	std::cout << (q3 * q4).to_string() << std::endl;
//
//	/*std::cout << std::endl;
//	std::cout << "AABB: " << std::boolalpha << Collisions::aabbCollision(Vec3(1.0F, 1.0F, 1.0F), Vec3(9.0F, 9.0F, 9.0F), Vec3(6.0F, 6.0F, 6.0F), Vec3(13.0F, 13.0F, 13.0F)) << std::endl;
//
//	std::cout << "OBB (angle of 0 for both) ~ inherently intersect: " << std::boolalpha << Collisions::obbCollision(
//		Vec2(4.0F, 4.0F), Vec2(10.0F, 4.0F), Vec2(4.0F, -2.0F), Vec2(10.0F, -2.0F), 0.0F,
//		Vec2(12.0F, 5.0F), Vec2(15.0F, 5.0F), Vec2(12.0F, 1.0F), Vec2(15.0F, 1.0F), 0.0F
//	) << std::endl;
//
//	std::cout << "OBB (angle of 0 for both) ~ inherently don't intersect: " << std::boolalpha << Collisions::obbCollision(
//		Vec2(4.0F, 4.0F), Vec2(10.0F, 4.0F), Vec2(4.0F, -2.0F), Vec2(10.0F, -2.0F), 0.0F,
//		Vec2(20.0F, 4.0F), Vec2(40.0F, 4.0F), Vec2(20.0F, -10.0F), Vec2(40.0F, -10.0F), 0.0F
//	) << std::endl;
//
//	std::cout << "OBB (thetaA = 40 degrees, thetaB = 0) ~ inherently intersect, and should return true: " << std::boolalpha << Collisions::obbCollision(
//		Vec2(4.0F, 4.0F), Vec2(10.0F, 4.0F), Vec2(4.0F, -2.0F), Vec2(10.0F, -2.0F), umath::degreesToRadians(40.0F),
//		Vec2(5.0F, 5.0F), Vec2(11.0F, 5.0F), Vec2(5.0F, -1.0F), Vec2(11.0F, -1.0F), umath::degreesToRadians(0.0F)
//	) << std::endl;
//
//	std::cout << "OBB (thetaA = 190 degrees, thetaB = -20 degrees) ~ interently intersect, and should return true: " << std::boolalpha << Collisions::obbCollision(
//		Vec2(4.0F, 4.0F), Vec2(10.0F, 4.0F), Vec2(4.0F, -2.0F), Vec2(10.0F, -2.0F), umath::degreesToRadians(190.0F),
//		Vec2(5.0F, 5.0F), Vec2(11.0F, 5.0F), Vec2(5.0F, -1.0F), Vec2(11.0F, -1.0F), umath::degreesToRadians(-20.0F)
//	) << std::endl;
//
//
//	std::cout << "OBB (thetaA = 0 degrees, thetaB = 0 degrees) ~ interently doesn't intersect unrotated: " << std::boolalpha << Collisions::obbCollision(
//		Vec2(4.0F, 4.0F), Vec2(10.0F, 4.0F), Vec2(4.0F, -2.0F), Vec2(10.0F, -2.0F), umath::degreesToRadians(0.0F),
//		Vec2(11.0F, 5.0F), Vec2(17.0F, 5.0F), Vec2(11.0F, -1.0F), Vec2(17.0F, -1.0F), umath::degreesToRadians(0.0F)
//	) << std::endl;
//*/
//	std::cout << "OBB (thetaA = 5 degrees, thetaB = -50 degrees) ~ only interesects rotated: " << std::boolalpha << umath::obbCollision(
//		Vec2(4.0F, 4.0F), Vec2(10.0F, 4.0F), Vec2(4.0F, -2.0F), Vec2(10.0F, -2.0F), umath::degreesToRadians(5.0F),
//		Vec2(11.0F, 5.0F), Vec2(17.0F, 5.0F), Vec2(11.0F, -1.0F), Vec2(17.0F, -1.0F), umath::degreesToRadians(-50.0F)
//	) << std::endl;
//
//	// version of the recent check where the rotations have already happened.
//	Vec2 posA{ 7, 1 };
//	Vec2 posB{ 14, 2 };
//	float rfA = umath::degreesToRadians(5.0F);
//	float rfB = umath::degreesToRadians(-50.0F);
//	std::cout << "OBB (thetaA = 5 degrees, thetaB = -50 degrees) ~ already rotated before calling function: " << std::boolalpha << umath::obbCollision(
//		umath::rotate(Vec2(4.0F, 4.0F) - posA, rfA) + posA, umath::rotate(Vec2(10.0F, 4.0F) - posA, rfA) + posA, umath::rotate(Vec2(4.0F, -2.0F) - posA, rfA) + posA, umath::rotate(Vec2(10.0F, -2.0F) - posA, rfA) + posA, rfA,
//		umath::rotate(Vec2(11.0F, 5.0F) - posB, rfB) + posB, umath::rotate(Vec2(17.0F, 5.0F) - posB, rfB) + posB, umath::rotate(Vec2(11.0F, -1.0F) - posB, rfB) + posB, umath::rotate(Vec2(17.0F, -1.0F) - posB, rfB) + posB, rfB,
//		true) << std::endl;
//
//	// Circle-Line Test
//	std::cout << "Circle-Line (should return true): " << umath::circleLineCollision(Vec2(0.0F, 0.0F), 3.0F, Vec2(-6.0F, -4.0F), Vec2(2.0F, 8.0F)) << std::endl;
//	std::cout << "Circle-Line (should return true): " << umath::circleLineCollision(Vec2(0.0F, 10.0F), 4.0F, Vec2(-6.0F, -3.0F), Vec2(2.0F, 9.0F)) << std::endl;
//	std::cout << "Circle-Line (should return false): " << umath::circleLineCollision(Vec2(0.0F, 0.0F), 3.0F, Vec2(0.0F, 6.0F), Vec2(6.0F, 0.0F)) << std::endl;
//	std::cout << "Circle-Line (should return false): " << umath::circleLineCollision(Vec2(0.5F, 0.5F), 3.0F, Vec2(6.0F, 0.0F), Vec2(0.0F, 6.0F)) << std::endl;
//
//	// Quat qr1 = Quat(cos(theta / 2), Vec3(1, 5, 2) * sin(theta / 2));

	system("pause");
	return 0;
}