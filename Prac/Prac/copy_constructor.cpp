#include <iostream>
#include "tag.h"
using namespace std;
typedef struct tagVector3
{
public:
	explicit tagVector3()
		:x(0.f), y(0.f), z(0.f)
	{}
	explicit tagVector3(const float& _x, const float& _y, const float& _z)
		: x(_x), y(_y), z(_z)
	{
		std::cout << "인자있는 생성자 호출" << std::endl;
	}
	explicit tagVector3(const float& num)
		: x(num), y(num), z(num)
	{}
	explicit tagVector3(const tagVector3& vec)
		: x(vec.x), y(vec.y), z(vec.z)
	{
		std::cout << "복사생성자 호출" << std::endl;
	}

	/* ===============================================연산자 오버로딩=============================================== */
	const tagVector3& operator+(const tagVector3& vec)
	{
		return tagVector3(this->x + vec.x, this->y + vec.y, this->z + vec.z);
	}

	const tagVector3& operator+(const tagVector3& vec) const
	{
		return tagVector3(this->x + vec.x, this->y + vec.y, this->z + vec.z);
	}

public:
	float x, y, z;

}_vec3;
int main()
{
	_vec3 temp1(1, 1, 1);
	cout << endl;
	_vec3 temp2(2, 2, 2);
	cout << endl;
	_vec3 temp3(2, 2, 2);
	cout << endl;

	temp3 = temp1 + temp2;

	_vec3 temp4(temp3);

	return 0;
}