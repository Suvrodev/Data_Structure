#include<iostream>
#include<cstdlib>
using namespace std;
struct Suvrodev{
    int Data;
    Suvrodev *Next_Address;
};
void Insert(Suvrodev *Node, int Data){
    while(Node->Next_Address!=NULL){
        Node=Node->Next_Address;
    }
    Node->Next_Address=(Suvrodev *)malloc(sizeof(Suvrodev));
    Node->Next_Address->Data=Data;
    Node->Next_Address->Next_Address=NULL;
}
int Display(Suvrodev *Node){
    int cc=0;
    while(Node->Next_Address!=NULL){
        cc++;
        cout<< Node->Next_Address->Data<<" ";
        Node=Node->Next_Address;
    }
    cout<<endl;
    return cc;
}

void Search_Single_item(Suvrodev *Node,int Search){
    int count=0;
   while(Node->Next_Address!=NULL){
       if(Search==Node->Next_Address->Data){
         count++;
       }
        Node=Node->Next_Address;
   }
   if(count==0){
       cout<<"Not Found"<<endl;
   }else{
   cout<<Search<<" include in Linked List "<<count<<" Times"<<endl;
   }
}



int Search_Position_By_item(Suvrodev* Node,int Search){
   int count=0;
   while(Node->Next_Address!=NULL){
        count++;
       if(Search==Node->Next_Address->Data){

          cout<<Search<<" found at "<< count<<" Number Position"<<endl;
          return -1;
       }
        Node=Node->Next_Address;
   }
}
int Search_Item_By_Position(Suvrodev* Node,int Position, int &Time){
    if(Position>Time || Position<1){
        cout<<"Position Error"<<endl;
        return -1;
    }
    int Data;
    for(int i=1;i<=Position;i++){
        Data=Node->Next_Address->Data;
        Node=Node->Next_Address;
    }
    return Data;
}
void Delete_item(Suvrodev* Node,int Data){
    int count=0;
    while(Node->Next_Address!=NULL){
        if(Node->Next_Address->Data==Data){
            Node->Next_Address=Node->Next_Address->Next_Address;
            cout<<"Deleted Successfully"<<endl;
            count++;
        }
        Node=Node->Next_Address;
    }
    if(count==0){
            cout<<"Data Not Found to Delete"<<endl;
     }
}
int Delete_Position(Suvrodev* Node,int Position, int &Time){
    if(Position>Time || Position<1){
        cout<<"Position Error"<<endl;
        return -1;
    }
    for(int i=1;i<=Position;i++){
        if(i==Position){
         Node->Next_Address=Node->Next_Address->Next_Address;
        }
        Node=Node->Next_Address;
    }
    cout<<"Deleted Successfully"<<endl;
}
int Replace_Data(Suvrodev * Node,int Data_,int Position,int &Time){
   if(Position>Time){
       cout<<"Position Error"<<endl;
       return -1;
   }
   for(int i=1;i<=Position;i++){
       if(i==Position){
           Node->Next_Address->Data=Data_;
       }
       Node=Node->Next_Address;
   }
}

void Exchanging(Suvrodev * Node,int P1,int P2,int & Time){
    int Helper1,Helper2;
    int Data1,Data2;

    Data1=Search_Item_By_Position(Node, P1,Time);
    Data2=Search_Item_By_Position(Node, P2,Time);

    cout<<"1st Data: "<<Data1<<endl;
    cout<<"2nd Data: "<<Data2<<endl;

    Replace_Data(Node,Data1,P2,Time);
    Replace_Data(Node,Data2,P1,Time);

}

void Insert_Data(Suvrodev * Node,int Data_,int Position,int & Time){

    int Count=0;
    while(Node->Next_Address!=NULL){
       Count++;
       if(Count==Position){
           Suvrodev *P=(Suvrodev *)malloc(sizeof(Suvrodev));
           P->Data=Data_;
           P->Next_Address=Node->Next_Address;
           Node->Next_Address=P;
       }


        Node=Node->Next_Address;
    }
}

int main()
{
  cout<<"Linked List"<<endl;
  int Time;
  int Input;
  int Position,Position2;
  int Count_Element;
  Suvrodev *Node=NULL;
  Node=(Suvrodev *)malloc(sizeof(Suvrodev));
  cout<<"How many time do you want to input: ";
  cin>>Time;
  for(int i=1;i<=Time;i++){
      cout<<i<<". Enter input: ";
      cin>>Input;
      Insert(Node,Input);
  }

  cout<<"Element of LinkedList: ";
  Display(Node);
  cout<<endl<<"Enter a Number do you want to search: ";
  cin>>Input;
  int Result=Search_Position_By_item(Node,Input);
  if(Result!=-1){
        cout<<"Your Search item not found"<<endl;
  }

  cout<<endl<<"Enter a Number do you want to Show how many Time in LinkedList: ";
  cin>>Input;
  Search_Single_item(Node,Input);

  cout<<endl<<"Enter a Position Number which data do you want to Search: ";
  cin>>Input;
  int Search_Position_=Search_Item_By_Position(Node, Input,Time);
  if(Search_Position_!= -1){
   cout<<"Thats Number: "<<Search_Position_<<endl;
  }else{
      cout<<" "<<endl;
  }


  cout<<"Enter a Data do you want to Delete: ";
  cin>>Input;
  Delete_item(Node,Input);
  Count_Element= Display(Node);
  cout<<"Total item in Linked List: "<<Count_Element<<endl;

  cout<<endl<<"Enter a Position Number which data do you want to Delete: ";
  cin>>Input;
  int DD=Delete_Position(Node,Input,Time);
  if(DD!=0){
  Count_Element= Display(Node);
  }else{}
  cout<<"Total item in Linked List: "<<Count_Element<<endl;

  cout<<endl<<"Enter a Position Number do you want to Replace: ";
  cin>>Position;
  cout<<"Enter a Data do you want to Replace: ";
  cin>>Input;

  int RD=Replace_Data(Node,Input,Position,Time);
  if(RD!=NULL){
      cout<<"All Data: ";
       Display(Node);
  }


  cout<<endl<<endl<<"For Exchanging Data give 1st Position Number: ";
  cin>>Position;
  cout<<"Give Second Position Number: ";
  cin>>Position2;

  Exchanging(Node,Position,Position2,Time);
  Display(Node);


  cout<<"Enter a Position do you want to Insert: ";
  cin>>Position;
  cout<<"Enter a Data do you want to Insert: ";
  cin>>Input;

  Insert_Data(Node,Input,Position,Time);
  Count_Element= Display(Node);
  cout<<"Total item in Linked List: "<<Count_Element<<endl;

  return 0;
}
