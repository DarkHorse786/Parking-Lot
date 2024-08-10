#include<iostream>
#include<conio.h>
#include <windows.h>
#include<cmath>
using namespace std;

//////////////     Declaring  Variables     //////////////

int capacity=20;
string press;
int tries=0,total_vehicles=0,amount=0,cash_receivable=0,cash_received=0;
int m_parked=0,r_parked=0,c_parked=0,b_parked=0;
int m_leaved=0,r_leaved=0,c_leaved=0,b_leaved=0;
int m=0,r=0,c=0,b=0;

/////////////     Declaring Functions     ////////////

HWND WINAPI GetConsoleWindowNT(void);

void Delete_Record();
void motorcycle_parked();void rickshaw_parked();void car_parked();void bus_parked();
void motorcycle_leaved();void rickshaw_leaved();void car_leaved();void bus_leaved();
void Screen();

///////////////////// MAIN ////////////////////////

int main()
{
	HWND hWnd=GetConsoleWindowNT();
    MoveWindow(hWnd,175,0,980,730,TRUE);
	while(tries==0)
	{
	Screen();
	cin>>press;
	if(press=="1")
	{
		motorcycle_parked();
	}
	else if(press=="2")
	{
		rickshaw_parked();		
	}
	else if(press=="3")
	{
		car_parked();	
 	}
	else if(press=="4")
	{
		bus_parked();	
	}
 	else if(press=="5")
 	{
		motorcycle_leaved();
	}
	else if(press=="6")
	{
		rickshaw_leaved();	
 	}
	else if(press=="7")
	{
		car_leaved();	
	}
	else if(press=="8")
	{
		bus_leaved();	
	}
	else if(press=="9")
	{
		Delete_Record();	
	}
	else if(press=="10")
	{
			cout<<"\n Are you sure to Quit the Program? \t (Y/N)"<<endl;
			cin>>press;
			if(press=="y" || press=="Y")
			{
				tries++;
				cout<<"--------------------------------------------------------------------------------\n";
				cout<<"                               Thank You.Exiting!                               \n";
				cout<<"--------------------------------------------------------------------------------\n";
			}	
 	
	}
	else
 	{
			cout<<"\n Invalid Choice!";
			cout<<"\n ---------------";
			getch();
	}
	}
}

///////////////////////// Sizing the Console //////////////////

HWND WINAPI GetConsoleWindowNT(void)
{
    //declare function pointer type
    typedef HWND WINAPI(*GetConsoleWindowT)(void);
    //declare one such function pointer
    GetConsoleWindowT GetConsoleWindow;
    //get a handle on kernel32.dll
    HMODULE hk32Lib = GetModuleHandle(TEXT("KERNEL32.DLL"));
    //assign procedure address to function pointer
    GetConsoleWindow = (GetConsoleWindowT)GetProcAddress(hk32Lib
    ,TEXT("GetConsoleWindow"));
    //check if the function pointer is valid
    //since the function is undocumented
    if(GetConsoleWindow == NULL){
        return NULL;
    }
    //call the undocumented function
    return GetConsoleWindow();
}
/////////////////////// Functions Definitions //////////////////
void Screen()
{
	system("cls");
	cout<<endl;
	cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n\n";
	cout<<"  -----------------\t-------------------------------------\t  ------------"<<endl;
	cout<<"  |               |\t|           Tickets Rates           |\t  |          |"<<endl;
	cout<<"  *               *\t*-----------------------------------*\t  * Capacity *"<<endl;
	cout<<"  |  Parking Lot  |\t| Bike  | Rickshaw  |  Car  |  Bus  |\t  |          |"<<endl;
	cout<<"  *               *\t*       |           |       |       *\t  *    "<<capacity<<"    *"<<endl;
	cout<<"  |               |\t| 50    | 100       |  200  |  300  |\t  |          |"<<endl;
	cout<<"  -----------------\t-------------------------------------\t  ------------"<<endl;
	cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-";
	cout<<endl<<endl;
	cout<<"\t\t\t\tParked: \t  Leaved: \t   Total: "<<endl;
	cout<<"\t\t\t\t------- \t  ------- \t   ------ "<<endl<<endl;
	cout<<"  Number of Motorcycles:   |\t   "<<m_parked<<"\t\t     "<<m_leaved<<"\t\t     "<<m<<endl;
	cout<<"\t\t\t   |"<<endl;
	cout<<"  Number of Rickshaws:     |\t   "<<r_parked<<"\t\t     "<<r_leaved<<"\t\t     "<<r<<endl;
	cout<<"\t\t\t   |"<<endl;
	cout<<"  Number of Cars:          |\t   "<<c_parked<<"\t\t     "<<c_leaved<<"\t\t     "<<c<<endl;
	cout<<"\t\t\t   |"<<endl;    
	cout<<"  Number of Buses:         |\t   "<<b_parked<<"\t\t     "<<b_leaved<<"\t\t     "<<b<<endl;
	cout<<"\t\t\t   |"<<endl<<endl<<endl;
	cout<<"\t\t\t   The total Number of Vehicles: "<<total_vehicles<<endl<<endl;
	cout<<"\t\t\t   The total cash Received: "<<cash_received<<endl<<endl;	
	cout<<"\t\t\t   The total cash Receivable: "<<cash_receivable<<endl<<endl;
	cout<<"\t\t\t   The total amount: "<<amount<<endl<<endl<<endl;
	cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-";
	cout<<endl<<endl;
	cout<<"\t\t\t\t     PRESS:"<<endl;
	cout<<"\t\t\t\t     ------"<<endl<<endl;
	cout<<"\t\t1 To Park a Motorcycle\t|   5 To Exit a Motorcycle."<<endl;
	cout<<"\t\t\t\t\t|\t\t\t\t"<<endl;
	cout<<"\t\t2 To Park a Rickshaw.\t|   6 To Exit a Rickshaw."<<endl;
	cout<<"\t\t\t\t\t|\t\t\t\t"<<endl;
	cout<<"\t\t3 To Park a Car.\t|   7 To Exit a Car."<<endl;
	cout<<"\t\t\t\t\t|\t\t\t\t"<<endl;
	cout<<"\t\t4 To Park a Bus.     \t|   8 To Exit a Bus."<<endl<<endl<<endl;
	cout<<"\t\t\t     9 To Delete the record."<<endl<<endl;
	cout<<"\t\t\t    10 To Exit the Program."<<endl<<endl;
}	
void Delete_Record()
{
	total_vehicles=0,amount=0,cash_receivable=0,cash_received=0,capacity=20;
	m_parked=0,r_parked=0,c_parked=0,b_parked=0;
	m_leaved=0,r_leaved=0,c_leaved=0,b_leaved=0;
	m=0,r=0,c=0,b=0;
	Screen();
	cout<<"--------------------------------------------------------------------------------\n";
	cout<<"                                 RECORD DELETED                                 \n";
	cout<<"--------------------------------------------------------------------------------\n";
	getch();
}
void motorcycle_parked()
{
	if(capacity>=1)
	{
		m_parked+=1;
		m++;
		amount=amount+50;
		cash_receivable=cash_receivable+50;
		total_vehicles++;
		capacity--;
		Screen();
		cout<<"\n Successfully Motorcycle has been Parked!";
		getch();
	}
	else
	{
		cout<<"\n Parking Lot is Full!";
		cout<<"\n --------------------";
		getch();
	}	
}
void rickshaw_parked()
{
	if(capacity>0)
	{
		r_parked+=1;
		r++;
		amount=amount+100;
		cash_receivable=cash_receivable+100;
		total_vehicles++;
		capacity--;
		Screen();
		cout<<"\n Successfully Rickshaw has been Parked!";
		getch();
	}
	else
	{
		cout<<"\n Parking Lot is Full!";
		cout<<"\n --------------------";
		getch();	
	}
}
void car_parked()
{
	if(capacity>=1)
	{
		c_parked+=1;
		c++;
		amount=amount+200;
		cash_receivable=cash_receivable+200;
		total_vehicles++;
		capacity--;
		Screen();
		cout<<"\n Successfully Car has been Parked!";
		getch();
	}
	else
	{
		cout<<"\n Parking Lot is Full!";
		cout<<"\n --------------------";
		getch();	
	}	
}
void bus_parked()
{
	if(capacity>=1)
	{
		b_parked+=1;
		b++;
		amount=amount+300;
		cash_receivable=cash_receivable+300;
		total_vehicles++;
		capacity--;
		Screen();
		cout<<"\n Successfully Bus has been Parked!";
		getch();
	}
	else
	{
		cout<<"\n Parking Lot is Full!";
		cout<<"\n --------------------";
		getch();	
	}
}
void motorcycle_leaved()
{
	if(m_parked>0)
	{
		m_leaved+=1;
		m_parked-=1;
		cash_receivable=cash_receivable-50;
		cash_received=cash_received+50;
		capacity++;
		Screen();
		cout<<"\n Successfully Motorcycle has been Left!";
		getch();
	}
	else
	{
		cout<<"\n No more Motorcycle is parked!";
		cout<<"\n -----------------------------";
		getch();
	}
}
void rickshaw_leaved()
{
	if(r_parked>0)
	{
		r_leaved+=1;
		r_parked-=1;
		cash_receivable=cash_receivable-100;
		cash_received=cash_received+100;
		capacity++;
		Screen();
		cout<<"\n Successfully Rickshaw has been Left!";
		getch();
	}
	else
	{
		cout<<"\n No more Rickshaw is parked!";
		cout<<"\n ---------------------------";
		getch();
	}
}
void car_leaved()
{
	if(c_parked>0)
	{
		c_leaved+=1;
		c_parked-=1;
		cash_receivable=cash_receivable-200;
		cash_received=cash_received+200;
		capacity++;
		Screen();
		cout<<"\n Successfully Car has been Left!";
		getch();
	}
	else
	{
		cout<<"\n No more Car is parked!";
		cout<<"\n ----------------------";
		getch();
	}
}
void bus_leaved()
{
	if(b_parked>0)
	{
		b_leaved+=1;
		b_parked-=1;
		cash_receivable=cash_receivable-300;
		cash_received=cash_received+300;
		capacity++;
		Screen();
		cout<<"\n Successfully Motorcycle has been left!";
		getch();
	}
	else
	{
		cout<<"\n No more Bus is parked!";
		cout<<"\n ----------------------";
		getch();
	}
}

