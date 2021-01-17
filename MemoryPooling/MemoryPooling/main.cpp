#include <Windows.h>
#include <time.h>
#include <chrono>
#include <iostream>
using namespace std;

template<class T, int ALLOC_BLOCK_SIZE = 50>
class CMemoryPool
{
public:
	static VOID* operator new(size_t allocLength)
	{
		if (!mFreePointer)
			AllocBlock();

		UCHAR* returnPointer = mFreePointer;

		mFreePointer = *reinterpret_cast<UCHAR**>(returnPointer);
		return returnPointer;
	}
	
	static VOID operator delete(VOID* deletePointer)
	{
		*reinterpret_cast<UCHAR**>(deletePointer) = mFreePointer;
		mFreePointer = static_cast<UCHAR*>(deletePointer);
	}

private:
	static VOID AllocBlock()
	{
		mFreePointer = new UCHAR[sizeof(T) * ALLOC_BLOCK_SIZE];
		UCHAR** current = reinterpret_cast<UCHAR**>(mFreePointer);
		UCHAR* next = mFreePointer;
		for (INT i = 0; i < ALLOC_BLOCK_SIZE - 1; ++i)
		{
			next += sizeof(T);
			*current = next;
			current = reinterpret_cast<UCHAR**>(next);
		}
		*current = 0;
	}
private:
	static UCHAR* mFreePointer;

protected:
	~CMemoryPool() {}
};


template<class T, int ALLOC_BLOCK_SIZE>
UCHAR* CMemoryPool<T, ALLOC_BLOCK_SIZE>::mFreePointer;

class CDataMP :public CMemoryPool<CDataMP>
{
public:
	BYTE a[1024];
	BYTE b[1024];
};
class CDataMP2 
{
public:
	BYTE a[1024];
	BYTE b[1024];
};

int main()
{
	int FOR_COUNT = 1000000;
	clock_t start_time, end_time;
	start_time = clock();
	for (int i = 0; i < FOR_COUNT; ++i)
	{
		CDataMP* pData = new CDataMP();
		delete pData;
	}
	end_time = clock();
	cout << endl;
	cout << "메모리풀 사용 시간 : " << (double)(end_time - start_time) / CLOCKS_PER_SEC << endl;;

	start_time = clock();
	for (int i = 0; i < FOR_COUNT; ++i)
	{
		CDataMP2* pData = new CDataMP2();
		delete pData;
	}
	end_time = clock();

	cout << "메모리풀 사용 시간 : " << (double)(end_time - start_time) / CLOCKS_PER_SEC;

}