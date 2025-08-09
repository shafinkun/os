#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("fcfs.txt", "r", stdin);
    int n;
    cin >> n;

    vector<int>BT, WT,TAT;
    vector<string>P;

    for(int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        P.push_back(s);

        int temp;
        cin >> temp;
        BT.push_back(temp);
    }

    TAT.push_back(BT[0]);
    WT.push_back(0);
    for(int i = 1; i < n; ++i)
    {
        TAT.push_back(TAT[i-1] + BT[i]);
        WT.push_back(TAT[i] - BT[i]);
    }


    float avg_TAT = (accumulate(TAT.begin(), TAT.end(), 0)) * 1.0 / n;
    float avg_WT = (accumulate(WT.begin(), WT.end(), 0)) * 1.0 / n;

    cout << "Process\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for(int i = 0; i < n; ++i)
    {
        cout << P[i] << "\t" << BT[i] << "\t\t"
             << TAT[i] << "\t\t" << WT[i] << endl; 
    }
    
    cout << "Gantt Chart:\n";
    cout << "0\t";
    for(int i = 0; i < n; ++i)
    {
        cout << P[i] << "\t";
        cout << TAT[i] << "\t";
    }

    cout << endl;

    cout << "Average WT: " << avg_WT << endl;
    cout << "Average TAT: " << avg_TAT << endl;

    return 0;
}