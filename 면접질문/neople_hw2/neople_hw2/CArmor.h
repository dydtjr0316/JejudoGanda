#pragma once
#include "CEquipmentItem.h"
class CArmor :
    public CEquipmentItem
{
private:
	ITEM_C_TYPE m_eItemCType;

public:
	CArmor(const ITEM_A_TYPE& itemAType, const ITEM_B_TYPE& itemBType,
		const ITEM_C_TYPE& itemCType, const string& name, const uint16_t& level,
		const uint16_t& en, const uint16_t& sm, const RARITY& r, const ITEM_TYPE& itemType, CRegistInfo* regi);

	~CArmor(){}

public: // get
	ITEM_C_TYPE GetItemCType() { return m_eItemCType; }
};

