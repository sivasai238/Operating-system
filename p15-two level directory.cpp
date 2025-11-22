#include <stdio.h>
#include <string.h>

int main() {
    int n, f, i, j;
    char user[10][20], file[10][10][20];
    
    printf("Enter number of users: ");
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        printf("User %d name: ", i+1);
        scanf("%s", user[i]);
        printf("No. of files: ");
        scanf("%d",&f);
        for(j=0;j<f;j++){
            printf("File %d: ", j+1);
            scanf("%s", file[i][j]);
        }
    }

    printf("\nTwo-Level Directory Structure:\n");
    for(i=0;i<n;i++){
        printf("\nUser: %s\nFiles:\n", user[i]);
        for(j=0;j<10 && strlen(file[i][j])>0;j++)
            printf("%s\n", file[i][j]);
    }
    return 0;
}

