#include <iostream>
#include <cmath>

using namespace std;

void fillarray(double *arr, int str, int col)
{
    for (int i = 0; i < str; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "Enter the element of " << i + 1 << " String and " << j + 1 << " Column" << endl;
            cin >> arr[i * col + j];
        }
    }
}


void showarray(double *arr, int str, int col)
{
    for (int i = 0; i < str; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i * col + j] << " ";
        }
        cout << endl;
    }
}

void find_maximum(double *arr, int str, int col, double &max)
{
    bool first = true;
    for (int i = 0; i < str; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if((arr[i * col + j] < 0) && first)
            {
                max = arr[i * col + j];
                first = false;
            }
            if((arr[i * col + j] < 0) && (arr[i * col + j] >= max))
            {
                max = arr[i * col + j];
            }
        }
    }
}

void find_minimum(double *arr, int str, int col, double &min)
{
    bool first = true;
    for (int i = 0; i < str; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if((arr[i * col + j] > 0) && first)
            {
                min = arr[i * col + j];
                first = false;
            }
            if((arr[i * col + j] > 0) && (arr[i * col + j] <= min))
            {
                min = arr[i * col + j];
            }
        }
    }
}
bool compare_abs(double max, double min, double compare)
{
    if(abs(max - min) < compare)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void changing_into_abs(double *arr, int str, int col)
{
    for (int i = 0; i < str; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if(arr[i * col + j] < 0)
            {
                arr[i * col + j] = abs(arr[i * col + j]);
            }
        }
    }
}


int main()
{
    double A[100];
    int rows;
    int cols;
    double compare;
    double max;
    double min;
    cout << "Enter the number of rows" << endl;
    cin >> rows;
    cout << "Enter the number of columns" << endl;
    cin >> cols;
    cout << "Enter compare number" << endl;
    cin >> compare;
    fillarray(A, rows, cols);
    showarray(A, rows, cols);
    find_maximum(A, rows, cols, max);
    find_minimum(A, rows, cols, min);
    cout << "max " << max << endl;
    cout << "min " << min << endl;
    if(compare_abs(max, min, compare))
    {
        changing_into_abs(A, rows, cols);
    }
    cout << "==============================================" << endl;
    showarray(A, rows, cols);



    return 0;
}
