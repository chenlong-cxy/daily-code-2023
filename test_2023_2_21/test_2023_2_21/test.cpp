//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//	int daysBetweenDates(string date1, string date2) {
//		int year1 = atoi(date1.substr(0, 4).c_str()), year2 = atoi(date2.substr(0, 4).c_str());
//		int month1 = atoi(date1.substr(5, 2).c_str()), month2 = atoi(date2.substr(5, 2).c_str());
//		int day1 = atoi(date1.substr(8, 2).c_str()), day2 = atoi(date2.substr(8, 2).c_str());
//		if (year1 > year2 || month1 > month2 || day1 > day2) {
//			swap(year1, year2);
//			swap(month1, month2);
//			swap(day1, day2);
//		}
//		cout << year1 << " " << month1 << " " << day1 << endl;
//		cout << year2 << " " << month2 << " " << day2 << endl;
//		vector<int> getMonthDay = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//		int count = 0;
//		while (year1 != year2 || month1 != month2 || day1 != day2) {
//			count++;
//			day2--;
//			if (day2 == 0) {
//				month2--;
//				if (month2 == 0) {
//					year2--;
//					month2 = 12;
//				}
//				day2 = getMonthDay[month2];
//				if (month2 == 2 && isLeapYear(year2))
//					day2++;
//			}
//		}
//		return count;
//	}
//	bool isLeapYear(int year) {
//		return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
//	}
//};
//int main()
//{
//	cout << Solution().daysBetweenDates("2010-09-23", "1971-06-29") << endl;
//	return 0;
//}

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char arr[26] = { 0 };
	char str[1000];
	scanf("%s", &str);
	int i = 0;
	while (str[i] != '\0') {
		char ch = str[i];
		arr[ch - 'a']++;
		i++;
	}
	char maxCh = 'a';
	int maxCount = 0;
	for (i = 0; i < 26; i++) {
		if (arr[i] > maxCount) {
			maxCh = 'a' + i;
			maxCount = arr[i];
		}
	}
	printf("%c\n", maxCh);
	printf("%d\n", maxCount);
	return 0;
}