#include<stdio.h>
#define MAX_CAPACITY 100


int is_in_memory(int memory[],int capacity,int page){
    for(int i=0;i<capacity;i++){
        if (memory[i]==page){
            return 1;
        }
    }
    return 0;
}

int fifo_page_replacement(int pages[],int n,int capacity){
    int memory[MAX_CAPACITY];
    int page_fault=0;
    int index=0;

    for (int i=0;i<capacity;i++){
        memory[i]=-1;
    }
    for(int i=0;i<n;i++){
        int page=pages[i];
        if(!is_in_memory(memory,capacity,page)){
            page_fault++;
            memory[index]=page;
            index=(index+1)%capacity;
        }
    }
return page_fault;
}
int main(){
        int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
        int n=sizeof(pages)/sizeof(pages[0]);
        int capacity=3;
        int pagefaults=fifo_page_replacement(pages,n,capacity);
        printf("Total page fault %d",pagefaults);
}

/*
  for (int j=0;j<capacity;j++){
                    if (memory[j]!=-1){
                        printf("%d ",memory[j]);
                    }else{
                        printf(" - ");
                    }
                    printf("\n");
                }


*/