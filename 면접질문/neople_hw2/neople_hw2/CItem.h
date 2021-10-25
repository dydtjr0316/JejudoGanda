#pragma once
class CRegistInfo
{
public:
	CRegistInfo() {};
	CRegistInfo(const uint32_t& price, const string& name)
	{
		m_sRegisterName = name; m_uiPrice = price;
	};
private:
	string		m_sRegisterName;
	uint32_t	m_uiPrice;
	uint16_t	m_usTimeCount = 24;
public:
	uint16_t	GetTimeCount() { return m_usTimeCount; }
	uint32_t	GetPrice() { return m_uiPrice; }
	string		GetRegisterName() { return m_sRegisterName; }
};
class CItem
{
public:
	CItem() {}
	CItem(const ITEM_A_TYPE& itemAType, const ITEM_B_TYPE& itemBType, const string& name, const uint16_t& level,/* const uint16_t& en, const uint16_t& sm,*/ const RARITY& r, CRegistInfo* regi)
	{
		m_eItemAType = itemAType, m_eItemBType = itemBType, m_usLevel = level, m_sName = name;/* m_usEnhance = en, m_usSmelting = sm;*/ m_eRarity = r;
		m_pRegisterInfo = regi;
	}
	virtual ~CItem() { }
public:
	uint16_t		GetItemTypeID() { return m_itemTypeID; }

	uint16_t		GetLevel()		{ return m_usLevel; }
	string			GetName()		{ return m_sName; }
	CRegistInfo*	GetRegistInfo() { return m_pRegisterInfo; }
	RARITY			GetRarity()		{ return m_eRarity; }
	ITEM_TYPE		GetItemType()	{ return m_eItemType; }
	ITEM_A_TYPE		GetItemAType()	{ return m_eItemAType; }
	ITEM_B_TYPE		GetItemBType()	{ return m_eItemBType; }
protected:
	uint16_t	m_itemTypeID;

	uint16_t	m_usLevel;

	string		m_sName;

	RARITY		m_eRarity;

	ITEM_TYPE	m_eItemType;
	ITEM_A_TYPE	m_eItemAType;
	ITEM_B_TYPE	m_eItemBType;

	CRegistInfo* m_pRegisterInfo = nullptr;

};

