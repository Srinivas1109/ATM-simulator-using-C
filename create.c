#include "atm.h"
void create()
    {
        struct customer c;
        char name[50];
        printf("\nEnter username: ");
        scanf("%s",c.username);
        strcpy(name, c.username);
        if(!username_verify(name))
            {
                fflush(stdin);
                printf("\nEnter your 4-digit pin:");
                scanf("%s",c.pin);
                while(strlen(c.pin) != 4)
                    {
                        printf("\033[31m");
                        printf("\nPlease Enter only 4-digit pin:");
                        fflush(stdin);
                        scanf("%s",c.pin);

                    }
                printf("\033[37m");
                printf("\nInput your security question: ");
                fflush(stdin);
                scanf("%[^\n]s", c.question);
                fflush(stdin);
                printf("Input your security answer:");
                scanf("%[^\n]s", c.answer);
                c.balance = 1000;
                c.i = 0;
                char filename[100] = "C:\\Users\\vasuy\\OneDrive\\ATM\\customers\\";
                strcat(filename, name);
                //strcpy(c.date_time,"\n");
                FILE *f;
                f = fopen(strcat(filename, ".dat"),"ab");
                fwrite(&c,sizeof(c),1,f);
                fclose(f);
                printf("\033[32m");
                printf("                                 ******************* Successfully Created...! **********************");
                Sleep(2000);
                printf("\033[37m");
                printf("\n");
            }
        else
            {
                printf("\nusername already in use\n");
                create();
            }
    }

int username_verify(char* name_verify)
    {
        DIR* dir = opendir("C:\\Users\\vasuy\\OneDrive\\ATM\\customers");
        char name[150];
        //Sleep(2000);
        strcpy(name, name_verify);
        if(dir == NULL)
            {
                printf("No such directory found...!\n");
            }
        else 
            {
                struct dirent* file;
                file = readdir(dir);
                while(file != NULL)
                    {
                        
                        char name1[150];
                        strcpy(name1, file->d_name);
                        char ch = '.';
                        char *file_name = name1;
                        char name2[150];
                        char *new_name = name2;
                        int i = 0;
                        while(*file_name != ch)
                            {
                                *new_name = *file_name;
                                file_name++;
                                new_name++;
                                i++;
                            }
                            name2[i] = '\0';
                            if(strcmp(name2, name) == 0)
                                {
                                    return 1;
                                }
                        file = readdir(dir); 
                    }
                closedir(dir);              
                
            }
        return 0;
    }
