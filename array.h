#pragma once

    /* Anticipating declaration class Matrix	*/
	class TMatrix;

    /* Anticipating declaration	class Quaternion  */
    class TQuaternion;

	/* Declaration of the class vectors	*/
	class TVector
	{
		/* Access modifier	*/
		protected:
			/* Dimension of the vector	*/
			int n;

			/* Data of the vector	*/
			double *data;

		/* Access modifier	*/
		public:
			/* Constructor standart	*/
			TVector();

			/* Constructor of set	*/
			TVector(int n);

			/* Constructor copy	*/
			TVector(const TVector& rvalue);

			/* Assignment operator	*/
			TVector& operator = (const TVector& rvalue);

			/* Destructor	*/
			virtual ~TVector();

			/* A method of obtaining the number of elements	*/
			inline int size() const { return n; }

			/* A method of obtaining the last item	*/
			inline int high() const { return n - 1; }

			/* Method used to set the number of elements	*/
			void resize(int n);

			/* Access operator elements of vector	*/
			inline double& operator[](int i) { return data[i]; }

			/* Operator const access elements of a vector	*/
			inline const double& operator[](int i) const { return data[i]; }

			/* Operator - unary minus	*/
			TVector operator - () const;

			/* Subtraction operator vectors	*/
			TVector operator - (const TVector& arg) const;

			/* Addition operator vectors	*/
			TVector operator + (const TVector& arg) const;

			/* The module (length) vector	*/
			double length() const;

			/* Operator of vector multiplication of vectors	*/
			TVector operator ^ (const TVector& arg) const;

			/* Operator of multiplication of a vector by a number	*/
			TVector operator * (double arg) const;

			/* Normalization of the vector	*/
			TVector& norm();

			/* Operator for scalar multiplication of vectors	*/
			double operator * (const TVector& arg) const;

			/* Operator of multiplication of a vector by a matrix	*/
			TVector operator * (const TMatrix& arg) const;

			/* Friendly function - the operator multiplying the number of vector	*/
			friend TVector operator * (double lvalue, const TVector& rvalue);

            /* Operator of multiplication of a vector by a quaternion	*/
            TQuaternion operator * (const TQuaternion& arg) const;

            /* Rotation of the vector around axis on phi by Ridrig`s formula	*/
            TVector rotateByRodrigFormula(double phi, const TVector& axis) const;

            /* Rotation of the vector around axis on phi	*/
            TVector rotate(double phi, const TVector& axis) const;

           /* Rotation of the vector by quaternion   */
            TVector rotateByQuaternion(const TQuaternion& L) const;
	};



	/* Declaration of the class matrix	*/
	class TMatrix
	{
		/* Access modifier	*/
		protected:
			/* Dimension of the matrix	*/
			int n, m;

			/* Data of the matrix	*/
			double **data;

		/* Access modifier	*/
		public:
			/* Constructor standart	*/
			TMatrix();

			/* Constructor of set	*/
			TMatrix(int n, int m);

			/* Constructor copy	*/
			TMatrix(const TMatrix& rvalue);

			/* Assignment operator	*/
			TMatrix& operator = (const TMatrix& rvalue);

			/* Destructor	*/
			virtual ~TMatrix();

			/* A method of obtaining the number row of the vector	*/
			inline int rowCount() const { return n; }

			/* A method of obtaining the number column of the vector	*/
			inline int colCount() const { return m; }

			/* Function to obtain the index of the last row	*/
			inline int rowHigh() const { return n-1; }

			/* Function to obtain the index of the last column	*/
			inline int colHigh() const { return m-1; }

			/* Method used to set the number of elements	*/
			void resize(int n, int m);

			/* Access operator elements of matrix	*/
			inline double& operator()(int i, int j) { return data[i][j]; }

			/* Operator const access elements of a matrix	*/
			inline const double& operator()(int i, int j) const { return data[i][j]; }

			/* Operator - unary minus	*/
			TMatrix operator - () const;

			/* Subtraction operator matrix	*/
			TMatrix operator - (const TMatrix& arg) const;

			/* Addition operator matrix	*/
			TMatrix operator + (const TMatrix& arg) const;

			/* Operator to multiply a matrix by a number	*/
			TMatrix operator * (double arg) const;

			/* Matrix multiplication operator	*/
			TMatrix operator * (const TMatrix& arg) const;

			/* Multiplication operator for the matrix-vector	*/
			TVector operator * (const TVector& arg) const;

			/* Transpose of the matrix	*/
			TMatrix t() const;

			/* Friendly feature - the operator multiplying the number of the matrix	*/
			friend TMatrix operator * (double lvalue, const TMatrix& rvalue);

			/* Function of the formation of the identity matrix	*/
			static TMatrix E(int n);

			/* Inversion operator matrix (Gauss method)	*/
			TMatrix operator ! () const throw(int);

			/* Function swap rows	*/
			TMatrix& swapRows(int i, int j);
	};

    class TQuaternion {

        /* Access modifier	*/
        protected:
            /*Scalar part */
            double q0;

            /*Vector part */
            TVector Q;

        /* Access modifier	*/
        public:
            /*Constructor standart  */
            TQuaternion();

            /*Constructor  set parameters  */
            TQuaternion(double l0, double l1, double l2, double l3);

            /*Constructor with phi and axis  */
            TQuaternion(double phi, const TVector& e);

            /*Copy constructor  */
            TQuaternion(const TQuaternion& rvalue);

            /* Get scalar part	*/
            inline double scal() const { return q0; }

            /* Get vector part	*/
            inline TVector vect() const { return Q; }

            /* Assignment operator	*/
            TQuaternion& operator = (const TQuaternion& rvalue);

            /* Subtraction operator quaternions	*/
            TQuaternion operator - (const TQuaternion& arg) const;

            /* Addition operator quaternions	*/
            TQuaternion operator + (const TQuaternion& arg) const;

            /* Quaternions multiplication operator	*/
            TQuaternion operator * (const TQuaternion& arg) const;

            /* Operator to multiply a quaternion by a vector	*/
            TQuaternion operator * (const TVector& arg) const;

            /* Operator to turn quaternion	*/
            TQuaternion operator ! () const;

            /* Normalized quaternion	*/
            TQuaternion& norm();

            /* Conjugate quaternion	*/
            TQuaternion conj() const;

            /* Get roatate matrix from quaternion	*/
            TMatrix toRotateMatrix() const;

            /* Function of creation quaternion by Krylov angles	*/
            static TQuaternion fromKrylovAngles(double yaw, double pitch, double roll);
    };

