#include <stdio.h>
#include "file.h"
#include<string.h>
#include<stdlib.h>

void saveContactsToFile(AddressBook *addressBook)//function to save contacts to file 
{
  FILE *fptr = fopen("contact.csv","w");// Opening file in write mode
  fprintf(fptr,"%d\n",addressBook->contactCount   );// Writing the contact count to the file
  for(int i=0;i<addressBook->contactCount && addressBook->contactCount<MAX_CONTACTS;i++)
  {
    fprintf(fptr,"%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);// Writing each contact's details in CSV file 
  }
  fclose(fptr);
}

void loadContactsFromFile(AddressBook *addressBook)//function to load contacts from file 
{
    FILE *fptr = fopen("contact.csv","r");// Opening file in read mode
    fscanf(fptr,"%d",&addressBook->contactCount);
    for(int i=0;i<addressBook->contactCount && i<=MAX_CONTACTS;i++)
    {
        fscanf(fptr,"\n%[^,],%[^,],%[^\n]\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);// Reading each contact's details from CSV file
    }
    fclose(fptr);
    
}
