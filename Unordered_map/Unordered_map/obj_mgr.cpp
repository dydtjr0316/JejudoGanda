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
    // 오브젝트를 관리하는 unordered_map<int, GameObj*> 를 담고있는 배열
    // objID에 따라 client, monster, npc를 담고있다.
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

// 확인
void ObjMgr::Add(GameObj* pObj, const objID& eID, const int& id)
{
    if (pObj != nullptr)
        m_objlst[eID].emplace(id, pObj);
}

// 확인
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

// 확인
void ObjMgr::Delete_lst(const objID& eID)
{
    for (auto& objlist : m_objlst[eID])
    {
        delete (objlist).second;
        (objlist).second = nullptr;
    }
    m_objlst[eID].clear();
   
}

// 확인
void ObjMgr::Delete_obj(const objID& eID, const int& id)
{
    if (!m_objlst[eID].empty())
    {
        SafeDelete(m_objlst[eID].find(id)->second);
        m_objlst[eID].erase(id);
    }
}

// 확인
int ObjMgr::Count(const objID& eID, const int& id)
{
    if (!m_objlst[eID].empty())
    {
        return m_objlst[eID].count(id);
    }

    return 0;
}

// 확인
int ObjMgr::Size(const objID& eID)
{
    return m_objlst[eID].size();
}

// 다른 함수 확인용
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
    // add 함수---------------------------------------
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
    // find 함수
    for (int i = 0; i < objID::end; ++i)
    {
        for (int j = 0; j < 10; ++j) {
            objmgr.Find((objID)i, j)->i = j;
        }
    }
    cout << "모든 objID 10개 생성후 0~9로 초기화" << endl << endl;
    // 함수 실행 확인용 
    for (int i = 0; i < objID::end; ++i)
    {
        objmgr.Print((objID)i);
    }
    cout << "---------------------------------------------------------" << endl;

    // --------------------------------------------------
    // --------------------------------------------------

    // delete list 함수
    objmgr.Delete_lst(objID::client);
    cout << "client의 모든 객체 삭제"  << endl;
    // 함수 실행 확인용 
    for (int i = 0; i < objID::end; ++i)
    {
        objmgr.Print((objID)i);
    }
    cout << "---------------------------------------------------------" << endl;

    // --------------------------------------------------
    // --------------------------------------------------

    // delete obj 함수
    objmgr.Delete_obj(objID::monster, 0);
    cout << "monster의 key가 0인 객체 삭제" << endl << endl;
    // 함수 실행 확인용 
    for (int i = 0; i < objID::end; ++i)
    {
        objmgr.Print((objID)i);
    }
    cout << "---------------------------------------------------------" << endl;

    // --------------------------------------------------
    // --------------------------------------------------

    // 함수 실행 확인용 
    for (int i = 0; i < objID::end; ++i)
    {
        objmgr.Print((objID)i);
    }
    // --------------------------------------------------

    // count 함수
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

    // size 함수
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



