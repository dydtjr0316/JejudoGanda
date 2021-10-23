#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <deque>
#include <chrono>
using namespace std;
using namespace std::chrono;
enum class TYPE
{
	WEAPON, ARMOR, ACC, SPECIAL_EQUIP
};
enum class WEAPON_TYPE
{
	A, B, C, D, E, F, G
};
enum class WEAPON_A_TYPE
{
	A, B, C, D, E, F, G
};
enum class WEAPON_B_TYPE
{
	A, B, C, D, E, F, G
};
enum class ARMOR_TYPE
{
	A, B, C, D, E, F, G
};
enum class ACC_TYPE
{
	A, B, C, D, E, F, G
};
enum class SPECIAL_EQUIP_TYPE
{
	A, B, C, D, E, F, G
};
enum class RARITY
{
	ENTIRE, COM, UNCOM, RARE, UNIQ, REGENDARY, EPIC, END
};
enum class SORTING_TYPE
{
	ENHANCE, SMELTING, NAME, LV, TIMECOUNT, GOLD, IDLE
};
enum class SORTING_ORDER
{
	IDLE, ASC/*오름*/, DESC/*내림*/
};