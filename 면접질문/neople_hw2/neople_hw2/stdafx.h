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

#define RAND100000 rand()%100000
#define RAND100 rand()%100
#define RAND10 rand()%10

enum class ITEM_A_TYPE
{
	WEAPON, 

	ARMOR, 

	ACC, 
};
enum class ITEM_B_TYPE
{
	WEAPON_DARKKNIGHT,

	ARMOR_LEATHER,

	ACC_NECK, ACC_RING
};
enum class ITEM_C_TYPE
{
	WEAPON_DARKKNIGHT_SWORD, WEAPON_DARKKNIGHT_KNIFE,

	ARMOR_LEATHER_SHIRT, ARMOR_LEATHER_SHOES,
};
//enum class WEAPON_TYPE
//{
//	A, B, C, D, E
//};
//enum class WEAPON_A_TYPE
//{
//	A, B, C, D, E
//};
//enum class WEAPON_B_TYPE
//{
//	A, B, C, D, E
//};
//enum class ARMOR_TYPE
//{
//	A, B, C, D, E
//};
//enum class ARMOR_A_TYPE
//{
//	A, B, C, D, E
//};
//enum class ARMOR_B_TYPE
//{
//	A, B, C, D, E
//};
//enum class ACC_TYPE
//{
//	A, B, C, D, E
//};
//enum class ACC_A_TYPE
//{
//	A, B, C, D, E
//};
//enum class ACC_B_TYPE
//{
//	A, B, C, D, E
//};
//enum class SPECIAL_EQUIP_TYPE
//{
//	A, B, C, D, E
//};
//enum class SPECIAL_EQUIP_A_TYPE
//{
//	A, B, C, D, E
//};
//enum class SPECIAL_EQUIP_B_TYPE
//{
//	A, B, C, D, E
//};
enum class RARITY
{
	ENTIRE, COM, UNCOM, RARE, UNIQ, REGENDARY, EPIC, END
};
enum class SORTING_TYPE
{
	ENHANCE, SMELTING, NAME, LV, TIMECOUNT, Price, IDLE
};
enum class SORTING_ORDER
{
	IDLE, ASC/*오름*/, DESC/*내림*/
};