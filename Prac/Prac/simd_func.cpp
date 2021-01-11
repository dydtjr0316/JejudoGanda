#include <iostream>
#include <emmintrin.h>
#include <windows.h>
#include<xmmintrin.h>
#include<iostream>
#include <time.h>
#include <windows.h>
#include <math.h>
#include <cmath>
#include <time.h>
#include <chrono>
#include <d3d12.h>
#include <dxgi1_4.h>
#include <D3Dcompiler.h>
#include <DirectXMath.h>
#include <DirectXPackedVector.h>

using namespace DirectX;

XMFLOAT3 xmv1 = XMFLOAT3(1.f, 2.f, 3.f);
XMFLOAT3 xmv2 = XMFLOAT3(8.f, 1.f, 7.f);

using namespace std;

const int n = 100000;

__m128 a, b, r;

__declspec(align(16)) float v1[4] = { 1,2,3,4 };

__declspec(align(16)) float v2[4] = { 8,1,7,2 };

__declspec(align(16)) float result[4];


float zv1[4] = { 1,2,3,4 };

float zv2[4] = { 8,1,7,2 };

float zresult[4];
//double inline __declspec (naked) __fastcall sqrt14(double n)
//{
//	_asm fld qword ptr[esp + 4]
//		_asm fsqrt
//	_asm ret 8
//}
float sqrt13(float n)
{
	__asm {
		fld n
		fsqrt
	}
}
void SIMD_POW()
{
	float* arrk;
	__m128* pppp = (__m128*)v1;
	__m128* aaaa = (__m128*)v2;
	__m128 res;
	__m128 mul_res;

	res = _mm_add_ps(*pppp, *aaaa);
	mul_res = _mm_mul_ps(res, res);
	arrk = reinterpret_cast<float*>(&mul_res);

	cout << arrk[0] + arrk[1] + arrk[2] + arrk[3] << endl;
}
void SIMD_SQRT()
{
	float* arrk;
	__m128* pppp = (__m128*)v1;
	__m128* aaaa = (__m128*)v2;
	__m128 res;
	__m128 mul_res;

	res = _mm_add_ps(*pppp, *aaaa);
	mul_res = _mm_mul_ps(res, res);
	arrk = reinterpret_cast<float*>(&mul_res);

	cout << arrk[0] + arrk[1] + arrk[2] + arrk[3] << endl;
}
int main()
{
	std::chrono::system_clock::time_point start;
	std::chrono::system_clock::time_point EndPoint;
	std::chrono::nanoseconds nano;
	start = std::chrono::system_clock::now();
	for (float i = 0.f; i < n; ++i) {
		sqrt13(i);
	}
	EndPoint = std::chrono::system_clock::now();
	nano = (EndPoint - start);
	cout << nano.count() << endl;
	
	///////////////////////////////////////////////

	start = std::chrono::system_clock::now();
	for (float i = 0.f; i < n; ++i) {
		sqrtf(i);
	}
	EndPoint = std::chrono::system_clock::now();
	nano = (EndPoint - start);
	cout << nano.count() << endl;
	return 0;
}
