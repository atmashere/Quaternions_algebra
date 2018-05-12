/* Standard library	*/
#include "array.h"
#include <cstring>
#include <math.h>



/* Model Linear	*/

    /* Constructor standart	*/
    TVector::TVector() : n(0), data(NULL) {}


    /* Constructor of set	*/
    TVector::TVector(int n) : n(0), data(NULL)
    {
        resize(n);
    }


    /* Constructor copy	*/
    TVector::TVector(const TVector& rvalue) : n(0), data(NULL)
    {
        (*this) = rvalue;
    }


    /* Assignment operator	*/
    TVector& TVector::operator = (const TVector& rvalue)
    {
        if (n != rvalue.n)
        {
            if (data)
            {
                delete[] data;
            }

            data = new double[rvalue.n];
            n = rvalue.n;
        }

        memcpy(data, rvalue.data, sizeof(double) * n);

        return (*this);
    }


    /* Destructor	*/
    TVector::~TVector()
    {
        if (data)
        {
            delete[] data;

            n = 0;
            data = NULL;
        }
    }


    /* Method used to set the number of elements	*/
    inline void TVector::resize(int n)
    {
        if (n == this->n)
            return;

        double *newData = new double[n];

        if (data)
        {
            int min_n = (this->n < n) ? this->n : n;

            memcpy(newData, data, sizeof(double)*min_n);

            delete[] data;
        }

        data = newData;

        this->n = n;
    }


    /* Operator - unary minus	*/
    TVector TVector::operator - () const
    {
        TVector V(n);

        for (int i = 0; i < n; i++)
            V[i] = - data[i];

        return V;
    }


    /* Subtraction operator vectors	*/
    TVector TVector::operator - (const TVector& arg) const
    {
        TVector V( n );

        for (int i = 0; i < n; i++)
            V[i] = data[i] - arg[i];

        return V;
    }


    /* Addition operator vectors	*/
    TVector TVector::operator + (const TVector& arg) const
    {
        TVector V( n );

        for (int i = 0; i < n; i++)
            V[i] = data[i] + arg[i];

        return V;
    }


    /* Operator of multiplication of a vector by a number	*/
    TVector TVector::operator * (double arg) const
    {
        TVector V( n );

        for (int i = 0; i < n; i++)
            V[i] = data[i] * arg;

        return V;
    }


    /* Operator for scalar multiplication of vectors	*/
    double TVector::operator * (const TVector& arg) const
    {
        double r = 0;

        for (int i = 0; i < n; i++)
            r += data[i] * arg[i];

        return r;
    }


    /* Operator of multiplication of a vector by a matrix	*/
    TVector TVector::operator * (const TMatrix& arg) const
    {
        TVector V(arg.colCount());

        for (int j = 0; j < V.n; j++)
        {
            V[j] = 0;

            for (int i = 0; i < n; i++)
                V[j] += data[i] * arg(i,j);
        }

        return V;
    }


    /* Operator of vector multiplication of vectors	*/
    TVector TVector::operator ^ (const TVector& arg) const
    {
        TVector V(3);

        V[0] = data[1]*arg[2] - arg[1]*data[2];
        V[1] = data[2]*arg[0] - arg[2]*data[0];
        V[2] = data[0]*arg[1] - arg[0]*data[1];

        return V;
    }


    /* Friendly function - the operator multiplying the number of vector	*/
    TVector operator * (double lvalue, const TVector& rvalue)
    {
        return rvalue * lvalue;
    }


    /* The module (length) vector	*/
    double TVector::length() const
    {
        return sqrt((*this)*(*this));
    }


    /* Normalization of the vector	*/
    TVector& TVector::norm()
    {
        double r = this->length();

        if (r > 0)
            for (int i = 0; i < n; i++)
            data[i] /= r;

        return *this;
    }



    /* Constructor standart	*/
    TMatrix::TMatrix() : n(0), m(0), data(NULL) {}


    /* Constructor of set	*/
    TMatrix::TMatrix(int n, int m) : n(0), m(0), data(NULL)
    {
        resize(n, m);
    }


    /* Constructor copy	*/
    TMatrix::TMatrix(const TMatrix& rvalue) : n(0), m(0), data(NULL)
    {
        (*this) = rvalue;
    }


    /* Assignment operator	*/
    TMatrix& TMatrix::operator = (const TMatrix& rvalue)
    {
        if (this != &rvalue)
        {
            this->~TMatrix();

            resize(rvalue.n, rvalue.m);

            for (int i = 0; i < n; i++)
                memcpy(data[i], rvalue.data[i], sizeof(double)*m);
        }

        return (*this);
    }


    /* Destructor	*/
    TMatrix::~TMatrix()
    {
        if (data)
        {
            for (int i = 0; i < n; i++)
                delete[] data[i];
                delete[] data;

                data = NULL;
                n = m = 0;
        }
    }


    /* Method used to set the number of elements	*/
    void TMatrix::resize(int n, int m)
    {
        int min_n = this->n < n ? this->n : n;

        if (this->m != m)
        {
            int min_m = this->m < m ? this->m : m;

            for (int i = 0; i < min_n; i++)
            {
                double *newDataRow = new double[ m ];

                memcpy(newDataRow, data[i], sizeof(double)*min_m);

                delete[] data[i];

                data[i] = newDataRow;
            }

            this->m = m;
        }

        if (this->n != n)
        {
            double **newData = new double*[ n ];

            memcpy(newData, data, sizeof(double*)*min_n);

            for (int i = n; i < this->n; i++)
                delete[] data[i];

            if (data)
                delete[] data;

            for (int i = this->n; i < n; i++)
                newData[i] = new double[ m ];
                data = newData;
            this->n = n;
        }
    }


    /* Operator - unary minus	*/
    TMatrix TMatrix::operator - () const
    {
        TMatrix M(n, m);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                M(i,j) = -data[i][j];

        return M;
    }


    /* Subtraction operator matrix	*/
    TMatrix TMatrix::operator - (const TMatrix& arg) const
    {
        TMatrix M(n, m);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                M(i,j) = data[i][j] - arg(i,j);

        return M;
    }


    /* Addition operator matrix	*/
    TMatrix TMatrix::operator + (const TMatrix& arg) const
    {
        TMatrix M(n, m);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                M(i,j) = data[i][j] + arg(i,j);

        return M;
    }


    /* Operator to multiply a matrix by a number	*/
    TMatrix TMatrix::operator * (double arg) const
    {
        TMatrix M(n, m);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                M(i,j) = data[i][j] * arg;

        return M;
    }


    /* Matrix multiplication operator	*/
    TMatrix TMatrix::operator * (const TMatrix& arg) const
    {
        TMatrix M(n, arg.m);

        for (int i = 0; i < M.n; i++)
            for (int j = 0; j < M.m; j++)
            {
                M(i,j) = 0;

                for (int k = 0; k < m; k++)
                    M(i,j) += data[i][k] * arg(k, j);
            }

        return M;
    }


    /* Multiplication operator for the matrix-vector	*/
    TVector TMatrix::operator * (const TVector& arg) const
    {
        TVector V(n);

        for (int i = 0; i < n; i++)
        {
            V[i] = 0;

            for (int j = 0; j < m; j++)
                V[i] += data[i][j] * arg[j];
        }

        return V;
    }


    /* Transpose of the matrix	*/
    TMatrix TMatrix::t() const
    {
        TMatrix M(m, n);

        for (int i = 0; i < M.n; i++)
            for (int j = 0; j < M.m; j++)
                M(i,j) = data[j][i];

        return M;
    }


    /* Friendly feature - the operator multiplying the number of the matrix	*/
    TMatrix operator * (double lvalue, const TMatrix& rvalue)
    {
        return rvalue * lvalue;
    }


    /* Function of the formation of the identity matrix	*/
    TMatrix TMatrix::E(int n)
    {
        TMatrix E(n,n);

        for (int i = 0; i < n; i++)
        {
            E(i,i) = 1;

            for (int j = i+1; j < n; j++)
                E(i,j) = E(j,i) = 0;
        }

        return E;
    }


    /* Inversion operator matrix (Gauss method)	*/
    TMatrix TMatrix::operator ! () const throw(int)
    {
        TMatrix X( E(n) ),
        A(*this);

        double tmp;

        for (int i = 0; i < n; i++)
        {
            if (A(i,i) == 0)
            {
                for (int k = i+1; k < n; k++)
                    if (A(k,i) != 0)
                    {
                        A.swapRows(i, k);
                        X.swapRows(i, k);

                        break;
                    }
            }

            if ( (tmp = A(i, i)) == 0 )
                throw 2;

            for (int j = 0; j < n; j++)
            {
                A(i, j) /= tmp;
                X(i, j) /= tmp;
            }

            for (int k = 0; k < n; k++)
                if (k != i)
                {
                    tmp = A(k, i);

                    for (int j = 0; j < n; j++)
                    {
                        A(k, j) -= A(i, j) * tmp;
                        X(k, j) -= X(i, j) * tmp;
                    }
                }
        }

        return X;
    }


    /* Function swap rows	*/
    TMatrix& TMatrix::swapRows(int i, int j)
    {
        double buf;

        for (int k = 0; k < m; k++)
        {
            buf = data[i][k];
            data[i][k] = data[j][k];
            data[j][k] = buf;
        }

        return *this;
    }

//----------------------------------------------------------------------------------

    TQuaternion::TQuaternion(): q0(0.), Q(3)
    {
        q0   = 0.;
        Q[0] = 0.;
        Q[1] = 0.;
        Q[2] = 0.;
    }

    TQuaternion::TQuaternion(double l0, double l1, double l2, double l3): q0(0.), Q(3)
    {
        q0   = l0;
        Q[0] = l1;
        Q[1] = l2;
        Q[2] = l3;
    }

    TQuaternion::TQuaternion(double phi, const TVector& e): q0(0.), Q(3)
    {
        q0   = double(cos((90*phi)/M_PI));
        Q[0] = double(sin((90*phi)/M_PI))*e[0];
        Q[1] = double(sin((90*phi)/M_PI))*e[1];
        Q[2] = double(sin((90*phi)/M_PI))*e[2];
    }

    TQuaternion::TQuaternion(const TQuaternion& rvalue): q0(0.), Q(3)
    {
        (*this) = rvalue;
    }

    TQuaternion& TQuaternion::operator = (const TQuaternion& rvalue)
    {
        q0   = rvalue.q0;
        Q[0] = rvalue.Q[0];
        Q[1] = rvalue.Q[1];
        Q[2] = rvalue.Q[2];

        return (*this);
    }

    TQuaternion TQuaternion::operator + (const TQuaternion& arg) const
    {
//       TQuaternion Quat(q0, Q[0], Q[1], Q[2]);
//       Quat.q0   = q0   + arg.q0;
//       Quat.Q[0] = Q[0] + arg.Q[0];
//       Quat.Q[1] = Q[1] + arg.Q[1];
//       Quat.Q[2] = Q[2] + arg.Q[2];

       return  TQuaternion(q0 + arg.q0, Q[0] + arg.Q[0], Q[1] + arg.Q[1], Q[2] + arg.Q[2]);
    }

    TQuaternion TQuaternion::operator * (const TQuaternion& arg) const
    {
       TQuaternion Quat(q0, Q[0], Q[1], Q[2]);

       Quat.q0 = q0*arg.q0 - Q*arg.Q;
       Quat.Q = q0*arg.Q + arg.q0*Q + (Q^arg.Q);

       return Quat;
    }

    TQuaternion TQuaternion::operator * (const TVector& arg) const
    {
        TQuaternion Quat(q0, Q[0], Q[1], Q[2]);

        Quat.q0 = -Q*arg;
        Quat.Q = q0*arg + (Q^arg);

        return Quat;
    }

    TQuaternion TQuaternion::operator ! () const
    {
        return conj().norm();
    }

     TQuaternion TQuaternion::conj() const
     {
         return TQuaternion(q0, -Q[0], -Q[1], -Q[2]);
     }

     TQuaternion& TQuaternion::norm()
     {
         double norma = (q0)  *(q0)  +
                        (Q[0])*(Q[0])+
                        (Q[1])*(Q[1])+
                        (Q[2])*(Q[2]);
         q0   = q0/norma;
         Q[0] = Q[0]/norma;
         Q[1] = Q[1]/norma;
         Q[2] = Q[2]/norma;


         return (*this);
     }

     TMatrix TQuaternion::toRotateMatrix() const
     {
        TMatrix M(3, 3);

        M(0,0) = q0*q0 + Q[0]*Q[0] - Q[1]*Q[1] - Q[2]*Q[2];
        M(0,1) = 2*(Q[0]*Q[1] - q0*Q[2]);
        M(0,2) = 2*(Q[0]*Q[2] + q0*Q[1]);

        M(1,0) = 2*(Q[0]*Q[1] + q0*Q[2]);
        M(1,1) = q0*q0 - Q[0]*Q[0] + Q[1]*Q[1] - Q[2]*Q[2];
        M(1,2) = 2*(Q[1]*Q[2] - q0*Q[0]);

        M(2,0) = 2*(Q[0]*Q[2] - q0*Q[1]);
        M(2,1) = 2*(Q[1]*Q[2] + q0*Q[0]);
        M(2,2) = q0*q0 - Q[0]*Q[0] - Q[1]*Q[1] + Q[2]*Q[2];

        return M;
     }

     TQuaternion TQuaternion::fromKrylovAngles(double yaw, double pitch, double roll)
     {
         yaw   = yaw*180/M_PI;
         pitch = pitch*180/M_PI;
         roll  = roll*180/M_PI;

         return TQuaternion(
                     cos(yaw/2.)*cos(pitch/2.)*cos(roll/2.) - sin(yaw/2.)*sin(pitch/2.)*sin(roll/2.),
                     cos(yaw/2.)*cos(pitch/2.)*sin(roll/2.) + sin(yaw/2.)*sin(pitch/2.)*cos(roll/2.),
                     sin(yaw/2.)*cos(pitch/2.)*cos(roll/2.) + cos(yaw/2.)*sin(pitch/2.)*sin(roll/2.),
                     cos(yaw/2.)*sin(pitch/2.)*cos(roll/2.) + sin(yaw/2.)*cos(pitch/2.)*sin(roll/2.)
                 );
     }



