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
    
    int complete_time[n+1] = {0};
    int prev = -1;
    int visited[n+1];
    for(int i=0 ; i<n ; i++){
        visited[i] = 0;
    }
    while(1){
        if(prev==-1){
            complete_time[0] = v[0].first.first + v[0].first.second;
            prev = complete_time[0];
            visited[0] = 1;
        }else{
            int minbt = INT_MAX;
            int next_process = -1;
            for(int j=0 ; j<n ; j++){
                if(v[j].first.first<=prev && visited[j]==0){
                    if(minbt>v[j].first.second){
                        minbt = v[j].first.second;
                        next_process = j;
                    }
                }
            }
            if(next_process==-1){
                for(int i=0 ; i<n ; i++){
                    if(visited[i]==0){
                        complete_time[i] = arrival_time[i] + burst_time[i];
                        visited[i] = 1;
                        prev = complete_time[i];
                        break;
                    }
                }
            }else{
                complete_time[next_process] = prev + burst_time[next_process];
                visited[next_process] = 1;
                prev = complete_time[next_process];
            }
        }
        bool stop = true;
        for(int i=0 ; i<n ; i++){
            if(visited[i]==0){
                stop = false;
            }
        }
        if(stop)break;
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