#include "stdafx.h"
#include "CStore.h"


int main()
{	
	CStore store;
	store.Init();
	store.PrintALL();
	store.SearchName("ø¿≈∞µÂ", 50, 60, RARITY::UNIQ);
	store.Search_ExpendableItems();
	store.Search_Atype(ITEM_A_TYPE::ACC);
	store.Search_Btype(ITEM_A_TYPE::ARMOR, ITEM_B_TYPE::ARMOR_LEATHER);
	store.Search_Ctype(ITEM_A_TYPE::WEAPON, ITEM_B_TYPE::WEAPON_DARKKNIGHT, ITEM_C_TYPE::WEAPON_DARKKNIGHT_KNIFE);
}