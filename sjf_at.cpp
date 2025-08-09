#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("sjf_at.txt", "r", stdin);

    int n;
    cin >> n;

    vector<int> AT, BT, CT, TAT, WT;
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

    //sorting
    for(int i = 0; i < n; ++i)
    {
        for(int j = i + 1; j < n; ++j)
        {
            if(BT[i] > BT[j])
            {
                swap(BT[i], BT[j]);
                swap(P[i], P[j]);
                swap(AT[i], AT[j]);
            }
        }
    }

    deque<int> idol;
    CT.push_back(BT[0] + AT[0]);
    for(int i = 1; i < n; ++i)
    {
        if(CT[i - 1] < AT[i])
        {    
            idol.push_back(AT[i]);
            CT.push_back(CT[i] + BT[i]);
        }
        else
            CT.push_back(CT[i - 1] + BT[i]);
    }
    CT.push_back(AT[0] + BT[0]);
    for(int i = 1; i < n; ++i)
    {
        if(CT[i - 1] < AT[i])
        {
            idol.push_back(AT[i]);
            CT.push_back(AT[i] + BT[i]);
        }
        else
            CT.push_back(CT[i - 1] + BT[i]);
    }

    cout << "Grantt Chart: \n";

    cout << AT[0] << "\t";
    for(int i = 0; i < n; ++i)
    {
        if(idol.front() > CT[i] and !idol.empty())
        {
            cout << P[i] << '\t' << CT[i] << '\t';
            cout << "Idle" << '\t' << idol.front() << '\t';
            idol.erase(idol.begin());
        }
        else 
            cout << P[i] << '\t' << CT[i] << '\t';
    }

    cout << endl;

    for(int i = 0; i < n; ++i)
    {
        TAT.push_back(CT[i] - AT[i]);
        WT.push_back(TAT[i] - BT[i]);
    }

    float avg_TAT = (accumulate(TAT.begin(), TAT.end(), 0)) * 1.0 / n;
    float avg_WT = (accumulate(WT.begin(), WT.end(), 0)) * 1.0 / n;

    cout << "Avg TAT: " << avg_TAT << endl;
    cout << "Avg  WT: " << avg_WT << endl;

    cout << "P" << "\t\t" << "BT" << "\t\t" << "CT" << "\t\t" << "TAT" << "\t\t" << "WT" << endl;

    for(int i = 0; i < n; ++i)
    {
        cout << P[i] << "\t\t" << BT[i] << "\t\t" << CT[i] << "\t\t" << TAT[i] << "\t\t" << WT[i] << endl;
    }

    return 0;
}