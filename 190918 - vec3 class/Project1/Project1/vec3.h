#ifndef VEC_3
#define VEC_3

template <class type>
class vec3
{
public:
	type x, y, z;

	//CONSTRUCTORS---------------------------------------------------------

	vec3()
	{}

	vec3(const type &x, const type &y, const type &z) :
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

	vec3 operator/ (const type &sentNum) const
	{
		return vec3(x/sentNum, y/sentNum, z/sentNum);
	}

	//METHODS----------------------------------------------------------------------------------

	//INFO:
	//- Casting x, y and z to type hides a warning if we used any type other than doubles
	//- A better way to do it would be to use template specializations

	void normalize() {
		*this = *this / (type) sqrt(x*x + y*y + z*z);
	}

	void zero() {
		x = (type)0;
		y = (type)0;
		z = (type)0;
	}

	bool is_zero() const {
		return (x == (type)0 && y == (type)0 && z == (type)0);
	}

	float distance_to(vec3 &sentVec) const {
		return (type) sqrt((sentVec.x - x)*(sentVec.x - x) + (sentVec.y - y) * (sentVec.y - y) + (sentVec.z - z) * (sentVec.z - z));
	}

	//- Additional methods

	void printCoordinates() {
		std::cout << "x: " << x << ", y: " << y << ", z: " << z << "\n";
	}

};

#endif
