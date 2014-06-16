/**
 * Proiectarea Algoritmilor, 2014
 * Lab 8: Drumuri minime
 *
 * @author 	Radu Iacob
 * @email	radu.iacob23@gmail.com
 */

#ifndef MATRIX_HPP_
#define MATRIX_HPP_

#include "Utils.h"

template< class T >
class Matrix
{
public:

	Matrix( int nrows, int ncols )
		: nrows(nrows), ncols(ncols)
	{
		_content = new T*[nrows];

		for( int i = 0; i < nrows; ++i ){
			_content[i] = new T[ncols];
			memset( _content[i], 0, ncols * sizeof(T) );
		}
	}

	void set_all( T value )
	{
		for( int i = 0; i < nrows; ++i ){
			for( int j = 0; j < ncols; ++j ){
				_content[i][j] = value;
			}
		}
	}

	inline T get_elem( int row, int col ) const
	{
		check_in_range<int>(row,0,nrows);
		check_in_range<int>(col,0,ncols);

		return _content[row][col];
	}

	inline void set_elem( int row, int col, T value )
	{
		check_in_range<int>(row,0,nrows);
		check_in_range<int>(col,0,ncols);

		_content[row][col] = value;
	}

	friend std::ostream& operator<<(std::ostream& out, Matrix& self )
	{
		out << "\n";
		for( int i = 0; i < self.nrows; ++i ){
			for( int j = 0; j < self.ncols; ++j ){
				out << self._content[i][j] << " ";
			}
			out << "\n";
		}
		out << "\n";

		return out;
	}

private:

	int nrows, ncols;
	T** _content;

};



#endif /* MATRIX_HPP_ */
