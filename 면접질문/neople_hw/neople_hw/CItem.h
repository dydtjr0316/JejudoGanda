#pragma once
class CItem
{
public:
	CItem(const INVEN_TYPE& type, const float& weight, const string& name) { m_eType = type, m_fWeight = weight, m_sName = name; }
	virtual ~CItem() {};
protected:		//����
	string			m_sName = "";
	int16_t			m_usLevelLimit;
	uint32_t		m_uiItemType;	// string�� ����ϸ� unordered_map�� ��ġ ȿ���� ��������.
	// � ������ �������ΰ� ex) �ռҵ� = 1, �ռҵ� +1 = 1
	
protected:		//�Ǽ�
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

