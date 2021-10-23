#pragma once
class CItem
{
private:
	INVEN_TYPE m_eType;
	uint32_t m_uiItemType;	// string�� ����ϸ� unordered_map�� ��ġ ȿ���� ��������.
	// � ������ �������ΰ� ex) �ռҵ� = 1, �ռҵ� +1 = 1
	
	bool m_bisEquip;

public:
	void SetType(const INVEN_TYPE& type) { m_eType = type; }
	void SetSerialNum(const uint32_t& num) { m_uiItemType = num; }

public:
	INVEN_TYPE GetType() { return m_eType; }
	uint32_t GetSerialNum() { return m_uiItemType; }
};

