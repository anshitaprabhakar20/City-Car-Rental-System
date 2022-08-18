#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"conio2.h"
#include"car.h"
void addAdmin()
{
  FILE *fp;
  fp=fopen("D:\\admin.bin","rb");
  if(fp==NULL)
  {
     fp=fopen("D:\\admin.bin","wb");
     user u[2]={{"admin","abc","Ramesh"},{"super","demo","anil"}};
     fwrite(&u,sizeof(u),1,fp);
     fclose(fp);
     getch();
  }
  else
    fclose(fp);

}
user* getInput()
{
    int i;
    clrscr();
    textcolor(YELLOW);
    gotoxy(33,2);
    printf("CAR RENTAL SYSTEM\n");
    gotoxy(1,7);
    for(i=1; i<=80; i++){
        printf("%c",247);
    }
    gotoxy(34,5);
    textcolor(LIGHTCYAN);
    printf("**LOGIN PANEL**");
    gotoxy(1,7);
    textcolor(YELLOW);
    for(i=1; i<=160; i++){
        printf("%c",247);
    }
    gotoxy(1,16);
    textcolor(YELLOW);
    for(i=1; i<=160; i++){
        printf("%c",247);
    }
    textcolor(WHITE);
    gotoxy(62,10);
    printf("PRESS 0 TO EXIT");
    gotoxy(28,10);
    textcolor(GREEN);
    printf("Enter User Id:");
    fflush(stdin);
    textcolor(WHITE);
    static user usr;
    fgets(usr.userid,20,stdin);
    char *pos;
    pos=strchr(usr.userid,'\n');
    if(pos!=NULL)
        *pos='\0';
    if(strcmp(usr.userid,"0")==0)
    {
        textcolor(LIGHTRED);
        gotoxy(35,20);
        printf("LOGIN CANCELLED");
        textcolor(YELLOW);
        return NULL;
    }
    gotoxy(28,11);
    textcolor(GREEN);
    printf("Enter Password:");
    fflush(stdin);
     i=0;
    char ch;
    textcolor(WHITE);
    while(1)
          {
             ch=getch();
             if(ch==13)
             {
                 usr.pwd[i]='\0';
                 break;
             }
             else if(ch==8)
             {
                 if(i>0)
                 {
                    i--;
                    printf("\b \b");
                 }
             }
             else if(ch==32)
                {
                  continue;
                }
             else
             {
                 usr.pwd[i]=ch;
                 printf("%c",usr.pwd[i]);
                  i++;
                 delay(1000);
                 printf("\b*");

             }
          }
          if(strcmp(usr.pwd,"0")==0)
          {
            textcolor(LIGHTRED);
            gotoxy(33,20);
            printf("LOGIN CANCELLED");
            textcolor(YELLOW);
            return NULL;
          }
          textcolor(6);
          gotoxy(28,13);
          printf("Verifying the Password..Please Wait");
          delay(3000);

        return &usr;

}
int checkUserExist(user u,char *usertype)
{
   if(strlen(u.userid)==0||strlen(u.pwd)==0)
   {
       gotoxy(28,18);
       textcolor(LIGHTRED);
       printf("Both fields are Mandatory..Try again");
       getch();
       getInput();
       return 0;
   }
  FILE *fp;
  user ur;
  int found=0;

  if(strcmp(usertype,"admin")==0)
  {
      fp=fopen("D:\\admin.bin","rb");
  }
  else
  {
      fp=fopen("D:\\emp.bin","rb");
  }
  if(fp==NULL)
  {
      gotoxy(28,20);
      textcolor(LIGHTRED);
      printf("Sorry! File cannot Open");
      getch();
      return -1;
  }

  while(fread(&ur,sizeof(ur),1,fp)==1)
  {
      if(strcmp(u.userid,ur.userid)==0&&strcmp(u.pwd,ur.pwd)==0)
      {
          found=1;
          break;
      }
  }

  if(found==0)
  {
      gotoxy(28,20);
      textcolor(LIGHTRED);
      printf("Invalid userid/password.Try again");
      getch();
  }
  else
  {
      gotoxy(40,19);
      textcolor(GREEN);
      printf("Login Successful..");
  }

  fclose(fp);
  return found;

}
int adminMenu()
{
int choice,i;
textcolor(LIGHTRED);
gotoxy(32,2);
printf("CAR RENTAL SYSTEM");
textcolor(LIGHTGREEN);

gotoxy(35,6);
printf("ADMIN MENU\n");
textcolor(11);
for(i=0; i<80; i++)
    {
printf("*");
    }
gotoxy(1,18);
for(i=0; i<80; i++)
    {
       printf("*");
    }
textcolor(YELLOW);
gotoxy(32,8);
printf("1. Add Employee");
gotoxy(32,9);
printf("2. Add Car Details");
gotoxy(32,10);
printf("3. Show Employee");
gotoxy(32,11);
printf("4. Show Car Details");
gotoxy(32,12);
printf("5. Delete Employee");
gotoxy(32,13);
printf("6. Delete Car Details");
gotoxy(32,14);
printf("7. Exit");
gotoxy(32,16);
printf("Enter choice:");
textcolor(WHITE);
scanf("%d",&choice);
    return choice;
}
void addEmployee()
{
    char empid[10]="Emp-";
    char temp[10];
    char uchoice,*pos;
    user u;
    FILE *fp=fopen("D:\\emp.bin","ab+");
      fseek(fp,0,SEEK_END);
    long total_rec=ftell(fp)/sizeof(user);
    if(total_rec!=0)
    {
        fseek(fp,-60,SEEK_END);
        fread(temp,sizeof(temp),1,fp);
        pos=strchr(temp,'-');
        total_rec=atoi(pos+1);
    }
        total_rec++;
        strcpy(empid,"Emp-");
        sprintf(temp,"%ld",total_rec);
        strcat(empid,temp);
        strcpy(u.userid,empid);
        fseek(fp,0,SEEK_END);
    do
    {
        clrscr();
        gotoxy(32,2);
        textcolor(LIGHTRED);
        printf("CAR RENTAL APP");
        textcolor(LIGHTGREEN);
        int i;
        gotoxy(1,3);
        for(i=0;i<80;i++)
        {
            printf("~");
        }
        textcolor(WHITE);
        gotoxy(25,5);
        printf("**** ADD EMPLOYEE DETAILS ****");
        gotoxy(1,8);
        textcolor(YELLOW);
        printf("Enter Employee Name:");
        fflush(stdin);
        textcolor(WHITE);
        fgets(u.name,20,stdin);
        pos=strchr(u.name,'\n');
        *pos='\0';
        textcolor(YELLOW);
        printf("Enter Employee Password:");
        fflush(stdin);
        textcolor(WHITE);
        fgets(u.pwd,20,stdin);
        pos=strchr(u.pwd,'\n');
        *pos='\0';
        textcolor(YELLOW);
        fseek(fp,0,SEEK_END);
        fwrite(&u,sizeof(u),1,fp);
        gotoxy(30,15);
        textcolor(LIGHTGREEN);
        printf("EMPLOYEE ADDED SUCCESSFULLY");
        printf("\nEMPLOYEE ID IS:%s",u.userid);
        _getch();
        gotoxy(1,20);
        textcolor(LIGHTRED);
        printf("\nDO YOU WANT TO ADD MORE EMPLOYEE(Y/N):");
        textcolor(WHITE);
        fflush(stdin);
        scanf("%c",&uchoice);
        if(uchoice=='N')
            break;
        total_rec++;
        strcpy(empid,"Emp-");
        sprintf(temp,"%ld",total_rec);
        strcat(empid,temp);
        strcpy(u.userid,empid);


    }while(1);
    fclose(fp);
}
void addCarDetails()
{
    char uchoice;
    FILE *fp=fopen("D:\\car.bin","ab+");
    fseek(fp,0,SEEK_END);
    int total_rec=ftell(fp)/sizeof(car);
    total_rec++;
    car c;
    c.car_id=total_rec;

    do
    {
        clrscr();
        gotoxy(32,2);
        textcolor(LIGHTRED);
        printf("CAR RENTAL APP");
        textcolor(LIGHTGREEN);
        int i;
        gotoxy(1,3);
        for(i=0;i<80;i++)
        {
            printf("~");
        }
        textcolor(WHITE);
        gotoxy(25,5);
        printf("**** ADD CAR DETAILS ****");
        gotoxy(1,8);
        textcolor(YELLOW);
        printf("Enter Car Model:");
        fflush(stdin);
        textcolor(WHITE);
        fgets(c.car_name,50,stdin);
        char *pos;
        pos=strchr(c.car_name,'\n');
        *pos='\0';
        textcolor(YELLOW);
        printf("Enter Car Capacity:");
        textcolor(WHITE);
        scanf("%d",&c.capacity);
        textcolor(YELLOW);
        printf("Enter Car Count:");
        textcolor(WHITE);
        scanf("%d",&c.car_count);
        textcolor(YELLOW);
        printf("Enter Car Price For Per Day:");
        textcolor(WHITE);
        scanf("%d",&c.price);
        fseek(fp,0,SEEK_END);
        fwrite(&c,sizeof(c),1,fp);
        gotoxy(30,15);
        textcolor(LIGHTGREEN);
        printf("CAR DETAILS ADDED SUCCESSFULLY");
        printf("\nCAR ID IS:%d",c.car_id);
        _getch();
        gotoxy(1,20);
        textcolor(LIGHTRED);
        printf("\nDO YOU WANT TO ADD MORE CAR(Y/N):");
        fflush(stdin);
        textcolor(WHITE);
        scanf("%c",&uchoice);
        total_rec++;
        c.car_id=total_rec;
    }while(uchoice=='Y'||uchoice=='y');
    fclose(fp);
}
void viewEmployee()
{
   FILE *fp;
    user user1;
    int i;
    clrscr();
    fp=fopen("D:\\emp.bin","rb");
    if(fp==NULL){
        gotoxy(32,8);
        textcolor(LIGHTRED);
        printf("Sorry! File Cannot be Open");
        getch();
        return ;
        }
    gotoxy(34,2);
    printf("CAR RENTAL SYSTEM");
    gotoxy(1,3);
    textcolor(11);
    for(i=0;i<80;i++)
     {
        printf("*");
     }

    gotoxy(32,5);
    textcolor(RED);
    printf("* EMPLOYEE DETAILS *");
    gotoxy(1,7);
    textcolor(GREEN);
    for(i=0;i<80;i++)
     {
        printf("*");
     }
     gotoxy(1,9);
     for(i=0;i<80;i++)
     {
        printf("*");
     }
    gotoxy(1,8);
    printf("EMPLOYEE ID");
    gotoxy(25,8);
    printf("NAME");
    gotoxy(50,8);
    printf("PASSWORD");
    rewind(fp);
    int row=10;
    while(fread(&user1,sizeof(user1),1,fp)==1)
    {
        textcolor(WHITE);
        gotoxy(1,row);
        printf("%s",user1.userid);
        gotoxy(50,row);
        printf("%s",user1.pwd);
        gotoxy(25,row);
        printf("%s",user1.name);
        row++;
    }
    fclose(fp);

}
void showCarDetails()
{
    FILE *fp;
    car c1;
    int i;
    clrscr();
    fp=fopen("D:\\car.bin","rb");
    if(fp==NULL){
        gotoxy(32,8);
        textcolor(LIGHTRED);
        printf("Sorry! File Cannot Open");
        getch();
        return ;
        }
    gotoxy(34,2);
    printf("CAR RENTAL SYSTEM");
    gotoxy(1,3);
    textcolor(11);
    for(i=0;i<80;i++)
     {
        printf("*");
     }

    gotoxy(32,5);
    textcolor(RED);
    printf("* CAR DETAILS *");
    gotoxy(1,7);
    textcolor(GREEN);
    for(i=0;i<80;i++)
     {
        printf("*");
     }
     gotoxy(1,9);
     for(i=0;i<80;i++)
     {
        printf("*");
     }
    gotoxy(1,8);
    printf("CAR ID");
    gotoxy(15,8);
    printf("NAME");
    gotoxy(30,8);
    printf("CAPACITY");
    gotoxy(47,8);
    printf("CAR COUNT");
    gotoxy(68,8);
    printf("RENT PRICE");
    int row=10;
    while(fread(&c1,sizeof(c1),1,fp)==1)
    {
        textcolor(WHITE);
        gotoxy(1,row);
        printf("%d",c1.car_id);
        gotoxy(15,row);
        printf("%s",c1.car_name);
        gotoxy(30,row);
        printf("%d",c1.capacity);
        gotoxy(47,row);
        printf("%d",c1.car_count);
        gotoxy(68,row);
        printf("%d",c1.price);
        row++;
    }
    fclose(fp);
}
int deleteEmp()
{
    FILE *fp;
    FILE *fp1;
    user u;
    int i,result;
    char str[20];
    unsigned flag=0;
    clrscr();
    fp=fopen("D:\\emp.bin","rb");
    if(fp==NULL)
    {
     textcolor(LIGHTRED);
     gotoxy(32,10);
     printf("\nNo Employee Added Yet!");
     getch();
     return -1;
    }
    gotoxy(34,1);
    printf("CAR RENTAL SYSTEM");
    gotoxy(1,2);
    textcolor(11);
    for(i=0;i<80;i++)
     {
        printf("*");
     }
    gotoxy(29,5);
    textcolor(RED);
    printf("##_DELETE EMPLOYEE RECORD_##");
    gotoxy(1,6);
    textcolor(GREEN);
    for(i=0;i<80;i++)
     {
        printf("*");
     }
    gotoxy(1,12);
    textcolor(GREEN);
    for(i=0;i<80;i++)
     {
        printf("*");
     }
    gotoxy(8,9);
    textcolor(YELLOW);
    printf("Enter the User Id of Employee Which You Want to delete:");
    textcolor(WHITE);
    scanf("%s",str);
    fp1=fopen("D:\\emp1.bin","wb+");
    while(fread(&u,sizeof(u),1,fp)==1)
    {
        if(strcmp(str,u.userid)!=0)
         fwrite(&u,sizeof(u),1,fp1);
        else
         flag=1;
    }
    fclose(fp);
    fclose(fp1);
    if(flag==0){
      remove("D:\\emp1.bin");
    }
    else{
          result=remove("D:\\emp.bin");
          if(result!=0)
            return 2;
          result=rename("D:\\emp1.bin","D:\\emp.bin");
          if(result!=0)
            return 2;
        }
     return flag;


}
int deleteCarModel()
{
    FILE *fp;
    FILE *fp1;
    car c;
    int i,result;
    char str[0];
    unsigned flag=0;
    clrscr();
    fp=fopen("D:\\car.bin","rb");
    if(fp==NULL)
    {
     textcolor(LIGHTRED);
     gotoxy(32,10);
     printf("\nNo Car Model Added Yet!");
     getch();
     return -1;
    }
    gotoxy(34,1);
    printf("CAR RENTAL SYSTEM");
    gotoxy(1,2);
    textcolor(11);
    for(i=0;i<80;i++)
     {
        printf("*");
     }
    gotoxy(29,5);
    textcolor(RED);
    printf("##_DELETE CAR MODEL_##");
    gotoxy(1,6);
    textcolor(GREEN);
    for(i=0;i<80;i++)
     {
        printf("*");
     }
    gotoxy(1,12);
    textcolor(GREEN);
    for(i=0;i<80;i++)
     {
        printf("*");
     }
    gotoxy(8,9);
    textcolor(YELLOW);
    printf("Enter the Name of the Model You Want To Delete:");
    textcolor(WHITE);
    scanf("%s",str);
    fp1=fopen("D:\\car1.bin","wb+");
    while(fread(&c,sizeof(c),1,fp)==1)
    {
        if(strcmp(str,c.car_name)!=0)
         fwrite(&c,sizeof(c),1,fp1);
        else
         flag=1;
    }
    fclose(fp);
    fclose(fp1);
     if(flag==0){
      remove("D:\\car1.bin");
    }
    else{
          result=remove("D:\\car.bin");
          if(result!=0)
            return 2;
          result=rename("D:\\car1.bin","D:\\car.bin");
          if(result!=0)
            return 2;
        }
     return flag;

}
int empMenu()
{
        int choice,i;
        textcolor(LIGHTRED);
        gotoxy(32,2);
        printf("CAR RENTAL SYSTEM");
        textcolor(LIGHTGREEN);

        gotoxy(35,6);
        printf("EMPLOYEE MENU\n");
        for(i=0; i<80; i++)
        {
          printf("*");
        }
        gotoxy(1,16);
        for(i=0; i<80; i++)
        {
          printf("*");
        }
        textcolor(YELLOW);
        gotoxy(32,8);
        printf("1. Rent A Car");
        gotoxy(32,9);
        printf("2. Booking Details");
        gotoxy(32,10);
        printf("3. Available Car Details");
        gotoxy(32,11);
        printf("4. Show All Car Details");
        gotoxy(32,12);
        printf("5. Delete Booked Car Details");
        gotoxy(32,13);
        printf("6. Exit");
        gotoxy(32,15);
        printf("Enter choice:");
        textcolor(WHITE);
        scanf("%d",&choice);
        return choice;
}


int selectCarModel()
{
    int flag;
    FILE *fp=fopen("D:\\car.bin","rb");
    if(fp==NULL)
    {
        gotoxy(27,18);
        textcolor(LIGHTRED);
        printf("Sorry ! File cannot be opened");
        getch();
        gotoxy(27,18);
        printf("\t\t");
        return -1;
    }
    car C;
    int choice,x=9,carcount=0;

   gotoxy(34,x);
    while(fread(&C,sizeof(C),1,fp)==1)
    {
        if(C.car_count>0)
        {
            printf("%d . %s",C.car_id,C.car_name);
            gotoxy(34,++x);
            ++carcount;
        }
    }
    if(carcount==0)
    {
        fclose(fp);
        return -2;
    }
   gotoxy(34,x+2);
   printf("Enter your choice:");
    while(1)
    {
        flag=0;
        scanf("%d",&choice);
        if(choice==0)
        {
            fclose(fp);
            return 0;
        }
        rewind(fp);
        while(fread(&C,sizeof(C),1,fp)==1)
        {
            if(C.car_id==choice)
            {
                flag=1;
                break;

            }
        }
        if(flag==1)
        {
            fclose(fp);
            return choice;
        }
        else
        {
          gotoxy(37,x+4);
          textcolor(LIGHTRED);
          printf("Wrong Input");
            _getch();
          gotoxy(35,x+4);
          printf("\t\t");
          gotoxy(52,x+2);
          printf("\t");
          gotoxy(52,x+2);
          textcolor(WHITE);

        }

    }
}
int rentCar()
{
    int i,c;
    Customer_Car_Details cc;
    time_t obj=time(0);
    struct tm *p=localtime(&obj);
    textcolor(LIGHTRED);
    gotoxy(32,2);
    printf("CAR RENTAL SYSTEM");
    textcolor(LIGHTGREEN);
    gotoxy(35,6);
    printf("EMPLOYEE MENU\n");
    for(i=1; i<80; i++)
    {
      printf("*");
    }
    gotoxy(1,15);
    for(i=1; i<=80; i++)
    {
      printf("*");
    }
    textcolor(YELLOW);
    c=selectCarModel();
    if(c==0||c==-2)
        return c;
    cc.car_id=c;
    clrscr();
     textcolor(LIGHTRED);
    gotoxy(32,2);
    printf("CAR RENTAL SYSTEM");
    textcolor(LIGHTGREEN);
    gotoxy(35,6);
    printf("EMPLOYEE MENU\n");
    for(i=1; i<80; i++)
    {
      printf("*");
    }
    gotoxy(1,17);
    for(i=1; i<80; i++)
    {
      printf("*");
    }
    textcolor(YELLOW);
    gotoxy(27,9);
    printf("Enter Customer Name:");
    fflush(stdin);
    textcolor(WHITE);
    fgets(cc.cust_name,30,stdin);
    char *pos;
    pos=strchr(cc.cust_name,'\n');
    *pos='\0';
    textcolor(YELLOW);
    gotoxy(27,10);
    printf("Enter Pickup Point:");
    fflush(stdin);
    textcolor(WHITE);
    fgets(cc.pick,30,stdin);
    pos=strchr(cc.pick,'\n');
    *pos='\0';
    gotoxy(27,11);
    textcolor(YELLOW);
    printf("Enter Drop Point:");
    fflush(stdin);
    textcolor(WHITE);
    fgets(cc.drop,30,stdin);
    pos=strchr(cc.drop,'\n');
    *pos='\0';
        gotoxy(27,12);
    textcolor(YELLOW);
    printf("Enter start date (dd/mm/yyyy):");
    textcolor(WHITE);
    do
    {
        scanf("%d/%d/%d",&cc.sd.tm_mday,&cc.sd.tm_mon,&cc.sd.tm_year);
        if(((cc.sd.tm_year>=1900+p->tm_year)&&(cc.sd.tm_year<=2022))&&(cc.sd.tm_mon>=1+p->tm_mon)&&(cc.sd.tm_mday>=p->tm_mday))
        {
           int datevalid=isValidDate(cc.sd);
           if(datevalid==0)
           {
               gotoxy(27,18);
               textcolor(LIGHTRED);
               printf("Wrong Date");
               _getch();
               gotoxy(27,18);
               printf("\t\t");
               gotoxy(56,12);
               printf("\t\t\t");
               gotoxy(56,12);
               textcolor(WHITE);
            }
          else
            break;
        }
        else
        {
            if(cc.sd.tm_mon>1+p->tm_mon)
            {
                break;
            }
            else
            {
              gotoxy(27,18);
              textcolor(LIGHTRED);
              printf("Wrong Date");
              _getch();
              gotoxy(27,18);
              printf("\t\t");
              gotoxy(56,12);
              printf("\t\t\t");
              gotoxy(56,12);
              textcolor(WHITE);
            }
        }
    }while(1);
    gotoxy(27,13);
    textcolor(YELLOW);
    printf("Enter end date (dd/mm/yyyy):");
    textcolor(WHITE);

    do
    {
        scanf("%d/%d/%d",&cc.ed.tm_mday,&cc.ed.tm_mon,&cc.ed.tm_year);
        if((cc.ed.tm_year>=cc.sd.tm_year&&cc.ed.tm_year<=2022)&&(cc.ed.tm_mon>=cc.sd.tm_mon)&&(cc.ed.tm_mday>=cc.sd.tm_mday))
        {
          int datevalid=isValidDate(cc.ed);
          if(datevalid==0)
            {
              gotoxy(27,18);
              textcolor(LIGHTRED);
              printf("Wrong Date");
              _getch();
              gotoxy(27,18);
              printf("\t\t");
              gotoxy(54,13);
              printf("\t\t\t");
              gotoxy(54,13);
              textcolor(WHITE);
            }
           else
              break;
        }
        else
        {
             if(cc.ed.tm_mon>cc.sd.tm_mon)
              {
                 break;
              }
              gotoxy(27,18);
              textcolor(LIGHTRED);
              printf("Wrong Date");
              _getch();
              gotoxy(27,18);
              printf("\t\t");
              gotoxy(54,13);
              printf("\t\t\t");
              gotoxy(54,13);
              textcolor(WHITE);
        }
    }while(1);

    FILE *fp;
    fp=fopen("D:\\customer.bin","ab");
if(fp==NULL)
    {
        gotoxy(27,18);
        textcolor(LIGHTRED);
        printf("Sorry ! File cannot be opened");
        getch();
        gotoxy(27,18);
        printf("\t\t");
        return -1;
    }
    fwrite(&cc,sizeof(Customer_Car_Details),1,fp);
    printf("Booking Done:%d",cc.car_id);
    printf("\nPress any key to continue...");
    getch();
    fclose(fp);
    updateCarCount(c);
    bookedCarDetails();
    return 1;
}

int isValidDate(struct tm dt)
{
    if(dt.tm_year>=2021&& dt.tm_year<=2022)
    {
        //check month
        if(dt.tm_mon>=1 && dt.tm_mon<=12)
        {
//check days
            if((dt.tm_mday>=1 && dt.tm_mday<=31) && (dt.tm_mon==1 || dt.tm_mon==3 || dt.tm_mon==5 || dt.tm_mon==7 || dt.tm_mon==8 || dt.tm_mon==10 || dt.tm_mon==12))
               return 1;
            else if((dt.tm_mday>=1 && dt.tm_mday<=30) && (dt.tm_mon==4 || dt.tm_mon==6 || dt.tm_mon==9 || dt.tm_mon==11))
               return 1;
            else if((dt.tm_mday>=1 && dt.tm_mday<=28) && (dt.tm_mon==2))
                return 1;
            else if(dt.tm_mday==29 && dt.tm_mon==2 && (dt.tm_year%400==0 ||(dt.tm_year%4==0 && dt.tm_year%100!=0)))
               return 1;
            else
               return 0;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }

}
void updateCarCount(int c)
{

    FILE *fp=fopen("D:\\car.bin","rb+");
    car C;
     if(fp==NULL){
        gotoxy(32,8);
        textcolor(LIGHTRED);
        printf("Sorry! File Cannot Be Open");
        getch();
        return ;
        }

    while(fread(&C,sizeof(car),1,fp)==1)
     {

        if(C.car_id==c)
        {
            fseek(fp,-8,SEEK_CUR);

            int cc_new=C.car_count-1;

            fwrite(&cc_new,sizeof(cc_new),1,fp);
            fseek(fp,-4,SEEK_CUR);

            _getch();


        }

      }


    fclose(fp);
}
void bookedCarDetails()
{
    clrscr();
    FILE *fp=fopen("D:\\customer.bin","rb");
     if(fp==NULL){
        gotoxy(32,8);
        textcolor(LIGHTRED);
        printf("Sorry! File Cannot Be Open");
        getch();
        return ;
        }
    Customer_Car_Details CC;
    int i;
    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM\n");
    for(i=1; i<=80; i++)
        printf("%c",247);
    gotoxy(31,5);
    textcolor(YELLOW);
    printf("* BOOKED CAR DETAILS *");
    gotoxy(1,6);
    textcolor(LIGHTGREEN);
    for(i=1; i<80; i++)
        printf("%c",247);
    gotoxy(1,7);
    printf("Model\t    Cust Name\t  Pick Up\t   Drop\t\t S_Date\t     E_Date");
    gotoxy(1,8);
    textcolor(LIGHTGREEN);
    for(i=1; i<80; i++)
        printf("%c",247);
    int x=9;
    textcolor(WHITE);

    while(fread(&CC,sizeof(Customer_Car_Details),1,fp)==1)
    {
        gotoxy(1,x);
        printf("%s",getCarName(CC.car_id));
        gotoxy(13,x);
        printf("%s",CC.cust_name);
        gotoxy(27,x);
        printf("%s",CC.pick);
        gotoxy(44,x);
        printf("%s",CC.drop);
        gotoxy(58,x);
        printf("%d-%d-%d",CC.sd.tm_mday,CC.sd.tm_mon,CC.sd.tm_year);
        gotoxy(70,x);
        printf("%d-%d-%d",CC.ed.tm_mday,CC.ed.tm_mon,CC.ed.tm_year);
        x++;


    }
    fclose(fp);
    _getch();

}
char* getCarName(int a)
{
     FILE *fp=fopen("D:\\car.bin","rb");
     static car c;
    while(fread(&c,sizeof(c),1,fp)==1)
    {
        if(c.car_id==a)
            break;
    }
    return c.car_name;
}
void availableCarDetails()
{
    FILE *fp;
    car c1;
    int i,f=0;
    clrscr();
    fp=fopen("D:\\car.bin","rb");
    if(fp==NULL){
        gotoxy(32,8);
        textcolor(LIGHTRED);
        printf("Sorry! File Cannot Be open");
        getch();
        return ;
        }
    gotoxy(34,2);
    printf("CAR RENTAL SYSTEM");
    gotoxy(1,3);
    textcolor(11);
    for(i=0;i<80;i++)
     {
        printf("*");
     }

    gotoxy(32,5);
    textcolor(RED);
    printf("* AVAILABLE CAR DETAILS *");
    gotoxy(1,7);
    textcolor(GREEN);
    for(i=0;i<80;i++)
     {
        printf("*");
     }
     gotoxy(1,9);
     for(i=0;i<80;i++)
     {
        printf("*");
     }
    gotoxy(1,8);
    printf("CAR ID");
    gotoxy(15,8);
    printf("NAME");
    gotoxy(30,8);
    printf("CAPACITY");
    gotoxy(47,8);
    printf("CAR COUNT");
    gotoxy(68,8);
    printf("RENT PRICE");
    int row=10;
    while(fread(&c1,sizeof(c1),1,fp)==1)
    {
        if(c1.car_count>0)
        {
        f=1;
        textcolor(WHITE);
        gotoxy(1,row);
        printf("%d",c1.car_id);
        gotoxy(15,row);
        printf("%s",c1.car_name);
        gotoxy(30,row);
        printf("%d",c1.capacity);
        gotoxy(47,row);
        printf("%d",c1.car_count);
        gotoxy(68,row);
        printf("%d",c1.price);
        row++;
        }

    }
    if(f==0)
        {
            gotoxy(28,14);
            textcolor(LIGHTRED);
            printf("NO,Car Available!");
        }

    fclose(fp);
}
int deleteBookedCar()
{
    FILE *fp;
    FILE *fp1;
    Customer_Car_Details cc;
    int i,result;
    char str[40];
    unsigned flag=0;
    clrscr();
    fp=fopen("D:\\customer.bin","rb");
    if(fp==NULL)
    {
    textcolor(LIGHTRED);
    gotoxy(32,10);
    printf("Sorry!No Car Booked Yet");
    getch();
    return -1;
    }
    gotoxy(34,1);
    printf("CAR RENTAL SYSTEM");
    gotoxy(1,2);
    textcolor(11);
    for(i=0;i<80;i++)
     {
        printf("*");
     }
    gotoxy(29,5);
    textcolor(RED);
    printf("##_DELETE CUSTOMER RECORD_##");
    gotoxy(1,6);
    textcolor(GREEN);
    for(i=0;i<80;i++)
     {
        printf("*");
     }
    gotoxy(1,12);
    textcolor(GREEN);
    for(i=0;i<80;i++)
     {
        printf("*");
     }
    gotoxy(8,9);
    textcolor(YELLOW);
    printf("Enter the Name of Customer Whose data You Want to delete:");
    textcolor(WHITE);
    scanf("%s",str);
    fp1=fopen("D:\\customer1.bin","wb+");
    while(fread(&cc,sizeof(Customer_Car_Details ),1,fp)==1)
    {
        if(strcmp(str,cc.cust_name)!=0)
         fwrite(&cc,sizeof(Customer_Car_Details ),1,fp1);
        else{
         updateCarCount1(cc.car_id);
         flag=1;
        }
    }
    fclose(fp);
    fclose(fp1);
    if(flag==0){
      remove("D:\\customer1.bin");
    }
    else{
          result=remove("D:\\customer.bin");
          if(result!=0)
            return 2;
          result=rename("D:\\customer1.bin","D:\\customer.bin");
          if(result!=0)
            return 2;
        }
     return flag;


}
void updateCarCount1(int c)
{
    FILE *fp=fopen("D:\\car.bin","rb+");
    car C;
    if(fp==NULL){
        gotoxy(32,8);
        textcolor(LIGHTRED);
        printf("Sorry! File Cannot Be Open");
        getch();
        return ;
        }


    while(fread(&C,sizeof(car),1,fp)==1)
    {

        if(C.car_id==c)
        {
            fseek(fp,-8,SEEK_CUR);

            int cc_new=C.car_count+1;

            fwrite(&cc_new,sizeof(cc_new),1,fp);
            fseek(fp,-4,SEEK_CUR);

            _getch();


        }

    }
    fclose(fp);
}




