#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("fcfs_at.txt", "r", stdin);
    int n;
    cin >> n;

    vector<int> AT, BT, CT, WT, TAT;
    vector<string> P;
    for(int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        P.push_back(s);
        int temp1;
        cin >> temp1;
        AT.push_back(temp1);
        int temp2;
        cin >> temp2;  
        BT.push_back(temp2);
    }

    for(int i = 0; i < n; ++i)
    {
        for(int j = i + 1; j < n; ++j)
        {
            if(AT[i] > AT[j])
            {
                swap(AT[i], AT[j]);
                swap(BT[i], BT[j]);
                swap(P[i], P[j]);
            }
        }
    }
    
    CT.push_back(BT[0] - AT[0]);
    for(int i = 1; i < n; ++i)
    {
        CT.push_back(CT[i-1] + BT[i]);
    }
    
    for(int i = 0; i < n; ++i)
    {
        TAT.push_back(CT[i] - AT[i]);
        WT.push_back(TAT[i] - BT[i]);
    }

    //Grantt Chart
    cout << 0 << "\t";
    for(int i = 0; i < n; ++i)
    {
        cout << P[i] << "\t";
        cout << CT[i] << "\t";
    }

    cout << endl;

    cout << endl;

    float avg_TAT = (accumulate(TAT.begin(), TAT.end(), 0)) * 1.0 / n;
    float avg_WT = (accumulate(WT.begin(), WT.end(), 0)) * 1.0 / n;

    cout << "Average WT: " << avg_WT<< endl;
    cout << "Average TAT: " << avg_TAT << endl;

    cout << endl;

    cout << 'P' << "\t" << "AT" << "\t\t" 
             << "BT" << "\t\t" << "CT" << "\t\t"
             << "CT" << "\t\t" << "WT" << endl;

    for(int i = 0; i < n; ++i)
    {
        cout << P[i] << "\t" << AT[i] << "\t\t" 
             << BT[i] << "\t\t" << CT[i] << "\t\t"
             << TAT[i] << "\t\t" << WT[i] << endl;
    }

}