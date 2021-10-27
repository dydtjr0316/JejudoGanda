#include "stdafx.h"
#include "CItem.h"
#include "CInventory.h"
#include "CExpendablItem.h"
#include "CEquipmentItem.h"

CInventory::CInventory()
{
	for (uInt i = 0; i < MAX_LAYER; ++i)
	{
		m_vItemLst[i].resize(SLOT_IDLE);
	}
}

void CInventory::InitItem(CItem* item, const uShort& addCount)
{
	INVEN_TYPE eItemType = item->GetType();
	float ResultWeight = m_fInvenWeight + item->GetWeight();

	switch (eItemType)
	{
	case INVEN_TYPE::EQUIPMENT:
		if (m_usMaxSlotSize > m_usCurItemCount && m_fMaxInvenWeight >= ResultWeight)
		{
			for (uInt index = 0; index < m_usMaxSlotSize; ++index)
			{
				// ����ȯ short�� �ϴ°� ��� ����� 
				if (m_vItemLst[(uInt)eItemType][index] == nullptr)
				{
					m_vItemLst[(uInt)eItemType][index] = item;
					break;
				}
			}
		}
		break;
	case INVEN_TYPE::EXPENDABLES:
		bool bisExist = false;
		uShort existIndex = 0;
		if (m_usMaxSlotSize > m_usCurItemCount && m_fMaxInvenWeight >= ResultWeight)
		{
			for (uInt index = 0; index < m_usMaxSlotSize; ++index)
			{
				if (m_vItemLst[(uInt)eItemType][index] != nullptr && m_vItemLst[(uInt)eItemType][index]->GetName() == item->GetName())
				{
					bisExist = true;
					existIndex = index;
					break;
				}
			}
			if (bisExist)
			{
				uShort count = dynamic_cast<CExpendablItem*>(m_vItemLst[(uInt)eItemType][existIndex])->GetItemCount() + addCount;
				dynamic_cast<CExpendablItem*>(m_vItemLst[(uInt)eItemType][existIndex])->SetItemCount(count);
			}
			else
			{
				for (uInt index = 0; index < m_usMaxSlotSize; ++index)
				{
					// ����ȯ short�� �ϴ°� ��� ����� 
					if (m_vItemLst[(uInt)eItemType][index] == nullptr)
					{
						m_vItemLst[(uInt)eItemType][index] = item;
						break;
					}
				}
			}
		}
		break;
	}
	m_fInvenWeight = ResultWeight;
	++m_usCurItemCount;
	
}

void CInventory::DeleteItem(const uShort& slotindex, const uShort& deleteCount)
// item���� delete�ؾߵǴ� ��� �ִ��� ã�ƺ���
// ������ ���� �ֱ�
{
	// �� ������ �ڵ� nullptr ����� �ڵ�
	INVEN_TYPE eItemType = m_vItemLst[(uInt)m_eCurInvenType][slotindex]->GetType();
	float ResultWeight = m_fInvenWeight + m_vItemLst[(uInt)m_eCurInvenType][slotindex]->GetWeight();
	m_fInvenWeight -= m_vItemLst[(uInt)m_eCurInvenType][slotindex]->GetWeight();

	switch (m_eCurInvenType)
	{
	case INVEN_TYPE::EQUIPMENT:
		m_vItemLst[(uInt)m_eCurInvenType][slotindex] = nullptr;
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
			m_vItemLst[(uInt)m_eCurInvenType][slotindex] = nullptr;
			--m_usCurItemCount;	// �̺κ� ��Ȳ���� ���Ĺ�����
		}
	
		break;
	}

}

void CInventory::PrintAll()
{
	for (uInt i = 1; i < 3; ++i)
	{
		cout << "-------------------------------" << endl;
		switch (i)
		{
		case 1: cout << "���" << endl;
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
		case 2: cout << "�Ҹ�ǰ" << endl;
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

