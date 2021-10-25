#pragma once
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
	void AddItem(CItem* item);

	// 검색
	void SearchName(const string& name, const uint16_t& minLv, const uint16_t& maxLv, const RARITY& rarity);
	void Search_Atype(const ITEM_A_TYPE& a);
	void Search_Btype(const ITEM_A_TYPE& a, const ITEM_B_TYPE& b);
	void Search_Ctype(const ITEM_A_TYPE& a, const ITEM_B_TYPE& b, const ITEM_C_TYPE& c);
	
	// 정렬
	void Sorting(const SORTING_TYPE& type);
	void Sorting_IDLE();
	void AscSorting();
	void DescSorting();
	void ReadySorting(const SORTING_TYPE& type);

	// 출력
	void Print(CItem* item);
	void PrintALL();

public:		//get함수
	vector<CItem*> GetItemLst() { return m_vItemLst; }
};

