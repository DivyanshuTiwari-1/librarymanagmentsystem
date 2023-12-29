#include<iostream>
using namespace std;
#include<unordered_map>
class listbook{
    public:
    int bookid;
    string name;
    string firstbook;
    string secondbook;
    string thirdbook;


void adddetails(int bookid,string name,string first,string second,string third){
  this->bookid=bookid;
   this->name=name;
    firstbook=first;
    secondbook=second;
    thirdbook=third;
}

void printdetails(){
    cout<<"the details of the following candidate is "<<endl;;
    cout<<"bookid"<<" "<<bookid<<endl;
    cout<<"name"<<" "<<name<<endl;
    cout<<"firstbook"<<" "<<firstbook<<endl;
    cout<<"secondbook"<<" "<<secondbook<<endl;
    cout<<"thirdbook"<<" "<<thirdbook<<endl;

}







};

