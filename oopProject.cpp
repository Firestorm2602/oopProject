#include <bits/stdc++.h>
#define max 100
using namespace std;
int noOcomp=0;
int comp[max];string namestore[max];int pinstore[max];int noOppl=0;
int a =-1,i=0,k=0;
bool ifOccupied1[max];
string tempname[max]; 

bool ifOccupied();
void admin1();
void menu();
 bool check();
 void registration();
class admin{
 public :
  void insertComp(){
     a++;noOcomp++;i++;
     comp[a] = i;
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
    string name;
    int pin,l=1;
 void details(){
cout<<"Enter your name\n";
cin >> name;
cout <<"Enter your pin\n";
cin >>pin;
for(int i=0;i<=k;i++){
    if(name==tempname[i]){
        cout<<"user already logged in";
        l=0;
        menu();
        break;}
}
if(l=1){
if(noOcomp>0){
if(check()){
  k++;
 tempname[k-1]=name;
    int i;int m=0;
    for( i=0;i<noOcomp;i++){
        if(ifOccupied1[i]==false){
            ifOccupied1[i]=true;
            m=1;
            break;
        }
    }
if(m==0){
    cout<<"No computer is free at the moment";
}
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
cout << "Welcome\nYou have been assigned computer no "<< i+1<<"\n" ;
cout<<"1.logout\n";
cout<<"2.Menu\n";
int a;
cin >> a;
if(a==1){
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    cout << "Time difference = " << std::chrono::duration_cast<std::chrono::seconds> (end - begin).count() << "[sec]" << std::endl;
    for(int i=k-1;i<=k;i++){
       tempname[i] = tempname[i+1];
     }
     k--;
    ifOccupied1[i] =false;
}else if(a==2){menu();}
}
    else{
    cout<<"No user registered \n";
    menu();
}
}else{
    cout<<"Please add computer first";
    menu();

}
 }
 }
  bool check(){
     for(int i=0;i<noOppl;i++){
         if(namestore[i] == name && pinstore[i] == pin){
           return true;
     }
    }
   return false;
  }
};


int main(){
     for(int i=0;i<max;i++){
     ifOccupied1[i] = false;
 }
menu();

    return 0;
}
bool ifOccupied(){
   
}
void registration(){
    string n; int p,q=1;
    cout << "enter your name\n";
    cin >> n;
    cout << "Enter your pin\n";
    cin >>p;
    for(int i=0;i<noOppl;i++){
       if(n== namestore[i]){
        q=0;
           break;
       }
    }
    if(q==1){
    cout << "you are registered\n";
    noOppl++;
        namestore[noOppl-1] = n;
        pinstore[noOppl-1] = p;
 menu();}else{
     cout<<"Name already taken please use a diffrent name";
     registration();
 }
 
}

 
void admin1(){
    int i;
    while(i!=5){
    cout<<endl<<"1.Add computer\n2.Delete computer\n3.Check occupied computer timer\n4.Check number of computer\n5.Menu\n";
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
    case 4:
    a.noOComp();
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
    login b;
while(i!=4){
    cout<<endl<<"1.ADMIN\n2.Login user\n3.Register user\n4.exit\n";
     scanf("%d",&i);
    switch (i)
    {
    case 1:
     admin1();
        break;
        case 2:
         b.details();
        break;
        case 3:
      registration();
        break;
     case 4:
     exit(4);
     break;
   
    }
}

}
