//main.cpp

#include<iostream>
#include "d2boh.h"
using namespace std;

int main(){
  int n;
  int output1[10]={0};
  int output2[10]={0};
  char output_char[10] = {'0'};

  cout<< "Enter a positive integer in the range [1, 100]: ";
  cin>> n;
  cout<<"Binary of the given number = ";
  decimal_to_binary(n,output1);
  int k=0;
  for(int i=9;i>=0;i--){
    if(output1[i]!=0){
      k = i;
      break;
    }
  }
  for(int i=k;i>=0;i--){
    cout<<output1[i];
  }
  cout<<endl;

  cout<<"Octal of the given number = ";
  decimal_to_octal(n,output2);

  for(int i=9;i>=0;i--){
    if(output2[i]!=0){
      k = i;
      break;
    }
  }
  for(int i=k;i>=0;i--){
    cout<<output2[i];
  }
  cout<<endl;

  cout<<"Hexadecimal of the given number = ";
  decimal_to_hexadecimal(n,output_char);

  for(int i=9;i>=0;i--){
    if(output_char[i]!=0){
      k = i;
      break;
    }
  }
  for(int i=k;i>=0;i--){
    cout<<output_char[i];
  }
  cout<<endl;

}
