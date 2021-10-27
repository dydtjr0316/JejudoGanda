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
#define SLOT_ADD2 64

typedef unsigned short uShort;
typedef unsigned int uInt;


enum class INVEN_TYPE
{
	IDLE,
	EQUIPMENT,		//장	비
	EXPENDABLES,	//소모품
	MATERIAL,		//재료
	SPECIAL,		//전문재료
	QUEST,			//퀘스트
	END
};

enum EQUIP
{
	IDLE,
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
	MAGINSTONE,
	END
};

enum class EXCHANGE_TYPE{IDLE, UNEXC, UNEXC_DEL, ATTRIBUTION, END};
enum class RARITY_TYPE{ IDLE, COM, UNCOM, RARE, UNIQ, REGEND, EPIC, END};
enum class EQUIPMENT_TYPE { IDLE, A,B,C,D,E, END};
enum class OCCUPATION_TYPE{ IDLE, A,B,C,D,E,F,G , END};