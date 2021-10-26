#pragma once
#include "CItem.h"
class CExpendableItem :
    public CItem
{
public:
    CExpendableItem() {}
    CExpendableItem(const ITEM_TYPE& itemType,
        const string& name, const uint16_t& level, const uint16_t& en, const uint16_t& sm, const uint16_t& count,
        const RARITY& r, CRegistInfo* regi);
    ~CExpendableItem() {}

private:
    uint16_t m_usItemCount;
};

