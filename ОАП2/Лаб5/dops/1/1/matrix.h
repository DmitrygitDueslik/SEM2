#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <iomanip>

namespace MatrixLib
{
	template <typename T>
	class Matrix
	{
	private:
		int rows;
		int cols;
		T** data;

	public:
		Matrix ( int r, int c ) : rows ( r ), cols ( c )
		{
			data = new T * [rows];
			for ( int i = 0; i < rows; i++ ) {
				data[i] = new T[cols] ( );
			}
		}

		~Matrix ( )
		{
			for ( int i = 0; i < rows; i++ ) {
				delete[] data[i];
			}
			delete[] data;
		}

		Matrix ( const Matrix& other ) : rows ( other.rows ), cols ( other.cols )
		{
			data = new T * [rows];
			for ( int i = 0; i < rows; i++ ) {
				data[i] = new T[cols];
				for ( int j = 0; j < cols; j++ ) {
					data[i][j] = other.data[i][j];
				}
			}
		}

		Matrix& operator=( const Matrix& other )
		{
			if ( this != &other ) {
				for ( int i = 0; i < rows; i++ ) delete[] data[i];
				delete[] data;

				rows = other.rows;
				cols = other.cols;
				data = new T * [rows];
				for ( int i = 0; i < rows; i++ ) {
					data[i] = new T[cols];
					for ( int j = 0; j < cols; j++ ) {
						data[i][j] = other.data[i][j];
					}
				}
			}
			return *this;
		}

		void fill ( T value )
		{
			for ( int i = 0; i < rows; i++ ) {
				for ( int j = 0; j < cols; j++ ) {
					data[i][j] = value;
				}
			}
		}

		void set ( int r, int c, T value )
		{
			if ( r >= 0 && r < rows && c >= 0 && c < cols ) {
				data[r][c] = value;
			}
		}

		T get ( int r, int c ) const
		{
			if ( r >= 0 && r < rows && c >= 0 && c < cols ) {
				return data[r][c];
			}
			return T ( );
		}

		int getRows ( ) const { return rows; }
		int getCols ( ) const { return cols; }

		void print ( ) const
		{
			for ( int i = 0; i < rows; i++ ) {
				std::cout << "    ";
				for ( int j = 0; j < cols; j++ ) {
					std::cout << std::setw ( 8 ) << data[i][j] << " ";
				}
				std::cout << std::endl;
			}
		}

		Matrix operator+( const Matrix& other ) const
		{
			Matrix<T> result ( rows, cols );
			for ( int i = 0; i < rows; i++ ) {
				for ( int j = 0; j < cols; j++ ) {
					result.data[i][j] = data[i][j] + other.data[i][j];
				}
			}
			return result;
		}

		Matrix operator*( const Matrix& other ) const
		{
			Matrix<T> result ( rows, other.cols );
			for ( int i = 0; i < rows; i++ ) {
				for ( int j = 0; j < other.cols; j++ ) {
					T sum = T ( );
					for ( int k = 0; k < cols; k++ ) {
						sum += data[i][k] * other.data[k][j];
					}
					result.data[i][j] = sum;
				}
			}
			return result;
		}

		Matrix operator*( T scalar ) const
		{
			Matrix<T> result ( rows, cols );
			for ( int i = 0; i < rows; i++ ) {
				for ( int j = 0; j < cols; j++ ) {
					result.data[i][j] = data[i][j] * scalar;
				}
			}
			return result;
		}
	};
}

#endif