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
void welcome();

class admin {
    public :
    
    void insertComp() {
        comp[noOcomp] = noOcomp+1;
        noOcomp++;
    }
    
    void deleteComp(int pos) {
        if(pos <= noOcomp) {
            for(int i=pos-1;i<noOcomp;i++) {
                comp[i] = comp[i+1];
            }
            noOcomp--;
        }
        else{
            cout << "\t No computer is registerd at that position"<<endl;
            admin1();
        }
    }
    
    void noOComp() {

        cout<<"\t Number of computers: ";
        for(int i=0;i<noOcomp;i++) {
            cout <<comp[i]<<" ";
        }
        
        cout<<"\n";
        admin1();
    }
};

class login {
    
    public:
    string name,pin,p;
    
    void details()  {
        sessions++;
        cout<<endl;
        cout<<"\t Enter your name: ";
        cin >> name;
        cout <<"\t Enter your pin: ";
        cin >>pin;
        
        if(check()) {
            int i;
            int m=0;
            
            for( i=0;i<noOcomp;i++) {
                if(ifOccupied1[i]==false) {
                    ifOccupied1[i]=true;
                    m=1;
                    break;
                }
            }
            
            if(m==0) {
                cout<<"\tNo computer is free at the moment.";
            }
            
            std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
            
            cout <<endl;
            cout<<"\t\tWelcome"<<endl;
            cout <<endl;
            cout<<"\t You have been assigned computer no: "<< i+1 <<endl;
            logout:
            cout<<"\t 1. Logout"<<endl<<endl;
            
            cout<<"\t Enter your Option: ";
            int a;
            cin >> a;
            
            if(a==1) {
                std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
                cout<<endl;
                cout << "\t Time difference = " << std::chrono::duration_cast<std::chrono::seconds> (end - begin).count() << "sec" << std::endl;
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
                
                cout<<"\t Charge for the session is Rs. "<<cost;
                cout<<endl;
                earn = cost + earn;
                ifOccupied1[i] =false;
            }
            else {
                cout<<"\t Please enter a valid key.\n";
                goto logout;
            }
        } 
        else {
            cout<<"\tNo user registered \n";
            menu();
        }
    }
    
    bool check() {
        ifstream read(name+".txt");
        getline(read,p);
        if( p == pin) {
            return true;
        }
        else {
            cout<<"\tRegister first."<<endl;
            return false;
        }
    }
};


int main() {
    
    welcome();
    for(int i=0;i<4;i++) {
        comp[i] = i+1;
    }
    
    menu();
    return 0;
}

void welcome() {
    cout<<endl<<endl;
    cout<<"-------------------------------------------------------------------------------------------"<<endl;
    cout<<"\t\t\tWelcome to Cyber-Cafe Management System!!"<<endl;
    cout<<"-------------------------------------------------------------------------------------------"<<endl;
}

void payCheck() {
    cout<<endl<<endl;
    cout<<"\tWelcome to our cost display option"<<endl;
    cout<<"\tThe cost for surfing internet per hour is as follows"<<endl;
    cout<<"\tUser will have to pay the amount for an hour even if he uses less than that"<<endl;
    cout<<endl;
    for(int i=1;i<10;i++) {
        cout<<"\tFor "<<i<<" hour it is Rs. "<<i*30<<endl;
    }
    cout<<endl;
    
    cout << "\tPress 1 to exit to menu: ";
    int a;
    cin>>a;
    
    if(a==1) {
        menu();
    }
}

void registration() {
    int q=1;
    ofstream fout;
    string n, p;
  
    cout<<endl;
    cout<<"\t Enter your name: ";
    cin>>n;
    cout<<"\t Enter your pin: ";
    cin>>p;
    
    fout.open(n+".txt");
    fout<<p;
    fout.close();
    
    cout << "\t You are registered."<<endl;
    noOppl++;
    menu();
}

void admin1() {
    int i;
    
    while(i!=6) {
        cout<<endl;
        cout<<"     -------------------------------------"<<endl;
        cout<<"\t\t   Admin Menu"<<endl;
        cout<<"     -------------------------------------"<<endl;
        cout<<"\t Welcome";
        cout<<endl<<endl;
        cout<<"\t 1. Add computer"<<endl;
        cout<<"\t 2. Delete computer"<<endl;
        cout<<"\t 3. Check occupied computer timers"<<endl;
        cout<<"\t 4. Check number of computers"<<endl;
        cout<<"\t 5. Check daily earning"<<endl;
        cout<<"\t 6. Menu"<<endl<<endl;
        
        cout<<"\t Enter your Option: ";
        scanf("%d",&i);
        admin a;
        
        switch (i) {
            case 1:
                a.insertComp();
                break;
            case 2:
                cout<<"\t Which Computer u want to delete?"<<endl;
                cout<<"\t (Enter no of Computer): ";
                int p;
                cin >>p;
                a.deleteComp(p);
            case 4:
                a.noOComp();
            case 5:
                cout<<"\t Today's earning : Rs. "<<earn<<endl;
                cout<<"\t From "<<sessions<<" sessions"<<endl;
                break;
            case 6:
                menu();
                break;
            default:
                break;
        }
    }
}

void menu() {
    int i;
    login b;
    string adminN, adminP;
    int h=0;
    
    while(i!=4){
        cout<<endl;
        cout<<"     -------------------------------------"<<endl;
        cout<<"\t\t      Menu"<<endl;
        cout<<"     -------------------------------------"<<endl;

        cout<<"\t 1. ADMIN"<<endl;
        cout<<"\t 2. Login user "<<endl;
        cout<<"\t 3. Register user"<<endl;
        cout<<"\t 4. Price Display"<<endl;
        cout<<"\t 5. Exit"<<endl<<endl;
        cout<<"\t Enter your Option: ";
        scanf("%d",&i);
    
        switch (i) {
            case 1:
                cout<<"\t Admin Login\n";
                cout<<"\t Enter admin name: ";
                cin>>adminN;
                cout<<"\t Enter Pin: ";
                cin>>adminP;
                
                for(int i=0;i<4;i++) {
                    if(adminN==adminName[i] && adminP==adminPin[i]) {
                        admin1();
                    }
                    else {
                        h=1;
                    }
                }
                
                if(h==1) {
                    cout<<"\t Wrong input";
                    menu();
                }
                break;
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
