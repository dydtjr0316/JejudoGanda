#include "stdafx.h"
#include "CItem.h"
#include "CInventory.h"
#include "CExpendablItem.h"
#include "CEquipmentItem.h"

CInventory::CInventory()
{
	for(int i = 0;i<MAX_LAYER;++i)
		m_vItemLst[i].resize(SLOT_IDLE);
}

void CInventory::InitItem(CItem* item, const uint16_t& addCount)
{
	INVEN_TYPE eItemType = item->GetType();
	float ResultWeight = m_fInvenWeight + item->GetWeight();
	// �̷��� �����س��� ���°� ��� 
	switch (eItemType)
	{
	case INVEN_TYPE::EQUIPMENT:
		if (m_usMaxSlotSize > m_usCurItemCount && m_fMaxInvenWeight >= ResultWeight)
		{
			for (int index = 0; index < m_usMaxSlotSize; ++index)
			{
				// ����ȯ short�� �ϴ°� ��� ����� 
				if (m_vItemLst[(uint32_t)eItemType][index] == nullptr)
				{
					m_vItemLst[(uint32_t)eItemType][index] = item;
					break;
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
				if (m_vItemLst[(uint32_t)eItemType][index]!=nullptr&&m_vItemLst[(uint32_t)eItemType][index]->GetName() == item->GetName())
				{
					bisExist = true;
					existIndex = index;
					break;
				}
			}
			if (bisExist)
			{
				int16_t count = dynamic_cast<CExpendablItem*>(m_vItemLst[(uint32_t)eItemType][existIndex])->GetItemCount()+ addCount;
				dynamic_cast<CExpendablItem*>(m_vItemLst[(uint32_t)eItemType][existIndex])->SetItemCount(count);
			}
			else
			{
				for (int index = 0; index < m_usMaxSlotSize; ++index)
				{
					// ����ȯ short�� �ϴ°� ��� ����� 
					if (m_vItemLst[(uint32_t)eItemType][index] == nullptr)
					{
						m_vItemLst[(uint32_t)eItemType][index] = item;
						break;
					}
				}
				m_fInvenWeight = ResultWeight;
				++m_usCurItemCount;
			}
		}
		break;
	}
	
	
}

void CInventory::DeleteItem(const uint16_t& slotindex, const uint16_t& deleteCount)
// item���� delete�ؾߵǴ� ��� �ִ��� ã�ƺ���
// ������ ���� �ֱ�
{
	// �� ������ �ڵ� nullptr ����� �ڵ�
	INVEN_TYPE eItemType = m_vItemLst[(uint32_t)m_eCurInvenType][slotindex]->GetType();
	float ResultWeight = m_fInvenWeight + m_vItemLst[(uint32_t)m_eCurInvenType][slotindex]->GetWeight();
	m_fInvenWeight -= m_vItemLst[(uint32_t)m_eCurInvenType][slotindex]->GetWeight();

	switch (m_eCurInvenType)
	{
	case INVEN_TYPE::EQUIPMENT:
		m_vItemLst[(uint32_t)m_eCurInvenType][slotindex] = nullptr;
		--m_usCurItemCount;
		break;
	case INVEN_TYPE::EXPENDABLES:
		CExpendablItem* expendableiTem = dynamic_cast<CExpendablItem*>(m_vItemLst[(short)m_eCurInvenType][slotindex]);
		if (expendableiTem->GetItemCount() - deleteCount > 0)
		{	// ������ŭ ���� 0���� Ŭ��
			expendableiTem->SetItemCount(expendableiTem->GetItemCount() - deleteCount);
		}
		else// 0�̵ɶ�
		{
			m_vItemLst[(uint32_t)m_eCurInvenType][slotindex] = nullptr;
			--m_usCurItemCount;	// �̺κ� ��Ȳ���� ���Ĺ�����
		}
	
		break;
	}

}

void CInventory::PrintAll()
{
	for (int i = 0; i < 2; ++i)
	{
		cout << "-------------------------------" << endl;
		switch (i)
		{
		case 0: cout << "���" << endl;
			cout << "-------------------------------" << endl;
			cout <<left <<setw(15)<<"�̸�"<<"����" << endl;
			cout << "-------------------------------" << endl;
			for (auto obj : m_vItemLst[i])
			{
				if (obj != nullptr)
				{
					cout << left << setw(15)<< (obj)->GetName() << "\t"
						<<(obj)->GetWeight() << "kg\t" << endl;
				}
			}
			break;
		case 1: cout << "�Ҹ�ǰ" << endl;
			cout << "-------------------------------" << endl;
			cout << left << setw(15) << "�̸�" << "����\t����" << endl;
			cout << "-------------------------------" << endl;
			for (auto obj : m_vItemLst[i])
			{
				if (obj != nullptr)
				{
					cout << left << setw(15) << (obj)->GetName() << "\t"
						<< dynamic_cast<CExpendablItem*>(obj)->GetItemCount() << "\t"
						<< obj->GetWeight() << "kg\t"  << endl;
				}
				
			}

		default:
			break;
		}
		cout << "-------------------------------" << endl;

	}
}

