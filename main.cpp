//Mohamed Anas Mohamed Abd El-Hamid 20206062
//Mohamed Ahmed Abd El-Hamid 20206064
#include <iostream>
#include <string>
using namespace std;
class MyPhoneBook
{
    string *names;
    string *phones;
    int phoneBookSize;

public:
    int counter = 0;
    /*Parametrized Constructor that takes the size of PhoneBook and allocate
    dynamic arrays of names and phones and a copy constructor to initialize a PhoneBook
     using another PhoneBook.*/
    MyPhoneBook(int psize)
    {
        phoneBookSize = psize;
        names = new string[phoneBookSize];
        phones = new string[phoneBookSize];
    }
    // Copy Constructor
    MyPhoneBook(const MyPhoneBook &ob1)
    {
        names = ob1.names;
        phones = ob1.phones;
        phoneBookSize = ob1.phoneBookSize;
    };
    //A function addEntry that adds a name and phone number.
    bool addEntry(string n, string p)
    {
        for (int i = 0; i < p.length(); i++)
        {

            if (p.length() != 11)
            {
                cout << "invalid number" << endl;
                cout << "Enter correct phone:";
                getline(cin, p);
            }
        }

        for (int i = 0; i < p.length(); i++)
        {

            if (!(p[i] >= '0' && p[i] <= '9'))
            {
                cout << "invalid number" << endl;
                cout << "Enter correct phone:";
                getline(cin, p);
            }
        }
        names[counter] = n;
        phones[counter] = p;

        counter++;
    }
    //A function that displays a name and phone number at the specified index.
    bool displayEntryAtIndex(int display)
    {
        if (!(display <= phoneBookSize && display > 0))
        {
            return false;
        }
        cout << names[display - 1] << endl;
        cout << phones[display - 1] << endl;
    }
    // A function to update name in PhoneBook
    bool updateNameAt(string n_new, int display)
    {
        if (!(display <= phoneBookSize && display > 0))
        {
            return false;
        }
        names[display - 1] = n_new;
    }
    // A function to update phone in PhoneBook
    bool updatePhoneAt(string p_new, int display)
    {
        if (p_new.length() != 11)
        {

            return false;
        }
        for (int i = 0; i < p_new.length(); i++)
        {

            if (!(p_new[i] >= '0' && p_new[i] <= '9'))
            {

                return false;
            }
        }
        phones[display - 1] = p_new;
    }
    //A function that displays all entries in the phone book.
    void displayAll()
    {
        cout << "Name"
             << "\t\t"
             << "phone" << endl;
        for (int i = 0; i < phoneBookSize; i++)
        {
            cout << names[i] << "\t" << phones[i] << endl;
        }
    }
    //A function  that search name in PhoneBook by sub or full name.
    int *findByName(string nameSearch)
    {
        int *arrptr;
        arrptr = new int[phoneBookSize];
        for (int i = 0; i < phoneBookSize; i++)
        {

            if (names[i].find(nameSearch) != string::npos)
            {

                arrptr[i] = 1;
            }
            else
            {

                arrptr[i] = 0;
            }
        }
        return arrptr;
    }
    //A function  that search phone in PhoneBook
    int *findByPhone(string phonesearch)
    {
        int *arrptr;
        arrptr = new int[phoneBookSize];

        for (int i = 0; i < phoneBookSize; i++)
        {

            if (phones[i].find(phonesearch) != string::npos)
            {

                arrptr[i] = 1;
            }
            else
            {

                arrptr[i] = 0;
            }
        }
        return arrptr;
    }
    //A function that receives an array of zeros and ones.
    void displayEntryAtIndices(int *arrptr)
    {
        int count = 0;
        for (int i = 0; i < phoneBookSize; i++)
        {

            if (arrptr[i] == 1)
            {

                cout << names[i] << endl;
                cout << phones[i] << endl;
            }
            else
            {
                count++;
            }
        }
        if (count == phoneBookSize)
        {
            cout << "NOT Existing";
        }
    }
    //A Destructor to deallocate dynamic arrays and leave no memory leak.
    ~MyPhoneBook()
    {
        delete[] names;
        delete[] phones;
    }
};
int main()
{
    cout << "Enter the size of your phone book:";
    int size;
    try{
        cin >> size;
    }catch(exception){
        cout<<"you enter wrong data";
        return 0;
    }
    string name;
    string phone;
    getline(cin, name);
    MyPhoneBook obj1(size);
    MyPhoneBook obj2(obj1);
    for (int i = 1; i <= size; i++)
    {
        cout << "Enter name" << i << ":";
        getline(cin, name);
        cout <<
             "Enter phone" << i << ":";
        getline(cin, phone);
        obj1.addEntry(name, phone);
    }
    int choice = 0;
    //Take Optiones From User.
    for (int i = 0; choice != 8; i++)
    {
        cout << "Enter your choice" << endl;
        cout << "1- Display all phone book" << endl;
        cout << "2- search for entry/entries by name" << endl;
        cout << "3- search for entry/entries by phone" << endl;
        cout << "4- Find an entry by index" << endl;
        cout << "5- Update name by index" << endl;
        cout << "6- Update phone by index" << endl;
        cout << "7- copy phone book to another and display entries of new phone book" << endl;
        cout << "8- Exit" << endl;
        cin >> choice;
        if (choice == 1)
        {
            obj1.displayAll();
        }
        if (choice == 2)
        {
            string Name_search;
            cin >> Name_search;
            obj1.findByName(Name_search);
            int *AtIndices = obj1.findByName(Name_search);
            obj1.displayEntryAtIndices(AtIndices);
        }
        if (choice == 3)
        {
            string phone_search;
            cin >> phone_search;
            obj1.findByPhone(phone_search);
            int *AtIndices = obj1.findByPhone(phone_search);
            obj1.displayEntryAtIndices(AtIndices);
        }

        if (choice == 4)
        {
            int dis;
            cout << "Enter Display number:";
            cin >> dis;
            obj1.displayEntryAtIndex(dis);
        }
        string update_name;
        getline(cin, update_name);
        if (choice == 5)
        {
            cout << "Enter your update name:";
            getline(cin, update_name);
            cout << endl
                 << "Enter your display Entry At Index:";
            int update_dis;
            cin >> update_dis;
            obj1.updateNameAt(update_name, update_dis);
        }

        if (choice == 6)
        {
            cout << "Enter your update phone:";
            string update_phone;
            cin >> update_phone;
            cout << endl
                 << "Enter your display Entry At Index:";
            int update_dis2;
            cin >> update_dis2;
            obj1.updatePhoneAt(update_phone, update_dis2);
        }
        if (choice == 7)
        {
            obj2.displayAll();
        }
    }
}
