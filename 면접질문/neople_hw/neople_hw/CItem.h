#pragma once
class CItem
{
private:		//����
	int16_t			m_usLevelLimit;

	uint32_t		m_uiItemType;	// string�� ����ϸ� unordered_map�� ��ġ ȿ���� ��������.
	// � ������ �������ΰ� ex) �ռҵ� = 1, �ռҵ� +1 = 1
	
private:		//�Ǽ�
	float			m_fWeight;

private:		// enum
	INVEN_TYPE		m_eType;
	EXCHANGE_TYPE	m_eExchangeType;

public:
	INVEN_TYPE GetType() { return m_eType; }
};

