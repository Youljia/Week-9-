#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
	//����С����
	void operator()(int* arra, int len)
	{
		//���й鲢����
		merge_sort(arra, 0, len, len);
		return;
	}

	//�ݹ����
	//����-->��[l,r)��������
	void merge_sort(int* arra, int l, int r, int len)
	{
		if (l >= (r - 1))
			return;
		int mid = (l + r - 1) / 2;
		//��[l,mid)��������
		merge_sort(arra, l, mid, len);
		//��[mid,r)��������
		merge_sort(arra, mid, r, len);
		//�ϲ�[l,mid),[mid,r)������������
		merge(arra, l, mid, r, len);
	}

	//�ϲ�������������[l,mid)��[mid,r)
	void merge(int* arra, int l, int mid, int r, int len)
	{
		int* arra_copy = new int[len];
		for (int x = 0; x < len; ++x)
		{
			arra_copy[x] = arra[x];
		}
		int i = l;
		int j = mid + 1;
		for (int t = l; t < r; ++t)
		{
			if (i > mid)
			{
				arra[t] = arra_copy[j];
				++j;
			}
			else if (j > r)
			{
				arra[t] = arra_copy[i];
				++i;
			}
			else if (arra_copy[i] <= arra_copy[j])
			{
				arra[t] = arra_copy[i];
				++i;
			}
			else
			{
				arra[t] = arra_copy[j];
				++j;
			}
		}
	}
};
int main()
{
	int* p = new int[4];
	p[0] = 3;
	p[1] = 2;
	p[2] = 1;
	p[3] = 4;
	Solution s;
	s(p, 4);
	cout << p[0] << p[1] << p[2] << p[3] << endl;
	return 0;
}