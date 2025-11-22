#include <stdio.h>
#include <string.h>

int main() {
    char dir[20], files[20][20];
    int n, i;
    
    printf("Enter directory name: ");
    scanf("%s", dir);
    printf("Enter number of files: ");
    scanf("%d", &n);

    for(i=0;i<n;i++){
        printf("Enter file %d: ", i+1);
        scanf("%s", files[i]);
    }

    printf("\nDirectory: %s\nFiles:\n", dir);
    for(i=0;i<n;i++)
        printf("%s\n", files[i]);

    return 0;
}

