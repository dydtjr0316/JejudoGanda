#pragma once
#include "stdafx.h"
#include "CItem.h"

bool Cmp_IDLE(CItem* a, CItem* b)
{
	/*switch (a->GetItemType())
	{
	case ITEM_TYPE::EQUIP:
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
		break;
	case ITEM_TYPE::EXPENDABLE:
		break;
	default:
		break;
	}*/
	return false;

}

bool Cmp_Enhance_ASC(CItem* a, CItem* b)
{
	//return a->GetEnhance() < b->GetEnhance();
	return false;
}
bool Cmp_Enhance_DESC(CItem* a, CItem* b)
{
	//return a->GetEnhance() > b->GetEnhance();
	return false;
}

bool Cmp_Smelting_ASC(CItem* a, CItem* b)
{
	//return a->GetSmelting() < b->GetSmelting();
	return false;
}
bool Cmp_Smelting_DESC(CItem* a, CItem* b)
{
	//return a->GetSmelting() > b->GetSmelting();
	return false;
}

bool Cmp_Name_ASC(CItem* a, CItem* b)
{
	return a->GetName() < b->GetName();
}
bool Cmp_Name_DESC(CItem* a, CItem* b)
{
	return a->GetName() > b->GetName();
}

bool Cmp_Level_ASC(CItem* a, CItem* b)
{
	return a->GetLevel() < b->GetLevel();
}
bool Cmp_Level_DESC(CItem* a, CItem* b)
{
	return a->GetLevel() > b->GetLevel();
}

bool Cmp_TimeCount_ASC(CItem* a, CItem* b)
{
	return a->GetRegistInfo()->GetTimeCount() < b->GetRegistInfo()->GetTimeCount();
}
bool Cmp_TimeCount_DESC(CItem* a, CItem* b)
{
	return a->GetRegistInfo()->GetTimeCount() > b->GetRegistInfo()->GetTimeCount();
}

bool Cmp_Price_ASC(CItem* a, CItem* b)
{
	return a->GetRegistInfo()->GetPrice() < b->GetRegistInfo()->GetPrice();
}
bool Cmp_Price_DESC(CItem* a, CItem* b)
{
	return a->GetRegistInfo()->GetPrice() > b->GetRegistInfo()->GetPrice();
}


