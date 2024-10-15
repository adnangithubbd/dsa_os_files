#include<stdio.h>

// m block size n process 
// blocks, block_numer, processes, process_number
//প্রসেস গুলো নিয়ে ব্লক খুজব যে কোথায় ফিট করে । 


void firstfit(int blocksize[],int m,int processsize[],int n){
    int allocation[n];
    for (int i=0;i<n;i++){
         allocation[i]=-1;
    }

    for(int i=0;i<n;i++){ // process n
        for (int j=0;j<m;j++){ // block m 
            if(blocksize[j]>=processsize[i]){
                allocation[i]=j;
                blocksize[j]-=processsize[i];
                break;
            }
        }
    }
    
        printf("\n Process No. \t Process Size \t Block No. \n");
        for (int i=0;i<n;i++){
            printf("%d \t %d",i+1, processsize[i]);
            if (allocation[i]!=-1){
                printf(" %d \n",allocation[i]+1);
            }else{
                printf(" Not allocated \n");
            }
        }

}

void bestfit(int blocksize[], int m, int processsize[],int n){
    int allocation[n];
    for(int i=0;i<n;i++){
        allocation[i]=-1;
    }
    for(int i=0;i<n;i++){ //iterate through process
        int bestIdx=-1;
        for(int j=0;j<n;j++){ // iterate through block 
            if(blocksize[j]>=processsize[i]){
                if(bestIdx==-1|| blocksize[j]<blocksize[bestIdx]){
                    bestIdx=j;
                }
            }
            if(bestIdx!=-1){
                allocation[i]=bestIdx;
                blocksize[bestIdx]-=processsize[i];
            }
        }

    }
}


void worstfit(int blocksize[],int m,int processsize[],int n){
    int allocatoin[n];

    for(int i=0;i<n;i++){
        allocatoin[i]=-1;
    }

    for(int i=0;i<n;i++){
        int worstIdx=-1;
        for(int j=0;j<m;j++){
            if (blocksize[j]>=processsize[i]){
                if(worstIdx==-1 || blocksize[j]>processsize[worstIdx]){
                    worstIdx=j;
                }
            }

            if(worstIdx!=-1){
                allocatoin[i]=worstIdx;
                blocksize[worstIdx]-=processsize[i];
            }
        }
    }
     printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < n; i++) {
        printf("\t\t%d\t\t%d\t\t", i + 1, processsize[i]);
        if (allocatoin[i] != -1)
            printf("%d\n", allocatoin[i] + 1);
        else
            printf("Not Allocated\n");
    }
}


int main(){
  int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};
    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);

    worstfit(blockSize, m, processSize, n);

    return 0;
}