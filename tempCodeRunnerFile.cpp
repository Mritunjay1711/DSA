#include <iostream> 
using namespace std; 
class METRO 
{ 
int Mno, TripNo, PassengerCount; public: 
METRO(int Tmno = 1) 
{ 
Mno = Tmno; 
TripNo = 0; 
PassengerCount = 0; 
} 
void Trip(int PC = 20) 
{ 
TripNo++; 
PassengerCount += PC; 
} 
void StatusShow() 
{ 
cout << Mno << ":" << TripNo << ":" << PassengerCount; } 
}; 
int main() 
{ 
METRO M(5), T; 
M.Trip(); 
T.Trip(50); 
M.StatusShow(); 
cout<<endl; 
M.Trip(30); 
T.StatusShow(); 
cout<<endl; 
M.StatusShow(); 
}
