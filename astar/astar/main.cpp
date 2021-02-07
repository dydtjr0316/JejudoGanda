// AstarImpl.cpp 
//

//#include "pch.h"
#include <iostream>
#include <list>
#include <algorithm>
#include <tuple>

using namespace std;
/// 1: walkable
/// 0: not walkable
///
///   S: start
///   G: goal

char map[7][5] = {
	{'G', '0', '1', '1', '1' },
	{'1', '0', '1', '0', '1' },
	{'1', '1', '1', '0', '1' },
	{'1', '1', '0', 'S', '1' },
	{'1', '1', '1', '1', '1' },
	{'1', '1', '0', '1', '1' },
	{'1', '1', '1', '1', '1' }
};

class ASNode {
public:
	ASNode* conn;
	int row, col; //index
	int g;	// 시작점 부터 새로운 다음 사각형까지의 거리
	int h;	// 현재 지점에서 목적지까지의 거리
	int f;	// g + h
	char nodeName;
	char value;

public:
	ASNode(int _x, int _y, char _v, int _i)
	{
		row = _x;
		col = _y;
		value = _v;
		nodeName = _i;
		g = 0;
		h = 0;
		f = 0;
	}
};

ASNode* GetChildNodes(int childIndRow, int childIndCol, ASNode* parentNode);
ASNode* CreateNodeByIndex(int rowIndex, int colIndex, ASNode* parentNode);

static char uniqueName = 'a';
list<ASNode*> openList;
list<ASNode*> closeList;

tuple<int, int> GetGoalIndex()
{
	int maxMapSizeRow = sizeof(map) / sizeof(map[0]);
	int maxMapSizeCol = sizeof(map[0]);

	for (int i = 0; i < maxMapSizeRow; i++)
	{
		for (int j = 0; j < maxMapSizeCol; j++)
		{
			if (map[i][j] == 'G')
			{
				return make_tuple(i, j);
			}
		}
	}
}

void DebugPrintList(list<ASNode*>& nodelist, string name)
{
	cout << name.c_str() << ":" << endl;
	//cout << "list length:" << nodelist.size() << endl;
	for (auto& ele : nodelist)
	{
		cout << "(" << ele->row << "," << ele->col << ")";
	}
	cout << endl;
}

void DebugPrintElement(ASNode* curNode, ASNode* parent)
{
	cout << "set parent:" << "(" << (curNode)->row << "," << (curNode)->col << ")->(" << (parent)->row << "," << (parent)->col << ")" << endl;
}

void ShowMap()
{
	int maxMapSizeRow = sizeof(map) / sizeof(map[0]);
	int maxMapSizeCol = sizeof(map[0]);

	cout << "\n=======================================" << endl;
	for (int i = 0; i < maxMapSizeRow; i++)
	{
		for (int j = 0; j < maxMapSizeCol; j++)
		{
			cout << map[i][j];
		}
		cout << endl;
	}
	cout << "=======================================" << endl;
}

void FindPath()
{
	//DebugPrintList(openList, "Open");
	//DebugPrintList(closeList, "Close");
	int maxMapSizeRow = sizeof(map) / sizeof(map[0]);	// 가로
	int maxMapSizeCol = sizeof(map[0]);					// 세로

	//cout << "maxMapSizeRow:" << maxMapSizeRow << ", maxMapSizeCol:" << maxMapSizeCol <<endl;
	
	if (openList.size() == 0)
	{
		//end of finding.  no route to goal
		cout << "no path exists." << endl;
		return;
	}

	ASNode* openNode = nullptr;

	int smallest_f = 10000;
	for (auto& op : openList)
	{
		if (op->f < smallest_f)
		{
			smallest_f = op->f;
			openNode = op;
		}
	}

	if (openNode != nullptr)
	{
		if (openNode->nodeName == 'G') //arrive at Goal
		{
			cout << "< Optimal Path (row, column)>" << endl;
			while (openNode != nullptr)
			{
				cout << "(" << openNode->row << "," << openNode->col << ")";

				int rowind = openNode->row;
				int colind = openNode->col;
				map[rowind][colind] = '*';

				openNode = openNode->conn;
				if (openNode != nullptr)
					cout << "<==";
			}

			ShowMap();
		}
		else
		{
			//Get children nodes from the current node
			//check 4-way, up,down,left,right
			int rowInd = openNode->row;		// 노드의 위치
			int colInd = openNode->col;		// 노드의 위치

			//check up
			ASNode* childNode;
			// 맵의 범위를 넘어갔는지에 대한 검사와 자식 노드를 찾아냄
			if (openNode->row - 1 >= 0)
			{
				int childIndRow = openNode->row - 1;
				int childIndCol = openNode->col;

				childNode = GetChildNodes(childIndRow, childIndCol, openNode);
			}

			if (openNode->row + 1 < maxMapSizeRow)
			{
				int childIndRow = openNode->row + 1;
				int childIndCol = openNode->col;

				childNode = GetChildNodes(childIndRow, childIndCol, openNode);
			}

			if (openNode->col + 1 < maxMapSizeCol)
			{
				int childIndRow = openNode->row;
				int childIndCol = openNode->col + 1;

				childNode = GetChildNodes(childIndRow, childIndCol, openNode);
			}

			if (openNode->col - 1 >= 0)
			{
				int childIndRow = openNode->row;
				int childIndCol = openNode->col - 1;

				childNode = GetChildNodes(childIndRow, childIndCol, openNode);
			}
			//
			//cout << "[Remove from openlist] (" << rowInd << "," << colInd << ")" << endl;
			openList.remove_if([&](ASNode* node)
				{
					if (node->row == rowInd && node->col == colInd)
					{
						return true;
					}
					else
					{
						return false;
					}
				});

			//cout << "[push] to closeList:" << rowInd << "," << openNode->col << endl;
			closeList.push_back(openNode);

			FindPath();
		}
	}
}

ASNode* GetChildNodes(int childIndRow, int childIndCol, ASNode* parentNode)
{
	auto it_open = find_if(openList.begin(), openList.end(), [&](ASNode* node)
		{
			if (node->row == childIndRow && node->col == childIndCol)
			{
				return true;
			}
			else
			{
				return false;
			}
		});

	auto it_close = find_if(closeList.begin(), closeList.end(), [&](ASNode* node)
		{
			if (node->row == childIndRow && node->col == childIndCol)
			{
				return true;
			}
			else
			{
				return false;
			}
		});

	if (it_open != openList.end())
	{
		//exist
		if ((*it_open)->g < parentNode->g + 1)
		{
			(*it_open)->g = parentNode->g + 1;
			parentNode->conn = (*it_open);
			(*it_open)->f = (*it_open)->g + (*it_open)->h;

			//cout << "[parenting openlist]";
			//DebugPrintElement(*it_open, parentNode);
		}

		return *it_open;
	}
	else if (it_close != closeList.end())
	{

		//exist
		if ((*it_close)->g < parentNode->g + 1)
		{
			(*it_close)->g = parentNode->g + 1;
			parentNode->conn = (*it_close);
			(*it_close)->f = (*it_close)->g + (*it_close)->h;
			/*	cout << "[parenting closelist]";
				DebugPrintElement(*it_close, parentNode);*/
		}
		return *it_close;
	}
	else
	{
		ASNode* newNode = CreateNodeByIndex(childIndRow, childIndCol, parentNode);

		if (newNode != nullptr)
		{
			//cout << "[push] to openlist:" << newNode->row << "," << newNode->col << endl;
			openList.push_back(newNode);
		}
		return newNode;
	}

	return nullptr;
}


ASNode* CreateNodeByIndex(int rowIndex, int colIndex, ASNode* parentNode)
{
	char val = map[rowIndex][colIndex];

	if (val == '0')
		return nullptr;

	ASNode* node = nullptr;
	if (val == 'G')
	{
		node = new ASNode(rowIndex, colIndex, 'G', 'G');
		node->g = parentNode->g + 1;
		node->h = 0;
		node->f = node->g;
		node->conn = parentNode;
	}
	else
	{
		node = new ASNode(rowIndex, colIndex, val, uniqueName++);
		node->g = parentNode->g + 1;

		auto inds = GetGoalIndex();
		int goalRowInd = get<0>(inds);
		int goalColInd = get<1>(inds);

		int h = abs(goalRowInd - rowIndex) + abs(goalColInd - colIndex);
		node->h = h;
		node->f = node->g + h;
		node->conn = parentNode;
	}

	return node;
}

int main()
{
	ShowMap();

	int startRowInd = 3;	// 시작 좌표 
	int startColInd = 3;	// 시작 좌표

	ASNode* startNode = new ASNode(startRowInd, startColInd, 'S', 'S');

	//put open list first
	openList.push_back(startNode);

	FindPath();
}