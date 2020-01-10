//structure with hospital staff details
typedef struct staff_record
{
    int S_id;
	char address[30],sex[2],age[4],name[30],contact_number[11];
	struct staff_record *next;
}stf;

//function to overwrite the whole linked list containing patient data to file
void S_Writetofile(stf *node){
	//opening file in overwrite mode
	FILE *f=fopen("S_hospital.dat","w+");
	while(node!=NULL){
        //writing each node of linked list to file
        fwrite(node,sizeof(stf),1,f);
	    node=node->next;
	}
	fclose(f);
}

//reading staff data from file and storing it in linked list
void S_readfromfile(stf **head_ref){
	FILE *f=fopen("S_hospital.dat","a+");
	//calculating the size of file to know the number of nodes(staff records)
	*head_ref=NULL;
	free(*head_ref);
	long lsize;
	char *c;
	size_t result;
	fseek(f,0,SEEK_END);
	lsize=ftell(f);
	rewind(f);
	int i;
	//iterating and reading the staff details and adding each one at the end of the linked list
	for(i=0;i<(int)lsize/sizeof(stf);i++)
	{
		stf *tmp=*head_ref;
		stf *new_record=(stf*)malloc(sizeof(stf));
		fread(new_record,sizeof(stf),1,f);
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


void S_create_node(stf **head_ref){
	int Count=0;
	stf *new_record=(stf*)malloc(sizeof(stf));
	if(*head_ref==NULL){
        new_record->S_id=1;
	}
	printf("\n\n\t\t\t\t\t\t\t\t\t\t1.Name :");
	fflush(stdin);
	fgets(new_record->name,30,stdin);
	printf("\n\n\t\t\t\t\t\t\t\t\t\t2.Adrress :");
	fgets(new_record->address,30,stdin);
	printf("\n\n\t\t\t\t\t\t\t\t\t\t4.Sex M/F:");
	while(1){
		scanf("%s",&new_record->sex);
		Count=strlen(new_record->sex);
	if(Count>1||(strcmp(new_record->sex,"M")&&strcmp(new_record->sex,"m")&&strcmp(new_record->sex,"F")&&strcmp(new_record->sex,"f")))
		printf("\n\n\t\t\t\t\t\t\t\t\t\tinvalid input...\n\t\t\t\t\t\t\t\t\t\t\n\t\t\t\t\t\t\t\t\t\tPlease enter valid input\n\n\t\t\t\t\t\t\t\t\t\t4.Sex M/F:");
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
	new_record->next=*head_ref;
	if(*head_ref!=NULL){
	int id=new_record->next->S_id;
	new_record->S_id=id+1;}
	*head_ref=new_record;
	printf("\n\n\t\t\t\t\t\t\t\t\t\t Staff record added successfully!\n\n\t\t\t\t\t\t\t\t\t\t Your Staff ID is ' %d '",new_record->S_id);
}


//displaying all the nodes present in the linked list containing staff details
void S_display(stf *node){
	while(node!=NULL){
    printf("\n\n\t\t\t\t\t\t\t\t\t\tStaff ID:  %d",node->S_id);
	printf("\n\t\t\t\t\t\t\t\t\t\t1.Name : %s",node->name);
	printf("\n\t\t\t\t\t\t\t\t\t\t2.Address : %s",node->address);
	printf("\n\t\t\t\t\t\t\t\t\t\t3.Sex : %s",node->sex);
	printf("\n\t\t\t\t\t\t\t\t\t\t4.Age : %s",node->age);
	printf("\n\t\t\t\t\t\t\t\t\t\t5.Contact Number : %s\n\n\n",node->contact_number);
	node=node->next;
	}
}

//searching for staff by name
void S_nsearch(stf *node,char str[]){

    int flg=1;
	while(node!=NULL){
		if(!strcmp(node->name,str)){
            printf("\n\n\t\t\t\t\t\t\t\t\t\t1.Name : %s",node->name);
            printf("\n\t\t\t\t\t\t\t\t\t\t2.Address : %s",node->address);
	        printf("\n\t\t\t\t\t\t\t\t\t\t3.Sex : %s",node->sex);
	        printf("\n\n\t\t\t\t\t\t\t\t\t\t4.Age : %s",node->age);
	        printf("\n\n\t\t\t\t\t\t\t\t\t\t5.Contact Number : %s",node->contact_number);
	        flg=0;
	        break;
		}
		node=node->next;
	}
	if(flg)
        printf("\n\n\t\t\t\t\t\t\t\t\t\tStaff Profile not found...");

}

//searching for staff by ID
void S_isearch(stf *node,int ID){

    int flg=1;
	while(node!=NULL){
		if(node->S_id==ID){
            printf("\n\n\t\t\t\t\t\t\t\t\t\tStaff ID:  %d",node->S_id);
            printf("\n\t\t\t\t\t\t\t\t\t\t1.Name : %s",node->name);
            printf("\n\t\t\t\t\t\t\t\t\t\t2.Address : %s",node->address);
	        printf("\n\t\t\t\t\t\t\t\t\t\t3.Sex : %s",node->sex);
	        printf("\n\n\t\t\t\t\t\t\t\t\t\t4.Age : %s",node->age);
	        printf("\n\n\t\t\t\t\t\t\t\t\t\t5.Contact Number : %s",node->contact_number);
	        flg=0;
	        break;
		}
		node=node->next;
	}
	if(flg)
        printf("\n\n\t\t\t\t\t\t\t\t\t\tStaff Profile not found...");

}


//function to delete staff record from linked list containing staff details
void S_delete_record(stf **head_ref,char str[]){
	stf *temp=*head_ref,*prev;
	while(temp!=NULL){
        if(!strcmp(temp->name,str))
            break;
        else temp=temp->next;
	}
	if(temp==NULL){
            printf("\n\n\t\t\t\t\t\t\t\t\t\tpatient profile not found...");
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
	while(!strcmp(temp->name,str)&&temp!=NULL){
		prev=temp;
		temp=temp->next;
	}
	if(!strcmp(temp->name,str)){
		prev->next=temp->next;
		free(temp);
		printf("\n\n\t\t\t\t\t\t\t\t\t\tPatient record deleted successfully...\n");
	}
	else{
		printf("\n\n\t\t\t\t\t\t\t\t\t\tstaff profile not found...");
	}
}

//function to modify staff details through search by name and update that node in the linked list
void S_nmodify(stf **head_ref,char str[]){
	int Count=0;
    stf *new_record=(stf*)malloc(sizeof(stf));
    new_record=*head_ref;
    int flg=1;
	while(new_record!=NULL){
		if(!strcmp(new_record->name,str)){
	        printf("\n\n\n\t\t\t\t\t\t\t\t\t\tEnter new details :");
	        printf("\n\n\t\t\t\t\t\t\t\t\t\t1.Name : ");
	        fflush(stdin);
	        fgets(new_record->name,30,stdin);
	        printf("\n\n\t\t\t\t\t\t\t\t\t\t2.Adrress : ");
	        fgets(new_record->address,30,stdin);
	        printf("\n\n\t\t\t\t\t\t\t\t\t\t4.Sex M/F: ");
	        while(1){
                scanf("%s",&new_record->sex);
		        Count=strlen(new_record->sex);
                if(Count>1||(strcmp(new_record->sex,"M")&&strcmp(new_record->sex,"m")&&strcmp(new_record->sex,"F")&&strcmp(new_record->sex,"f")))
                    printf("\n\t\t\t\t\t\t\t\t\t\tinvalid input...\n\t\t\t\t\t\t\t\t\t\tPlease enter valid input\n\n\t\t\t\t\t\t\t\t\t\t4.Sex M/F:");
                else
                    break;
	        }
            while(1){
                int i;
                printf("\n\n\t\t\t\t\t\t\t\t\t\t5.Age :");
                fflush(stdin);
                scanf("%s",&new_record->age);
                if(strlen(new_record->age)>3){
                    printf("\n\t\t\t\t\t\t\t\t\t\tInvalid Input.");
                    continue;
                    }
                for(i=0;i<strlen(new_record->age);i++){
                    if(new_record->age[i]<48||new_record->age[i]>57){
                        printf("\n\t\t\t\t\t\t\t\t\t\tInvalid Input.");
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
                    printf("\n\t\t\t\t\t\t\t\t\t\tInvalid Input.");
			        continue;
                    }
                for(i=0;i<strlen(new_record->contact_number);i++){
                    if(new_record->contact_number[i]<48||new_record->contact_number[i]>57){
                        printf("\n\t\t\t\t\t\t\t\t\t\tInvalid Input.");
                        break;
                        }
                    }
                if(i<strlen(new_record->age))
                    continue;
                break;
	        }
            printf("\n\n\t\t\t\t\t\t\t\t\t\tProfile modified successfully...\n");
            flg=0;
            break;
		}
        new_record=new_record->next;
	}
	if(flg)
	printf("\n\n\t\t\t\t\t\t\t\t\t\tstaff profile not found...");
}

//function to modify staff details through search by ID and update that node in the linked list
void S_imodify(stf **head_ref,int ID){
	int Count=0;
    stf *new_record=(stf*)malloc(sizeof(stf));
    new_record=*head_ref;
    int flg=1;
	while(new_record!=NULL){
		if(new_record->S_id==ID){
	        printf("\n\n\n\t\t\t\t\t\t\t\t\t\tEnter new details :");
	        printf("\n\n\t\t\t\t\t\t\t\t\t\t1.Name : ");
	        fflush(stdin);
	        fgets(new_record->name,30,stdin);
	        printf("\n\n\t\t\t\t\t\t\t\t\t\t2.Adrress : ");
	        fgets(new_record->address,30,stdin);
	        printf("\n\n\t\t\t\t\t\t\t\t\t\t4.Sex M/F: ");
	        while(1){
                scanf("%s",&new_record->sex);
		        Count=strlen(new_record->sex);
                if(Count>1||(strcmp(new_record->sex,"M")&&strcmp(new_record->sex,"m")&&strcmp(new_record->sex,"F")&&strcmp(new_record->sex,"f")))
                    printf("\n\t\t\t\t\t\t\t\t\t\tinvalid input...\n\t\t\t\t\t\t\t\t\t\tPlease enter valid input\n\n\t\t\t\t\t\t\t\t\t\t4.Sex M/F:");
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
            printf("\n\n\t\t\t\t\t\t\t\t\t\tRecord modified successfully...\n");
            flg=0;
            break;
		}
        new_record=new_record->next;
	}
	if(flg)
	printf("\n\n\t\t\t\t\t\t\t\t\t\tstaff record not found...");
}

