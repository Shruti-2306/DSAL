#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int max_r = 10; // Maximum number of records in the direct access file
const int n = 13;     // Hash table size

struct Student
{
    int rollno;
    char name[50];
    float marks;
};

class DirectAccessFile
{
private:
    fstream file;
    int hashTable[n]; // Hash table to store record positions

public:
    //constructor
    DirectAccessFile()
    {
        // Initialize hash table entries to -1 (indicating empty position)
        for (int i = 0; i < n; i++)
        {
            hashTable[i] = -1;
        }
    }

    void openFile(const char *fileName)
    {
        file.open(fileName, ios::binary | ios::in | ios::out | ios::trunc);
        if (!file)
        {
            cerr << "Error opening file." << endl;
            exit(1);
        }
    }

    void closeFile()
    {
        file.close();
    }

    void insert(Student rec)
    {
        // Calculate the hash value
        int hashValue = rec.rollno % n;
        int loc;

        // Collision handled using linear probing
        int i = 0;
        while (i < n)
        {
            loc = (hashValue + i) % n;
            if (hashTable[loc] == -1)
                break;
            if (loc == hashValue)
            {
                cout << "Table is full." << endl;
                return;
            }
            i++;
        }

        // Move file pointer to the hash value position
        file.seekp(loc * sizeof(Student));

        // Write the record to the file
        file.write((char *)&rec, sizeof(Student));

        hashTable[loc] = rec.rollno;
        cout << "Record inserted successfully." << endl;
    }

    void display()
{
    file.seekg(0, ios::beg);

    cout << "File Contents:" << endl;
    cout << "--------------" << endl;

    for (int i = 0; i < n; i++)
    {
        if (hashTable[i] != -1)
        {
            file.seekg(i * sizeof(Student));
            Student rec;
            file.read((char *)&rec, sizeof(Student));

            cout << i << ") Rollno: " << rec.rollno << ", Name: " << rec.name << ", Marks: " << rec.marks << endl;
        }
        else
        {
            cout << i << ") ------------------------" << endl;
        }
    }

    cout << "--------------" << endl;
}


    void del(int rollno1)
    {
        // Calculate the hash value
        int hashValue = rollno1 % n;

        // Search for the record
        int i = 0;
        int loc = -1;
        while (i < n)
        {
            loc = (hashValue + i) % n;
            if (hashTable[loc] == rollno1)
                break;
            i++;
        }

        if (i == n)
        {
            cout << "Record with key " << rollno1 << " not found." << endl;
            return;
        }

        // Delete the record by marking hash table entry as -1
        hashTable[loc] = -1;

        // Move file pointer to the record position
        file.seekp(loc * sizeof(Student));

        // Reset the record data to zeros
        Student rec;
        memset(&rec, 0, sizeof(Student));

        // Write the updated record to the file
        file.write((char *)&rec, sizeof(Student));

        cout << "Record with key " << rollno1 << " deleted successfully." << endl;
    }
};

int main()
{
    DirectAccessFile d;
    d.openFile("direct.txt");
    Student rec;
    int ch;

    do
    {
        cout << "1: Insert" << endl;
        cout << "2: Delete" << endl;
        cout << "3: Display" << endl;
        cout << "4: Exit"<<endl;
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter record (RollNo, Name, Marks): ";
            cin >> rec.rollno >> rec.name >> rec.marks;
            d.insert(rec);
            break;

        case 2:
            int rollno1;
            cout << "Enter RollNo: ";
            cin >> rollno1;
            d.del(rollno1);
            break;

        case 3:
            d.display();
            break;

        case 4:
            cout<<"Thank you for using this code!"<<endl;
            break;
        }
    } while (ch != 4);

    d.closeFile();
    return 0;
}
