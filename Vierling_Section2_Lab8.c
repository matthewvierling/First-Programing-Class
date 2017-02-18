//Phonebook 3
//Matthew Vierling
//10/22/2015
//Lab #8
//section 2


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


typedef struct friend{
	char name1[30];
	char name2[30];
	char number[30];
	
}PhoneStruct;

/*prototypes*********************************/

PhoneStruct * addfriend(PhoneStruct*, int*);
PhoneStruct * deletefriend(PhoneStruct*, int*);
void showcontacts(PhoneStruct*, int*);
PhoneStruct * sortfriends(PhoneStruct *, int*);
void findafriend(PhoneStruct *, int*);
void randomfriend(PhoneStruct *, int*);
PhoneStruct * clearfriends(PhoneStruct *, int*);
void savefriends(PhoneStruct *, int *);
PhoneStruct * openphonebook(PhoneStruct *, int *);
void freeallmemory(PhoneStruct*);

/********************************************/


int main(){
	
	srand(time(NULL));
	
	int selection;
	int Friends=0;
	int *PtrFriends=&Friends;
	PhoneStruct *Phonebook=NULL;
	
	while (selection!=10){
		
		printf("*****************************\n*      Phonebook Menu       *\n*****************************");
		printf("\n* 1. Add Friend             *");
		printf("\n* 2. Delete Friend          *");
		printf("\n* 3. Show Friends           *");
		printf("\n* 4. Sort Friends(last name)*");
		printf("\n* 5. Find A Friend          *");
		printf("\n* 6. Find A Random Freind   *");
		printf("\n* 7. Delete All Friends     *");
		printf("\n* 8. Save Contacts          *");
		printf("\n* 9. Open Saved Phonebook   *");
		printf("\n* 10. Exit                  *\n*****************************");
		printf("\n\n Total Friends: %d", Friends);
		printf("\n\n What do you want to do? ");
		scanf("%d", &selection);
		
		system ("cls");
		
		switch (selection){
			
			case 1:
				Phonebook=addfriend(Phonebook, PtrFriends);
				break;
				
			case 2:
				Phonebook=deletefriend(Phonebook, PtrFriends);
				break;
				
			case 3:
				showcontacts(Phonebook, PtrFriends);
				break;
				
			case 4:
				Phonebook=sortfriends(Phonebook, PtrFriends);
				break;
				
			case 5:
				findafriend(Phonebook, PtrFriends);
				break;
				
			case 6:
				randomfriend(Phonebook, PtrFriends);
				break;
				
			case 7:
				Phonebook=clearfriends(Phonebook, PtrFriends);
				break;
				
			case 8:
				savefriends(Phonebook, PtrFriends);
				break;
				
			case 9:
				Phonebook=openphonebook(Phonebook, PtrFriends);
				break;
				
			case 10:
				printf("\n Goodbye!");
				freeallmemory(Phonebook);
				break;
				
			default:
				printf(" Something went wrong :(");
				selection=0;
				break;
						
		}//switch
	}//while loop
	
	return 0;
	
}//main

/***************************function definitions********************************************************************/


PhoneStruct * addfriend (PhoneStruct *Contacts, int *Fnumber){ 

	*Fnumber=*Fnumber+1;

	Contacts=(PhoneStruct *)realloc(Contacts, ((*Fnumber)*(sizeof(PhoneStruct))));
	
	if (Contacts==NULL){
		printf("\n Out of memory");
		return 0;
	}

	printf("**************\n* Add Friend *\n**************\n");
	
	printf("\n Fist name: ");
	scanf("%s", Contacts[*Fnumber-1].name1);
	printf("\n Last name: ");
	scanf("%s", Contacts[*Fnumber-1].name2);
	printf("\n %s %s's phone number (XXX-XXX-XXXX): ", Contacts[*Fnumber-1].name1, Contacts[*Fnumber-1].name2);
	scanf("%s", Contacts[*Fnumber-1].number);
	
	system("pause");
	system("cls");
	
	return Contacts;
	
}//**********************************************************************************************************addfrind 1

PhoneStruct * deletefriend (PhoneStruct *Book, int *Nfriends){
	
	char first[30];
	char last[30];
	int f;
	int m;
	int flag=0;
	
	printf("******************\n* deleted freind *\n******************\n");
	printf("\n The person you want to delete's first name: ");
	scanf("%s", first);
	printf("\n The person you want to delete's last name: ");
	scanf("%s", last);
	printf("\n");
	
	for (f=0;f<*Nfriends;f++){
		if(strcmp(Book[f].name1, first)==0){
			if(strcmp(Book[f].name2 , last)==0){
				flag=1;
				for (m=f;m<*Nfriends;m++){
					strcpy(Book[m].name1,Book[m+1].name1);
					strcpy(Book[m].name2,Book[m+1].name2);
					strcpy(Book[m].number,Book[m+1].number);
				}//for
			}
		}
	}//for
	
	if(flag==0){
		printf("\n You have no friends named %s %s.\n\n", first, last);
		return Book;
	}//test for contact
	
	*Nfriends=*Nfriends-1;
	
	Book=(PhoneStruct*)realloc(Book, (*Nfriends)*sizeof(PhoneStruct));
	system("pause");
	system("cls");
	
	return Book;
	
}//********************************************************************************************************* deletefriend 2

void showcontacts(PhoneStruct* ContactShow, int *Friends){  
	
	int x;
	  
	printf("****************\n* contact list *\n****************\n\n");
	
	if(*Friends>0){
	
		for (x=0;x<*Friends;x++){
			printf("%d.)\n %s %s\n %s\n\n", x+1, ContactShow[x].name1, ContactShow[x].name2, ContactShow[x].number);
		}
	}
	else {
		printf("\n\n You have no friends :(\n\n");
	}
	
	system("pause");
	system("cls");
	
}//******************************************************************************************************** show contacts 3

PhoneStruct * sortfriends(PhoneStruct *Phonebook, int *Friends){
	
	int a,b,comp;
	char tempF[25];
	char tempL[25];
	char tempN[20];
	
	if(*Friends==0){
		printf("\n You have no friends to sort.\n\n");
		system("pause");
		system("cls");
		return Phonebook;
	}
	
	for(a=0;a<*Friends;a++){
		for(b=0;b<*Friends-1;b++){
			comp=strcmp(Phonebook[b].name2,Phonebook[b+1].name2);
			
			if(comp>0){
				strcpy(tempF, Phonebook[b+1].name1);
				strcpy(tempL, Phonebook[b+1].name2);
				strcpy(tempN, Phonebook[b+1].number);
				strcpy(Phonebook[b+1].name1, Phonebook[b].name1);
				strcpy(Phonebook[b+1].name2, Phonebook[b].name2);
				strcpy(Phonebook[b+1].number, Phonebook[b].number);
				strcpy(Phonebook[b].name1, tempF);
				strcpy(Phonebook[b].name2, tempL);
				strcpy(Phonebook[b].number, tempN);
			}
		}//for
	}//for   >>sorts frinds' last name
	
	printf("******************\n* Sorted frineds *\n******************\n\n");
	
	for (a=0;a<*Friends;a++){
		printf("%d.)\n %s %s\n %s\n", a+1, Phonebook[a].name1, Phonebook[a].name2, Phonebook[a].number);
	}//displays sorted friends
	
	printf("\n** This Is Permanent. **\n\n");
	
	system("pause");
	system("cls");
	
	return Phonebook;
	
}//************************************************************************************************************ sort friends 4

void findafriend(PhoneStruct *Phonebook, int *Friends){
	
	printf("*****************\n* Find A Friend *\n*****************\n\n");
	
	char fname[30];
	char lname[30];
	int x;
	int flag=0;
	
	if(*Friends==0){
		printf("\n You have no friends :(\n\n");
		system("pause");
		system("cls");
		return;
	}

	printf("\nWho do you want to find?");
	printf("\n First name: ");
	scanf("%s", fname);
	printf("\n Last name: ");
	scanf("%s", lname);

	for(x=0;x<*Friends;x++){
		if(strcmp(Phonebook[x].name1, fname)==0){
			if(strcmp(Phonebook[x].name2, lname)==0){
				printf("\n Friend has been found.\n");
				printf("\n %s %s's number is %s\n\n", Phonebook[x].name1, Phonebook[x].name2, Phonebook[x].number);
				flag=1;
			}
		}
	}//for
	
	if(flag==0){
		printf("\n You have no friends named %s %s.\n\n", fname, lname);
	}//test for contact
	
	system("pause");
	system("cls");
	
}//********************************************************************************************************* find a friend 5

void randomfriend(PhoneStruct *Phonebook, int *Friends){
	
	printf("*****************\n* Random Friend *\n*****************\n");
			
	if(*Friends>0){
		int x=(rand()%*Friends);
		printf("\n%s %s\n %s\n\n", Phonebook[x].name1, Phonebook[x].name2, Phonebook[x].number);
	}
	else{
		printf("\n\n You have no friends to call :(\n\n");
	}
	
	system("pause");
	system("cls");
	
}//********************************************************************************************************* random friend 6

PhoneStruct * clearfriends(PhoneStruct *Phonebook, int *Frinds){
	
	*Frinds=0;
	free(Phonebook);
	PhoneStruct *Phonebookn=NULL;
	
	printf("\n All frieds are now deleted.\n\n");
	
	system("pause");
	system("cls");
	
	return Phonebookn;
	
}//***************************************************************************************************** clear all friends 7

void savefriends(PhoneStruct *Phonebook, int *Friends){
	
	FILE *fileS;
	char filename[100];
	int s,selection;
	
	printf("***************\n*  Save File  *\n***************\n");
	printf("\n How do you want to save your file?");
	printf("\n 1. Default name/location.\n 2. Enter your own name/location.");
	printf("\n\n Enter choice here: ");
	scanf("%d", &selection);
	
	switch (selection){//gets name for file
		
		case 1:
			strcpy(filename, "phonebook.dat");
			break;
			
		case 2:
			printf("\n Enter the name/location of the file (only one \"\\\" is needed).\n ");
			scanf("%s", filename);
			
			int x,y;
			
			for(x=0;x<=100;x++){
		
				if(filename[x]=='\\'){
			
					for(y=100;y>x;y--){
						filename[y+1]=filename[y];
					}
				filename[x+1]='\\';
				x++;
				}
			}//for loop- takes "\" and makes them "\\"
			printf("\n%s", filename);
			break;
			
		default:
			printf("\n Wrong selection. file could not save. please try again.\n\n");
			system("pause");
			system("cls");
			return;
	}//end of switch on how to save
	
	fileS=fopen(filename, "w");
	
	if (fileS==NULL){
		printf("\n File could not open or save\n\n");
		system("pause");
		system("cls");
		return;
	}
	
	fprintf(fileS, "%d\n", *Friends);
	
	for(s=0;s<*Friends;s++){
		fprintf(fileS, "%s %s %s\n", Phonebook[s].name1, Phonebook[s].name2, Phonebook[s].number);
	}
	
	fclose(fileS);
	
	printf("\n Friends Saved\n\n");
	
	system("pause");
	system("cls");
	
	return;
	
}//************************************************************************************************************save friends 8

PhoneStruct *openphonebook(PhoneStruct *Phonebook, int *Friends){

	FILE *fileO;
	int count=0;
	int fr=*Friends;
	char filename[100];
	int selection;
	
	printf("***************\n*  Open File  *\n***************\n");
	printf("\n What do you want to open?");
	printf("\n 1. Default file.");
	printf("\n 2. Enter name/location of file.");
	printf("\n\n Enter selection here: ");
	scanf("%d", &selection);
	
	switch (selection){//gets name for file
		
		case 1:
			strcpy(filename, "phonebook.dat");
			break;
			
		case 2:
			printf("\n Enter the name/location of the file (only one \"\\\" is needed).\n ");
			scanf("%s", filename);
			
			int x,y;
			
			for(x=0;x<=100;x++){
		
				if(filename[x]=='\\'){
			
					for(y=100;y>x;y--){
						filename[y+1]=filename[y];
					}
				filename[x+1]='\\';
				x++;
				}
			}//for loop- takes "\" and makes them "\\"
			printf("\n%s", filename);
			break;
			
		default:
			printf(" Wrong selection. File could not open. Please try again.\n\n");
			system("pause");
			system("cls");
			return Phonebook;
	}//end switch for open option
	
	fileO=fopen(filename, "r");
	
	if (fileO==NULL){
		printf("\n Failed to open file :(\n\n");
		system("pause");
		system("cls");
		return Phonebook;
	}
	
	fscanf(fileO, "%d", &fr);
	
	*Friends=fr;
	
	Phonebook=(PhoneStruct *)realloc(Phonebook, ((*Friends)*(sizeof(PhoneStruct))));
	
	
	while(!feof(fileO)){
		fscanf(fileO, "%s %s %s\n", Phonebook[count].name1, Phonebook[count].name2, Phonebook[count].number);
		count++;
	}
	
	fclose(fileO);
	printf("\n File has been open and data has been loaded into your phonebook.\n\n");

	system("pause");
	system("cls");	
	
	return Phonebook;
	
}//**********************************************************************************************************open phonebook 9

void freeallmemory(PhoneStruct* Phonebook){
	
	free(Phonebook);
	
}//***************************************************************************************** free the memory before exiting 10

