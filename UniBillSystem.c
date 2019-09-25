//starting of the project...



#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

struct dat                       //for date(month and day)
{
    int d,m;                     //d=day,m=month
};
int clscanf();                   //check class (1-12)

struct student
{
    struct dat dt;
    float f,fine,tot,adv,due;    //f=fee
    char n[50];
    int r,c;                     //roll and class
} stud,s;

struct teacher
{
    struct dat dt;
    char n[50];
    float sal,adv,tot;
    int id,no;
} tech,t;


int chkdat(int,int);            //for checking date
void addrec(int);               //for adding records
void modrec(int);               //for modifying records
void searchrec(int);            //for searching records
void delrec(int);               //for deleting records
void salary(int);               //for the calculation of salary of teacher and staff


int mm,dd;                      //mm=month, dd=day


int main()
{
    int i;

    printf("\n\tPLEASE ENTER ANY KEY TO START THE PROGRAM");
    for(i=0; i<5; i++)
    {
        printf(".");
        Sleep(500);                          //after printing one . another comes after 0.5 seconds
    }
    getch();
    system("cls");                           //clears the screen
    printf("\n");


    SYSTEMTIME stime;                        //windows has its own SYSTEMTIME structure written, so i haven't declared it.
    GetSystemTime(&stime);                   //this is also a function written in the system, so i haven't declared it.
    printf("Date: %d/ %d/ %d\n\n\n", stime.wDay, stime.wMonth, stime.wYear);
    printf("Enter any key...");
    getch();

    start();
}



void start()
{
    int i, j;                                //j is for selection account type
    system("cls");
    printf("\n\tPLEASE ENTER ACCOUNT TYPE:");
    printf("\n\t\t1.Student");
    printf("\n\t\t2.Teacher & Stuffs");
    printf("\n\t\t3.Exit");
    printf("\n\n\n\tAccount type choice: ");
    fflush(stdin);                           //it will clear the output buffer
    scanf("%d", &j);

    switch(j){
    case 1:
    {
        system("cls");
        printf("\n\t\tPLEASE ENTER THE CHOICE");
        printf("\n\t\t1:: Add record");
        printf("\n\t\t2:: Search record");
        printf("\n\t\t3:: Modify record");
        printf("\n\t\t4:: Delete record");
        printf("\n\t\t5:: Calculate fee");
        printf("\n\t\t6:: Exit");
        printf("\n\n Enter choice  ");
        fflush(stdin);
        scanf("%d",&i);
        switch (i)
        {
        case 1:
            addrec(j);
            start();
        case 2:
            searchrec(j);
            start();
        case 3:
            modrec(j);
            start();
        case 4:
            delrec(j);
            start();
        case 5:
            fee(j);
            start();
        case 6:
            exit(1);
        default :
        {
            printf("\n\n\tInvalid entry!!");
            printf("\n\nTo Account Type\n\n\t");
            system("pause");                            //pause the console if given input is wrong
            start();
        }
        }
    }




    case 2:
       {

           system("cls");
           printf("\n\t\tPLEASE ENTER THE CHOICE");
           printf("\n\t\t1:: Add record");
           printf("\n\t\t2:: Search record");
           printf("\n\t\t3:: Modify record");
           printf("\n\t\t4:: Delete record");
           printf("\n\t\t5:: Calculate Salary");
           printf("\n\t\t6:: Exit");
           printf("\n\n Enter choice  ");
           fflush(stdin);
           scanf("%d",&i);
           switch (i)
           {
           case 1:
               addrec(j);
               start();
           case 2:
               searchrec(j);
               start();
           case 3:
               modrec(j);
               start();
           case 4:
               delrec(j);
           case 5:
               salary(mm);
               start();
           case 6:
               exit(1);
           default :
           {
               printf("\n\n\tInvalid entry!!");
               printf("\n\nTo Account Type\n\n\t");
               system("pause");                                    //pause the console if given input is wrong
               start();
           }

           }
       }

    case 3:
           exit(1);

       default :
       {
           printf("\n\n\tInvalid entry!!");
           printf("\n\nTo Account Type\n\n\t");
           system("pause");                                        //pause the console if given input is wrong
           start();
       }
       }
}


void addrec(int j)
{
    int
    float ff;             //used in calculation of fee of different classe
    char c='y';           //used as yes
    system("cls");        //clears the screen
    printf("\n\t###########################################################");
    printf("\n\t   +++++++++++++++++++ ADD RECORD +++++++++++++++++++++");
    printf("\n\t###########################################################");
    if(j==1){
        while(c=='y' || c=='Y'){
            int a=1;
            printf("\n\nEnter the name of the students: ");
            fflush(stdin);
            scanf("[^\n]", &stud.n);
            printf("\nEnter the class: ");
            fflush(stdin);
            stud.c=clscanf();
            printf("\nEnter the eoll No.: ");
            fflush(stdin);
            scanf("%2d", &stud.r);
            printf("\nEnter month and day till which fee is paid:");
            fflush(stdin);
            scanf("%2d%2d", &cdat, &ddat);

        }
    }

}

void searchrec(int j)
{


}

void modrecc(int j)
{


}

void delrec(int j)
{


}

void fee(int j)
{


}


