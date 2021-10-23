#pragma once
class CRegistInfo
{
public:
	CRegistInfo(const uint32_t& price, const string& name);
private:
	string		m_sRegisterName;
	uint32_t	m_uiPrice;
	uint16_t	m_usTimecount = 24;
};
class CItem
{
public:
	CItem(uint16_t t) { m_itemTypeID = t; }
	CItem(string name) {  m_sName = name; }
	CItem(string name, uint16_t level) { m_usLevel = level, m_sName = name; }
	CItem(string name, uint16_t level, uint16_t en, uint16_t sm, uint16_t type, RARITY r) 
	{
		m_usLevel = level, m_sName = name; m_usEnhance = en, m_usSmelting = sm; m_itemTypeID = type; m_eRarity = r;
	}
public:
	uint16_t	GetItemTypeID() { return m_itemTypeID; }
	uint16_t	GetEnhance()	{ return m_itemTypeID; }
	uint16_t	GetSmelting()	{ return m_itemTypeID; }
	uint16_t	GetLevel()		{ return m_itemTypeID; }

private:
	uint16_t	m_itemTypeID;
	uint16_t	m_usEnhance = 0;
	uint16_t	m_usSmelting = 0;
	uint16_t	m_usLevel;

	string		m_sName;

	RARITY		m_eRarity;

	CRegistInfo* m_pRegisterInfo = nullptr;

};

