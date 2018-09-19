#ifndef VEC_3
#define VEC_3

template <class type>
class vec3
{
public:
	type x, y, z;

#pragma region Constructors

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

#pragma endregion

#pragma region Operators

	vec3 operator+ (const vec3 &sentVec) const {
		return vec3(x + sentVec.x, y + sentVec.y, z + sentVec.z);
	}

	vec3 operator- (const vec3 &sentVec) const {
		return vec3(x - sentVec.x, y - sentVec.y, z - sentVec.z);
	}

	vec3 operator+= (const vec3 &sentVec) {
		x += sentVec.x;
		y += sentVec.y;
		z += sentVec.z;
		return *this;
	}

	vec3 operator-= (const vec3 &otherVec) {
		x -= otherVec.x;
		y -= otherVec.y;
		z -= otherVec.z;
		return *this;
	}

	vec3 operator= (vec3 sentVec) {
		x = sentVec.x;
		y = sentVec.y;
		z = sentVec.z;
		return *this;
	}

	bool operator== (const vec3 &sentVec) const {
		return (x == sentVec.x && y == sentVec.y && z == sentVec.z);
	}

#pragma endregion

#pragma region Methods

	void normalize() {
		float module;
		module = sqrt( pow(x, 2) + pow(y, 2) + pow(z, 2) );
		x = x / module;
		y = y / module;
		z = z / module;
	}

	void zero() {
		x = 0;
		y = 0;
		z = 0;
	}

	bool is_zero() const {
		return (x == 0 && y == 0 && z == 0);
	}

	float distance_to(vec3 &otherVec) const {
		return sqrt( pow(otherVec.x - x, 2) + pow(otherVec.y - y, 2) + pow(otherVec.z - z, 2));
	}

	//ADDITIONAL METHODS
	void printCoordinates() {
		std::cout << "x: " << x << ", y: " << y << ", z: " << z << "\n";
	}

#pragma endregion

};

#endif
