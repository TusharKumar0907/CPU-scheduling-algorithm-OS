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

    //{{arrival time , burst time} , process}
    vector<pair<pair<int,int> , int>>v;
    for(int i=0 ; i<n ; i++){
        v.push_back({{arrival_time[i] , burst_time[i]} , i+1});
    }
    
    sort(v.begin() , v.end());
    
    int complete_time[n+1];
    int prevct = -1;
    for(int i=0 ; i<n ; i++){
        pair<pair<int,int> , int>x = v[i];
        int curr_arrival = x.first.first;
        int curr_burst = x.first.second;
        if(prevct<=curr_arrival){
            complete_time[i] = curr_arrival + curr_burst;
            prevct = complete_time[i];
        }else{
            complete_time[i] = prevct + curr_burst;
            prevct = complete_time[i];
        }
    }

    int turnaround_time[n+1];

    for(int i=0 ; i<n ; i++){
        turnaround_time[i] = complete_time[i] - v[i].first.first;
    }


    int waiting_time[n+1];

    for(int i=0 ; i<n ; i++){
        waiting_time[i] = turnaround_time[i] - v[i].first.second;
    }

    cout<<"Process"<<" "<<"A.T."<<" "<<"B.T"<<" "<<"C.T."<<" "<<"T.T"<<" "<<"W.T"<<endl;

    for(int i=0 ; i<n ; i++){
        cout<<v[i].second<<"       "<<v[i].first.first<<"    "<<v[i].first.second<<"   "<<complete_time[i]<<"    "<<turnaround_time[i]<<"   "<<waiting_time[i]<<endl;
    }

}