#include<stdio.h>

#define MAX_FRAMES 3

int isPageInFrame(int frames[],int page,int n){
    for (int i=0;i<n;i++){
        if (frames[i]==page){
            return i;
        }
    }
   
   return -1;
}

void printFrames(int frames[],int n){
    for (int i=0;i<n;i++){
        if (frames[i]==-1){
            printf(" - ");
        }else{
            printf("%d ",frames[i] );
        }
    }
    printf("\n");
}

int main(){
    int pages[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
    
    int n=sizeof(pages)/sizeof(pages[0]);

    int frames[MAX_FRAMES];
    int counters[MAX_FRAMES];

    for (int i=0;i<MAX_FRAMES;i++){
        frames[i]=-1;
        counters[i]=0;
    }
    int page_faults=0;

    for(int i=0;i<n;i++){
        int page=pages[i];

        int index=isPageInFrame(frames,page,MAX_FRAMES);
        if (index==-1){
            page_faults++;
            int lru_index=0;
            for (int j=1;j<MAX_FRAMES;j++){
                if (counters[j]<counters[lru_index]){
                    lru_index=j;
                }
            }
            frames[lru_index]=page;
            counters[lru_index]=i;
          }else{
            counters[index]=i;
          }
          printf("counter frames");
          printFrames(frames,MAX_FRAMES);
    }
    printf("\n Total page faults\n",page_faults);
    return 0;

    
    }