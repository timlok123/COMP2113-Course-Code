#include <iostream>

const int MAXDIM = 10;

//----------------------DO NOT CHANGE ANYTHING ABOVE THIS LINE------------------

using namespace std;

void read_matrix(int matrix[][MAXDIM], int &dim){
  //Ask the users to input the dim
  cin>>dim;

  //Ask the users to input all the numbers in matrix
  for(int i=0; i<dim; i++){
    for(int j =0; j<dim;j++){
      int a;
      cin>>a;
      matrix[i][j] = a;
    }
  }
}

void display_inner_cw_rotated(int matrix[][MAXDIM],int dim){


  // take the inner matrix & rotate the matrix by 90 degree
  for(int i=1;i<=(dim-2);i++){
    for(int j=(dim-2); j>=1;j--){
      cout<<matrix[j][i]<<" ";
    }
    cout<<endl;
 }
}

//----------------------DO NOT CHANGE ANYTHING BELOW THIS LINE------------------

int main()
{
  int matrix[MAXDIM][MAXDIM]{};
  int dim = 0;

  read_matrix(matrix, dim);
  display_inner_cw_rotated(matrix, dim);

  return 0;
}


// Points to Note: Mark to Notion later
// 1. When taking square matrix, remember to write void read_matrix(int matrix[][MAXDIM], int dim){
