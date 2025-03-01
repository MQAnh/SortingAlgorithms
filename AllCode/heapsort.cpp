#include <bits/stdc++.h>
using namespace  std;

const int maxn = 1e6+55;

double a[maxn], b[maxn];

void heapify(double a[], int n, int node) 
{
    int LeftNode = node * 2;
    int RightNode = node * 2 + 1;

    int mxNode = node;
    if (LeftNode <= n && a[mxNode] < a[LeftNode]) mxNode = LeftNode;
    if (RightNode <= n && a[mxNode] < a[RightNode]) mxNode = RightNode;

    if (mxNode != node) 
    {
        swap(a[node], a[mxNode]);
        heapify(a, n, mxNode);
    }
}

void heapSort(double a[], int n)
{
    for (int i = n / 2; i >= 1; i --) heapify(a, n, i);
    
    for (int i = n; i >= 1; i --) 
    {
        swap(a[i], a[1]);
        n --;
        heapify(a, n, 1);
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    // read numTest
    ifstream inp("numTest.txt");
    string idTest; 
    inp >> idTest;
    idTest += ".inp";
    inp.close();

    // read id test
    ifstream inpp(idTest);
    int n;
    inpp >> n;
    for (int i = 1; i <= n; i ++) inpp >> a[i];
    inpp.close();
    
    // measure time sorting
    auto start = std::chrono::high_resolution_clock::now();
    heapSort(a, n);
    auto end = std::chrono::high_resolution_clock::now(); // Kết thúc đo    
    std::chrono::duration<double> duration = end - start; // Tính thời gian chạy

    // check ans
    for (int i = 1; i <= n; i ++) b[i] = a[i];
    sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; i ++) if (a[i] != b[i]) assert(0);

    cout << "Time " << idTest << " : " << duration.count() << endl;       

    return 0;
} 