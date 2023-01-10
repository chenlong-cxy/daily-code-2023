////�ϲ�����
//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <vector>
//using namespace std;
////�ж��ַ���str�Ƿ����ַ���TΪǰ׺
//bool Judge(const string& str, const string& pre)
//{
//	if (str.size() < pre.size())
//		return false;
//	size_t i = 0;
//	while (i < pre.size() && str[i] == pre[i])
//		i++;
//	if (i == pre.size())
//		return true;
//	else
//		return false;
//}
//int main()
//{
//	int N;
//	cin >> N;
//	vector<string> v(N);
//	for (int i = 0; i < N; i++)
//	{
//		cin >> v[i];
//	}
//	string T;
//	cin >> T;
//	//1������������ַ����������ж����Ƿ����ַ���TΪǰ׺
//	vector<string> ans;
//	for (int i = 0; i < N; i++)
//	{
//		if (Judge(v[i], T))
//			ans.push_back(v[i]);
//	}
//	//2�������ַ���TΪǰ׺���ַ������ֵ��������������
//	sort(ans.begin(), ans.end());
//	
//	for (auto& e : ans)
//	{
//		cout << e << endl;
//	}
//	return 0;
//}


////ǧ������
//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <vector>
//using namespace std;
//int main()
//{
//	int n, q;
//	cin >> n >> q;
//	vector<int> v(n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> v[i];
//	}
//	//1�����������н������������Ա��������������ұ߽�
//	sort(v.begin(), v.end());
//	for (int i = 0; i < q; i++)
//	{
//		int left, right;
//		cin >> left >> right;
//		//2���ҵ��������߽磬�������������д��������ҵ���һ�����ڵ���left��λ��
//		int begin = 0;
//		while (begin < n&&v[begin] < left)
//			begin++;
//		if (begin == n) //���������в����ڴ��ڵ���left��ֵ�����0
//		{
//			cout << 0 << endl;
//			continue;
//		}
//		//2���ҵ�������ұ߽磬�������������д���߽翪ʼ����ҵ����һ��С�ڵ���right��λ��
//		int end = begin, count = 0, prev = -1;
//		while (end < n&&v[end] <= right)
//		{
//			//Ѱ���ұ߽��ͬʱͳ�������ڲ�ͬ�����ĸ���
//			if (v[end] != prev)
//			{
//				count++;
//				prev = v[end];
//			}
//			end++;
//		}
//		cout << count << endl;
//	}
//	return 0;
//}


////���������������
//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <vector>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> v(n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> v[i];
//	}
//	vector<int> tmp(n);
//	tmp[0] = v[0];
//	int Max = tmp[0];
//	for (int i = 1; i < n; i++)
//	{
//		//1�����±�Ϊi��Ԫ�ؽ�β�����������������
//		tmp[i] = max(v[i], v[i] + tmp[i - 1]);
//		//2�������������������������������
//		Max = max(Max, tmp[i]);
//	}
//	cout << Max << endl;
//	return 0;
//}


//��ˮ��
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	int water = 0;
	for (int i = 0; i < n; i++)
	{
		//1�����������ĺ��θ߶ȵ���ˮƽ�棬����ͳ�Ƹ�����ˮƽ���µĻ�ˮ���
		if (v[i] < 0)
		{
			water += (-v[i]);
			v[i] = 0; //��������ĺ��θ߶�����Ϊ0�����ں���ͳ�Ƹ�����ˮƽ���ϵĻ�ˮ���
		}
		//2���ҵ�����������������ߺ���
		int lmax = 0;
		for (int j = i; j >= 0; j--)
		{
			lmax = max(lmax, v[j]);
		}
		//3���ҵ��������ұ��������ߺ���
		int rmax = 0;
		for (int j = i; j < n; j++)
		{
			rmax = max(rmax, v[j]);
		}
		//4��������ˮƽ���ϵĻ�ˮ���������������ߺ��εĽ�Сֵ��ȥ������ĺ��θ߶�
		water += min(lmax, rmax) - v[i];
	}
	cout << water << endl;
	return 0;
}
