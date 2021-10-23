#pragma once
#include "CItem.h"
enum class SORTING_TYPE
{
	ENHANCE, SMELTING, NAME, LV, TIMECOUNT, GOLD
};
enum class SORTING_ORDER
{
	IDLE, DESC/*내림*/, ASC/*오름*/
};
class CItem;
class CSortingMgr
{
public:
	bool IdleCmp(CItem* a, CItem* b);
};

