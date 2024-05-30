#include <iostream>
#include "Vector.h" 
#include "Matrix.h"
#include "ArraySequence.h"
#include "MyComplex.h"
using namespace std;

double sqrt(complex c)
{
	return c.Norm();
}



template<class T>
void printMatrix(Matrix<T>& m)
{
	cout << "Matrix!!!\n";
	for (int i = 0; i < m.GetShape(); i++)
	{
		auto h = m[i];
		auto j = Vector<T>(h);
		printVector(j);
	}
		
}

int main() {
	auto arr = new ArraySequence<int>();
	arr->Append(1);
	arr->Append(1);
	arr->Append(2);
	arr->Append(3);
	arr->Append(4);


	for (int i = 0; i < arr->GetLength(); i++)
		cout << arr->Get(i) << '\n';
	// auto ptr = (Sequence*)arr;
	cout << '\n';
	auto vector = Vector<int>(arr);


	
	
	printVector(vector);
	auto c = (vector) + (vector);
	printVector(c);
	//auto vectorMult = vector * vector;
	//cout << vectorMult << '\n';
	//int t = (int)vectorMult;
	//auto vectorScalat = vector * t;
	//printVector(vectorScalat);
	cout << "Norm: " << (vector).Norm() << '\n';

	cout << "Compleh!!!\n";

	auto arrComplex = new ArraySequence<complex>();
	arrComplex->Append(complex(0.0, 0.0));
	arrComplex->Append(complex(1.0, 1.0));
	arrComplex->Append(complex(2.0, 2.0));
	arrComplex->Append(complex(3.0, 3.0));
	arrComplex->Append(complex(4.0, 4.0));
	for (int i = 0; i < arrComplex->GetLength(); i++)
		cout << arrComplex->Get(i) << '\n';
	// auto ptr = (Sequence*)arr;
	auto vectorComplex = Vector<complex>(arrComplex);

	printVector(vectorComplex);
	auto cComplex = vectorComplex + vectorComplex;
	printVector(cComplex);
	//auto vectorMultComplex = vectorComplex * vectorComplex;
	//cout << vectorMultComplex << '\n';
	//complex tComplex = (complex)vectorMultComplex;
	//auto vectorScalatComplex = vectorComplex * tComplex;
	//printVector(vectorScalatComplex);
	cout << "Norm: " << vectorComplex.Norm() << '\n';



	auto arrarr = new Vector<Vector<int>>(5);
	for (size_t i = 0; i < 5; i++)
	{
		(*arrarr)[i] = vector;
	}
	auto matrix = Matrix<int>(arrarr);

	printMatrix(matrix);

	auto matr1 = matrix + matrix;
	printMatrix(matr1);

	auto matr2 = matrix * 5;
	printMatrix(matr2);

	cout << matrix.Norm() << '\n';


	auto arrarrComplex = new Vector<Vector<complex>>(5);
	for (size_t i = 0; i < 5; i++)
	{
		(*arrarrComplex)[i] = vectorComplex;
	}
	auto matrixComplex = Matrix<complex>(arrarrComplex);

	printMatrix(matrixComplex);

	auto matr1Complex = matrixComplex + matrixComplex;
	printMatrix(matr1Complex);

	auto matr2Complex = matrixComplex * complex(1, 2);
	printMatrix(matr2Complex);

	cout << matrixComplex.Norm();

	return 0;
}