#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
void create_acc();
void acc_holder();
void transaction();
void selection();
void login();
void delay(int);
void search_record();
void design();
void delete_acc();
int main()
{
	login();
}
void delay(int d)
{
   int i,j;
   for(i=0;i<d;i++)
   {
      j=i;
   }
}
void design()
{
	for(int i=0;i<5;i++)
	{
		delay(50000000);
		printf(".");
	}
}
typedef struct login
{
	int user_id;
	char password[15];
}L;
void login()
{
	system("cls");
	int ch;
	char pass[15],con_pass[15]="BNY@123",user_id[15],con_user_id[15]="BNY";
	system("COLOR 4F");
	printf("\n\t\t\t\t\t\t\t\t\xB2\xB2\xB2  WELCOME TO THE BANK OF NEWYORK  \xB2\xB2\xB2\n\n");
	printf("\n\t\t\t\t\t\t\t\xB2\xB2\xB2       LOGIN PAGE OF THE BANK OF NEWYORK          \xB2\xB2\xB2\n\n\n");
	details:
	printf("\t\t\tEnter the user id:\t\t\t\t");fflush(stdin);
	gets(user_id);
	printf("\n\t\t\tEnter your password:\t\t\t\t");
	gets(pass);
	if((strcmp(pass,con_pass)==0)&&(strcmp(user_id,con_user_id)==0))
	{
		printf("\n\t\t\tUSER ID MATCH FOUND!!\n");
		printf("\t\t\tPASSWORD MATCH FOUND!!\n\n");
		printf("\t\t\tRedirecting you securely to the main menu");design();
		selection();
	}
	else
	{
		printf("\n\t\t\tInvalid credentials\n");
		try_again:
		printf("\n\t\t\tPLEASE CHOOSE AN OPTION FROM THE FOLLLOWING MENU:\n");
		printf("\t\t\t1)TRY AGAIN\n\t\t\t2)EXIT\n\n");
		printf("\t\t\tENTER AN OPTION FROM THE ABOVE MENU(1/2): \t");
		scanf("%d",&ch);
		system("cls");
		printf("\n\n\t\t\t\t\t\t\t\xB2\xB2\xB2       LOGIN PAGE OF THE BANK OF NEWYORK          \xB2\xB2\xB2\n\n");
		switch(ch)
		{
			case 1: goto details;
			break;
			case 2: printf("\n\t\t\tThank you for your time!!\n");
			printf("\t\t\tDo visit us again!!\n");
			exit(0);
			default: printf("\n\n\t\t\tInvalid Choice!\n");
			printf("\t\t\tKindly choose again!\n");
			goto try_again;
			break;
		}
	}
}
typedef struct date
{
	int day,month,year;
}D;
typedef struct bank_account
{
	char name[100];
	int age;
	int acc_no,temp_acc;
	char phone_no[15];
	char type_acc[16];
	char nationality[20];
	char address[100];
	D dob;
	char password[15];
	float amount;
}bank;
void create_acc()
{
	FILE *fr;
	char acc_type1[16]="Savings Account",acc_type2[16]="Current account";int ch,num,flag=0;
	bank *emp;
    fr=fopen("Bank_Record.txt","ab+");
    acc_info:
   	system("cls");
    system("COLOR 3F");
    printf("\n\t\t\t\t\t\t\t\t\xB2\xB2\xB2  WELCOME TO THE BANK OF NEWYORK  \xB2\xB2\xB2\n\n");
	printf("\n\t\t\t\t\t\t\t\xB2\xB2\xB2       RECORD CREATION PAGE OF THE BANK OF NEWYORK          \xB2\xB2\xB2\n\n");
	printf("\t\t\tEnter the number of records you want to create:\t\t\t\t\t");
	scanf("%d",&num);
	emp=(bank*)calloc(num,sizeof(bank));
	for(int i=1;i<=num;i++)
	{
	    printf("\n\t\t\tDate and time for the %dst entry:\t\t\t\t",i);
	    time_t entry_time;
        entry_time=time(&entry_time);
        printf(ctime(&entry_time));
	    printf("\n\t\t\tEnter the account number:\t\t\t\t\t");fflush(stdin);
	    scanf("%d",&emp[i].acc_no);
	    printf("\n\t\t\tEnter the name of the individual:\t\t\t\t");fflush(stdin);
        scanf("%[^\n]s",emp[i].name);
        printf("\n\t\t\tEnter the age of the individual:\t\t\t\t");fflush(stdin);
        scanf("%d",&emp[i].age);
        printf("\n\t\t\tEnter the DOB of the individual:\t\t\t\t");fflush(stdin);
        scanf("%d/%d/%d",&emp[i].dob.day,&emp[i].dob.month,&emp[i].dob.year);
        printf("\n\t\t\tEnter the address:\t\t\t\t\t\t");fflush(stdin);
        scanf("%[^\n]s",emp[i].address);
        printf("\n\t\t\tEnter the nationality :\t\t\t\t\t\t");fflush(stdin);
        scanf("%[^\n]s",emp[i].nationality);
        printf("\n\t\t\tEnter the phone number:\t\t\t\t\t\t+91");fflush(stdin);
        scanf("%[^\n]s",emp[i].phone_no);
        printf("\n\t\t\tEnter the amount you want to initially deposit:\t\t\tRs.");fflush(stdin);
        scanf("%f",&emp[i].amount);
        acc_create:
        printf("\n\n\t\t\tSelect the account type for the individual:\n");
        printf("\t\t\t1)SAVINGS ACCOUNT\n\t\t\t2)CURRENT ACCOUNT\n\n");
        printf("\t\t\tEnter your choice:(1/2):\t");fflush(stdin);
		scanf("%d",&ch);
        switch(ch)
		{
		    case 1:printf("\n\t\t\t%s\n",acc_type1);strcpy(emp[i].type_acc,acc_type1);
			break;
        	case 2:printf("\n\t\t\t%s\n",acc_type2);strcpy(emp[i].type_acc,acc_type2);
       	    break;
        	default: printf("\n\n\t\t\tInvalid Choice!\n");
        	printf("\t\t\tKindly choose again!\n\n");
        	printf("\t\t\tRedirecting to the menu in the create account page");design();
		    goto acc_create;
		    break;
    	}
    	fwrite(&emp[i],sizeof(bank),1,fr);
    	printf("\n\t\t\tAccount creation successful!!\n");
		fclose(fr);
	}
	choice:
	printf("\n\t\t\tPLEASE CHOOSE AN OPTION FROM THE FOLLLOWING MENU:\n");
	printf("\t\t\t1)CREATE ACCOUNT\n\t\t\t2)MAIN MENU\n\t\t\t3)EXIT\n\n");
	printf("\t\t\tENTER AN OPTION FROM THE ABOVE MENU(1/2):\t");fflush(stdin);
	scanf("%d",&ch);
	system("cls");
	printf("\n\t\t\t\t\t\t\t\xB2\xB2\xB2       CREATE ACCOUNT PAGE OF THE BANK OF NEWYORK          \xB2\xB2\xB2\n\n");
	switch(ch)
	{
		case 1: printf("\n\t\t\tRedirecting you securely to the create account page");design();
		create_acc();
		break;
		case 2:printf("\n\t\t\tRedirecting you securely to the main menu");design();
		selection();
		break;
		case 3: printf("\n\t\t\tThank you for your time!!\nDo visit us again!!\n");
		exit(0);
		default: printf("\n\n\t\t\tInvalid Choice!\n");
        printf("\t\t\tKindly choose again!\n\n");
        printf("\t\t\tRedirecting to the menu in the create account page");design();
		goto choice;
		break;
	}
}
void acc_holder()
{
	FILE *hld;
	bank emp;
	hld=fopen("Bank_Record.txt","rb+");
	int choice;
	char ch;
	int flag=0;
	system("cls");
	system("COLOR 5F");
	printf("\n\t\t\t\t\t\t\t\t\xB2\xB2\xB2  WELCOME TO THE BANK OF NEWYORK  \xB2\xB2\xB2\n\n");
	printf("\n\t\t\t\t\t\t\t\xB2\xB2\xB2       ALL ACCOUNT HOLDERS PAGE OF THE BANK OF NEWYORK          \xB2\xB2\xB2\n\n");
	printf("\n\t\t\tAccount_Number\t\tName\t\tAddress\t\t\t\tAccount Type\t\tPhone_No.\tAccount Balance\n");
	while(fread(&emp,sizeof(bank),1,hld))
	{
		flag=1;
		printf("\n\t\t\t%d\t\t\t%s\t\t%s\t%s\t\t%s\t%f\n",emp.acc_no,emp.name,emp.address,emp.type_acc,emp.phone_no,emp.amount);
	}
	if(flag!=1)
	{
	    printf("\n\t\t\tThe records do not exist\n");
	    goto choice;
    }
    else
    {
        choice:
    	printf("\n\n\t\t\tPLEASE CHOOSE AN OPTION FROM THE FOLLLOWING MENU:\n");
    	printf("\t\t\t1)MAIN MENU\n\t\t\t2)EXIT\n\n");
    	printf("\t\t\tENTER AN OPTION FROM THE ABOVE MENU(1/2):\t");
	    scanf("%d",&ch);
		system("cls");
		printf("\n\n\t\t\t\t\t\t\t\xB2\xB2\xB2       ALL ACCOUNT HOLDERS PAGE OF THE BANK OF NEWYORK          \xB2\xB2\xB2\n\n");
	    switch(ch)
		{
			case 1: printf("\n\t\t\tRedirecting you securely to the main menu");design();
		    selection();
	     	case 2: printf("\n\t\t\tThank you for your time!!\n\t\t\tDo visit us again!!\n");
		    exit(0);
		    default: printf("\n\n\t\t\tInvalid Choice!\n");
            printf("\t\t\tKindly choose again!\n\n");
            printf("\t\t\tRedirecting to the menu in the account holders page page");design();
		    goto choice;
		    break;
		}
	}
	fclose(hld);
}   
void bank_functions()
{
	system("cls");
	system("COLOR 09");
	bank emp;
	int acc_num;
	float amt;
    int flag=0,ch;
	FILE *rec1,*rec2;
	rec1=fopen("Bank_Record.txt","rb+");
	rec2=fopen("Record.txt","wb+");
	printf("\n\t\t\t\t\t\t\t\t\xB2\xB2\xB2  WELCOME TO THE BANK OF NEWYORK  \xB2\xB2\xB2\n\n");
	printf("\n\t\t\t\t\t\t\t\xB2\xB2\xB2       TRANSACTION PAGE OF THE BANK OF NEWYORK          \xB2\xB2\xB2\n\n");
	printf("\n\t\t\tEnter the account number of the individual:\t\t\t");fflush(stdin);
	scanf("%d",&acc_num);
	while(fread(&emp,sizeof(bank),1,rec1))
	{
		if(acc_num==emp.acc_no)
		{	printf("\n\t\t\tPLEASE CHOOSE AN OPTION FROM THE FOLLLOWING MENU:\n");
		    printf("\t\t\t1)DEPOSIT\n\t\t\t2)WITHDRAW\n\n");
		    printf("\t\t\tENTER AN OPTION FROM THE ABOVE MENU(1/2):\t\t\t");
	     	scanf("%d",&ch);
			flag=1;
			if(ch==1)
			{
				printf("\n\n\t\t\tEnter the amount you to deposit:\t\t\t\tRs.");
				scanf("%f",&amt);
				emp.amount=emp.amount+amt;
				printf("\n\t\t\tAmount deposited successfully!!\n\n\t\t\tRecord updated as follows: \n");
		    	printf("\n\t\t\tAccount_Number\t\tName\t\tAddress\t\t\t\tAccount Type\t\tPhone_No.\tAccount Balance\n");
				printf("\n\t\t\t%d\t\t\t%s\t\t%s\t%s\t\t%s\t%f\n",emp.acc_no,emp.name,emp.address,emp.type_acc,emp.phone_no,emp.amount);
				fwrite(&emp,sizeof(bank),1,rec2);
			}
			else if(ch==2)
			{
				printf("\n\n\t\t\tEnter the amount you to withdraw:\t\t\t\tRs.");
				scanf("%f",&amt);
				if(amt<emp.amount)
				{
				emp.amount=emp.amount-amt;
				printf("\n\t\t\tAmount withdrawn successfully!!\n\n\t\t\tRecord updated as follows:\n");
				printf("\n\t\t\tAccount_Number\t\tName\t\tAddress\t\t\t\tAccount Type\t\tPhone_No.\tAccount Balance\n");
				printf("\n\t\t\t%d\t\t\t%s\t\t%s\t%s\t\t%s\t%f\n",emp.acc_no,emp.name,emp.address,emp.type_acc,emp.phone_no,emp.amount);
		        fwrite(&emp,sizeof(bank),1,rec2);
		        }
		        else
		        {
		        	printf("\n\n\t\t\tThe amount entered is greater than the current account balance which is: (Rs.%f)\n\n",emp.amount );
		        	printf("\t\t\tRedirecting you securely to the menu in the transaction page");design();
		        	goto choice;
				}
		    }
			else
			{
				printf("\n\t\t\tNo transaction takes place\n\n\t\t\tCurrent record is as follows:\n");
				printf("\n\t\t\tAccount_Number\t\tName\t\tAddress\t\t\t\tAccount Type\t\tPhone_No.\tAccount Balance\n");
				printf("\n\t\t\t%d\t\t\t%s\t\t%s\t%s\t\t%s\t%f\n",emp.acc_no,emp.name,emp.address,emp.type_acc,emp.phone_no,emp.amount);
		        fwrite(&emp,sizeof(bank),1,rec2);
			}		
	    }
	    else
	    {
		    fwrite(&emp,sizeof(bank),1,rec2);
	    }
    }
	fclose(rec1);
    fclose(rec2);
    if(flag==1)
    {
    	rec1=fopen("Bank_Record.txt","wb+");
	    rec2=fopen("Record.txt","rb+");
    	while(fread(&emp,sizeof(bank),1,rec2))
		{
			fwrite(&emp,sizeof(bank),1,rec1);
		}
		fclose(rec1);
		fclose(rec2);
		choice:
        printf("\n\t\t\tPLEASE CHOOSE AN OPTION FROM THE FOLLLOWING MENU:\n");
        printf("\t\t\t1)TRANSACTIONS\n\t\t\t2)MAIN MENU\n\t\t\t3)EXIT\n\n");
        printf("\t\t\tENTER AN OPTION FROM THE ABOVE MENU(1/2):\t");
        scanf("%d",&ch);
	    system("cls");
	    printf("\n\n\t\t\t\t\t\t\t\xB2\xB2\xB2       TRANSACTION PAGE OF THE BANK OF NEWYORK          \xB2\xB2\xB2\n\n");
        switch(ch)
	    {
        case 1: printf("\n\t\t\tRedirecting you securely to the transaction page");design();
        bank_functions();
       	break;
       	case 2: printf("\n\t\t\tRedirecting you securely to the main menu page");design();
       	selection();
		break;
		case 3: printf("\n\t\t\tThank you for your time!!\n\t\t\tDo visit us again!!\n");
		exit(0);
		default: printf("\n\n\t\t\tInvalid Choice!\n");
        printf("\t\t\tKindly choose again!\n\n");
        printf("\t\t\tRedirecting to the menu in the create account page");design();
		goto choice;
		break;
	    }
	}
    else
	{ 
       printf("\n\n\t\t\tThe record does not exist!!\n");
       goto choice;
    }
}
void search_record()
{
	system("cls");
	system("COLOR 9");
	bank emp;
	int acc_no;int flag=0,ch;
	FILE *fp;
	fp=fopen("Bank_Record.txt","rb+");
	printf("\n\t\t\t\t\t\t\t\t\xB2\xB2\xB2  WELCOME TO THE BANK OF NEWYORK  \xB2\xB2\xB2\n\n");
	printf("\n\t\t\t\t\t\t\t\xB2\xB2\xB2       SEARCH RECORD PAGE OF THE BANK OF NEWYORK          \xB2\xB2\xB2\n\n");
	printf("\n\t\t\tEnter the account number you're searching for:\t\t\t");
	scanf("%d",&acc_no);
	while(fread(&emp,sizeof(bank),1,fp))
	{
	    if(acc_no==emp.acc_no)
	    {
	    	flag=1;
	    	printf("\n\n\t\t\tAccount number found!!\n\n\n");
	   		printf("\t\t\tFollowing is the record:\n");
	   		printf("\n\t\t\tAccount_Number\t\tName\t\tAddress\t\t\t\tAccount Type\t\tPhone_No.\tAccount Balance\n");
	   		printf("\n\t\t\t%d\t\t\t%s\t\t%s\t%s\t\t%s\t%f\n",emp.acc_no,emp.name,emp.address,emp.type_acc,emp.phone_no,emp.amount);
			}
		}
	if(flag!=1)
	{ 
       printf("\n\n\t\t\tThe record does not exist!!\n");
       goto choice;
    }
    else
    {
       choice:
       printf("\n\t\t\tPLEASE CHOOSE AN OPTION FROM THE FOLLLOWING MENU:\n");
       printf("\n\t\t\t1)SEARCH RECORD\n\t\t\t2)MAIN MENU\n\t\t\t3)EXIT\n\n");
       printf("\t\t\tENTER AN OPTION FROM THE ABOVE MENU(1/2):\t");
       scanf("%d",&ch);
	   system("cls");
	   printf("\n\n\t\t\t\t\t\t\t\xB2\xB2\xB2       SEARCH RECORD PAGE OF THE BANK OF NEWYORK          \xB2\xB2\xB2\n\n");
       switch(ch)
	   {
        case 1: printf("\n\t\t\tRedirecting you securely to the search record page");
		design();
        search_record();
       	break;
       	case 2: printf("\n\t\t\tRedirecting you securely to the main menu page");design();
       	selection();
		break;
		case 3: printf("\n\t\t\tThank you for your time!!\n\t\t\tDo visit us again!!\n");
		exit(0);
		default: printf("\n\n\t\t\tInvalid Choice!\n");
        printf("\t\t\tKindly choose again!\n\n");
        printf("\t\t\tRedirecting to the menu in the transaction page");design();
		goto choice;
		break;
	   }
    }
    fclose(fp);
}
void delete_acc()
{
	system("cls");
	system("COLOR 7D");
	int accno;
	int flag=0,ch;
	bank emp;
	FILE *fp,*fr;
	fp=fopen("Bank_Record.txt","rb+");
	fr=fopen("Deleted.txt","wb+");
	printf("\n\t\t\t\t\t\t\t\t\xB2\xB2\xB2  WELCOME TO THE BANK OF NEWYORK  \xB2\xB2\xB2\n\n");
	printf("\n\t\t\t\t\t\t\t\xB2\xB2\xB2       DELETE RECORD PAGE OF THE BANK OF NEWYORK          \xB2\xB2\xB2\n\n");
	printf("\t\t\tEnter the account number you want to delete:\t\t\t");
	scanf("%d",&accno);
	while(fread(&emp,sizeof(bank),1,fp))
	{
		if(accno==emp.acc_no)
		{
			flag=1;
			printf("\n\t\t\tAccount number match found!!\n\n");
		}
		else
		{
			fwrite(&emp,sizeof(bank),1,fr);
		}
	}
	fclose(fp);
	fclose(fr);
	if(flag==1)
	{
		fp=fopen("Bank_Record.txt","wb+");
		fr=fopen("Deleted.txt","rb+");
		while(fread(&emp,sizeof(bank),1,fr))
		{
			fwrite(&emp,sizeof(bank),1,fp);
		}
		fclose(fp);
		fclose(fr);
		printf("\n\t\t\tAccount number was deleted successfully!!\n\n");
		choice:
        printf("\n\t\t\tPLEASE CHOOSE AN OPTION FROM THE FOLLLOWING MENU:\n");
        printf("\n\t\t\t1)DELETE RECORD\n\t\t\t2)MAIN MENU\n\t\t\t3)EXIT\n\n");
        printf("\t\t\tENTER AN OPTION FROM THE ABOVE MENU(1/2):\t");
        scanf("%d",&ch);
	    system("cls");
	    printf("\n\n\t\t\t\t\t\t\t\xB2\xB2\xB2       DELETE RECORD PAGE OF THE BANK OF NEWYORK          \xB2\xB2\xB2\n\n");
        switch(ch)
	    {
            case 1: printf("\n\t\t\tRedirecting you securely to the delete record page");
	    	design();
            delete_acc();
        	break;
        	case 2: printf("\n\t\t\tRedirecting you securely to the main menu page");design();
        	selection();
	    	break;
		    case 3: printf("\n\t\t\tThank you for your time!!\n\t\t\tDo visit us again!!\n");
	    	exit(0);
	    	default: printf("\n\n\t\t\tInvalid Choice!\n");
            printf("\t\t\tKindly choose again!\n\n");
            printf("\t\t\tRedirecting to the menu in the delete record page");design();
		    goto choice;
		    break;
	    }
	}
	else
	{
		printf("\n\t\t\tThe record does not exist!!\n\n");
		goto choice;
	}
}
void selection()
{
	system("cls");
	system("COLOR 1F");
	int ch;
	printf("\n\t\t\t\t\t\t\t\t\xB2\xB2\xB2  WELCOME TO THE BANK OF NEWYORK  \xB2\xB2\xB2\n\n");
	printf("\n\t\t\t\t\t\t\t\xB2\xB2\xB2       MAIN MENU PAGE OF THE BANK OF NEWYORK          \xB2\xB2\xB2\n\n");
	printf("\t\t\tPLEASE SELECT FROM THE FOLLOWING FROM THE FOLLOWING:\n\n");
	printf("\t\t\t1)CREATING AN ACCOUNT\n\t\t\t2)ALL ACCOUNT HOLDER LIST\n\t\t\t3)TRANSACTIONS\n\t\t\t4)SEARCH RECORD\n\t\t\t5)DELETE RECORD\n\n");
	printf("\t\t\tEnter your choice: \t\t\t\t");
	scanf("%d",&ch);
	switch(ch)
	{
	   case 1: printf("\n\n\t\t\tRedirecting you securely to the create account page");
	        design();create_acc();
		    break;
		case 2: printf("\n\n\t\t\tRedirecting you securely to the account holders page");
		    design();acc_holder();
	     	break;
		case 3:printf("\n\n\t\t\tRedirecting you securely to the transactions page");
		    design();bank_functions();
	    	break;
	    case 4:printf("\n\n\t\t\tRedirecting you securely to the search record page");
		    design();search_record();
	    	break;
	    case 5:printf("\n\n\t\t\tRedirecting you securely to the delete record page");
	    design();delete_acc();
		default: printf("\n\n\t\t\tInvalid Choice!\n");
        printf("\t\t\tKindly choose again!\n\n");
        printf("\t\t\tRedirecting you securely to the main menu");
		design(); selection();
	    break;
	}
}
