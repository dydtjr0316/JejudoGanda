#pragma once
class CItem
{
public:
	CItem(uint16_t t) { m_itemtypeID = t; }
	CItem(string name) {  m_sName = name; }
	CItem(string name, uint16_t level) { m_usLevel = level, m_sName = name; }
	CItem(string name, uint16_t level, uint16_t en, uint16_t sm, uint16_t type, RARITY r) 
	{
		m_usLevel = level, m_sName = name; m_usEnhance = en, m_usSmelting = sm; m_itemtypeID = type; m_eRarity = r;
	}
//private:
	uint16_t	m_itemtypeID;
	uint16_t	m_usEnhance = 0;
	uint16_t	m_usSmelting = 0;
	uint16_t	m_usLevel;
	string		m_sName;
	RARITY		m_eRarity;
};

