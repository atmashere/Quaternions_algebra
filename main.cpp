/* Standard library	*/
#include <tchar.h>
#include <stdio.h>
#include <iostream>

/* Custom libraries	*/
#include "array.cpp"



/* Main program	*/
int main(int argc, _TCHAR* argv[])
{
    //unsigned int CountIndex_Vektor_x = 0, CountIndex_Vektor_y = 0, CountIndex_Vektor_z = 0;
    int i = 0, j = 0;
    double temp = 0;

    /* Working with vectors	*/
    TVector Vektor_x;
    TVector Vektor_y(3);
    TVector Vektor_z(3);
    TVector Vektor_temp(3);

    Vektor_x.resize(3);

    for (i=0; i<3; i++)
    {
        Vektor_x[i] = i+1;
        Vektor_y[i] = i+3;
        Vektor_z[i] = i+5;
    }

    /* [1] Vector	*/
    printf("\n[1]	Vector");
    printf("\n---------------------------------------------------------------------");

    /* [1.1] Creating instances of vectors	*/
    printf("\n[1.1]	Creating instances of vectors\n");
    printf("\nCount index Vektor_x = %i", Vektor_x.size());
    printf("\nCount index Vektor_y = %i", Vektor_y.size());
    printf("\nCount index Vektor_z = %i", Vektor_z.size());

    printf("\n\nData Vektor_x:\n");
    for (i=0; i<3; i++)
    {
        printf("%5.2f   ", Vektor_x[i]);
    }

    printf("\n\nData Vektor_y:\n");
    for (i=0; i<3; i++)
    {
        printf("%5.2f   ", Vektor_y[i]);
    }

    printf("\n\nData Vektor_z:\n");
    for (i=0; i<3; i++)
    {
        printf("%5.2f   ", Vektor_z[i]);
    }

    /* [1.2] Vector addition	*/
    printf("\n\n------------------------------------------------------");
    printf("\n[1.2]	Vector addition\n");

    Vektor_temp = Vektor_x + Vektor_y + Vektor_z;

    printf("\nData Vektor (_x + _y + _z):\n");
    for (i=0; i<3; i++)
    {
        printf("%5.2f   ", Vektor_temp[i]);
    }

    /* [1.3] Vector subtraction	*/
    printf("\n\n------------------------------------------------------");
    printf("\n[1.3]	Vector subtraction\n");

    Vektor_temp = Vektor_x - Vektor_y - Vektor_z;

    printf("\nData Vektor (_x - _y - _z):\n");
    for (i=0; i<3; i++)
    {
        printf("%5.2f   ", Vektor_temp[i]);
    }

    /* [1.4] Vector multiplication - vectorial	*/
    printf("\n\n------------------------------------------------------");
    printf("\n[1.4]	Vector multiplication - vectorial\n");

    Vektor_temp = Vektor_x ^ Vektor_y;

    printf("\nData Vektor (_x ^ _y):\n");
    for (i=0; i<3; i++)
    {
        printf("%5.2f   ", Vektor_temp[i]);
    }

    /* [1.5] Vector multiplication - scalar	*/
    printf("\n\n------------------------------------------------------");
    printf("\n[1.5]	Vector multiplication - scalar\n");

    temp = Vektor_x * Vektor_y;
    printf("\nVektor_x * Vektor_y = %5.2f", temp);

    /* [1.6] Vector multiplication by a constant	*/
    printf("\n\n------------------------------------------------------");
    printf("\n[1.6]	Vector multiplication by a constant\n");

    temp = 7.0;
    Vektor_temp = Vektor_z * temp;

    printf("\nData Vektor (_z * 7.0):\n");
    for (i=0; i<3; i++)
    {
        printf("%5.2f   ", Vektor_temp[i]);
    }

    /* [1.7] Module of the vector	*/
    printf("\n\n------------------------------------------------------");
    printf("\n[1.7]	Module of the vector\n");
    printf("\nModule of the vector _z = %5.2f", Vektor_z.length());

    /* [1.8] Normalization of the vector	*/
    printf("\n\n------------------------------------------------------");
    printf("\n[1.8]	Normalization of the vector\n");

    Vektor_temp = Vektor_z;
    Vektor_temp.norm();

    printf("\nData Vektor _z (Normalization):\n");
    for (i=0; i<3; i++)
    {
        printf("%5.2f   ", Vektor_temp[i]);
    }

    /* [1.9] Negation of the vector	*/
    printf("\n\n------------------------------------------------------");
    printf("\n[1.9]	Negation of the vector\n");

    Vektor_temp = - Vektor_z;

    printf("\nData Vektor _z (Negation):\n");
    for (i=0; i<3; i++)
    {
        printf("%5.2f   ", Vektor_temp[i]);
    }



    /* Working with matrixs	*/
    TMatrix Matrix_x;
    TMatrix Matrix_y(3,5);
    TMatrix Matrix_z(5,6);
    TMatrix Matrix_v(5,3);
    TMatrix Matrix_temp(3,5);
    TMatrix Matrix_edin(5,5);
    TMatrix Matrix_ga(3,3);

    Matrix_x.resize(3,5);

    for (i=0; i<3; i++)
    {
        for (j=0; j<5; j++)
        {
            Matrix_x(i,j) = i+j*2.0;
            Matrix_y(i,j) = i+j/2.0;
        }
    }

    for (i=0; i<5; i++)
    {
        for (j=0; j<6; j++)
        {
            Matrix_z(i,j) = i+j;
        }
    }

    for (i=0; i<5; i++)
    {
        for (j=0; j<3; j++)
        {
            Matrix_v(i,j) = i+j+2;
        }
    }

    Matrix_ga(0,0) = 1;
    Matrix_ga(0,1) = 7;
    Matrix_ga(0,2) = 3;

    Matrix_ga(1,0) = -4;
    Matrix_ga(1,1) = 9;
    Matrix_ga(1,2) = 4;

    Matrix_ga(2,0) = 0;
    Matrix_ga(2,1) = 3;
    Matrix_ga(2,2) = 2;

    /* [2] Matrix	*/
    printf("\n\n\n[2]	Matrix");
    printf("\n---------------------------------------------------------------------");

    /* [2.1] Creating instances of matrix	*/
    printf("\n[2.1]	Creating instances of matrix\n");

    printf("\nCount string Matrix_x = %i", Matrix_x.rowCount());
    printf("\nCount column Matrix_x = %i", Matrix_x.colCount());

    printf("\n\nCount string Matrix_y = %i", Matrix_y.rowCount());
    printf("\nCount column Matrix_y = %i", Matrix_y.colCount());

    printf("\n\nCount string Matrix_z = %i", Matrix_z.rowCount());
    printf("\nCount column Matrix_z = %i", Matrix_z.colCount());

    printf("\n\nCount string Matrix_v = %i", Matrix_v.rowCount());
    printf("\nCount column Matrix_v = %i", Matrix_v.colCount());

    printf("\n\nCount string Matrix_ga = %i", Matrix_ga.rowCount());
    printf("\nCount column Matrix_ga = %i", Matrix_ga.colCount());

    printf("\n\nData Matrix_x:\n");
    for (i=0; i<3; i++)
    {
        for (j=0; j<5; j++)
        {
            printf("%5.2f   ", Matrix_x(i,j));
        }
        printf("\n");
    }

    printf("\nData Matrix_y:\n");
    for (i=0; i<3; i++)
    {
        for (j=0; j<5; j++)
        {
            printf("%5.2f   ", Matrix_y(i,j));
        }
        printf("\n");
    }

    printf("\nData Matrix_z:\n");
    for (i=0; i<5; i++)
    {
        for (j=0; j<6; j++)
        {
            printf("%5.2f   ", Matrix_z(i,j));
        }
        printf("\n");
    }

    printf("\nData Matrix_v:\n");
    for (i=0; i<5; i++)
    {
        for (j=0; j<3; j++)
        {
            printf("%5.2f   ", Matrix_v(i,j));
        }
        printf("\n");
    }

    printf("\nData Matrix_ga:\n");
    for (i=0; i<3; i++)
    {
        for (j=0; j<3; j++)
        {
            printf("%5.2f   ", Matrix_ga(i,j));
        }
        printf("\n");
    }

    /* [2.2]	Negation of the Matrix	*/
    printf("\n\n------------------------------------------------------");
    printf("\n[2.2]	Negation of the Matrix\n");

    Matrix_temp = - Matrix_z;

    printf("\nData Matrix _z (Negation):\n");
    for (i=0; i<5; i++)
    {
        for (j=0; j<6; j++)
        {
            printf("%5.2f   ", Matrix_temp(i,j));
        }
        printf("\n");
    }

    /* [2.3]	Matrix addition	*/
    printf("\n\n------------------------------------------------------");
    printf("\n[2.3]	Matrix addition\n");

    Matrix_temp = Matrix_x + Matrix_y;

    printf("\nData Matrix (_x + _y):\n");
    for (i=0; i<3; i++)
    {
        for (j=0; j<5; j++)
        {
            printf("%5.2f   ", Matrix_temp(i,j));
        }
        printf("\n");
    }

    /* [2.4]	Matrix subtraction	*/
    printf("\n\n------------------------------------------------------");
    printf("\n[2.4]	Matrix subtraction\n");

    Matrix_temp = Matrix_x - Matrix_y;

    printf("\nData Matrix (_x - _y):\n");
    for (i=0; i<3; i++)
    {
        for (j=0; j<5; j++)
        {
            printf("%5.2f   ", Matrix_temp(i,j));
        }
        printf("\n");
    }

    /* [2.5]	Matrix multiplication by a matrix	*/
    printf("\n\n------------------------------------------------------");
    printf("\n[2.5]	Matrix multiplication by a matrix\n");

    Matrix_temp = Matrix_x * Matrix_z;

    printf("\nData Matrix (_x * _z):\n");
    for (i=0; i<3; i++)
    {
        for (j=0; j<6; j++)
        {
            printf("%5.2f   ", Matrix_temp(i,j));
        }
        printf("\n");
    }

    /* [2.6]	Matrix multiplication by a vektor	*/
    printf("\n\n------------------------------------------------------");
    printf("\n[2.6]	Matrix multiplication by a vektor\n");

    MyLinearAlgebra::TVector Vektor_v(5);
    Vektor_v = Matrix_v * Vektor_z;

    printf("\nData Vektor (Matrix_v * Vektor_z):\n");
    for (i=0; i<5; i++)
    {
        printf("%5.2f   ", Vektor_v[i]);
    }

    /* [2.7]	Matrix multiplication by a constant	*/
    printf("\n\n------------------------------------------------------");
    printf("\n[2.7]	Matrix multiplication by a constant\n");

    temp = 7.0;
    Matrix_temp = Matrix_z * temp;

    printf("\nData Matrix (_z * 7.0):\n");
    for (i=0; i<5; i++)
    {
        for (j=0; j<6; j++)
        {
            printf("%5.2f   ", Matrix_temp(i,j));
        }
        printf("\n");
    }

    /* [2.8]	Matrix transposition	*/
    printf("\n\n------------------------------------------------------");
    printf("\n[2.8]	Matrix transposition\n");

    Matrix_temp = Matrix_x.t();

    printf("\nData Matrix _x (Transposition):\n");
    for (i=0; i<5; i++)
    {
        for (j=0; j<3; j++)
        {
            printf("%5.2f   ", Matrix_temp(i,j));
        }
        printf("\n");
    }

    /* [2.9]	Matrix single	*/
    printf("\n\n------------------------------------------------------");
    printf("\n[2.9]	Matrix single\n");

    Matrix_edin = Matrix_edin.E(5);

    printf("\nData Matrix _edin (Single):\n");
    for (i=0; i<5; i++)
    {
        for (j=0; j<5; j++)
        {
            printf("%5.2f   ", Matrix_edin(i,j));
        }
        printf("\n");
    }

    /* [2.10]	Matrix swap	*/
    printf("\n\n------------------------------------------------------");
    printf("\n[2.10]	Matrix swap\n");

    printf("\nData Matrix _x init:\n");
    for (i=0; i<3; i++)
    {
        for (j=0; j<5; j++)
        {
            printf("%5.2f   ", Matrix_x(i,j));
        }
        printf("\n");
    }

    Matrix_x.swapRows(0,2);

    printf("\nData Matrix _x result (Swap_rows(1,3)):\n");
    for (i=0; i<3; i++)
    {
        for (j=0; j<5; j++)
        {
            printf("%5.2f   ", Matrix_x(i,j));
        }
        printf("\n");
    }

    /* [2.11]	Matrix handling (Gauss)	*/
    printf("\n\n------------------------------------------------------");
    printf("\n[2.11]	Matrix handling (Gauss)\n");

    Matrix_temp = ! Matrix_ga;

    printf("\nData Matrix _ga handling (Gauss):\n");
    for (i=0; i<3; i++)
    {
        for (j=0; j<3; j++)
        {
            printf("%5.2f   ", Matrix_temp(i,j));
        }
        printf("\n");
    }

    /* Working with quaternions	*/




    printf("\n\n------------------------------------------------------");
    printf("\n[3]	\n");


    return 0;
}
