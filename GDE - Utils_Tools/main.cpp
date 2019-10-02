/*
 * Author: Roderick "R.J." Montague (100701758)
 * Date: 05/01/2019
 * Description: a project that contains various utility functions
*/

// #include "Utils.h"
// #include "math/Vector.h"
// #include "Array.h"

#include "UtilsToolsLib.h"
#include <iostream>

#include <random>
#include <ctime>

using namespace util;
using namespace util::math;

int main()
{
	srand(time(0));
	std::cout << "PI: " << pi() << std::endl;
	std::cout << "PI (Double): " << pid() << std::endl;
	std::cout << "PI (Float): " << pif() << std::endl;
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

	std::cout << "\nLERP: " << util::math::Vec2::LERP(lvec1, lvec2, 0.75F).toString() << std::endl;

	std::cout << std::endl;

	std::cout << rand() << std::endl;

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