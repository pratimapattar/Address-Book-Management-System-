#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

void listContacts(AddressBook *addressBook, int sortCriteria) 
{
    Contact temp;
    printf("\n📋 Contact List:\n");
    printf("-------------------------------------------------------------\n");
    printf("%-20s %-15s %-30s\n", "Name", "Phone", "Email");
    printf("-------------------------------------------------------------\n");
    for(int i = 0; i < addressBook->contactCount; i++)
    {
        printf("%-20s %-15s %-30s\n",
            addressBook->contacts[i].name,
            addressBook->contacts[i].phone,
            addressBook->contacts[i].email);
    }
    printf("\n🔽 Sorting By Names...\n");

    // Sorting
    for(int i = 0; i < addressBook->contactCount - 1; i++)
    {
        for(int j = 0; j < addressBook->contactCount - i - 1; j++)
        {
            if(strcmp(addressBook->contacts[j].name,
                      addressBook->contacts[j+1].name) > 0)
            {
                temp = addressBook->contacts[j];
                addressBook->contacts[j] = addressBook->contacts[j+1];
                addressBook->contacts[j+1] = temp;
            }
        }
    }

    printf("\n✅ Sorted Contact List:\n");
    printf("-------------------------------------------------------------\n");
    printf("%-20s %-15s %-30s\n", "Name", "Phone", "Email");
    printf("-------------------------------------------------------------\n");

    for(int i = 0; i < addressBook->contactCount; i++)
    {
        printf("%-20s %-15s %-30s\n",
            addressBook->contacts[i].name,
            addressBook->contacts[i].phone,
            addressBook->contacts[i].email);
    }

    printf("✔ Contacts listed successfully\n");
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


void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */
    char phone_num[50];
    char email_id[50];
    printf("👤 Enter the name:");
    scanf(" %[^\n]", addressBook->contacts[addressBook->contactCount].name);
    while(1)
    {
     printf(" 📞 Enter the phone number:");
     getchar();
     scanf("%[^\n]",phone_num);
     if(validate_phone_num(addressBook,phone_num))
     {
        strcpy(addressBook->contacts[addressBook->contactCount].phone,phone_num);
        break;
     }
       else
       {
        printf("❌ Invalid phone number\n");
        printf("🔁 Please enter valid phone number\n");
       }
    }

    while(1)
    {


        printf("📧 Enter the your email id:");
        scanf(" %[^\n]",email_id);
        if(validate_email_id(addressBook,email_id))
        {
            strcpy(addressBook->contacts[addressBook->contactCount].email,email_id);
            break;
        }
        else
        {
            printf("❌ Invalid email id\n");
            printf("🔁 Please enter valid email id\n");
        }
    }

    addressBook->contactCount++;
   printf("✅ Contact is created sucessfully\n");
}
int validate_phone_num(AddressBook *addressBook,char *phone_num)
{
    int len=0;
    int ind=0;
    while(phone_num[ind] != '\0')
    {
        if(phone_num[ind] <'0'||phone_num[ind]>'9')
        {
            return 0;
        }
        len++;
        ind++;
    }
    if(len != 10)
    {
        return 0;
    }
    for(int i=0;i<addressBook->contactCount;i++)
    {
        if(strcmp(addressBook->contacts[i].phone,phone_num)==0)
        {
            printf("😊 Phone number already exist\n");
            return 0;
        }
    }
    return 1;
}   
int validate_email_id(AddressBook *addressBook,char* email_id)
{
    int i = 0;
    int at_count = 0, dot_count = 0;
    int at_pos = 0, dot_pos = 0;

    while(email_id[i] != '\0')
    {
        if(email_id[i] == '@')
        {
            at_count++;
            at_pos = i;
        }
        if(!((email_id[i] >= 'a' && email_id[i] <= 'z') || (email_id[i] >= 'A' && email_id[i] <= 'Z') || (email_id[i] >= '0' && email_id[i] <= '9') || email_id[i] == '.' || email_id[i] == '_' || email_id[i] == '@'))
        {
            return 0;
        }
        if(email_id[i] == '.' && email_id[i+1] == '.')
        {
            return 0;
        }
        if(email_id[i] == '.' && i > at_pos)
        {
          dot_count++;
          dot_pos = i;
        }
        i++;
    }
    if(email_id[0]=='.')
    {
        return 0;
    }
    if(at_count != 1)
    {
        return 0;
    }
    if(at_pos == 0 || at_pos == i-1)
    {
        return 0;
    }
    if(email_id[at_pos - 1]=='.')
    {
        return 0;
    }
    if(email_id[at_pos + 1]=='.')
    {
        return 0;
    }
    //dot should NOT be immediately after '@'
    if(dot_pos == at_pos + 1)
    {
         return 0;
    }

    if(email_id[i-1] =='.')
    {
        return 0;
    }
    if(at_pos > dot_pos)
    {
        return 0;
    }
    // email should not end with '.'
    if(email_id[i-1] == '.')
    {
         return 0;
    }
    for(int i=0;i<addressBook->contactCount;i++)
    {
        if(strcmp(addressBook->contacts[i].email,email_id)==0)
        {
            printf("😊 Email already exist\n");
            return 0;
        }
    }
    return 1;
}

int searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
    //printing the menu for the user
    printf("\n🔍 what to search:\n");
    printf("1️⃣. Search by name\n");
    printf("2️⃣. Search by Phone\n");
    printf("3️⃣. Search by email\n");
    printf("\n");

    //Reading the choice from user
    int choice,i=-1;
    printf("👉 Enter your choice:");
    scanf(" %d",&choice);

    // Calling the function based on user input
   switch(choice)
    {
        case 1:
        i = Search_by_name(addressBook);
        break;

        case 2:
        i=Search_by_phonenum(addressBook);
        break;

        case 3:
        i=Search_by_email(addressBook);
        break;

        default:
        printf("❌ Invalid choice. Please try again.\n");
    }
   return i;
}
int Search_by_name(AddressBook *addressBook)
{
    char name[50];
    printf("😎 Enter the name to search:");
    scanf(" %[^\n]", name);

    int found_indexes[100];
    int count = 0;

    for(int i = 0; i < addressBook->contactCount; i++)
    {
        if(strcmp(name, addressBook->contacts[i].name) == 0)
        {
            printf("👉 [%d] %s\t%s\t%s\n", i,
                addressBook->contacts[i].name,
                addressBook->contacts[i].phone,
                addressBook->contacts[i].email);

            found_indexes[count++] = i;
        }
    }

    // ❌ NO MATCH
    if(count == 0)
    {
        printf("😩 Contact is not found\n");
        return -1;
    }

    // ✅ MULTIPLE MATCHES
    if(count > 1)
    {
        int choice;
        printf("⚠️ Multiple contacts found. Enter index to select: ");
        scanf("%d", &choice);

        return choice;   
    }

    // ✅ SINGLE MATCH
    return found_indexes[0];  
}

int Search_by_phonenum(AddressBook *addressBook)
{
    char num[50];
    printf("😎 Enter the number to search:");
    scanf(" %[^\n]",num);

    int flag=0,i;
    for(i=0 ; i < addressBook->contactCount ; i++)
    {
        if(strcmp(num, addressBook->contacts[i].phone) == 0)
        {
            flag=1;
            break;
        }
    }
    if(flag == 1)
    {
        printf("🎯 Contact is found at %d\n",i);
        printf("%s\t\t\t%s\t\t\t%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    else
    {
        printf("😩 Contact is not found\n");
        return -1;
    }
     return i;

}
int Search_by_email(AddressBook *addressBook)
{
    char email_id[50];
    printf("😎 Enter the email to search:");
    scanf(" %[^\n]",email_id);

    int flag=0,i;
    for(i=0 ; i < addressBook->contactCount ; i++)
    {
        if(strcmp(email_id, addressBook->contacts[i].email) == 0)
        {
            flag=1;
            break;
        }
    }
    if(flag == 1)
    {
        printf("🎯 Contact is found at %d\n",i);
        printf("%s\t\t\t%s\t\t\t%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    else
    {
        printf("😩 Contact is not found\n");
        return -1;
    }
     return i;

}
void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
    // Calling the search contact function
    int i;
    int ret=searchContact(addressBook);
    if(ret== -1)
    {
        printf("😫 Edit contact failure");
        return;
    }

    // Asking the user to enter the index to edit contacts
    printf("😃 Enter the index to edit:");
    scanf("%d",&i);

    // Printing the menu for the user
    printf("\n ✏️ Edit Menu:\n");
    printf("1.Edit by name\n");
    printf("2.Edit by Phone\n");
    printf("3.Edit by email\n");
    printf("\n");

    int choice,index=-1;
    printf("👉 Enter your choice:");
    scanf("%d",&choice);

    // Calling the function based on user input
    switch(choice)
    {
        case 1:
        index=edit_by_name(addressBook,ret);
        break;

        case 2:
        index=edit_by_phonenum(addressBook,ret);
        break;

        case 3:
        index=edit_by_email(addressBook,ret);
        break;

        default:
        printf("❌ Invalid choice. Please try again.\n");
    }

    if(index==-1)
    {
       printf("🙁 Editing contact failure\n");
    }
    
}
int edit_by_name(AddressBook *addressBook,int index)
{
    char new_name[50];
    printf("😊 Enter the name to edit:");
    scanf(" %[^\n]",new_name);

    strcpy(addressBook->contacts[index].name,new_name);
    
    printf("✔️ Name is updated succesfully\n");

    return index;


}
int edit_by_phonenum(AddressBook *addressBook,int index)
{
    char new_num[50];
    printf("😊 Enter the number to edit:");
    scanf(" %[^\n]",new_num);

    strcpy(addressBook->contacts[index].phone,new_num);
    
    printf("✔️ Number is updated succesfully");
    return index; 

}
int edit_by_email(AddressBook *addressBook,int index)
{
    char new_email[50];
    printf("😊 Enter the email to edit:");
    scanf(" %[^\n]",new_email);

    strcpy(addressBook->contacts[index].email,new_email);
    
    printf("✔️ Email is updated succesfully");
    return index;

}
void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
    int index;
    int ret=searchContact(addressBook);
    if(ret== -1)
    {
        printf("❌Delete contact failure\n");
        return;
    }

    // Asking the user to enter the index to edit contacts
    printf("🗑️ Enter the index to delete:");
    scanf("%d",&index);

    for(int i=index;i<addressBook->contactCount;i++)
    {
        addressBook->contacts[i]=addressBook->contacts[i+1];
    }
    addressBook->contactCount--;

    printf("✨ Contact deleted sucessfully\n");
    
}