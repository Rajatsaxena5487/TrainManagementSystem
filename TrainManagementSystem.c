#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>





//Structure
struct train
{
int train_no;
char train_name[35];
char train_arrival_time[20];
char train_departure_time[20];
char source[35];
char destination[35];
char stop_time[20];
int to_bareilly;
char from_bareilly[20];
};



//Methods
void start();
void menu();
void add_train_detail();
void train_details();
void search_train();
void delete_train_record();
void modify_train_record();
struct train t;



//Main Function
int main()
{
system("color 3f");
	start();
	return 0;
}



//Start Function
void start()
{
	menu();
}



//Menu Fuction
void menu()

{

	
	system("cls");
	printf("\n\t\t\t\t\t\t\t*****WELCOME TO Indian Railway****\r");
	printf("\n\n\t\t\t\t\t\t\t      **Train Management System**");
	printf("\n\n\n\t--------------- MENU-------------\t\t\n\n");
	printf("\t1.Add Train Detail \t\t\t2.Show Trains\t \t\t\t3.Exit \n\n\t4.Modify Train Detail \t\t\t5.Search Train\t\t\t\t6.Delete Train Record");
	switch(getch())
	{
		case '1':  add_train_detail();
 				   break;
		case '2':  printf("\n\n\n\n");
		 		   train_details();
				   break;
		case '3':  exit(0);
				   break;
		case '4':  modify_train_record();
				   break;
		
		case '5':  search_train();
				   break;
        case '6':  delete_train_record(); 
				   break;
	    default:
	    		system("cls");
				
	printf("\nEnter 1 to 6 only");
	printf("\n Enter any key");
	getch();
	menu();
}
}



void add_train_detail()
{
	system("cls");
	FILE *f;
	struct train t;
	f=fopen("TrainProject","ab+");

	printf("\n\n\t\t\t\t*******Add New Train Detail*******\n\n ");
	
	printf(" Train Number  : ");
	scanf("%d",&t.train_no);

	printf("\n  Train Name    : ");
	scanf("%s",&t.train_name);


	printf("\n  Arriaval Time : ");
	scanf("%s",&t.train_arrival_time);

	printf("\n  Departure Time: ");
	scanf("%s",&t.train_departure_time);

	printf("\n  Stop Time     : ");
	scanf("%s",&t.stop_time);

	printf("\n  Source        : ");
	scanf("%s",&t.source);

	printf("\n  Destination   : ");
	scanf("%s",&t.destination);

	printf("\n  Distance from source : ");
	scanf("%d",&t.to_bareilly);
 
 	printf("\n  Distance to Destination : ");
	scanf("%s",&t.from_bareilly);

fwrite(&t,sizeof(t),1,f); 

	printf("\n\t\t\t\t\trecord saved....!!!");

fclose(f);

	printf("\n\n\t\t\t\t\tEnter any key for menu :");

getch();
system("cls");
menu();
}




void train_details()
{
	struct train t;
	FILE *f;
    f=fopen("TrainProject","rb");

	if(f==NULL)
	{
		printf("\nNo Train Detail Found....!!!!");
		printf("Enter any Key :");
		getch();
		menu();
		}

	while(fread(&t,sizeof(t),1,f)==1)
	{
		printf("               ___________________________________________________________________________________________________________________________\n\n");
	    printf(" \t\t\t\t\t\t\t\tTrain Details : %d\n\n ",t.train_no);
	    printf("  Train_Number    Train_Name      Arrival_Time  Departure_Time  Stop_Time(min)   Source \t Destination \tDistance_From_Source   Distance_To_Destination\n\n");

  		printf("     %d\n",t.train_no);
		printf("	    	   %s\n",t.train_name);
		printf("                                      %s",t.train_arrival_time);
		printf("         %s",t.train_departure_time);
		printf("           %s",t.stop_time);
		printf("         %s\n",t.source);
		printf("\t\t\t\t\t\t\t\t\t\t\t\t  %s\n",t.destination);
		printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t        %d                    ",t.to_bareilly);	
		printf("%s\n",t.from_bareilly);
		getch();
}

fclose(f);
printf("\n Enter any key");
getch();
system("cls");
menu();
}










void search_train()
{
	int flag =0;
	FILE *f;
	int number;
	f=fopen("TrainProject","rb");
system("cls");
	if(f==NULL)
	{
		printf("\n\n\n\t Error in opening \n\n");
		exit(1);
	}
	
	printf("\n\n\n\tEnter the train number for search :");
	scanf("%d",&number);
	while(fread(&t,sizeof(t),1,f)==1)
	{
		if(number==t.train_no)
		{
			printf("               ___________________________________________________________________________________________________________________________\n\n");
			printf(" \t\t\t\t\t\t\t\tTrain Details : %d\n\n ",t.train_no);
			printf("  Train_Number    Train_Name      Arrival_Time  Departure_Time  Stop_Time(min)   Source \t Destination \tDistance_From_Source   Distance_To_Destination\n\n");
			printf("     %d\n",t.train_no);
			printf("	    	   %s\n",t.train_name);
			printf("                                      %s",t.train_arrival_time);
			printf("         %s",t.train_departure_time);
			printf("           %s",t.stop_time);
			printf("         %s\n",t.source);
			printf("\t\t\t\t\t\t\t\t\t\t\t\t  %s\n",t.destination);
			printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t        %d                    ",t.to_bareilly);
			printf("%s\n",t.from_bareilly);

			flag=1;
		}
	}
	
	if(flag==1)
	{
		printf("");
	}
	else
	{
		printf("\nTrain detail Not Found...!!!");
	}

fclose(f);
printf("\n Enter any key");
getch();
system("cls");
menu();
}
























void delete_train_record()
{
	struct train t;
	FILE *f,*ft;
	int flag;
	int number;	
	f=fopen("TrainProject","rb");
	if(f==NULL)
	{
		printf("\n\n\tTRAIN DATA NOT ADDED YET.");
	}
	else
	{
		ft=fopen("temp","wb+");
		if(ft==NULL)
		printf("\n\n\tfile opaning error");
		else
		{	
			printf("\n\n\tEnter The Train Number :");
			scanf("%d",&number);
			while(fread(&t,sizeof(t),1,f)==1)
			{
				if(number!=t.train_no)
			{
				fwrite(&t,sizeof(t),1,ft);
			}
				if(number==t.train_no)
				flag=1;
			}
			fclose(f);
			fclose(ft);
			if(flag!=1)
			{			
				printf("\n\n\tNO TRAIN RECORD TO DELETE.");
				remove("temp.txt");
			}
			else
			{
				remove("TrainProject");
				rename("temp","TrainProject");
				printf("\n\tRECORD DELETED SUCCESSFULLY.");
			}		
		}
	}	
printf("\n\n\t Enter any key");
getch();
system("cls");
menu();
}






void modify_train_record()
{
int number;
FILE *f,*ft;
int flag=0;
struct train t,s;

f=fopen("TrainProject","rb+");

if(f==NULL)
{
	printf("TRAIN DATA NOT ADDED YET.");
	exit(1);
}

else
{
	ft=fopen("temp","ab+");
		if(ft==NULL)
		{
		printf("\n\n\tfile opaning error");
	   }else
	   {
	
	system("cls");
	printf("\nEnter Train Number to Modify : ");
	scanf("%d",&number);

	while(fread(&t,sizeof(t),1,f)==1)
	{
	if(number==t.train_no)
	{
		printf(" Train Number  : ");
	scanf("%d",&s.train_no);

	printf("\n  Train Name    : ");
	scanf("%s",&s.train_name);


	printf("\n  Arriaval Time : ");
	scanf("%s",&s.train_arrival_time);

	printf("\n  Departure Time: ");
	scanf("%s",&s.train_departure_time);

	printf("\n  Stop Time     : ");
	scanf("%s",&s.stop_time);

	printf("\n  Source        : ");
	scanf("%s",&s.source);

	printf("\n  Destination   : ");
	scanf("%s",&s.destination);

	printf("\n  Distance from source : ");
	scanf("%d",&s.to_bareilly);
 
 	printf("\n  Distance to Destination : ");
	scanf("%s",&s.from_bareilly);;

    fwrite(&s,sizeof(t),1,ft); 
                
flag=1;
}
else
{
	fwrite(&t,sizeof(t),1,ft); 
}
}
fclose(f);
			fclose(ft);
}
	if(flag==1)
	{	     
           remove("TrainProject");
		   rename("temp","TrainProject");
           printf("\n Train Data modified");
}
else
{
printf(" \n Train data is not found");
}
fclose(f);
}

printf("\n Enter any key");
getch();
system("cls");
menu();
}


























