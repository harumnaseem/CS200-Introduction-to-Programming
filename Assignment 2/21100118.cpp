#include <iostream>
#include <fstream>

using namespace std;
void AllocateTriangularMatrix(int ***arr, int& n)
{
    *arr = new int*[n];
	int Count = n;
	for (int i=0; i<n ; i++)
	{
		(*arr)[i] = new int [Count];
		Count++;
	}
}

void Input(int*** arr, int n)
{
        for (int i=0; i<n ; i++)
		{

			for (int Count = i; Count<n; Count++)
			{
			    cout<<"Enter the index " << i << " "<< Count<<": ";
				cin>> (*arr)[i][Count];
				cout<<endl;
			}
                cout << endl;
		}
}

void Deallocating_array(int ***arr, int& n)
{
    for(int i=0; i<n; i++)
    {
        delete[](*arr)[i];
    }
        delete [](*arr);
}
int getItem(int ** matrix, int rowIndex, int colIndex)
{

    cout<<"Matrix in row wise form is: "<<endl;
    for(int i=0; i<rowIndex; i++)
    {
        for(int j=0; j<colIndex; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
    }
    cout<<endl<<"Matrix in column wise form is: "<<endl;
    for(int i=0; i<colIndex; i++)
    {
        for(int j=0; j<rowIndex; j++)
        {
            cout<<matrix[j][i]<<endl;
        }
    }
    int row, column;
    cout<<"Enter the row index of the number you want from the original matrix: ";
    cin>> row;
    cout<<endl<<"Enter the column index of the number you want from the original matrix: ";
    cin>> column;

    cout<<"The number at index "<< row <<" "<< column<<" is "<<matrix[row][column];

}
void Print_matrix(int ***arr, int n)
{
    cout<<"The upper triangular matrix is: "<<endl;
    int Count=0;
    for (int i=0; i<n ; i++)
		{
            if(i>0)
            {
                for(int j=0; j<i;j++)
                    cout<<"0 ";
            }
			for (Count = i; Count<n; Count++)
			{
				cout<< ((*arr)[i][Count])<<" ";

			}
                cout << endl;
		}
}

void Input_data(ifstream& input_file, int*** arr1, int*** arr2, int& n)
{
    input_file>>n;

    *arr1 = new int*[n];
    *arr2 = new int*[n];

	for (int i=0; i<n ; i++)
	{
		(*arr1)[i] = new int [n];
	}
    for(int i=0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
			{
			    input_file>> (*arr1)[i][j];
			}
    }

    for (int i=0; i<n ; i++)
	{
		(*arr2)[i] = new int [n];
	}
    for(int i=0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
			{
			    input_file>> (*arr2)[i][j];
			}

    }
    cout<<"MATRIX 1"<<endl;
    Print_matrix(arr1,n);
    getItem(*arr1, n, n);
    cout<<endl<<"MATRIX 2"<<endl;
    Print_matrix(arr2,n);
    getItem(*arr2, n, n);
    for(int i=0; i<n; i++)
    {
        delete[](*arr1)[i];
    }
        delete [](*arr1);

    for(int i=0; i<n; i++)
    {
        delete[](*arr2)[i];
    }
        delete [](*arr2);
}

bool MultiplyMatrices(int **A, int **B, int ***C, int m, int n, int r)
{

    if(C != NULL)
    {
        return false;
    }

    AllocateTriangularMatrix(C,n);
    int sum;
    for (int k = 0; k < m; ++k)
    {
            for (int i = 0; i < r; ++i)
            {
                sum = 0;

                for (int j = 0; j <= i; ++j)
                {
                     sum += (A[k][j])*(B[j][i]);
                }

                (*C)[k][i] = sum;
            }
    }
    cout<<"ANSWER IS: "<<endl;
    Print_matrix(C,n);
    return true;
}
void Swap_rows(int ** matrix, int n1, int n2, int n)
{
    int *temp;
    temp = matrix[n1 - 1];
    matrix[n1 - 1] = matrix[n2 - 1];
    matrix[n2 - 1] = temp;
    cout<<"The swapped matrix is: "<<endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout <<endl;
    }
}
void delete_row(int **arr, int row, int n)
{
    int del_rindex = row - 1;
    delete [] arr[del_rindex];

    int new_size = n -1;
    int ** temp = new int *[new_size];
    int Count =0;

    for(int i=0; i<n; i++)
    {
        if(i==del_rindex)
            continue;
        else
        {
            temp[Count]= arr[i];
            Count++;
        }
    }
    delete [] arr;

    arr=temp;

    for(int i=0; i<new_size; i++)
    {
        for(int Count=0; Count<new_size; Count++)
        {
            if(i>Count || (i == del_rindex && Count ==del_rindex))
            {
                arr[i][Count] = 0;
            }
                cout<<arr[i][Count]<<" ";
        }
            cout<<endl;
    }
}

int main()
{
    int n;
    cout<<"NOTE: if you enter a decimal value then it will be discarded. For instance, if you enter 4.5 then only 4 will be considered."<<endl;
    cout<<"Enter the size of your nxn matrix: ";
    while(!(cin>>n))
        {
            cout<<"Not a valid input size!"<<endl<<endl;
            cin.clear();
 	        cin.ignore(999999,'\n');
 	        cout<<"Enter your size again: ";
        }
    cout<<endl;
    int ** matrix = NULL;
    int ** matrixa =NULL, **matrixb =NULL;

    AllocateTriangularMatrix(&matrix, n);
    Input(&matrix, n);
    Print_matrix(&matrix, n);

    ifstream input_file;
    input_file.open("sampleMatrices.txt");
    if(input_file.fail())
    {
        cout<<"Input file opening failed.";
    }
    cout<<endl<<endl<<"The date from the file is "<<endl;
    Input_data(input_file, &matrixa, &matrixb , n);
    input_file.close();

    int ** matrixS=NULL;
    int n1,n2;
    cout<<endl<<endl<<"Enter the size of the matrices you want to swap rows of: ";
    cin>>n;
    cout<<endl;
    cout<<"Enter the row you want to swap: ";
    cin>>n1;
    cout<<endl<<"Enter the row you want too swap it with: ";
    cin>>n2;
     matrixS = new int*[n];
	for (int i=0; i<n ; i++)
	{
            (matrixS)[i]= new int[n];
	}
    cout<<endl;
     for (int i=0; i<n ; i++)
		{
            if(i>0)
            {
                for(int j=0; j<i;j++)
                    matrixS[i][j]=0;
            }
			for (int Count = i; Count<n; Count++)
			{
			    cout<<"Enter the index value "<< i <<" "<< Count<<" : ";
                cin>> matrixS[i][Count];
			}
                cout << endl<<endl;;
		}
	Print_matrix(&matrixS, n);
    Swap_rows(matrixS, n1, n2, n);
    for(int i=0; i<n; i++)
    {
        delete[]matrixS[i];
    }
        delete []matrixS;

    /*
    int ** matrix1=NULL, **matrix2=NULL, ***matrix3=NULL;
    cout<<"Multiplication -"<<endl;
    cout<<endl<<"Enter the size of the matrices you want to multiply: ";
    cin>>n;
    cout<<endl;
    matrix1 = new int*[n];
	for (int i=0; i<n ; i++)
	{
            (matrix1)[i]= new int[n];
	}
    cout<<endl;
     for (int i=0; i<n ; i++)
		{
            if(i>0)
            {
                for(int j=0; j<i;j++)
                    matrix1[i][j]=0;
            }
		}
    cout<<endl<<"MATRIX 1"<<endl;
    Input(&matrix1,n);
    Print_matrix(&matrix1,n);
    matrix2 = new int*[n];
	for (int i=0; i<n ; i++)
	{
            (matrix2)[i]= new int[n];
	}
    cout<<endl;
     for (int i=0; i<n ; i++)
		{
            if(i>0)
            {
                for(int j=0; j<i;j++)
                    matrix2[i][j]=0;
            }
		}
    cout<<endl<<"MATRIX 2"<<endl;
    Input(&matrix2,n);
    Print_matrix(&matrix2,n);
    cout<<MultiplyMatrices(matrix1, matrix2, matrix3, n, n, n);
    */
    int **matrix4,row;

    cout<<"Enter the size of the current matrix: ";
    cin>>n;
    matrix4= new int*[n];
    for (int i=0; i<n ; i++)
	{
            matrix4[i]= new int[n];
	}
    for (int i=0; i<n ; i++)
		{
            if(i>0)
            {
                for(int j=0; j<i;j++)
                    matrix4[i][j]=0;
            }
			for (int Count = i; Count<n; Count++)
			{
			    cout<<"Enter the index value "<< i <<" "<< Count<<" : ";
                cin>> matrix4[i][Count];
			}
                cout << endl<<endl;;
		}
	Print_matrix(&matrix4, n);
    cout<<endl<<"Enter the row you want to delete: ";
    cin>>row;
    delete_row(matrix4, row , n);
    return 0;
}
