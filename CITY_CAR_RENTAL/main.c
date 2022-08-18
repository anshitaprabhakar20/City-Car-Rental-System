#include<stdio.h>
#include<stdlib.h>
#include"conio2.h"
#include"car.h"
int main()
{   int ch,k,choice;
    struct user *usr;
    gotoxy(27,10);
    textcolor(YELLOW);
    printf("WELCOME TO CAR RENTAL SYSTEM");
    gotoxy(21,14);
    textcolor(LIGHTGREEN);
    printf("* RENT A CAR AND GO WHEREVER YOU NEED *");
    getch();
    textcolor(YELLOW);
    addAdmin();
  while(1)
    {
        clrscr();
        textcolor(LIGHTRED);
        gotoxy(32,4);
        printf("CAR RENTAL SYSTEM");
        textcolor(11);
        gotoxy(1,7);
        for(int i=1; i<=80; i++){
            printf("*");
        }

        gotoxy(1,17);
        for(int i=1; i<=80; i++){
            printf("*");
        }
        textcolor(YELLOW);
        gotoxy(35,9);
        printf("1.ADMIN");
        gotoxy(35,11);
        printf("2.EMPLOYEE");
        gotoxy(35,13);
        printf("3.QUIT");
        textcolor(GREEN);
        gotoxy(35,15);
        printf("SELECT:");
        do{
           scanf("%d",&ch);
           k=0;
           if(ch==1)
             {

                    do
						{
                            usr=getInput();
							if(usr!=NULL)
							{
									k=checkUserExist(*usr,"admin");
							}
							else
							{
                               break;
							}
						}  while(k==0);
						if(usr==NULL)
                            break;
                        if(k==-1)
                           break;
                        if(k==1)
					       {
						      gotoxy(1,20);
                              textcolor(WHITE);
                              printf("Press any key to continue");
                              getch();
                             while(1)
						       {
							       clrscr();
                                   choice=adminMenu();
                                    if(choice==7)
                                     {
                                        clrscr();
                                        break;
                                     }
						            switch(choice)
						              {
								          case 1:
								                {
											       clrscr();
                                                   addEmployee();
											       break;
                                                }
                                          case 2:
                                                {
											       clrscr();
                                                   addCarDetails();
											       break;
                                                }
							              case 3:
							                    {
							                        clrscr();
                                                    viewEmployee();
                                                    getch();
											        break;
                                                 }
                                          case 4:
                                                 {
											        clrscr();
											        showCarDetails();
											        getch();
                                                    break;
						                         }
                                          case 5:{
							                       int result;
                                                   clrscr();
                                                   result=deleteEmp();
                                                   gotoxy(20,14);
                                                   if(result==0)
                                                      {
                                                          textcolor(LIGHTRED);
                                                          printf("Sorry! No Emp Found For Given Emp Id");
                                                      }
                                                   else if(result==1)
                                                      {
                                                           textcolor(LIGHTGREEN);
                                                           printf("Record Deleted Successfully.");
                                                      }
                                                   else if(result==2)
                                                      {
                                                           textcolor(LIGHTRED);
                                                           printf("Sorry! Error in Deletion.Try Again");
                                                      }
                                                    textcolor(WHITE);
                                                    printf("\n\n\n\n\nPress Any Key to go back to the Main Screen!");
                                                    getch();
                                                    break;
							                      }

                                            case 6:
							                    {
											        int result;
							  				        clrscr();
                                                    result=deleteCarModel();
                                                    gotoxy(20,14);
                                                   if(result==0)
                                                     {
                                                         textcolor(LIGHTRED);
                                                         printf("Sorry! No Record Found");
                                                     }
                                                   else if(result==1)
                                                     {
                                                        textcolor(LIGHTGREEN);
                                                        printf("Record Deleted Successfully.");
                                                     }
                                                   else if(result==2)
                                                     {
                                                        textcolor(LIGHTRED);
                                                        printf("Sorry! Error in Deletion.Try Again");
                                                     }
                                                    textcolor(WHITE);
                                                    printf("\n\n\n\n\nPress Any Key to go back to the Main Screen!");
                                                    getch();
                                                    break;
							                   }

						                 default:
										           printf("Incorrect Choice:");

                               }//switch close
                        } //While Close

                            if(choice==7)
                                {
                                    break;
                                }
                    }//if close
            }

         else if(ch==2)
              {
                    do
						{
                            usr=getInput();
							if(usr!=NULL)
							{
									k=checkUserExist(*usr,"emp");
							}
							else
							{
                               break;
							}
						}  while(k==0);
						if(usr==NULL)
                            break;
                       if(k==-1)
                          break;
                       if(k==1)
					       {
						     gotoxy(1,20);
                             textcolor(WHITE);
                             printf("Press any key to continue");
                             getch();


						        while(1)
                                        {
                                           clrscr();
                                            choice=empMenu();
                                             if(choice==6)
                                             {
                                                 clrscr();
                                                 break;
                                             }

						                         switch(choice)
						                              {
								                          case 1:
								                              {
                                                                     clrscr();
                                                                     int rentresp;
                                                                     rentresp=rentCar();
											                         if(rentresp==-2)
                                                                         {
                                                                             gotoxy(28,9);
                                                                             textcolor(LIGHTRED);
                                                                             printf("Sorry!All Car Booked.. Try Later");
                                                                             getch();
                                                                          }
                                                                        else if(rentresp==0)
                                                                          {
                                                                             gotoxy(27,18);
                                                                             textcolor(LIGHTRED);
                                                                             printf("You Did not Choose any Car");
                                                                             getch();

                                                                          }

											                           break;
								                              }
								                           case 2:
                                                                  {
											                         clrscr();
											                         bookedCarDetails();
                                                                     break;
                                                                  }
                                                           case 3:
                                                                  {
                                                                     clrscr();
											                         availableCarDetails();
											                         getch();
                                                                     break;
                                                                   }																								break;
                                                           case 4:{
											                         clrscr();
											                         showCarDetails();
											                         getch();
                                                                     break;
                                                                  }
                                                           case 5:
                                                            {
                                                                      int result;
                                                                      clrscr();
                                                                      result=deleteBookedCar();
                                                                      gotoxy(20,14);
                                                                    if(result==0)
                                                                    {
                                                                      textcolor(LIGHTRED);
                                                                      printf("Sorry! No Record Found");
                                                                    }
                                                                    else if(result==1)
                                                                     {
                                                                       textcolor(LIGHTGREEN);
                                                                       printf("Record Deleted Successfully.");
                                                                     }
                                                                   else if(result==2)
                                                                    {
                                                                       textcolor(LIGHTRED);
                                                                       printf("Sorry! Error in Deletion.Try Again");
                                                                    }
                                                                   textcolor(WHITE);
                                                                   printf("\n\n\n\n\nPress Any Key to go back to the Main Screen!");
                                                                   getch();
                                                                   break;
                                                            }


                                                          default:
										                          printf("Incorrect Choice:");

                                                    }//switch close
                                                            // if exit press go back to the role selction
                                         }//while close
                                         if(choice==6)
                                             {
                                                 break;
                                             }
                            }//if close
              }//else if close

         else if(ch==3)
             {
               clrscr();
               gotoxy(25,12);
               textcolor(11);
               printf("Thank You for using the App!");
               getch();
               exit(0);
             }
        else
             {
               textcolor(RED);
               gotoxy(25,18);
               printf("WRONG CHOICE..TRY AGAIN!");
               break;
             }

        }while(1);//do while close
        getch();
    }//While Close


    return 0;
}
