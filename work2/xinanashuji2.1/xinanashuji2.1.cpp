// xinanashuji2.1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include<iostream>
using namespace std;
int Square_Multi(int a, int  n, int m) {
	int c = 1;
	int binary[100];
	int k = 0; //length of the number n
	while (n) {
		binary[k] = n % 2;
		n /= 2;
		k++;
	}
	while (k) {
		k--; //current index of binary_array
		c = (c * c) % m;
		if (binary[k])
			c = (c * a) % m;

	}

	return c;
}

int main() {
	cout << "Calulate a^n(mod m)...\nPlease input: ";
	cout << "\n  a=";
	int a; cin >> a;
	cout << "  n=";
	int n; cin >> n;
	cout << "  m=";
	int m; cin >> m;
	int r = Square_Multi(a, n, m);
	cout << a << "^" << n << "(mod " << m << ")=" << r;
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
