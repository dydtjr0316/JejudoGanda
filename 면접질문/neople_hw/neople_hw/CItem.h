#pragma once
class CItem
{
public:
	CItem();
	CItem(const INVEN_TYPE& type, const float& weight, const string& name) { m_eType = type, m_fWeight = weight, m_sName = name; }
	virtual ~CItem() {};	

protected:
	uShort			m_usLevelLimit;
	uShort			m_usEnhance;
	uShort			m_usSmelting;

	uInt			m_uiSerialNo;		// �ĺ���ȣ

	string			m_sName = "";

	float			m_fWeight;

	INVEN_TYPE		m_eType;			// ���, �Ҹ�ǰ ��
	EXCHANGE_TYPE	m_eExchangeType;	// �ͼ� ���� ���

public:
	uShort		GetLevelLimit() { return m_usLevelLimit; }
	uShort		GetEnhance() { return m_usEnhance; }
	uShort		GetSmelting() { return m_usSmelting; }

	uInt		GetSerialNo() { return m_uiSerialNo; }

	string			GetName()		{ return m_sName; }

	float			GetWeight()		{ return m_fWeight; }

	INVEN_TYPE		GetType()		{ return m_eType; }
	EXCHANGE_TYPE	GetExchangeType() { return m_eExchangeType; }

public:

};

