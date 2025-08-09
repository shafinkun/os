#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("priority.txt", "r", stdin);

    int n;
    cin >> n;

    vector<int> PR, BT, CT, TAT, WT;
    vector<string> P;

    for(int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        P.push_back(s);

        int temp1;
        cin >> temp1;
        PR.push_back(temp1);

        int temp2;
        cin >> temp2;
        BT.push_back(temp2);
    }

    for(int i = 0; i < n; ++i)
    {
        for(int j = i + 1; j < n; ++j)
        {
            if(PR[i] < PR[j])
            {
                swap(PR[i], PR[j]);
                swap(BT[i], BT[j]);
                swap(P[i], P[j]);
            }
        }
    }

    CT.push_back(BT[0]);
    for(int i = 1; i < n; ++i)
    {
        CT.push_back(CT[i - 1] + BT[i]);    
    }

    for(int i = 0; i < n; ++i)
    {
        TAT.push_back(CT[i]);
        WT.push_back(TAT[i] - BT[i]);
    }

    //Grantt Chart
    cout << 0 << '\t';
    for(int i = 0; i < n; ++i)
    {
        cout << P[i] << '\t' << CT[i] << '\t';
    }

    cout << endl;

    float avg_tat = (accumulate(TAT.begin(), TAT.end(), 0))*1.0 / n;
    float avg_wt = (accumulate(WT.begin(), WT.end(), 0))*1.0 / n;

    cout << "Avg TAT: " << avg_tat << endl;
    cout << "Avg WT: " << avg_wt << endl;

    cout << "P\t" << "PR\t" << "BT\t" << "CT\t" << "TAT\t" << "WT\t" << endl;
    for(int i = 0; i < n; ++i)
    {
        cout << P[i] << '\t' << PR[i] << '\t' << BT[i] << "\t" << CT[i] << '\t' << TAT[i] << '\t' << WT[i] << endl;
    } 

    return 0;

}