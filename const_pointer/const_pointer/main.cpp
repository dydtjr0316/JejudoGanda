#include <iostream>
#include "CClass.h"
#include <windows.h>
#include <emmintrin.h>
#include <time.h>


using namespace std;

const int n = 10000000000;

__m128i a, b, r;

__declspec(align(16)) short v1[8] = { 1,2,3,4,5,6,7,8 };

__declspec(align(16)) short v2[8] = { 8,1,7,2,6,3,5,4 };

__declspec(align(16)) short result[8];



int main() {

	clock_t startTime, endTime;

	double nProcessExcuteTime;

	startTime = clock(); /*현재 시각을 구한다.*/

	// SISD

	for (int i = 0; i < n; i++) {

		result[0] = v1[0] > v2[0] ? v1[0] : v2[0];

		result[1] = v1[1] > v2[1] ? v1[1] : v2[1];

		result[2] = v1[2] > v2[2] ? v1[2] : v2[2];

		result[3] = v1[3] > v2[3] ? v1[3] : v2[3];

		result[4] = v1[4] > v2[4] ? v1[4] : v2[4];

		result[5] = v1[5] > v2[5] ? v1[5] : v2[5];

		result[6] = v1[6] > v2[6] ? v1[6] : v2[6];

		result[7] = v1[7] > v2[7] ? v1[7] : v2[7];

	}

	endTime = clock(); /*현재 시각을 구한다.*/

	nProcessExcuteTime = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;

	printf("Excute time: %f\n", nProcessExcuteTime);





	startTime = clock(); /*현재 시각을 구한다.*/

	// SIMD

	for (int i = 0; i < n; i++) {

		a = _mm_loadu_si128((__m128i*)v1);

		b = _mm_loadu_si128((__m128i*)v2);

		r = _mm_max_epi16(a, b);

		r = _mm_min_epi16(a, b);

		_mm_storeu_si128((__m128i*) result, r);

	}

	endTime = clock(); /*현재 시각을 구한다.*/

	nProcessExcuteTime = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;

	printf("Excute time: %f\n", nProcessExcuteTime);

}
