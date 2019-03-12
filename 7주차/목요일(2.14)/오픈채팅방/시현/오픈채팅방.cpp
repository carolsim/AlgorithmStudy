#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

vector<string> solution(vector<string> record);

vector<string> solution(vector<string> record)
{
	map<string, string> idname;
	vector<string> answer;
	vector<string> id;
	string temp;
	vector<string> condition(record.size(), "");
	vector<bool> inout;

	for (int i = 0; i < record.size(); i++)
	{
		stringstream check(record[i]);
		int j = 0;

		/* ���⸦ �������� ������ condition �迭�� ���� */
		while (getline(check, temp, ' '))
		{
			condition[j]=temp;
			j++;
		}

		if (condition[0] == "Enter")
		{
			id.push_back(condition[1]); // id �迭�� ���̵� �־��ֱ�
			inout.push_back(true); // inout �迭�� true �־��ֱ�
			idname[condition[1]] = condition[2]; // ���̵�(condition[1])�� idname �迭���� ã�Ƽ� �̸� �־��ֱ� & �����ϱ�
		}
		else if (condition[0] == "Change")
		{
			idname[condition[1]] = condition[2];
		}
		else
		{
			id.push_back(condition[1]);
			inout.push_back(false);
		}
	}

	string ans="";
	for (int i = 0; i < id.size(); i++)
	{
		if (inout[i])
		{
			ans = idname[id[i]] + "���� ���Խ��ϴ�.";
		}
		else
		{
			ans= idname[id[i]] + "���� �������ϴ�.";
		}
		answer.push_back(ans);
	}
	return answer;
}

int main()
{
	vector<string> ans = solution({ "Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo" , "Change uid4567 Ryan" });

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << endl;
	}
}