#include "Map.h"
#include "Default.h"

Map::Map()
{
	// ���� ũ�⸦ �ҷ���
	char csizeX[4], csizeY[4];
	GetPrivateProfileStringA("MAP", "sizeX", "", csizeX, sizeof(csizeX) - 1, "../Data/Map.txt");
	GetPrivateProfileStringA("MAP", "sizeY", "", csizeY, sizeof(csizeY) - 1, "../Data/Map.txt");
	sizeX = atoi(csizeX); sizeY = atoi(csizeY);

	// �� ũ�� �Ҵ�
	map = new int*[sizeX]; // �� �Ҵ�
	for (int i = 0; i < sizeX; i++) // �� �Ҵ�
	{
		map[i] = new int[sizeY];
	}

	FILE* stream = fopen("../Data/Map.txt", "rt"); // ���� �ڷḦ �ҷ��� 0=������ �� �ִ� �� , 1=��ֹ�
	for (int i = 0; i < sizeX; i++)
	{
		for (int j = 0; j < sizeY; j++)
		{
			fscanf(stream, "%d", &map[i][j]);
		}
	}
	fclose(stream);		
}

Map::~Map()
{
	delete[] map;
}

void Map::PrintMap()
{
	for (int i = 0; i < sizeX; i++)
	{
		for (int j = 0; j < sizeY; j++)
		{
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
}