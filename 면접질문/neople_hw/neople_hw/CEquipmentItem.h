#pragma once
#include "CItem.h"
class CEquipmentItem :
    public CItem
{
private:
    bool        m_bisEquip;             // ���� ����

    uint16_t    m_usEnhance;            // ��ȭ

    EQUIPMENT_TYPE	m_eEquipmentType;	// �������
    OCCUPATION_TYPE	m_eOccupationType;	// �������� ����
    RARITY_TYPE m_eRarityType;          // ���Ƽ

public:
    CEquipmentItem(const INVEN_TYPE& type, const float& weight, const string& name) 
    { m_eType = type, m_fWeight = weight, m_sName = name; }
    ~CEquipmentItem() {}
};

