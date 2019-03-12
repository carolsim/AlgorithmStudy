#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

void find_Replace(string &data, string toSearch, string replaceStr);
string solution(string m, vector<string> musicinfos);

/* string�� �Ϻθ� �ٲ��ִ� �Լ� */
void find_Replace(string &data, string toSearch, string replaceStr)
{
	size_t pos = data.find(toSearch);

	while (pos != string::npos)
	{
		data.replace(pos, toSearch.size(), replaceStr);
		pos = data.find(toSearch, pos + replaceStr.size());
	}
}

string solution(string m, vector<string> musicinfos)
{
	string answer = "";
	string temp;
	vector<vector<string>> split(musicinfos.size(), vector<string>(6, "")); // 2���� �迭 �ʱ�ȭ
	vector<string> listen;
	vector<int> found;
	int min = 0;
	int timeDifference = 0;

	find_Replace(m, "C#", "c");
	find_Replace(m, "D#", "d");
	find_Replace(m, "F#", "f");
	find_Replace(m, "G#", "g");
	find_Replace(m, "A#", "a");

	for (int i = 0; i < musicinfos.size(); i++)
	{
		/* musicinfos�� :�� ,�� �ٲٱ� */
		find_Replace(musicinfos[i], ":", ",");

		find_Replace(musicinfos[i], "C#", "c");
		find_Replace(musicinfos[i], "D#", "d");
		find_Replace(musicinfos[i], "F#", "f");
		find_Replace(musicinfos[i], "G#", "g");
		find_Replace(musicinfos[i], "A#", "a");

		stringstream check(musicinfos[i]);
		int j = 0;

		/* �޸�(,)�� �������� ������ split �迭�� ���� */
		while (getline(check, temp, ','))
		{
			split[i][j]=temp;
			j++;
		}
	}

	for (int i = 0; i < split.size(); i++)
	{
		temp = "";
		min = 0;

		/* ����ð� ���ϱ� - string�� int�� ��ȯ �� ��� */
		timeDifference = (stoi(split[i][2]) * 60 + stoi(split[i][3])) - (stoi(split[i][0]) * 60 + stoi(split[i][1]));

		/* ����ð��� �Ǻ� �������� ª�ų� ���� ��� ����ð���ŭ listen �迭�� ���� */
		if (timeDifference <= split[i][5].length())
		{
			temp = split[i][5].substr(0, timeDifference);
			listen.push_back(temp);
		}
		else
		{
			while (min <= timeDifference-split[i][5].length())
			{
				min += split[i][5].length();
				temp += split[i][5];
			}
			if (min < timeDifference)
			{
				temp += split[i][5].substr(0, timeDifference - min);
			}
			listen.push_back(temp);
		}
	}

	/* m�� listen �迭�� �ִ��� �˻� �� index�� found �迭�� ���������� �߰� */
	size_t pos = 0;
	for (int i = 0; i < listen.size(); i++)
	{
		pos = listen[i].find(m);
		if (pos != string::npos)
		{
			found.push_back(i);
		}
	}

	int max = 0;
	if (found.size() == 1) // �� �� ã�� ���
	{
		answer = split[found[0]][4];
	}
	else if (found.size() == 0) // �� � ��ã�� ���
	{
		answer = "(None)";
	}
	else // ���� �� ã�� ���
	{
		max = (stoi(split[found[0]][2]) * 60 + stoi(split[found[0]][3]))
			- (stoi(split[found[0]][0]) * 60 + stoi(split[found[0]][1]));
		answer = split[found[0]][4];
		for (int i = 1; i < found.size(); i++)
		{
			timeDifference = (stoi(split[found[i]][2]) * 60 + stoi(split[found[i]][3]))
				- (stoi(split[found[i]][0]) * 60 + stoi(split[found[i]][1]));
			/* ��� �ð� �� ��� ã�� */
			if (max < timeDifference) // ��� �ð��� ���� ��� ���� �Էµ� ���� ���� ��ȯ
			{
				max = timeDifference;
				answer = split[found[i]][4];
			}
		}
	}

	return answer;
}

int main()
{
	string ans = solution("ABCDEFG", { "12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF" });
	cout << ans << endl;
	ans = solution("CC#BCC#BCC#BCC#B", { "03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B" });
	cout << ans << endl;
	ans = solution("ABC", { "12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF" });
	cout << ans << endl;
	return 0;
}