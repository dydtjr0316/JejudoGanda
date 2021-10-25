#pragma once
#include "CEquipmentItem.h"
class CWeapon :
    public CEquipmentItem
{
private:
    ITEM_C_TYPE m_eItemCType;
public:
	CWeapon(const ITEM_TYPE& itemType, const ITEM_A_TYPE& itemAType, const ITEM_B_TYPE& itemBType, const ITEM_C_TYPE& itemCType,
		const string& name, const uint16_t& level, const uint16_t& en, const uint16_t& sm, const RARITY& r, CRegistInfo* regi);

	~CWeapon(){}

public:
    ITEM_C_TYPE GetItemCType() { return m_eItemCType; }
	
	
};

