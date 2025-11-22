#include <stdio.h>

int main() {
    int b[10], p[10], nb, np, i, j;
    printf("Enter no of blocks: ");
    scanf("%d", &nb);
    printf("Enter block sizes: ");
    for(i=0;i<nb;i++) scanf("%d",&b[i]);
    
    printf("Enter no of processes: ");
    scanf("%d",&np);
    printf("Enter process sizes: ");
    for(i=0;i<np;i++) scanf("%d",&p[i]);

    printf("\nFirst Fit Allocation:\n");
    int alloc[10]={0};
    int bs[10];
    for(i=0;i<nb;i++) bs[i]=b[i];

    for(i=0;i<np;i++){
        for(j=0;j<nb;j++){
            if(bs[j] >= p[i]){
                alloc[i] = j+1;
                bs[j] -= p[i];
                break;
            }
        }
        if(!alloc[i]) printf("P%d Not Allocated\n", i+1);
        else printf("P%d Allocated in B%d\n", i+1, alloc[i]);
    }
    return 0;
}

