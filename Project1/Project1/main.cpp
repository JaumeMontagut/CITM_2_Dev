#include <iostream>
#include <math.h>
#include "vec3.h"

void printVec(vec3<float> sentVec)
{
	std::cout << "x: " << sentVec.x << ", y: " << sentVec.y << ", z: " << sentVec.z << "\n";
}

int main()
{
	//TEST
	vec3<float> testVec1;
	vec3<float> testVec2(1,1,1);
	vec3<float> testVec3(1,1,1);
	
	testVec1 = testVec2 + testVec3;

	printVec(testVec2 + testVec3);

	system("pause");
}