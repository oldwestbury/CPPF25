#include <iostream>
using namespace std;

//Array as an parameter
void f(int a[], int c, int &b){
    a[0]=10;
    a[1]=a[1]*2;
    c=10;
    b=10;
}
int main(){

int a[2]={4,8};
int c=1;
int b=5;

cout << "A" << a[0] <<' '<< a[1] <<'\n';
cout << "c" << c << " b" <<b <<"\n";

f(a,c,b);

cout << "A" << a[0] <<' '<< a[1] <<'\n';
cout << "c" << c << " b" <<b <<"\n";

}
