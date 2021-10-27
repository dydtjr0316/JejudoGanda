#pragma once
#include "CItem.h"
class CExpendableItem :
    public CItem
{
public:
    CExpendableItem() {}
    CExpendableItem(const ITEM_TYPE& itemType,
        const string& name, const uShort& level, const uShort& en, const uShort& sm, const uShort& count,
        const RARITY& r, CRegistInfo* regi);
    ~CExpendableItem() {}

private:
    uShort m_usItemCount = 0;
};

