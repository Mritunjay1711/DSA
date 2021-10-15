#include <iostream>
#include<cstring>
using namespace std;


int main(){
    char s[20] = {"hello\0hi"};
    cout << sizeof(s) << strlen(s);
    return 0;
}