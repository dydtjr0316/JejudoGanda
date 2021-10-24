#pragma once
#include "CItem.h"
class CArmor :
    public CItem
{
private:
	ITEM_C_TYPE m_eItemCType;
public:

	ITEM_C_TYPE GetItemCType() { return m_eItemCType; }
	CArmor(const ITEM_A_TYPE& itemAType, const ITEM_B_TYPE& itemBType, const ITEM_C_TYPE& itemCType, const string& name, const uint16_t& level, const uint16_t& en, const uint16_t& sm, const RARITY& r, CRegistInfo* regi)
	{
		m_eItemAType = itemAType, m_eItemBType = itemBType, m_eItemCType = itemCType;
		m_usLevel = level, m_sName = name; m_usEnhance = en, m_usSmelting = sm; m_eRarity = r;
		m_pRegisterInfo = regi;
	}
};

