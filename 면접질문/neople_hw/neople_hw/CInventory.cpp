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
				// ����ȯ short�� �ϴ°� ��� ����� 
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
					// ����ȯ short�� �ϴ°� ��� ����� 
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
	// �̷��� �����س��� ���°� ��� 
	
}

void CInventory::DeleteItem(const uint16_t& slotindex, const uint16_t& deleteCount)
// item���� delete�ؾߵǴ� ��� �ִ��� ã�ƺ���
// ������ ���� �ֱ�
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
		{	// ������ŭ ���� 0���� Ŭ��
			expendableiTem->SetItemCount(expendableiTem->GetItemCount() - deleteCount);
		}
		else// 0�̵ɶ�
		{
			item = nullptr;
			--m_usCurItemCount;	// �̺κ� ��Ȳ���� ���Ĺ�����
		}
	
		break;
	}
	m_fInvenWeight -= item->GetWeight();

}

