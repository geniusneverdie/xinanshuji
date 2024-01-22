// tuoyunaquxian.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "Elliptic_Curve_Crytography.h"
#define Elliptic_Curve_EC "E_" << p << "(" << a << ',' << b << ")"
#define Point_P "P(" << x << "," << y << ")"
#include<iostream>
using namespace std;

int main()
{
    int p, a, b;
    cout << "请输入椭圆曲线的参数 p: ";
    cin >> p;
    cout << "请输入椭圆曲线的参数 a: ";
    cin >> a;
    cout << "请输入椭圆曲线的参数 b: ";
    cin >> b;

    Elliptic_Curve ec(p, a, b);
    int x, y;
    cout << endl;
    cout << "1.判断所给参数是否能构成一个椭圆曲线" << endl;
    cout << Elliptic_Curve_EC << " is ";
    if (!ec.Test_Is_Elliptic_Curve())
    {
        cout << "not ";
        return 0;
    }
    cout << "Elliptic_Curve" << endl;

    cout << endl;
    cout << "2.判断给出的点是否在给定的椭圆曲线上" << endl;
    cout << "输入 x: ";
    cin >> x;
    cout << "输入 y: ";
    cin >> y;
    cout << Point_P " is ";
    if (!ec.Is_On_Elliptic_Curve(Point(x, y))) cout << "not ";
    cout << "on " << Elliptic_Curve_EC << endl;

    cout << endl;
    cout << "3.计算给定的两点相加" << endl;
    int x1, y1, x2, y2;
    cout << "输入 x1: ";
    cin >> x1;
    cout << "输入 y1: ";
    cin >> y1;
    cout << "输入 x2: ";
    cin >> x2;
    cout << "输入 y2: ";
    cin >> y2;
    cout << "结果是" << ec.Add({ x1, y1 }, { x2, y2 }) << endl;

    cout << endl;
    cout << "4.计算给出的点的倍加" << endl;
    cout << "输入 x: ";
    cin >> x;
    cout << "输入 y: ";
    cin >> y;
    int times;
    cout << "输入倍数: ";
    cin >> times;
    cout << "结果是" << ec.Add_K_Times({ x, y }, times) << endl;

    cout << endl;
    cout << "5.计算给出的点的阶" << endl;
    cout << "输入 x: ";
    cin >> x;
    cout << "输入 y: ";
    cin >> y;
    cout << Point_P << "的阶是" << ec.Ord_Of_Point({ x, y }) << endl;

    cout << endl;
    cout << "6.计算给出的椭圆曲线的阶" << endl;
    cout << Elliptic_Curve_EC << "的阶是" << ec.Ord_Of_Elliptic_Curve() << endl;

    cout << endl;
    cout << "7.列出给出的椭圆曲线上的所有点" << endl;
    cout << ec.Show_All_Points();

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
