#include<bits/stdc++.h>
using namespace std;
int main(){
    
    int n;
    cin>>n;
    
    int arrival_time[n+1];
    for(int i=0 ; i<n ; i++){
        cin>>arrival_time[i];
    }

    int burst_time[n+1];
    for(int i=0 ; i<n ; i++){
        cin>>burst_time[i];
    }

    int updated_bt[n+1];
    for(int i=0 ; i<n ; i++){
        updated_bt[i] = burst_time[i];
    }


    int time = 0;
    int complete_time[n+1];
    cout<<"gangue chart ";
    while(1){
        int minbt = INT_MAX;
        int process = -1;
        for(int i=0 ; i<n ; i++){
            if(updated_bt[i]>0 && arrival_time[i]<=time){
                if(minbt>updated_bt[i]){
                    minbt = updated_bt[i];
                    process = i;
                }
                if(minbt==updated_bt[i] && arrival_time[i]<arrival_time[process]){
                    process = i;
                }
            }
        }
        time++;
        if(process!=-1){
            cout<<process+1<<" ";
            updated_bt[process]--;
            complete_time[process] = time;
        }
        bool stop = true;
        for(int i=0 ; i<n ; i++){
            if(updated_bt[i]>0)stop = false;
        }
        if(stop)break;
    }

    cout<<endl;

    // for(int i=0 ; i<n ; i++){
    //     cout<<complete_time[i]<<endl;
    // }

    int turnaround_time[n+1];

    for(int i=0 ; i<n ; i++){
        turnaround_time[i] = complete_time[i] - arrival_time[i];
    }


    int waiting_time[n+1];

    for(int i=0 ; i<n ; i++){
        waiting_time[i] = turnaround_time[i] - burst_time[i];
    }

    cout<<"Process"<<" "<<"A.T."<<" "<<"B.T"<<"  "<<"C.T."<<"   "<<"T.T"<<"   "<<"W.T"<<endl;

    for(int i=0 ; i<n ; i++){
        cout<<i<<"       "<<arrival_time[i]<<"    "<<burst_time[i]<<"    "<<complete_time[i]<<"      "<<turnaround_time[i]<<"      "<<waiting_time[i]<<endl;
    } 


}