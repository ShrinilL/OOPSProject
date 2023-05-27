//Put get info fn to get cust info


#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int Deluxe[50];
int SuperDeluxe[25];
int suite[25];

class customer {
protected:
    string Name="";
    string mobNo="";
    int age=0;
    string Id_No="";
    string inDate="";
    // string outDate;
    string address="";
};

class DeluxeRoom : private customer {
    public:
        int roomNo=0;
    friend void checkIn(DeluxeRoom* obj1, int cnt);
    friend void checkOut(DeluxeRoom* obj1, int room);
};

class SuperDeluxeRoom : private customer {
    public:
        int roomNo;
    friend void checkIn(SuperDeluxeRoom* obj2, int cnt);
    friend void checkOut(SuperDeluxeRoom* obj2, int room);
};

class Suite : private customer {
    public:
        int roomNo;
    friend void checkIn(Suite* obj3, int cnt);
    friend void checkOut(Suite* obj3, int room);
};

void checkIn(DeluxeRoom* obj1, int cnt) {
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, obj1->Name);
    cout << "Enter Mobile Number: ";
    getline(cin, obj1->mobNo);
    cout << "Enter Age: ";
    cin >> obj1->age;
    cin.ignore();
    cout << "Enter Id Number: ";
    getline(cin, obj1->Id_No);
    cout << "Enter Date: ";
    getline(cin, obj1->inDate);
    cout << "Enter Address: ";
    cin.ignore();
    getline(cin, obj1->address);

    cout<<obj1->Name<<endl;
    cout<<obj1->mobNo<<endl;
    cout<<obj1->age<<endl;
    cout<<obj1->Id_No<<endl;
    cout<<obj1->inDate<<endl;
    cout<<obj1->address;
    int i;
    for (i = 0; i < 50; i++) {
        if (Deluxe[i] == 0)
            break;
    }
    if (i < 10) {
        obj1->roomNo = 100 + (i + 1);
    }
    else if (i < 20) {
        obj1->roomNo = 200 + (i - 10 + 1);
    }
    else if (i < 30) {
        obj1->roomNo = 300 + (i - 20 + 1);
    }
    else if (i < 40) {
        obj1->roomNo = 400 + (i - 30 + 1);
    }
    else if (i<50) {
        obj1->roomNo = 500 + (i - 40 + 1);
    }
    else{
        cout<<"Sorry. No rooms available!"<<endl;
    }

    cout<<"Checked in to Deluxe Room "<<obj1->roomNo<<endl;
    Deluxe[i]=1;
    cnt++;
    
}

void checkIn(SuperDeluxeRoom* obj2, int cnt) {
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, obj2->Name);
    cout << "Enter Mobile Number: ";
    getline(cin, obj2->mobNo);
    cout << "Enter Age: ";
    cin >> obj2->age;
    cin.ignore();
    cout << "Enter Id Number: ";
    getline(cin, obj2->Id_No);
    cout << "Enter Date: ";
    getline(cin, obj2->inDate);
    cout << "Enter Address: ";
    cin.ignore();
    getline(cin, obj2->address);

    cout<<obj2->Name<<endl;
    cout<<obj2->mobNo<<endl;
    cout<<obj2->age<<endl;
    cout<<obj2->Id_No<<endl;
    cout<<obj2->inDate<<endl;
    cout<<obj2->address;

    int i;
    for (i = 0; i < 25; i++) {
        if (SuperDeluxe[i] == 0)
            break;
    }
    if (i < 5) {
        obj2->roomNo = 110 + (i + 1);
    }
    else if (i < 10) {
        obj2->roomNo = 210 + (i - 5 + 1);
    }
    else if (i < 15) {
        obj2->roomNo = 310 + (i - 10 + 1);
    }
    else if (i < 20) {
        obj2->roomNo = 410 + (i - 15 + 1);
    }
    else if(i<25){
        obj2->roomNo = 510 + (i - 20 + 1);
    }
    else{
        cout<<"Sorry. No rooms available!"<<endl;
    }

    cout<<"Checked in to Super Deluxe Room "<<obj2->roomNo<<endl;
    cnt++;
    SuperDeluxe[i]=1;

}

void checkIn(Suite* obj3, int cnt) {
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, obj3->Name);
    cout << "Enter Mobile Number: ";
    getline(cin, obj3->mobNo);
    cout << "Enter Age: ";
    cin >> obj3->age;
    cin.ignore();
    cout << "Enter Id Number: ";
    getline(cin, obj3->Id_No);
    cout << "Enter Date: ";
    getline(cin, obj3->inDate);
    cout << "Enter Address: ";
    cin.ignore();
    getline(cin, obj3->address);

    cout<<obj3->Name<<endl;
    cout<<obj3->mobNo<<endl;
    cout<<obj3->age<<endl;
    cout<<obj3->Id_No<<endl;
    cout<<obj3->inDate<<endl;
    cout<<obj3->address<<endl;


    int i;
    for (i = 0; i < 25; i++) {
        if (suite[i] == 0)
            break;
    }
    if (i < 5) {
        obj3->roomNo = 115 + (i + 1);
    }
    else if (i < 10) {
        obj3->roomNo = 215 + (i - 5 + 1);
    }
    else if (i < 15) {
        obj3->roomNo = 315 + (i - 10 + 1);
    }
    else if (i < 20) {
        obj3->roomNo = 415 + (i - 15 + 1);
    }
    else if(i<25) {
        obj3->roomNo = 515 + (i - 20 + 1);
    }
    else{
        cout<<"Sorry. No rooms available!"<<endl;
    }
    cout<<"Checked in to- Suite "<<obj3->roomNo<<endl;
    cnt++;
    suite[i]=1;
}

void checkOut(DeluxeRoom* obj1, int room)
{
    cout<<"Details"<<endl;
    cout<<"Room Number: "<<room<<endl;
    cout<<"Name: "<<obj1->Name<<endl;
    cout<<"Mobile Number: "<<obj1->mobNo<<endl;
    cout<<"Check-In date:"<<obj1->inDate<<endl;
    obj1->Name="";
    obj1->mobNo="";
    obj1->age=0;
    obj1->Id_No="";
    obj1->inDate="";
    obj1->address="";
    obj1->roomNo=0;
    cout<<"Thank You for staying with us!"<<endl;
}

void checkOut(SuperDeluxeRoom* obj2, int room)
{
    cout<<"Details"<<endl;
    cout<<"Room Number: "<<room<<endl;
    cout<<"Name: "<<obj2->Name<<endl;
    cout<<"Mobile Number: "<<obj2->mobNo<<endl;
    cout<<"Check-In date:"<<obj2->inDate<<endl;
    obj2->Name="";
    obj2->mobNo="";
    obj2->age=0;
    obj2->Id_No="";
    obj2->inDate="";
    obj2->address="";
    obj2->roomNo=0;
    cout<<"Thank You for staying with us!"<<endl;
}

void checkOut(Suite* obj3, int room)
{
    cout<<"Details"<<endl;
    cout<<"Room Number: "<<room<<endl;
    cout<<"Name: "<<obj3->Name<<endl;
    cout<<"Mobile Number: "<<obj3->mobNo<<endl;
    cout<<"Check-In date:"<<obj3->inDate<<endl;
    obj3->Name="";
    obj3->mobNo="";
    obj3->age=0;
    obj3->Id_No="";
    obj3->inDate="";
    obj3->address="";
    obj3->roomNo=0;
    cout<<"Thank You for staying with us!"<<endl;
}

void Available()
{
    int i, cn=0;
    for(i=0; i<50; i++)
    {
        if(Deluxe[i]==0)
            cn++;
    }
    cout<<"Number of Deluxe Rooms Available: "<<cn<<endl;
    cn=0;
    for(i=0; i<25; i++)
    {
        if(SuperDeluxe[i]==0)
            cn++;
    }
    cout<<"Number of Super Deluxe Rooms Available: "<<cn<<endl;
    cn=0;
    for(i=0; i<25; i++)
    {
        if(suite[i]==0)
            cn++;
    }
    cout<<"Number of Suites Available: "<<cn<<endl;
}

int main() {
    DeluxeRoom* obj1[50];
    int y;
    for(y=0;y<50;y++)
    {
        obj1[y]=new DeluxeRoom();
    }
    int cnt1 = 0;
    SuperDeluxeRoom* obj2[25];
    for(y=0;y<25;y++)
    {
        obj2[y]=new SuperDeluxeRoom();
    }
    int cnt2 = 0;
    Suite* obj3[25];
    for(y=0;y<50;y++)
    {
        obj3[y]=new Suite();
    }
    int cnt3 = 0;

    int option = 0;
    int choice;

    while (option != 5) {
        cout << "1. Check-In" << endl;
        cout << "2. Check-Out" << endl;
        cout << "3. Available Rooms" << endl;
        cout << "4. Search Customer" << endl;
        cout << "5. Exit" << endl;
        cin >> option;

        cnt1=0;
        int z;
        for(z=0;z<50;z++)
        {
            if (Deluxe[z]==0)
                break;
            cnt1++;
        }

        cnt2=0;
        for(z=0;z<50;z++)
        {
            if (SuperDeluxe[z]==0)
                break;
            cnt2++;
        }

        cnt3=0;
        for(z=0;z<50;z++)
        {
            if (suite[z]==0)
                break;
            cnt3++;
        }

        switch (option) {
        case 1:
            cout << "1. Deluxe" << endl;
            cout << "2. Super Deluxe" << endl;
            cout << "3. Suite" << endl;
            cout << "Enter option number: ";
            cin >> choice;
            if (choice == 1) {
                obj1[cnt1] = new DeluxeRoom();
                checkIn(obj1[cnt1], cnt1);
                cnt1++;
            }
            else if (choice == 2) {
                obj2[cnt2] = new SuperDeluxeRoom();
                checkIn(obj2[cnt2], cnt2);
                cnt2++;
            }
            else if (choice == 3) {
                obj3[cnt3] = new Suite();
                checkIn(obj3[cnt3], cnt3);
                cnt3++;
            }
            else
            {
                cout<<"Invalid Choice!"<<endl;
            }
            break;
        case 2:
            cout<<"Enter Room Number: "<<endl;
            int room;
            cin>>room;

            if ((room<=110 && room>100) || (room<=210 && room>200) || (room<=310 && room>300) || (room<=410 && room>400) || (room<=510 && room>500))
            {
                int c;
                for(c=0;c<50;c++)
                {
                    if(obj1[c]->roomNo==room)
                    {
                        checkOut(obj1[c], room);
                        Deluxe[c]=0;
                        delete obj1[c];// We had a segmentation fault
                    }
                }
            }
            else if ((room<=115 && room>110) || (room<=215 && room>210) || (room<=315 && room>310) || (room<=415 && room>410) || (room<=515 && room>510))
            {
                int c;
                for(c=0;c<25;c++)
                {
                    if(obj2[c]->roomNo==room)
                    {
                        checkOut(obj2[c], room);
                        SuperDeluxe[c]=0;
                        delete obj2[c];
                    }
                }
            }
            else if ((room<=120 && room>115) || (room<=220 && room>215) || (room<=320 && room>315) || (room<=420 && room>415) || (room<=520 && room>515))
            {
                int c;
                for(c=0;c<25;c++)
                {
                    if(obj3[c]->roomNo==room)
                    {
                        checkOut(obj3[c], room);
                        suite[c]=0;
                        delete obj3[c];
                    }
                }
            }
            else
            {
                cout<<"Not a valid Room Number"<<endl;
            }
            break;
        case 3:
            Available();
            break;
            
        case 5:
            break;
        }
    }
    
    
    
    int x;
    for(x=0; x<50; x++)
    {
        printf("%d ", obj1[x]->roomNo);
        // if(Deluxe[x]!=0)
        // {
        //     printf("%d  ", obj1[x]->roomNo);
        // }
    }
    for(x=0; x<25; x++)
    {
        if(SuperDeluxe[x]!=0)
        {
            printf("%d  ", obj2[x]->roomNo);
        }
    }
    for(x=0; x<25; x++)
    {
        if(suite[x]!=0)
        {
            printf("%d  ", obj3[x]->roomNo);
        }
    }

    for (int i = 0; i < cnt1; i++) {
        delete obj1[i];
    }
    for (int i = 0; i < cnt2; i++) {
        delete obj2[i];
    }
    for (int i = 0; i < cnt3; i++) {
        delete obj3[i];
    }

    return 0;
}