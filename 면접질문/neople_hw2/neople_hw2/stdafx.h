#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <deque>
#include <string>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace std::chrono;

#define RAND100000 rand()%100000
#define RAND100 rand()%100
#define RAND10 rand()%10
enum class ITEM_TYPE
{
	IDLE, EQUIP,EXPENDABLE, END
};

enum class ITEM_A_TYPE
{
	IDLE,
	WEAPON, 
	ARMOR, 
	ACC,
	END
};
enum class ITEM_B_TYPE
{
	IDLE,

	WEAPON_DARKKNIGHT,

	ARMOR_LEATHER,

	ACC_NECK, ACC_RING
	
	, END
};
enum class ITEM_C_TYPE
{
	IDLE,
	WEAPON_DARKKNIGHT_SWORD, WEAPON_DARKKNIGHT_KNIFE,

	ARMOR_LEATHER_SHIRT, ARMOR_LEATHER_SHOES,

	END
};
enum class RARITY
{
	IDLE,ENTIRE, COM, UNCOM, RARE, UNIQ, REGENDARY, EPIC, END
};
enum class SORTING_TYPE
{
	IDLE, ENHANCE, SMELTING, NAME, LV, TIMECOUNT, Price,  END
};
enum class SORTING_ORDER
{
	IDLE, ASC/*오름*/, DESC/*내림*/, END
};