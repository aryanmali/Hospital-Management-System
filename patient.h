//structure with patient details
typedef struct patient_record
{
    int P_id;
	char address[30],disease[30],sex[2],age[4],name[30],contact_number[11],password[30];
	struct patient_record *next;
}pat;

//function to overwrite the whole linked list containing patient data to file
void P_Writetofile(pat *n){
	//opening file in overwrite mode
	FILE *f=fopen("P_hospital.dat","w+");
	pat *node=n;
	while(node!=NULL){
	    //writing each node of linked list to file
	    fwrite(node,sizeof(pat),1,f);
		node=node->next;
	}
	fclose(f);
}

//reading patient data from file and storing it in linked list
void P_readfromfile(pat **head_ref){
	FILE *f=fopen("P_hospital.dat","a+");
	//calculating the size of file to know the number of nodes(patient records)
	*head_ref=NULL;
	free(*head_ref);
	long lsize;
	char *c;
	size_t result;
	fseek(f,0,SEEK_END);
	lsize=ftell(f);
	rewind(f);
	int i;
	//iterating and reading the patient details and adding each one at the end of the linked list
	for(i=0;i<(int)lsize/sizeof(pat);i++)
	{
		pat *tmp=*head_ref;
		pat *new_record=(pat*)malloc(sizeof(pat));
		fread(new_record,sizeof(pat),1,f);
		new_record->next=NULL;
		if(tmp==NULL)
		{
		    *head_ref=new_record;
			continue;
			}
		while(tmp->next!=NULL)
		{
		    tmp=tmp->next;
			}
	    tmp->next=new_record;
		}
	fclose(f);
}

//taking input and creating a new node in the linked list
void P_create_node(pat **head_ref){
	int Count=0;
	pat *new_record=(pat*)malloc(sizeof(pat));
	//assigning patient IDs
	if(*head_ref==NULL){
        new_record->P_id=1;
	}
	//taking patient details from user
	printf("\n\n\t\t\t\t\t\t\t\t\t\t1.Name :");
	fflush(stdin);
	fgets(new_record->name,30,stdin);//fgets(new_record->name,30,stdin);
	printf("\n\n\t\t\t\t\t\t\t\t\t\t2.Adrress :");
	fgets(new_record->address,30,stdin);
	printf("\n\n\t\t\t\t\t\t\t\t\t\t3.Health issue :");
	fgets(new_record->disease,30,stdin);
	printf("\n\n\t\t\t\t\t\t\t\t\t\t4.Sex M/F:");
	while(1){
		scanf("%s",&new_record->sex);
		Count=strlen(new_record->sex);
	if(Count>1||(strcmp(new_record->sex,"M")&&strcmp(new_record->sex,"m")&&strcmp(new_record->sex,"F")&&strcmp(new_record->sex,"f")))
		printf("\n\t\t\t\t\t\t\t\t\t\tinvalid input...\n\t\t\t\t\t\t\t\t\t\tPlease enter valid input\n\t\t\t\t\t\t\t\t\t\t4.Sex M/F:");
		else
		break;
	}
	while(1){
		int i;
	printf("\n\n\t\t\t\t\t\t\t\t\t\t5.Age :");
	fflush(stdin);
	scanf("%s",&new_record->age);
	if(strlen(new_record->age)>3)
		{
			printf("\n\n\t\t\t\t\t\t\t\t\t\tInvalid Input.");
			continue;
		}
	for(i=0;i<strlen(new_record->age);i++){
		if(new_record->age[i]<48||new_record->age[i]>57){
			printf("\n\n\t\t\t\t\t\t\t\t\t\tInvalid Input.");
       		break;

			}
		}
		if(i<strlen(new_record->age))
			continue;
		break;
	}
	while(1){
		int i;
	printf("\n\n\t\t\t\t\t\t\t\t\t\t6.Contact Number :");
	fflush(stdin);
	scanf("%s",&new_record->contact_number);
	if(strlen(new_record->contact_number)!=10)
		{
			printf("\n\n\t\t\t\t\t\t\t\t\t\tInvalid Input.");
			continue;
		}
	for(i=0;i<strlen(new_record->contact_number);i++){
		if(new_record->contact_number[i]<48||new_record->contact_number[i]>57){
			printf("\n\n\t\t\t\t\t\t\t\t\t\tInvalid Input.");
       		break;

			}
		}
		if(i<strlen(new_record->age))
			continue;
		break;
	}
	int k=0;
	char str1[30],str2[30];
	while(1){
	printf("\n\n\t\t\t\t\t\t\t\t\t\tEnter Password : ");
	fflush(stdin);
    do{
        str1[k]=_getch();
        if(str1[k]!='\r')
            printf("*");
        k++;
    }while(str1[k-1]!='\r');
    str1[k-1]='\0';
    k=0;
	printf("\n\n\t\t\t\t\t\t\t\t\t\tConfirm Password : ");
	fflush(stdin);
    do{
        str2[k]=_getch();
        if(str2[k]!='\r')
            printf("*");
        k++;
    }while(str2[k-1]!='\r');
    str2[k-1]='\0';	;
	if(!strcmp(str1,str2)){
        strcpy(new_record->password,str1);
        break;
	}
	else{
        printf("\n\n\t\t\t\t\t\t\t\t\t\tPasswords didn't matched! :(\n");
	}
	}
	//adding the node to the linked list
	new_record->next=*head_ref;
	if(*head_ref!=NULL){
	int id=new_record->next->P_id;
	new_record->P_id=id+1;}
	*head_ref=new_record;
	printf("\n\n\t\t\t\t\t\t\t\t\t\t Record added successfully!\n\n\t\t\t\t\t\t\t\t\t\t Your Patient ID is ' %d '",new_record->P_id);
}

//displaying all the nodes present in the linked list containing patient details
void P_display(pat *node){
	while(node!=NULL){
	printf("\n\t\t\t\t\t\t\t\t\t\tPatient ID:  %d",node->P_id);
	printf("\n\t\t\t\t\t\t\t\t\t\t1.Name : %s",node->name);
	printf("\n\t\t\t\t\t\t\t\t\t\t2.Address : %s",node->address);
	printf("\n\t\t\t\t\t\t\t\t\t\t3.Health issue : %s",node->disease);
	printf("\n\t\t\t\t\t\t\t\t\t\t4.Sex : %s",node->sex);
	printf("\n\n\t\t\t\t\t\t\t\t\t\t5.Age : %s",node->age);
	printf("\n\n\t\t\t\t\t\t\t\t\t\t6.Contact Number : %s\n\n\n",node->contact_number);
	node=node->next;
	}
}

//searching for patient by name
void P_nsearch(pat *node,char str[]){
    int flg=1,k=0;
    pat *n=node;
	while(n!=NULL){
		if(!strcmp(n->name,str)){
            //checking for password before displaying patient data
            printf("\n\n\t\t\t\t\t\t\t\t\t\tEnter your password : ");
            char str[30];
            fflush(stdin);
            do{
                str[k]=_getch();
                if(str[k]!='\r')
                    printf("*");
                k++;
            }while(str[k-1]!='\r');
            str[k-1]='\0';
            if(!strcmp(str,n->password)){
                printf("\n\n\t\t\t\t\t\t\t\t\t\tPatient ID:  %d",n->P_id);
                printf("\n\t\t\t\t\t\t\t\t\t\t1.Name : %s",n->name);
                printf("\n\t\t\t\t\t\t\t\t\t\t2.Address : %s",n->address);
                printf("\n\t\t\t\t\t\t\t\t\t\t3.Health issue : %s",n->disease);
                printf("\n\t\t\t\t\t\t\t\t\t\t4.Sex : %s",n->sex);
                printf("\n\n\t\t\t\t\t\t\t\t\t\t5.Age : %s",n->age);
                printf("\n\n\t\t\t\t\t\t\t\t\t\t6.Contact Number : %s\n",n->contact_number);
                flg=0;
                break;
                }
            else{
                printf("\n\n\t\t\t\t\t\t\t\t\t\tIncorrect password :(\n");
                return;
            }
		}
		n=n->next;
	}
	if(flg)
	printf("\n\n\t\t\t\t\t\t\t\t\t\tPatient Profile not found...");
}

//searching for patient by ID
void P_isearch(pat *node,int i){
    int flg=1,k=0;
    pat *n=node;
	while(n!=NULL){
		if(n->P_id==i){
        //checking for password before displaying patient data
        printf("\n\n\t\t\t\t\t\t\t\t\t\tEnter Password : ");
            char str[30];
            fflush(stdin);
            do{
                str[k]=_getch();
                if(str[k]!='\r')
                    printf("*");
                k++;
            }while(str[k-1]!='\r');
            str[k-1]='\0';
            if(!strcmp(str,n->password)){
    printf("\n\n\t\t\t\t\t\t\t\t\t\tPatient ID:  %d",n->P_id);
	printf("\n\t\t\t\t\t\t\t\t\t\t1.Name : %s",n->name);
	printf("\n\t\t\t\t\t\t\t\t\t\t2.Address : %s",n->address);
	printf("\n\t\t\t\t\t\t\t\t\t\t3.Health issue : %s",n->disease);
	printf("\n\t\t\t\t\t\t\t\t\t\t4.Sex : %s",n->sex);
	printf("\n\n\t\t\t\t\t\t\t\t\t\t5.Age : %s",n->age);
	printf("\n\n\t\t\t\t\t\t\t\t\t\t6.Contact Number : %s\n",n->contact_number);
	flg=0;
	break;
            }
            else{
                printf("\nIncorrect Password :(\n");
                return;
            }
		}
		n=n->next;
	}
	if(flg)
	printf("\n\n\t\t\t\t\t\t\t\t\t\tPatient Profile not found...");
}

//function to delete patient record from linked list containing staff details
void P_delete_record(pat **head_ref,char str[]){
	pat *temp=*head_ref,*prev;
	while(temp!=NULL){
        if(!strcmp(temp->name,str))
            break;
        else temp=temp->next;
	}
	if(temp==NULL){
            printf("\n\n\t\t\t\t\t\t\t\t\t\tPatient Profile not found...");
        return ;
        }
    else
        temp=*head_ref;
	if(temp!=NULL&&!strcmp(temp->name,str)){
		*head_ref=temp->next;
		free(temp);
		printf("\n\n\t\t\t\t\t\t\t\t\t\tPatient Profile deleted successfully...\n");
		return;
	}
	while(strcmp(temp->name,str)&&temp!=NULL){
		prev=temp;
		temp=temp->next;
	}
	if(temp==NULL){
		printf("\n\n\t\t\t\t\t\t\t\t\t\tPatient Profile not found...");
		return;
	}
	else{
		prev->next=temp->next;
		free(temp);
		printf("\n\n\t\t\t\t\t\t\t\t\t\tPatient Profile deleted successfully...\n");
	}
}

//function to take feedback from the patient
void review(){
    FILE *f=fopen("review.dat","a+");
    fprintf(f,"%s","(");
    char  name[30];
    printf("\n\n\t\t\t\t\t\t\t\t\t\tEnter your name : ");
    fflush(stdin);
    gets(name);
    fprintf(f,"%s","Name : ");
    fprintf(f,"%s\n",name);
    printf("\n\n\t\t\t\t\t\t\t\t\t\tPlease leave your review/feedback-\n\n\t\t\t\t\t\t\t\t\t\t");
    char fb[300];
    gets(fb);
    fprintf(f,"%s\n",fb);
    fprintf(f,"%s\n","\n**********************************************\n\n");
    printf("\n\n\t\t\t\t\t\t\t\t\t\tThank you for your valuable feedback. :) \n");
    fclose(f);
}

//function to modify patient details through search by name and update that node in the linked list
void P_nmodify(pat **head_ref,char str[]){
	int Count=0;
    pat *new_record=(pat*)malloc(sizeof(pat));
    new_record=*head_ref;
    int flg=1,k=0;
	while(new_record!=NULL){
		if(!strcmp(new_record->name,str)){
        //checking for password before displaying patient data
        printf("\n\n\t\t\t\t\t\t\t\t\t\tEnter Password : ");
            char str[30];
            fflush(stdin);
            do{
                str[k]=_getch();
                if(str[k]!='\r')
                    printf("*");
                k++;
            }while(str[k-1]!='\r');
            str[k-1]='\0';
            if(!strcmp(str,new_record->password)){
	        printf("\n\n\n\t\t\t\t\t\t\t\t\t\tEnter new details :");
	        printf("\n\n\t\t\t\t\t\t\t\t\t\t1.Name : ");
	        fgets(new_record->name,30,stdin);
	        printf("\n\n\t\t\t\t\t\t\t\t\t\t2.Adrress : ");
	        fgets(new_record->address,30,stdin);
	        printf("\n\n\t\t\t\t\t\t\t\t\t\t3.Health issue : ");
	        fgets(new_record->disease,30,stdin);
	        printf("\n\n\t\t\t\t\t\t\t\t\t\t4.Sex M/F: ");
	        while(1){
		        scanf("%s",&new_record->sex);
		        Count=strlen(new_record->sex);
                if(Count>1||(strcmp(new_record->sex,"M")&&strcmp(new_record->sex,"m")&&strcmp(new_record->sex,"F")&&strcmp(new_record->sex,"f")))
                    printf("\n\t\t\t\t\t\t\t\t\t\tinvalid input...\n\t\t\t\t\t\t\t\t\t\tPlease enter valid input\n\t\t\t\t\t\t\t\t\t\t4.Sex M/F:");
                else
                    break;
                }
	        while(1){
                int i;
                printf("\n\n\t\t\t\t\t\t\t\t\t\t5.Age :");
                fflush(stdin);
                scanf("%s",&new_record->age);
                if(strlen(new_record->age)>3){
                    printf("\n\n\t\t\t\t\t\t\t\t\t\tInvalid Input.");
                    continue;
                    }
                for(i=0;i<strlen(new_record->age);i++){
                    if(new_record->age[i]<48||new_record->age[i]>57){
                        printf("\n\n\t\t\t\t\t\t\t\t\t\tInvalid Input.");
                        break;
                    }
                }
                if(i<strlen(new_record->age))
                    continue;
                break;
            }
	        while(1){
		        int i;
                printf("\n\n\t\t\t\t\t\t\t\t\t\t6.Contact Number :");
                fflush(stdin);
                scanf("%s",&new_record->contact_number);
                if(strlen(new_record->contact_number)!=10){
			        printf("\n\n\t\t\t\t\t\t\t\t\t\tInvalid Input.");
			        continue;
                    }
                for(i=0;i<strlen(new_record->contact_number);i++){
                    if(new_record->contact_number[i]<48||new_record->contact_number[i]>57){
                        printf("\n\n\t\t\t\t\t\t\t\t\t\tInvalid Input.");
                        break;
			        }
		        }
		        if(i<strlen(new_record->age))
			        continue;
		        break;
            }
            printf("\n\n\t\t\t\t\t\t\t\t\t\tRecord modified successfully...");
            flg=0;
            break;
		}
            else{
                printf("\n\n\t\t\t\t\t\t\t\t\t\tIncorrect password");
                return;
            }
	}
    new_record=new_record->next;
	}
	if(flg)
	printf("\n\t\t\t\t\t\t\t\t\t\tpatient profile not found...");
}

//function to modify patient details through search by ID and update that node in the linked list
void P_imodify(pat **head_ref,int ID){
	int Count=0;
    pat *new_record=(pat*)malloc(sizeof(pat));
    new_record=*head_ref;
    int flg=1,k=0;
	while(new_record!=NULL){
		if(new_record->P_id==ID){
        //checking for password before displaying patient data
        printf("\n\n\t\t\t\t\t\t\t\t\t\tEnter your password : ");
            char str[30];
            fflush(stdin);
            do{
                str[k]=_getch();
                if(str[k]!='\r')
                    printf("*");
                k++;
            }while(str[k-1]!='\r');
            str[k-1]='\0';
            if(!strcmp(str,new_record->password)){
	        printf("\n\n\n\t\t\t\t\t\t\t\t\t\tEnter new details :");
	        printf("\n\n\t\t\t\t\t\t\t\t\t\t1.Name : ");
	        fgets(new_record->name,30,stdin);
	        printf("\n\n\t\t\t\t\t\t\t\t\t\t2.Adrress : ");
	        fgets(new_record->address,30,stdin);
	        printf("\n\n\t\t\t\t\t\t\t\t\t\t3.Health issue : ");
	        fgets(new_record->disease,30,stdin);
	        printf("\n\n\t\t\t\t\t\t\t\t\t\t4.Sex M/F: ");
	        while(1){
		        scanf("%s",&new_record->sex);
		        Count=strlen(new_record->sex);
                if(Count>1||(strcmp(new_record->sex,"M")&&strcmp(new_record->sex,"m")&&strcmp(new_record->sex,"F")&&strcmp(new_record->sex,"f")))
                    printf("\n\t\t\t\t\t\t\t\t\t\tinvalid input...\n\t\t\t\t\t\t\t\t\t\tPlease enter valid input\n4.Sex M/F:");
                else
                    break;
                }
	        while(1){
                int i;
                printf("\n\n\t\t\t\t\t\t\t\t\t\t5.Age :");
                fflush(stdin);
                scanf("%s",&new_record->age);
                if(strlen(new_record->age)>3){
                    printf("\n\n\t\t\t\t\t\t\t\t\t\tInvalid Input.");
                    continue;
                    }
                for(i=0;i<strlen(new_record->age);i++){
                    if(new_record->age[i]<48||new_record->age[i]>57){
                        printf("\n\n\t\t\t\t\t\t\t\t\t\tInvalid Input.");
                        break;
                    }
                }
                if(i<strlen(new_record->age))
                    continue;
                break;
            }
	        while(1){
		        int i;
                printf("\n\n\t\t\t\t\t\t\t\t\t\t6.Contact Number :");
                fflush(stdin);
                scanf("%s",&new_record->contact_number);
                if(strlen(new_record->contact_number)!=10){
			        printf("\n\n\t\t\t\t\t\t\t\t\t\tInvalid Input.");
			        continue;
                    }
                for(i=0;i<strlen(new_record->contact_number);i++){
                    if(new_record->contact_number[i]<48||new_record->contact_number[i]>57){
                        printf("\n\n\t\t\t\t\t\t\t\t\t\tInvalid Input.");
                        break;
			        }
		        }
		        if(i<strlen(new_record->age))
			        continue;
		        break;
            }
            printf("\t\n\t\t\t\t\t\t\t\t\t\tProfile modified successfully...\n");
            flg=0;
            break;
		}
            else{
                printf("\n\n\t\t\t\t\t\t\t\t\t\tIncoorect password :(\n");;
                return;
            }
	}
    new_record=new_record->next;
	}
	if(flg)
	printf("\n\n\t\t\t\t\t\t\t\t\t\tpatient profile not found...");
}

