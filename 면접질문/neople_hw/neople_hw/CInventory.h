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
	// 1. 인벤토리안에서 아이템이 가지는 아이디 ex) 같은 아이템이 여러개 있을 때
	//	아이디, 아이템
	unordered_map<uint16_t, CItem*> m_ItemLst_ID[MAX_LAYER];

	// 2. 아이디, 슬롯의 인덱스
	unordered_map<uint16_t, uint16_t> m_ItemLst_Slot[MAX_LAYER];
	// 3. 아이디, 갯수
	unordered_map<uint16_t, uint16_t> m_ExpendableNumLst[MAX_LAYER];


private:
	INVEN_TYPE  m_eCurInvenType = INVEN_TYPE::EQUIPMENT;
	// search, option, sorting등의 함수에서 사용하기 
	// 위해 현재 어떤 창에 있는지를 나타내는 변수

	float		m_fInvenWeight;			// 무게
	float		m_fMaxInvenWeight;		// 무게 한도
	uint16_t	m_usCoin;			// 코인
	uint16_t	m_usVictoryToken;	// 승리의 증표
	uint32_t	m_uiGold;			// 골드
	uint32_t	m_uiSera;			// 세라
	uint16_t	m_usMaxItemCount;	// 아이템 갯수 최대치
	uint16_t	m_usItemCount;		// 아이템 갯수
	uint16_t	m_usMaxSlotSize = SLOT_IDLE;


public:
	void InitItem(CItem* item);
	void DeleteItem(const uint16_t& itemid);
};

