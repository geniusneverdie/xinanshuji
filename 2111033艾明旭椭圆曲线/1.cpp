#include "curve.h"
#define EC "E_" << p << "(" << a << ',' << b << ")"
#define Po "P(" << x << "," << y << ")"
#include<iostream>
using namespace std;

int main()
{
    int p, a, b;
    cout << "��������Բ���ߵĲ��� p: ";
    cin >> p;
    cout << "��������Բ���ߵĲ��� a: ";
    cin >> a;
    cout << "��������Բ���ߵĲ��� b: ";
    cin >> b;

    Elliptic_Curve ec(p, a, b);
    int x, y;
    cout << endl;
    cout << "1.�ж����������Ƿ��ܹ���һ����Բ����" << endl;
    cout << EC << " is ";
    if (!ec.Test_Is_Elliptic_Curve())
    {
        cout << "not ";
        return 0;
    }
    cout << "Elliptic_Curve" << endl;

    cout << endl;
    cout << "2.�жϸ����ĵ��Ƿ��ڸ�������Բ������" << endl;
    cout << "���� x: ";
    cin >> x;
    cout << "���� y: ";
    cin >> y;
    cout << Po " is ";
    if (!ec.Is_On_Elliptic_Curve(Point(x, y))) cout << "not ";
    cout << "on " << EC << endl;

    cout << endl;
    cout << "3.����������������" << endl;
    int x1, y1, x2, y2;
    cout << "���� x1: ";
    cin >> x1;
    cout << "���� y1: ";
    cin >> y1;
    cout << "���� x2: ";
    cin >> x2;
    cout << "���� y2: ";
    cin >> y2;
    cout << "�����" << ec.Add({ x1, y1 }, { x2, y2 }) << endl;

    cout << endl;
    cout << "4.��������ĵ�ı���" << endl;
    cout << "���� x: ";
    cin >> x;
    cout << "���� y: ";
    cin >> y;
    int times;
    cout << "���뱶��: ";
    cin >> times;
    cout << "�����" << ec.Add_K_Times({ x, y }, times) << endl;

    cout << endl;
    cout << "5.��������ĵ�Ľ�" << endl;
    cout << "���� x: ";
    cin >> x;
    cout << "���� y: ";
    cin >> y;
    cout << Po << "�Ľ���" << ec.Ord_Of_Point({ x, y }) << endl;

    cout << endl;
    cout << "6.�����������Բ���ߵĽ�" << endl;
    cout << EC << "�Ľ���" << ec.Ord_Of_Elliptic_Curve() << endl;

    cout << endl;
    cout << "7.�г���������Բ�����ϵ����е�" << endl;
    cout << ec.Show_All_Points();

    return 0;
}