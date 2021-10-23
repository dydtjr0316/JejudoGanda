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
typedef uint16_t ID;
class CInventory
{
public:
	CInventory();
private:
	vector<CItem*> m_vItemLst[MAX_LAYER];


private:
	INVEN_TYPE  m_eCurInvenType = INVEN_TYPE::EQUIPMENT;
	// search, option, sorting���� �Լ����� ����ϱ� 
	// ���� ���� � â�� �ִ����� ��Ÿ���� ����

	float		m_fInvenWeight = 0.f;			// ����
	float		m_fMaxInvenWeight = 45.f;		// ���� �ѵ� // ���� �ϴ� ���� �ִ�ġ �־����
	uint16_t	m_usCoin = 0;					// ����
	uint16_t	m_usVictoryToken = 0;			// �¸��� ��ǥ
	uint32_t	m_uiGold = 0 ;					// ���
	uint32_t	m_uiSera = 0;					// ����
	uint16_t	m_usCurItemCount = 0;			// ������ ����
	uint16_t	m_usMaxSlotSize = SLOT_IDLE;	// �����ִ밹��


public:
	void InitItem		(CItem* item, const uint16_t& addCount = 1);
	void DeleteItem		(const uint16_t& itemid, const uint16_t& deleteCount = 1);
};

