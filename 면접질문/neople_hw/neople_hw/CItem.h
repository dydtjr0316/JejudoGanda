#pragma once
class CItem
{
private:
	INVEN_TYPE m_eType;
	uint64_t m_SerialNum;	// string을 사용하면 unordered_map의 서치 효율이 떨어진다.
	

public:
	void SetType(const INVEN_TYPE& type) { m_eType = type; }
	void SetSerialNum(const uint64_t& num) { m_SerialNum = num; }

public:
	INVEN_TYPE GetType() { return m_eType; }
	uint64_t GetSerialNum() { return m_SerialNum; }
};

