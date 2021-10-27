#pragma once
class CRegistInfo
{
public:
	CRegistInfo(const uint32_t& price, const string& name)
	{
		m_sRegisterName = name; m_uiPrice = price;
	};
private:
	string		m_sRegisterName = "";
	uint32_t	m_uiPrice = 0;
	uint16_t	m_usTimeCount = 24;	// CHAR써도되지않나? 신영
public:
	uint16_t	GetTimeCount() { return m_usTimeCount; }
	uint32_t	GetPrice() { return m_uiPrice; }
	string		GetRegisterName() { return m_sRegisterName; }
};
class CItem
{
public:
	CItem() {}
	virtual ~CItem() { }
public:
	uint16_t		GetItemTypeID() { return m_itemTypeID; }
	uint16_t		GetEnhance()	{ return m_usEnhance; }
	uint16_t		GetSmelting()	{ return m_usSmelting; }
	uint16_t		GetLevel()		{ return m_usLevel; }
	string			GetName()		{ return m_sName; }
	CRegistInfo*	GetRegistInfo() { return m_pRegisterInfo; }
	RARITY			GetRarity()		{ return m_eRarity; }
	ITEM_TYPE		GetItemType()	{ return m_eItemType; }

protected:
	uint16_t	m_itemTypeID = 0;
	uint16_t	m_usEnhance = 0;
	uint16_t	m_usSmelting = 0;
	uint16_t	m_usLevel = 0;

	string		m_sName = "";

	RARITY		m_eRarity = RARITY::IDLE;

	ITEM_TYPE	m_eItemType = ITEM_TYPE::IDLE;


	CRegistInfo* m_pRegisterInfo = nullptr;

};

