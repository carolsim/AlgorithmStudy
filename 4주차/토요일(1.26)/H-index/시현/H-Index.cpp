#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations);

int solution(vector<int> citations)
{
	int answer = 0;
	int index = citations.size()-1;
	/* citations ���� �������� ���� */
	sort(citations.begin(), citations.end());

	for (int i = citations[citations.size()-1]; i >= 0; i--)
	{
		if (index != 0)
		{
			/* ���ڰ� �� index ���̿� ���� �� ū index �������� �� */
			while (i == citations[index - 1])
			{
				index--;
				if (index == 0)
				{
					break;
				}
				if (citations[index - 1] < i && i <= citations[index])
				{
					break;
				}
			}
			/* h�� �̻� �ο�� ���� h�� �̻��̰� ������ ���� h�� ���� �ο�Ǿ����� Ȯ�� */
			if (i <= citations.size() - index && i >= index - 1)
			{
				answer = i;
				return answer;
			}
		}
		else
		{
			/* index�� 0�϶� h�� �̻� �ο�� ���� h�� �̻����� Ȯ�� */
			if (i <= citations.size())
			{
				answer = i;
				return answer;
			}
		}
	}
}

int main()
{
	int ans = solution({ 3, 0, 6, 1, 5 }); // 3
	cout << ans << endl;
	ans = solution({ 2, 0, 8, 4, 6 }); // 3
	cout << ans << endl;
	ans = solution({ 7, 9, 2, 1, 4, 6, 5 }); // 4
	cout << ans << endl;
	ans = solution({ 10, 100 }); // 2
	cout << ans << endl;
	return 0;
}