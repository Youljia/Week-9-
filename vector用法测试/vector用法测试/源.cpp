#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> v{ 1,2,3,4,5,6,7,7 };
	//������Ԫ�غ�
	int sum = accumulate(v.begin(), v.end(),0);
	cout << sum << endl;
	//�������е����Ԫ�غ���СԪ��
	int max = *max_element(v.begin(), v.end());
	int min = *min_element(v.begin(), v.end());
	cout << max << endl;
	cout << min << endl;
	return 0;
}