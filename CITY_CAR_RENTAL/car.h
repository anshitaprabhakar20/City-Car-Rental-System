#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED
#include<time.h>
struct user
{
    char userid[20];
    char pwd[20];
    char name[20];
};
struct car
{
    int car_id;
    char car_name[50];
    int capacity;
    int car_count;
    int price;
};
struct Customer_Car_Details
{
    int car_id;
    char cust_name[30];
    char pick[30];
    char drop[30];
    struct tm sd;
    struct tm ed;
};
typedef struct user user;
typedef struct car car;
typedef struct Customer_Car_Details Customer_Car_Details;

void addAdmin();
user* getInput();
int checkUserExist(user,char*);
int adminMenu();
int empMenu();
void addEmployee();
void viewEmployee();
void addCarDetails();
void showCarDetails();
int deleteEmp();
int deleteCarModel();
int selectCarModel();
int isValidDate(struct tm);
void updateCarCount(int);
void bookedCarDetails();
int rentCar();
char* getCarName(int );
void availableCarDetails();
int deleteBookedCar();
void updateCarCount1(int );
#endif // CAR_H_INCLUDED
