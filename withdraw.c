#include "atm.h"

void withdraw(char name[], char pin[], char ques[], char ans[])
    {
        char name_w[50];
        char name_ww[50];
        char pin_ww[20];
        struct customer c;
        struct atm a;
        strcpy(name_w, name);
        strcpy(name_ww, name);
        strcpy(pin_ww, pin);
        char filename[100] = "C:\\Users\\vasuy\\OneDrive\\ATM\\customers\\";
        strcat(filename, name_w);
        int user_amt;
        printf("\nEnter amount to be withdraw: ");
        scanf("%d",&user_amt);
        int amt = user_amt;
        int atm_amt = transfer();
        FILE *f;
        f = fopen(strcat(filename,".dat"),"rb");
        if (f == NULL)
            {
                printf("\033[32m");
                printf("\n                                 ******************** user not found...! **********************");
                printf("\n");
            }
        while(fread(&c,sizeof(c),1,f))
            {
                if(user_amt > atm_amt)
                    {
                        system("cls");
                        printf("\033[33m");
                        printf("\n                                   sorry for the Inconvenience, Insufficient balance in ATM...!"); 
                        Sleep(2000);
                        printf("\033[37m");
                        system("cls");
                        printf("\n"); 
                    }
                else
                    {
                        if (user_amt > c.balance)
                            {
                                system("cls");
                                printf("\033[31m");
                                printf("\n                                  ****************** Insufficient balance...! ********************");
                                Sleep(2000);
                                system("cls");
                                printf("\033[37m");
                                printf("\n");
                            }
                        else
                            {
                                if(user_amt%50 == 0)
                                    {
                                        char str1[10];
                                        char str2[10] = ": ";
                                        char str[120] = "Statement ";
                                        char time1[30];
                                        char str4[20] = " Rs Debited on ";
                                        char str3[10];
                                        int aa = 0,b = 0,cc = 0,d = 0,e = 0,a1 = 0,b1 = 0,c1 = 0,d1 = 0;
                                        FILE *f1;
                                        f1 = fopen("C:\\Users\\vasuy\\OneDrive\\ATM\\totalamount\\totalamount.dat", "rb");
                                        while(fread(&a, sizeof(a), 1, f1))
                                            {
                                                
                                                if(user_amt >= 2000 && a.thous != 0)
                                                        {
                                                            a1 = user_amt%2000;
                                                            aa = (user_amt - a1)/2000;
                                                            user_amt = a1;
                                                        }
                                                if((user_amt >= 500 || a1 >= 500) && a.fives != 0 )
                                                    {
                                                        b1 = user_amt%500;
                                                        b = (user_amt - b1)/500;
                                                        user_amt = b1;
                                                    }
                                                if((user_amt >= 200 || b1 >= 200) && a.twos != 0 )
                                                    {
                                                        c1 = user_amt%200;
                                                        cc = (user_amt - c1)/200;
                                                        user_amt = c1;
                                                    }
                                                if((user_amt >= 100 || c1 >= 100) && a.hunds != 0 )
                                                    {
                                                        d1 = user_amt%100;
                                                        d = (user_amt - d1)/100;
                                                        user_amt = d1;
                                                    }
                                                if((user_amt >= 50 || c1 >= 50) && a.fiftys != 0 )
                                                    {
                                                        e = user_amt/50;
                                                    }
                                            }
                                                fclose(f1);
                                                c.i =  c.i + 1;
                                                FILE *fp;
                                                fp = fopen("C:\\Users\\vasuy\\OneDrive\\ATM\\customers\\temp.dat","ab");
                                                strcpy(c.username, name_ww);
                                                strcpy(c.pin, pin_ww);
                                                strcpy(c.question, ques);
                                                strcpy(c.answer, ans);
                                                c.balance = c.balance - amt;
                                                totalsub(aa, b, cc, d, e);
                                                time_t now;
                                                time(&now);
                                                strcpy(time1, ctime(&now));
                                                sprintf(str1,"%d",c.i);
                                                sprintf(str3, "%d", amt);
                                                strcat(str, str1);
                                                strcat(str,str2);
                                                strcat(str,str3);
                                                strcat(str,str4);
                                                strcat(str, time1);
                                                strcat(c.statement[c.i], str);
                                                strcat(c.date_time,str);
                                                fwrite(&c,sizeof(c),1,fp);
                                                fclose(fp);
                                                printf("\033[33m");
                                                printf("\n                                        Transaction of Rs %d.00 is completed successfully...!",amt);
                                                printf("\n");
                                                printf("\033[36m");
                                                printf("\n                                        Remaining amount in your account Rs %d.00",c.balance);
                                                printf("\n");
                                                fclose(f);
                                                remove(filename);
                                                rename("C:\\Users\\vasuy\\OneDrive\\ATM\\customers\\temp.dat",filename);
                                            
                                    }
                                else
                                    {
                                        system("cls");
                                        printf("\033[31m");
                                        printf("\n                          Enter amount in multiples of 50's (or) 100's (or) 200's (or) 500's (or) 2000's\n");
                                        Sleep(3000);
                                        system("cls");
                                        printf("\033[37m");
                                        printf("\n");
                                    }
                            }
                    }

            }
        fclose(f);

    }