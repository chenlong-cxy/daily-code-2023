//先计算两个日期之间的年份天数差值，然后减去较小日期当年的天数，加上较大日期当年的天数
#include <iostream>
#include <vector>
using namespace std;
bool isLeapYear(int year) {
	return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}
int dateDiff(int date1, int date2) {
	vector<int> getMonthDay = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int year1 = date1 / 10000, month1 = date1 % 10000 / 100, day1 = date1 % 100;
	int year2 = date2 / 10000, month2 = date2 % 10000 / 100, day2 = date2 % 100;
	int diff = 1;
	for (int i = year1; i < year2; i++) {
		diff += 365;
		if (isLeapYear(i))
			diff++;
	}
	auto getCurYearDays = [&getMonthDay](int year, int month, int day)->int {
		int total = 0;
		for (int i = 1; i < month; i++) {
			total += getMonthDay[i];
			if (i == 2 && isLeapYear(year))
				total++;
		}
		return total + day;
	};
	int days1 = getCurYearDays(year1, month1, day1), days2 = getCurYearDays(year2, month2, day2);
	diff -= days1;
	diff += days2;
	return diff;
}
int main()
{
	int date1, date2;
	while (cin >> date1 >> date2) {
		if (date2 < date1)
			swap(date1, date2);
		int diff = dateDiff(date1, date2);
		cout << diff << endl;
	}
	return 0;
}

////分别计算两个日期包含的天数（从0年1月1日开始），然后计算两个日期的差值
//#include <iostream>
//#include <vector>
//using namespace std;
//bool isLeapYear(int year) {
//	return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
//}
//int getDays(int date) {
//	vector<int> getMonthDay = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	int year = date / 10000, month = date % 10000 / 100, day = date % 100;
//	int total = 0;
//	for (int i = 0; i < year; i++) {
//		total += 365;
//		if (isLeapYear(i))
//			total++;
//	}
//	for (int i = 1; i < month; i++) {
//		total += getMonthDay[i];
//		if (i == 2 && isLeapYear(year))
//			total++;
//	}
//	total += day;
//	return total;
//}
//int main()
//{
//	int date1, date2;
//	while (cin >> date1 >> date2) {
//		if (date2 < date1)
//			swap(date1, date2);
//		int total1 = getDays(date1), total2 = getDays(date2);
//		int diff = total2 - total1 + 1;
//		cout << diff << endl;
//	}
//	return 0;
//}

////不断让一个日期逼近另一个日期，统计所需的天数
//#include <iostream>
//#include <vector>
//using namespace std;
//bool isLeapYear(int year) {
//	return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
//}
//int dateDiff(int date1, int date2) {
//	vector<int> getMonthDay = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	int year1 = date1 / 10000, month1 = date1 % 10000 / 100, day1 = date1 % 100;
//	int year2 = date2 / 10000, month2 = date2 % 10000 / 100, day2 = date2 % 100;
//	int diff = 1;
//	while (year1 != year2 || month1 != month2 || day1 != day2) {
//		day2--;
//		if (day2 == 0) {
//			month2--;
//			if (month2 == 0) {
//				year2--;
//				month2 = 12;
//			}
//			day2 = getMonthDay[month2];
//			if (month2 == 2 && isLeapYear(year2))
//				day2++;
//		}
//		diff++;
//	}
//	return diff;
//}
//int main() {
//	int date1, date2;
//	while (cin >> date1 >> date2) {
//		if (date2 < date1)
//			swap(date1, date2);
//		int diff = dateDiff(date1, date2);
//		cout << diff << endl;
//	}
//	return 0;
//}