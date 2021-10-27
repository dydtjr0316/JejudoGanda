#pragma once
#include "CItem.h"
class CExpendablItem
	: public CItem
{
private:	// ����
	uShort			m_usCoolTime;				// ��Ÿ��
	uShort			m_usExpiryDate;				// ��ȿ�Ⱓ
	uShort			m_usMaxPossessionLimit;		// �ִ� ���� �ѵ�
	uShort			m_usMaxDurability = 45;		// �ִ� ������
	uShort			m_usCurDurability;			// ���� ������
	uShort			m_usItemCount = 1;

	string				m_sExplanation;				// ����

public:
	CExpendablItem(const INVEN_TYPE& type, const float& weight, const string& name, const uShort& count)
	{
		m_eType = type, m_fWeight = weight, m_sName = name; m_usItemCount = count;
	}

public:	// get
	uShort		GetItemCount()	{ return m_usItemCount; }

public: // set
	void		SetItemCount(const uShort& itemCount) { m_usItemCount = itemCount; }
};

