// xinanshuji2.2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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


void Get_Inverse(int a, int b) {
	int r0 = a, r1 = b;
	//si = si−2 − qi−1si−1, ti = ti−2 − qi−1ti−1, 其中 qi = ri−1/r
	int s_2 = 1, s_1 = 0, t_2 = 0, t_1 = 1;
	int s, q, t, r;
	while (r0 % r1) {
		q = r0 / r1;
		s = s_2 - q * s_1;
		t = t_2 - q * t_1;
		s_2 = s_1;
		s_1 = s;
		t_2 = t_1;
		t_1 = t;
		r = r0 % r1;
		r0 = r1;
		r1 = r;
	}
	cout << "gcb(a,b)=" << r1 << endl;
	cout << "lcm(a,b)=" << a * b / r1 << endl;
	cout << "a^(-1)=" << s << "(mod " << b << ")\n";
	cout << "b^(-1)=" << t << "(mod " << a << ")\n";
}
int main() 
{
	cout << "a=";
	int x; cin >> x;
	cout << "b=";
	int y; cin >> y;
	Get_Inverse(x, y);
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
