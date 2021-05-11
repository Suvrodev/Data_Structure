#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class MyFile{
public:
    void Write(string,string,string,string,string);
    void Read();
    void Othersfile();
    void NewFile(string);
};
void MyFile::Write(string ID,string Name,string Department,string Semester,string CGPA){
     ofstream myfile;
     myfile.open("E:\\mahadi.txt", ios::out | ios::app);
     myfile << ID << "\n";
     myfile << Name << "\n";
     myfile << Department << "\n";
     myfile << Semester << "\n";
     myfile << CGPA << "\n";

     myfile.close();
}
void MyFile::Read(){
    string Line;
    string ID,Name,Department,Semester,CGPA;
    ifstream myfile("E:\\mahadi.txt");

    while(getline(myfile,Line)){
        cout<<Line<<endl;
    }

    myfile.close();
}
void MyFile::Othersfile()
{
    int count=0,c=0;
    string Line;
    string FullInfo="";
    string id="",ID,Name,Department,Semester,CGPA;
    ifstream myfile("E:\\mahadi.txt");

    cout<<"Enter ID Number: ";
    cin.ignore();
    getline(cin,id);

   while(getline(myfile,Line)){
        if(Line==id){
          count++;
        }
        if(count>0){
            cout<<Line<<endl;
            FullInfo+=Line+"\n";
            c++;
            if(c==5){
                break;
            }
        }
    }
    myfile.close();
    NewFile(FullInfo);
}

void MyFile::NewFile(string Full_Info){
     ofstream myfilee;
     myfilee.open("E:\\mahadii.txt", ios::out | ios::app);
     myfilee << Full_Info << "\n";
     myfilee.close();
}
int main()
{
    MyFile my;
    string Name, Department, Semester, CGPA, ID;
    char ch;

    while(true){

    cout<<"File Write->w\nFile Read->r\nFir Copy Content->s\nNow Press:";
    cin>>ch;
    switch(ch){
    case 'w':
    cout << "Enter ID Number: ";
    cin.ignore();
    getline(cin, ID);
    cout << "Name: ";
    getline(cin, Name);
    cout << "Department: ";
    getline(cin, Department);
    cout << "Semester: ";
    getline(cin, Semester);
    cout << "CGPA: ";
    getline(cin, CGPA);
    my.Write(ID,Name,Department,Semester,CGPA);
    break;
    case 'r':
        my.Read();
        break;
    case 's':
        my.Othersfile();
        break;
    default:
        break;
    }
    }
    return 0;
}
