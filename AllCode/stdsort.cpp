#include <bits/stdc++.h>
using namespace  std;

const int maxn = 1e6+55;

double a[maxn];

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
    sort(a + 1, a + 1 + n);
    auto end = std::chrono::high_resolution_clock::now(); // Kết thúc đo
    std::chrono::duration<double> duration = end - start; // Tính thời gian chạy

    cout << "Time " << idTest << " : " << duration.count() << endl;

    return 0;
}
