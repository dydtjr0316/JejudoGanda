#pragma once
// �κ��丮 ���� -> �ش� �κ��丮 �������� ����ũ�� �������� ���̵� -> �ش� �������� ���� ���̵�
class CItem;
typedef uShort ID;
class CInventory
{
public:
	CInventory();
private:
	vector<CItem*> m_vItemLst[MAX_LAYER];
private:
	INVEN_TYPE  m_eCurInvenType = INVEN_TYPE::EXPENDABLES;
	// search, option, sorting���� �Լ����� ����ϱ� 
	// ���� ���� � â�� �ִ����� ��Ÿ���� ����

	float		m_fInvenWeight = 0.f;			// ����
	float		m_fMaxInvenWeight = 45.f;		// ���� �ѵ� // ���� �ϴ� ���� �ִ�ġ �־����

	//  �̰� ����Ǵ°�?
	uShort	m_usCoin = 0;					// ����
	uShort	m_usVictoryToken = 0;			// �¸��� ��ǥ
	uInt	m_uiGold = 0 ;					// ���
	uInt	m_uiSera = 0;					// ����


	uShort	m_usCurItemCount = 0;			// ������ ����
	uShort	m_usMaxSlotSize = SLOT_IDLE;	// �����ִ밹��


public:
	void InitItem		(CItem* item, const uShort& addCount = 1);
	void DeleteItem		(const uShort& itemid, const uShort& deleteCount = 1);
	void PrintAll		();
};

