#pragma once
#include "CItem.h"
class CEquipmentItem :
    public CItem
{
protected:
    uint16_t	m_usEnhance = 0;
    uint16_t	m_usSmelting = 0;

public:
    CEquipmentItem() {};
    ~CEquipmentItem() {}

public:     //get
    uint16_t		GetEnhance() { return m_usEnhance; }
    uint16_t		GetSmelting() { return m_usSmelting; }
};

