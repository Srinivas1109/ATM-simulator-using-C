#include<stdio.h>
#include<time.h>

struct atm
    {
        int amount;
        int thous;
        int fives;
        int twos;
        int hunds;
        int fiftys;

    };

struct customer
    {
        float balance;
        char pin[10];
        char username[10];
        char date_time[9000];
        int i;
        char statement[1000][150];   
    };

void user_demonitions(int);
void display();
void withdraw();

int main()
    {
        //printf("%d\n", 88888800/2000);
        struct atm a;
        printf("Enter the amount: ");
        int user_amt;
        scanf("%d", &user_amt);
        user_demonitions(user_amt);
        
        return 0;

    }

void user_demonitions(int user_amt)
    {
        FILE *f;
        struct atm a;
        display();
        f = fopen("C:\\Users\\vasuy\\OneDrive\\ATM\\totalamount\\totalamount.dat", "rb");
        while(fread(&a, sizeof(a), 1, f))
            {

                if(user_amt%50 == 0)
                    {
                        int aa,b,c,d,e,a1 = 0,b1 = 0,c1 = 0,d1 = 0;
                        printf("\nuser amount: %d\n", user_amt);
                        printf("\nuser demonitions: \n");
                        if(user_amt >= 2000 && a.thous != 0)
                            {
                                a1 = user_amt%2000;
                                aa = (user_amt - a1)/2000;
                                user_amt = a1;
                                printf("no. of 2000's are %d\n",aa);
                            }
                        if((user_amt >= 500 || a1 >= 500) && a.fives != 0 )
                            {
                                b1 = user_amt%500;
                                b = (user_amt - b1)/500;
                                printf("no. of 500's are %d\n",b );
                                user_amt = b1;
                            }
                        if((user_amt >= 200 || b1 >= 200) && a.twos != 0 )
                            {
                                c1 = user_amt%200;
                                c = (user_amt - c1)/200;
                                printf("no. of 200's are %d\n",c );
                                user_amt = c1;
                            }
                        if((user_amt >= 100 || c1 >= 100) && a.hunds != 0 )
                            {
                                d1 = user_amt%100;
                                d = (user_amt - d1)/100;
                                printf("no. of 100's are %d\n",d );
                                user_amt = d1;
                            }
                        if((user_amt >= 50 || c1 >= 50) && a.fiftys != 0 )
                            {
                                e = user_amt/50;
                                printf("no. of 50's are %d\n",e );
                            }
                        
                    }
                else
                    printf("Enter amount in multiples of 50's (or) 100's (or) 200's (or) 500's (or) 2000's\n");
            }
        fclose(f);
        
    }

void display()
    {
        FILE *f;
        struct atm a;
        f = fopen("C:\\Users\\vasuy\\OneDrive\\ATM\\totalamount\\totalamount.dat", "rb");
        while(fread(&a, sizeof(a), 1, f))
            {
                printf("total amount is %d\n",a.amount);
                printf("no. of 2000's are %d\n",a.thous);
                printf("no. of 500's are %d\n",a.fives );
                printf("no. of 200's are %d\n",a.twos);
                printf("no. of 100's are %d\n",a.hunds );
                printf("no. of 50's are %d\n",a.fiftys);
            }
        fclose(f);
    }

