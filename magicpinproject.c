#include<stdio.h>
#include<string.h>

int upper_case(char pass[],int len)
{
    int i = 0;
    while(pass[i]!='\0')
    {
        if(pass[i]>='A' && pass[i]<='Z')
            return 0;
        else if(i==len)
            return 1;
        i++;
    }
}
int lower_case(char pass[],int len)
{
    int i = 0 ;
    while(pass[i]!='\0')
    {
        if(pass[i]>='a' && pass[i]<='z')
            return 0;
        else if(i==len)
            return 1;
        i++;
    }

}
int number(char pass[],int len)
{
    int i = 0 ;
    while(pass[i]!='\0')
    {
        if(pass[i]>='0' && pass[i]<='9')
            return 0;
        else if(i==len)
            return 1;
        i++;
    }

}
int spec_char(char pass[],int len)
{
    int i = 0 ;
    while(pass[i]!='\0')
    {
        if(pass[i]=='*' || pass[i]=='$'|| pass[i]=='#'|| pass[i]=='='|| pass[i]=='@'|| pass[i]=='_')
            return 0;
        else if(i==len)
            return 1;
        i++;
    }

}
int notspec_char(char pass[],int len)
{
    int i = 0 ;
    while(pass[i]!='\0')
    {
        if(pass[i]=='[' || pass[i]==']'|| pass[i]=='%'|| pass[i]=='!'|| pass[i]==')'||pass[i]=='(')
            return 1;
        else if(i==len)
            return 0;
        i++;
    }

}
void check_pass(char pass[])
{
    int len = strlen(pass),i=0;
    if(len<6)
        printf("%s Failure Password must be at least 6 characters long.\n",pass);
    else if(len>12)
        printf("%s Failure Password must be at max 12 characters long.\n",pass);
    else if(lower_case(pass,len))
        printf("%s Failure Password must contain at least one letter from a-z.\n",pass);
    else if(number(pass,len))
        printf("%s Failure Password must contain at least one letter from 0-9.\n",pass);
    else if(upper_case(pass,len))
        printf("%s Failure Password must contain at least one letter from A-Z.\n",pass);
    else if(spec_char(pass,len))
        printf("%s Failure Password must contain at least one letter from *$_#=@.\n",pass);
    else if(notspec_char(pass,len))
        printf("%s Failure Password cannot contain %!)(.\n",pass);
    else
        printf("%s Success\n",pass);

}

int main()
{
    int i = 0 ,j=0;
    char ptr[1000];
    char token[20];
    scanf("%s",ptr);
    while (ptr[i] != '\0')
    {
        while(ptr[i]!=',')
        {
          token[j] = ptr[i];
          i++;
          j++;
        }
        token[j]='\0';
        check_pass(token);
        j=0;
        i++;
    }
    return 0;
}
