#include "stdafx.h"
#include "CStore.h"
#include "CItem.h"


int main()
{	
		/*auto startMM = system_clock::now();
		auto endMM = system_clock::now();
		std::cout << "vector int 비교 : " << duration_cast<milliseconds>(endMM - startMM).count() << "ms" << std::endl;
		cout << endl;*/

	CStore store;
	store.Init();
	store.PrintALL();
	store.SearchName("오키드", 50, 60, RARITY::UNIQ);
	store.Search_Atype(ITEM_A_TYPE::ACC);
	store.Search_Btype(ITEM_A_TYPE::ARMOR, ITEM_B_TYPE::ARMOR_LEATHER);
	store.Search_Ctype(ITEM_A_TYPE::WEAPON, ITEM_B_TYPE::WEAPON_DARKKNIGHT, ITEM_C_TYPE::WEAPON_DARKKNIGHT_KNIFE);
	
}