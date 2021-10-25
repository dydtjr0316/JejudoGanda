#pragma once
#include "CItem.h"
class CEquipmentItem :
    public CItem
{
private:
    bool        m_bisEquip;             // 장착 여부

    uint16_t    m_usEnhance;            // 강화

    EQUIPMENT_TYPE	m_eEquipmentType;	// 장비종류
    OCCUPATION_TYPE	m_eOccupationType;	// 장착가능 직업
    RARITY_TYPE m_eRarityType;          // 레어리티

public:
    CEquipmentItem(const INVEN_TYPE& type, const float& weight, const string& name) 
    { m_eType = type, m_fWeight = weight, m_sName = name; }
    ~CEquipmentItem() {}
};

