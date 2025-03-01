#include <bits/stdc++.h>
using namespace  std;

const int maxn = 1e6+55;

double a[maxn], b[maxn];

int partition(int l, int r)
{
    int privot = rand() % (r - l + 1) + l;
    swap(a[privot], a[r]);
    // const privot = r

    int j = l;
    for (int i = r - 1; i > j; i --)
    {
        if (a[i] < a[r])
        {
            swap(a[i], a[j]);
            j ++;
            i ++;
        }
    }

    if (a[j] > a[r]) swap(a[j], a[r]);
    else
    {
        j ++;
        swap(a[j], a[r]);
    }
    return j;

}

void quickSort(int l, int r)
{
    if (l >= r) return;

    int g = partition(l, r);

    quickSort(l, g-1);
    quickSort(g+1, r);
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

    //read id test
    ifstream inpp(idTest);
    int n;
    inpp >> n;
    for (int i = 1; i <= n; i ++) inpp >> a[i];
    inpp.close();

    srand(time(NULL));
    // measure time sorting
    auto start = std::chrono::high_resolution_clock::now();
    quickSort(1, n);
    auto end = std::chrono::high_resolution_clock::now(); // Kết thúc đo
    std::chrono::duration<double> duration = end - start; // Tính thời gian chạy

    // check ans
    for (int i = 1; i <= n; i ++) b[i] = a[i];
    sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; i ++) if (a[i] != b[i]) assert(0);

    cout << "Time " << idTest << " : " << duration.count() << endl;

    return 0;
}
