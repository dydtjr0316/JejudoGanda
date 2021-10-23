#pragma once
//enum INVEN_TYPE
//{
//	EQUIPMENT,		//��	��
//	EXPENDABLES,	//�Ҹ�ǰ
//	MATERIAL,		//���
//	SPECIAL,		//�������
//	QUEST,			//����Ʈ
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
// �κ��丮 ���� -> �ش� �κ��丮 �������� ����ũ�� �������� ���̵� -> �ش� �������� ���� ���̵�
class CItem;
class CInventory
{
private:
	// 1. �κ��丮�ȿ��� �������� ������ ���̵� ex) ���� �������� ������ ���� ��
	//	���̵�, ������
	unordered_map<uint16_t, CItem*> m_ItemLst_ID[MAX_LAYER];

	// 2. ���̵�, ������ �ε���
	unordered_map<uint16_t, uint16_t> m_ItemLst_Slot[MAX_LAYER];
	// 3. ���̵�, ����
	unordered_map<uint16_t, uint16_t> m_ExpendableNumLst[MAX_LAYER];


private:
	INVEN_TYPE  m_eCurInvenType = INVEN_TYPE::EQUIPMENT;
	// search, option, sorting���� �Լ����� ����ϱ� 
	// ���� ���� � â�� �ִ����� ��Ÿ���� ����

	float		m_fInvenWeight;			// ����
	float		m_fMaxInvenWeight;		// ���� �ѵ�
	uint16_t	m_usCoin;			// ����
	uint16_t	m_usVictoryToken;	// �¸��� ��ǥ
	uint32_t	m_uiGold;			// ���
	uint32_t	m_uiSera;			// ����
	uint16_t	m_usMaxItemCount;	// ������ ���� �ִ�ġ
	uint16_t	m_usItemCount;		// ������ ����
	uint16_t	m_usMaxSlotSize = SLOT_IDLE;


public:
	void InitItem(CItem* item);
	void DeleteItem(const uint16_t& itemid);
};

