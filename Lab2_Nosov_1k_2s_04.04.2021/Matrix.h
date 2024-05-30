#pragma once
#include "Vector.h"
#include <assert.h>

template <typename T>
class Matrix
{
private:
	Vector<Vector<T>>* matrix_items;
public:
	int GetShape(size_t axis = 0) {
		assert(axis == 0 || axis == 1);
		if (axis == 0) { return this->matrix_items->GetLength(); }
		else { return (*this)[0].GetLength(); }
	}

	Matrix(const Vector<Vector<T>>* vector) : matrix_items(vector->clone()) {}

	Matrix(const Matrix<T>& m) : Matrix<T>(m.matrix_items) {}

	Matrix<T> operator+(Matrix<T>& m2) {
		int l1 = this->GetShape();
		int l2 = m2.GetShape();

		assert(l1 == l2);
		Matrix<T>* v = new Matrix<T>(m2);
		for (int i = 0; i < GetShape(); ++i) {
				(*v)[i] = (*v)[i] + (*this)[i];
		}
		return *v;
	}

	Matrix<T> operator*(const T& a) {
		Matrix<T>* scaled = new Matrix<T>(*this);
		for (int i = 0; i < GetShape(); ++i) {
			Vector<T> buf = (*this)[i];
			(*scaled)[i] = buf * a;
		}
		return *scaled;
	}

	T operator*(const Matrix<T>& v2) {
		T* t = new T();
		complex var;
		if (typeid(*t).name() == typeid(var).name()) {
			for (int i = 0; i != GetShape(); ++i) {
				complex buf = (*this)[i];
				complex c2 = v2[i];

				complex c3 = c2.conjugate();
				complex c4 = *t;
				*t = c4 + buf * c3;
			}
		}
		else {
			for (int i = 0; i != GetShape(); ++i) {
				T buf = (*this)[i];
				T c2 = v2[i];

				T c3 = c2;
				*t = *t + buf * c3;
			}
		}
		return *t;
	}

	Vector<T>& operator[](int i) const {
		// assert(i < items->GetLength()); TODO
 		return (*matrix_items)[i];
	}

	double Norm() const {
		double norm = 0.0;
		double max = -1.7976931348623157E+308;
		for (int j = 0; j != (*this)[0].GetLength(); ++j) {
			double sum = 0;
			for (int i = 0; i != this->matrix_items->GetLength(); ++i) {
				complex c = complex((*this)[i][j]);
				sum += c.Norm();
			}
				
			
				if (sum > max) max = sum;
		}

		return max;
	}

};

