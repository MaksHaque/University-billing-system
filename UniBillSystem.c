//starting of the project...



#include<stdio.h>
#include<windows.h>
#include<ctype.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

void addrec(int);               //for adding records
void searchrec(int);            //for searching records
void modrec(int);               //for modifying records
void delrec(int);               //for deleting records

struct res_scholar_std
{
    char name[50], dept[4], month[10];
    int id;
    //float res_fee, res_paid, res_due;
    float laundry_fee, laundry_paid, laundry_due;
    float medical_fee, medical_paid, medical_due;
    float printing_fee, printing_paid, printing_due;
}res_scholar;

struct res_nonscholar_std
{
    char name[50], dept[4], month[10];
    int id;
    float tuition_fee, tuition_paid, tuition_due;
    float laundry_fee, laundry_paid, laundry_due;
    float medical_fee, medical_paid, medical_due;
    float printing_fee, printing_paid, printing_due;
}res_nonscholar;

struct nonres_std
{
    char name[50], dept[4], month[10];
    int id;
    float tuition_fee, tuition_paid, tuition_due;
    float laundry_fee, laundry_paid, laundry_due;
    float medical_fee, medical_paid, medical_due;
    float printing_fee, printing_paid, printing_due;
}nonres_std;


FILE *rsstd, *rnstd, *nrstd;

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
            printf("\nWelcome, Login Successful!");
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
    printf("\n\tPLEASE ENTER ANY OF THE OPTION:");
    printf("\n\t\t1.Student");
    //printf("\n\t\t2.Teacher & Stuffs");
    printf("\n\t\t2.Exit");
    printf("\n\n\n\tEnter the choice: ");
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
            exit(1);

    }
}


void addrec(int j)
{
    int x;
    printf("\n\nChoose any of the following scheme student: \n");
    printf("\n\t\t1. Residential scholarship student\n\t\t2. Residential non-scholarship student\n\t\t3. Non-residential student");
    printf("\n\n\tEnter the choice: ");
    scanf("%d", &x);
    system("cls");
    if(x==1)
    {
        printf("Enter the student name: ");
        fflush(stdin);
        scanf("%[^\n]", res_scholar.name);
        printf("Enter the student id: ");
        fflush(stdin);
        scanf("%d", &res_scholar.id);
        printf("Enter the department name: ");
        fflush(stdin);
        scanf("%s", &res_scholar.dept);
        printf("Enter the month: ");
        fflush(stdin);
        scanf("%s", &res_scholar.month);
        printf("Enter the laundry fee: ");
        fflush(stdin);
        scanf("%f", &res_scholar.laundry_fee);
        printf("\t\tEnter the paid laundry fee: ");
        fflush(stdin);
        scanf("%f", &res_scholar.laundry_paid);
        printf("\t\tEnter the due laundry_fee: ");
        fflush(stdin);
        scanf("%f", &res_scholar.laundry_due);
        printf("Enter the medical fee: ");
        fflush(stdin);
        scanf("%f", &res_scholar.medical_fee);
        printf("\t\tEnter the paid medical fee: ");
        fflush(stdin);
        scanf("%f", &res_scholar.medical_paid);
        printf("\t\tEnter the due medical_fee: ");
        fflush(stdin);
        scanf("%f", &res_scholar.medical_due);
        printf("Enter the printing fee: ");
        fflush(stdin);
        scanf("%f", &res_scholar.printing_fee);
        printf("\t\tEnter the paid printing fee: ");
        fflush(stdin);
        scanf("%f", &res_scholar.printing_paid);
        printf("\t\tEnter the due printing_fee: ");
        fflush(stdin);
        scanf("%f", &res_scholar.printing_due);

        rsstd=fopen("res_scholar_std", "ab+");
        fwrite(&res_scholar, sizeof(res_scholar), 1, rsstd);
        fclose(rsstd);
    }

    else if(x==2)
    {
        printf("Enter the student name: ");
        fflush(stdin);
        scanf("%[^\n]", res_nonscholar.name);
        printf("Enter the student id: ");
        fflush(stdin);
        scanf("%d", &res_nonscholar.id);
        printf("Enter the department name: ");
        fflush(stdin);
        scanf("%s", &res_nonscholar.dept);
        printf("Enter the month: ");
        fflush(stdin);
        scanf("%s", &res_nonscholar.month);
        printf("Enter the tuition fee: ");
        fflush(stdin);
        scanf("%f", &res_nonscholar.tuition_fee);
        printf("\t\tEnter the paid tuition fee: ");
        fflush(stdin);
        scanf("%f", &res_nonscholar.tuition_paid);
        printf("\t\tEnter the due tuition_fee: ");
        fflush(stdin);
        scanf("%f", &res_nonscholar.tuition_due);
        printf("Enter the laundry fee: ");
        fflush(stdin);
        scanf("%f", &res_nonscholar.laundry_fee);
        printf("\t\tEnter the paid laundry fee: ");
        fflush(stdin);
        scanf("%f", &res_nonscholar.laundry_paid);
        printf("\t\tEnter the due laundry_fee: ");
        fflush(stdin);
        scanf("%f", &res_nonscholar.laundry_due);
        printf("Enter the medical fee: ");
        fflush(stdin);
        scanf("%f", &res_nonscholar.medical_fee);
        printf("\t\tEnter the paid medical fee: ");
        fflush(stdin);
        scanf("%f", &res_nonscholar.medical_paid);
        printf("\t\tEnter the due medical_fee: ");
        fflush(stdin);
        scanf("%f", &res_nonscholar.medical_due);
        printf("Enter the printing fee: ");
        fflush(stdin);
        scanf("%f", &res_nonscholar.printing_fee);
        printf("\t\tEnter the paid printing fee: ");
        fflush(stdin);
        scanf("%f", &res_nonscholar.printing_paid);
        printf("\t\tEnter the due printing_fee: ");
        fflush(stdin);
        scanf("%f", &res_nonscholar.printing_due);

        rnstd=fopen("res_nonscholar_std", "ab+");
        fwrite(&res_nonscholar, sizeof(res_nonscholar), 1, rnstd);
        fclose(rnstd);
    }

    else if(x==3)
    {
        printf("Enter the student name: ");
        fflush(stdin);
        scanf("%[^\n]", nonres_std.name);
        printf("Enter the student id: ");
        fflush(stdin);
        scanf("%d", &nonres_std.id);
        printf("Enter the department name: ");
        fflush(stdin);
        scanf("%s", &nonres_std.dept);
        printf("Enter the month: ");
        fflush(stdin);
        scanf("%s", &nonres_std.month);
        printf("Enter the tuition fee: ");
        fflush(stdin);
        scanf("%f", &nonres_std.tuition_fee);
        printf("\t\tEnter the paid tuition fee: ");
        fflush(stdin);
        scanf("%f", &nonres_std.tuition_paid);
        printf("\t\tEnter the due tuition_fee: ");
        fflush(stdin);
        scanf("%f", &nonres_std.tuition_due);
        printf("Enter the laundry fee: ");
        fflush(stdin);
        scanf("%f", &nonres_std.laundry_fee);
        printf("\t\tEnter the paid laundry fee: ");
        fflush(stdin);
        scanf("%f", &nonres_std.laundry_paid);
        printf("\t\tEnter the due laundry_fee: ");
        fflush(stdin);
        scanf("%f", &nonres_std.laundry_due);
        printf("Enter the medical fee: ");
        fflush(stdin);
        scanf("%f", &nonres_std.medical_fee);
        printf("\t\tEnter the paid medical fee: ");
        fflush(stdin);
        scanf("%f", &nonres_std.medical_paid);
        printf("\t\tEnter the due medical_fee: ");
        fflush(stdin);
        scanf("%f", &nonres_std.medical_due);
        printf("Enter the printing fee: ");
        fflush(stdin);
        scanf("%f", &nonres_std.printing_fee);
        printf("\t\tEnter the paid printing fee: ");
        fflush(stdin);
        scanf("%f", &nonres_std.printing_paid);
        printf("\t\tEnter the due printing_fee: ");
        fflush(stdin);
        scanf("%f", &nonres_std.printing_due);

        nrstd=fopen("nonres_std", "ab+");
        fwrite(&nonres_std, sizeof(nonres_std), 1, nrstd);
        fclose(nrstd);
    }

    else{
        printf("Wrong input!!!\n\n");
        system("pause");
    }


}


void searchrec(int j)
{
    int i, p, roll;
    char c[50], mon[20];
    printf("Search by: ");
    //fflush(stdin);
    printf("\n1. Individually\n2. Totally\n");
    printf("Enter any of the option: ");
    fflush(stdin);
    scanf("%d", &i);

    if(i==1)
    {
        printf("Choose any of the following scheme:\n\n1. Residential scholarship student\n2. Residential non-scholarship student\n3. Non residential student");
        printf("\nEnter your choice: ");
        fflush(stdin);
        scanf("%d", &p);
        if(p==1)
        {
            int a=1;
            printf("Enter name, id & month of the billing: ");
            //fflush(stdin);
            scanf("%s", c);
            scanf("%d", &roll);
            scanf("%s", &mon);
            rsstd=fopen("res_scholar_std", "rb");
            while(fread(&res_scholar, sizeof(res_scholar), 1, rsstd)==1)
            {
                if((strcmpi(c, res_scholar.name)==0) && (roll==res_scholar.id) && (strcmpi(mon, res_scholar.month)==0))
                {
                    a=0;
                    printf("\nName: %s", res_scholar.name);
                    printf("\nDepartment: %s", res_scholar.dept);
                    printf("\nId: %d", res_scholar.id);
                    printf("\nMonth: %s", res_scholar.month);
                    printf("\nAmount of laundry fee: %.2f", res_scholar.laundry_fee);
                    printf("\nPaid laundry fee: %.2f", res_scholar.laundry_paid);
                    printf("\nDue laundry fee: %.2f", res_scholar.laundry_due);
                    printf("\nAmount of medical fee: %.2f", res_scholar.medical_fee);
                    printf("\nPaid medical fee: %.2f", res_scholar.medical_paid);
                    printf("\nDue medical fee: %.2f", res_scholar.medical_due);
                    printf("\nAmount of printing fee: %.2f", res_scholar.printing_fee);
                    printf("\nPaid printing fee: %.2f", res_scholar.printing_paid);
                    printf("\nDue printing fee: %.2f", res_scholar.printing_due);
                }
            }
            if (a==1)
                    printf("\n\nRECORD NOT FOUND");
                printf("\n\n");
                system("pause");
                fflush(stdin);
                fclose(rsstd);
        }
        if(p==2)
        {
            int a=1;
            printf("Enter name, id & month of the billing: ");
            //fflush(stdin);
            scanf("%s", c);
            scanf("%d", &roll);
            scanf("%s", &mon);
            rnstd=fopen("res_nonscholar_std", "rb");
            while(fread(&res_nonscholar, sizeof(res_nonscholar), 1, rnstd)==1)
            {
                if((strcmpi(c, res_nonscholar.name)==0) && (roll==res_nonscholar.id) && (strcmpi(mon, res_nonscholar.month)==0))
                {
                    a=0;
                    printf("\nName: %s", res_nonscholar.name);
                    printf("\nDepartment: %s", res_nonscholar.dept);
                    printf("\nId: %d", res_nonscholar.id);
                    printf("\nMonth: %s", res_nonscholar.month);
                    printf("\nAmount of tuition fee: %.2f", res_nonscholar.tuition_fee);
                    printf("\nPaid tuition fee: %.2f", res_nonscholar.tuition_paid);
                    printf("\nDue tuition fee: %.2f", res_nonscholar.tuition_due);
                    printf("\nAmount of laundry fee: %.2f", res_nonscholar.laundry_fee);
                    printf("\nPaid laundry fee: %.2f", res_nonscholar.laundry_paid);
                    printf("\nDue laundry fee: %.2f", res_nonscholar.laundry_due);
                    printf("\nAmount of medical fee: %.2f", res_nonscholar.medical_fee);
                    printf("\nPaid medical fee: %.2f", res_nonscholar.medical_paid);
                    printf("\nDue medical fee: %.2f", res_nonscholar.medical_due);
                    printf("\nAmount of printing fee: %.2f", res_nonscholar.printing_fee);
                    printf("\nPaid printing fee: %.2f", res_nonscholar.printing_paid);
                    printf("\nDue printing fee: %.2f", res_nonscholar.printing_due);
                }
            }
            if (a==1)
                    printf("\n\nRECORD NOT FOUND");
                printf("\n\n");
                system("pause");
                fflush(stdin);
                fclose(rnstd);

            if(p==3)
            {
                int a=1;
            printf("Enter name, id & month of the billing: ");
            //fflush(stdin);
            scanf("%s", c);
            scanf("%d", &roll);
            scanf("%s", &mon);
            rnstd=fopen("nonres_std", "rb");
            while(fread(&nonres_std, sizeof(nonres_std), 1, nrstd)==1)
            {
                if((strcmpi(c, nonres_std.name)==0) && (roll==nonres_std.id) && (strcmpi(mon, nonres_std.month)==0))
                {
                    a=0;
                    printf("\nName: %s", nonres_std.name);
                    printf("\nDepartment: %s", nonres_std.dept);
                    printf("\nId: %d", nonres_std.id);
                    printf("\nMonth: %s", nonres_std.month);
                    printf("\nAmount of tuition fee: %.2f", nonres_std.tuition_fee);
                    printf("\nPaid tuition fee: %.2f", nonres_std.tuition_paid);
                    printf("\nDue tuition fee: %.2f", nonres_std.tuition_due);
                    printf("\nAmount of laundry fee: %.2f", nonres_std.laundry_fee);
                    printf("\nPaid laundry fee: %.2f", nonres_std.laundry_paid);
                    printf("\nDue laundry fee: %.2f", nonres_std.laundry_due);
                    printf("\nAmount of medical fee: %.2f", nonres_std.medical_fee);
                    printf("\nPaid medical fee: %.2f", nonres_std.medical_paid);
                    printf("\nDue medical fee: %.2f", nonres_std.medical_due);
                    printf("\nAmount of printing fee: %.2f", nonres_std.printing_fee);
                    printf("\nPaid printing fee: %.2f", nonres_std.printing_paid);
                    printf("\nDue printing fee: %.2f", nonres_std.printing_due);
                }
            }
            if (a==1)
                    printf("\n\nRECORD NOT FOUND");
                printf("\n\n");
                system("pause");
                fflush(stdin);
                fclose(nrstd);
            }
        }
    }

    else if(i==2)
    {
        rsstd=fopen("res_scholar_std", "rb");
        if(rsstd==NULL)
        {
            printf("ERROR!!! FILE COULD NOT BE OPEN FOR RESIDENTIAL SCHOLARSHIP STUDENT\n\n\n Go To Main Menu to create File");
            printf("\n\n\n Program is closing ....");
            getch();
            exit(0);
        }
        printf("\n\t***************** Total residential scholarship student records *****************\n");
        printf("\n=================================================================================================================================\n");
        printf("Name       ID    dept.  Month    laundry fee : paid : due     medical fee : paid : due     printing fee : paid : due");
        printf("\n=================================================================================================================================\n");
        while(fread(&res_scholar, sizeof(res_scholar), 1, rsstd)>0)
        {
            printf("%-10s %-5d %-6s %-10s %-4.2f %-4.2f %-20.2f %-4.2f %-4.2f %-20.2f %-4.2f %-4.2f %-6.2f\n", res_scholar.name, res_scholar.id, res_scholar.dept, res_scholar.month, res_scholar.laundry_fee, res_scholar.laundry_paid, res_scholar.laundry_due, res_scholar.medical_fee, res_scholar.medical_paid, res_scholar.medical_due, res_scholar.printing_fee, res_scholar.printing_paid, res_scholar.printing_due);
        }
        fclose(rsstd);
        //getch();

        rnstd=fopen("res_nonscholar_std", "rb");
        if(rnstd==NULL)
        {
            printf("ERROR!!! FILE COULD NOT BE OPEN FOR RESIDENTIAL NON-SCHOLARSHIP STUDENT\n\n\n Go To Main Menu to create File");
            printf("\n\n\n Program is closing ....");
            getch();
            exit(0);
        }
        printf("\n\t***************** Total residential non-scholarship student records *****************\n");
        printf("\n================================================================================================================================================\n");
        printf("Name       ID    dept.  Month    tuition fee : paid : due    laundry fee : paid : due     medical fee : paid : due     printing fee : paid : due");
        printf("\n================================================================================================================================================\n");
        while(fread(&res_nonscholar, sizeof(res_nonscholar), 1, rnstd)>0)
        {
            printf("%-10s %-5d %-6s %-10s %-4.2f %-4.2f %-20.2f %-4.2f %-4.2f %-20.2f %-4.2f %-4.2f %-20.2f %-4.2f %-4.2f %.2f\n", res_nonscholar.name, res_nonscholar.id, res_nonscholar.dept, res_nonscholar.month, res_nonscholar.laundry_fee, res_nonscholar.laundry_paid, res_nonscholar.laundry_due, res_nonscholar.medical_fee, res_nonscholar.medical_paid, res_nonscholar.medical_due, res_nonscholar.printing_fee, res_nonscholar.printing_paid, res_nonscholar.printing_due);
        }
        fclose(rnstd);
        //getch();

        nrstd=fopen("nonres_std", "rb");
        if(nrstd==NULL)
        {
            printf("ERROR!!! FILE COULD NOT BE OPEN FOR NON-RESIDENTIAL STUDENT\n\n\n Go To Main Menu to create File");
            printf("\n\n\n Program is closing ....");
            getch();
            exit(0);
        }
        printf("\n\t***************** Total non-residential student records *****************\n");
        printf("\n================================================================================================================================================\n");
        printf("Name       ID    dept.  Month    tuition fee : paid : due    laundry fee : paid : due     medical fee : paid : due     printing fee : paid : due");
        printf("\n================================================================================================================================================\n");
        while(fread(&nonres_std, sizeof(nonres_std), 1, rnstd)>0)
        {
            printf("%-10s %-5d %-6s %-10s %-4.2f %-4.2f %-20.2f %-4.2f %-4.2f %-20.2f %-4.2f %-4.2f %-20.2f %-4.2f %-4.2f %.2f\n", nonres_std.name, nonres_std.id, nonres_std.dept, nonres_std.month, nonres_std.laundry_fee, nonres_std.laundry_paid, nonres_std.laundry_due, nonres_std.medical_fee, nonres_std.medical_paid, nonres_std.medical_due, nonres_std.printing_fee, nonres_std.printing_paid, nonres_std.printing_due);
        }
        fclose(nrstd);
        getch();
    }

}

void modrec(int j)
{
    char c[50], mon[20];
    int roll, m;
    printf("Choose any of the following option to modify:\n\n\t1. Residential scholarship student\n2. Residential non-scholarship student\n3. Non-residential student\n");
    printf("Enter the option: ");
    scanf("%d", &m);
    printf("Enter name, id & month of the student: ");
    scanf("%s", &c);
    scanf("%d", &roll);
    scanf("%s", &mon);

    if(m==1)
    {
        int a=1;
        rsstd=fopen("res_scholar_std", "rb+");
        while(fread(&res_scholar, sizeof(res_scholar), 1, rsstd)==1)
        {
            a=0;
            if(strcmpi(c, res_scholar.name)==0 && roll==res_scholar.id && strcmpi(mon, res_scholar.month)==0)
            {
                printf("\nEnter new name: ");
                scanf("%s", res_scholar.name);
                printf("\nEnter new id: ");
                scanf("%d", &res_scholar.id);
                printf("\nEnter new month: ");
                scanf("%s", res_scholar.month);
                fseek(rsstd, -sizeof(res_scholar), SEEK_CUR);
                fwrite(&res_scholar, sizeof(res_scholar), 1, rsstd);
                fclose(rsstd);
            }

        }
        if (a==1)
            printf("\n\nRECORDS NOT FOUND");
        else
            printf("\n\nRECORDS SUCCESSFULLY  MODIFIED");
            printf("\n\n");
            system("pause");
    }

    if(m==2)
    {
        int a=1;
        rsstd=fopen("res_nonscholar_std", "rb+");
        while(fread(&res_nonscholar, sizeof(res_nonscholar), 1, rnstd)==1)
        {
            a=0;
            if(strcmpi(c, res_nonscholar.name)==0 && roll==res_nonscholar.id && strcmpi(mon, res_nonscholar.month)==0)
            {
                printf("\nEnter new name: ");
                scanf("%[^\n]", res_nonscholar.name);
                printf("\nEnter new id: ");
                scanf("%d", &res_nonscholar.id);
                printf("\nEnter new month: ");
                scanf("%s", res_nonscholar.month);
                fseek(rnstd, -sizeof(res_nonscholar), SEEK_CUR);
                fwrite(&res_nonscholar, sizeof(res_nonscholar), 1, rnstd);
                fclose(rnstd);
            }

        }
        if (a==1)
            printf("\n\nRECORDS NOT FOUND");
        else
            printf("\n\nRECORDS SUCCESSFULLY  MODIFIED");
            printf("\n\n");
            system("pause");
    }

    if(m==3)
    {
        int a=1;
        nrstd=fopen("nonres_std", "rb+");
        while(fread(&nonres_std, sizeof(nonres_std), 1, nrstd)==1)
        {
            a=0;
            if(strcmpi(c, nonres_std.name)==0 && roll==nonres_std.id && strcmpi(mon, nonres_std.month)==0)
            {
                printf("\nEnter new name: ");
                scanf("%[^\n]", nonres_std.name);
                printf("\nEnter new id: ");
                scanf("%d", &nonres_std.id);
                printf("\nEnter new month: ");
                scanf("%s", nonres_std.month);
                fseek(nrstd, -sizeof(nonres_std), SEEK_CUR);
                fwrite(&nonres_std, sizeof(nonres_std), 1, nrstd);
                fclose(nrstd);
            }

        }
        if (a==1)
            printf("\n\nRECORDS NOT FOUND");
        else
            printf("\n\nRECORDS SUCCESSFULLY  MODIFIED");
            printf("\n\n");
            system("pause");

    }

}

void delrec(int j)
{
    int d, roll;
    FILE *temp1, *temp2, *temp3;
    char c[50], mon[20];
    printf("Choose any of the option:\n1. Residential scholarship student\n2. Residential non-scholarship student\n3. Non-residential student\n");
    printf("\nEnter your choice: ");
    scanf("%d", &d);
    if(d==1)
    {
        int a=1;
        printf("\nEnter the name of the student to delete: ");
        fflush(stdin);
        scanf("%[^\n]", c);
        fflush(stdin);
        printf("\nEnter the id of the student: ");
        scanf("%d", &roll);
        printf("\nEnter the month: ");
        scanf("%s", &mon);


        rsstd=fopen("res_scholar_std", "rb");
        temp1=fopen("tempfile", "wb");
        //check both files opened or created successfully. Terminate program accordingly
        while(fread(&res_scholar, sizeof(res_scholar), 1, rsstd)==1)
        {
            if(strcmp(c, res_scholar.name)==0 && roll==res_scholar.id && strcmp(mon, res_scholar.month)==0)
            {
                a=0;
                continue;
            }
            else
            {
                 fwrite(&res_scholar, sizeof(res_scholar), 1, temp1);
            }

        }
        if (a==1)
                printf("\n\nRECORD NOT FOUND");
            else
                printf("\n\nRECORD SUCCESSFULLY  DELETED");
            printf("\n\n");
            system("pause");

        fclose(rsstd);
        fclose(temp1);
        system("del res_scholar_std");

        system("ren tempfile, res_scholar_std");

    }

    else if(d==2)
    {
        int a=1;
        printf("\nEnter the name of the student to delete: ");
        fflush(stdin);
        scanf("%[^\n]", c);
        fflush(stdin);
        printf("\nEnter the id of the student: ");
        scanf("%d", &roll);
        printf("\nEnter the month: ");
        scanf("%s", &mon);


        rnstd=fopen("res_nonscholar_std", "rb");
        temp2=fopen("tempfile1", "wb");
        //check both files opened or created successfully. Terminate program accordingly
        while(fread(&res_nonscholar, sizeof(res_nonscholar), 1, rnstd)==1)
        {
            if(strcmp(c, res_nonscholar.name)==0 && roll==res_nonscholar.id && strcmp(mon, res_nonscholar.month)==0)
            {
                a=0;
                continue;
            }
            else
            {
                 fwrite(&res_nonscholar, sizeof(res_nonscholar), 1, temp2);
            }

        }
        if (a==1)
                printf("\n\nRECORD NOT FOUND");
            else
                printf("\n\nRECORD SUCCESSFULLY  DELETED");
            printf("\n\n");
            system("pause");

        fclose(rnstd);
        fclose(temp2);
        system("del res_nonscholar_std");

        system("ren tempfile1, res_nonscholar_std");

    }

    if(d==3)
    {
        int a=1;
        printf("\nEnter the name of the student to delete: ");
        fflush(stdin);
        scanf("%[^\n]", c);
        fflush(stdin);
        printf("\nEnter the id of the student: ");
        scanf("%d", &roll);
        printf("\nEnter the month: ");
        scanf("%s", &mon);


        nrstd=fopen("nonres_std", "rb");
        temp3=fopen("tempfile3", "wb");
        //check both files opened or created successfully. Terminate program accordingly
        while(fread(&nonres_std, sizeof(nonres_std), 1, nrstd)==1)
        {
            if(strcmp(c, nonres_std.name)==0 && roll==nonres_std.id && strcmp(mon, nonres_std.month)==0)
            {
                a=0;
                continue;
            }
            else
            {
                 fwrite(&nonres_std, sizeof(nonres_std), 1, temp3);
            }

        }
        if (a==1)
                printf("\n\nRECORD NOT FOUND");
            else
                printf("\n\nRECORD SUCCESSFULLY  DELETED");
            printf("\n\n");
            system("pause");

        fclose(nrstd);
        fclose(temp3);
        system("del nonres_std");

        system("ren tempfile3, nonres_std");

    }

}

