#include "stdafx.h"
#include "CItem.h"
#include "CInventory.h"

void CInventory::InitItem(CItem* item)
{
	random_device rd;
	mt19937 mersenne(rd());
	uniform_int_distribution<> die(0, UINT16_MAX);
	uint16_t tempID = (uint16_t)die(mersenne);

	if (m_usMaxSlotSize > m_ItemLst_ID[item->GetType()].size())
	{
		m_ItemLst_ID[item->GetType()].emplace(tempID, item);
	}
}

void CInventory::DeleteItem(const uint16_t& itemid)
{
	if (m_ItemLst_ID[m_eCurInvenType].count(itemid) != 0)
		m_ItemLst_ID[m_eCurInvenType].erase(m_ItemLst_ID[m_eCurInvenType].find(itemid));
}

