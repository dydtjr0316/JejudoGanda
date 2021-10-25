#pragma once
#include "CItem.h"
class CExpendablItem
	: public CItem
{
private:	// ����
	uint16_t			m_usCoolTime;				// ��Ÿ��
	uint16_t			m_usExpiryDate;				// ��ȿ�Ⱓ
	uint16_t			m_usMaxPossessionLimit;		// �ִ� ���� �ѵ�
	uint16_t			m_usMaxDurability = 45;		// �ִ� ������
	uint16_t			m_usCurDurability;			// ���� ������
	uint16_t			m_usItemCount = 1;

	string				m_sExplanation;				// ����

public:
	CExpendablItem(const INVEN_TYPE& type, const float& weight, const string& name, const int16_t& count)
	{
		m_eType = type, m_fWeight = weight, m_sName = name; m_usItemCount = count;
	}

public:	// get
	int16_t		GetItemCount()	{ return m_usItemCount; }

public: // set
	void		SetItemCount(const int16_t& itemCount) { m_usItemCount = itemCount; }
};

