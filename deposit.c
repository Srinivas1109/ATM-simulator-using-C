#include "atm.h"

void deposit(char name[], char pin[], char ques[], char ans[])
    {
            char name_d[50];
            char name_dd[50];
            char pin_dd[20];
            int user_amt;
            struct customer c;
            strcpy(name_d, name);
            strcpy(name_dd, name);
            strcpy(pin_dd, pin);
            char filename[100] = "C:\\Users\\vasuy\\OneDrive\\ATM\\customers\\";
            strcat(filename, name_d);
            int thous, fives, twos, hunds, fiftys;
            FILE *f;
            f = fopen(strcat(filename,".dat"),"rb");
            if (f == NULL)
                {
                    printf("\033[31m");  // red
                    printf("\n                                 ******************** user not found...! **********************");
                    Sleep(2000);
                    system("cls");
                    printf("\033[37m");  // white
                    printf("\n");
                }
            while(fread(&c,sizeof(c),1,f))
                {
                    
                    int balance;
                    int amt;
                    c.i =  c.i + 1;
                    printf("\033[36m"); // light blue
                    printf("                     Enter amount only in multiples of 50's (or) 100's (or) 200's (or) 500's (or) 2000's\n");
                    printf("\033[37m"); // white
                    printf("\nEnter amount to be deposited: ");
                    scanf("%d",&amt);
                    user_amt = amt;
                       
                    if (amt < 0)
                        {
                            printf("\033[31m");
                            printf("\n                                  ****************** Enter a valid amount...! ********************");
                            Sleep(2000);
                            system("cls");
                            printf("\033[37m");
                            printf("\n");
                        }
                    else
                        {
                        
                            if(amt%50 == 0)
                                {
                                    
                                    struct atm a;
                                        char str3[10];
                                        char str2[10] = ": ";
                                        char str[120] = "Statement ";
                                        char time1[30];
                                        char str4[20] = " Rs credited on ";
                                        char str1[10];
                                        int aa = 0,b = 0,cc = 0,d = 0,e = 0,a1 = 0,b1 = 0,c1 = 0,d1 = 0;
                        
                                         
                                        if(user_amt >= 2000 )
                                                {
                                                    a1 = user_amt%2000;
                                                    aa = (user_amt - a1)/2000;
                                                    user_amt = a1;
                                                }
                                        if((user_amt >= 500 || a1 >= 500))
                                            {
                                                b1 = user_amt%500;
                                                b = (user_amt - b1)/500;
                                                user_amt = b1;
                                            }
                                        if((user_amt >= 200 || b1 >= 200))
                                            {
                                                c1 = user_amt%200;
                                                cc = (user_amt - c1)/200;
                                                user_amt = c1;
                                            }
                                        if((user_amt >= 100 || c1 >= 100))
                                            {
                                                d1 = user_amt%100;
                                                d = (user_amt - d1)/100;
                                                user_amt = d1;
                                            }
                                        if((user_amt >= 50 || c1 >= 50))
                                            {
                                                e = user_amt/50;
                                            }
                                           
                                    
                                    if(amt == ((aa*2000) + (b*500) + (cc*200) + (d*100) + (e*50)))
                                        {
                                            FILE *fp;
                                            fp = fopen("C:\\Users\\vasuy\\OneDrive\\ATM\\customers\\temp.dat","ab");
                                            sprintf(str1, "%d", c.i);
                                            strcpy(c.username, name_dd);
                                            strcpy(c.pin, pin_dd);
                                            c.balance = c.balance + amt;
                                            totaladd(aa, b, cc, d, e);
                                            time_t now;
                                            time(&now);
                                            strcpy(time1, ctime(&now));
                                            sprintf(str3, "%d", amt);
                                            strcat(str,str1);
                                            strcat(str,str2);
                                            strcat(str,str3);
                                            strcat(str, str4);
                                            strcat(str, time1);
                                            strcat(c.date_time,str);
                                            strcat(c.statement[c.i], str);
                                            strcpy(c.question, ques);
                                            strcpy(c.answer, ans);
                                            fwrite(&c,sizeof(c),1,fp);
                                            fclose(fp);
                                            printf("\033[36m");
                                            printf("\n                                        Amount of Rs %d.00 is credited successfully...!",amt);
                                            printf("\n");
                                            printf("\033[33m");
                                            printf("\n                                        Remaining amount in your account Rs %d.00",c.balance);
                                            printf("\n");
                                            fclose(f);
                                            remove(filename);
                                            rename("C:\\Users\\vasuy\\OneDrive\\ATM\\customers\\temp.dat",filename);
                                        }
                                    else
                                        {
                                            printf("\033[31m");  // red
                                            printf("                                          Enter correct Denominations...!\n");
                                            printf("\033[37m");  // white
                                        }
                                    
                                        
                                }
                            else
                                {
                                    printf("\033[31m");  // red
                                    printf("                           Enter amount only in multiples of 50's (or) 100's (or) 200's (or) 500's (or) 2000's\n"); 
                                    printf("\033[37m");  // white
                                }  
                        }
            
                }
        fclose(f);
   
    }