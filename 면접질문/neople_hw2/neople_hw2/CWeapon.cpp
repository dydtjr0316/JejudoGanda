#include "stdafx.h"
#include "CWeapon.h"

CWeapon::CWeapon(const ITEM_TYPE& itemType, const ITEM_A_TYPE& itemAType, const ITEM_B_TYPE& itemBType, const ITEM_C_TYPE& itemCType,
	const string& name, const uShort& level, const uShort& en, const uShort& sm, const RARITY& r,  CRegistInfo* regi)
{
	m_eItemAType = itemAType, m_eItemBType = itemBType, m_eItemCType = itemCType;
	m_usLevel = level, m_sName = name; m_usEnhance = en, m_usSmelting = sm; m_eRarity = r;
	m_pRegisterInfo = regi; m_eItemType = itemType;
}
