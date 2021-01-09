#include <iostream>
#include <emmintrin.h>
#include <windows.h>
#include<xmmintrin.h>
#include<iostream>
#include <time.h>
#include <windows.h>
#include <math.h>

#include <time.h>

using namespace std;

const int n = 1000000000;

__m128 a, b, r;

__declspec(align(16)) float v1[4] = { 1,2,3,4};

__declspec(align(16)) float v2[4] = { 8,1,7,2 };

__declspec(align(16)) float result[4];


float zv1[4] = { 1,2,3,4 };

float zv2[4] = { 8,1,7,2 };

float zresult[4];
int main()
{
	clock_t startTime, endTime;

	double nProcessExcuteTime;
	float k;
	bool one = false;

	__m128 pppp;
	__m128 aaaa;
	__m128 res;
	__m128 mul_res;
	startTime = clock(); /*현재 시각을 구한다.*/
	for (int a = 0; a < 100000000; ++a) {
		pppp = _mm_load_ps(v1);
		aaaa = _mm_load_ps(v2);
		res = _mm_add_ps(pppp, aaaa);
		mul_res = _mm_mul_ps(res, res);

		_mm_store_ps(result, mul_res);
		k = result[0] + result[1] + result[2] + result[3];
		if (!one) {
			cout << k << endl;
			one = true;
		}
	}
	one = false;
	endTime = clock(); /*현재 시각을 구한다.*/
	nProcessExcuteTime = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;
	printf("SIMD Excute time: %f\n", nProcessExcuteTime);


	startTime = clock(); /*현재 시각을 구한다.*/
	for (int a = 0; a < 100000000; ++a) {
		//k = powf(zv1[0] + zv2[0], 2) + powf(zv1[1] + zv2[1], 2) + powf(zv1[2] + zv2[2], 2) + powf(zv1[3] + zv2[3], 2);
		k = (zv1[0] + zv2[0]) * (zv1[0] + zv2[0]);
		k += (zv1[1] + zv2[1]) * (zv1[1] + zv2[1]);
		k += (zv1[2] + zv2[2]) * (zv1[2] + zv2[2]);
		k += (zv1[3] + zv2[3]) * (zv1[3] + zv2[3]);
		if (!one) {
			cout << k << endl;
			one = true;
		}
	}
	endTime = clock(); /*현재 시각을 구한다.*/
	nProcessExcuteTime = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;
	printf("노말 Excute time: %f\n", nProcessExcuteTime);

	startTime = clock(); /*현재 시각을 구한다.*/
	for (int a = 0; a < 100000000; ++a) {
		k = powf(zv1[0] + zv2[0], 2) + powf(zv1[1] + zv2[1], 2) + powf(zv1[2] + zv2[2], 2) + powf(zv1[3] + zv2[3], 2);

		if (!one) {
			cout << k << endl;
			one = true;
		}
	}
	endTime = clock(); /*현재 시각을 구한다.*/
	nProcessExcuteTime = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;
	printf("시스템 함수 Excute time: %f\n", nProcessExcuteTime);

	return 0;
}
