#pragma once
class CRegistInfo
{
public:
	CRegistInfo(const uInt& price, const string& name)
	{
		m_sRegisterName = name; m_uiPrice = price;
	};
private:
	string		m_sRegisterName = "";
	uInt		m_uiPrice = 0;
	uShort		m_usTimeCount = 24;	// CHAR써도되지않나? 신영
public:
	uShort		GetTimeCount() { return m_usTimeCount; }
	uInt		GetPrice() { return m_uiPrice; }
	string		GetRegisterName() { return m_sRegisterName; }
};
class CItem
{
public:
	CItem() {}
	virtual ~CItem() { }
public:
	uShort			GetItemTypeID() { return m_itemTypeID; }
	uShort			GetEnhance()	{ return m_usEnhance; }
	uShort			GetSmelting()	{ return m_usSmelting; }
	uShort			GetLevel()		{ return m_usLevel; }
	string			GetName()		{ return m_sName; }
	CRegistInfo*	GetRegistInfo() { return m_pRegisterInfo; }
	RARITY			GetRarity()		{ return m_eRarity; }
	ITEM_TYPE		GetItemType()	{ return m_eItemType; }

protected:
	uShort		m_itemTypeID = 0;
	uShort		m_usEnhance = 0;
	uShort		m_usSmelting = 0;
	uShort		m_usLevel = 0;

	string		m_sName = "";

	RARITY		m_eRarity = RARITY::IDLE;

	ITEM_TYPE	m_eItemType = ITEM_TYPE::IDLE;


	CRegistInfo* m_pRegisterInfo = nullptr;

};

