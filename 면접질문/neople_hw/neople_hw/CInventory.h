#pragma once
enum INVEN_TYPE
{
	EQUIPMENT,		//��	��
	EXPENDABLES,	//�Ҹ�ǰ
	MATERIAL,		//���
	SPECIAL,		//�������
	QUEST,			//����Ʈ
};
enum EQUIP
{
	HEADNSHOULDER,
	TOP,
	PANTS,
	BELT,
	SHOES,
	WEAPON,
	STYLE,
	BRACELET,
	NECKLACE,
	SUB,
	RING,
	EARRING,
	MAGINSTONE
};
class CItem;
class CInventory
{
private:
	vector<bool> m_vSlot;			// ���Կ� �������� �ִ°�?
	list<CItem*> m_InvenLst[MAX_LAYER];
	// vector list citem �ϴ°� ��������?
	CItem* m_EquipLst[MAX_EQUIP]{ nullptr, };
	// vector citem�� ��������

private:
	INVEN_TYPE  m_eCurInvenType = INVEN_TYPE::EQUIPMENT;
	// search, option, sorting���� �Լ����� ����ϱ� 
	// ���� ���� � â�� �ִ����� ��Ÿ���� ����

	float		m_fWeight;			// ����
	float		m_fmaxWeight;		// ���� �ѵ�
	uint16_t	m_usCoin;			// ����
	uint16_t	m_usVictoryToken;	// �¸��� ��ǥ
	uint32_t	m_uiGold;			// ���
	uint32_t	m_uiSera;			// ����

	uint16_t	m_usMaxItemCount;	// ������ ���� �ִ�ġ
	uint16_t	m_usItemCount;		// ������ ����

public:
	void InitItem(CItem& item);
	void DeleteItem(CItem* item);

	void Search(const string& str) {};
	void Option() {};
	void Sorting(INVEN_TYPE& type) {};
};

