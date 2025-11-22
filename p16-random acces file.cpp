#include <stdio.h>

struct emp {
    int id;
    char name[20];
    float salary;
};

int main() {
    FILE *fp;
    struct emp e;
    int pos;

    fp = fopen("emp.dat", "wb+");

    printf("Enter employee id name salary: ");
    scanf("%d %s %f", &e.id, e.name, &e.salary);
    fwrite(&e, sizeof(e), 1, fp);

    printf("Enter record position to read (0): ");
    scanf("%d", &pos);

    fseek(fp, pos * sizeof(e), SEEK_SET);
    fread(&e, sizeof(e), 1, fp);
    
    printf("ID: %d Name: %s Salary: %.2f\n", e.id, e.name, e.salary);
    fclose(fp);
    return 0;
}

