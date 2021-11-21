#include<iostream>
using namespace std;

class sample
{
public:
    void set_data(char c)
    {
        ch = c;
    }
    void show_data()
    {
        cout << a << " " << ch;
    }
private:
    int a = 10;
    char ch;
};


int main(){
    sample s;
    s.set_data('d');
    s.show_data();    
    return 0;
}