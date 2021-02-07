#include "Default.h"
#include "Astar.h"

void main()
{	
	Astar::Coordinate A(0, 0);
	Astar::Coordinate B(0, 4);

	Astar astar(A, B);

	astar.PrintNavi();
}