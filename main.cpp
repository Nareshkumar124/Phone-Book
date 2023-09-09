#include <iostream>
#include <fstream>
using namespace std;
class PhoneBook;
string *split(string data);
class contact
{
private:
    contact *pre = NULL;
    contact *next = NULL;
    string phone;
    string name;
    string email;
    void displayContact()
    {
        cout << "Name: " << this->name << endl;
        cout << "Phone: " << this->phone << endl;
        cout << "Email: " << this->email << endl
             << "\n\n";
    }
    contact *contactDetail()
    {
        cout << "Enter Your Name: ";
        getline(cin, this->name);
        cout << "Enter Your Phone Number: ";
        getline(cin, this->phone);
        cout << "Enter Your Email: ";
        getline(cin, this->email);
        return this;
    }
    contact * strTwoContact(string data)
    {
        string *arr = split(data);
        this->name = arr[0];
        this->phone = arr[1];
        this->email = arr[2];
        delete [] arr;
        return this;
    }
    friend class PhoneBook;
};
class PhoneBook
{
private:
    string fileName;
    contact *head = NULL;

public:
    PhoneBook(string file);
    void addContact();
    void deleteContact(string searchTerm);
    void searchContact(string searchTerm);
    void display();
    ~PhoneBook();
};

PhoneBook::PhoneBook(string file)
{
    this->fileName=file;
    ifstream contactFile=ifstream(file);
    string line;
    contact * iter=head;
    contact * last=NULL;
    while (!contactFile.eof())
    {
        getline(contactFile,line);
        contact * newContact=new contact;
        newContact->strTwoContact(line);
        if(head==NULL){
            head=newContact;
            last=newContact;
        }
        else{
            last->next=newContact;
            newContact->pre=last;
            last=newContact;
        }
    }
    contactFile.close();
}
PhoneBook::~PhoneBook(){
    // Use to load txt file into PhoneBook data structure
    ofstream contactFile=ofstream(this->fileName);
    contact * iter=head;
    while(true){
        string data="";
        data+=iter->name+",";
        data+=iter->phone+",";
        data+=iter->email;
        contactFile<<data;
        iter=iter->next;
        if(iter!=NULL){
            contactFile<<"\n";
        }
        else{
            break;
        }
    }
    contactFile.close();
}

void PhoneBook::addContact()
{
    // This function use to add contact alphabetically
    contact *newContact = new contact();
    newContact->contactDetail();

    if (head == NULL)
    {
        head = newContact;
    }
    else
    {
        // Find the correct position to insert the contact alphabetically
        contact *current = head;
        contact *previous = NULL;

        while (current != NULL && current->name < newContact->name)
        {
            previous = current;
            current = current->next;
        }

        if (previous == NULL)
        {
            // Insert at the beginning
            newContact->next = head;
            head->pre = newContact;
            head = newContact;
        }
        else
        {
            // Insert in the middle or at the end
            previous->next = newContact;
            newContact->pre = previous;
            newContact->next = current;
            if (current != NULL)
            {
                current->pre = newContact;
            }
        }
    }
}


void PhoneBook::display()
{
    // Use to display contact list.
    contact *iter = this->head;
    int i = 1;
    cout << "Contacts:  \n";
    while (iter != NULL)
    {
        cout << "Contact " << i << endl;
        iter->displayContact();
        iter = iter->next;
        i++;
    }
}

void PhoneBook::searchContact(string searchTerm)
{
    contact *current = head;
    bool found = false;

    while (current != NULL)
    {
        if (current->name.find(searchTerm) != string::npos || current->phone.find(searchTerm) != string::npos)
        {
            // Found a matching contact, display it.
            current->displayContact();
            found = true;
        }

        current = current->next;
    }

    if (!found)
    {
        cout << "Contact not found." << endl;
    }
}


int main()
{
    PhoneBook book = PhoneBook("data.txt");
    // book.addContact();
    // book.display();
    book.searchContact("");
    // book.search("Naresh Kuma");
    // book.addContact();
}


string *split(string data)
{
    // This functtion use to convert string into arr if string in a given order.
    int start = 0, end = 0;
    int inputNumber = 0;
    string *arr = new string[3]{"", "", ""};
    for (int i = 0; i < data.length(); i++)
    {
        if (data[i] == ',')
        {
            for (; start < end; start++)
            {
                arr[inputNumber] += data[start];
            }
            inputNumber += 1;
            start++;
        }
        end++;
    }
    for (; start < end; start++)
    {
        arr[inputNumber] += data[start];
    }
    return arr;
}