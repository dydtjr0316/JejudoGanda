#include<iostream>
#include<set>
#include<vector>
#include <string>
using namespace std;

string solution(string encrypted_text, string key, int rotation)
{
	string result = "";
		char temp;
	if (rotation < 0)
	{
		result += encrypted_text.substr(encrypted_text.size() + rotation, encrypted_text.size());
		result += encrypted_text.substr(0, encrypted_text.size() + rotation);
	}
	else
	{
		result += encrypted_text.substr(rotation, encrypted_text.size());
		result += encrypted_text.substr(0,rotation);
	}
	for (int i = 0; i < encrypted_text.size(); i++)
	{
		if ((result[i] - (key[i] - 'a' + 1) - 'a') <= 0)
		{
			temp = (result[i] - (key[i] - 'a' + 1) - 'a') + 26;
			temp = temp % 26 + 'a';
		}
		else

		{
			temp = (result[i] - (key[i] - 'a' + 1) - 'a') % 26 + 'a';
		}
		result[i] = temp;
	}

	
	return result;
}
int main()
{
	cout<<solution("qyyigoptvfb", "abcdefghijk", 3);
}