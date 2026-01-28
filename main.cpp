#include <iostream>
using namespace std;
struct medicine
{
    int id;
    string name;
    int dosage;
    int quantity;
};
medicine med[50];
medicine *ptr;
int total = 0;
void line()
{
    cout << "-----------------------------------" << endl;
}
void header()
{
    cout << "====================================" << endl;
    cout << "  WELCOME TO MEDICINE MANAGEMENT  " << endl;
    cout << "====================================" << endl;
    cout << endl;
}
void menu()
{
    cout << "===== MAIN MENU =====" << endl;
    cout << "1. Add Medicine" << endl;
    cout << "2. List Medicines" << endl;
    cout << "3. Update Medicine" << endl;
    cout << "4. Delete Medicine" << endl;
    cout << "5. Take Medicine" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice:" << endl;
}
void addMedicine()
{
    ptr = &med[total];
    cout << "Enter medicine id:" << endl;
    cin >> ptr->id;
    cout << "Enter medicine name:" << endl;
    cin >> ptr->name;
    cout << "Enter medicine dosage:" << endl;
    cin >> ptr->dosage;
    cout << "Enter medicine quantity:" << endl;
    cin >> ptr->quantity;
    total++;
    cout << "Medicine added successfully!" << endl;
    line();
    cout << endl;
}
void listMedicine()
{
    cout << "ID  Name  Dosage  Quantity" << endl;
    line();
    if (total == 0)
    {
        cout << "No medicine available!" << endl;
        line();
        cout << endl;
        return;
    }
    for (int i = 0; i < total; i++)
    {
        ptr = &med[i];
        cout << ptr->id << "   ";
        cout << ptr->name << "   ";
        cout << ptr->dosage << "   ";
        cout << ptr->quantity << endl;
    }
    line();
    cout << endl;
}
void updateMedicine()
{
    int id;
    cout << "Enter medicine ID to update:" << endl;
    cin >> id;
    for (int i = 0; i < total; i++)
    {
        ptr = &med[i];
        if (ptr->id == id)
        {
            cout << "Enter new medicine name:" << endl;
            cin >> ptr->name;
            cout << "Enter new medicine dosage:" << endl;
            cin >> ptr->dosage;
            cout << "Enter new medicine quantity:" << endl;
            cin >> ptr->quantity;
            cout << "Medicine updated successfully!" << endl;
            line();
            cout << endl;
            return;
        }
    }
    cout << "Medicine not found!" << endl;
    line();
    cout << endl;
}
void deleteMedicine()
{
    int id;
    cout << "Enter medicine ID to delete:" << endl;
    cin >> id;
    for (int i = 0; i < total; i++)
    {
        if (med[i].id == id)
        {
            for (int j = i; j < total - 1; j++)
            {
                med[j] = med[j + 1];
            }
            total--;
            cout << "Medicine deleted successfully!" << endl;
            line();
            cout << endl;
            return;
        }
    }
    cout << "Medicine not found!" << endl;
    line();
    cout << endl;
}
void takeMedicine()
{
    int id;
    cout << "Enter medicine ID to take:" << endl;
    cin >> id;
    for (int i = 0; i < total; i++)
    {
        ptr = &med[i];
        if (ptr->id == id)
        {
            if (ptr->quantity > 0)
            {
                ptr->quantity--;
                cout << "Medicine taken successfully!" << endl;
            }
            else
            {
                cout << "Medicine out of stock!" << endl;
            }
            line();
            cout << endl;
            return;
        }
    }
    cout << "Medicine not found!" << endl;
    line();
    cout << endl;
}
int main()
{
    int choice;
    header();
    do
    {
        menu();
        cin >> choice;
        if (choice == 1)
        {
            addMedicine();
        }
        else if (choice == 2)
        {
            listMedicine();
        }
        else if (choice == 3)
        {
            updateMedicine();
        }
        else if (choice == 4)
        {
            deleteMedicine();
        }
        else if (choice == 5)
        {
            takeMedicine();
        }
        else if (choice == 6)
        {
            cout << "Thank you for using the system." << endl;
            cout << "Program exiting..." << endl;
        }
        else
        {
            cout << "Invalid choice!" << endl;
            line();
            cout << endl;
        }
    } while (choice != 6);
    cout << "====================================" << endl;
    cout << "        END OF PROGRAM" << endl;
    cout << "====================================" << endl;
    return 0;
}