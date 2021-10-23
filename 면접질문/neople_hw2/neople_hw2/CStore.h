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
	void InitItem(CItem* item);
	void Sorting(const SORTING_TYPE& type);
	void AscSorting();
	void DescSorting();
	void ReadySorting(const SORTING_TYPE& type);
public:
	vector<CItem*> GetItemLst() { return m_vItemLst; }
};

