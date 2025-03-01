#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6+55;

double randNum(double l, double r) {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_real_distribution<>(l, r)(rng);
}

double a[maxn];

signed main()
{
    ios_base::sync_with_stdio(0);
    
    ifstream inp("numTest.txt");
    string numTest;
    inp >> numTest;
    numTest += ".inp";
    inp.close();

    int n = 1e6;
    for (int i = 1; i <= n; i ++) a[i] = randNum(1e5, 1e6); 
    if (numTest == "1.inp") sort(a + 1, a + 1 + n);
    if (numTest == "2.inp") sort(a + 1, a + 1 + n, greater <double> ());

    ofstream out(numTest);
    out << n << endl;
    for (int i = 1; i <= n; i ++) out << setprecision(7) << fixed << a[i] << " ";
    out << endl;
    out.close();

    cerr << "Gen Test : " << numTest << " Successful" << endl;

    return 0;
}