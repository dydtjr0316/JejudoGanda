#pragma once
#include "CEquipmentItem.h"
class CAcc :
    public CEquipmentItem
{
public:
	CAcc(const ITEM_TYPE& itemType, const ITEM_A_TYPE& itemAType, const ITEM_B_TYPE& itemBType,
		const string& name, const uint16_t& level, const uint16_t& en,
		const uint16_t& sm, const RARITY& r,  CRegistInfo* regi);
	~CAcc() {}


};

