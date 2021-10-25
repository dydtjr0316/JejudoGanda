#pragma once
class CItem
{
public:
	CItem() {}
	CItem(const INVEN_TYPE& type, const float& weight, const string& name) { m_eType = type, m_fWeight = weight, m_sName = name; }
	virtual ~CItem() {};	// virtual 키워드 사용 위치

protected:
	uint16_t	m_usLevelLimit;
//	uint16_t	m_usLevel;
	uint16_t	m_usEnhance = 0;
	uint16_t	m_usSmelting = 0;

	uint32_t    m_uiSerialNo;       // 식별번호

	string		m_sName = "";

	float			m_fWeight;

	INVEN_TYPE		m_eType;
	EXCHANGE_TYPE	m_eExchangeType; // 귀속 교불 등등

public:
	uint16_t		GetLevelLimit() { return m_usLevelLimit; }
	uint16_t		GetEnhance() { return m_usEnhance; }
	uint16_t		GetSmelting() { return m_usSmelting; }
	/*uint16_t		GetLevel() { return m_usLevel; }*/

	uint32_t		GetSerialNo() { return m_uiSerialNo; }

	string			GetName()		{ return m_sName; }

	float			GetWeight()		{ return m_fWeight; }

	INVEN_TYPE		GetType()		{ return m_eType; }
	EXCHANGE_TYPE	GetExchangeType() { return m_eExchangeType; }

public:

};

