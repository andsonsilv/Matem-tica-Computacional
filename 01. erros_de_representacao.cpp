/* calcule s =somatorio i=1-30000 x

	x = 0,5
		-calculadora s = 15000
		-computador s = 15000
	x = 0,11
		-calculadora s = 3300
		-computador s = 3300,9851074219
*/

#include<iostream>

using namespace std;

int main(void){
	
	float x = 0.11;
	float total = 0.0;
	for(int i = 1; i <= 30000; i++){
		total += x;
	}

	cout << total << endl;
	

	return 0;
}


