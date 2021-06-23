#include <bits/stdc++.h>
#define max 100
using namespace std;
int noOcomp=4;
int comp[max];int noOppl=0;
int earn=0; int sessions=0;
bool ifOccupied1[max];
string adminName[4] = {"Rohit","Siddhant","Arushi","Mukul"};
string adminPin[4] = {"1234","1234","1234","1234"};
void admin1();
void menu();
 bool check();
 void registration();
 void payCheck();
class admin{
 public :
  void insertComp(){
     comp[noOcomp] = noOcomp+1;
     noOcomp++;
 }
 void deleteComp(int pos){
   if(pos <= noOcomp){
     for(int i=pos-1;i<noOcomp;i++){
       comp[i] = comp[i+1];
     }
       noOcomp--;}
       else{
           cout << "No computer is registerd at that position\n";
           admin1();
       }
 }
 void noOComp(){
     for(int i=0;i<noOcomp;i++){
         cout <<comp[i]<<" ";
     }
     cout<<"\n";
     admin1();
 }
};

class login{
    public:
    string name,pin,p;
 void details(){
     sessions++;
cout<<"Enter your name\n";
cin >> name;
cout <<"Enter your pin\n";
cin >>pin;
if(check()){
    int i;int m=0;
    for( i=0;i<noOcomp;i++){
        if(ifOccupied1[i]==false){
            ifOccupied1[i]=true;
            m=1;
            break;
        }
    }
if(m==0){
    cout<<"No computer is free at the moment\n";
}
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
cout << "Welcome\nYou have been assigned computer no "<< i+1<<"\n" ;
logout:
cout<<"1.logout\n";

int a;
cin >> a;
if(a==1){
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    cout << "Time difference = " << std::chrono::duration_cast<std::chrono::seconds> (end - begin).count() << "sec" << std::endl;
    float cost=0;
    float a;
   a = std::chrono::duration_cast<std::chrono::seconds> (end - begin).count() ;
    if(a<60)
    cost=1*30;
    else if(a>60&&a<120)
    cost=2*30;
    else if(a>120&&a<180)
    cost=3*30;
    else if(a>180&&a<240)
    cost=4*30;
    else if(a>240&&a<300)
    cost=5*30;
    else if(a>300&&a<360)
    cost=6*30;
    else if(a>360&&a<420)
    cost=7*30;
    else if(a>420&&a<480)
    cost=8*30;
    else if(a>480&&a<540)
    cost=9*30;
    cout<<"Charge for the session is Rs."<<cost;  
    earn = cost + earn;
     ifOccupied1[i] =false;
}else{
    cout<<"please enter a valid key\n";
    goto logout;
}

} else{
    cout<<"No user registered \n";
    menu();
}

 
 }
  bool check(){
    ifstream read(name+".txt");
     getline(read,p);
    if( p == pin){
        return true;
    }else{
        cout<<"Register first\n";
        return false;
    }
  }
};


int main(){
     for(int i=0;i<4;i++){
  comp[i] = i+1;
 }
menu();

    return 0;
}
void payCheck(){
    cout<<"Welcome to our cost display option"<<endl;
    cout<<"The cost for surfing internet per hour is as follows"<<endl;
    cout<<"User will have to pay the amount for an hour even if he uses less than that"<<endl;
    for(int i=1;i<10;i++)
    {
        cout<< "For " <<i<< " hour it is Rs."<<i*30<<endl;
    }
    cout << "Press 1 to exit to menu.\n";
    int a;
    cin>>a;
    if(a==1){
        menu();
        }
}
void registration(){
    int q=1;
    ofstream fout;
    string n, p;
    cout << "enter your name\n";
    cin >> n;
    cout << "Enter your pin\n";
    cin >>p;
  
   
        fout.open(n+".txt");
        fout<<p;
        fout.close();
    cout << "you are registered\n";
    noOppl++;
 menu();
 
}
 
void admin1(){
    int i;
    while(i!=5){
        
    cout<<endl<<"1.Add computer\n2.Delete computer\n3.Check number of computer\n4.Check daily earning\n5.Menu\n";
    scanf("%d",&i);
    admin a;
switch (i)
    {
    case 1:
      a.insertComp();
        break;
    case 2:
    cout<<"which computer u want to delete\n";
    int p;
    cin >>p;
    a.deleteComp(p);
    case 3:
    a.noOComp();
    case 4:
    cout << "Today's earning : Rs "<<earn<<" \nFrom "<<sessions<<" session ";
    case 5:
    menu();
    break;
    default:
        break;
    }
    }
}
void menu(){
    int i;
    login b;string adminN;string adminP;int h=0;
while(i!=4){
    cout<<endl<<"1.ADMIN\n2.Login user\n3.Register user\n4.Price Display\n5.exit\n";
     scanf("%d",&i);
    switch (i)
    {
    case 1:
cout<<"Admin Login\n";
cout<<"Enter admin name\n";
cin>>adminN;cout<<"Enter Pin\n";cin>>adminP;
for(int i=0;i<4;i++){
    if(adminN==adminName[i] && adminP==adminPin[i]){cout<<"Welcome\n";admin1();
    }else{h=1;}
}
if(h==1){cout<<"Wrong input";
menu();
}       break;
        case 2:
         b.details();
        break;
        case 3:
      registration();
        break;
        case 4:
        payCheck();
        break;
     case 5:
     exit(5);
     break;
   
    }
}

}
