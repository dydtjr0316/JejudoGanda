#pragma once
class CItem
{
public:
	CItem();
	CItem(const INVEN_TYPE& type, const float& weight, const string& name) { m_eType = type, m_fWeight = weight, m_sName = name; }
	virtual ~CItem() {};	// virtual 키워드 사용 위치

protected:
	uShort	m_usLevelLimit;
//	uShort	m_usLevel;
	uShort	m_usEnhance = 0;
	uShort	m_usSmelting = 0;

	uInt    m_uiSerialNo;       // 식별번호

	string		m_sName = "";

	float			m_fWeight;

	INVEN_TYPE		m_eType;
	EXCHANGE_TYPE	m_eExchangeType; // 귀속 교불 등등

public:
	uShort		GetLevelLimit() { return m_usLevelLimit; }
	uShort		GetEnhance() { return m_usEnhance; }
	uShort		GetSmelting() { return m_usSmelting; }
	/*uShort		GetLevel() { return m_usLevel; }*/

	uInt		GetSerialNo() { return m_uiSerialNo; }

	string			GetName()		{ return m_sName; }

	float			GetWeight()		{ return m_fWeight; }

	INVEN_TYPE		GetType()		{ return m_eType; }
	EXCHANGE_TYPE	GetExchangeType() { return m_eExchangeType; }

public:

};

