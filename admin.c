#include<stdio.h>
#include "atm.h"
#include<conio.h>

void admin(char name[], char pin[])
    {
        if(strcmp(name, "admin") == 0 && strcmp(pin, "1234") == 0)
            {
               
                int choice;
                
                while(1)
                {
                    printf("\n1.Total amount in ATM\n");
                    printf("\n2.Reload\n");
                    printf("\n0.Logout\n");
                    printf("\nEnter choice: ");
                    scanf("%d", &choice);
                    switch(choice)
                        {
                            case 1: display();
                                    printf("\npress any key\n");
                                    char ch;
                                    fflush(stdin);
                                    ch = getch();
                                    system("cls");
                                    break;
                            case 2: {
                                        struct atm a;
                                        a.thous = 20;
                                        a.fives = 80;
                                        a.twos = 50;
                                        a.hunds = 50;
                                        a.fiftys = 100;
                                        a.amount = (a.thous*2000) + (a.fives*500) + (a.twos*200) + (a.hunds*100) + (a.fiftys*50);
                                        FILE *p;
                                        p = fopen("C:\\Users\\vasuy\\OneDrive\\ATM\\totalamount\\totalamount.dat", "wb");
                                        fwrite(&a, sizeof(a), 1, p);
                                        fclose(p);
                                        printf("\nReloaded\n");
                                        break;
                                    }
                            case 0: main();
                        }
                }
                
            }

    }