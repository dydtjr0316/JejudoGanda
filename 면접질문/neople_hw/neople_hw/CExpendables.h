#pragma once
#include "CItem.h"
class CExpendables
	: public CItem
{
private:	// ����
	int16_t			m_usCoolTime;				// ��Ÿ��
	int16_t			m_usExpiryDate;				// ��ȿ�Ⱓ
	int16_t			m_usMaxPossessionLimit;		// �ִ� ���� �ѵ�
	int16_t			m_usMaxDurability;			// �ִ� ������
	int16_t			m_usCurDurability;			// ���� ������

private: // ���ڿ�
	string			m_sExplanation;				// ����
	
private:	// enum
	EQUIPMENT_TYPE	m_eEquipmentType;			// �������
	OCCUPATION_TYPE	m_eOccupationType;			// �������� ����
};

