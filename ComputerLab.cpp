/*
 Dennis Frenkel
 Computer Science 2
 
 Dakota Hernandez
 ComputerLab.cpp
 Last Edited: Wed Oct 11, 2023
 */

#include <iostream>
using namespace std;

typedef int* IntPtr;
const int NUMLABS = 4;

void createArrays(IntPtr labs[], int labsizes[]);
void freeArrays(IntPtr labs[]);
void showLabs(IntPtr labs[], int labsizes[]);
void login(IntPtr labs[], int labsizes[]);
void logout(IntPtr labs[], int labsizes[]);
void search(IntPtr labs[], int labsizes[]);

int main()
{
    IntPtr labs[NUMLABS];
    int labsizes[NUMLABS];
    int choice = -1;

    cout << "Welcome to the LabMonitorProgram!" << endl;
    cout << "Please enter the number of computer stations in each lab:" << endl;
    for (int i = 0; i < NUMLABS; i++)
    {
        do
        {
            cout << "How many computers in Lab " << i + 1 << "? ";
            cin >> labsizes[i];
        } while (labsizes[i] < 0);
    }

    createArrays(labs, labsizes);

    while (choice != 0)
    {
        cout << endl;
        cout << "MAIN MENU" << endl;
        cout << "0) Quit" << endl;
        cout << "1) Simulate login" << endl;
        cout << "2) Simulate logout" << endl;
        cout << "3) Search" << endl;
        cin >> choice;

        if (choice == 1)
        {
            login(labs, labsizes);
            showLabs(labs, labsizes);
        }
        else if (choice == 2)
        {
            logout(labs, labsizes);
            showLabs(labs, labsizes);
        }
        else if (choice == 3)
        {
            search(labs, labsizes);
        }
    }

    freeArrays(labs);
    cout << "Bye!" << endl;
    return 0;
}

void createArrays(IntPtr labs[], int labsizes[])
{
    for (int i = 0; i < NUMLABS; i++)
    {
        labs[i] = new int[labsizes[i]];
        for (int j = 0; j < labsizes[i]; j++)
        {
            labs[i][j] = -1;
        }
    }
}

void freeArrays(IntPtr labs[])
{
    for (int i = 0; i < NUMLABS; i++)
    {
        delete[] labs[i];
    }
}

void showLabs(IntPtr labs[], int labsizes[])
{
    int i;
    int j;

    cout << "LAB STATUS" << endl;
    cout << "Lab #     Computer Stations" << endl;
    for (i = 0; i < NUMLABS; i++)
    {
        cout << i + 1 << "         ";
        for (j = 0; j < labsizes[i]; j++)
        {
            cout << (j + 1) << ": ";
            if (labs[i][j] == -1)
            {
                cout << "empty ";
            }
            else
            {
                cout << labs[i][j] << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void login(IntPtr labs[], int labsizes[])
{
    int id, lab, num = -1;

    do
    {
        cout << "Enter the 5 digit ID number of the user logging in:" << endl;
        cin >> id;
    } while ((id < 10000) || (id > 99999));

    do
    {
        cout << "Enter the lab number the user is logging in from (1-" << NUMLABS << "):" << endl;
        cin >> lab;
    } while ((lab <= 0) || (lab > NUMLABS));

    do
    {
        cout << "Enter computer station number the user is logging in to (1-" << labsizes[lab - 1] << "):" << endl;
        cin >> num;
    } while ((num <= 0) || (num > labsizes[lab - 1]));

    if (labs[lab - 1][num - 1] != -1)
    {
        cout << "ERROR, user " << labs[lab - 1][num - 1] << " is already logged into that station." << endl;
        return;
    }
    labs[lab - 1][num - 1] = id;
    return;
}

void logout(IntPtr labs[], int labsizes[])
{
    int id;
    int positionI = -1, positionJ = -1;
    do
    {
        cout << "Enter the 5 digit ID number of the user logging in:" << endl;
        cin >> id;
    }
    while((id < 10000) || (id > 99999));
    for (int i = 0; i < NUMLABS; i++)
    {
        for (int j = 0; j < labsizes[i]; j++)
        {
            if (labs[i][j] == id)
            {
                labs[i][j] = -1;
                positionI = i;
                positionJ = j;
            }
        }
    }
    if (positionI >= 0 && positionJ >= 0)
    {
        cout << "Logout user " << id << " in Lab " << (positionI + 1) << " at computer " << (positionJ + 1) << endl;
    }
    else
    {
        cout << "User not logged in." << endl;
    }
}

void search(IntPtr labs[], int labsizes[])
{
        int id;
        int positionI = -1, positionJ = -1;
        do
        {
            cout << "Enter the 5 digit ID number of the user logging in:" << endl;
            cin >> id;
        } while ((id < 10000) || (id > 99999));
        for(int i = 0; i<NUMLABS;i++) {
            for(int j = 0; j < labsizes[i]; j++) {
                if(labs[i][j] == id) {
                    positionI = i;
                    positionJ = j;
                }
            }
        }
        if(positionI >= 0 && positionJ >= 0)
        {
            cout << "User ";
            cout << id;
            cout << " logged in Lab ";
            cout << positionI+1;
            cout << " at computer ";
            cout << positionJ + 1<<endl;
        }
        else
        {
            cout << "User not logged in."<< endl;
        }
}

/*Welcome to the LabMonitorProgram!
 Please enter the number of computer stations in each lab:
 How many computers in Lab 1? 4
 How many computers in Lab 2? 5
 How many computers in Lab 3? 6
 How many computers in Lab 4? 4

 MAIN MENU
 0) Quit
 1) Simulate login
 2) Simulate logout
 3) Search
 1
 Enter the 5 digit ID number of the user logging in:
 33333
 Enter the lab number the user is logging in from (1-4):
 3
 Enter computer station number the user is logging in to (1-6):
 3
 LAB STATUS
 Lab #     Computer Stations
 1         1: empty 2: empty 3: empty 4: empty
 2         1: empty 2: empty 3: empty 4: empty 5: empty
 3         1: empty 2: empty 3: 33333 4: empty 5: empty 6: empty
 4         1: empty 2: empty 3: empty 4: empty


 MAIN MENU
 0) Quit
 1) Simulate login
 2) Simulate logout
 3) Search
 1
 Enter the 5 digit ID number of the user logging in:
 22222
 Enter the lab number the user is logging in from (1-4):
 2
 Enter computer station number the user is logging in to (1-5):
 2
 LAB STATUS
 Lab #     Computer Stations
 1         1: empty 2: empty 3: empty 4: empty
 2         1: empty 2: 22222 3: empty 4: empty 5: empty
 3         1: empty 2: empty 3: 33333 4: empty 5: empty 6: empty
 4         1: empty 2: empty 3: empty 4: empty


 MAIN MENU
 0) Quit
 1) Simulate login
 2) Simulate logout
 3) Search
 3
 Enter the 5 digit ID number of the user logging in:
 22222
 User 22222 logged in Lab 2 at computer 2

 MAIN MENU
 0) Quit
 1) Simulate login
 2) Simulate logout
 3) Search
 2
 Enter the 5 digit ID number of the user logging out:
 11111
 User not logged in.
 LAB STATUS
 Lab #     Computer Stations
 1         1: empty 2: empty 3: empty 4: empty
 2         1: empty 2: 22222 3: empty 4: empty 5: empty
 3         1: empty 2: empty 3: 33333 4: empty 5: empty 6: empty
 4         1: empty 2: empty 3: empty 4: empty


 MAIN MENU
 0) Quit
 1) Simulate login
 2) Simulate logout
 3) Search
 2
 Enter the 5 digit ID number of the user logging out:
 33333
 Logout user 33333 in Lab 3 at computer 3
 LAB STATUS
 Lab #     Computer Stations
 1         1: empty 2: empty 3: empty 4: empty
 2         1: empty 2: 22222 3: empty 4: empty 5: empty
 3         1: empty 2: empty 3: empty 4: empty 5: empty 6: empty
 4         1: empty 2: empty 3: empty 4: empty


 MAIN MENU
 0) Quit
 1) Simulate login
 2) Simulate logout
 3) Search
 0
 Bye!
 Program ended with exit code: 0
 */
