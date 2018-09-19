#include <iostream>
#include <math.h>
#include "vec3.h"

int main()
{
	vec3<float> vecA(1,1,1);
	vec3<float> vecB;
	vec3<float> vecC;

	vecC = vecB = vecA;

	vecC.printCoordinates();

	system("pause");
}