#include<iostream>
#include <unordered_map>
using namespace std;

class CGameObject {
protected:
	int m_id;
public:
	void SetID(const int& id) { m_id = id; }
	const int& GetID() { return m_id; }
};
class CClient :public CGameObject
{

};
class CMonster :public CGameObject
{

};
class CNpc :public CGameObject
{

};
unordered_map<int, CGameObject*> g_Object;
int main()
{
	CGameObject* pObj = nullptr;
	for (int i = 0; i < 100; ++i)
	{
		pObj = new CClient;
		pObj->SetID(i);
		g_Object.emplace(i, pObj);

	}

	for (int i = 100; i < 200; ++i)
	{
		pObj = new CMonster;
		pObj->SetID(i);
		g_Object.emplace(i, pObj);
	}

	for (int i = 200; i < 300; ++i)
	{
		pObj = new CNpc;
		pObj->SetID(i);
		g_Object.emplace(i, pObj);
	}

	for (int i = 0; i < 300; ++i)
	{
		cout << g_Object.find(i)->second->GetID() << endl;
	}




}