#pragma once
#include "CItem.h"
class CEquipmentItem :
    public CItem
{

public:
    CEquipmentItem() {};
    ~CEquipmentItem() {}
public:
    ITEM_A_TYPE		GetItemAType() { return m_eItemAType; }
    ITEM_B_TYPE		GetItemBType() { return m_eItemBType; }
protected:
    ITEM_A_TYPE	m_eItemAType = ITEM_A_TYPE::IDLE;
    ITEM_B_TYPE	m_eItemBType = ITEM_B_TYPE::IDLE;
};

