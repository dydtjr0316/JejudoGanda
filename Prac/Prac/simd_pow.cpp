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

using namespace std;

const int n = 1;

__m128 a, b, r;

__declspec(align(16)) float v1[3] = { 1,2,3};

__declspec(align(16)) float v2[3] = { 8,1,7};


XMFLOAT3 zv1 = XMFLOAT3(1.0f, 2.0f, 3.0f);
XMFLOAT3 zv2 = XMFLOAT3(8.0f, 1.0f, 7.0f);

float zv1[4] = { 1,2,3,4 };

float zv2[4] = { 8,1,7,2 };

float zresult[4];
int main()
{
	
	float k;
	float* arrk;
	__m128* pppp = (__m128*)v1;
	__m128* aaaa = (__m128*)v2;
	__m128 res;
	__m128 mul_res;
	std::chrono::system_clock::time_point start;
	std::chrono::system_clock::time_point EndPoint;
	std::chrono::nanoseconds nano;

	//
	start = std::chrono::system_clock::now();
	for (int i = 0; i < n; ++i) {

		
		res = _mm_add_ps(*pppp, *aaaa);
		mul_res = _mm_mul_ps(res, res);
		arrk = reinterpret_cast<float*>(&mul_res);
		
		cout << arrk[0] + arrk[1] + arrk[2]  << endl;
		/*_mm_store_ps(result, mul_res);
		k = result[0] + result[1] + result[2] + result[3];*/
	}
	//cout << k << endl;

	EndPoint = std::chrono::system_clock::now();
	nano = (EndPoint - start);

	cout << nano.count() << endl;

	//
	start = std::chrono::system_clock::now();		//k = powf(zv1[0] + zv2[0], 2) + powf(zv1[1] + zv2[1], 2) + powf(zv1[2] + zv2[2], 2) + powf(zv1[3] + zv2[3], 2);

	for (int i = 0; i < n; ++i) {
		/*k = (zv1[0] + zv2[0]) * (zv1[0] + zv2[0]);
		k += (zv1[1] + zv2[1]) * (zv1[1] + zv2[1]);
		k += (zv1[2] + zv2[2]) * (zv1[2] + zv2[2]);
		k += (zv1[3] + zv2[3]) * (zv1[3] + zv2[3]);*/
		

	}
	EndPoint = std::chrono::system_clock::now();
	nano = (EndPoint - start);
	cout << k << endl;

	cout << nano.count() << endl;
	{
		//EndPoint = std::chrono::system_clock::now();
		//nano = (EndPoint - start);
		//cout << nano.count() << endl;
		////

		////
		//start = std::chrono::system_clock::now();
		//for (int i = 0; i < 1000000000; ++i) {
		//	k = powf(zv1[0] + zv2[0], 2) + powf(zv1[1] + zv2[1], 2)
		//		+ powf(zv1[2] + zv2[2], 2) + powf(zv1[3] + zv2[3], 2);
		//}


		//EndPoint = std::chrono::system_clock::now();
		//nano = (EndPoint - start);
		//cout << nano.count() << endl;
		//cout << endl;
		//cout << endl;
	}

	return 0;
}
