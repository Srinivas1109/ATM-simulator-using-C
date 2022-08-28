#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<stdio.h>
#include<windows.h>
#include<dirent.h>
#include<conio.h>

int main();
void create();
void login();
void balance(char[], char[], char[], char[]);
void change(char[], char[], char[], char[]);
void withdraw(char[], char[], char[], char[]);
void statement(char[], char[], char[], char[]);
void deposit(char[], char[], char[], char[]);
void totaladd(int, int, int, int, int);
void totalsub(int, int, int, int, int);
void display();
int transfer();
void admin(char[], char[]);
int username_verify(char*);


struct customer
    {
        int balance;
        char pin[10];
        char username[10];
        char date_time[9000];
        int i;
        char statement[1000][150];
        char question[100];
        char answer[100];   
    };

struct atm
    {
        int amount;
        int thous;
        int fives;
        int twos;
        int hunds;
        int fiftys;
    };

