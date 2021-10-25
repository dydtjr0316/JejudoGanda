#include "stdafx.h"
#include "CInventory.h"
#include "CItem.h"
#include "CEquipmentItem.h"
#include "CExpendablItem.h"
int main()
{
	CInventory i;
	CItem* pitem = nullptr;

	pitem = new CEquipmentItem(INVEN_TYPE::EQUIPMENT, 5.7, "Æø¿­ ±¤°Ë A");
	i.InitItem(pitem);

	pitem = new CEquipmentItem(INVEN_TYPE::EQUIPMENT, 3.2, "Æø¿­ ±¤°Ë B");
	i.InitItem(pitem);

	pitem = new CEquipmentItem(INVEN_TYPE::EQUIPMENT, 4.8, "Æø¿­ ±¤°Ë C");
	i.InitItem(pitem);

	pitem = new CExpendablItem(INVEN_TYPE::EXPENDABLES, 1.7, "¸¶·ÂÀÇ ²É A", 2);
	i.InitItem(pitem);

	pitem = new CExpendablItem(INVEN_TYPE::EXPENDABLES, 2.7, "¸¶·ÂÀÇ ²É B", 15);
	i.InitItem(pitem);

	pitem = new CExpendablItem(INVEN_TYPE::EXPENDABLES, 3.7, "¸¶·ÂÀÇ ²É C", 20);
	i.InitItem(pitem);

	i.DeleteItem(0, 2);
	i.DeleteItem(1, 5);

	i.PrintAll();

}
