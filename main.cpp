#include <iostream>
#include <string>
#include "listbook.h"
#include <unordered_map>
#include <cstdlib>

using namespace  std;
unordered_map<int, listbook> librarydata;
unordered_map<int, bool> cheackreduduncy;
string booklist[] = {"mathematics", "physics", "chemistry", "english", "science", "c++", "java", "javascript"};
unordered_map<string, bool> havingbooks()
{
    unordered_map<string, bool> seen;
    for (int i = 0; i < booklist->size(); i++)
    {
        seen[booklist[i]] = true;
    }
    return seen;
}
bool ispresent(string str)
{
    unordered_map<string, bool> seen = havingbooks();
    if (seen.count(str) > 0)
    {

        return true;
    }
    return false;
}

void showdetails(int bookid)
{
    cout << "if you want to see your details in database enter 0";
    int a;
    cin >> a;
    if (a == 0)
    {
        listbook obj = librarydata[bookid];

        obj.printdetails();
    }
    else
    {
        cout << "ok we will not show your details ";
    }
}

void issuebooks()
{
    cout << "enter the name of three books you want ";
    string str1, str2, str3;
    cin >> str1 >> str2 >> str3;
    if (ispresent(str1) && ispresent(str2) && ispresent(str3))
    {
        cout << "kindly enter your name" << endl;
        string name;
        cin >> name;
        int bookid = (1 + (rand() % 33));

        listbook b;
        b.adddetails(bookid, name, str1, str2, str3);

        librarydata[bookid] = b;
        cheackreduduncy[bookid] = true;
        cout << "congratulations you have gained your book and your bookid is " << bookid << endl;
        showdetails(bookid);

        unordered_map<string, bool> seen = havingbooks();
        seen[str1] = false;
        seen[str2] = false;

        seen[str3] = false;
    }
    else
    {
        cout << "sorry for inconvince casued our library don't have the book combination you want";
    }
}
void submitbooks()
{
    cout << "enter your book id" << endl;
    int bookid;
    cin >> bookid;
    listbook obj = librarydata[bookid];
    cout << "your record was as shown bellow" << endl;
    obj.printdetails();
    cout << "As you submit the book data is erreased by the database to do so enter 5" << endl;
    int d;
    cin >> d;
    if (d == 5)
    {
        unordered_map<string, bool> seen = havingbooks();
        seen[obj.firstbook] = true;
        seen[obj.secondbook] = true;
        seen[obj.thirdbook] = true;
        cout<<"data errased succesfully ! congratulations "<<endl;
    }
}

int main()
{
    int count = 0;
    cout << "Hi,welcome to our libraray" << endl;
    cout << "if you want issue your book enter 1 or submit than enter 2" << endl;

    
        issuebooks();
        submitbooks();
   
}