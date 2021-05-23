//This is a Telecom billing project//
/*Created by Rachit Agrawal */
/*Palak Talwar */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<graphics.h>
struct account//defining structure
{
   char phonenumber[200];
   int accountno;
   float ammount;
   char mothername[200];
   char name[200];
   int pincode;
   char Fathername[200];
};
char op;//for taking operation
int main()
{
   int gd=DETECT,gm;
   initgraph(&gd,&gm,NULL);
   setcolor(5);
   settextstyle(4,0,6);
   outtextxy(100,100,"Welcome");
   setcolor(3);
   settextstyle(3,0,3);
   outtextxy(200,80,"Telecom billing project");
   delay(2500);
   closegraph();
   struct account *p;//declaring pointer variable
   int i,t,n,s,u,q,r,v,w,b,y,a,B,A,Y,U;
   n=0;
   system("color D0");
   printf("***********************************************************************************************************************\n");
   printf("                                Welcome to Telecom billing project                                                    \n");
   printf("***********************************************************************************************************************\n");
   printf("please enter the choice\n");
   printf("A:      For adding new records.\n");
   printf("L:      For list of record\n");
   printf("S:      To search a record\n");
   printf("M:      To change account detail\n");
   printf("P:      For payment\n");
   printf("D:      To delete a account\n");
   printf("E:      For exit\n");
   for(t=0;op!='E';i++)
   {
      printf("Enter any one of the operation(A,M,D,L,E,P,S)\t");

      scanf("%c",&op);
      system("CLS");
      fflush(stdin);
      if(op=='A')//for adding account
      {
         system("color 50");
         printf("no of records do you want to add?\t");
         scanf("%d",&n);
         p=(struct account*)malloc(n*sizeof(struct account));
         for(i=0;i<n;i++)
         {
            printf("---------------------------------------------\n");
            printf("Enter the details of account %d\n",i+1);
            printf("phone number---------\t");
            scanf("%*c%[^\n]s",(*(p+i)).phonenumber);
            printf("name-----\t");
            scanf("%*c%[^\n]s",(*(p+i)).name);
            printf("pincode----\t");
            scanf("%d",&(*(p+i)).pincode);
            printf("Father's name----\t");
            scanf("%*c%[^\n]s",(*(p+i)).Fathername);
            printf("mother's name-----\t");
            scanf("%*c%[^\n]s",(*(p+i)).mothername);
            printf("ammount----\t");
            scanf("%f",&(*(p+i)).ammount);
            (*(p+i)).accountno = i+1;
            printf("\t account number == %d\n",(*(p+i)).accountno);
            printf("----------------------------------------------\n");
            fflush(stdin);
         }
         FILE *ptr1;
         ptr1 = fopen("Listofrec.txt","w");
         if(ptr1==NULL)
         {
             printf("we are unable to save account permanently\n");
             delay(1000);
         }
         else
         {
               fprintf(ptr1,"Details of accounts that are saved in the system\n");
               fprintf(ptr1,"-------------------------------------------------------------------------------\n");
               for(i=0;i<n;i++)
               {
                  fprintf(ptr1,"-------------------------------------\n");
                  fprintf(ptr1,"|ACCOUNTNUMBER  %20d|\n",(*(p+i)).accountno);
                  fprintf(ptr1,"|-----------------------------------|\n");
                  fprintf(ptr1,"|PHONENUMBER    %20s|\n",(*(p+i)).phonenumber);
                  fprintf(ptr1,"|-----------------------------------|\n");
                  fprintf(ptr1,"|NAME  %29s|\n",(*(p+i)).name);
                  fprintf(ptr1,"|-----------------------------------|\n");
                  fprintf(ptr1,"|FATHER'S NAME %21s|\n",(*(p+i)).Fathername);
                  fprintf(ptr1,"|-----------------------------------|\n");
                  fprintf(ptr1,"|MOTHER'S NAME %21s|\n",(*(p+i)).mothername);
                  fprintf(ptr1,"|-----------------------------------|\n");
                  fprintf(ptr1,"|Pincode  %26d|\n",(*(p+i)).pincode);
                  fprintf(ptr1,"|-----------------------------------|\n");
                  fprintf(ptr1,"|AMMOUNT  %26.2f|\n",(*(p+i)).ammount);
                  fprintf(ptr1,"-------------------------------------\n");
               }
               fprintf(ptr1,"--------------------------------------------------------------------------------\n");
               fclose(ptr1);
         }

      }
      else
      {
         if(op=='L')//for listing accounts
         {
            system("color DF");
            if(n==0)
            {
               printf("--------------------------OOPS! NO RECORD-------------------------------------\n");
            }
            else
            {
               printf("Details of accounts that are saved in the system\n");
               printf("-------------------------------------------------------------------------------\n");
               for(i=0;i<n;i++)
               {
                  printf("-------------------------------------\n");
                  printf("|ACCOUNTNUMBER  %20d|\n",(*(p+i)).accountno);
                  printf("|-----------------------------------|\n");
                  printf("|PHONENUMBER    %20s|\n",(*(p+i)).phonenumber);
                  printf("|-----------------------------------|\n");
                  printf("|NAME  %29s|\n",(*(p+i)).name);
                  printf("|-----------------------------------|\n");
                  printf("|FATHER'S NAME %21s|\n",(*(p+i)).Fathername);
                  printf("|-----------------------------------|\n");
                  printf("|MOTHER'S NAME %21s|\n",(*(p+i)).mothername);
                  printf("|-----------------------------------|\n");
                  printf("|Pincode  %26d|\n",(*(p+i)).pincode);
                  printf("|-----------------------------------|\n");
                  printf("|AMMOUNT  %26.2f|\n",(*(p+i)).ammount);
                  printf("-------------------------------------\n");
               }
               printf("--------------------------------------------------------------------------------\n");
            }
         }

      }
      if(op=='E')//for exiting from program
      {
         system("color 4F");
         printf("******************************************THANKS FOR COMMING*****************************************************\n");
      }
      if(op=='S')//for searching a account
      {
         system("color B0");
         if(n==0)
         {
            printf("----------------------OOPS!NO RECORDS----------------\n");
            printf("------------------------\n");
         }
         else
         {
            three:
            printf("Please enter the accountnumber\n");
            printf("-------------");
            int acsearch;
            scanf("%d",&acsearch);
            fflush(stdin);
            char namesearch[20];
            for(i=0;i<n;i++)
            {
               if(acsearch==(*(p+i)).accountno)
               {
                  one:
                  printf("Please enter name of accountholder\n");
                  scanf("%[^\n]s",namesearch);
                  if(strcmp(namesearch,(*(p+i)).name)==0)
                  {
                      printf("These are all the details stored about coustmer\n");
                      printf("------------------------------------\n");
                      printf("|ACCOUNTNUMBER  %20d|\n",(*(p+i)).accountno);
                      printf("------------------------------------|\n");
                      printf("|PHONENUMBER    %20s|\n",(*(p+i)).phonenumber);
                      printf("------------------------------------|\n");
                      printf("|NAME  %29s|\n",(*(p+i)).name);
                      printf("------------------------------------|\n");
                      printf("|FATHER'S NAME %21s|\n",(*(p+i)).Fathername);
                      printf("|-----------------------------------|\n");
                      printf("|MOTHER'S NAME %21s|\n",(*(p+i)).mothername);
                      printf("|-----------------------------------|\n");
                      printf("|Pincode  %26d|\n",(*(p+i)).pincode);
                      printf("|-----------------------------------|\n");
                      printf("|AMMOUNT  %26.2f|\n",(*(p+i)).ammount);
                      printf("-------------------------------------\n");
                      fflush(stdin);
                      U = 1;
                      char download[10];
                      printf("\nEnter d if you want to save this record or any key to exit\t\t");
                      scanf("%s",download);
                      fflush(stdin);
                      if(strcmp(download,"d")==0)
                      {
                          FILE *ptr2;
                          ptr2 = fopen("searchedrecord.txt","w");
                          if(ptr2==NULL)
                          {
                              printf("Error in saving the account......\n");
                              delay(1000);
                          }
                          else
                          {
                              fprintf(ptr2,"These are all the details stored about coustmer\n");
                              fprintf(ptr2,"------------------------------------\n");
                              fprintf(ptr2,"|ACCOUNTNUMBER  %20d|\n",(*(p+i)).accountno);
                              fprintf(ptr2,"------------------------------------|\n");
                              fprintf(ptr2,"|PHONENUMBER    %20s|\n",(*(p+i)).phonenumber);
                              fprintf(ptr2,"------------------------------------|\n");
                              fprintf(ptr2,"|NAME  %29s|\n",(*(p+i)).name);
                              fprintf(ptr2,"------------------------------------|\n");
                              fprintf(ptr2,"|FATHER'S NAME %21s|\n",(*(p+i)).Fathername);
                              fprintf(ptr2,"|-----------------------------------|\n");
                              fprintf(ptr2,"|MOTHER'S NAME %21s|\n",(*(p+i)).mothername);
                              fprintf(ptr2,"|-----------------------------------|\n");
                              fprintf(ptr2,"|Pincode  %26d|\n",(*(p+i)).pincode);
                              fprintf(ptr2,"|-----------------------------------|\n");
                              fprintf(ptr2,"|AMMOUNT  %26.2f|\n",(*(p+i)).ammount);
                              fprintf(ptr2,"-------------------------------------\n");
                              fclose(ptr2);
                          }

                      }

                  }
                  else
                  {
                     printf("Wrong name\n");
                     printf("Enter 1 for searching again or any number for exit--------\t");
                     scanf("%d",&q);
                     fflush(stdin);
                     if(q==1)
                     {
                        goto one;
                     }
                     else
                        U=1;
                  }
               }
            }
            if(U!=1)
            {
               printf("-------------------Wrong account number---------------------\n");
               printf(" please Enter 1 if you want to search again or any integer for exit from searching\t");
               scanf("%d",&s);
               fflush(stdin);
               if(s==1)
               {
                  goto three;
               }
            }
         }
      }
      if(op=='M')//for modify a perticular account and first take account number and name for verification
      {
         system("color F1");
         if(n==0)
         {
            printf("----------------------------OOPS!NO RECORDS-----------------\n");
         }
         else
         {
            four:
            printf("Please enter the accountnumber of account you want to modify\n");
            int acsearch2;
            scanf("%d",&acsearch2);
            fflush(stdin);
            char namesearch2[20];
            for(i=0;i<n;i++)
            {
               if(acsearch2==(*(p+i)).accountno)
               {
                  five:
                  printf("Please enter name of accountholder\n");
                  scanf("%[^\n]s",namesearch2);
                  fflush(stdin);
                  if(strcmp(namesearch2,(*(p+i)).name)==0)
                  {
                     printf("\t\tEnter the details again\n");
                     printf("Phone number--------------------\t\t");
                     scanf("%*c%[^\n]s",(*(p+i)).phonenumber);
                     printf("name--------------------------\t\t");
                     scanf("%*c%[^\n]s",(*(p+i)).name);
                     printf("father name-----------------\t\t");
                     scanf("%*c%[^\n]s",(*(p+i)).Fathername);
                     printf("mother name--------------------------\t\t");
                     scanf("%*c%[^\n]s",(*(p+i)).mothername);
                     printf("pincode----------------\t\t");
                     scanf("%d",&(*(p+i)).pincode);
                     printf("Ammount-----------------------\t\t");
                     scanf("%f",&(*(p+i)).ammount);
                     fflush(stdin);
                     r = 1;
                  }
                  else
                  {
                     printf("------------------------------Wrong name------------------------\n");
                     printf("Enter 1 to try again or any number for exit\t");
                     scanf("%d",&v);
                     fflush(stdin);
                     if(v==1)
                     {
                        goto five;
                     }
                     else
                        r=1;
                  }
               }
            }
            if(r!=1)
            {
               printf("--------------------------------Wrong account number----------------------\n");
               printf(" please Enter 1 to again or any integer for exit\t");
               scanf("%d",&w);
               fflush(stdin);
               if(w==1)
               {
                  goto four;
               }
            }
         }
      }
      if(op=='P')//for balance of the account holder
      {
         system("color B1");
         if(n==0)
         {
            printf("------------------------------------OOPS!NO RECORDS-------------------------------\n");
         }
         else
         {
            six:
            printf("Please enter the accountnumber of account to check net payable ammount.........\t\t");
            int acsearch3;
            scanf("%d",&acsearch3);
            fflush(stdin);
            char namesearch3[20];
            for(i=0;i<n;i++)
            {
               if(acsearch3==(*(p+i)).accountno)
               {
                  seven:
                  printf("Please enter name of accountholder--------\n");
                  scanf("%[^\n]s",namesearch3);
                  fflush(stdin);
                  if(strcmp(namesearch3,(*(p+i)).name)==0)
                  {
                     printf("net ammount that this person will pay-----------------\t\t'%f'\n",(*(p+i)).ammount);
                     b=10;
                  }
                  else
                  {
                     printf("-----------------------------------------Wrong name---------------------------\n");
                     printf("Enter 0 to try again or any number for exit\t");
                     scanf("%d",&y);
                     fflush(stdin);
                     if(y==0)
                     {
                        goto seven;
                     }
                     else
                        b=10;
                  }
               }
            }
            if(b!=10)
            {
               printf("--------------------------------------------Wrong account number----------------------\n");
               printf(" please Enter 0 to try again or any integer for exit\t");
               scanf("%d",&a);
               fflush(stdin);
               if(a==0)
               {
                  goto six;
               }
            }
         }
      }
      if(op=='D')//to delete a account first verify it
      {
         system("color 74");
         if(n==0)
         {
            printf("-------------------------OOPS!NO RECORDS-------------------------------------\n");
         }
         else
         {
            Eight:
            printf("Please enter the account number of account you want to delete__________________\n");
            int acsearch4;
            scanf("%d",&acsearch4);
            fflush(stdin);
            char namesearch4[20];
            for(i=0;i<n;i++)
            {
               if(acsearch4==(*(p+i)).accountno)
               {
                  nine:
                  printf("Please enter name of accountholder_______________\n");
                  scanf("%[^\n]s",namesearch4);
                  fflush(stdin);
                  if(strcmp(namesearch4,(*(p+i)).name)==0)
                  {
                     printf("-----------All the details of this account is deleted now------------\n");
                     for(B=i;B<n-1;B++)
                     {
                        *(p+B)=*(p+B+1);
                     }
                     n=n-1;
                     B = 1;
                  }
                  else
                  {
                     printf("-----------------------Wrong name--------------------\n");
                     printf("Enter 1 to try again or any number for exit\t");
                     scanf("%d",&Y);
                     fflush(stdin);
                     if(Y==1)
                     {
                        goto nine;
                     }
                     else
                        B=1;
                  }
               }
            }
            if(B!=1)
            {
               printf("----------------------Wrong account number---------------\n");
               printf(" please Enter 1 to try again or any integer for exit\t");
               scanf("%d",&A);
               fflush(stdin);
               if(A==1)
               {
                  goto Eight;
               }
            }
         }
      }
      if(op!='L'&&op!='S'&&op!='M'&&op!='P'&&op!='D'&&op!='E'&&op!='A')//for a wrong operation input
      {
          system("color 50");
          printf("_________________________________PLEASE ENTER THE RIGHT OPERATION_________________\n");
      }
   }
   return 0;
}

