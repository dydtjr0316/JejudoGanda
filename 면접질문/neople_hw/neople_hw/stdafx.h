#pragma once
#include <iostream>
#include <list>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <deque>

using namespace std;

#define MAX_LAYER 5
#define MAX_EQUIP 13
#define MAX_SLOT 48
enum INVEN_TYPE
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