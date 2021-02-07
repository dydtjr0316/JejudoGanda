#include "Default.h"
#include "Struct.h"

class Node
{
public:
	Coordinate point;
	int F, G, H; // F = ���, G = ���� �Ÿ�, H = ���� �Ÿ�

	Coordinate end;
	Node* pParent;

public:
	Node(int _x, int _y, Node* _pParent, Coordinate _EndPoint);
	Node();
	~Node();
};

