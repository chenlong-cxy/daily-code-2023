//#include <iostream>
//using namespace std;
//
////������
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
////			if (N & 1) //�ñ���λ�й���
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
////���ٳ�
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
//			if (x & 1) //�ñ���λ�й���
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
		//�����������
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
		//��a��b��ת���ɸ���
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
		//x/y=z,x<0,y<0,zΪȡ�����ֵ
		//z*y>=x>(z+1)*y
		//ͨ�����ֲ����ҵ�����z*y>=x�����zֵ
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
	//�ж�z*y>=x�Ƿ����
	bool quickAdd(int x, int y, int z)
	{
		int result = 0, base = y;
		while (z)
		{
			if (z & 1) //�ñ���λ�й���
			{
				if (result < x - base) //����result�����Ӹ���ֻ���С
					return false;
				result += base;
			}
			if (z != 1)
			{
				if (base < x - base) //base+base�Ǹ�����Ϊ�˱�֤��������result������������ܴ��ڵ���x����Ҫ��֤base+base�Ǵ��ڵ���x��
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
