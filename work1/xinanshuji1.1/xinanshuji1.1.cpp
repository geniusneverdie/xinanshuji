// xinanshuji1.1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
using namespace std;

//筛法求素数
void init(int minnum, int maxnum)
{
	int cnt = 0;
	bool* is_prime = new bool[maxnum - 1];
	for (int i = 0; i <= maxnum - 1; i++)
		is_prime[i] = true;
	if (minnum == 1 || minnum == 2)
	{
		is_prime[minnum - 1] = false;
	}
	for (int i = 2; i <= maxnum - minnum; i++)
	{
		if (is_prime[i])
		{
			if (cnt)
			{
				cout << ',';
			}
			if(i>minnum){
			cout << i;//边筛边打印素数
			
			cnt++;
			}
			for (int j = 2 * i; j <= maxnum; j += i)
				is_prime[j] = false;
		}
	}
	cout << endl;
	cout << "Total:" << cnt << endl;
}

int main()
{
	//输入
	cout << "Please input the range:" << endl;
	string str;
	cin >> str;
	//转换
	int len = str.length();
	int numS = 0, numB = 0;
	bool cho = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == '-')
		{
			cho = !cho;
			continue;
		}
		if (!cho)
		{
			numS = numS * 10 + str[i] - '0';
		}
		else
		{
			numB = numB * 10 + str[i] - '0';
		}
	}
	//调用筛法
	init(numS, numB);
	return 0;
}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
