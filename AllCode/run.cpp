#include <bits/stdc++.h>
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int ntest = 10;
    for (int itest = 1; itest <= ntest; itest ++) 
    {
        ofstream out("numTest.txt");
        out << itest;
        out.close();
        
        string tmp;
        // tmp = "GenTest.exe";
        // tmp = "stdsort.exe";
        // tmp = "heapsort.exe";
        // tmp = "mergesort.exe";
        tmp = "quicksort.exe";
        
        system(tmp.c_str());   
    }
    
    return 0;
}
