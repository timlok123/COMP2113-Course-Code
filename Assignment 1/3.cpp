#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

//function to find value of the factorial
double one_over_fact(int a) //a must be greater than or equal to 0
{
  double result=1;int i;
  if(a==0){
    return 1;
  }
  else{
    for(i=a;i>0;i--){
      result*=pow(i,-1);
      }
    return result;
  }
}

int main(){
  double x,result,x_power,pm; int n,i=0;
  cin>>x>>n;

  if(-3<=x<=3 && 0<=n<=50){
    cout<<"sin(x) by cmath: "<<fixed<<setprecision(15);
    cout<<sin(x)<<endl;
    cout<<"Taylor series approximation:"<<endl;

    for(i=0;i<=n;++i){
      //if-else statement to set positive or negative
      if(i%2==0){
        pm = 1;
      }
      else{
        pm = -1;
      }

      x_power = pow(x,2*i+1);
      result = result+ one_over_fact(2*i+1)*x_power*pm;
      cout<<i<<" "<<fixed<<setprecision(5)<<result<<endl;
    }
  }
  else{
    cout<<"your input invalid, please try again"<<endl;
    //What if they don't input int and float? Like string?}
   }
  return 0;
}
