#pragma once
#include "CItem.h"
class CExpendablItem
	: public CItem
{
private:	// 정수
	uint16_t			m_usCoolTime;				// 쿨타임
	uint16_t			m_usExpiryDate;				// 유효기간
	uint16_t			m_usMaxPossessionLimit;		// 최대 소지 한도
	uint16_t			m_usMaxDurability = 45;		// 최대 내구도
	uint16_t			m_usCurDurability;			// 현재 내구도
	uint16_t			m_usItemCount = 1;

	string				m_sExplanation;				// 설명

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

