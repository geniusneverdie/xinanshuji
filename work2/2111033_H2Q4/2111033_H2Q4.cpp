// 2111033_H2Q4.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

//#include <iostream>
//#include<math.h>
//using namespace std;
//int getdis(int a, int b, int c, int d)
//{
//    int dx = a - c;
//    int dy = b - d;
//    return dx * dx + dy * dy;
//}
//
//int main()
//{
//    int n = 0;
//    cin >> n;
//    int x[1000], y[1000];
//    int temp = 0, temp1 = 0, temp2 = 0;
//    int d = 1000;
//    for (int i = 0; i < n; i++)
//    {
//        cin >> x[i] >> y[i];
//    }    
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = i + 1; j < n; j++)
//        {
//            temp = getdis(x[i], x[j], y[i], y[j]);
//            if (temp < d)
//            {
//                temp1 = i;
//                temp2 = j;
//            }
//        }
//    }
//    cout << temp1 << temp2;
//}


//这道题目可以使用最短路径算法进行求解，比如Dijkstra算法或Bellman - Ford算法。由于输入的数据形式比较特殊，我们可以先把点的坐标存储下来，然后根据点之间的距离构建一个图，再使用最短路径算法求解出最短路径。

//具体实现可以按照以下步骤：
//
//1. 定义点的结构体，包括x，y坐标和该点的编号。
//
//```c+ +
//
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Point {
    int x, y;
    int id;
};

int main()
{
    //```
    //2. 读入输入数据，将每个点的坐标存储在一个数组中。
    //```c+ +
    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = { x, y, i };
    }
    //```

       // 3. 根据点之间的距离构建一个邻接矩阵。为了方便，可以先计算出每两个点之间的距离。

        //```c+ +
        vector<vector<int>> dist(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int dx = points[i].x - points[j].x;
            int dy = points[i].y - points[j].y;
            dist[i][j] = dist[j][i] = sqrt(dx * dx + dy * dy);
        }
    }
   // ```

       // 4. 使用Dijkstra算法或者Bellman - Ford算法求解最短路径。以Dijkstra算法为例，我们需要先将起点的距离初始化为0，其他点的距离初始化为一个较大的值（比如INT_MAX）。

        //```c+ +
        int start = 0;
    vector<int> d(n, INT_MAX);
    d[start] = 0;
    //```
    int end = 0;
        //然后我们可以使用一个优先队列priority_queue来维护当前能够到达的点中距离最小的那个点。每次从队列中取出距离最小的点，更新它能够到达的所有点的距离。

        //```c+ +
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({ 0, start });
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();
        end++;
        for (int v = 0; v < n; v++) {
            if (d[u] + dist[u][v] < d[v]) {
                d[v] = d[u] + dist[u][v];
                q.push({ d[v], v });
            }
        }
    }
    cout << d[end];
}

//```

//5. 最终的答案即为从起点到终点的最短距离，即d[end]。

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
