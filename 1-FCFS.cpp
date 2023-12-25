#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;  //number of process
    cin>>n; 

    vector <int> processID(n), BT(n), WT(n), TAT(n);
    int totalWT = 0, totalTAT = 0;

    for (int i = 0; i < n; i++){ 
        processID[i] = i; //assigning process IDs
    }

    for (int i = 0; i < n; i++){ 
        cin>>BT[i]; //input all BT
    }

    //Calculating waiting time
    WT[0] = 0;
    for (int i = 1; i < n; i++){ 
        WT[i] = BT[i-1]+WT[i-1];
    }

    //Calculating turn around time
    for (int i = 0; i < n; i++){ 
        TAT[i] = BT[i]+WT[i];
    }

    //Calculating total waiting time and total turnaround time
    for (int i = 0; i < n; i++){ 
        totalWT += WT[i];
        totalTAT += TAT[i];
    }
    
    //Display processes along with details
    cout<<"Process ID "<<"Burst Time "<<"Waiting Time "<<"Turn Around Time\n";
    for (int i = 0; i < n; i++){
        cout<<"\t"<<processID[i]<<"\t"<<BT[i]<<"\t"<<WT[i]<<"\t\t"<<TAT[i]<<"\n";
    }

    cout<<"Average waiting time: "<<(double)totalWT/n<<"\n";
    cout<<"Average turn around time: "<<(double)totalTAT/n<<"\n";

    return 0;
}
