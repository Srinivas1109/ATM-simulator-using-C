#include "atm.h"

void login()
    {
        system("cls");
        char name[50];
        char pin[10];
        char name1[50];
        fflush(stdin);
        printf("\nEnter username:");
        scanf("%s",name);
        printf("\nEnter your PIN: ");
        scanf("%s",pin);
        if(strcmp(name, "admin") == 0)
            admin(name, pin);
        else
        {
            strcpy(name1,name);
            struct customer c;
            char filename[100] = "C:\\Users\\vasuy\\OneDrive\\ATM\\customers\\";
            strcat(filename, name);
            FILE *f;
            f = fopen(strcat(filename, ".dat"),"rb");
            if (f == NULL)
            {
                printf("\033[31m");
                printf("\n                                      **************** Invalid username!!!! ****************");
                Sleep(2000);
                printf("\033[37m");
                printf("\n");
            }
            while(fread(&c,sizeof(c),1,f))
                {
                    if(strcmp(pin , c.pin) == 0 && strcmp(name1, c.username) == 0)
                        {    
                            int n;
                            printf("\033[32m");
                            struct customer c;
                            printf("\n                                                        Login Successful...!");
                            Sleep(2000);
                            printf("\033[37m");
                            system("cls");
                            printf("\n");
                            char ques[100];
                            char ans[100];
                            strcpy(ques, c.question);
                            strcpy(ans, c.answer);
                            while(1)
                                {
                                    printf("\033[37m");
                                    printf("\n                                           ==========================================                                     ");
                                    printf("\033[36m");
                                    printf("\n                                                       Available Options                                                  ");
                                    printf("\033[37m");
                                    printf("\n                                           ==========================================                                     "); 
                                    printf("\033[32m");
                                    printf("\n                                                           [1] Check balance                                              \n");
                                    printf("\033[33m");
                                    printf("                                                           [2] Change PIN                                                 \n");
                                    printf("\033[34m");
                                    printf("                                                           [3] Withdraw                                                   \n");
                                    printf("\033[35m");
                                    printf("                                                           [4] Mini Statement                                             \n");
                                    printf("\033[37m");
                                    printf("                                                           [5] Deposit                                                    \n");
                                    printf("\033[36m");
                                    printf("                                                           [0] Home Page                                                       \n"); 
                                    printf("\033[37m");
                                    printf("                                           ===========================================                                  \n");
                                    printf("Enter your choice: ");
                                    scanf("%d",&n);
                                    printf("\n");
                                    if(n == 0 || n == 1 || n == 2 || n == 3 || n == 4 || n == 5)
                                        {
                                            switch(n)
                                                {
                                                    case 1: {
                                                                fclose(f);
                                                                system("cls");
                                                                balance(name1, pin, ques, ans);
                                                                printf("\033[37m");
                                                                break;
                                                            }   
                                                    case 2: {
                                                                fclose(f);
                                                                system("cls");
                                                                change(name1, pin, ques, ans);
                                                                printf("\033[37m");
                                                                break;
                                                            }
                                                    case 3: {
                                                                fclose(f);
                                                                system("cls");
                                                                withdraw(name1, pin, ques, ans);
                                                                printf("\033[37m");
                                                                break;
                                                            }
                                                    case 4: {
                                                                fclose(f);
                                                                system("cls");
                                                                statement(name1, pin, ques, ans);
                                                                printf("\033[37m");
                                                                break;
                                                            }
                                                    case 5: {
                                                                fclose(f);
                                                                system("cls");
                                                                deposit(name1, pin, ques, ans);
                                                                printf("\033[37m");
                                                                break;
                                                            }
                                                            
                                                    case 0: {
                                                                fclose(f);
                                                                system("cls");
                                                                main();
                                                            }
                                                }
                                        }
                                        else
                                            {
                                                system("cls");
                                                printf("\033[31m");
                                                printf("                                   **********************  Invalid Entry **********************\n");
                                                Sleep(1000);
                                                system("cls");
                                                printf("\033[37m");
                                                printf("\n");
                                                login();
                                            }
                                    

                                }
                        }
                    else
                        {
                            printf("\033[31m");
                            printf("\n                                        ****************** Inavlid PIN...! ******************");
                            Sleep(1000);
                            printf("\033[37m");
                            printf("\n");
                            printf("\n                                        ======================================================");
                            printf("\033[36m");
                            printf("\n                                                         Available Options                    ");
                            printf("\033[37m");
                            printf("\n                                        ======================================================");
                            printf("\033[32m");
                            printf("\n                                                             [1] Retry                             ");
                            printf("\033[35m");
                            printf("\n");
                            printf("\033[34m");
                            printf("\n                                                             [2] Forgot Pin                        ");
                            printf("\n");
                            printf("\033[37m");
                            printf("\033[33m");
                            printf("\n                                                             [0] Home Page                              ");
                            printf("\033[37m");
                            printf("\n                                        ======================================================");
                            int num;
                            printf("\nPlease Enter your choice: ");
                            scanf("%d",&num);
                            switch(num)
                            {
                                case 1: {
                                            fclose(f);
                                            system("cls");
                                            login();
                                            break;
                                        }   
                                case 2: {
                                            printf("\nplease answer for your security question...!\n");
                                            printf("your security question: %s?\n", c.question);
                                            char answer[100];
                                            fflush(stdin);
                                            scanf("%s", answer);
                                            if(strcmp(answer, c.answer) == 0)
                                                {
                                                    printf("\nYour Pin  is %s\n",c.pin);
                                                    Sleep(3000);
                                                }

                                            else
                                                {
                                                    printf("\nsorry you have entered an incorrect answer...!\n");
                                                    printf("\nIn case if you have forgot your answer please contact your bank...!\n");
                                                    printf("\nPress any key");
                                                    char ch = getch();
                                                    break;
                                                }
                                        }
                                case 0: {
                                            fclose(f);
                                            main();
                                        }
                                default: {
                                            printf("\033[31m");
                                            printf("                                       ********************* Invalid choice *********************");
                                            Sleep(1000);
                                            printf("\033[37m");
                                            break;
                                        }
                            }
                            printf("\n");
                        }
                
                }
            fclose(f);
        }
    }
