#include <stdio.h>

int strEqual(char a[], char b[])
{
    int i=0;
    while(a[i] != '\0' && b[i] != '\0')
    {
        if(a[i] != b[i])
        {
            return 0;
        }
        i++;
    }
    return a[i]=='\0' && b[i]=='\0';
}

int strToInt(char s[])
{
    int num=0;
    int i=0;
    while(s[i]!='\0')
    {
        num = num*10+(s[i]-'0');
        i++;
    }
    return num;
}

int main() {
    int accno=401;
    int pin=5555;
    int adminPin=9999;
    int balance=60000;
    
    int frozen=0;
    int failedAttempts=0;
    int withdrawInHour=0;
    int withDrawCount=0;
    
    char input[200];
    scanf("%s", input);
    
    if(strEqual(input, "Admin"))
    {
        int a_pin;
        scanf("%d", &a_pin);
        
        if(a_pin!=adminPin)
        {
            printf("Invalid admin id\n");
            return 0;
        }
        
        char cmd[200];
        int ad_acc;
        scanf("%s", cmd);
        scanf("%d", &ad_acc);
        
        if(strEqual(cmd,"Reset") && ad_acc==accno)
        {
            frozen=0;
            failedAttempts=0;
            withDrawCount=0;
            withdrawInHour=0;
            printf("Account Frozen");
        }
        return 0;
    }
    
    int u_acc = strToInt(input);
    if(u_acc!=accno)
    {
        printf("Invalid Account Number\n");
        return 0;
    }
    
    int pin_in;
    int success=0;
    
    while(failedAttempts<3)
    {
        scanf("%d", &pin_in);
        
        if(pin_in==pin)
        {
            success=1;
            printf("Login successful\n");
            break;
        }
        else
        {
            failedAttempts++;
            if(failedAttempts==3)
            {
                printf("Alert: Multiple Failed Attempts");
                return 0;
            }
        }
    }
    
    if(!success) return 0;
    
    if(frozen)
    {
        printf("Account Frozen");
        return 0;
    }
    
    char action[20];
    
    while(scanf("%s",action) != EOF)
    {
        if(strEqual(action, "Withdraw"))
        {
            int amount;
            scanf("%d", &amount);
            
            if(amount<=0)
            {
                printf("Invalid Amount\n");
                continue;
            }
            
            withdrawInHour++;
            withDrawCount += amount;
            
            if(withDrawCount>25000)
            {
                frozen = 1;
                printf("Account Frozen\n");
                break;
            }
            
            if(withdrawInHour>3)
            {
                printf("Suspicious Activity\n");
                continue;
            }
            
            if(amount>balance)
            {
                printf("Insufficient Balance\n");
                continue;
            }
            
            balance -= amount;
            printf("Withdraw Successful\n");
        }
    }
     return 0;
}

