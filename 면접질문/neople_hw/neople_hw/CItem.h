#pragma once
class CItem
{
private:
	INVEN_TYPE m_eType;
	uint64_t m_SerialNum;	// string�� ����ϸ� unordered_map�� ��ġ ȿ���� ��������.
	

public:
	void SetType(const INVEN_TYPE& type) { m_eType = type; }
	void SetSerialNum(const uint64_t& num) { m_SerialNum = num; }

public:
	INVEN_TYPE GetType() { return m_eType; }
	uint64_t GetSerialNum() { return m_SerialNum; }
};

