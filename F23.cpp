#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class Student
{
    typedef struct Stud
    {
        int roll_no;
        char name[10];
        char div;
        char add[10];
    }Stud;

    Stud rec;
    public:
     void create();
     void display();
     int search();
     void Delete();
};

void Student::create()
{
    char ans;
    ofstream fout;
    fout.open("stud.data",ios::out| ios::binary);
    do
    {
        cout<<"\n\tEnter roll number of student:";
        cin>>rec.roll_no;
        cout<<"\n\tEnter name of student: ";
        cin>>rec.name;
        cout<<"\n\tEnter the division of student: ";
        cin>>rec.div;
        cout<<"\n\tEnter address of student: ";
        cin>>rec.add;

        fout.write((char*)&rec,sizeof(Stud))<<flush;
        cout<<"\n\tDo you want to add more?(y/n)";
        cin>>ans;
    }while(ans == 'y'|| ans == 'Y');

    fout.close();
}

void Student::display()
{
    ifstream fin;
    fin.open("stud.data",ios::in|ios::binary);
    fin.seekg(0,ios::beg);
    cout<<"\n\tThe Content of file: \n";
    cout<<"\n\tRoll\tName\tDiv\tAdd";

    while(fin.read((char *)&rec,sizeof(Stud)))
    {
        if(rec.roll_no != -1)
        {
            cout<<"\n\t"<<rec.roll_no<<"\t"<<rec.name<<"\t"<<rec.div<<"\t"<<rec.add;
        }
       
    }
     fin.close();
}

int Student::search()
{
    int r,i = 0;
    ifstream fin;
    fin.open("stud.data",ios::in|ios::binary);
    fin.seekg(0,ios::beg);
    cout<<"\n\tEnter roll number:";
    cin>>r;
    while(fin.read((char *)&rec,sizeof(Stud)))
    {
        if(rec.roll_no == r)
        {
            cout<<"\n\tRecord Found..\n";
            cout<<"\nRoll number\tName\tDiv\tAddress";
            cout<<"\n\t"<<rec.roll_no<<"\t"<<rec.name<<"\t"<<rec.div<<"\t"<<rec.add;
            
        }
        i++;
    }
    fin.close();
    return 0;
}

void Student::Delete()
{
    int pos;
    pos = search();
    fstream f;
    f.open("stud.data",ios::in|ios::out|ios::binary);
    f.seekg(0,ios::beg);
    if(pos == -1)
    {
        cout<<"\n\tRecord Not Found\n";
        return;
    }

    int offset = pos*sizeof(Stud);
    f.seekp(offset);
    rec.roll_no = -1;
    strcpy(rec.name,"NULL");
    rec.div= 'N';
    strcpy(rec.add,"NULL");
    f.write((char *)&rec,sizeof(Stud));
    f.seekg(0);
    f.close();
    cout<<"\n\tRecord Deleted";
}

int main()
{
    Student obj;
    int ch,key;
    char ans;

    do{
        cout<<"\n\t***********Student Information***********\n";
        cout<<"\n\t1.create\n\t2.Display\n\t3.Delete\n\t4.Search\n\t5.Exit";
        cout<<"\nEnter your choice: ";
        cin>>ch;

        switch(ch)
        {
            case 1:
            obj.create();
            break;

            case 2:
            obj.display();
            break;

            case 3:
            obj.Delete();
            break;

            case 4:
            key = obj.search();
            if(key == 0)
            {
                cout<<"Record not found....\n";
            }
                 break;

            case 5:
            cout<<"Terminating...\n";
            break;

            default:
            cout<<"Invalid choice..\n";     
        }
        cout<<"\n\tDo you want to continue main menu?(y/n)";
        cin>>ans;

    }while(ans == 'y' || ans == 'Y');

    return 1;
}