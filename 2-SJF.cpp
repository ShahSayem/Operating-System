#include <bits/stdc++.h>
using namespace std;

//SJF
int main()
{
    int n;  //number of process
    cin>>n; 
                  //BT //ID
    vector < pair <int, int> > process(n);
    vector <int> WT(n), TAT(n);
    int totalWT = 0, totalTAT = 0;

    for (int i = 0; i < n; i++){ 
        process[i].second = i+1; //assigning process IDs
    }

    for (int i = 0; i < n; i++){ 
        cin>>process[i].first; //input all BT
    }
    //sort the vector
    sort(process.begin(), process.end());

    //Calculating waiting time
    WT[0] = 0;
    for (int i = 1; i < n; i++){ 
        WT[i] = process[i-1].first+WT[i-1];
    }

    //Calculating turn around time
    for (int i = 0; i < n; i++){ 
        TAT[i] = process[i].first+WT[i];
    }

    //Calculating total waiting time and total turnaround time
    for (int i = 0; i < n; i++){ 
        totalWT += WT[i];
        totalTAT += TAT[i];
    }
    
    //Display processes along with details
    cout<<"Process ID "<<"Burst Time "<<"Waiting Time "<<"Turn Around Time\n";
    for (int i = 0; i < n; i++){
        cout<<"\t"<<process[i].second<<"\t"<<process[i].first<<"\t"<<WT[i]<<"\t\t"<<TAT[i]<<"\n";
    }

    cout<<"Average waiting time: "<<(double)totalWT/n<<"\n";
    cout<<"Average turn around time: "<<(double)totalTAT/n<<"\n";

    return 0;
}
