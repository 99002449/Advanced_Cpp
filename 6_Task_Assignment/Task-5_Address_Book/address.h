/*## Address class
  * Create a collection of Contact objects using suitable STL container
  * Implement following operations on the collection
    * addContact
    * removeContact by primary number
    * display all contacts
    * find contact by primary number
    * find all contacts with matching name (sub string match - first name or last name)
    * Update contact details, based on primary number (update first name, last name or alternate number)*/
#ifndef __ADDRESS_H
#define __ADDRESS_H
#include<list>
#include<iostream>
#include"contact.h"
class Address{
   std::list<contact> contacts;
public:
   void addContact(std::string,std::string,std::string,std::string);
   void displayAll();
   void removeContactBypnum(std::string); //by id
   contact* findContactBypnum(std::string);
   contact* findContactWithMatchname(std::string,std::string);//by firstname & lastname
   void updateContactdetails(std::string,std::string,std::string);
   int  countAll(){return contacts.size();}
};
#endif
