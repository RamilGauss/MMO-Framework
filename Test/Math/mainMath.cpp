/*
	Эксперименты по замене DirectX математических функций в 
	Struct3D на boost-вские.
*/

#include "Struct3D.h"
//
//#include <boost/numeric/ublas/matrix.hpp>
//#include <boost/numeric/ublas/operation.hpp> 
//#include <boost/numeric/ublas/io.hpp>
//#include <iostream>
//#include <queue>
//#include "SetOrderElement.h"
//#include "MapCallBack.h"
#include "DescEvent.h"
#include "SrcEvent.h"
#include "Events.h"
#include "SrcEvent_ex.h"
#include "DstEvent.h"

using namespace nsStruct3D;
using namespace nsMMOEngine;

//using namespace boost::numeric::ublas;

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

	{
		char data[100];
		int sizeData = 100;

		TEventTryLogin* pEventTL = new TEventTryLogin;
		pEventTL->id_session = 0;
		pEventTL->c.SetDataByCount(data,sizeData);

		nsEvent::TEvent* pEvent = new nsEvent::TEvent();
		pEvent->Init<TEventTryLogin>(0);

		pEvent->from = 0;
		pEvent->pContainer->EntrustByCount((char*)pEventTL,1);
		delete pEvent;
	}

  return 0;
}
//--------------------------------------------------------------------------------
