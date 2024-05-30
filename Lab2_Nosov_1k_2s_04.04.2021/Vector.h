#pragma once
#include "Sequence.h"
#include "ArraySequence.h"


template <typename T>
class Vector {
private:
	Sequence<T>* vector_items;
public:
	int GetLength() {
		return this->vector_items->GetLength();
	}

	friend void printVector(Vector<T>& v)
	{
		cout << "Vector!!!\n";
		for (int i = 0; i < v.GetLength(); i++)
			cout << v[i] << ' ';
		cout << "\n\n";
	}

	Vector(int n = 1) : vector_items(new ArraySequence<T>(n)) {}

	Vector(const Sequence<T>* seq) : vector_items(seq->clone()) {}

	Vector(const Vector<T>& v) : Vector<T>(v.vector_items) {}

	Vector<T>* clone () const {
		auto vect = new Vector<T>(*this);
		return vect;
	}

	Vector<T> operator+(Vector<T>& v2) {
		int l1 = this->GetLength();
		int l2 = v2.GetLength();

		assert(l1 == l2);
		Vector<T>* v = new Vector<T>(v2);
		for (int i = 0; i < GetLength(); ++i) {
			T buf = v2[i];
			buf = buf + this->vector_items->Get(i);
			v->vector_items->Set(i, buf);
		}
		return *v;
	}

	Vector<T> operator*(const T& a) {
		Vector<T>* scaled = new Vector<T>(*this);
		for (int i = 0; i < GetLength(); ++i) {
			T buf = (*this)[i];
			buf = buf * a;
			scaled->vector_items->Set(i, buf);
		}
		return *scaled;
		
	}

	//T operator*(const Vector<T>& v2) {
	//	T* t = new T();
	//	complex var;
	//	if (typeid(*t).name() == typeid(var).name()) {
	//		for (int i = 0; i != GetLength(); ++i) {
	//			complex buf = (*this)[i];
	//			complex c2 = v2[i];

	//			complex c3 = c2.conjugate();
	//			complex c4 = *t;
	//			*t = c4 + buf * c3;
	//		}
	//	}
	//	else {
	//		for (int i = 0; i != GetLength(); ++i) {
	//			T buf = (*this)[i];
	//			T c2 = v2[i];

	//			T c3 = c2;
	//			*t = *t + buf * c3;
	//		}
	//	}
	//	return *t;
	//}


	T& operator[](size_t i) const {
		// assert(i < vector_items->GetLength()); TODO
		return vector_items->Get((int)i);
	}

	double Norm() const {
		double norm = 0.0;
		
		for (int i = 0; i != this->vector_items->GetLength(); ++i) {
			complex c = (*this)[i];
			norm += c.Norm()*c.Norm();
		}

		return sqrt(norm);
	}
};
