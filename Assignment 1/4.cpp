#include<iostream>

using namespace std;
char CaesarShift(char c, int k)
{ int a = (c-'A' + k)%26;
  int b = (c-'a'+k)%26;
  // check if c would be negative or one_over_fact
  if (a <0){
    a = 26+a;
  }

  if (b <0){
    b = 26+b;
  }

  if ('A'<=c && c<='Z'){ /*if the character is upper case -> lower case*/
    c = a +'a';
  }
  else if('a'<=c && c<='z'){ /*if the character lower case -> upper case*/
    c = b +'A';
  }
  //If it is not character, the function will return the things back
  return c;
}

int main(){
  char s,a;int k;
  cin>>s>>k>>a;
  //What if 2nd number is ! ? We don't get 2nd number?
  while(a!='!'){
    if(s =='e'){
      cout<<CaesarShift(a,k);
    }
    else if(s =='d') {
      cout<<CaesarShift(a,-k);
    }
    cin>>a;
  }
  cout<<'!'<<endl;
  return 0;
}
