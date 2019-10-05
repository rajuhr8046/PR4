#include <stdio.h>
#include <stdlib.h>

struct employee
{
    int employee_id,salary,age;
    char name[25],department[25];
}e[3];

void read(void);
void display(void);
void search(void);

int main()
{
    read();
    display();     //write details of employee to a file
    search();         //searching details of employee using employee_id
    return 0;
}

void read(void)
{
    int i;
    printf("don't give spaces in between the name and department,instead of using speces, use underscore(_) \n\n");
    printf("details are employee_id,name,department,salary,age\n");
    for(i=0;i<3;i++)
    {
        printf("enter the details of employee %d\n",i+1);
        scanf("%d%s%s%d%d",&e[i].employee_id,e[i].name,e[i].department,&e[i].salary,&e[i].age);
        printf("\n");
    }
}
void display(void)
{
    int j;
    FILE *fp1;
    fp1=fopen("employee_info.txt","w");
    if(fp1==NULL)
    {
        printf("error in opening a file\n");
        exit(0);
    }

    //fprintf(fp1,"%s\t%s\t\t%s\t\t%s\t\t%s\n","Employee id","Name","Department","Salary","Age");
    for(j=0;j<3;j++)
    {
        fprintf(fp1,"%d\t\t%s\t\t%s\t\t%d\t\t%d\n",e[j].employee_id,e[j].name,e[j].department,e[j].salary,e[j].age);

    }
    printf("contents are written successfully\n");
}

void search(void)
{
    int k,n;
    printf("enter the employee_id\n");
    scanf("%d",&n);
    for(k=0;k<3;k++)
    {
        if(n==e[k].employee_id)
        {
            printf("welcome,employee id is vaild\n");
            printf("name,department,salary and age of the employee is\n");
            printf("%s\t%s\t%d\t%d\t",e[k].name,e[k].department,e[k].salary,e[k].age);
            printf("respectively\n");
            exit(0);
        }

    }

    printf("employee_id is not valid\n");
}

