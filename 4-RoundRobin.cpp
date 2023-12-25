#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int MAX = 1e7+5;


void solve(){
    int n;
    cout<<"Enter the number of process: ";
    cin>>n;

    vector <int> bt(n+5), wt(n+5), tat(n+5);
    cout<<"Enter the burst time:"<<"\n";
    deque < pair <int, int> > dq;
    for(int i = 0; i < n; i++){
        cout<<"Process "<<i<<" :";
        cin>>bt[i];
        dq.push_back({bt[i], i});
    }

    cout<<"Enter the size of time slice: ";
    int TimeSlice;
    cin>>TimeSlice;

    for(int i = 0; i < n; i++){
        wt[i] = 0;
    }

    while(!dq.empty()){
        int x = dq.front().first;
        int idx = dq.front().second;
        dq.pop_front();

        for(int i = 0; i < dq.size(); i++){
            wt[dq[i].second]+=min(TimeSlice,x);
        }    

        x -= TimeSlice;

        if(x > 0)
            dq.push_back({x,idx});
    }

    double avgWT = 0, avgTAT = 0;
    for(int i = 0; i < n; i++){
        avgWT += wt[i];
        tat[i] = wt[i] + bt[i];
        avgTAT += tat[i];
    }

    avgTAT /= n;
    avgWT /= n;
    cout<<"\n";

    cout<<"PROCESS\tBT\tWT\tTAT\n";
    for(int i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\n", i, bt[i], wt[i], tat[i]);

    cout<<"Average Turnaround Time: ";
    printf("%2f\n", avgTAT);
    cout<<"Average Waiting Time: ";
    printf("%2f\n", avgWT);
    cout<<"\n";
}

int main()
{
    int tc = 1;
    cin>>tc;
    while (tc--){
        solve();
        cout<<"\n";
    }

    return 0;
}