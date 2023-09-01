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
    PhoneBook(string file) {
        cout<<file;
    }
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
        if(iter==NULL){
            cout<<"Contact Not Found.";
            break;
        }
        else if(iter->name == name)
        {
            iter->displayContact();
            break;
        }
        iter=iter->next;
    }
}
int main(){
    PhoneBook book = PhoneBook("data.txt");
    book.addContact("Naresh Kumar", "9466639962", "nkk124421@gmail.com");
    // data.display();
    book.search("Naresh Kuma");
}