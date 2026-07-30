#include <iostream>
using namespace std;

class Todo
{
private:
    string itemname;
    int id;
    int quantity;
    static int totalitems;
    int s = 0;
    Todo *ptr;

public:
    Todo(string name = " ", int i = 0, int q = 0) : itemname(name), id(i), quantity(q)
    {
        totalitems++;
        ptr = nullptr;
    }
    void additem()
    {

        Todo *nitem = new Todo[s + 1];
        string name;
        int i, q;
        cout << "\nEnter the name of the item: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter the id: ";
        cin >> i;
        cout << "Enter the quantity: ";
        cin >> q;

        nitem[s] = Todo(name, i, q);

        for (int i = 0; i < s; i++)
        {
            nitem[i] = ptr[i];
        }
        nitem[s] = Todo(name, i, q);
        s++;
        delete[] ptr;
        ptr = nitem;
        cout << "\nAdded Successfully\n";
    }
    void removeitem()
    {
        int i_d, f;
        bool find = false;
        cout << "\nEnter the ID to Remove the element: ";
        cin >> i_d;
        for (int i = 0; i < s; i++)
        {
            if (ptr[i].id == i_d)
            {
                find = true;
                f = i;
                break;
            }
        }
        Todo *newlist = new Todo[s - 1];
        int j = 0;
        if (find == false)
        {
            cout << "\nInvalid ID Entered\n";
            return;
        }
        if (find)
        {
            for (int i = 0; i < s; i++)
            {
                if (i != f)
                {
                    newlist[j] = ptr[i];
                    j++;
                }
            }
        }
        cout << "\nItem Removed Successfully\n";
        delete[] ptr;
        ptr = newlist;
        s--;
    }
    void displayallitems()
    {
        for (int i = 0; i < s; i++)
        {
            cout << "\n====================\n";
            cout << "Item Name is: " << ptr[i].itemname << endl;
            cout << "Item ID is: " << ptr[i].id << endl;
            cout << "Item Quantity is: " << ptr[i].quantity << endl;
            cout << "====================\n";
        }
    }
    void updateitem()
    {
        int i_d, f;
        bool find = false;
        cout << "\nEnter the Item ID to Update: ";
        cin >> i_d;
        for (int i = 0; i < s; i++)
        {
            if (ptr[i].id == i_d)
            {
                find = true;
                f = i;
                break;
            }
        }
        if (find)
        {
            int q;
            cout << "\nEnter the new quantity: ";
            cin >> q;
            ptr[f].quantity = q;
            cout << "\nUpdated successfully\n";
        }
        else
        {
            cout << "\ninvalid id entered\n";
        }
    }
    inline ~Todo() noexcept
    {
        delete[] ptr;
        ptr = nullptr;
    }
};
int Todo::totalitems = 0;
int main()
{
    Todo *mptr = new Todo;
    while (true)
    {
        int choice;
        cout << "\n1. Add item\n";
        cout << "2. Remove item\n";
        cout << "3. Update item\n";
        cout << "4. Display all items\n";
        cout << "5. Exit...\n";
        cout << "\nSelect from the menu: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            mptr->additem();
            break;
        case 2:
            mptr->removeitem();
            break;
        case 3:
            mptr->updateitem();
            break;
        case 4:
            mptr->displayallitems();
            break;
        case 5:
            cout << "\nprogram closed by user\n";
            mptr->~Todo();
            exit(EXIT_SUCCESS);
        }
    }
    return 0;
}