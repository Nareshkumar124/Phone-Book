#include <iostream>
#include <fstream>
using namespace std;
class PhoneBook;
void linklistTwoTxt(PhoneBook &book);
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
    contact *head = NULL;

public:
    PhoneBook(string file);
    void addContact();
    void display();
    void search(string name);
};

PhoneBook::PhoneBook(string file)
{
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
}
void PhoneBook::addContact()
{
    contact *newContact = new contact();
    newContact->contactDetail();
    contact *iter = head;
    if (head == NULL)
    {
        head = newContact;
    }
    else
    {
        while (iter->next != NULL)
        {
            iter = iter->next;
        }
        iter->next = newContact;
        newContact->pre = iter;
    }
    // Insert into text file.
}

void PhoneBook::display()
{
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

void PhoneBook::search(string name)
{
    contact *iter = this->head;
    while (true)
    {
        if (iter == NULL)
        {
            cout << "Contact Not Found.";
            break;
        }
        else if (iter->name == name)
        {
            iter->displayContact();
            break;
        }
        iter = iter->next;
    }
}

int main()
{
    PhoneBook book = PhoneBook("data.txt");
    book.display();
    // book.search("Naresh Kuma");
}


void linklistTwoTxt(PhoneBook &book)
{
    printf("Write");
}
string *split(string data)
{
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