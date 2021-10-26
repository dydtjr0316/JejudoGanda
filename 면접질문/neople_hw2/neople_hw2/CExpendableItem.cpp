#include "stdafx.h"
#include "CExpendableItem.h"

CExpendableItem::CExpendableItem(const ITEM_TYPE& itemType,
	const string& name, const uint16_t& level, const uint16_t& en, const uint16_t& sm, const uint16_t& count,
	const RARITY& r, CRegistInfo* regi)
{
	m_eItemType = itemType,
	m_usLevel = level, m_sName = name; m_usEnhance = en, m_usSmelting = sm;
	m_eRarity = r;m_pRegisterInfo = regi;
}
