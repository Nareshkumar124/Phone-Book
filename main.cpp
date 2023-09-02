#include <iostream>
using namespace std;
string * userInformation();
void linkList2txt(PhoneBook &book);
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
    void addContact();
    void display();
    void search(string name);
};


void PhoneBook::addContact()
{
    string * info=userInformation();
    contact *temp = new contact();
    temp->name = info[0];
    temp->phone = info[1];
    temp->email = info[2];
    delete[] info;
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
    book.addContact();
    book.display();
    book.search("Naresh Kuma");
}

string * userInformation(){
    string * info=new string[3];
    cout<<"Enter Your Name: ";
    getline(cin,info[0]);
    cout<<"Enter Your Phone Number: ";
    getline(cin,info[1]);
    cout<<"Enter Your Email: ";
    getline(cin,info[2]);
    return info;
}

void linkList2txt(PhoneBook &book){
    printf("Write");
}