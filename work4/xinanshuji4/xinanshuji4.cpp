// xinanshuji4.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<math.h>
using namespace std;
const int maxn = 100;
long long prime[maxn];
int cnt = 0;

void make_prime(long long x) {
     for (int i = 2; i * i <= x; i++) 
	 {
         if (x % i == 0) 
		 {
             prime[cnt++] = i;
             while (x % i == 0) 
			 {
                x /= i;				
			 }			
		 }		
	 }
	    if (x > 1) 
		{
		         prime[cnt++] = x;		
	    }	
}

long long get_pow(long long x, int n, int mod) 
{
	    long long ans = 1;
	    while (n) 
		{
		        if (n & 1) //n的末尾数字为1
				{
			            ans = ans * x % mod;
			    }
		        x = x * x % mod;
		        n >>= 1;//按位右移一位
	    }
	    if (ans < 0) 
		{
		         ans += mod;
		}
	    return ans;	
}

int maxi(int a, int b) {
	int i = 0;
	while (b != 0) {
		i = a % b;
		a = b;
		b = i;
	}
	return a;
}//求最大公因数的函数

int main(void) {
	cout << "Please input n(n>0):";
	long long  m;
	cin >> m;
	//cout << m << endl;
    make_prime(m - 1);
	int temp = 0;
    for (int i = 2; i < m; i++) 
	{
	         int flag = 1;
	         for (int j = cnt-1;j>=0;j--) 
			 {
	             int x = (m - 1) / prime[j];
	             if (get_pow(i, x, m) == 1) {
	                 flag = 0;
	                 break;	
			     }
			 }
	         if (flag)
			 {				 
				 temp = i;
				 break;
		     }			 
	}
	int g = temp;	
	cout << "The min primitive root of " << m << ": g=" << temp<<endl;
	cout << "The ind_table of " << m << " based on g=" << temp << " is:"<<endl;
	int oula = 0;
	for (int t = 1; t < m; t++) {
		if (maxi(m, t) == 1) {
			oula++;
		}
	}//求欧拉函数
	int r = 0;
	int shii = oula / 10;//记录十位数字
	shii++;
	int** ans = new int* [shii];
	for (int i = 0; i < shii; i++)
		ans[i] = new int[10];//声明最后的数组
	for (int i = 0; i < shii; i++) {
		for (int j = 0; j < 10; j++) {
			ans[i][j] = -1;//先把初值全部赋值为-1
		}
	}
	int* t = new int[oula];//记录g的r次方的同余值
	for (r = 0; r < oula; r++) {
		if (r == 0) {
			t[0] = 1;//欧拉函数为1
		}
		else {
			t[r] = t[r - 1] * g;
			t[r] = fmod(t[r], m);
		}
		int shi = t[r] / 10;
		int ge = t[r] % 10;
		ans[shi][ge] = r;
	}
	cout << "    ";//一些输出格式控制语句
	for (int i = 0; i < 10; i++) {
		cout << i << "  ";
	}
	cout << endl;
	cout << "___";
	for (int i = 0; i < 10; i++) {
		cout << "___";
	}
	cout << endl;
	for (int i = 0; i < shii; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				cout << " " << i << " |";
			}
			if (ans[i][j] == -1) {
				cout << "   ";
			}
			else {
				cout << ans[i][j] << " ";
				if (ans[i][j] / 10 == 0) {
					cout << " ";
				}
			}
		}
		cout << endl;
	}
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
