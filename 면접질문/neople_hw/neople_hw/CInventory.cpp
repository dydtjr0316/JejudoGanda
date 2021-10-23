#include "stdafx.h"
#include "CItem.h"
#include "CInventory.h"
#include "CExpendablItem.h"

CInventory::CInventory()
{
	m_vItemLst->resize(SLOT_IDLE);
}

void CInventory::InitItem(CItem* item, const uint16_t& addCount)
{
	INVEN_TYPE eItemType = item->GetType();
	float ResultWeight = m_fInvenWeight + item->GetWeight();
	switch (eItemType)
	{
	case INVEN_TYPE::EQUIPMENT:
		if (m_usMaxSlotSize > m_usCurItemCount && m_fMaxInvenWeight >= ResultWeight)
		{
			for (int index = 0; index < m_usMaxSlotSize; ++index)
			{
				// 형변환 short로 하는거 어떤지 물어보기 
				if (m_vItemLst[(short)eItemType][index] == nullptr)
				{
					m_vItemLst[(short)eItemType][index] = item;
				}
			}
			m_fInvenWeight = ResultWeight;
			++m_usCurItemCount;
		}
		break;
	case INVEN_TYPE::EXPENDABLES:
		bool bisExist = false;
		int16_t existIndex = 0;
		if (m_usMaxSlotSize > m_usCurItemCount && m_fMaxInvenWeight >= ResultWeight)
		{
			for (int index = 0; index < m_usMaxSlotSize; ++index)
			{
				if (m_vItemLst[(short)eItemType][index]->GetName() == item->GetName())
				{
					bisExist = true;
					existIndex = index;
					break;
				}
			}
			if (bisExist)
			{
				int16_t count = dynamic_cast<CExpendablItem*>(m_vItemLst[(short)eItemType][existIndex])->GetItemCount()+ addCount;
				dynamic_cast<CExpendablItem*>(m_vItemLst[(short)eItemType][existIndex])->SetItemCount(count);
			}
			else
			{
				for (int index = 0; index < m_usMaxSlotSize; ++index)
				{
					// 형변환 short로 하는거 어떤지 물어보기 
					if (m_vItemLst[(short)eItemType][index] == nullptr)
					{
						m_vItemLst[(short)eItemType][index] = item;
					}
				}
				m_fInvenWeight = ResultWeight;
				++m_usCurItemCount;
			}
		}
		break;
	}
	// 이렇게 선언해놓고 쓰는거 어떤지 
	
}

void CInventory::DeleteItem(const uint16_t& slotindex, const uint16_t& deleteCount)
// item으로 delete해야되는 경우 있는지 찾아보기
// 갯수로 삭제 넣기
{
	CItem* item = m_vItemLst[(short)m_eCurInvenType][slotindex];
	INVEN_TYPE eItemType = item->GetType();
	float ResultWeight = m_fInvenWeight + item->GetWeight();
	switch (m_eCurInvenType)
	{
	case INVEN_TYPE::EQUIPMENT:
		item = nullptr;
		--m_usCurItemCount;
		break;
	case INVEN_TYPE::EXPENDABLES:
		CExpendablItem* expendableiTem = dynamic_cast<CExpendablItem*>(item);
		if (expendableiTem->GetItemCount() - deleteCount > 0)
		{	// 갯수만큼 빼도 0보다 클때
			expendableiTem->SetItemCount(expendableiTem->GetItemCount() - deleteCount);
		}
		else// 0이될때
		{
			item = nullptr;
			--m_usCurItemCount;	// 이부분 상황봐서 합쳐버리기
		}
	
		break;
	}
	m_fInvenWeight -= item->GetWeight();

}

