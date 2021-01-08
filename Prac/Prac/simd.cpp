#include <iostream>
#include <emmintrin.h>
#include <windows.h>
#include<xmmintrin.h>
#include<iostream>
#include <time.h>
#include <windows.h>

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

	__m128 pppp;
	__m128 aaaa;
	__m128 res;
	startTime = clock(); /*현재 시각을 구한다.*/
	for (int a = 0; a < 10000000; ++a) {

		pppp = _mm_load_ps(v1);
		aaaa = _mm_load_ps(v2);
		res = _mm_add_ps(pppp, aaaa);

		_mm_store_ps(result, res);
	}
	endTime = clock(); /*현재 시각을 구한다.*/
	nProcessExcuteTime = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;
	printf("Excute time: %f\n", nProcessExcuteTime);

	startTime = clock(); /*현재 시각을 구한다.*/
	for (int a = 0; a < 10000000; ++a) {
		for (int i = 0; i < 4; ++i)
		{
			zresult[i] = zv1[i] + zv2[i];
		}
	}
	endTime = clock(); /*현재 시각을 구한다.*/
	nProcessExcuteTime = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;
	printf("Excute time: %f\n", nProcessExcuteTime);
	return 0;
}
