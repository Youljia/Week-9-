#include<iostream>
using namespace std;

#include<iostream>
using namespace std;

class Solution
{
public:
	Solution(int* p, int l)
	{
		arra = new int[l];
		this->len = l;
		for (int i = 0; i < l; ++i)
			this->arra[i] = p[i];
		sort();
	}
	~Solution()
	{
		cout << "This arra is releasing... ..." << endl;
		if (arra != nullptr)
			delete[] arra;
		arra = nullptr;
		len = NULL;
	}

	void sort()
	{
		quick_sort(0, len - 1);
	}
	void show()
	{
		cout << "[ ";
		for (int i = 0; i < len; ++i)
		{
			cout << arra[i];
			if (i != len - 1)
				cout << ",";
		}
		cout << " ]" << endl;
	}

	//lowerѰ��С��Ŀ��Ԫ�ص����ֵ���������
	int lower(double target)
	{
		int l = -1;
		int r = this->len - 1;
		while (l < r)
		{
			int mid = l + ((r - l + 1) / 2);
			if (arra[mid] < target)
				l = mid;
			else
				r = mid - 1;
		}
		return l;
	}

	//lower_floor ����Ŀ��Ԫ�ص���С����
	//			  Ѱ��С��Ŀ��Ԫ�ص����ֵ���������
	int lower_floor(double target)
	{
		int p = lower(target);
		if (p + 1 < this->len && arra[p + 1] == target)
			return p + 1;
		else
			return p;
	}

	//upper_floor����Ŀ��Ԫ�ص��������
	//			  Ѱ��С��Ŀ��Ԫ�ص����ֵ���������
	int upper_floor(double target)
	{
		int p = lower(target);
		while (p + 1 < this->len && arra[p + 1] == target)
			p++;
		return p;
	}
private:
	//�ݹ����
	//����:��[l,r]��������
	void quick_sort(int l, int r)
	{
		if (l >= r)
			return;
		//Ϊ������������
		int q = rand() % (r - l + 1);
		temp(arra[l], arra[l + q]);
		int p = partition(l, r);
		quick_sort(l, p - 1);
		quick_sort(p + 1, r);
	}
	int partition(int l, int r)
	{
		int j = l;
		int e = l + 1;
		for (e; e <= r; ++e)
		{
			if (arra[e] < arra[l])
			{
				j++;
				temp(arra[j], arra[e]);
			}
		}
		temp(arra[l], arra[j]);
		return j;
	}
	//����
	void temp(int& i, int& j)
	{
		int temp = i;
		i = j;
		j = temp;
	}
public:
	int* arra;
	int len;
};

int main()
{
	int p[10] = { 2,2,4,5,6,7,7,8,9,10 };
	Solution s(p, 10);
	s.show();
	int i = s.lower(7.7);
	cout << i << endl;
	cout << s.arra[i] << endl;

	i = s.upper_floor(7.7);
	cout << i << endl;
	cout << s.arra[i] << endl;

	i = s.lower_floor(7.7);
	cout << i << endl;
	cout << s.arra[i] << endl;
	return 0;
}