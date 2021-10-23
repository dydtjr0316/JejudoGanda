#pragma once
//enum INVEN_TYPE
//{
//	EQUIPMENT,		//장	비
//	EXPENDABLES,	//소모품
//	MATERIAL,		//재료
//	SPECIAL,		//전문재료
//	QUEST,			//퀘스트
//};
//enum EQUIP
//{
//	HEADNSHOULDER,
//	TOP,
//	PANTS,
//	BELT,
//	SHOES,
//	WEAPON,
//	STYLE,
//	BRACELET,
//	NECKLACE,
//	SUB,
//	RING,
//	EARRING,
//	MAGINSTONE
//};
// 인벤토리 종류 -> 해당 인벤토리 내에서의 유니크한 아이템의 아이디 -> 해당 아이템의 슬롯 아이디
class CItem;
class CInventory
{
private:
	vector<bool> m_vSlot;			// 슬롯에 아이템이 있는가?
	list<CItem*> m_InvenLst[MAX_LAYER];
	unordered_map<int, CItem*> m_InvenLst[MAX_LAYER];
	// vector list citem 하는게 나으려나?

	// 1. 인벤토리안에서 아이템이 가지는 아이디 ex) 같은 아이템이 여러개 있을 때
	//	아이디, 아이템

	// 2. 아이디, 슬롯의 인덱스

	CItem* m_EquipLst[MAX_EQUIP]{ nullptr, }; // 얘가 없고
	// vector citem이 나으려나

private:
	INVEN_TYPE  m_eCurInvenType = INVEN_TYPE::EQUIPMENT;
	// search, option, sorting등의 함수에서 사용하기 
	// 위해 현재 어떤 창에 있는지를 나타내는 변수

	float		m_fWeight;			// 무게
	float		m_fmaxWeight;		// 무게 한도
	uint16_t	m_usCoin;			// 코인
	uint16_t	m_usVictoryToken;	// 승리의 증표
	uint32_t	m_uiGold;			// 골드
	uint32_t	m_uiSera;			// 세라
	uint16_t	m_usMaxItemCount;	// 아이템 갯수 최대치
	uint16_t	m_usItemCount;		// 아이템 갯수

public:
	void InitItem(CItem* item);
	void DeleteItem(CItem* item);

	void Search(const string& str) {};
	void Option() {};
	void Sorting(INVEN_TYPE& type) {};
};

