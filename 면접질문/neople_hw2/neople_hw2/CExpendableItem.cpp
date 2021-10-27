#include "stdafx.h"
#include "CExpendableItem.h"

CExpendableItem::CExpendableItem(const ITEM_TYPE& itemType,
	const string& name, const uShort& level, const uShort& en, const uShort& sm, const uShort& count,
	const RARITY& r, CRegistInfo* regi)
{
	m_eItemType = itemType,
	m_usLevel = level, m_sName = name; m_usEnhance = en, m_usSmelting = sm;
	m_eRarity = r;m_pRegisterInfo = regi;
}
