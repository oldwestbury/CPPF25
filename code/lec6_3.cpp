#include <iostream>
using namespace std;

const int ARRAY_LENGTH = 20;
#if 0
int main() {

	
	
	int A[ARRAY_LENGTH];

	int B;
	for (int i = 0; i < ARRAY_LENGTH; i++) {
		cout << "A [" <<i <<"]"  << A[i] << "\n";
	}

	cout << A[-1];


}

#endif


int main() {

	char tictactoe[3][3];

	for (int i=0;i<3;i++)
		for (int j = 0; j < 3; j++) {

			cout << i << ' ' << j << ' ';
			char* o = &(tictactoe[i][j]);
			int diff = ((char*)o) - (char*)tictactoe;
			cout << (void*)o <<' ' <<diff <<"\n";
		}

}

