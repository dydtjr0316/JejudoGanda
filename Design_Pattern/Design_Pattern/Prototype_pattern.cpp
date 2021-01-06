#include "stdafx.h"
// ������ ���� - ������ Ÿ��
//������ �Ǵ� �ν��Ͻ��� ����Ͽ� ������ ��ü�� ������ ����ϰ�, �̷��� ���� �ߺ��� �����ؼ� ���ο� ��ü�� �����մϴ�.
//
//��ó: https://boycoding.tistory.com/108?category=959177 [�ҳ��ڵ�]

// ������ ������ �� 
// Ŭ������ ���� �ݺ� �ڵ嵵 ����.
// �̷��� ������ Ÿ�� ������ ����Ѵ�.
// ���⼭ �ٽ��� � ��ü�� �ڱ�� ����� ��ü�� ������ �� �ִٴ� ��.

//class Monster {};
//
//class M1 :public Monster {};
//class M2 :public Monster {};
//class M3 :public Monster {};
//
//class Spawner {
//public:
//	virtual ~Spawner() {};
//	virtual Monster* spawnMonster() = 0;
//};
//
//class SpawnM1 :public Spawner
//{
//public:
//	virtual Monster* spawnMonster() override { return new M1(); }
//};
//
//class SpawnM2 :public Spawner
//{
//public:
//	virtual Monster* spawnMonster() override { return new M2(); }
//};
//
//class SpawnM3 :public Spawner
//{
//public:
//	virtual Monster* spawnMonster() override { return new M3(); }
//};


// ������ Ÿ���� �����ϴ� ������ ����
// ���ø��� ����ϸ� �� �������� ���α׷����� �����ѵ� ���� ����� ���߰�
// �� ���� ������� ���� �� �ѹ��� ����

// �ٵ� ���ø��� ������� �� ������ �� ��������
// ���ø� ����
// 1. ������ Ÿ���� ���� ������ - ���ø� �Ű� ������ �߰��� ���� ������
// 2. ���� ������ ũ�Ⱑ Ŀ���� ������ ĳ�� ȿ�뼺�� ������ ��Ÿ�� �ӵ��� �� �������ٰ� �� ���� ����.
// 3. �������� �ʹ� ��������

class Monster {
public:
	virtual ~Monster() {};
	
	// �ڽ� Ŭ������ �ڽ��� �ڷ����� ���°� ���� ���ο� ��ü�� ��ȯ�ϵ��� Ŭ���� �����Ѵ�.
	virtual Monster* clone() = 0;
};

class M1 :public Monster {
public:
	M1(int x, int y) :m_x(x), m_y(y) {}
	virtual Monster* clone()
	{
		return new M1(m_x, m_y);
	}
private:
	int m_x;
	int m_y;
};

class M2 :public Monster {
public:
	M2(int x, int y) :m_x(x), m_y(y) {}
	virtual Monster* clone()
	{
		return new M2(m_x, m_y);
	}
private:
	int m_x;
	int m_y;
};

class M3 :public Monster {
public:
	M3(int x, int y) :m_x(x), m_y(y) {}
	virtual Monster* clone()
	{
		return new M3(m_x, m_y);
	}
private:
	int m_x;
	int m_y;
};

class Spawner {
public:
	Spawner(Monster* prototype) : m_prototype(prototype) {}

	Monster* spawnMonster() {return m_prototype->clone();}

private:
	Monster* m_prototype;
};


int main()
{
	Monster* m1Proto = new M1(1, 1);
	Monster* m2Proto = new M2(2, 2);
	Monster* m3Proto = new M3(3, 3);
	
	Spawner* m1Spawner = new Spawner(m1Proto);
	Spawner* m2Spawner = new Spawner(m2Proto);
	Spawner* m3Spawner = new Spawner(m3Proto);


	return 0;
}