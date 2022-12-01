//class Tree {
//
//public:
//	Tree(); // 생성자
//
//	void PreOrder(int value); // 전위
//	void InOrder(int value); // 중위
//	void PostOrder(int value); // 후위
//
//	virtual ~Tree();
//
//private:
//	int* tree; // 이진트리를 저장할 메모리 공간 (배열의 첫번째 요소는 사이즈)
//};
//
//#include <iostream>
//
//using namespace std;
//
//// 이진트리에 입력될 값을 생성자
//Tree::Tree() {
//	int size;
//	cin >> size;
//	this->tree = new int[size + 1]; // 메모리 공간 할당
//	tree[0] = size; // 배열의 첫번째 요소는 크기
//	for (int i = 0; i < size; i++) {
//		cin >> tree[i + 1];
//	}
//}
//
////소멸자
//Tree::~Tree() {
//	delete[] tree;
//}
//
//
//
//// 후위순회
//void Tree::PostOrder(int value) {
//	if (value <= tree[0] && tree[value] != -1) {
//		PostOrder(2 * value);
//		PostOrder(2 * value + 1);
//		cout << tree[value] << " "; // 부모노드를 마지막으로 방문
//	}
//}
//
//// 중위순회
//void Tree::InOrder(int value) {
//	if (value <= tree[0] && tree[value] != -1) {
//		InOrder(2 * value);
//		cout << tree[value] << " "; // 부모노드를 중간에 방문
//		InOrder(2 * value + 1);
//	}
//}
//
//int main() {
//	Tree tree;
//
//	/*cout << "전위 순회 : ";
//	tree.PreOrder(1);
//	cout << endl;*/
//
//	cout << "후위 순회 : ";
//	tree.PostOrder(1);
//	cout << endl;
//
//	//cout << "중위 순회 : ";
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