#include "stdafx.h"
// 디자인 패턴 - 프로토 타입
//원형이 되는 인스턴스를 사용하여 생성할 객체의 종류를 명시하고, 이렇게 만든 견본을 복사해서 새로운 객체를 생성합니다.
//
//출처: https://boycoding.tistory.com/108?category=959177 [소년코딩]

// 굉장히 안좋은 예 
// 클래스도 많고 반복 코드도 많다.
// 이럴때 프로토 타입 패턴을 사용한다.
// 여기서 핵심은 어떤 객체가 자기와 비슷한 객체를 스폰할 수 있다는 점.

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


// 프로토 타입을 생성하는 디자인 패턴
// 템플릿을 사용하면 더 현대적인 프로그래밍이 가능한데 이해 제대로 못했고
// 이 패턴 사용할일 있을 때 한번더 보기

// 근데 템플릿을 사용했을 때 단점이 더 많은느낌
// 템플릿 단점
// 1. 컴파일 타임이 비교적 느려짐 - 템플릿 매개 변수를 추가할 수록 느려짐
// 2. 실행 파일의 크기가 커지기 때문에 캐시 효용성이 떨어져 런타임 속도가 더 빨라진다고 할 수도 없음.
// 3. 가독성이 너무 안좋아짐

class Monster {
public:
	virtual ~Monster() {};
	
	// 자식 클래에서 자신의 자료형과 상태가 같은 새로운 객체를 반환하도록 클론을 구현한다.
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