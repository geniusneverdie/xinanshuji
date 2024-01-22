#include "curve.h"
#define EC "E_" << p << "(" << a << ',' << b << ")"
#define Po "P(" << x << "," << y << ")"
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
    cout << EC << " is ";
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
    cout << Po " is ";
    if (!ec.Is_On_Elliptic_Curve(Point(x, y))) cout << "not ";
    cout << "on " << EC << endl;

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
    cout << Po << "的阶是" << ec.Ord_Of_Point({ x, y }) << endl;

    cout << endl;
    cout << "6.计算给出的椭圆曲线的阶" << endl;
    cout << EC << "的阶是" << ec.Ord_Of_Elliptic_Curve() << endl;

    cout << endl;
    cout << "7.列出给出的椭圆曲线上的所有点" << endl;
    cout << ec.Show_All_Points();

    return 0;
}