#pragma once
#include "CItem.h"
class CItem;
class CSortingMgr;
class CStore
{
private:
	vector<CItem*>	m_vItemLst;
	SORTING_ORDER	m_eCurSortingOrder = SORTING_ORDER::IDLE;
	SORTING_TYPE	m_eCurSortingType = SORTING_TYPE::IDLE;
public:
	void Init();
	void SearchName(const string& name, const uint16_t& minLv, const uint16_t& maxLv, const RARITY& rarity);
	void Search_Atype(const ITEM_A_TYPE& a);
	void Search_Btype(const ITEM_A_TYPE& a, const ITEM_B_TYPE& b);
	void Search_Ctype(const ITEM_A_TYPE& a, const ITEM_B_TYPE& b, const ITEM_C_TYPE& c);

	void AddItem(CItem* item);
	void Sorting(const SORTING_TYPE& type);
	void Sorting_IDLE();
	void AscSorting();
	void DescSorting();
	void ReadySorting(const SORTING_TYPE& type);
	void Print(CItem* item);
	void PrintALL();
public:
	vector<CItem*> GetItemLst() { return m_vItemLst; }
};

