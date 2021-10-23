#include "stdafx.h"
#include "CStore.h"
#include "CItem.h"
struct tSort
{
	bool operator()(const CItem* a, const CItem* b) const
	{
		if (a->m_usEnhance == b->m_usEnhance)
		{
			return a->m_usSmelting < b->m_usSmelting;
		}
		else
			return a->m_usEnhance < b->m_usEnhance;
	}
};
bool cmp(pair<CItem*, CRegistInfo*> a, pair<CItem*, CRegistInfo*> b)
{
	if (a.first->m_usEnhance == b.first->m_usEnhance)
	{
		return a.first->m_usSmelting < b.first->m_usSmelting;
	}
	else
		return a.first->m_usEnhance < b.first->m_usEnhance;
}
int main()
{	
	for (int t = 0; t < 5; ++t)
	{
		CItem* item = nullptr;
		CRegistInfo* regi = nullptr;
		vector<pair<CItem*, CRegistInfo*>> ItemLst;
		// pair 삭제
		for (int i = 0; i < 400000; ++i)	// i++ 하면 임시객체가 생성 후위연산
		{
			item = new CItem("김덕기의 검", rand() % 100, rand() % 10, rand() % 10, rand() % 10, RARITY(rand() % (int)RARITY::END));
			regi = new CRegistInfo("이용석", rand() % 100000000);
			ItemLst.emplace_back(make_pair(item, regi));
		}
		for (int i = 0; i < 100000; ++i)
		{
			item = new CItem("조현동의 토", rand() % 100, rand() % 10, rand() % 10, rand() % 10, RARITY(rand() % (int)RARITY::END));
			regi = new CRegistInfo("이용석", rand() % 100000000);
			ItemLst.emplace_back(make_pair(item, regi));
		}

		for (int i = 0; i < 500000; ++i)
		{
			item = new CItem("김덕기의 검2", rand() % 100, rand() % 10, rand() % 10, rand() % 10, RARITY(rand() % (int)RARITY::END));
			regi = new CRegistInfo("이용석", rand() % 100000000);
			ItemLst.emplace_back(make_pair(item, regi));

		}
		
		sort(ItemLst.begin(), ItemLst.end(), cmp);

		auto startMM = system_clock::now();
		for (auto iter = ItemLst.begin(); iter != ItemLst.end(); iter++)
		{
			if (iter->first->m_itemtypeID == 3)
				cnt++;
		}
		auto endMM = system_clock::now();
		std::cout << "vector int 비교 : " << duration_cast<milliseconds>(endMM - startMM).count() << "ms" << std::endl;
		cout << endl;

	}


}