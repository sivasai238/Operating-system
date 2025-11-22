#include <stdio.h>

int main() {
    int n, m, i, j, k;
    printf("Enter processes and resources: ");
    scanf("%d %d",&n,&m);

    int alloc[10][10], max[10][10], avail[10];
    int need[10][10], finish[10]={0}, safe[10], idx=0;

    printf("Enter Allocation matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&alloc[i][j]);

    printf("Enter Max matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&max[i][j]);

    printf("Enter Available:\n");
    for(i=0;i<m;i++) scanf("%d",&avail[i]);

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            need[i][j] = max[i][j] - alloc[i][j];

    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            if(!finish[i]){
                int flag=0;
                for(j=0;j<m;j++)
                    if(need[i][j] > avail[j]) flag=1;
                if(!flag){
                    safe[idx++] = i;
                    for(j=0;j<m;j++)
                        avail[j] += alloc[i][j];
                    finish[i] = 1;
                }
            }
        }
    }

    printf("\nSafe Sequence: ");
    for(i=0;i<n;i++) printf("P%d ", safe[i]);
    return 0;
}

