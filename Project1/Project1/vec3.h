#ifndef VEC_3
#define VEC_3

template <class unit>
class vec3
{
public:
	unit x, y, z;

public:

#pragma region Constructors

	vec3() {
		x = 0;
		y = 0;
		z = 0;
	}

	vec3(unit x, unit y, unit z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	vec3(vec3 &startPoint, vec3 &endPoint) {
		x = endPoint.x - startPoint.x;
		y = endPoint.y - startPoint.y;
		z = endPoint.z - startPoint.z;
	}

#pragma endregion

#pragma region Operators

	vec3<unit> operator+ (vec3 &otherVec) {
		vec3 returnVec;
		returnVec.x = x + otherVec.x;
		returnVec.y = y + otherVec.y;
		returnVec.z = z + otherVec.z;
		return returnVec;
	}

	vec3<unit> operator- (vec3 &otherVec) {
		vec3 returnVec;
		returnVec.x = x - otherVec.x;
		returnVec.y = y - otherVec.y;
		returnVec.z = z - otherVec.z;
		return returnVec;
	}

	void operator+= (vec3 &otherVec) {
		x = x + otherVec.x;
		y = y + otherVec.y;
		z = z + otherVec.z;
	}

	void operator-= (vec3 &otherVec) {
		x = x - otherVec.x;
		y = y - otherVec.y;
		z = z - otherVec.z;
	}

	void operator= (vec3 otherVec) {
		x = otherVec.x;
		y = otherVec.y;
		z = otherVec.z;
	}

	bool operator== (vec3 &otherVec) const {
		return (x == otherVec.x && y == otherVec.y && z == otherVec.z);
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
		return sqrt(pow(otherVec.x - x) + pow(otherVec.y - y) + pow(otherVec.z - z));
	}

	//ADDITIONAL METHODS
	void printCoordinates() {
		std::cout << "x: " << x << ", y: " << y << ", z: " << z << "\n";
	}

#pragma endregion

};

#endif
