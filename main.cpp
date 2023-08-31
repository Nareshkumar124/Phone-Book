#include <iostream>
using namespace std;
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
    friend class PhoneBook;
};
class PhoneBook
{
private:
    contact *head = NULL;

public:
    PhoneBook() {}
    void addContact(string name, string phone, string email);
    void display();
    void search(string name);
};

void PhoneBook::addContact(string name,string phone, string email)
{
    contact *temp = new contact();
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
        if (iter->name == name)
        {
            iter->displayContact();
            break;
        }
    }
}
int main(){
    PhoneBook data = PhoneBook();
    data.addContact("Naresh Kumar", "9466639962", "nkk124421@gmail.com");
    data.display();
    // getchar();
}