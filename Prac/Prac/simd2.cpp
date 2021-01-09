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

using namespace std;

const int n = 1000000000;

__m128 a, b, r;

__declspec(align(16)) float v1[10] = { 1,2,3,4,7,8,2,6,1,2 };

__declspec(align(16)) float v2[10] = { 8,1,7,2, 1,2,3,4,7,8 };

__declspec(align(16)) float result[10];


float zv1[10] = { 1,2,3,4,7,8,2,6,1,2 };

float zv2[10] = { 8,1,7,2, 1,2,3,4,7,8 };

float zresult[10];
int main()
{
	for (int i = 0; i < 10; ++i) {
		float k;

		__m128 pppp;
		__m128 aaaa;
		__m128 res;
		__m128 mul_res;
		std::chrono::system_clock::time_point start;
		std::chrono::system_clock::time_point EndPoint;
		std::chrono::nanoseconds nano;

		//
		start = std::chrono::system_clock::now();
		pppp = _mm_load_ps(v1);
		aaaa = _mm_load_ps(v2);
		res = _mm_add_ps(pppp, aaaa);
		mul_res = _mm_mul_ps(res, res);

		_mm_store_ps(result, res);
		k = result[0] + result[1] + result[2] + result[3] +
			result[4] + result[5] + result[6] + result[7] + result[8] + result[9];

		EndPoint = std::chrono::system_clock::now();
		nano = (EndPoint - start);

		cout << nano.count() << endl;

		//
		start = std::chrono::system_clock::now();		//k = powf(zv1[0] + zv2[0], 2) + powf(zv1[1] + zv2[1], 2) + powf(zv1[2] + zv2[2], 2) + powf(zv1[3] + zv2[3], 2);
		k = (zv1[0] + zv2[0]) * (zv1[0] + zv2[0]);
		k += (zv1[1] + zv2[1]) * (zv1[1] + zv2[1]);
		k += (zv1[2] + zv2[2]) * (zv1[2] + zv2[2]);
		k += (zv1[3] + zv2[3]) * (zv1[3] + zv2[3]);
		k += (zv1[3] + zv2[4]) * (zv1[4] + zv2[4]);
		k += (zv1[3] + zv2[5]) * (zv1[5] + zv2[5]);
		k += (zv1[3] + zv2[6]) * (zv1[6] + zv2[6]);
		k += (zv1[3] + zv2[7]) * (zv1[7] + zv2[7]);
		k += (zv1[3] + zv2[8]) * (zv1[8] + zv2[8]);
		k += (zv1[3] + zv2[9]) * (zv1[9] + zv2[9]);

		EndPoint = std::chrono::system_clock::now();
		nano = (EndPoint - start);
		cout << nano.count() << endl;
		//

		//
		start = std::chrono::system_clock::now();	k = powf(zv1[0] + zv2[0], 2) + powf(zv1[1] + zv2[1], 2) + powf(zv1[2] + zv2[2], 2) + powf(zv1[3] + zv2[3], 2)
			+ powf(zv1[4] + zv2[4], 2)
			+ powf(zv1[5] + zv2[5], 2)
			+ powf(zv1[6] + zv2[6], 2)
			+ powf(zv1[7] + zv2[7], 2)
			+ powf(zv1[8] + zv2[8], 2)
			+ powf(zv1[9] + zv2[9], 2);


		EndPoint = std::chrono::system_clock::now();
		nano = (EndPoint - start);
		cout << nano.count() << endl;
		cout << endl;
		cout << endl;
	}
	
	return 0;
}
