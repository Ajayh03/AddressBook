#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"

void listContacts(AddressBook *addressBook, int sortCriteria) // Function to list contacts with sorting options
{
    // Sort contacts based on the chosen criteria
    if (sortCriteria == 1) // Sort by name
    {
        //Bubble sort logic
        for(int i=0;i<addressBook->contactCount-1;i++)
        {
            for(int j=0;j<addressBook->contactCount-i-1;j++)
            {
                if(strcmp(addressBook->contacts[j].name,addressBook->contacts[j+1].name) >0 )// Comparing two names
                {
                     addressBook->temp[0] = addressBook->contacts[j];
                     addressBook->contacts[j] = addressBook->contacts[j+1];
                     addressBook->contacts[j+1] = addressBook->temp[0];
                }
            }
        }

    }

    else if(sortCriteria == 2) // Sort by phone
    {
        //Bubble sort logic
        for(int i=0;i<addressBook->contactCount-1;i++)
        {
            for(int j=0;j<addressBook->contactCount-i-1;j++)
            {
                if(strcmp(addressBook->contacts[j].phone,addressBook->contacts[j+1].phone) >0 )// Comparing two phone numbers
                {
                     addressBook->temp[0] = addressBook->contacts[j];
                     addressBook->contacts[j] = addressBook->contacts[j+1];
                     addressBook->contacts[j+1] = addressBook->temp[0];
                }
            }
        }
    }

    else if(sortCriteria == 3) // Sort by email
    {
        //Bubble sort logic
        for(int i=0;i<addressBook->contactCount-1;i++)
        {
            for(int j=0;j<addressBook->contactCount-i-1;j++)
            {
                if(strcmp(addressBook->contacts[j].email,addressBook->contacts[j+1].email) >0 )// Comparing two emails
                {
                     addressBook->temp[0] = addressBook->contacts[j];
                     addressBook->contacts[j] = addressBook->contacts[j+1];
                     addressBook->contacts[j+1] = addressBook->temp[0];

                }
            }
        }
    }
   
    else if(sortCriteria == 4) // Normal method
    {
        //Not any Sorting 
        //Move to next line and just print
    }
    printf("   Name                 phone                 email \n");
        printf("---------------------------------------------------------------\n");
        printf("\n");
        for(int i=0;i<(addressBook->contactCount);i++)
        {
            printf("%-20s %10s        %-s",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
            printf("\n \n");
        }
        printf("---------------------------------------------------------------\n");    
}

 void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    //populateAddressBook(addressBook);
    
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook) //function to create a contact
{
	/* Define the logic to create a Contacts */
    char nm[50];
    skip1:
    printf("Enter the name : ");
    getchar();
    scanf("%[^\n]",nm);
    int ret = validate_name(addressBook,nm);// Function call to validate name
    if(ret ==1)
    {
        strcpy(addressBook->contacts[addressBook->contactCount].name,nm);// Copying name to structure
    }
    else
    {
        printf("Invalid name !!\n");
        goto skip1;// If name is invalid, ask for input again
    }
  
    
    char ph[50];
    skip2:
    printf("Enter the phone number : ");
    getchar();
    scanf("%[^\n]",ph);
    int ret1 = validate_phone(addressBook,ph);// Function call to validate phone number
    if(ret1 == 1)
    {
        strcpy(addressBook->contacts[addressBook->contactCount].phone,ph);// Copying phone number to structure
    }
    else
    {
        printf("Invalid phone !!\n");
        goto skip2;// If phone number is invalid, ask for input again
    }

    char mail[50];
    skip3:
    
    printf("Enter the email : ");
    getchar();
    scanf("%[^\n]",mail);
    int ret2 = validate_email(addressBook,mail); // Function call to validate email
    if(ret2 == 1)
    {
        strcpy(addressBook->contacts[addressBook->contactCount].email,mail);// Copying email to structure
    }
    else
    {
        printf("Invalid email !!\n");
        goto skip3; // If email is invalid, ask for input again
    } 

    addressBook->contactCount++;// Increment contact count after adding a new contact
}

int searchContact(AddressBook *addressBook) //function to search a contact
{
    /* Define the logic for search */
    int sr;
    printf("1. Search by name\n");
    printf("2. Search by phone number\n");
    printf("3. Search by mail\n");
    scanf("%d",&sr);

    if(sr == 1)// Search by name
    {
       char name[50];
       int i,flag=0; 
       printf("Enter the name : ");
       getchar(); 
       scanf("%[^\n]",name);
       for(i=0;i<addressBook->contactCount;i++)
       {
        if(strcmp(addressBook->contacts[i].name,name) == 0)// Comparing two names
        {
            flag=1;
            printf("Index : %d\n",i);
            printf("Name : %s\n",addressBook->contacts[i].name);    // If name matches, print the contact details
            printf("Phone : %s\n",addressBook->contacts[i].phone);
            printf("Email : %s\n",addressBook->contacts[i].email);
            printf("\n");

        }
       }
        if(flag == 0)
        {
            printf("NAME NOT FOUND!!");// If no match found, print not found message
            return 0;
        }
        else
        {
             return 1;
        }
    }
    
    if(sr == 2)// Search by phone number
    {
        char ph[20];
        int i=0,flag=0;
        printf("Enter the phone number : ");
        getchar();
        scanf("%[^\n]",ph);
        for(i=0;i<addressBook->contactCount;i++)
        {
            if(strcmp(addressBook->contacts[i].phone,ph)==0)// Comparing two phone numbers
            { 
                flag=1;
                printf("Index : %d\n",i);
                printf("Name : %s\n",addressBook->contacts[i].name);// If phone number matches, print the contact details
                printf("Phone : %s\n",addressBook->contacts[i].phone);
                printf("Email : %s\n",addressBook->contacts[i].email);
                printf("\n");
            }
        }
        if(flag == 0)
        {
            printf("PHONE NUMBER NOT FOUND!!");// If no match found, print not found message
            return 0;
        }
        else
        {
             return 1;
        }
    }
    if(sr == 3)// Search by email
    {
        char mail[50];
        int i=0,flag=0;
        printf("Enter the mail : ");
        getchar();
        scanf("%[^\n]",mail);

        for(i=0;i<addressBook->contactCount;i++)
        {
            if(strcmp(addressBook->contacts[i].email,mail) == 0)// Comparing two emails
            {
                flag=1;
                printf("Index : %d\n",i);
                printf("Name : %s\n",addressBook->contacts[i].name);// If email matches, print the contact details
                printf("Phone : %s\n",addressBook->contacts[i].phone);
                printf("Email : %s\n",addressBook->contacts[i].email);
                printf("\n");
                
            }
        }
        if(flag == 0)
        {
            printf("EMAIL NOT FOUND!!");// If no match found, print not found message
            return 0;
        }
        else
        {
             return 1;
        }       
    }

}    

void editContact(AddressBook *addressBook)//function to edit a contact
{
	/* Define the logic for Editcontact */
    int ret = searchContact(addressBook);
    if(ret == 1)
    {
       int index;
       printf("Enter the index which want to edit : ");// Index of the contact to be edited
       scanf("%d",&index);
       int num;
       printf("1 .Edit name\n");
       printf("2 .Edit phone number\n");
       printf("3 .Edit mail\n");
       scanf("%d",&num);
       
       if(num == 1)
       {
        char name[50];
        skip1:
        printf("Enter the name to edit : ");
        getchar();
        scanf("%[^\n]",name);
        int ret1 = validate_name(addressBook,name);// Function call to validate name
        if(ret1 == 1)
        { 
           strcpy(addressBook->contacts[index].name,name);// Copying new name to structure
        }
        else
        {
            printf("Invalid name!!\n");
            goto skip1;// If name is invalid, ask for input again
        }
       }
       
       if(num == 2)
       {
        char phone[50];
        skip2:
        printf("Enter the phone no to edit : ");
        getchar();
        scanf("%[^\n]",phone);
        int ret2 = validate_phone(addressBook,phone);// Function call to validate phone number
        if(ret2 == 1)
        {
           strcpy(addressBook->contacts[index].phone,phone);// Copying new phone number to structure
        }
        else
        {
            printf("Invalid phone!!\n");
            goto skip2;// If phone number is invalid, ask for input again
        }
       }

       if(num == 3)
       {
        char mail[50];
        skip3:
        printf("Enter the mail to edit : ");
        getchar();
        scanf("%[^\n]",mail);
        int ret3 = validate_email(addressBook,mail);// Function call to validate email
        if(ret3 == 1)
        {
          strcpy(addressBook->contacts[index].email,mail);// Copying new email to structure
        }
        else
        {
            printf("Invalid email!!\n");
            goto skip3;// If email is invalid, ask for input again
        }
       }

    }

    
}

void deleteContact(AddressBook *addressBook)//function to delete a contact
{
	/* Define the logic for deletecontact */
    int ret = searchContact(addressBook);// Search for the contact to be deleted
    if(ret == 1)
    {
        int index;
        printf("Enter the index to delete : ");
        scanf("%d",&index);
        
        for(int i=index;i<addressBook->contactCount-1;i++)
        {
            addressBook->contacts[i] = addressBook->contacts[i+1];
        }
        addressBook->contactCount--;// Decrement contact count after deleting a contact
    }  
}
