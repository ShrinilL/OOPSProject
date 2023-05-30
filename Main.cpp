#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

// Create room status(occupied-1 or not-0) array
int Deluxe[50];
int SuperDeluxe[25];
int suite[25];

//Create class prototypes
class customer;
class DeluxeRoom;
class SuperDeluxeRoom;
class Suite;

// Define base class customer
class customer {
protected:
    string Name="";
    string mobNo="";
    int age=0;
    string Id_No="";
    string inDate="";
    string address="";

public:
    void getinfo()
    {
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin,Name);
    cout << "Enter Mobile Number: ";
    getline(cin,mobNo);
    cout << "Enter Age: ";
    cin >> age;
    cin.ignore();
    cout << "Enter Id Number: ";
    getline(cin,Id_No);
    cout << "Enter Date: ";
    getline(cin, inDate);
    cout << "Enter Address: ";
    getline(cin,address);
    }

    void showinfo()
    {
        cout<<endl;
        cout<<"Name: "<<Name<<endl;
        cout<<"Mobile Number: "<<mobNo<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Id No: "<<Id_No<<endl;
        cout<<"Check-in Date: "<<inDate<<endl;
        cout<<"Address: "<<address<<endl;
        cout<<endl;
    }
};

//Create derived class DeluxeRoom from customer
class DeluxeRoom : private customer {
    public:
        int roomNo=0;
    //Declare friend functions to access the variables of the class
    friend void checkIn(DeluxeRoom* obj1, int cnt);
    friend void checkOut(DeluxeRoom* obj1, int room);
    friend int searchcustomer(DeluxeRoom* obj1,SuperDeluxeRoom* obj2,Suite* obj3,string name);
};

//Create derived class SuperDeluxeRoom from customer
class SuperDeluxeRoom : private customer {
    public:
        int roomNo;
    //Declare friend functions to access the variables of the class
    friend void checkIn(SuperDeluxeRoom* obj2, int cnt);
    friend void checkOut(SuperDeluxeRoom* obj2, int room);
    friend int searchcustomer(DeluxeRoom* obj1,SuperDeluxeRoom* obj2,Suite* obj3,string name);

};

//Create derived class suite from customer
class Suite : private customer {
    public:
        int roomNo;
    //Declare friend functions to access the variables of the class
    friend void checkIn(Suite* obj3, int cnt);
    friend void checkOut(Suite* obj3, int room);
    friend int searchcustomer(DeluxeRoom* obj1,SuperDeluxeRoom* obj2,Suite* obj3,string name);
};

/* Here we overload the function checkIn using different class pointer object
   Each function corresponds to a different type of room in the hotel.*/
void checkIn(DeluxeRoom* obj1, int cnt)
{
    obj1->getinfo();
    obj1->showinfo();
    
    //Below is the logic for room number assignment
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
    else {
        cout<<"Sorry. No rooms available!"<<endl;
    }

    cout<<"Checked in to Deluxe Room "<<obj1->roomNo<<endl;
    Deluxe[i]=1;
    cnt++;
    
}

void checkIn(SuperDeluxeRoom* obj2, int cnt) {
 
    obj2->getinfo();
    obj2->showinfo();

    //Below is the logic for room number assignment
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
 
    obj3->getinfo();
    obj3->showinfo();

    //Below is the logic for room number assignment
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

/* Here we overload the function checkOut using different class pointer object
   Each function corresponds to a different type of room in the hotel.*/
void checkOut(DeluxeRoom* obj1, int room)
{
    // Print Customer details
    cout<<endl;
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
    cout<<endl;
    cout<<"Thank You for staying with us!"<<endl;
    cout<<endl;
}

void checkOut(SuperDeluxeRoom* obj2, int room)
{
    //Print Customer Details
    cout<<endl;
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
    cout<<endl;
    cout<<"Thank You for staying with us!"<<endl;
    cout<<endl;
}

void checkOut(Suite* obj3, int room)
{
    //Print Customer Details
    cout<<endl;
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
    cout<<endl;
    cout<<"Thank You for staying with us!"<<endl;
    cout<<endl;
}

//The function Available checks the number of rooms of each type that are available
void Available()
{
    cout<<endl;
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
    cout<<endl;
}

// This function searchcustomer takes the name of the customer and searches all the rooms for the customer name and returns the
// details of the customer after finding the match
int  searchcustomer(DeluxeRoom* obj1,SuperDeluxeRoom* obj2,Suite* obj3,string name){
      if (obj1->Name==name)
      {
        cout<<"Room Number: "<<obj1->roomNo;
        obj1->showinfo();
        return 1;
      }
      if (obj2->Name==name)
      {
        cout<<"Room Number: "<<obj2->roomNo;
        obj2->showinfo();
        return 1;
      }
      if (obj3->Name==name)
      {
        cout<<"Room Number: "<<obj3->roomNo;
        obj3->showinfo();
        return 1;
      }
      return 0;
 }

// Main method
int main()
{
    // We create an array of objects for each type of room
    //The counter is for the postion of the room in the room status arrays
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
    string n;
    int flag=0;

    while (option != 5) 
    {
        //Display the Menu
        cout<<endl;
        cout << "\t*MENU*"<<endl;
        cout << "1. Check-In" << endl;
        cout << "2. Check-Out" << endl;
        cout << "3. Available Rooms" << endl;
        cout << "4. Search Customer" << endl;
        cout << "5. Exit" << endl;
        cin >> option;

        // The for loops below iterate through the room status array and find the next room that is empty
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

        // We open the switch case to carry out each menu task
        switch(option)
        {
            // Case 1 is for Check In for each room type
        case 1:
            cout << "1. Deluxe" << endl;
            cout << "2. Super Deluxe" << endl;
            cout << "3. Suite" << endl;
            cout << "Enter option number: ";
            cin >> choice;
            // Allocate a Deluxe Room
            if (choice == 1) {
                obj1[cnt1] = new DeluxeRoom();
                checkIn(obj1[cnt1], cnt1);
                cnt1++;
            }
            // Allocate a Super Deluxe Room
            else if (choice == 2) {
                obj2[cnt2] = new SuperDeluxeRoom();
                checkIn(obj2[cnt2], cnt2);
                cnt2++;
            }
            // Allocate a Suite
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
            // Case 2 is for Check Out
        case 2:
            cout<<"Enter Room Number: "<<endl;
            int room;
            cin>>room;
            // Based on the room number decide which type of room and corresponding class object is to be deleted
            if ((room<=110 && room>100) || (room<=210 && room>200) || (room<=310 && room>300) || (room<=410 && room>400) || (room<=510 && room>500))
            {
                int c;
                for(c=0;c<50;c++)
                {
                    if(obj1[c]->roomNo==room)
                    {
                        checkOut(obj1[c], room);
                        Deluxe[c]=0;
                        delete obj1[c];
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
            // Case 3 is to check the number 
        case 3:
            Available();
            break;
            // Case 4 is to search customer using their name
        case 4:
            cout<<"Enter the name of the customer"<<endl;
            cin.ignore();
            getline(cin,n);
            int c1,c2,c3;
            for(c1=0,c2=0,c3=0;c1<50;c1++){
                if(Deluxe[c1]==1 || SuperDeluxe[c2]==1 || suite[c3]==1) {
                    flag=searchcustomer(obj1[c1], obj2[c2], obj3[c3], n);
                    if (flag==1)
                    {
                        break;
                    }
                }
                if(c2<25)
                    c2++;
                if(c3<25)
                    c3++;
            }
            if (flag==0)
            {
                cout<<"Customer Not Found!"<<endl;
            }
            break;
        case 5:
            break;
        default:
            cout<<"Not a valid choice! Try again!"<<endl;
        }
    }

    // Delete the object array
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