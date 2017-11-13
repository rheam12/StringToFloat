//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
// You are allowed float.h

//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING
#include <iostream>
using namespace std;
#endif

//////////////////////////////////////////////////////////////
//
// Function declarations; do not remove
enum type {GOTSIGN,GOTDIGIT,EXPONENT,DONE,REJECTED,SIGNEDEXP,GOTDEC};
bool stringToFloat(const char input[], float& value);

//////////////////////////////////////////////////////////////
//
// Your code here ...
void power(int n, float& x)
{
    float temp = x;
    while (n > 1) {
        x = x * temp;
        n--;
    }
    //return x;
}
bool stringToFloat(const char input[], float& value) {
  float val=0;
	int i=0;
	int dec=1;
	int n=1;
	type state = GOTSIGN;
	bool sigh=false;
	bool sign=false;
	bool decCheck=false;
	int check;
	while(input[i]!=0){
		//i++;
		//cout<<"why the fuck?"<<endl;
		switch(state){
			//case GOTDEC:
				//dec=dec*10;
				//state=GOTDIGIT;
			case GOTSIGN:
				if(input[i]=='-'){
					sigh=true;
					state=GOTDIGIT;
					i++;
					break;
				}
				else if(input[i]=='+'){
					sigh=false;
					state=GOTDIGIT;
					i++;
					break;
				}
				else
					state=GOTDIGIT;
			case GOTDIGIT:
				if(input[i]=='0'){
					check=(int) input[i];
					//cout<<check<<endl;
					val=val*10+0;
					state=GOTDIGIT;
					i++;
					if(decCheck){
					dec=dec*10;
					}
					break;
				}
				else if(input[i]=='1'){
					val=val*10+1;
					state=GOTDIGIT;
					i++;
					if(decCheck){
					dec=dec*10;
					}
					break;
				}
				else if(input[i]=='2'){
					val=val*10+2;
					state=GOTDIGIT;
					i++;
					if(decCheck){
					dec=dec*10;
					}
					break;
				}
				else if(input[i]=='3'){
					val=val*10+3;
					state=GOTDIGIT;
					i++;
					if(decCheck){
					dec=dec*10;
					}
					break;
				}
				else if(input[i]=='4'){
					val=val*10+4;
					state=GOTDIGIT;
					i++;
					if(decCheck){
					dec=dec*10;
					}
					break;
				}
				else if(input[i]=='5'){
					val=val*10+5;
					state=GOTDIGIT;
					i++;
					if(decCheck){
					dec=dec*10;
					}
					break;
				}
				else if(input[i]=='6'){
					val=val*10+6;
					state=GOTDIGIT;
					i++;
					if(decCheck){
					dec=dec*10;
					}
					break;
				}
				else if(input[i]=='7'){
					val=val*10+7;
					state=GOTDIGIT;
					i++;
					if(decCheck){
					dec=dec*10;
					}
					break;
				}
				else if(input[i]=='8'){
					val=val*10+8;
					state=GOTDIGIT;
					i++;
					if(decCheck){
					dec=dec*10;
					}
					break;
				}
				else if(input[i]=='9'){
					val=val*10+9;
					state=GOTDIGIT;
					i++;
					if(decCheck){
					dec=dec*10;
					}
					break;
				}
				else if(input[i]=='.'){	
					decCheck=true;
					i++;
					state=GOTDIGIT;
					break;
				}
				else if(input[i]=='e'){
					state=SIGNEDEXP;
					i++;
					n=0;
					break;
				}
				else{
					state=REJECTED;
					break;
				}
				if(input[i+1]==0){
					state=DONE;
				}
			case SIGNEDEXP:
				if(input[i]=='-'){
					sign=true;
					state=EXPONENT;
					i++;
					break;
				}
				else if(input[i]=='+'){
					sign=false;
					state=EXPONENT;
					i++;
					break;
				}
				else
					state=EXPONENT;
			case EXPONENT:
			if(input[i]=='0'){
					n=n*10+0;
					state=EXPONENT;
					i++;
					break;
				}
				else if(input[i]=='1'){
					n=n*10+1;
					state=EXPONENT;
					i++;
					break;
				}
				else if(input[i]=='2'){
					n=n*10+2;
					state=EXPONENT;
					i++;
					break;
				}
				else if(input[i]=='3'){
					n=n*10+3;
					state=EXPONENT;
					i++;
					break;
				}
				else if(input[i]=='4'){
					n=n*10+4;
					state=EXPONENT;
					i++;
					break;
				}
				else if(input[i]=='5'){
					n=n*10+5;
					state=EXPONENT;
					i++;
					break;
				}
				else if(input[i]=='6'){
					n=n*10+6;
					state=EXPONENT;
					i++;
					break;
				}
				else if(input[i]=='7'){
					n=n*10+7;
					state=EXPONENT;
					i++;
					break;
				}
				else if(input[i]=='8'){
					n=n*10+8;
					state=EXPONENT;
					i++;
					break;
				}
				else if(input[i]=='9'){
					n=n*10+9;
					state=EXPONENT;
					i++;
					break;
				}
				else{
					state=REJECTED;
					break;
				}
				
			case DONE:
				return true;
			case REJECTED:
				return false;
		}
	}
			//cout<<dec<<endl;
				if(sigh)
					val=val*(-1);
				val=val/dec;
				value=val;
				power(n,value);
				if(sign)
					value=1/value;
				if(n==0)
					value=1;
	return true;
}

//////////////////////////////////////////////////////////////
//
// Test Driver
//
// Do not remove the #ifndef and its associated #endif
// This is required so that when you submit your code,
// this test driver will be ignored by Marmoset
//

#ifndef MARMOSET_TESTING
int main(const int argc, const char* const argv[]) {
  
  // Some test driver code here ....
  float argv1;

  if (argc < 2) {
    cerr << "Error: Usage: " << argv[0] << " <float>" << endl;
    return -1;
  }

  if (stringToFloat(argv[1],argv1)) 
    cout << "argv[1] is a float with value: " << argv1 <<endl;
  else
    cout << "argv[1] is not a float. argv[1]: " <<argv[1] << endl;
  return 0;
}

#endif
