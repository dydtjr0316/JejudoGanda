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
typedef uint16_t ID;
class CInventory
{
public:
	CInventory();
private:
	vector<CItem*> m_vItemLst[MAX_LAYER];


private:
	INVEN_TYPE  m_eCurInvenType = INVEN_TYPE::EQUIPMENT;
	// search, option, sorting등의 함수에서 사용하기 
	// 위해 현재 어떤 창에 있는지를 나타내는 변수

	float		m_fInvenWeight = 0.f;			// 무게
	float		m_fMaxInvenWeight = 45.f;		// 무게 한도 // 여기 일단 대충 최대치 넣어놓기
	uint16_t	m_usCoin = 0;					// 코인
	uint16_t	m_usVictoryToken = 0;			// 승리의 증표
	uint32_t	m_uiGold = 0 ;					// 골드
	uint32_t	m_uiSera = 0;					// 세라
	uint16_t	m_usCurItemCount = 0;			// 아이템 갯수
	uint16_t	m_usMaxSlotSize = SLOT_IDLE;	// 슬롯최대갯수


public:
	void InitItem		(CItem* item, const uint16_t& addCount = 1);
	void DeleteItem		(const uint16_t& itemid, const uint16_t& deleteCount = 1);
};

