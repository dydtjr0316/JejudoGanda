#pragma once
#include "CItem.h"
class CExpendablItem
	: public CItem
{
private:	// 정수
	uShort			m_usCoolTime;				// 쿨타임
	uShort			m_usExpiryDate;				// 유효기간
	uShort			m_usMaxPossessionLimit;		// 최대 소지 한도
	uShort			m_usMaxDurability = 45;		// 최대 내구도
	uShort			m_usCurDurability;			// 현재 내구도
	uShort			m_usItemCount = 1;

	string				m_sExplanation;				// 설명

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

