//structure with patient name used to book appointment
typedef struct appointment
{
    char name[30];
    struct appointment *next;
}appt;

//function to overwrite the whole linked list containing patient appt data to file
void A_Writetofile(appt *n){
    //opening file in overwrite mode
	FILE *f=fopen("A_hospital.dat","w+");
	appt *node=n;
	while(node!=NULL){
        //writing each node of linked list to file
	    fwrite(node,sizeof(appt),1,f);
	    node=node->next;
	}
	fclose(f);
}

//function to search and check if the patient is present in hospital patient records before booking an appt
int Search(pat *node,char str[]){
    pat *n=node;
    while(n!=NULL){
        //if patient name is found in hospital records
        if(!strcmp(n->name,str))
            return 1;
        else
            n=n->next;
    }
    //patient data not found in the hospital records
    if(n==NULL)
        return 0;

}

//calculating approximate waiting time for appt
void t_left(int t){
    int h,m;
    h=t/60;
    m=t%60;
    printf("\n\n\t\t\t\t\t\t\t\t\t\tEstimated Time for your appointment is %d h : %d m\n\n",h,m);
    return;
}

//function to add a node to appt queue
void A_create_node(appt **head_ref,char str[]){
    appt *new_node=(appt*)malloc(sizeof(appt));
    appt *temp=*head_ref;
    int Count=1,flg=1;
    while(temp!=NULL){
        if(!strcmp(temp->name,str)){
        	printf("\n\n\t\t\t\t\t\t\t\t\t\tYou have already booked an appointment.\n");
            printf("\n\n\t\t\t\t\t\t\t\t\t\tName : %s",temp->name);
            //approximate time calculated based on number of appointments preceding the patients
            if(Count==1){
            	printf("\n\n\t\t\t\t\t\t\t\t\t\tyou can directly consult doctor :)");
			}
			else
            t_left(Count*15);
            flg=0;
            break;
        }
        else{
            Count++;
            temp=temp->next;
        }
    }
    if(flg){
	temp=*head_ref;
    //inserting the name in the node and adding the node at the end of queue
    strcpy(new_node->name,str);
    new_node->next=NULL;
    //if no prior appointments are found
    if (*head_ref == NULL)
	{
       *head_ref = new_node;
	   }
    //iterating till the end of queue
    else{
	    while(temp->next!=NULL)
		{
            temp=temp->next;
			}
        temp->next=new_node;
	}
    printf("\n\n\t\t\t\t\t\t\t\t\t\tAppointment Booked! :)\n");
    }
}

//function to read the booked appointments from file and storing it in the linked list containing patient appt data
void A_readfromfile(appt **head_ref){
	FILE *f=fopen("A_hospital.dat","a+");
	//calculating the size of file to know the number of nodes(patient appointments)
	long lsize;
	char *c;
	size_t result;
	fseek(f,0,SEEK_END);
	lsize=ftell(f);
	rewind(f);
	int i;
	//iterating and reading the patient appt details and adding each one at the end of queue
	for(i=0;i<(int)lsize/sizeof(appt);i++){
		appt *tmp=*head_ref;
		appt *new_record=(appt*)malloc(sizeof(appt));
		fread(new_record,sizeof(appt),1,f);
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

//display function to show estimated waiting time for appt
void A_display(appt *node,char pname[]){
    int Count=1,flg=1;
    while(node!=NULL){
        if(!strcmp(node->name,pname)){
            printf("\n\n\t\t\t\t\t\t\t\t\t\tName : %s",node->name);
            //approximate time calculated based on number of appointments preceding the patients
            if(Count==1){
            	printf("\n\n\t\t\t\t\t\t\t\t\t\tyou can directly consult doctor :)");
			}
			else
            t_left(--Count*15);
            flg=0;
            break;
        }
        else{
            Count++;
            node=node->next;
        }
    }
    if(flg)
        printf("\n\n\t\t\t\t\t\t\t\t\t\tPatient appointment not found...\n\n");
}

//function to delete patient name from appt linked list upon completion of appt
void A_delete_record(appt **head_ref,char str[]){
	appt *temp=*head_ref,*prev,*sec=temp;
	while(temp!=NULL){
        if(!strcmp(temp->name,str))
            break;
        else temp=temp->next;
	}
	if(temp==NULL){
            printf("\n\n\t\t\t\t\t\t\t\t\t\tpatient appointment not found...\n");
        return ;
        }
    else
        temp=*head_ref;
    while(strcmp(temp->name,str)&&temp!=NULL){
        prev=temp;
        temp=temp->next;
    }
    if(!strcmp(sec->name,str)){
        prev->next=temp->next;
        free(temp);
        printf("\n\n\t\t\t\t\t\t\t\t\t\tpatient appointment has been completed!\n");
    }
    else if(sec!=temp){
    	printf("\n\n\t\t\t\t\t\t\t\t\t\tThis patient is not next in appointment list");
	}

}

//function to display all the feedback given by patient
void review_display(){
    FILE *f=fopen("review.dat","a+");
    int i=1;
    do
    {
        // Taking input single character at a time
        char c = fgetc(f);

        // Checking for end of file
        if (feof(f))
            break ;
        if(c=='('){
            printf("%c%d) ",c,i);
            i++;
            continue;
        }
        printf("%c", c);
    }  while(1);
    fclose(f);
}



