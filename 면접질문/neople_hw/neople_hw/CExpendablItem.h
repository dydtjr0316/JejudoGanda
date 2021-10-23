#pragma once
#include "CItem.h"
class CExpendablItem
	: public CItem
{
private:	// 정수
	int16_t			m_usCoolTime;				// 쿨타임
	int16_t			m_usExpiryDate;				// 유효기간
	int16_t			m_usMaxPossessionLimit;		// 최대 소지 한도
	int16_t			m_usMaxDurability = 45;			// 최대 내구도
	int16_t			m_usCurDurability;			// 현재 내구도
	int16_t			m_usItemCount = 1;

private: // 문자열
	string			m_sExplanation;				// 설명
	
private:	// enum
	EQUIPMENT_TYPE	m_eEquipmentType;			// 장비종류
	OCCUPATION_TYPE	m_eOccupationType;			// 장착가능 직업

public:
	int16_t		GetItemCount()	{ return m_usItemCount; }

public:
	void	SetItemCount(const int16_t& itemCount) { m_usItemCount = itemCount; }
};

