#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct {
    Contact contacts[100];
    int contactCount;
} AddressBook;

void createContact(AddressBook *addressBook);
int  searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook );
void listContacts(AddressBook *addressBook, int sortCriteria);
void initialize(AddressBook *addressBook);
void saveContactsToFile(AddressBook *AddressBook);
int Search_by_name(AddressBook *AddressBook);
int Search_by_phonenum(AddressBook *AddressBook);
int Search_by_email(AddressBook *AddressBook);
int edit_by_email(AddressBook *addressBook,int index);
int edit_by_phonenum(AddressBook *addressBook,int index);
int edit_by_name(AddressBook *addressBook,int index);
int validate_phone_num(AddressBook *addressBook,char *phone_num);
int validate_email_id(AddressBook *addressBook,char *email_id);
void saveAndExit(AddressBook *addressBook);
#endif