#include "stdafx.h"
#include "CStore.h"
#include "CItem.h"


int main()
{	
		
		sort(ItemLst.begin(), ItemLst.end(), cmp);

		auto startMM = system_clock::now();
		auto endMM = system_clock::now();
		std::cout << "vector int ºñ±³ : " << duration_cast<milliseconds>(endMM - startMM).count() << "ms" << std::endl;
		cout << endl;
}