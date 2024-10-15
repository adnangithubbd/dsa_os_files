#include<stdio.h>
#define MAX_PROCESS 100

struct Process{
    int id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void calculateTime(struct Process processes[],int n){
    int total_waiting=0,total_turnaround=0;
    processes[0].waiting_time=0;

    for(int i=1;i<n;i++){
        processes[i].waiting_time=processes[i-1].waiting_time+processes[i-1].burst_time;
        total_waiting+=processes[i].waiting_time;
    }
    for (int i=0;i<n;i++){
        processes[i].turnaround_time=processes[i].waiting_time+processes[i].burst_time;
        total_turnaround+=processes[i].turnaround_time;
    }
    printf("Avg waiting time %0.2f", (float)total_waiting/n );
    printf("Avg turn around time time %0.2f", (float)total_turnaround/n );

}
void displayProcess(struct Process processes[], int n) {
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time,
               processes[i].waiting_time, processes[i].turnaround_time);
    }
}
void sortProcessByBurstTime(struct Process process[],int n){
 for(int i=0;i<n-1;i++){
    for (int j=0;j<n-i-1;j++){
        if (process[j].burst_time>process[j+1].burst_time){
            struct Process temp=process[j];
            process[j]=process[j+1];
            process[j+1]=temp;
        }
    }
 }
}

int main(){
    struct Process processes[MAX_PROCESS];
    int n=4;
    processes[0]=(struct Process){1,6};
    processes[1]=(struct Process){2,8};
    processes[2]=(struct Process){3,7};
    processes[3]=(struct Process){4,3};

    sortProcessByBurstTime(processes,n);
    calculateTime(processes,n);
    // displayProcess(processes,n);
}

