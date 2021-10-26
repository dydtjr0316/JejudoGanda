#pragma once
#include <iostream>
#include <list>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <random>
#include <iomanip>

using namespace std;

#define MAX_LAYER 5
#define MAX_EQUIP 13

#define SLOT_IDLE 48
#define SLOT_ADD1 56
#define SLOT_SIZEUP8 64


enum class INVEN_TYPE
{
	EQUIPMENT,		//장	비
	EXPENDABLES,	//소모품
	MATERIAL,		//재료
	SPECIAL,		//전문재료
	QUEST,			//퀘스트
};

enum EQUIP
{
	HEADNSHOULDER,		
	TOP,				
	PANTS,				
	BELT,				
	SHOES,				
	WEAPON,
	STYLE,
	BRACELET,
	NECKLACE,
	SUB,
	RING,
	EARRING,
	MAGINSTONE
};

enum class EXCHANGE_TYPE{IDLE, UNEXC, UNEXC_DEL, ATTRIBUTION };
enum class RARITY_TYPE{COM, UNCOM, RARE, UNIQ, REGEND, EPIC};
enum class EQUIPMENT_TYPE { A,B,C,D,E }; 
enum class OCCUPATION_TYPE{A,B,C,D,E,F,G };