/*
1949年的国庆节（10月1日）是星期六。 
2012的国庆节是星期一。
那么，从建国到现在，有几次国庆节正好是星期日呢？
*/


#include<iostream>
using namespace std;
bool isLeap(int year)
{
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
	{
		return true;
	}
	else
	{
		return false;
	}

}
int main()
{
	int days = 0;
	for (int year = 1950; year <= 2019; year++)
	{
		 days += isLeap(year) ? 366 : 365;
		 if (days % 7 == 1)
		 {
			 cout << year << "的国庆节是星期日。" <<endl;
		 }
	}
}