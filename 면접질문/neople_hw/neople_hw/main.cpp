#include "stdafx.h"
#include "CInventory.h"
#include "CItem.h"
int main()
{
	CInventory i;
	CItem* pitem = nullptr;

	pitem = new CItem(INVEN_TYPE::EQUIPMENT, 5.7, "Æø¿­ ±¤°Ë");
	i.InitItem(pitem);

	pitem = new CItem(INVEN_TYPE::EXPENDABLES, 5.7, "¸¶·ÂÀÇ ²É");
	i.InitItem(pitem);

	pitem = new CItem(INVEN_TYPE::MATERIAL, 5.7, "Çë°Ò Á¶°¢");
	i.InitItem(pitem);

	pitem = new CItem(INVEN_TYPE::QUEST, 5.7, "ÇåÅÍ Ä«µå");
	i.InitItem(pitem);

	pitem = new CItem(INVEN_TYPE::SPECIAL, 5.7, "³°Àº Áöµµ");
	i.InitItem(pitem);

	i.PrintAll();



	
}
