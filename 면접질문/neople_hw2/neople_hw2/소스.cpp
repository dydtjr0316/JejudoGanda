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
	int cnt = 0;
	for (int t = 0; t < 5; t++)
	{

		CItem* item;
		CRegistInfo* regi;
		list<pair<CItem*, CRegistInfo*>> ItemLst;
		for (int i = 0; i < 400000; i++)
		{
			item = new CItem("�������� ���ε� ���ī��", rand() % 100, rand() % 10, rand() % 10, rand() % 10, RARITY(rand() % (int)RARITY::END));
			regi = new CRegistInfo("�̿뼮", rand() % 100000000);
			ItemLst.emplace_back(make_pair(item, regi));
		}
		for (int i = 0; i < 100000; i++)
		{
			item = new CItem("�������� ���ε� ����Ʈ ���̵�", rand() % 100, rand() % 10, rand() % 10, rand() % 10, RARITY(rand() % (int)RARITY::END));
			regi = new CRegistInfo("�̿뼮", rand() % 100000000);
			ItemLst.emplace_back(make_pair(item, regi));
		}

		for (int i = 0; i < 500000; i++)
		{
			item = new CItem("�������� ���ε� ������", rand() % 100, rand() % 10, rand() % 10, rand() % 10, RARITY(rand() % (int)RARITY::END));
			regi = new CRegistInfo("�̿뼮", rand() % 100000000);
			ItemLst.emplace_back(make_pair(item, regi));

		}
		
		ItemLst.sort(cmp);
		auto startMM = system_clock::now();

		for (auto iter = ItemLst.begin(); iter != ItemLst.end(); iter++)
		{
			if (iter->first->m_itemtypeID == 3 && iter->first->m_usLevel >= 50 && iter->first->m_usLevel <= 60 && iter->first->m_eRarity == RARITY::UNIQ)
				cnt++;
		}
		auto endMM = system_clock::now();
		std::cout << "list �� : " << duration_cast<milliseconds>(endMM - startMM).count() << "ms" << std::endl;
		cout << endl;

	}
	/*for (int t = 0; t < 5; t++)
	{

		map<CItem*, CRegistInfo*, tSort> ItemLst;
		for (int i = 0; i < 400000; i++)
		{
			CItem* item = new CItem("�������� ���ε� ���ī��", rand() % 100, rand() % 10, rand() % 10, rand() % 10, RARITY(rand() % (int)RARITY::END));
			CRegistInfo* regi = new CRegistInfo("�̿뼮", rand() % 100000000);
			cout << ItemLst.size() << endl;
			if (ItemLst.count(item) != 0)
			{
				int i = 0;
			}
			ItemLst.insert(make_pair(item, regi));

		}
		for (int i = 0; i < 100000; i++)
		{
			CItem* item = new CItem("�������� ���ε� ����Ʈ ���̵�", rand() % 100, rand() % 10, rand() % 10, rand() % 10, RARITY(rand() % (int)RARITY::END));
			CRegistInfo* regi = new CRegistInfo("�̿뼮", rand() % 100000000);
			ItemLst.emplace(item, regi);
		}

		for (int i = 0; i < 500000; i++)
		{
			CItem* item = new CItem("�������� ���ε� ������", rand() % 100, rand() % 10, rand() % 10, rand() % 10, RARITY(rand() % (int)RARITY::END));
			CRegistInfo* regi = new CRegistInfo("�̿뼮", rand() % 100000000);
			ItemLst.emplace(item, regi);

		}


		auto startMM = system_clock::now();
		for (auto iter = ItemLst.begin(); iter != ItemLst.end(); iter++)
		{
			if (iter->first->m_itemtypeID == 3 && iter->first->m_usLevel >= 50 && iter->first->m_usLevel <= 60 && iter->first->m_eRarity == RARITY::UNIQ)
				cnt++;
		}
		auto endMM = system_clock::now();

		std::cout << "map �� : " << duration_cast<milliseconds>(endMM - startMM).count() << "ms" << std::endl;
		cout << endl;

	}*/
	
	for (int t = 0; t < 5; ++t)
	{
		CItem* item = nullptr;
		CRegistInfo* regi = nullptr;
		vector<pair<CItem*, CRegistInfo*>> ItemLst;
		// pair ����
		for (int i = 0; i < 400000; ++i)	// i++ �ϸ� �ӽð�ü�� ���� ��������
		{
			item = new CItem("������� ��", rand() % 100, rand() % 10, rand() % 10, rand() % 10, RARITY(rand() % (int)RARITY::END));
			regi = new CRegistInfo("�̿뼮", rand() % 100000000);
			ItemLst.emplace_back(make_pair(item, regi));
		}
		for (int i = 0; i < 100000; ++i)
		{
			item = new CItem("�������� ��", rand() % 100, rand() % 10, rand() % 10, rand() % 10, RARITY(rand() % (int)RARITY::END));
			regi = new CRegistInfo("�̿뼮", rand() % 100000000);
			ItemLst.emplace_back(make_pair(item, regi));
		}

		for (int i = 0; i < 500000; ++i)
		{
			item = new CItem("������� ��2", rand() % 100, rand() % 10, rand() % 10, rand() % 10, RARITY(rand() % (int)RARITY::END));
			regi = new CRegistInfo("�̿뼮", rand() % 100000000);
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
		std::cout << "vector int �� : " << duration_cast<milliseconds>(endMM - startMM).count() << "ms" << std::endl;
		cout << endl;

	}


}