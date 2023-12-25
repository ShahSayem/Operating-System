#include <bits/stdc++.h>
using namespace std;

//Priority Scheduling - Non preemptive
int main()
{
    cout<<"Enter number of process: ";
    int n;  //number of process
    cin>>n; 

    vector <int> WT(n), TAT(n);
    int totalWT = 0, totalTAT = 0;

                //Priority    ID   BT
    vector < pair <int, pair <int, int>> > BT(n);
    int priority, bt;
    cout<<"Enter BT and Priority for process 1-n:\n";
    for (int i = 0; i < n; i++){ 
        cin>>bt>>priority;      //input all BT and priority
        BT[i] = {priority, {i+1, bt}}; 
    }
    sort(BT.begin(), BT.end());
    

    //Calculating waiting time
    WT[0] = 0;
    for (int i = 1; i < n; i++){ 
        WT[i] = BT[i-1].second.second + WT[i-1];
    }

    //Calculating turn around time
    for (int i = 0; i < n; i++){ 
        TAT[i] = BT[i].second.second + WT[i];
    }

    //Calculating total waiting time and total turnaround time
    for (int i = 0; i < n; i++){ 
        totalWT += WT[i];
        totalTAT += TAT[i];
    }
    
    //Display processes along with details
    cout<<"Process ID "<<"Burst Time "<<"Waiting Time "<<"Turn Around Time\n";
    for (int i = 0; i < n; i++){
        cout<<"\t"<<BT[i].second.first<<"\t"<<BT[i].second.second<<"\t"<<WT[i]<<"\t\t"<<TAT[i]<<"\n";
    }

    cout<<"Average waiting time: "<<(double)totalWT/n<<"\n";
    cout<<"Average turn around time: "<<(double)totalTAT/n<<"\n";

    return 0;
}
