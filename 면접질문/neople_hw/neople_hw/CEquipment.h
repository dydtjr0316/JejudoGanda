#pragma once
#include "CItem.h"
class CEquipment :
    public CItem
{
private: // bool ����
    bool        m_bisEquip;         // ���� ����

private: // ����
    uint16_t    m_usEnhance;        // ��ȭ
    uint32_t    m_uiSerialNo;       // �ĺ���ȣ

private: // enum
    RARITY_TYPE m_eRarityType;      // ���Ƽ
};

