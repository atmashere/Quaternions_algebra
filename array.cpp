/* Standard library	*/
#include "array.h"
#include <cstring>
#include <math.h>



/* Model Linear	*/
namespace MyLinearAlgebra
{
	/* Constructor standart	*/
	TVector::TVector() : n(0), data(NULL) {}


	/* Constructor of set	*/
	TVector::TVector(int n) : n(0), data(NULL)
	{

	}


	/* Constructor copy	*/
	TVector::TVector(const TVector& rvalue) : n(0), data(NULL)
	{

	}


	/* Assignment operator	*/
	TVector& TVector::operator = (const TVector& rvalue)
	{

	}


	/* Destructor	*/
	TVector::~TVector()
	{

	}


	/* Method used to set the number of elements	*/
	inline void TVector::resize(int n)
	{

	}


	/* Operator - unary minus	*/
	TVector TVector::operator - () const
	{

	}


	/* Subtraction operator vectors	*/
	TVector TVector::operator - (const TVector& arg) const
	{

	}


	/* Addition operator vectors	*/
	TVector TVector::operator + (const TVector& arg) const
	{

	}


	/* Operator of multiplication of a vector by a number	*/
	TVector TVector::operator * (double arg) const
	{

	}


	/* Operator for scalar multiplication of vectors	*/
	double TVector::operator * (const TVector& arg) const
	{

	}


	/* Operator of multiplication of a vector by a matrix	*/
	TVector TVector::operator * (const TMatrix& arg) const
	{

	}


	/* Operator of vector multiplication of vectors	*/
	TVector TVector::operator ^ (const TVector& arg) const
	{

	}


	/* Friendly function - the operator multiplying the number of vector	*/
	TVector operator * (double lvalue, const TVector& rvalue)
	{

	}


	/* The module (length) vector	*/
	double TVector::length() const
	{

	}


	/* Normalization of the vector	*/
	TVector& TVector::norm()
	{

	}



	/* Constructor standart	*/
	TMatrix::TMatrix() : n(0), m(0), data(NULL) {}


	/* Constructor of set	*/
	TMatrix::TMatrix(int n, int m) : n(0), m(0), data(NULL)
	{

	}


	/* Constructor copy	*/
	TMatrix::TMatrix(const TMatrix& rvalue) : n(0), m(0), data(NULL)
	{

	}


	/* Assignment operator	*/
	TMatrix& TMatrix::operator = (const TMatrix& rvalue)
	{

	}


	/* Destructor	*/
	TMatrix::~TMatrix()
	{

	}


	/* Method used to set the number of elements	*/
	void TMatrix::resize(int n, int m)
	{

	}


	/* Operator - unary minus	*/
	TMatrix TMatrix::operator - () const
	{

	}


	/* Subtraction operator matrix	*/
	TMatrix TMatrix::operator - (const TMatrix& arg) const
	{

	}


	/* Addition operator matrix	*/
	TMatrix TMatrix::operator + (const TMatrix& arg) const
	{

	}


	/* Operator to multiply a matrix by a number	*/
	TMatrix TMatrix::operator * (double arg) const
	{

	}


	/* Matrix multiplication operator	*/
	TMatrix TMatrix::operator * (const TMatrix& arg) const
	{

	}


	/* Multiplication operator for the matrix-vector	*/
	TVector TMatrix::operator * (const TVector& arg) const
	{

	}


	/* Transpose of the matrix	*/
	TMatrix TMatrix::t() const
	{

	}


	/* Friendly feature - the operator multiplying the number of the matrix	*/
	TMatrix operator * (double lvalue, const TMatrix& rvalue)
	{

	}


	/* Function of the formation of the identity matrix	*/
	TMatrix TMatrix::E(int n)
	{

	}


	/* Inversion operator matrix (Gauss method)	*/
	TMatrix TMatrix::operator ! () const throw(int)
	{

	}


	/* Function swap rows	*/
	TMatrix& TMatrix::swapRows(int i, int j)
	{

	}
};