#include <stdio.h>
#define MAX_PROCESS 4
struct Process {
    int id;              
    int burst_time;      
    int remaining_time;  
    int waiting_time;   
    int turnaround_time;  
};

void calculateRoundRobin(struct Process processes[],int n,int quantum){
    int total_waiting=0,total_turnaround=0;
    int current_time=0;
    int completed=0;

    while(completed<n){
        for (int i=0;i<n;i++){
            if (processes[i].remaining_time>0){
                if (processes[i].remaining_time>quantum){
                    current_time+=quantum;
                    processes[i].remaining_time-=quantum;
                }else{
                    current_time+=processes[i].remaining_time;
                    processes[i].waiting_time=current_time-processes[i].burst_time;
                    processes[i].turnaround_time=current_time;
                    
                    processes[i].remaining_time=0;
                    completed++;
                }
            }
        }
    }

    for (int i=0;i<n;i++){
        total_waiting+=processes[i].waiting_time;
        total_turnaround+=processes[i].turnaround_time;
    }

        printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");

        for(int i=0;i<n;i++){
            printf("\t%d\t%d\t%d\t%d \n",processes[i].id,processes[i].burst_time,
            processes[i].waiting_time,processes[i].turnaround_time );
        }
        printf("\n Avg waiting time : %0.2f",(float)total_waiting/n);
        printf("\n Avg turnAround  time : %0.2f",(float)total_turnaround/n);

}

void main(){
    int n=4,quantum;
    struct Process processes[MAX_PROCESS];

     // Set up example processes
    n = 4;
    quantum = 2; // Time quantum for Round Robin
    processes[0] = (struct Process){1, 6, 6, 0, 0}; // {id, burst_time, remaining_time, waiting_time, turnaround_time}
    processes[1] = (struct Process){2, 8, 8, 0, 0};
    processes[2] = (struct Process){3, 7, 7, 0, 0};
    processes[3] = (struct Process){4, 3, 3, 0, 0};

    calculateRoundRobin(processes,n,quantum);
    

    }