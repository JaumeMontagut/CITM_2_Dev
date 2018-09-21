#ifndef VEC_3
#define VEC_3

#include <math.h>

template <class _type>
class vec3
{
public:
	_type x, y, z;

	//CONSTRUCTORS---------------------------------------------------------

	vec3()
	{}

	vec3(const _type &x, const _type &y, const _type &z) :
		x(x),
		y(y),
		z(z){}

	vec3(const vec3 &vecToCpy) :
		x(vecToCpy.x),
		y(vecToCpy.y),
		z(vecToCpy.z){}

	vec3(const vec3 &startPoint, const vec3 &endPoint) :
		x(endPoint.x - startPoint.x),
		y(endPoint.y - startPoint.x),
		z(endPoint.z - startPoint.z) {}

	//OPERATORS-----------------------------------------------------------

	vec3 operator+ (const vec3 &otherVec) const {
		return vec3(x + otherVec.x, y + otherVec.y, z + otherVec.z);
	}

	vec3 operator- (const vec3 &otherVec) const {
		return vec3(x - otherVec.x, y - otherVec.y, z - otherVec.z);
	}

	vec3 operator+= (const vec3 &otherVec) {
		x += otherVec.x;
		y += otherVec.y;
		z += otherVec.z;
		return *this;
	}

	vec3 operator-= (const vec3 &otherVec) {
		x -= otherVec.x;
		y -= otherVec.y;
		z -= otherVec.z;
		return *this;
	}

	vec3 operator= (vec3 otherVec) {
		x = otherVec.x;
		y = otherVec.y;
		z = otherVec.z;
		return *this;
	}

	bool operator== (const vec3 &otherVec) const {
		return (x == otherVec.x && y == otherVec.y && z == otherVec.z);
	}

	//- Extra operators

	vec3 operator/ (const _type &sentNum) const
	{
		return vec3(x/sentNum, y/sentNum, z/sentNum);
	}

	//METHODS----------------------------------------------------------------------------------

	//INFO:
	//- Casting x, y and z to type hides a warning if we used any type other than doubles
	//- A better way to do it would be to use template specializations

	void normalize() {
		float vecModule = sqrt(x*x + y * y + z * z);
		x /= vecModule;
		y /= vecModule;
		z /= vecModule;
	}

	void zero() {
		x = (_type)0;
		y = (_type)0;
		z = (_type)0;
	}

	bool is_zero() const {
		return (x == (_type)0 && y == (_type)0 && z == (_type)0);
	}

	_type distance_to(vec3 &otherVec) const {
		return (_type) sqrt((otherVec.x - x)*(otherVec.x - x) + (otherVec.y - y) * (otherVec.y - y) + (otherVec.z - z) * (otherVec.z - z));
	}

};

#endif
