#include "stdafx.h"
#include "CItem.h"
#include "CStore.h"

void CStore::InitItem(CItem* item, CRegistInfo* info)
{
	m_mItemLst.emplace(item, info);
}

CRegistInfo::CRegistInfo(string name, uint32_t price)
{
	m_sRegisterName = name;
	m_uiPrice = price;
}
