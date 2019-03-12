#include <string>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

string solution(int n, int t, int m, int p);

string solution(int n, int t, int m, int p){
	string answer = "";
	string sample = "0"; // ���� ����
	int num = 1; // ���� Ž���� ����(�ӽ�)
	int count = 1; // ���� ����
	int exp = 0; // ����

	/* ���� �����ϱ� */
	while (sample.length() < t*m){
		/* ���� ���ڸ� n�������� ǥ������ �� �ڸ��� ���ϱ� */
		while (1){
			if (count < (int)pow(n, exp)){
				break;
			}
			exp++;
		}

		num = count;
		exp--;
		while (exp >= 0){
			if (num / (int)pow(n, exp) > 0){ // �ڸ����� ���� �� ���� ��
				if (n <= 10){ // 10���� �����϶�
					sample += to_string(num / (int)pow(n, exp));
					num = num - (int)pow(n, exp)*(num / (int)pow(n, exp));
				}
				else{ // 10���� �ʰ��϶�
					if (num / (int)pow(n, exp) >= 10){
						if (num / (int)pow(n, exp) == 10){
							sample += "A";
						}
						else if (num / (int)pow(n, exp) == 11){
							sample += "B";
						}
						else if (num / (int)pow(n, exp) == 12){
							sample += "C";
						}
						else if (num / (int)pow(n, exp) == 13){
							sample += "D";
						}
						else if (num / (int)pow(n, exp) == 14){
							sample += "E";
						}
						else{
							sample += "F";
						}
						num = num - (int)pow(n, exp)*(num / (int)pow(n, exp));
					}
					else{
						sample += to_string(num / (int)pow(n, exp));
						num = num - (int)pow(n, exp)*(num / (int)pow(n, exp));
					}
				}
			}
			else{ // �ڸ����� ���� �� ���� ��
				sample += "0";
			}
			exp--;
		}
		count++;
		exp = 0;
	}

	/* ���ϴ� ���� ���� */
	p--;
	while (answer.length() != t) {
		answer += sample.at(p);
		p += m;
	}

	return answer;
}

int main(){
	string ans = solution(2, 4, 2, 1);
	cout << ans << endl;
	ans = solution(6, 5, 3, 1);
	cout << ans << endl;
	ans = solution(16, 8, 2, 2);
	cout << ans << endl;
	ans = solution(14, 7, 3, 1);
	cout << ans << endl;
	ans = solution(10, 6, 3, 3);
	cout << ans << endl;
}