/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ManagerNodeLocation_Model.h"

TManagerNodeLocation_Model::TManagerNodeLocation_Model()
{

}
//------------------------------------------------------------------------------
TManagerNodeLocation_Model::~TManagerNodeLocation_Model()
{

}
//------------------------------------------------------------------------------
void TManagerNodeLocation_Model::Add(std::string namePart)
{
	TNodeLocation_Model nodeLocation;
	nodeLocation.name = namePart;
	mMapNamePart_NodeLocation.insert(TMapStrNodeLocationVT(namePart,nodeLocation));
}
//------------------------------------------------------------------------------
void TManagerNodeLocation_Model::Remove(std::string namePart)
{
	mMapNamePart_NodeLocation.erase(namePart);
}
//------------------------------------------------------------------------------
void TManagerNodeLocation_Model::Clear()
{
	mMapNamePart_NodeLocation.clear();
}
//------------------------------------------------------------------------------
int TManagerNodeLocation_Model::GetCount()
{
	return mMapNamePart_NodeLocation.size();
}
//------------------------------------------------------------------------------
TNodeLocation_Model* TManagerNodeLocation_Model::Get(int index)
{
	if( index < 0 ||
		  index >= GetCount())
		return NULL;
	TMapStrNodeLocationIt bit = mMapNamePart_NodeLocation.begin();
	for( int i = 0 ; i < index ; i++ )
		bit++;
	return &(bit->second);
}
//------------------------------------------------------------------------------
TNodeLocation_Model* TManagerNodeLocation_Model::Get(std::string namePart)
{
	TMapStrNodeLocationIt fit = mMapNamePart_NodeLocation.find(namePart);
	if( fit==mMapNamePart_NodeLocation.end() )
		return NULL;
	return &(fit->second);
}
//------------------------------------------------------------------------------
