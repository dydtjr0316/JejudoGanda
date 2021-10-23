#pragma once
#include "CItem.h"
class CExpendablItem
	: public CItem
{
private:	// ����
	int16_t			m_usCoolTime;				// ��Ÿ��
	int16_t			m_usExpiryDate;				// ��ȿ�Ⱓ
	int16_t			m_usMaxPossessionLimit;		// �ִ� ���� �ѵ�
	int16_t			m_usMaxDurability = 45;			// �ִ� ������
	int16_t			m_usCurDurability;			// ���� ������
	int16_t			m_usItemCount = 1;

private: // ���ڿ�
	string			m_sExplanation;				// ����
	
private:	// enum
	EQUIPMENT_TYPE	m_eEquipmentType;			// �������
	OCCUPATION_TYPE	m_eOccupationType;			// �������� ����

public:
	int16_t		GetItemCount()	{ return m_usItemCount; }

public:
	void	SetItemCount(const int16_t& itemCount) { m_usItemCount = itemCount; }
};

