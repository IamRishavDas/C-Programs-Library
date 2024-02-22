#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 10



void new_account();
void account();
void account_verification(char [], char []);
void verified_login(char []);
void new_password_verification(char [], char [], char[]);
void enter_password();
void login_activity();

int main()
{
    int choice;

    printf("\nPress 1 for Log in press 0 for create a new account: ");
    scanf("%d",&choice);
	
	if(choice==1)
		account();
	else if(choice==0)
		new_account();
	else
		puts("invalid choice!!!");

    return 0;
}
void new_account()
{
   char name[max],sir_name[max];
  
   system("cls");
   printf("\n Enter your name: ");
   scanf("%s",name);
   printf("\n Enter your sir name: ");
   scanf("%s",sir_name);
   enter_password(name);
    

}
void enter_password(char user_id[])
{
	char new_password[max], confirm_password[max];
	printf("\n enter new password: ");
    scanf("%s",new_password);
    printf("\n confirm password: ");
    scanf("%s",confirm_password);
    new_password_verification(new_password,confirm_password,user_id);
}
void new_password_verification(char new_password[], char confirm_password[], char user_id[])
{
	int check_password;
	check_password=strcmp(new_password,confirm_password);
	if(check_password!=0)
	{
		printf("\n password confirmation is not correct!!!");
		sleep(5);
		system("cls");
		printf("\n Again ");
		enter_password(user_id);	
	}
	else
	{
		verified_login(user_id);
	}	
}
void account()
{

	system("cls");
    char user_id[max];
	char password[max];
    
	printf("Enter User id: ");
    scanf("%s",user_id);
    printf("Enter password: ");
    scanf("%s",password);
    
    account_verification(user_id,password);
    
    
}
void account_verification(char user_id[], char password[])
{
	int check_user_id, check_password;
	check_user_id=strcmp(user_id,"iamrishavdas");
	if(check_user_id==0)
	{
		check_password=strcmp(password,"stayaway");
		if(check_password==0)
		{
			verified_login(user_id);
		}
		else
		{
			printf("\n you have entered a wrong password!!!");
			sleep(5);
			account();
		}
	}
	else
	{
		printf("\n you have entered wrong user id!!!");
		sleep(5);
		account();
	}
}
void verified_login(char user_id[])
{
	system("cls");
	printf("\n Successfully loged in :) ");
	printf("\n welcome %s :)",user_id);
	sleep(5);
	login_activity();
	
}
void login_activity()
{
	int choice;
	char c;
	
	do
	{
		printf("\n press 1 for open notepad: ");
		printf("\n press 2 for get ip addess: ");
		printf("\n press 3 for shutdown the computer: ");
		printf("\n press 4 for make a directory: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: system("notepad");
					break;
			case 2:	system("ipconfig");
					break;
			case 3:	system("SHUTDOWN -S");
					system("pause");
					break;
			case 4:	system("mkdir");
					break;
			default: printf("\n wrong choice!!!");
		}
		printf("\n do you want to choose another option(y/n): ");
		fflush(stdin);
		scanf("%c",&c);
	}while(c=='y'||c=='Y');
	
}
