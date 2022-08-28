#include "atm.h"

void balance(char name[], char pin[], char ques[], char ans[])
    {
        char name_b[50];
        char pin_bb[10];
        char name_bb[50];
        strcpy(name_b,name);
        strcpy(name_bb,name);
        strcpy(pin_bb,pin);
        struct customer c;
        char filename[100] = "C:\\Users\\vasuy\\OneDrive\\ATM\\customers\\";
        strcat(filename, name_b);
        FILE *f;
        f = fopen(strcat(filename, ".dat"),"rb");
        if (f == NULL)
        {
            printf("\033[31m");
            printf("\n                                      **************** Invalid username!!!! ****************");
            printf("\033[37m");
            printf("\n");
        }
        while(fread(&c,sizeof(c),1,f))
            {    
                printf("\033[35m");
                printf("\n                                                           username: %s",c.username);
                printf("\n");
                printf("\033[33m");
                printf("\n                                                           Balance: %d.00",c.balance);
                printf("\n");
            }
        fclose(f);
    }