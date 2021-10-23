#include "stdafx.h"
#include "CItem.h"
#include "CInventory.h"

void CInventory::InitItem(CItem* item)
{
	m_InvenLst[item->GetType()].emplace_back(item);
}

void CInventory::DeleteItem(CItem* item)
{
	m_InvenLst[item->GetType()].remove(item);
}
