////合并序列
//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <vector>
//using namespace std;
////判断字符串str是否以字符串T为前缀
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
//	//1、遍历输入的字符串，依次判断其是否以字符串T为前缀
//	vector<string> ans;
//	for (int i = 0; i < N; i++)
//	{
//		if (Judge(v[i], T))
//			ans.push_back(v[i]);
//	}
//	//2、将以字符串T为前缀的字符串按字典序进行升序排序
//	sort(ans.begin(), ans.end());
//	
//	for (auto& e : ans)
//	{
//		cout << e << endl;
//	}
//	return 0;
//}


////千问万问
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
//	//1、将整数序列进行升序排序，以便查找子区间的左右边界
//	sort(v.begin(), v.end());
//	for (int i = 0; i < q; i++)
//	{
//		int left, right;
//		cin >> left >> right;
//		//2、找到区间的左边界，即在整数序列中从左向右找到第一个大于等于left的位置
//		int begin = 0;
//		while (begin < n&&v[begin] < left)
//			begin++;
//		if (begin == n) //整数序列中不存在大于等于left的值，输出0
//		{
//			cout << 0 << endl;
//			continue;
//		}
//		//2、找到区间的右边界，即在整数序列中从左边界开始向后找到最后一个小于等于right的位置
//		int end = begin, count = 0, prev = -1;
//		while (end < n&&v[end] <= right)
//		{
//			//寻找右边界的同时统计区间内不同整数的个数
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


////连续子数组的最大和
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
//		//1、以下标为i的元素结尾的连续子数组的最大和
//		tmp[i] = max(v[i], v[i] + tmp[i - 1]);
//		//2、更新整数数组中连续子数组的最大和
//		Max = max(Max, tmp[i]);
//	}
//	cout << Max << endl;
//	return 0;
//}


//降水量
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
		//1、如果该区域的海拔高度低于水平面，则先统计该区域水平面下的积水面积
		if (v[i] < 0)
		{
			water += (-v[i]);
			v[i] = 0; //将该区域的海拔高度设置为0，便于后续统计该区域水平面上的积水面积
		}
		//2、找到该区域左边区域的最高海拔
		int lmax = 0;
		for (int j = i; j >= 0; j--)
		{
			lmax = max(lmax, v[j]);
		}
		//3、找到该区域右边区域的最高海拔
		int rmax = 0;
		for (int j = i; j < n; j++)
		{
			rmax = max(rmax, v[j]);
		}
		//4、该区域水平面上的积水面积，等于左右最高海拔的较小值减去该区域的海拔高度
		water += min(lmax, rmax) - v[i];
	}
	cout << water << endl;
	return 0;
}
