#include <bits/stdc++.h>
using namespace  std;

const int maxn = 1e6+55;

double a[maxn], b[maxn];
int top1, top2;
double st1[maxn], st2[maxn];

void merge(int l, int r, int g)
{
    top1 = top2 = 0;
    for (int i = l; i <= g; i ++) st1[++top1] = a[i];
    for (int i = g+1; i <= r; i ++) st2[++top2] = a[i];

    int i = l;
    int id1 = 1, id2 = 1;
    while (i <= r)
    {
        assert(id1 <= top1 || id2 <= top2);
        if (id1 > top1) // Full st1
        {
            a[i ++] = st2[id2 ++];
        }
        else if (id2 > top2) // Full st2
        {
            a[i ++] = st1[id1 ++];
        }
        else if (st1[id1] <= st2[id2])
        {
            a[i ++] = st1[id1 ++];
        }
        else a[i ++] = st2[id2 ++];
    }
}

void mergeSort(int l, int r)
{
    if (l == r) return;
    int g = (l + r) >> 1;

    mergeSort(l, g);
    mergeSort(g+1, r);

    merge(l, r, g);
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
    mergeSort(1, n);
    auto end = std::chrono::high_resolution_clock::now(); // Kết thúc đo
    std::chrono::duration<double> duration = end - start; // Tính thời gian chạy

    // check ans
    for (int i = 1; i <= n; i ++) b[i] = a[i];
    sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; i ++) if (a[i] != b[i]) assert(0);

    cout << "Time " << idTest << " : " << duration.count() << endl;

    return 0;
}
