//#include <iostream>
//using namespace std;
//
////快速幂
////class Solution {
////public:
////	double myPow(double x, int n) {
////		long long N = n;
////		return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
////	}
////	double quickMul(double x, long long N)
////	{
////		double ans = 1.0, base = x;
////		while (N)
////		{
////			if (N & 1) //该比特位有贡献
////			{
////				ans *= base;
////			}
////			base *= base;
////			N >>= 1;
////		}
////		return ans;
////	}
////};
//
////快速乘
//class Solution {
//public:
//	int myMul(int x, int y) {
//		bool rev = false;
//		//if (x < 0)
//		//{
//		//	x = -x;
//		//	rev = !rev;
//		//}
//		//if (y < 0)
//		//{
//		//	y = -y;
//		//	rev = !rev;
//		//}
//		int ans = quickAdd(x, y);
//		return rev == true ? -ans : ans;
//	}
//	int quickAdd(int x, int y)
//	{
//		int ans = 0, base = y;
//		while (x)
//		{
//			if (x & 1) //该比特位有贡献
//			{
//				ans += base;
//			}
//			base += base;
//			x >>= 1;
//		}
//		return ans;
//	}
//};
//int main()
//{
//	cout << Solution().myMul(5,-6) << endl;
//	cout << (-1 >> 2) << endl;
//	cout << (-1 / 2) << endl;
//	return 0;
//}

#include <iostream>
using namespace std;

class Solution {
public:
	int divide(int a, int b) {
		//特殊情况处理
		if (a == INT_MIN)
		{
			if (b == 1)
				return INT_MIN;
			if (b == -1)
				return INT_MAX;
		}
		if (b == INT_MIN)
		{
			return a == INT_MIN ? 1 : 0;
		}
		if (a == 0)
			return 0;
		//将a和b都转换成负数
		bool rev = false;
		if (a > 0)
		{
			a = -a;
			rev = !rev;
		}
		if (b > 0)
		{
			b = -b;
			rev = !rev;
		}
		//x/y=z,x<0,y<0,z为取整后的值
		//z*y>=x>(z+1)*y
		//通过二分查找找到满足z*y>=x的最大z值
		int left = 1, right = INT_MAX, ans = 0;
		while (left <= right)
		{
			int mid = left + ((right - left) >> 1);
			if (quickAdd(a, b, mid))
			{
				ans = mid;
				if (mid == INT_MAX)
					break;
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}
		return rev == true ? -ans : ans;
	}
	//判断z*y>=x是否成立
	bool quickAdd(int x, int y, int z)
	{
		int result = 0, base = y;
		while (z)
		{
			if (z & 1) //该比特位有贡献
			{
				if (result < x - base) //后续result继续加负数只会更小
					return false;
				result += base;
			}
			if (z != 1)
			{
				if (base < x - base) //base+base是负数，为了保证后续加上result（负数）后可能大于等于x，需要保证base+base是大于等于x的
					return false;
				base += base;
			}
			z >>= 1;
		}
		return true;
	}
};
int main()
{
	cout << Solution().divide(7, -3) << endl;
	//cout << Solution().quickAdd(-10, -2, 5) << endl;
	return 0;
}
