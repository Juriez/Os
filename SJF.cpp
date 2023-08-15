#include<bits/stdc++.h>
using namespace std;

int findelement(int arr[], int n, int target){
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}
int main(){
    int burst_time[10];
    cout<<"how much process do you want to execute?"<<endl;
    int process_num;
    cin>>process_num;
    cout<<"Enter the burst time for the respective process :"<<endl;
    for(int i=0;i<process_num;i++){
        cin>>burst_time[i];
    }
    int main_burst[process_num];
    for(int i=0;i< process_num;i++){
        main_burst[i] = burst_time[i];
    }

    //int n = sizeof(burst_time)/sizeof(burst_time[0]);
    sort(burst_time, burst_time + process_num);
    cout<<"Sorted"<<endl;
    for(int i=0;i<process_num;i++){
        cout<<burst_time[i] <<" ";
    }
    cout<<endl;
    int find_index[process_num];
    for(int i=0;i<process_num;i++){
        find_index[i] = findelement(main_burst,process_num,burst_time[i]);
    }
    /*for(int i=0;i<process_num;i++){
        cout<<"index :"<<find_index[i];
    }*/

    cout<<"Waiting time :"<<endl;
    cout<<"P"<<find_index[0]+1<<" : 0 unit"<<endl;
    float sum = 0;
    int avg_waiting[process_num];
    for(int i=0;i<process_num-1;i++){
        sum = sum + burst_time[i];
        avg_waiting[i+1] = sum;
        cout<<"P"<<find_index[i+1]+1<<" : "<<sum<<endl;
    }
    sum = 0;
    cout<<"Average waiting time : ";
    for(int i=1;i<process_num;i++){
        sum = sum + avg_waiting[i];
    }
    sum = sum/process_num;
    cout<<sum<<endl;

    int sum2=0;
    int turn_around[process_num];
    for(int i=0;i<process_num;i++){
        sum2 = sum2 + burst_time[i];
        turn_around[i] = sum2;
    }
    sum2=0;
    for(int i=0;i<process_num;i++){
        sum2 = sum2+ turn_around[i];
    }
    //sum2 = sum2 + burst_time[process_num-1];
    cout<<"Turnaround Time : " <<sum2<<endl;



}
