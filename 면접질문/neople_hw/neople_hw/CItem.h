#pragma once
class CItem
{
public:
	CItem(const INVEN_TYPE& type, const float& weight, const string& name) { m_eType = type, m_fWeight = weight, m_sName = name; }
	virtual ~CItem() {};
protected:		//정수
	string			m_sName = "";
	int16_t			m_usLevelLimit;
	uint32_t		m_uiItemType;	// string을 사용하면 unordered_map의 서치 효율이 떨어진다.
	// 어떤 종류의 아이템인가 ex) 롱소드 = 1, 롱소드 +1 = 1
	
protected:		//실수
	float			m_fWeight;

protected:		// enum
	INVEN_TYPE		m_eType;
	EXCHANGE_TYPE	m_eExchangeType;

public:
	INVEN_TYPE	GetType()		{ return m_eType; }
	float		GetWeight()		{ return m_fWeight; }
	string		GetName()		{ return m_sName; }

public:

};

