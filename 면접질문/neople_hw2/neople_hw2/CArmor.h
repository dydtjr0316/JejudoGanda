#pragma once
#include "CEquipmentItem.h"
class CArmor :
    public CEquipmentItem
{
private:
	ITEM_C_TYPE m_eItemCType = ITEM_C_TYPE::IDLE;

public:
	CArmor(const ITEM_TYPE& itemType, const ITEM_A_TYPE& itemAType, const ITEM_B_TYPE& itemBType,
		const ITEM_C_TYPE& itemCType, const string& name, const uShort& level,
		const uShort& en, const uShort& sm, const RARITY& r, CRegistInfo* regi);

	~CArmor(){}

public: // get
	ITEM_C_TYPE GetItemCType() { return m_eItemCType; }
};

