//starting of the project...



#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <conio.h>
#include<windows.h>

struct dat              //for date(month and day)
{
    int d, m;           //d=day,m=month
};

int clscanf();          //check class (1-6)   //will represent as department

struct student
{
    struct dat dt;
    float f, fine, tot, adv, due;   //f=fee
    char n[50];
    int r, c;                       //roll and class
} stud, s;

struct teacher
{
    struct dat dt;
    char n[50];
    float sal, tot;
    int id, no;
} tech,t;



int chkdat(int,int);            //for checking date
void addrec(int);               //for adding records
void modrec(int);               //for modifying records
void searchrec(int);            //for searching records
void delrec(int);               //for deleting records
void salary(int);               //for the calculation of salary of teacher and staff

FILE *fs,*ft;                   //file declaration

int mm,dd;                      //mm=month, dd=day




int main()
{
    int f=0;
    char username[6];
    char password[6];
    printf("\t\t\t**************************LOGIN PAGE***************************\n");
    printf("\nEnter your username: ");
    scanf("%s", &username);

    printf("Enter your password: ");
    scanf("%s", &password);

    if(strcmp(username, "admin")==0){
        if(strcmp(password, "1234")==0){
            printf("\nWelcome, Login Succesful!");
            f=1;
        }
        else printf("\nUsername or password is incorrect!");
    }
    else printf("\nUsername or password is incorrect!");

    if(f==1){
        int i;

        printf("\n\n\n\tPLEASE ENTER ANY KEY TO START THE PROGRAM");
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

}


void start()
{
    int i, j;                                //j is for selection account type
    system("cls");
    printf("\n\tPLEASE ENTER ANY OF THE ACCOUNT TYPE:");
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
            //printf("\n\t\t5:: Calculate fee");
            printf("\n\t\t5:: Exit");
            printf("\n\n Enter choice: ");
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
            //printf("\n\t\t5:: Calculate Salary");
            printf("\n\t\t5:: Exit");
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
                exit(1);

                default :
                {
                    printf("\n\n\tInvalid entry!!");
                    printf("\n\nTo Account Type\n\n\t");
                    system("pause");
                    start();
                }
            }
        }
        case 3:
            exit(1);

    }

}



void addrec(int j)
{
    int dif,cdat,ddat,month=0;                //cdat=month till which fee is cleared
    float ff;                                 //used in calculatin of fee of different class
    char c='y';
    system("cls");
    printf("\n\t******************************************************************");

    printf("\n\t                     ***************************                  ");

    printf("\n\t*********************          ADD RECORD       *******************");

    printf("\n\t                     ***************************                  ");

    printf("\n\t******************************************************************");
    if (j==1)
    {
        while(c=='y'||c=='Y')
        {
            int a=1;
            printf("\n\nEnter the name of student: ");
            fflush(stdin);
            scanf("%[^\n]",stud.n);
            printf("\nEnter the dept. no (1.CSE 2.EEE 3.MCE 4.CEE 5.BTM): ");
            fflush(stdin);
            stud.c=clscanf();
            printf("\nEnter the Roll No: ");
            fflush(stdin);
            scanf("%d",&stud.r);
            printf("\nEnter month and day till which fee is paid: ");
            fflush(stdin);
            scanf("%2d%2d",&cdat,&ddat);
            cdat=chkdat(cdat,ddat);
            stud.dt.m=cdat;
            ff=400;
            stud.f=400;                        //fee of different depts
            dif=12-stud.dt.m;                  //months of fee left to be paid
            stud.fine=(dif*stud.f)*1/100;
            stud.due=(dif)*stud.f;             //fees left to be paid
            if(dif==1)
            {
                stud.tot=stud.f;
                stud.fine=0;
            }
            else
            {
                stud.tot=stud.fine+stud.due;
            }                                  //for calculation of total fee
            fs=fopen("student","ab+");         //opening a binary file in apend mode
            fwrite(&stud,sizeof(stud),1,fs);
            fclose(fs);
            printf("\n\nDo you want to continue with the process(press y or Y)");
            fflush(stdin);
            c=getch();
        }
        getch();
    }



    if (j==2)
    {
        while(c=='y'||c=='Y')
        {
            int a=1;
            printf("\n\nEnter name of teacher/staff: ");
            fflush(stdin);
            scanf("%[^\n]",tech.n);
            printf("\nEnter teacher/staff id: ");
            fflush(stdin);
            scanf("%d",&tech.id);
            //printf("\nEnter number of class/shift per month:: ");
            //scanf("%d",&tech.no);
            fflush(stdin);
            printf("\nEnter month and day till which fee is paid:");
            fflush(stdin);
            scanf("%2d%2d",&cdat,&ddat);
            cdat=chkdat(cdat,ddat);
            tech.dt.m=cdat;
            tech.sal=1500;
            tech.tot=tech.sal;
            ft=fopen("teacher","ab+");
            fwrite(&tech,sizeof(tech),1,ft);
            fclose(ft);
            printf("\n\nDo you want to continue with the process(press y or Y)");
            fflush(stdin);
            c=getch();
        }
        fflush(stdin);
        printf("\n\n");
        system("pause");

    }
}



void searchrec(int j)
{
    char name[50],namet[50];
    int a=1,choice;
    char c='y';
    if (j==1)
    {
        while(c=='y'||c=='Y')
        {
            int a=1;
            system("cls");
            printf("\n\t******************************************************************");

            printf("\n\t                    ***************************                  ");

            printf("\n\t*********************   SEARCH RECORD     *******************");

            printf("\n\t                     ***************************                  ");

            printf("\n\t******************************************************************");
            printf("\n\n\t\tPLEASE CHOOSE SEARCH TYPE::");
            printf("\n\n\t\t1::Search by name::");
            printf("\n\n\t\t2::Search by dept no (1.CSE 2.EEE 3.MCE 4.CEE 5.BTM)::");
            printf("\n\n\t\t3::Search by roll no::");
            printf("\n\n\t\t4::Exit");
            printf("\n\n\t\t::Enter your choice:: ");
            fflush(stdin);
            scanf("%d",&choice);
            if (choice==1)
            {
                a=1;
                printf("\n\nEnter name of student to search: ");
                fflush(stdin);
                scanf("%[^\n]",name);
                fs=fopen("student","rb");
                while(fread(&stud,sizeof(stud),1,fs)==1)
                {
                    if (strcmpi(name,stud.n)==0)
                    {
                        a=0;
                        printf("\nname = %s",stud.n);
                        printf("\ndept = %d",stud.c);
                        printf("\nroll no = %d",stud.r);
                        printf("\nmonthy fee = %.2f",stud.f);
                        printf("\nlast fee paid in month = %2d",stud.dt.m);
                        printf("\n due=%.2f",stud.due);
                        //printf("\n fine=%.2f",stud.fine);
                        //printf("\n total=%.2f\n\n",stud.tot);
                    }
                }
                if (a==1)
                    printf("\n\nRECORD NOT FOUND");
                printf("\n\n");
                system("pause");
                fflush(stdin);
                fclose(fs);
            }
            else if (choice==2)
            {
                int cl;
                a=1;
                printf("\n\nEnter dept. of student to search: ");
                fflush(stdin);
                cl=clscanf();
                fs=fopen("student","rb");
                while(fread(&stud,sizeof(stud),1,fs)==1)
                {
                    if (stud.c==cl)
                    {
                        a=0;
                        printf("\nname = %s",stud.n);
                        printf("\nclass = %d",stud.c);
                        printf("\nroll no = %d",stud.r);
                        printf("\nmonthy fee = %.2f",stud.f);
                        printf("\nlast fee paid in month = %2d",stud.dt.m);
                        printf("\n due=%.2f",stud.due);
                        //printf("\n fine=%.2f",stud.fine);
                        //printf("\n total=%.2f",stud.tot);
                    }
                }
                if (a==1)
                    printf("\n\nRECORD NOT FOUND");
                printf("\n\n");
                system("pause");
                fflush(stdin);
                fclose(fs);
            }
            else if (choice==3)
            {
                int rll;
                a=1;
                printf("\n\nEnter roll of student to search: ");
                fflush(stdin);
                rll=clscanf();
                fs=fopen("student","rb");
                while(fread(&stud,sizeof(stud),1,fs)==1)
                {
                    if (strcmpi(name,stud.n)==0)
                    {
                        a=0;
                        printf("\nname = %s",stud.n);
                        printf("\nclass = %d",stud.c);
                        printf("\nroll no = %d",stud.r);
                        printf("\nmonthy fee = %.2f",stud.f);
                        printf("\nlast fee paid in month = %2d",stud.dt.m);
                        printf("\n due=%.2f",stud.due);
                        //printf("\n fine=%.2f",stud.fine);
                        //printf("\n total=%.2f",stud.tot);
                    }
                }
                if (a==1)
                    printf("\n\nRECORD NOT FOUND");
                printf("\n\n");
                system("pause");
                fflush(stdin);
                fclose(fs);
            }
            else if(choice==4)
            {
                exit(1);
            }
            else
            {
                printf("\n\n\n\t\tINVALID ENTRY!!!!\n\n\t\t");
                system("pause");
                searchrec(1);
            }
            printf("\n\nDo you want to continue with the process(press y or Y");
            fflush(stdin);
            c=getch();
        }
        getch();
    }
    if (j==2)
    {
        while(c=='y'||c=='Y')
        {
            int a=1;
            printf("\n\nname of teacher/staff to search: ");
            fflush(stdin);
            scanf("%[^\n]",namet);
            ft=fopen("teacher","rb");
            while(fread(&tech,sizeof(tech),1,ft)==1)
            {
                if (strcmp(namet,tech.n)==0)
                {
                    a=0;
                    printf("\nname = %s",tech.n);
                    printf("\nteacher/staff id = %d",tech.id);
                    printf("\nmonth till when salary is paid = %d",tech.dt.m);
                    printf("\nmonthly salary = %.2f",tech.sal);
                }
            }
            if (a==1)
                printf("\n\nRECORD NOT FOUND");
            printf("\n\n");
            system("pause");
            fflush(stdin);
            fclose(ft);
            printf("\n\nDo you want to continue with the process(press y or Y)");
            fflush(stdin);
            c=getch();
        }
        getch();
    }

}

void delrec(int j)
{
    system("cls");
    printf("\n\t******************************************************************");

    printf("\n\t                     ***************************                  ");

    printf("\n\t*********************          DELETE RECORD     *******************");

    printf("\n\t                     ***************************                  ");

    printf("\n\t******************************************************************");
    FILE *temp,*t1;
    int a=1;
    char name[50],c='y';
    if (j==1)
    {
        while(c=='y'||c=='Y')
        {
            int a=1;
            printf("\n\nenter name of student to delete: ");
            fflush(stdin);
            scanf("%[^\n]",name);
            fs=fopen("student","rb");
            temp=fopen("tempfile","wb");//opening of temporary file for deleting process
            while (fread(&stud,sizeof(stud),1,fs)==1)
            {
                if (strcmp(stud.n,name)==0)
                {
                    a=0;
                    continue;
                }
                else
                {
                    fwrite(&stud,sizeof(stud),1,temp);
                }
            }

            if (a==1)
                printf("\n\nRECORD NOT FOUND");
            else
                printf("\n\nRECORD SUCCESSFULLY  DELETED");
            printf("\n\n");
            system("pause");
            fflush(stdin);

            fclose(fs);
            fclose(temp);
            system("del student");          //all data except the data to be deleted in student were 1st moved to temp and data in student was deleted

            system("ren tempfile, student");//renaming temp to student
            printf("\n\nDo you want to continue with the process(press y or Y");
            fflush(stdin);
            c=getch();
        }
        getch();
    }

    if (j==2)
    {
        a=1;
        char namet[50];
        while(c=='y'||c=='Y')
        {
            printf("\n\nEnter name of teacher to delete record: ");
            fflush(stdin);
            scanf("%[^\n]",namet);
            ft=fopen("teacher","rb");
            t1=fopen("tempfile1","wb");
            while (fread(&tech,sizeof(tech),1,ft)==1)
            {
                if (strcmp(tech.n,namet)==0)
                {
                    a=0;
                    continue;
                }
                else
                {
                    fwrite(&tech,sizeof(tech),1,t1);
                }
            }

            if (a==1)
                printf("\n\nRECORD NOT FOUND");
            else
                printf("\n\nRECORD SUCCESSFULLY  DELETED");
            printf("\n\n");
            system("pause");
            fflush(stdin);

            fclose(ft);
            fclose(t1);
            system("del teacher");
            system("ren tempfile1, teacher");
            printf("\n\nDo you want to continue with the process(press y or Y");
            fflush(stdin);
            c=getch();
        }
        getch();
    }
}


void modrec(int j)
{

    char name[50];
    int a=1,choice,cl,rolno;
    char c='y';
    if (j==1)
    {
        while(c=='y'||c=='Y')
        {
            system("cls");
            printf("\n\t******************************************************************");

            printf("\n\t                    ***************************                  ");

            printf("\n\t*********************   MODIFY RECORD     *******************");

            printf("\n\t                     ***************************                  ");

            printf("\n\t******************************************************************");
            printf("\n\n\t\tPLEASE CHOOSE MODIFY TYPE::");
            printf("\n\n\t\t1::Modify by name::");
            printf("\n\n\t\t2::Modify by name &class::");
            printf("\n\n\t\t3::Modify by name,class & rollno::");
            printf("\n\n\t\t4::Exit");
            printf("\n\n\t\t::Enter your choice:: ");
            fflush(stdin);
            scanf("%d",&choice);
            if (choice==1)
            {
                int a=0;
                printf("\n\nenter name of student to modify: ");
                fflush(stdin);
                scanf("%[^\n]",name);
                fs=fopen("student","rb+");
                while(fread(&stud,sizeof(stud),1,fs)==1)
                {
                    a=1;
                    if (strcmpi(name,stud.n)==0)
                    {
                        a=0;
                        printf("\nenter new name of student: ");
                        fflush(stdin);
                        scanf("%[^\n]",stud.n);
                        printf("\nenter new class of student: ");
                        fflush(stdin);
                        stud.c=clscanf();
                        printf("\nenter new roll of student: ");
                        fflush(stdin);
                        scanf("%d",&stud.r);
                        fseek(fs,-sizeof(stud),SEEK_CUR);
                        fwrite(&stud,sizeof(stud),1,fs);
                        fclose(fs);
                    }
                }
                if (a==1)
                    printf("\n\nRECORDS NOT FOUND");
                else
                    printf("\n\nRECORDS SUCCESSFULLY  MODIFIED");
                printf("\n\n");
                system("pause");
            }
            else if (choice==2)
            {
                int a=0;
                printf("\n\nenter name of student to modify: ");
                fflush(stdin);
                scanf("%[^\n]",name);
                printf("\n\nenter class of student to modify: ");
                fflush(stdin);
                cl=clscanf();
                fs=fopen("student","rb+");
                while(fread(&stud,sizeof(stud),1,fs)==1)
                {
                    a=1;
                    if (strcmpi(name,stud.n)==0 && cl==stud.c)
                    {
                        a=0;
                        printf("\nenter new name of student: ");
                        fflush(stdin);
                        scanf("%[^\n]",stud.n);
                        printf("\nenter new class of student: ");
                        fflush(stdin);
                        stud.c=clscanf();
                        printf("\nenter new roll of student: ");
                        fflush(stdin);
                        scanf("%d",&stud.r);
                        fseek(fs,-sizeof(stud),SEEK_CUR);
                        fwrite(&stud,sizeof(stud),1,fs);
                        fclose(fs);
                    }
                }
                if (a==1)
                    printf("\n\nRECORDS NOT FOUND");
                else
                    printf("\n\nRECORDS SUCCESSFULLY  MODIFIED");
                printf("\n\n");
                system("pause");
            }
            else if (choice==3)
            {
                int a=0;
                printf("\n\nenter name of student to modify: ");
                fflush(stdin);
                scanf("%[^\n]",name);
                printf("\n\nenter class of student to modify: ");
                fflush(stdin);
                cl=clscanf();
                printf("\n\nenter roll of student to modify: ");
                fflush(stdin);
                scanf("%d",&rolno);
                fs=fopen("student","rb+");
                while(fread(&stud,sizeof(stud),1,fs)==1)
                {
                    a=1;
                    if (strcmpi(name,stud.n)==0 && cl==stud.c &&rolno==stud.r)
                    {
                        a=0;
                        printf("\nenter new name of student: ");
                        fflush(stdin);
                        scanf("%[^\n]",stud.n);
                        printf("\nenter new class of student: ");
                        fflush(stdin);
                        stud.c=clscanf();
                        printf("\nenter new roll of student: ");
                        fflush(stdin);
                        scanf("%d",&stud.r);
                        fseek(fs,-sizeof(stud),SEEK_CUR);
                        fwrite(&stud,sizeof(stud),1,fs);
                        fclose(fs);
                    }
                }
                if (a==1)
                    printf("\n\nRECORDS NOT FOUND");
                else
                    printf("\n\nRECORDS SUCCESSFULLY  MODIFIED");
                printf("\n\n");
                system("pause");
            }
            else if (choice==4) exit(1);
            else
            {
                printf("\n\n\n\t\tINVALID ENTRY!!!!\n\n\t\t");
                system("pause");
                modrec(1);
            }

            printf("\n\nDo you want to continue with the process(press y or Y");
            fflush(stdin);
            c=getch();
        }
        getch();
    }

    if (j==2)
    {
        while(c=='y'||c=='Y')
        {
            int a=1;
            printf("enter name of teacher to modify: ");
            fflush(stdin);
            scanf("%[^\n]",name);
            ft=fopen("teacher","rb+");
            while(fread(&tech,sizeof(tech),1,ft)==1)
            {
                if (strcmpi(name,tech.n)==0)
                {
                    a=0;
                    printf("\nenter new name of teacher: ");
                    fflush(stdin);
                    scanf("%[^\n]",tech.n);
                    printf("\nenter new id of teacher: ");
                    fflush(stdin);
                    scanf("%d",&tech.id);
                    fseek(ft,-sizeof(tech),SEEK_CUR);
                    fwrite(&tech,sizeof(tech),1,ft);
                    fclose(ft);
                }
            }

            if (a==1)
                printf("\n\nRECORD NOT FOUND");
            else
                printf("\n\nRECORD SUCCESSFULLY  MODIFIED");
            printf("\n\n");
            system("pause");
            fflush(stdin);

            printf("\n\nDo you want to continue with the process(press y or Y");
            fflush(stdin);
            c=getch();
        }
        getch();
    }
}




int chkdat(int mnt, int dnt)
{
    int mon, day;
    if (mnt>12 || mnt<1 || dnt<1 || dnt>32)
    {
        MessageBox(0,"Invalid Date!\nEnter Again","Error!",0);

        fflush(stdin);
        scanf("%d%d", &mon, &day);
        mon=chkdat(mon,day);
    }
    else
        return (mnt);
}


int clscanf()
{
    int mnt,mon;
    fflush(stdin);
    scanf("%d",&mnt);
    if (mnt>5 || mnt<1)
    {

        MessageBox(0,"Invalid Class!\nEnter Class","Error!!",0);
        fflush(stdin);
        mon=clscanf();
    }
    else
        return mnt;
}


