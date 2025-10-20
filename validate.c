#include "contact.h"
#include<string.h>

int validate_phone(AddressBook *addressBook,char *ph)//function to validate phone number
{
    if(strlen(ph) == 10 )// Check if phone number length is 10
    {
        for(int i=0;i<10;)
        {
            if(ph[i]>=48 && ph[i]<=57)// Check if each character is a digit
            {
                i++;
            }
            else
            {
                return 0;
            }
        }
        int j;
        for(j=0;j<10;)
        {
            if(strcmp(addressBook->contacts[j].phone,ph) != 0)// Check for duplicate phone numbers
            {
                j++;
            }
            else
            {
                return 0;
            }
        }
        if(j==10)
        {
            return 1;
        }
    }
    return 0;
}

int validate_name(AddressBook *addressBook,char *name)//function to validate name
{
    int i;
     for(i=0;i<strlen(name);)
     {
        if(name[i]==' ' || name[i]>=65 && name[i]<=90 || name[i]>=97 && name[i]<=122)// Check if each character is a letter or space
        {
            i++;
        }
        else
        {
            return 0;
        }
     }
     if(i == strlen(name))// If all characters are valid, return 1
     {
        return 1;
     }
}

int validate_email(AddressBook *addressBook,char *mail)//function to validate email
{
    int flag=0;
    for(int i=0;i<strlen(mail);i++)
    {
        if(mail[i] == '@')// Check for presence of '@' character
        {
            if(i != 0)// Ensure '@' is not the first character
            {
                if(mail[i+1] != '.')// Check that '@' is not the first character and is not followed by '.' 
                {
                    for(int j=i+1;j<strlen(mail);j++)
                    {
                        if(mail[j] == '.')// Check for presence of '.' character after '@'
                        {
                            if(mail[j+1] != '\0')// Check that '.' is not the last character
                            {
                                flag=1;
                                break;
                            }
                            else
                            {
                                return 0;
                            }
                        }
                    }
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                return 0;
            }
        }
    }
    if(flag == 0)
    {
        return 0;
    }

    if(flag == 1)
    {
        for(int i=0;i<strlen(mail);i++)
        {
            if(mail[i]>=65 && mail[i]<=90)//check for uppercase letters
            {
                return 0;
            }
        }

        for(int i=0;i<addressBook->contactCount;i++)
        {
            if(strcmp(addressBook->contacts[i].email,mail)==0)// Check for duplicate emails
            {
                return 0;
            }
        }
        int count=0;
        for(int i=0;i<strlen(mail);i++)
        {
            if(mail[i]=='@' || mail[i]=='.' || (mail[i]<97 && !(mail[i]>=48 && mail[i]<=57)) || mail[i]>122)// Check for invalid characters
            {
                count++;
            }
        }
        if(count>2)
        {
            return 0;
        }

        int flag1=0;
        for(int i=0;i<strlen(mail);i++)
        {
            if(mail[i] ==' ')// Check for spaces in email
            {
                flag1=1;
            }
        }
        if(flag1 == 0)
        {
            return 1; 
        }
        else
        {
            return 0;
        }
    }
}