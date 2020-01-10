#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include"menufinal.h"
#include"patient.h"
#include"staff.h"
#include"appointment.h"

//Password to authorise access to admin and staff
char pass1[]="staff";
char pass2[]="admin";

int once=1;

void delay(int number_of_seconds)
{
    int milli_seconds = 1000 * number_of_seconds;
	clock_t start_time = clock();
	while (clock() < start_time + milli_seconds);
}

int main()
{
    if(once){

                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t     ------------------------------------");
                printf("\n\t\t\t\t\t\t\t\t\t\t     |   WELCOME TO THE ACSES HOSPITAL  |");
                printf("\n\t\t\t\t\t\t\t\t\t\t     ------------------------------------");
	delay(5);
    system("cls");
    once--;
    }
    main_menu();
    char z;
    fflush(stdin);
    scanf("%c",&z);

    if(z=='1'){
    system("cls");
    char i;
	pat *P=NULL;
	appt *A=NULL;
	P_readfromfile(&P);
	A_readfromfile(&A);
	menu_patient();
	do{
            fflush(stdin);
            scanf("%c",&i);

            if(i=='1')
                {
                    system("cls");
                    printf("\n\n\n\t\t\t\t\t\t\t\t\t\tCREATE PATIENT PROFILE :\n");
                    P_create_node(&P);
                    printf("\n\n\t\t\t\t\t\t\t\t\t\tPress any key to continue...");
                    fflush(stdin);
                    if(getch())
                        system("cls");
                    menu_patient();
                    }

            else if(i=='2')
                {
                    system("cls");
                    printf("\n\n\n\t\t\t\t\t\t\t\t\t\tMODIFY PATIENT PROFILE :\n");
                    menu_search();
                    char opt;
                    fflush(stdin);
                    scanf("%c",&opt);
                    if(opt=='1'){
                    char name[30];
                    printf("\n\n\t\t\t\t\t\t\t\t\t\tEnter the name of patient : ");
                    fflush(stdin);
                    fgets(name,30,stdin);
					P_nmodify(&P,name);
                    printf("\n\n\t\t\t\t\t\t\t\t\t\tPress any key to continue...");
                    fflush(stdin);
                    if(getch())
                        system("cls");
                    menu_patient();
                        }
                    else if(opt=='2'){
                    int ID;
                    printf("\n\n\t\t\t\t\t\t\t\t\t\tEnter the ID of patient : ");
                    fflush(stdin);
                    scanf("%d",&ID);
					P_imodify(&P,ID);
                    printf("\n\n\t\t\t\t\t\t\t\t\t\tPress any key to continue...");
                    fflush(stdin);
                    if(getch())
                        system("cls");
                    menu_patient();
                    }
                    else{
                        printf("\n\n\t\t\t\t\t\t\t\t\t\tinvalid input\n");
                    printf("\n\n\t\t\t\t\t\t\t\t\t\tPress any key to continue...");
                    fflush(stdin);
                    if(getch())
                        system("cls");
                    menu_patient();
                    }
                }


            else if(i=='3')
                {
                    system("cls");
                    printf("\n\n\n\t\t\t\t\t\t\t\t\t\tPATIENT SEARCH : \n");
                    menu_search();
                    while(1){
                        char opt;
                        fflush(stdin);
                        scanf("%c",&opt);
                        if(opt=='1'){
                            char name[30];
                            printf("\n\n\t\t\t\t\t\t\t\t\t\tEnter the Patient Name : ");
                            fflush(stdin);
                            fgets(name,30,stdin);
                            P_nsearch(P,name);
                            printf("\n\n\t\t\t\t\t\t\t\t\t\tPress any key to continue...");
                            fflush(stdin);
                            if(getch())
                                system("cls");
                            menu_patient();
                            break;
                            }
                        else if(opt=='2'){
                            int ID;
                             printf("\n\n\t\t\t\t\t\t\t\t\t\tEnter the Patient ID : ");
                            fflush(stdin);
                            scanf("%d",&ID);
                            P_isearch(P,ID);
                            printf("\n\n\t\t\t\t\t\t\t\t\t\tPress any key to continue...");
                            fflush(stdin);
                            if(getch())
                                system("cls");
                            menu_patient();
                            break;
                            }
                        else{
                            printf("\n\n\t\t\t\t\t\t\t\t\t\tPlease enter valid input...\n");
                            }
                        }
                    }

            else if(i=='4')
                {
                    system("cls");
                    //printf("Appointment menu :\n");
                    menu_appointment();
                    char opt;
                    fflush(stdin);
                    scanf("%c",&opt);

                    if(opt=='1'){
                        printf("\n\n\t\t\t\t\t\t\t\t\t\tEnter patient name : ");
                        char name[30];
                        fflush(stdin);
					    fgets(name,30,stdin);
					    if(Search(P,name)){
                            A_create_node(&A,name);
                                }
                        else{
                            printf("\n\n\t\t\t\t\t\t\t\t\t\tNew Patient???\n\n\t\t\t\t\t\t\t\t\t\tPlease create a new record to book appointment\n");
                                }
                        printf("\n\n\t\t\t\t\t\t\t\t\t\tPress any key to continue...");
                        fflush(stdin);
                        if(getch())
                            system("cls");
                        menu_patient();
                            }

                    else if(opt=='2'){
                        printf("\n\n\t\t\t\t\t\t\t\t\t\tEnter patient name : ");
                        char name[30];
                        fflush(stdin);
					    fgets(name,30,stdin);
                        A_display(A,name);
                        printf("\n\n\t\t\t\t\t\t\t\t\t\tPress any key to continue...");
                        fflush(stdin);
                        if(getch())
                            system("cls");
                        menu_patient();
                            }

                    else{
                        printf("\n\n\t\t\t\t\t\t\t\t\t\tEnter valid input");
                            }
            }

            else if(i=='5'){
                system("cls");
                printf("\n\n\n\t\t\t\t\t\t\t\t\t\tFEEDBACK/SUGGESTIONS :\n");
                review();
                printf("\n\n\t\t\t\t\t\t\t\t\t\tPress any key to continue...");
                fflush(stdin);
                if(getch())
                    system("cls");
                menu_patient();
            }

            else if(i=='6'){
                system("cls");
            }

            else{
            	printf("\n\n\t\t\t\t\t\t\t\t\t\tPlease enter a valid input...\n\n\t\t\t\t\t\t\t\t\t\tSelect Option : ");
            	continue;
			}
                P_Writetofile(P);
                A_Writetofile(A);
    }while(i!='6');
    main();
    }

    else if(z=='2'){
        int k=0;
        system("cls");
        printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tEnter Admin Password to Grant Access Authorisation :\n\t\t\t\t\t\t\t\t\t\t\t\t");
        char password[100];
        fflush(stdin);
        do{
            password[k]=_getch();
            if(password[k]!='\r')
                printf("*");
            k++;
    }while(password[k-1]!='\r');
    password[k-1]='\0';
    system("cls");
    if(!strcmp(password,pass1)){
    char i;
    stf *S=NULL;
    S_readfromfile(&S);
    menu_staff();
    do{
            fflush(stdin);
            scanf("%c",&i);

            if(i=='1')
                {
                    system("cls");
                    printf("\n\n\n\t\t\t\t\t\t\t\t\t\tCREATE STAFF PROFILE :\n");
                    S_create_node(&S);
                    printf("\n\n\n\t\t\t\t\t\t\t\t\t\tPress any key to continue...");
                    fflush(stdin);
                    if(getch())
                        system("cls");
                    menu_staff();
                    }

            else if(i=='2')
                {
                    system("cls");
                    printf("\n\n\n\t\t\t\t\t\t\t\t\t\tMODIFY STAFF  PROFILE :\n");
                    menu_search();
                    char opt;
                    fflush(stdin);
                    scanf("%c",&opt);
                    if(opt=='1'){
                    char name[30];
                    printf("\n\n\t\t\t\t\t\t\t\t\t\tEnter the name of staff : ");
                    fflush(stdin);
                    fgets(name,30,stdin);
					S_nmodify(&S,name);
                    printf("\n\n\t\t\t\t\t\t\t\t\t\tPress any key to continue...");
                    fflush(stdin);
                    if(getch())
                        system("cls");
                    menu_staff();
                        }
                    else if(opt=='2'){
                    int ID;
                    printf("\n\n\t\t\t\t\t\t\t\t\t\tEnter the ID of staff : ");
                    fflush(stdin);
                    scanf("%d",&ID);
					S_imodify(&S,ID);
                    printf("\n\n\t\t\t\t\t\t\t\t\t\tPress any key to continue...");
                    fflush(stdin);
                    if(getch())
                        system("cls");
                    menu_staff();
                    }
                    else{
                        printf("\n\t\t\t\t\t\t\t\t\t\tinvalid input\n");
                    printf("\n\tPress any key to continue...");
                    fflush(stdin);
                    if(getch())
                        system("cls");
                    menu_staff();
                    }
                    }


            else if(i=='3')
                {
                    system("cls");
                    printf("\n\n\n\t\t\t\t\t\t\t\t\t\tSTAFF SEARCH : \n");
                    menu_search();
                    while(1){
                        char opt;
                        fflush(stdin);
                        scanf("%c",&opt);
                        if(opt=='1'){
                            char name[30];
                            printf("\n\n\t\t\t\t\t\t\t\t\t\tEnter the name of staff : ");
                            fflush(stdin);
                            fgets(name,30,stdin);
                            S_nsearch(S,name);
                            printf("\n\n\t\t\t\t\t\t\t\t\t\tPress any key to continue...");
                            fflush(stdin);
                            if(getch())
                                system("cls");
                            menu_staff();
                            break;
                            }
                        else if(opt=='2'){
                            int ID;
                             printf("\n\n\t\t\t\t\t\t\t\t\t\tEnter the ID of staff : ");
                            fflush(stdin);
                            scanf("%d",&ID);
                            S_isearch(S,ID);
                            printf("\n\n\t\t\t\t\t\t\t\t\t\tPress any key to continue...");
                            fflush(stdin);
                            if(getch())
                                system("cls");
                            menu_staff();
                            break;
                            }
                        else{
                            printf("\n\n\t\t\t\t\t\t\t\t\t\tPlease enter valid input...");
                            }
                        }
                    }

            else if(i=='4'){
                system("cls");
            }

            else{
            	printf("\n\n\t\t\t\t\t\t\t\t\t\tPlease enter a valid input...\n\n\t\t\t\t\t\t\t\t\t\tSelect Option : ");
            	continue;
            }
                S_Writetofile(S);
    }while(i!='4');
}
	else
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t******!!! ACCESS DENIED !!!******");
		delay(2);
		system("cls");
	}
    main();
    }

    else if(z=='3'){
        int k=0;
        system("cls");
        printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tEnter Admin Password to Grant Access Authorisation :\n\t\t\t\t\t\t\t\t\t\t\t\t");
        char password[100];
        fflush(stdin);
        do{
            password[k]=_getch();
            
            if(password[k]!='\r')
                printf("*");
            k++;
    }while(password[k-1]!='\r');
    password[k-1]='\0';
    system("cls");
    char i;
    appt *A=NULL;
    stf *S=NULL;
    pat *P=NULL;
    A_readfromfile(&A);
    S_readfromfile(&S);
    P_readfromfile(&P);
	if(strcmp(pass2,password)==0)
	{
    menu_admin();
    do{
            fflush(stdin);
            scanf("%c",&i);
            
            if(i=='1'){
                system("cls");
                printf("\n\n\n\t\t\t\t\t\t\t\t\t\tEnter Patient Name: ");
                char name[30];
                fflush(stdin);
                fgets(name,30,stdin);
                if(A!=NULL)
                {

					A_delete_record(&A,name);
				}
				else if(A==NULL)
                printf("\n\n\t\t\t\t\t\t\t\t\t\tNo Appointments Pending!!!\n");
                printf("\n\n\t\t\t\t\t\t\t\t\t\tPress any key to continue...");
                fflush(stdin);
                if(getch())
                    system("cls");
                menu_admin();
            }
            
            else if(i=='2')
                {

                    system("cls");
                    printf("\n\n\n\t\t\t\t\t\t\t\t\t\tDELETE PATIENT PROFILE :\n");
                    char name[30];
                    printf("\n\n\t\t\t\t\t\t\t\t\t\tEnter the name of patient : ");
                    fflush(stdin);
                    fgets(name,30,stdin);
                    P_delete_record(&P,name);
                    printf("\n\n\t\t\t\t\t\t\t\t\t\tPress any key to continue...");
                    if(getch())
                        system("cls");
                    menu_admin();

                    }

            else if(i=='3')
                {

                    system("cls");
                    printf("\n\n\n\t\t\t\t\t\t\t\t\t\tDELETE STAFF PROFILE :");
                    char name[30];
                    printf("\n\n\t\t\t\t\t\t\t\t\t\tEnter the name of staff : ");
                    fflush(stdin);
                    fgets(name,30,stdin);
                    S_delete_record(&S,name);
                    printf("\n\n\t\t\t\t\t\t\t\t\t\tPress any key to continue...");
                    fflush(stdin);
                    if(getch())
                        system("cls");
                    menu_admin();
                    }

            else if(i=='4')
                {

                    system("cls");
                    if(P!=NULL){
                    printf("\n\n\n\t\t\t\t\t\t\t\t\t\tPATIENT DATA : \n\n");
                    P_display(P);
                    printf("\n\n\t\t\t\t\t\t\t\t\t\tPress any key to continue...");
                    fflush(stdin);
                    if(getch())
                        system("cls");
                    menu_admin();
                        }
                    else{
                        printf("\n\n\t\t\t\t\t\t\t\t\t\t No records found");
                        printf("\n\t\t\t\t\t\t\t\t\t\tPress any key to continue...");
                        fflush(stdin);
                        if(getch())
                            system("cls");
                        menu_admin();
                            }
                    }

            else if(i=='5')
                {
                    system("cls");
                    if(S!=NULL){

                        printf("\n\n\n\t\t\t\t\t\t\t\t\t\tSTAFF DATA :\n");
                        S_display(S);
                        printf("\n\n\t\t\t\t\t\t\t\t\t\tPress any key to continue...");
                        fflush(stdin);
                        if(getch())
                            system("cls");
                        menu_admin();
                        }
                    else{
                        printf("\n\n\t\t\t\t\t\t\t\t\t\t No records found");
                        printf("\n\t\t\t\t\t\t\t\t\t\tPress any key to continue...");
                        fflush(stdin);
                        if(getch())
                            system("cls");
                        menu_admin();
                            }
                    }

            else if(i=='6'){
                system("cls");
                printf("\n\n\n\n\tFEEDBACKS/SUGGESTIONS :\n\n\n\n");
                review_display();
                printf("\n\tPress any key to continue...");
                fflush(stdin);
                if(getch())
                    system("cls");
                menu_admin();
            }

            else if(i=='7'){
                system("cls");
            }

            else{
            	printf("\n\n\t\t\t\t\t\t\t\t\t\tPlease enter a valid input...\n\n\t\t\t\t\t\t\t\t\t\tSelect Option : ");
            	continue;
            }
            P_Writetofile(P);
            S_Writetofile(S);
            A_Writetofile(A);
    }while(i!='7');
	}
	else
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t******!!! ACCESS DENIED !!!******");
		delay(2);
		system("cls");
	}
    main();
    }


    else if(z=='4'){
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\tTHANK YOU!!");
		delay(2);
		system("cls");
        exit(0);
    }

	else{
        system("cls");
        printf("\n\n\t\t\t\t\t\t\t\t\t\tPlease enter a valid input...\n");
        delay(1);
        system("cls");
        main();
	}
}

