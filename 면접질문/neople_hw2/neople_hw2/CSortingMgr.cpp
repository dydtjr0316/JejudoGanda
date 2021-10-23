#include "stdafx.h"
#include "CSortingMgr.h"
bool cmp(CItem* a, CItem* b)
{
	
}

bool CSortingMgr::IdleCompare(CItem* a, CItem* b)
{
	uint16_t a_Enhance = a->GetEnhance();
	uint16_t b_Enhance = b->GetEnhance();
	uint16_t a_Smelting = a->GetSmelting();
	uint16_t b_Smelting = b->GetSmelting();

	if (a_Enhance == b_Enhance)
	{
		return a_Smelting < b_Smelting;
	}
	else
		return a_Enhance < b_Enhance;
}
