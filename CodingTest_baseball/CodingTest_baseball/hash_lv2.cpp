#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;
bool solution(vector<string> phone_book) {
    unordered_map<string, int> hash_map;
    for (int i = 0;i<phone_book.size();i++)
        hash_map[phone_book[i]] = 1;

    for (int i = 0; i < phone_book.size(); i++)
    {
        string number = "";
        for (int j = 0; j < phone_book[i].size(); j++)
        {
            number += phone_book[i][j];
            if (hash_map[number] && number != phone_book[i])
                return false;
        }
    }
    return  true;
}
int main()
{
    vector<string> t{ "119", "97674223", "1195524421" };
    solution(t);
}