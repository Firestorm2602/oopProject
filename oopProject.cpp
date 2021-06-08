#include <iostream>
#define max 100
using namespace std;
int noOcomp=0;
int comp[max];int arr[max];
int a =-1,i=0;
class admin{
 public :
 admin(){
for(int i=0;i<max;i++){
    arr[i] = 0;
}
 }
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
           cout << "No computer is registerd at that position";
       }
 }
 void check(int a){
if(arr[a] == 1){
    cout << "Computer is occupied";
}else{
    cout <<"Computer is free";
}
 }

};
int main(){
    admin a;
    a.insertComp();
    a.insertComp();
    a.insertComp();
    a.deleteComp(1);
    for(int i=0;i<noOcomp;i++){
        cout<<comp[i];
    }
    return 0;
}
