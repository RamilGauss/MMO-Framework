/*
	Эксперименты по замене DirectX математических функций в 
	Struct3D на boost-вские.
*/

#include "Struct3D.h"

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/operation.hpp> 
#include <boost/numeric/ublas/io.hpp>
#include <iostream>
#include <queue>
#include "SetOrderElement.h"
#include "MapCallBack.h"
#include "ManagerRecommutation.h"
#include "WrapperECDSA.h"

using namespace nsStruct3D;

using namespace boost::numeric::ublas;

int main(int argc, char** argv)
{
	//identity_matrix<float> ident_m(4,4);
	//matrix<float> m(4,4);
	//m = ident_m;
	//float* pM = (float*)&m(0,0);
	//int size1 = m.size1();
	//int size2 = m.size2();
	//std::cout << m << std::endl;

	//TMatrix16 matrix;
	//TMatrix16* pResMatrix = SetMatrixIdentity(&matrix);
  return 0;
}
//--------------------------------------------------------------------------------
