#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <fstream>
#include <stdlib.h>
using namespace std;

string name_output, surname_output;
int option;
FILE *fp;

struct Person
{
    string name, surname;
};
struct Person obj;

void new_details()
{
    cout<<"                         ...............New Details............"<<endl;
    do{
        cout<<"                                                             press (0) to go back"<<endl;
        //Save Name and Surname in File
        //Open File
        fp=fopen("Person_data.txt", "ab");
        cout<<"Enter your Name"<<endl;
        cin>>obj.name;
        fflush(stdin);
        cout<<"Enter your Surname"<<endl;
        cin>>obj.surname;
        fflush(stdin);
        cout<<endl;

        //Close File
        fwrite(&obj,sizeof(obj),1,fp);
        fclose(fp);

        do
        {
            cout<<"Enter option"<<endl;
            cin>>option;
        }while(option != 0);
    }while(option != 0);
}

void view_details()
{
    cout<<"                         ...............View Details............"<<endl;
    do{
        cout<<"                                                             press (0) to go back"<<endl;
        //Open Name File
        fp=fopen("Person_data.txt", "rb");

        while(fread(&obj,sizeof(obj),1,fp))
        {
            cout<<"Name: "<<obj.name<<endl;
            cout<<"Surname: "<<obj.surname<<endl;
            cout<<endl;
        }

        fclose(fp);

        do
        {
            cout<<"Enter option"<<endl;
            cin>>option;
        }while(option != 0);
    }while(option != 0);
}

void display()
{
    do{
        cout<<"                         ...............Portal............"<<endl;
        cout<<"                                                                        press (999) to Exit"<<endl;
        cout<<"                 [1]Enter Name and Surname             [2]View Details     "<<endl;
        cout<<endl;
        cout<<"Enter option"<<endl;
        cin>>option;
        system("PAUSE");
        system("CLS");
        switch(option)
        {
        case 1:
            new_details();
            break;
        case 2:
            view_details();
            break;
        case 999:
            cout<<"                         ...............Exiting Portal............"<<endl;
            cout<<endl;
            cout<<"                                     ///..SHUTDOWN..///"<<endl;
            break;
        default:
            cout<<"Invalid Option!!!"<<endl;
        }
        system("PAUSE");
        system("CLS");
    }while(option != 999);
}
int main()
{
    display();

    return 0;
}
