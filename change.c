#include "atm.h"

void change(char name[], char pin[], char ques[], char ans[])
    {
        char name_c[50];
        char pin_cc[20];
        char name_cc[50];
        struct customer c;
        strcpy(name_c, name);
        strcpy(name_cc, name);
        strcpy(c.username,name_c);
        strcpy(c.question, ques);
        strcpy(c.answer, ans);
        strcpy(name_cc,c.username);
        strcpy(pin_cc, pin);
        char filename[100] = "C:\\Users\\vasuy\\OneDrive\\ATM\\customers\\";
        strcat(filename, name_c);
        FILE *f;
        f = fopen(strcat(filename,".dat"),"rb");
        if (f == NULL)
            {
                printf("\033[31m");
                printf("\n                                   ******************* username not found!!! ********************");
                printf("\n");
            }
        while(fread(&c,sizeof(c),1,f))
            {
                
                char newpin[10];
                char newpin1[10];
                printf("\n");
                printf("\nPlease Enter your new PIN: ");
                fflush(stdin);
                scanf("%s",newpin);
                while(strlen(newpin) != 4)
                    {
                        printf("\033[31m");
                        printf("\nPlease Enter only 4-digit pin:");
                        fflush(stdin);
                        scanf("%s",newpin);

                    }
                printf("\033[37m");
                printf("\nPlease Re-Enter your new PIN: ");
                fflush(stdin);
                scanf("%s",newpin1);
                while(strlen(newpin1) != 4)
                    {
                        printf("\033[31m");
                        printf("\nPlease Enter only 4-digit pin:");
                        fflush(stdin);
                        printf("\033[37m");
                        scanf("%s",newpin1);

                    }
                printf("\033[37m");
                if(strcmp(newpin, newpin1) == 0)
                    strcpy(c.pin, newpin1);
                else
                    {
                        printf("\033[31m");
                        printf("\n                                                  Please Enter the same pin as above...!");
                        Sleep(2000);
                        printf("\033[37m");
                        fclose(f);
                        change(name_cc, pin_cc, ques, ans);
                        break;
                    }
                
                system("cls");
                FILE *fp;
                fp = fopen("C:\\Users\\vasuy\\OneDrive\\ATM\\customers\\temp.dat","ab");
                fwrite(&c,sizeof(c),1,fp);
                fclose(fp);
                printf("\033[32m");
                printf("\n                            ***************** Successfully your new pin has been updated...! *******************");
                Sleep(2000);
                system("cls");
                printf("\033[37m");
                printf("\n");
                printf("\n");
                fclose(f);
                remove(filename);
                rename("C:\\Users\\vasuy\\OneDrive\\ATM\\customers\\temp.dat",filename);
        
            }
        fclose(f);
        
    }   