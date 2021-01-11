#include <iostream>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include<algorithm>
#include <iterator>
using namespace std;
enum  objID{client, monster, npc, end};
class GameObj;
typedef unordered_map<int, GameObj*> OBJLIST;
typedef OBJLIST::iterator OBJITER;

template <typename T>
void SafeDelete(T& ptr)
{
    if (ptr)
    {
        delete ptr;
        ptr = nullptr;
    }
}

template <typename T>
void SafeDeleteArr(T& ptr)
{
    if (ptr)
    {
        delete[] ptr;
        ptr = nullptr;
    }
}

using namespace std;
class GameObj{

public:
    GameObj() {  }
   GameObj(const objID& t, const int& id) { i = id; }
   virtual ~GameObj() {}
    int i = 0;
    objID t;
};
class Client :public GameObj {
public:
    Client() = default;
    virtual ~Client() = default;

};
class NPC :public GameObj {

};
class Monster : public GameObj {

};

class ObjMgr {
private:
    // ������Ʈ�� �����ϴ� unordered_map<int, GameObj*> �� ����ִ� �迭
    // objID�� ���� client, monster, npc�� ����ִ�.
    OBJLIST m_objlst[objID::end];       


public:
    OBJLIST* GEt_OBjlst(const objID& eID) { return &(m_objlst[eID]); }
    void Add(GameObj* pObj, const objID& eID, const int& id);
    GameObj* Find(const objID& eID, const int& id);
    void Delete_lst(const objID& eID);
    void Delete_obj(const objID& eID, const int& id);
    int Count(const objID& eID, const int& id);
    int Size(const objID& eID);
    void Print(const objID& eID);
};

// Ȯ��
void ObjMgr::Add(GameObj* pObj, const objID& eID, const int& id)
{
    if (pObj != nullptr)
        m_objlst[eID].emplace(id, pObj);
}

// Ȯ��
GameObj* ObjMgr::Find(const objID& eID, const int& id)
{
    if (!m_objlst[eID].empty())
    {
        OBJITER iter;
        iter = m_objlst[eID].find(id);
        return (iter->second);
    }

    return nullptr;

}

// Ȯ��
void ObjMgr::Delete_lst(const objID& eID)
{
    for (auto& objlist : m_objlst[eID])
    {
        delete (objlist).second;
        (objlist).second = nullptr;
    }
    m_objlst[eID].clear();
   
}

// Ȯ��
void ObjMgr::Delete_obj(const objID& eID, const int& id)
{
    if (!m_objlst[eID].empty())
    {
        SafeDelete(m_objlst[eID].find(id)->second);
        m_objlst[eID].erase(id);
    }
}

// Ȯ��
int ObjMgr::Count(const objID& eID, const int& id)
{
    if (!m_objlst[eID].empty())
    {
        return m_objlst[eID].count(id);
    }

    return 0;
}

// Ȯ��
int ObjMgr::Size(const objID& eID)
{
    return m_objlst[eID].size();
}

// �ٸ� �Լ� Ȯ�ο�
void ObjMgr::Print(const objID& eID)
{
    if (!m_objlst[eID].empty())
    {
        for (auto& a : m_objlst[eID])
        {
            switch (eID)
            {
            case client:
                cout << "client -> " << a.first << "     id ->" << a.second->i << endl;
                break;
            case monster:
                cout << "monster -> " << a.first << "     id ->" << a.second->i << endl;
                break;
            case npc:
                cout << "npc -> " << a.first << "     id ->" << a.second->i << endl;
                break;
            }
        }
    }
    cout << endl;
}
ObjMgr objmgr;
int main() {
    GameObj* pObj = nullptr;
    // add �Լ�---------------------------------------
    for (int i = 0; i < 10; ++i)
    {
        pObj = new Client;
        objmgr.Add(pObj, client, i);
    }
    for (int i = 0; i < 10; ++i)
    {
        pObj = new NPC;
        objmgr.Add(pObj, monster, i);
    }
    for (int i = 0; i < 10; ++i)
    {
        pObj = new Monster;
        objmgr.Add(pObj, npc, i);
    }
    // --------------------------------------------------
    // find �Լ�
    for (int i = 0; i < objID::end; ++i)
    {
        for (int j = 0; j < 10; ++j) {
            objmgr.Find((objID)i, j)->i = j;
        }
    }
    cout << "��� objID 10�� ������ 0~9�� �ʱ�ȭ" << endl << endl;
    // �Լ� ���� Ȯ�ο� 
    for (int i = 0; i < objID::end; ++i)
    {
        objmgr.Print((objID)i);
    }
    cout << "---------------------------------------------------------" << endl;

    // --------------------------------------------------
    // --------------------------------------------------

    // delete list �Լ�
    objmgr.Delete_lst(objID::client);
    cout << "client�� ��� ��ü ����"  << endl;
    // �Լ� ���� Ȯ�ο� 
    for (int i = 0; i < objID::end; ++i)
    {
        objmgr.Print((objID)i);
    }
    cout << "---------------------------------------------------------" << endl;

    // --------------------------------------------------
    // --------------------------------------------------

    // delete obj �Լ�
    objmgr.Delete_obj(objID::monster, 0);
    cout << "monster�� key�� 0�� ��ü ����" << endl << endl;
    // �Լ� ���� Ȯ�ο� 
    for (int i = 0; i < objID::end; ++i)
    {
        objmgr.Print((objID)i);
    }
    cout << "---------------------------------------------------------" << endl;

    // --------------------------------------------------
    // --------------------------------------------------

    // �Լ� ���� Ȯ�ο� 
    for (int i = 0; i < objID::end; ++i)
    {
        objmgr.Print((objID)i);
    }
    // --------------------------------------------------

    // count �Լ�
    for (int i = 0; i < objID::end; ++i)
    {
        switch (i)
        {
        case client:
            cout << "client count() -> " << objmgr.Count((objID)i, i) << endl;
            break;
        case monster:
            cout << "monster count() -> " << objmgr.Count((objID)i, i) << endl;
            break;
        case npc:
            cout << "npc count() -> " << objmgr.Count((objID)i, i) << endl;
            break;
        }
    }
    cout << endl;
    // --------------------------------------------------

    // size �Լ�
    for (int i = 0; i < objID::end; ++i)
    {
        switch (i)
        {
        case client:
            cout << "client size() -> " << objmgr.Size((objID)i) << endl;
            break;
        case monster:
            cout << "monster size() -> " << objmgr.Size((objID)i) << endl;
            break;
        case npc:
            cout << "npc size() -> " << objmgr.Size((objID)i) << endl;
            break;
        }
    }
    cout << endl;

    // --------------------------------------------------

    return 0;
}



