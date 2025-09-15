#include <iostream>
using namespace std;
#include <string.h>
const int ARRAY_LENGTH = 10;

int main() {

	int A[ARRAY_LENGTH]={5};

	//memset(A,2,sizeof(A));
	for (int i = 0; i < ARRAY_LENGTH; i++) {
		cout << "A [" <<i <<"]"  << A[i] << "\n";
	}
	
    cout << A << "\n";
    
    cout << "size of A " << sizeof(A) << "\n";
    cout << "&A[0] " << &A[0] << "\n";
    cout << "&A[1] "<< &A[1] << "\n";
    cout << "&A[2]" << &A[2] << "\n";
    
}