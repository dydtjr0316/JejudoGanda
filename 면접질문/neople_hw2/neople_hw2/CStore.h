#pragma once
#include "CItem.h"

class CItem;
class CRegistInfo;
struct mySort
{
	
	bool operator()(pair<CItem*, CRegistInfo*>  a, pair<CItem*, CRegistInfo*> b) const
	{
		if (a.first->m_usEnhance == b.first->m_usEnhance)
		{
			return a.first->m_usSmelting < b.first->m_usSmelting;
		}
		else
			a.first->m_usEnhance < b.first->m_usEnhance;
	}
};
class CRegistInfo
{
public:
	CRegistInfo(string name, uint32_t price);
//private:
	string		m_sRegisterName;
	uint32_t	m_uiPrice;
	uint16_t	m_usTimecount = 24;
};
class CStore
{
private:
	vector<pair<CItem*, CRegistInfo*>> m_vItemLst;
	multimap<CItem*, CRegistInfo*> m_mItemLst;
	
public:
	void InitItem(CItem* item, CRegistInfo* info);
	void Delete(CItem* item, CRegistInfo* info);
public:
	multimap<CItem*, CRegistInfo*> GetItemLst() { return m_mItemLst; }
};

