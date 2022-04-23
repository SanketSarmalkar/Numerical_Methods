/*
Sanket S.Sarmalkar
Direct Method
*/
#include <stdio.h>
#include <iostream>
#include <limits>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int

#define ROW 100
#define COL 100

void get_coefficient(double[][COL], int, int);
void get_vector(double[], int);
void create_Ab(double[][COL], double[], int, int);
void show_matrix(double[][COL], int, int);
void guass_elimination(double *[ROW], int, int);
void exchange_row(double *[ROW], int, int, int);
void show_solution(double *[ROW], int, int);
void back_substitution(double *[ROW], int, int);
void back_substitution(double *[ROW], int, int, int);

int main()
{
    double Receptacle[ROW][COL]; // store the matrix A
    double Vector[ROW];          // store the vector b
    double *Ab_pointer[ROW];     // store every row of augment matrix (A,b)
    int row, col;                // store the row/col of the matrix;
    int i;

    printf("Enter the coefficient matrix's size (less than %d * %d): ", ROW, COL - 1);
    while (scanf("%d%d", &row, &col) == 2)
    {
        get_coefficient(Receptacle, row, col);   // get the value of matrix A
        get_vector(Vector, row);                 // get the value of vector b
        create_Ab(Receptacle, Vector, row, col); // create the augment matrix (A,b)

        printf("\nThe linear equations in the form of augmented matrix as follow:\n");
        show_matrix(Receptacle, row, col + 1); // output the augment matrix (A,b)

        for (i = 0; i < ROW; i++) // make every Ab_pointer points every row of the augment matrix (A,b)
            Ab_pointer[i] = Receptacle[i];

        guass_elimination(Ab_pointer, row, col + 1); // get the result by the Guass Elimination

        printf("\nEnter the coefficient matrix's size (less than %d * %d, q to quit): ", ROW, COL - 1);
    }
    printf("Bye!\n");

    return 0;
}

/*************************************************
 Function:       get_coefficient
 Description:    get the matrix coefficient that user input in console
 *************************************************/
void get_coefficient(double matrix[ROW][COL], int row, int col)
{
    int i, j;

    printf("Enter the coefficient (%d * %d):\n", row, col);
    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
            scanf("%lf", &matrix[i][j]);

    return;
}

/*************************************************
 Function:       get_vector
 Description:    get the vector that user input in console
 *************************************************/
void get_vector(double vector[ROW], int row)
{
    int i;

    printf("Enter the vector (size is %d):\n", row);
    for (i = 0; i < row; i++)
        scanf("%lf", &vector[i]);

    return;
}

/*************************************************
 Function:       create_Ab
 Description:    create the augment matrix
 *************************************************/
void create_Ab(double matrix[ROW][COL], double vector[ROW], int row, int col)
{
    int i;

    for (i = 0; i < row; i++)
        matrix[i][col] = vector[i];

    return;
}

/*************************************************
 Function:       show_matrix
 Description:    output the matrix
 *************************************************/
void show_matrix(double matrix[ROW][COL], int row, int col)
{
    int i, j;

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
            printf("%-8.3f", matrix[i][j]);
        putchar('\n');
    }

    return;
}

/*************************************************
 Function:       guass_elimination
 Description:    transform the matrix to the upper
 triangle matrix and get the solution
 by the Guass Elimination!
 *************************************************/
void guass_elimination(double *matrix[ROW], int row, int col)
{
    int result;        // the flag of the number of the solution
    int rankA, rankAb; // store the rank of matrix A or augment matrix (A,b)
    int i, j, k, l;
    double coe; // store the multiple of two rows temporarily

    // transform the matrix to the upper triangle matrix
    for (i = 0; i < row; i++)
    {
        // find the first non-zero value after exchange the row of the matrix
        for (j = i; j < col - 1; j++)
        {
            if (fabs(matrix[i][j]) < 0.00001)
            {
                exchange_row(matrix, i, j, row);
                if (fabs(matrix[i][j]) > 0.00001)
                {
                    break;
                }
            }
            else
                break;
        }

        // do the elimination
        for (k = i + 1; k < row; k++)
        {
            if (matrix[i][j] == 0)
                break;
            coe = matrix[k][j] / matrix[i][j];
            for (l = j; l < col; l++)
            {
                matrix[k][l] -= coe * matrix[i][l];
            }
        }
    }

    rankA = rankAb = 0;

    // get the value of rank(A)
    for (i = 0; i < row; i++)
    {
        for (j = i; j < col - 1; j++)
        {
            if (fabs(matrix[i][j]) > 0.00001)
            {
                rankA++;
                break;
            }
        }
    }

    // get the value of rank(A,b)
    for (i = 0; i < row; i++)
    {
        for (j = i; j < col; j++)
        {
            if (fabs(matrix[i][j]) > 0.00001)
            {
                rankAb++;
                break;
            }
        }
    }

    // rank(A)!=rank(A,b) => no solution
    if (rankA != rankAb)
    {
        result = -1;
        printf("\nAfter elimination:\n");
        show_solution(matrix, row, col);
        printf("\nThere is no solution for the linear equations!\n");
    }

    // rank(A)=rank(A,b)=col => only one solution
    else if (rankA == col - 1)
    {
        result = 0;
        printf("\nAfter elimination:\n");
        show_solution(matrix, row, col);
        printf("\nThere is only one solution for the linear equations!\n");
        back_substitution(matrix, row, col - 1);
    }

    // rank(A)=rank(A,b)<col => infinite solutions
    else
    {
        result = 1;
        printf("\nAfter elimination:\n");
        show_solution(matrix, row, col);
        printf("\nThere are infinite solutions for the linear equations!\n");
        back_substitution(matrix, row, col - 1, rankA);
    }

    return;
}

/*************************************************
 Function:       exchange_row
 Description:    exchange the row of the matrix
 to ensure the matrix[i][j]!=0
 (except matrix[i][j] ~ matrix[row-1][j] all 0)
 *************************************************/
void exchange_row(double *matrix[ROW], int i, int j, int row)
{
    int k;
    double *temp;

    for (k = i + 1; k < row; k++)
    {
        if (fabs(matrix[k][j]) > 0.00001)
        {
            temp = matrix[i];
            matrix[i] = matrix[k];
            matrix[k] = temp;
            return;
        }
    }

    return;
}

/*************************************************
 Function:       show_solution
 Description:    output the upper triangle matrix after elimination
 *************************************************/
void show_solution(double *matrix[ROW], int row, int col)
{
    int i, j;

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
            printf("%-8.3f", matrix[i][j]);
        putchar('\n');
    }

    return;
}

/*************************************************
 Function:       back_substitution
 Description:    to find the unique solution by back-substitution
 *************************************************/
void back_substitution(double *matrix[ROW], int row, int col)
{
    int i, j;
    double temp;
    double x[COL]; // store the unique solution x

    for (i = 0; i < col; i++)
    {
        temp = matrix[col - 1 - i][col];
        for (j = 0; j < i; j++)
        {
            temp -= x[col - 1 - j] * matrix[col - 1 - i][col - 1 - j];
        }
        x[col - 1 - i] = temp / matrix[col - 1 - i][col - 1 - i];
    }

    // output the solution
    printf("The solution is[", i, x[i]);
    for (i = 0; i < col; i++)
    {
        printf("%8.3f", x[i]);
    }
    printf("]\n");

    return;
}

/*************************************************
 Function:       back_substitution
 Description:    to find the infinite solutions
 step 1:find the special solution Xp for Ax=b
 step 2:find the general solutions Xn for Ax=0
 *************************************************/
void back_substitution(double *matrix[ROW], int row, int col, int rankA)
{
    int i, j, k, n;
    int pivot[COL], free[COL]; // store the position of pivot/free
    double temp;
    double x_p[COL];            // store the special solution Xp for Ax=b
    double x_n[COL][COL] = {0}; // store the general solutions for Ax=0

    // find the position of pivot
    for (i = 0; i < rankA; i++)
        for (j = i; j < col; j++)
            if (fabs(matrix[i][j]) > 0.00001)
            {
                pivot[i] = j;
                break;
            }

    // find the position of free
    j = n = 0;
    for (i = 0; i < col; i++)
        if (i == pivot[j])
        {
            j++;
        }
        else
        {
            free[n] = i;
            x_p[i] = 1; // set the free value of Xp
            n++;
        }

    // get a special solution for Ax=b
    for (i = 0; i < rankA; i++)
    {
        n = rankA - 1 - i; // get current row number
        temp = matrix[n][col];
        for (j = pivot[n] + 1; j < col; j++)
        {
            temp -= x_p[j] * matrix[n][j];
        }
        x_p[pivot[n]] = temp / matrix[n][pivot[n]];
    }

    // set the free value of Xn
    for (i = 0; i < col - rankA; i++)
        x_n[i][free[i]] = 1;

    // get the general solutions for Ax=0
    for (k = 0; k < col - rankA; k++)
    {
        for (i = 0; i < rankA; i++)
        {
            n = rankA - 1 - i; // get current row number
            temp = 0;
            for (j = pivot[n] + 1; j < col; j++)
            {
                temp -= x_n[k][j] * matrix[n][j];
            }
            x_n[k][pivot[n]] = temp / matrix[n][pivot[n]];
        }
    }

    // output the solution
    printf("The solutions are X=Xp+Xn.\n");
    printf("The Vector Xp is:[");
    for (i = 0; i < col; i++)
    {
        printf("%8.3f", x_p[i]);
    }
    printf("]\n");

    for (k = 0; k < col - rankA; k++)
    {
        printf("The Vector Xn%d is:[", k + 1);
        for (i = 0; i < col; i++)
        {
            printf("%8.3f", x_n[k][i]);
        }

        printf("]\n");
    }

    return;
}