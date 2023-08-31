#include <iostream>
using namespace std;
class contact
{
public:
    contact *pre = NULL;
    contact *next = NULL;
    long long phone;
    string name;
    string email;
    void displayContact() {
        cout << "Name: " << this->name << endl;
        cout << "Phone: " << this->phone << endl;
        cout << "Email: " << this->email << endl
             << "\n\n";
    }
};
class PhoneBook
{
private:
    contact *head = NULL;

public:
    PhoneBook() {}
    void addContact(string name, long long phone, string email);
    void display();
    void search(string name);
};

void PhoneBook::addContact(string name, long long phone, string email)
{
    contact *temp = (contact *)malloc(sizeof(contact));
    temp->name = name;
    temp->phone = phone;
    temp->email = email;
    contact *iter = head;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        while (iter->next != NULL)
        {
            iter = iter->next;
        }
        iter->next = temp;
        temp->pre = iter;
    }
}
void PhoneBook::display()
{
    contact *iter = this->head;
    int i = 1;
    cout << "Contacts:  \n";
    while (iter != NULL)
    {
        cout << "Contact " << i << endl;
        cout << "Name: " << iter->name << endl;
        cout << "Phone: " << iter->phone << endl;
        cout << "Email: " << iter->email << endl
             << "\n\n";
        iter = iter->next;
        i++;
    }
}
void PhoneBook::search(string name) {
    contact *iter = this->head;
    while(true) {
        if (iter->name == name) {
            iter->displayContact();
            break;
        }
    }
}
int main()
{
    PhoneBook data = PhoneBook();
    data.addContact("Naresh Kumar", 1234567890, "nkk124421@gmail.com");
    data.display();
    data.search("Naresh Kumar");
}