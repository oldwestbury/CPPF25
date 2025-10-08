
#include <iostream>
using namespace std;
#include <cstring>
void fn(){

	int arr[] = { 10, 20, 30 };
	int* ptr = arr;  // ptr points to the first element of arr

	cout << *ptr << endl;  // Output: 10
	ptr++;                 // Move to the next integer
	cout << *ptr << endl;  // Output: 20
	ptr++;                 // Move to the next integer
	cout << *ptr << endl;  // Output: 30

	ptr++;                 // Move to the next integer
	cout << *ptr << endl;  
}

void f1() {

	int x = 70 + 256 * 111;
	int* ptr;

	ptr = &x;

	cout << "x" << x << endl;

	cout << "ptr" << ptr << endl;
	cout << *ptr << endl;
	x++;

	cout << x << endl;
	cout << ptr << endl;
	cout << *ptr << endl;
	ptr++;

	cout << x << endl;
	cout << ptr << endl;
	cout << *ptr << endl;


	char* p;

	p = (char*)(&x);


	cout << *p << "\n";
	p++;

	cout << *p << "\n";

}
void f3() {
	char h[] = "Hello to C++"; //12 characters plus null char
	int l = sizeof(h) / sizeof(char);
	char* p = h + l-1;
	for (int i = 0; i < l; i++,p--) {
		cout << h[i] << "\t" << *p << "\n";
	}
	h[l-1] = 'A';

	cout << h <<"\n";
	h[6] = 0;
	cout << h << "\n";

}

char toupper_(char c) {
	if (c >= 'a' && c <= 'z') {

		c = c - 'a' + 'A';
	}
	return c;
}
char tolower_(char c) {
	if (c >= 'A' && c <= 'Z') {
		c = c - 'A' + 'a';
	}
	return c;
}


char* pattern_case(char* s) {
	char* r = s;
	int i = 0;
	for (; *s!='\0'; s++, i++) {
		if (i & 1)*s = tolower_(*s);
		else *s = toupper_(*s);
	}
	return r;
}

int  strlen_(char* s) {
	
	int i = 0;
	for (; *s != '\0'; s++, i++);
	return i;
}


int main() {
	
	char s[] = "This is only a test";
	cout << strlen_(s);
	cout << strlen(s);
	//cout << pattern_case(s);

	int* p=0;
	//*p = 0;


	//cout << "What a beautiful world!!";

}