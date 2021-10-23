#pragma once
class CItem
{
private:
	INVEN_TYPE m_eType;
	uint32_t m_uiItemType;	// string을 사용하면 unordered_map의 서치 효율이 떨어진다.
	// 어떤 종류의 아이템인가 ex) 롱소드 = 1, 롱소드 +1 = 1
	
	bool m_bisEquip;

public:
	void SetType(const INVEN_TYPE& type) { m_eType = type; }
	void SetSerialNum(const uint32_t& num) { m_uiItemType = num; }

public:
	INVEN_TYPE GetType() { return m_eType; }
	uint32_t GetSerialNum() { return m_uiItemType; }
};

