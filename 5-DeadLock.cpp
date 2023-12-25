#include <bits/stdc++.h>
using namespace std;

//Banker's Algo
int main()
{
    int n, m;
    cin>>n>>m;

    int alloc[n][m], mx[n][m];
    int totalRes[m], avail[m];
    for (int i = 0; i < m; i++){
        cin>>totalRes[i];
        avail[i] = totalRes[i];
    }
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin>>alloc[i][j];

            avail[j] -= alloc[i][j];
        }
    }
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin>>mx[i][j];
        }
    }

    int flag[n], ans[n], idx = 0;
    for (int i = 0; i < n; i++){
        flag[i] = 0;
    }
    
    int need[n][m];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            need[i][j] = mx[i][j] - alloc[i][j];
        }
    }
    

    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
            if (flag[i] == 0){
                bool curr = 0;
                for (int j = 0; j < m; j++){
                    if (need[i][j] > avail[j]){
                        curr = 1;
                        break;
                    }
                }

                if (!curr){
                    ans[idx] = i;
                    idx++;
                    for (int j = 0; j < m; j++){
                        avail[j] += alloc[i][j];
                    }
                    
                    flag[i] = 1;
                }
            }
        }
    }
    

    bool check = 1;
    for (int i = 0; i < n; i++){
        if (flag[i] == 0){
            check = 0;
            cout<<"The given sequence is not safe";
            break;
        }
    }
    
    if (check){
        cout<<"Following is the safe sequence"<<"\n";
        for (int i = 0; i < n; i++){
            cout<<"p"<<ans[i];

            if (i != n-1)
                cout<<" -> ";
        }  
    }

    return 0;
}