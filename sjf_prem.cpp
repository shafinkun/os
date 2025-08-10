#include <bits/stdc++.h>
using namespace std;

int main()
{

    freopen("sjf_prem.txt", "r", stdin);
    int n;
    cin >> n;
    vector<string> P(n), gantt;
    vector<int> BT(n), rBT(n), CT(n), TAT(n), WT(n);

    for (int i = 0; i < n; i++)
    {
        cin >> P[i] >> BT[i];
        rBT[i] = BT[i];
    }

    // for (auto x : P)
    //     cout << x << " ";
    // cout << endl;
    // for (auto x : BT)
    //     cout << x << " ";
    // cout << endl;

    int completed = 0, currentTime = 0;
    while (completed < n)
    {
        int index = -1;
        int min_rBT = INT_MAX;

        // Find P with shortest remaining burst time which is not finished
        for (int i = 0; i < n; i++)
        {
            if (rBT[i] > 0 && rBT[i] < min_rBT)
            {
                min_rBT = rBT[i];
                index = i;
            }
        }

        // All done or no P to run (shouldn't happen without arrival time)
        if (index == -1)
            break;

        // Run P for 1 unit time
        rBT[index]--;
        currentTime++;
        gantt.push_back(P[index]);

        if (rBT[index] == 0)
        {
            completed++;
            CT[index] = currentTime;
        }
    }

    // Calculate TAT and WT
    for (int i = 0; i < n; i++)
    {
        TAT[i] = CT[i]; // Arrival time = 0, so TAT = CT - 0 = CT
        WT[i] = TAT[i] - BT[i];
    }

    // Print Gantt chart
    cout << "Gantt Chart (P execution order):\n";
    for (auto &p : gantt)
        cout << p << " -> ";
    cout << "end\n\n";

    // keep only the single P
    gantt.erase(unique(gantt.begin(), gantt.end()), gantt.end());
    // Print table
    cout << "P   Burst Time   Completion Time   Turn Around Time   Waiting Time\n";
    for (int i = 0; i < n; i++)
    {
        cout << gantt[i] << "            " << BT[i] << "             " << CT[i] << "                 " << TAT[i] << "                 " << WT[i] << "\n";
    }

    float avgTAT = accumulate(TAT.begin(), TAT.end(), 0.0f) / n;
    float avgWT = accumulate(WT.begin(), WT.end(), 0.0f) / n;

    cout << "\nAverage Turn Around Time: " << avgTAT << endl;
    cout << "Average Waiting Time: " << avgWT << endl;

    return 0;
}