#include "atm.h"


void totaladd(int thous, int fives, int twos, int hunds, int fiftys)
    {
        struct atm a;
        FILE *pntr;
        pntr = fopen("C:\\Users\\vasuy\\OneDrive\\ATM\\totalamount\\totalamount.dat", "rb");
        if (pntr == NULL)
            {
                printf("Error Occured while opening the FILE...!");
            }
        while(fread(&a, sizeof(a), 1, pntr))
            {
                FILE *ptr5;
                ptr5 = fopen("C:\\Users\\vasuy\\OneDrive\\ATM\\totalamount\\details.dat","ab");
                a.thous = a.thous + thous;
                a.fives = a.fives + fives;
                a.twos = a.twos + twos;
                a.hunds = a.hunds + hunds;
                a.fiftys = a.fiftys + fiftys; 
                a.amount = (a.thous*2000) + (a.fives*500) + (a.twos*200) + (a.hunds*100) + (a.fiftys*50);
                fwrite(&a, sizeof(a), 1, ptr5);
                fclose(ptr5);
            }
            
        fclose(pntr);
        remove("C:\\Users\\vasuy\\OneDrive\\ATM\\totalamount\\totalamount.dat");
        rename("C:\\Users\\vasuy\\OneDrive\\ATM\\totalamount\\details.dat", "C:\\Users\\vasuy\\OneDrive\\ATM\\totalamount\\totalamount.dat");

    }

void totalsub(int thous, int fives, int twos, int hunds, int fiftys)
    {
        struct atm a;
        FILE *ptnr1;
        ptnr1 = fopen("C:\\Users\\vasuy\\OneDrive\\ATM\\totalamount\\totalamount.dat", "rb");
        if (ptnr1 == NULL)
            {
                printf("Error Occured while opening the FILE...!");
            }
        while(fread(&a, sizeof(a), 1, ptnr1))
            {
                FILE *ptr7;
                ptr7 = fopen("C:\\Users\\vasuy\\OneDrive\\ATM\\totalamount\\details.dat","ab");
                a.thous = a.thous - thous;
                a.fives = a.fives - fives;
                a.twos = a.twos - twos;
                a.hunds = a.hunds - hunds;
                a.fiftys = a.fiftys - fiftys; 
                a.amount = (a.thous*2000) + (a.fives*500) + (a.twos*200) + (a.hunds*100) + (a.fiftys*50);
                fwrite(&a, sizeof(a), 1, ptr7);
                fclose(ptr7);
            }
            
        fclose(ptnr1);
        remove("C:\\Users\\vasuy\\OneDrive\\ATM\\totalamount\\totalamount.dat");
        rename("C:\\Users\\vasuy\\OneDrive\\ATM\\totalamount\\details.dat", "C:\\Users\\vasuy\\OneDrive\\ATM\\totalamount\\totalamount.dat");

    }
void display()
    {
        struct atm a;
        FILE *ptr6;
        ptr6 = fopen("C:\\Users\\vasuy\\OneDrive\\ATM\\totalamount\\totalamount.dat", "rb");
        if (ptr6 == NULL)
            {
                printf("\nError Occured while opening a file...!");
            }
        fread(&a, sizeof(a), 1, ptr6);
            
        printf("\ntotalamount: %d\n", a.amount);
        printf("\nno of 2000's are %d\n", a.thous);
        printf("\nno of 500's are %d\n", a.fives);
        printf("\nno of 200's are %d\n", a.twos);
        printf("\nno of 100's are %d\n", a.hunds);
        printf("\nno of 50's are %d\n", a.fiftys);
            
        fclose(ptr6);
    }


int transfer()
    {
        struct atm a;
        FILE *ptr6;
        int temp;
        ptr6 = fopen("C:\\Users\\vasuy\\OneDrive\\ATM\\totalamount\\totalamount.dat", "rb");
        if (ptr6 == NULL)
            {
                printf("\nError Occured while opening a file...!");
            }
        while(fread(&a, sizeof(a), 1, ptr6))
            {
                temp = a.amount;
            }
        fclose(ptr6);

        return temp;
    }