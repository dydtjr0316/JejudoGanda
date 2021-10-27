#pragma once
class CItem;
class CInventory
{
public:
	CInventory();
private:
	vector<CItem*> m_vItemLst[MAX_LAYER];
private:
	INVEN_TYPE  m_eCurInvenType = INVEN_TYPE::EXPENDABLES;
	// search, option, sorting등의 함수에서 사용하기 
	// 위해 현재 어떤 창에 있는지를 나타내는 변수

	float		m_fInvenWeight = 0.f;			// 무게
	float		m_fMaxInvenWeight = 45.f;		// 무게 한도 // 여기 일단 대충 최대치 넣어놓기

	uShort	m_usCoin = 0;					// 코인
	uShort	m_usVictoryToken = 0;			// 승리의 증표
	uInt	m_uiGold = 0 ;					// 골드
	uInt	m_uiSera = 0;					// 세라


	uShort	m_usCurItemCount = 0;			// 아이템 갯수
	uShort	m_usMaxSlotSize = SLOT_IDLE;	// 슬롯최대갯수
public:
	void InventorySizeUp();
	void InitItem		(CItem* item, const uShort & addCount = 1);
	void DeleteItem		(const uShort& itemid, const uShort& deleteCount = 1);
	void PrintAll		();
};

