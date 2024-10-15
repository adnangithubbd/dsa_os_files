#include<stdio.h>
#define MAX_PROCESS 100


struct  Process
{
int id;
int arrival;
int brust;
int waiting;
int turnaround;
};
//fcfs
void calculatetimes(struct Process processes[],int n){
    int total_waiting=0, total_turnaround=0;

    processes[0].waiting=0;

    for(int i=1;i<n;i++){
        processes[i].waiting=processes[i-1].waiting+processes[i-1].brust;
        total_waiting+=processes[i].waiting;
    }
    for (int i=0;i<n;i++){
        processes[i].turnaround=processes[i].waiting+processes[i].brust;
        total_turnaround+=processes[i].turnaround;
    }
    printf("Average waiting tme %.2f",(float)total_waiting/n);
    printf("Average turn arround time %.2f",(float)total_turnaround/n);
}





void  displayProcess(struct Process processes[],int n){
    printf("Process \t Arrival time \t Waiting time \t TurnAroundTime");
    for (int i=0;i<n;i++){
         printf("%d \t %d \t %d \t %d\n", processes[i].id, processes[i].arrival,
               processes[i].waiting, processes[i].turnaround);
    }
}

void main(){
    struct Process processes[MAX_PROCESS];
    int n=4;

 
     processes[0] = (struct Process){1, 0, 5};
    processes[1] = (struct Process){2, 1, 3};
    processes[2] = (struct Process){3, 2, 8};
    processes[3] = (struct Process){4, 3, 6};

  

    // for(int i=0;i<n-1;i++){
    //     for(int j=0;j<n-i-1;j++){
    //         if(processes[j].arrival>processes[j+1].arrival){
    //             struct Process temp=processes[j];
    //             processes[j]=processes[j+1];
    //             processes[j+1]=temp;
    //         }
    //     }
    // }

    calculatetimes(processes,n);
    // displayProcess(processes,n);

 
}
 




   // for(int i=0;i<n;i++){
    //     processes[i].id=i+1;
    //     printf("arival and burst for %d",processes[i].id);
    //     scanf("%d %d",&processes[i].arrival,&processes[i].brust);
    // }