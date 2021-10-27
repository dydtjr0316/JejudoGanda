#include "stdafx.h"
#include "CItem.h"
#include "CWeapon.h"
#include "CArmor.h"
#include "CAcc.h"
#include "CStore.h"
#include "CSortingMgr.h"
#include "CExpendableItem.h"
#include "compare.h"
void CStore::Init()
{
	CRegistInfo* pRegi = nullptr;
	CItem* pObj = nullptr;
	for (int i = 0; i < RAND10+10; i++)
	{
		pRegi = new CRegistInfo(RAND100000, "용석");
		pObj = new CWeapon(ITEM_TYPE::EQUIP, ITEM_A_TYPE::WEAPON, (ITEM_B_TYPE)(rand()%(int)ITEM_B_TYPE::END), ITEM_C_TYPE::WEAPON_DARKKNIGHT_KNIFE,
			"폭열 광검"+ to_string(i), RAND100, RAND10, RAND10, RARITY::RARE,  pRegi);
		m_vItemLst.emplace_back(pObj);
	}
	for (int i = 0; i < RAND10 + 10; i++)
	{
		pRegi = new CRegistInfo(RAND100000, "덕기");
		pObj = new CWeapon(ITEM_TYPE::EQUIP, ITEM_A_TYPE::WEAPON, ITEM_B_TYPE::WEAPON_DARKKNIGHT, ITEM_C_TYPE::WEAPON_DARKKNIGHT_SWORD,
			"오키드", RAND10+55, RAND10, RAND10, RARITY::UNIQ,  pRegi);
		m_vItemLst.emplace_back(pObj);
	}
	for (int i = 0; i < RAND10 + 10; i++)
	{
		pRegi = new CRegistInfo(RAND100000, "조사장");
		pObj = new CArmor(ITEM_TYPE::EQUIP, ITEM_A_TYPE::ARMOR, ITEM_B_TYPE::ARMOR_LEATHER, ITEM_C_TYPE::ARMOR_LEATHER_SHIRT,
			"전장의 매", RAND100, RAND10, RAND10, RARITY::REGENDARY,  pRegi);
		m_vItemLst.emplace_back(pObj);
	}
	for (int i = 0; i < RAND10 + 10; i++)
	{
		pRegi = new CRegistInfo(RAND100000, "욱이");
		pObj = new CExpendableItem(ITEM_TYPE::EXPENDABLE,
			"추출기", RAND100, 0, 0,RAND10, RARITY::RARE,  pRegi);
		m_vItemLst.emplace_back(pObj);
	}
	for (int i = 0; i < RAND10 + 10; i++)
	{
		pRegi = new CRegistInfo(RAND100000, "윤사장");
		pObj = new CAcc(ITEM_TYPE::EQUIP, ITEM_A_TYPE::ACC, ITEM_B_TYPE::ACC_NECK,
			"왕가의 목걸이", RAND100, RAND10, RAND10, RARITY::UNIQ,  pRegi);
		m_vItemLst.emplace_back(pObj);
	}
	for (int i = 0; i < RAND10 + 10; i++)
	{
		pRegi = new CRegistInfo(RAND100000, "영우");
		pObj = new CExpendableItem(ITEM_TYPE::EXPENDABLE,
			"코인", RAND100, 0, 0, RAND10, RARITY::UNCOM, pRegi);
		m_vItemLst.emplace_back(pObj);
	}
	
	Sorting_IDLE();
	

}

void CStore::SearchName(const string& name, const uShort& minLv, const uShort& maxLv, const RARITY& rarity)
{
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "이름, 레벨, 타입 검색" << endl;
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "강화\t재련\t" << left << setw(15) << "이름" << "Lv\t마감\t가격\t판매자" << endl;
	cout << "-------------------------------------------------------------------------" << endl;
	for (auto& obj : m_vItemLst)
	{
		if (obj->GetName() == name &&
			obj->GetLevel() >= minLv &&
			obj->GetLevel() <= maxLv &&
			obj->GetRarity() == rarity)
			Print(obj);
	}
	cout << endl;
}

void CStore::Search_ExpendableItems()
{
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "소모품 검색" << endl;
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "강화\t재련\t" << left << setw(15) << "이름" << "Lv\t마감\t가격\t판매자" << endl;
	cout << "-------------------------------------------------------------------------" << endl;
	for (auto& obj : m_vItemLst)
	{
		if (obj->GetItemType() == ITEM_TYPE::EXPENDABLE)
			Print(obj);
	}
	cout << endl;
}

void CStore::Search_Atype(const ITEM_A_TYPE& a)
{
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "A타입으로 검색" << endl;
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "강화\t재련\t" << left << setw(15) << "이름" << "Lv\t마감\t가격\t판매자" << endl;
	cout << "-------------------------------------------------------------------------" << endl;
	for (auto& obj : m_vItemLst)
	{
		if (obj->GetItemType() == ITEM_TYPE::EQUIP && dynamic_cast<CEquipmentItem*>(obj)->GetItemAType() == a)
			Print(obj);
	}
	cout << endl;
}

void CStore::Search_Btype(const ITEM_A_TYPE& a, const ITEM_B_TYPE& b)
{
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "B타입으로 검색" << endl;
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "강화\t재련\t" << left << setw(15) << "이름" << "Lv\t마감\t가격\t판매자" << endl;
	cout << "-------------------------------------------------------------------------" << endl;

	for (auto& obj : m_vItemLst)
	{
		if (obj->GetItemType() == ITEM_TYPE::EQUIP&& dynamic_cast<CEquipmentItem*>(obj)->GetItemBType() == b)
			Print(obj);
	}
	cout << endl;
}

void CStore::Search_Ctype(const ITEM_A_TYPE& a, const ITEM_B_TYPE& b, const ITEM_C_TYPE& c)
{
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "C타입으로 검색" << endl;
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "강화\t재련\t"<< left << setw(15) << "이름"<<	"Lv\t마감\t가격\t판매자" << endl;
	cout << "-------------------------------------------------------------------------" << endl;
	switch (c)
	{
	case ITEM_C_TYPE::WEAPON_DARKKNIGHT_SWORD:
	case ITEM_C_TYPE::WEAPON_DARKKNIGHT_KNIFE:
		for (auto& obj : m_vItemLst)
		{
			if (obj->GetItemType() == ITEM_TYPE::EQUIP&&
				dynamic_cast<CEquipmentItem*>(obj)->GetItemAType() == a &&
				dynamic_cast<CEquipmentItem*>(obj)->GetItemBType() == b &&
				dynamic_cast<CWeapon*>(obj)->GetItemCType() == c)
				Print(obj);
		}
		break;
	case ITEM_C_TYPE::ARMOR_LEATHER_SHIRT:
	case ITEM_C_TYPE::ARMOR_LEATHER_SHOES:
		for (auto& obj : m_vItemLst)
		{
			if (obj->GetItemType() == ITEM_TYPE::EQUIP &&
				dynamic_cast<CEquipmentItem*>(obj)->GetItemAType() == a &&
				dynamic_cast<CEquipmentItem*>(obj)->GetItemBType() == b &&
				dynamic_cast<CArmor*>(obj)->GetItemCType() == c)
				Print(obj);
		}
		break;
	default:
		break;
	}
}

void CStore::AddItem(CItem* item)
{
	m_vItemLst.emplace_back(item);
}

void CStore::Sorting(const SORTING_TYPE& type)
{
	ReadySorting(type);
	switch (m_eCurSortingOrder)
	{
	case SORTING_ORDER::IDLE:	// 이거 필요한가 보기
		if(m_eCurSortingType == SORTING_TYPE::IDLE)
			sort(m_vItemLst.begin(), m_vItemLst.end(), Cmp_IDLE);
		break;
	case SORTING_ORDER::ASC:
		AscSorting();
		break;
	case SORTING_ORDER::DESC:
		DescSorting();
		break;
	default:
		break;
	}
}

void CStore::Sorting_IDLE()
{
	sort(m_vItemLst.begin(), m_vItemLst.end(), Cmp_IDLE);
}

void CStore::AscSorting()	
{
	switch (m_eCurSortingType)
	{
	case SORTING_TYPE::ENHANCE:
		sort(m_vItemLst.begin(), m_vItemLst.end(), Cmp_Enhance_ASC); break;
	case SORTING_TYPE::SMELTING:
		sort(m_vItemLst.begin(), m_vItemLst.end(), Cmp_Smelting_ASC); break;
	case SORTING_TYPE::NAME:
		sort(m_vItemLst.begin(), m_vItemLst.end(), Cmp_Name_ASC); break;
	case SORTING_TYPE::LV:
		sort(m_vItemLst.begin(), m_vItemLst.end(), Cmp_Level_ASC); break;
	case SORTING_TYPE::TIMECOUNT:
		sort(m_vItemLst.begin(), m_vItemLst.end(), Cmp_TimeCount_ASC); break;
	case SORTING_TYPE::Price:
		sort(m_vItemLst.begin(), m_vItemLst.end(), Cmp_Price_ASC); break;
	default:
		break;
	}
}

void CStore::DescSorting()
{
	switch (m_eCurSortingType)
	{
	case SORTING_TYPE::ENHANCE:
		sort(m_vItemLst.begin(), m_vItemLst.end(), Cmp_Enhance_DESC); break;
	case SORTING_TYPE::SMELTING:
		sort(m_vItemLst.begin(), m_vItemLst.end(), Cmp_Smelting_DESC); break;
	case SORTING_TYPE::NAME:
		sort(m_vItemLst.begin(), m_vItemLst.end(), Cmp_Name_DESC); break;
	case SORTING_TYPE::LV:
		sort(m_vItemLst.begin(), m_vItemLst.end(), Cmp_Level_DESC); break;
	case SORTING_TYPE::TIMECOUNT:
		sort(m_vItemLst.begin(), m_vItemLst.end(), Cmp_TimeCount_DESC); break;
	case SORTING_TYPE::Price:
		sort(m_vItemLst.begin(), m_vItemLst.end(), Cmp_Price_DESC); break;
	default:
		break;
	}
}

void CStore::ReadySorting(const SORTING_TYPE& type)
{
	if (m_eCurSortingType != type)
	{
		m_eCurSortingType = type;
		m_eCurSortingOrder = SORTING_ORDER::IDLE;
	}
	switch (m_eCurSortingOrder)
	{
	case SORTING_ORDER::IDLE:
		m_eCurSortingOrder = SORTING_ORDER::ASC;
		break;
	case SORTING_ORDER::ASC:
		m_eCurSortingOrder = SORTING_ORDER::DESC;
		break;
	case SORTING_ORDER::DESC:
		m_eCurSortingOrder = SORTING_ORDER::ASC;
		break;
	default:
		break;
	}
}

void CStore::Print(CItem* item)
{
	cout << (item)->GetEnhance() << "\t" <<
		item->GetSmelting() << "\t";


	cout << left << setw(15) << item->GetName() << item->GetLevel() << "\t" << item->GetRegistInfo()->GetTimeCount() << "\t"
		<< item->GetRegistInfo()->GetPrice() << "\t" << item->GetRegistInfo()->GetRegisterName() << endl << endl;
}

void CStore::PrintALL()
{
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "전체 검색" << endl;
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "강화\t재련\t" << left << setw(15) << "이름" << "Lv\t마감\t가격\t판매자" << endl;
	cout << "-------------------------------------------------------------------------" << endl;
	for (auto& item : m_vItemLst)
	{
		cout << (item)->GetEnhance() << "\t" <<(item)->GetSmelting() << "\t";
		cout << left << setw(15) << item->GetName() << item->GetLevel() << "\t" << item->GetRegistInfo()->GetTimeCount() << "\t"
			<< item->GetRegistInfo()->GetPrice() << "\t" << item->GetRegistInfo()->GetRegisterName() << endl;
	}
	cout << endl;
}
