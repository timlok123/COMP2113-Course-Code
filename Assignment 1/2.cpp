#include<iostream>
#include<iomanip>

using namespace std;

int main(){
  float x,result=0,a;
  int n,i=0;
  // Do we need to check whether n is valid?
  // What if i is not positive?
  // What if the users don't input numnbers
  // What if they input sth like 1 2 3 4 5 6 => incomplete run ??
  cin>>x>>n;
  if(n==0){
    cin>>a;
    result = a;
  }
  else{
    for(i=n;i>0;i--){
      if(i==n){
        cin>>result>>a;
        result = result*x + a;
      }
      else{
        cin>>a;
        result = result*x + a;
      }
    }
  }

  // Set the precision here 
  cout<<fixed;
  cout<<setprecision(6);
  cout<<result<<endl;

  return 0;
}
