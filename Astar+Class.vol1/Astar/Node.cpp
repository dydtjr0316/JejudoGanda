#include "Node.h"

Node::Node()
{

}

Node::Node(int _x, int _y, Node* _pParent, Coordinate _EndPoint)
{
	point.x = _x;
	point.y = _y;
	pParent = _pParent;
	end = _EndPoint;

	if (pParent == NULL) // �θ� ���� ���
	{	
		G = 0;		
	}
	else if ( // ���� ������ ���
		(pParent->point.x == point.x - 1 && pParent->point.y == point.y) || // �θ� '��'���⿡ �ְų�
		(pParent->point.x == point.x + 1 && pParent->point.y == point.y) || // �θ� '��'���⿡ �ְų�
		(pParent->point.x == point.x && pParent->point.y == point.y - 1) || // �θ� '��'���⿡ �ְų�
		(pParent->point.x == point.x && pParent->point.y == point.y + 1)) // �θ� '��'���⿡ ������		
	{
		G = pParent->G + 10;
	}
	else if ( // �밢�� ������ ���
		(pParent->point.x == point.x - 1 && pParent->point.y == point.y - 1) || // �θ� '�»�'���⿡ �ְų�
		(pParent->point.x == point.x - 1 && pParent->point.y == point.y + 1) || // �θ� '���'���⿡ �ְų�
		(pParent->point.x == point.x + 1 && pParent->point.y == point.y - 1) || // �θ� '����'���⿡ �ְų�
		(pParent->point.x == point.x + 1 && pParent->point.y == point.y + 1)) // �θ� '����'���⿡ ������
	{
		G = pParent->G + 14;
	}		
	else { 
		cout << " �θ� ���� ���� " << endl; 
		F = -100000;  H = -100000; G = -100000;
	}

	H = (abs(end.x - point.x) + abs(end.y - point.y)) * 10;

	F = G + H;
}

Node::~Node()
{

}