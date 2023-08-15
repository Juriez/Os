#include<bits/stdc++.h>
using namespace std;
int main()
{
    int burst_time[10];
    cout<<"how much process do you want to execute?"<<endl;
    int process_num;
    cin>>process_num;
    cout<<"Enter the burst time for the respective process :"<<endl;
    for(int i=0;i<process_num;i++){
        cin>>burst_time[i];
    }
    cout<<"Waiting time :"<<endl;
    cout<<"P1 : 0 unit"<<endl;
    float sum = 0;
    int avg_waiting[process_num];
    for(int i=0;i<process_num-1;i++){
        sum = sum + burst_time[i];
        avg_waiting[i+1] = sum;
        cout<<"P"<<(i+2)<<" : "<<sum<<endl;
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
