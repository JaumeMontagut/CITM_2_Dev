#include <iostream>
#include <math.h>
#include "vec3.h"

int main()
{
	//NORMAL ADDITION
	vec3<float> vecA (1,1,1);
	vec3<float> vecB (2,2,2);
	vec3<float> vecC (1,1,1);

	vecC = vecA + vecB;

	vecC.printCoordinates();

	//ADDITION WHEN DECLARING
	//vec3<float> vecA (1,1,1);
	//vec3<float> vecB (2,2,2);
	//vec3<float> vecC (vecA + vecB);
	//vecC.printCoordinates();

	system("pause");
}