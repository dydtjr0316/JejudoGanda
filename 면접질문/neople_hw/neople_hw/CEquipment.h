#pragma once
#include "CItem.h"
class CEquipment :
    public CItem
{
private: // bool 변수
    bool        m_bisEquip;         // 장착 여부

private: // 정수
    uint16_t    m_usEnhance;        // 강화
    uint32_t    m_uiSerialNo;       // 식별번호

private: // enum
    RARITY_TYPE m_eRarityType;      // 레어리티
};

