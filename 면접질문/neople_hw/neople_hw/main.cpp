#include "stdafx.h"
#include "CInventory.h"
#include "CItem.h"
int main()
{
	CInventory i;
	CItem* pitem = nullptr;

	pitem = new CItem(INVEN_TYPE::EQUIPMENT, 5.7, "���� ����");
	i.InitItem(pitem);

	pitem = new CItem(INVEN_TYPE::EXPENDABLES, 5.7, "������ ��");
	i.InitItem(pitem);

	pitem = new CItem(INVEN_TYPE::MATERIAL, 5.7, "��� ����");
	i.InitItem(pitem);

	pitem = new CItem(INVEN_TYPE::QUEST, 5.7, "���� ī��");
	i.InitItem(pitem);

	pitem = new CItem(INVEN_TYPE::SPECIAL, 5.7, "���� ����");
	i.InitItem(pitem);

	i.PrintAll();



	
}
