//class Tree {
//
//public:
//	Tree(); // ������
//
//	void PreOrder(int value); // ����
//	void InOrder(int value); // ����
//	void PostOrder(int value); // ����
//
//	virtual ~Tree();
//
//private:
//	int* tree; // ����Ʈ���� ������ �޸� ���� (�迭�� ù��° ��Ҵ� ������)
//};
//
//#include <iostream>
//
//using namespace std;
//
//// ����Ʈ���� �Էµ� ���� ������
//Tree::Tree() {
//	int size;
//	cin >> size;
//	this->tree = new int[size + 1]; // �޸� ���� �Ҵ�
//	tree[0] = size; // �迭�� ù��° ��Ҵ� ũ��
//	for (int i = 0; i < size; i++) {
//		cin >> tree[i + 1];
//	}
//}
//
////�Ҹ���
//Tree::~Tree() {
//	delete[] tree;
//}
//
//
//
//// ������ȸ
//void Tree::PostOrder(int value) {
//	if (value <= tree[0] && tree[value] != -1) {
//		PostOrder(2 * value);
//		PostOrder(2 * value + 1);
//		cout << tree[value] << " "; // �θ��带 ���������� �湮
//	}
//}
//
//// ������ȸ
//void Tree::InOrder(int value) {
//	if (value <= tree[0] && tree[value] != -1) {
//		InOrder(2 * value);
//		cout << tree[value] << " "; // �θ��带 �߰��� �湮
//		InOrder(2 * value + 1);
//	}
//}
//
//int main() {
//	Tree tree;
//
//	/*cout << "���� ��ȸ : ";
//	tree.PreOrder(1);
//	cout << endl;*/
//
//	cout << "���� ��ȸ : ";
//	tree.PostOrder(1);
//	cout << endl;
//
//	//cout << "���� ��ȸ : ";
//	//tree.InOrder(1);
//	//cout << endl;
//
//	return 0;
//}



#include <iostream>
#include <vector>
#include<map>
using namespace std;
string answer;
void visit(int i, string message)
{
	if (i<message.size())
	{
		visit(2 * i, message);
		visit(2 * i + 1, message);
		answer += message[i];
	}
}
#include <stack>
enum Flag
{
	start = 1, end = 2
};


int main()
{
	vector<vector<int>> customer{ {1, 4}, {3, 5}, {8, 10 } };
	map<int, Flag> m;
	stack<int> s;
	for (auto& obj : customer)
	{
		m[obj[0]] = Flag::start;
		m[obj[1]] = Flag::end;
	}
	s.push((*m.begin()).first);
	for (int i = 1;i<m.size();++i)
	{
		if (s.top() == Flag::start)
		{

		}
		else
		{

		}
	}

	return 0;
}