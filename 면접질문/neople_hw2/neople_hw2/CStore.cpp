#include "stdafx.h"
#include "CItem.h"
#include "CStore.h"
#include "CSortingMgr.h"

void CStore::InitItem(CItem* item)
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
			sort(m_vItemLst.begin(), m_vItemLst.end(), &CSortingMgr::IdleCmp);
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

void CStore::AscSorting()
{
	switch (m_eCurSortingType)
	{
	case SORTING_TYPE::ENHANCE:
		break;
	case SORTING_TYPE::SMELTING:
		break;
	case SORTING_TYPE::NAME:
		break;
	case SORTING_TYPE::LV:
		break;
	case SORTING_TYPE::TIMECOUNT:
		break;
	case SORTING_TYPE::GOLD:
		break;
	default:
		break;
	}
}

void CStore::DescSorting()
{
	switch (m_eCurSortingType)
	{
	case SORTING_TYPE::ENHANCE:
		break;
	case SORTING_TYPE::SMELTING:
		break;
	case SORTING_TYPE::NAME:
		break;
	case SORTING_TYPE::LV:
		break;
	case SORTING_TYPE::TIMECOUNT:
		break;
	case SORTING_TYPE::GOLD:
		break;
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
