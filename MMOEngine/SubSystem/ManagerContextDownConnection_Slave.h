/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef MANAGER_CONTEXT_DOWN_CONNECTION_SLAVE_H
#define MANAGER_CONTEXT_DOWN_CONNECTION_SLAVE_H

#include "ManagerContextDownConnection.h"
#include <vector>

namespace nsMMOEngine
{
	class TManagerContextDownConnection_Slave : public TManagerContextDownConnection
  {
    typedef std::map<unsigned int,unsigned char> TMapUintUchar;
    typedef TMapUintUchar::iterator TMapUintUcharIt;
    
    TMapUintUchar mMapSessionLoadProcent;

		struct TDesc
		{
			unsigned char load_procent;
			unsigned int id_session;

			TDesc(unsigned char lp,unsigned int is)
			{
				load_procent = lp;
				id_session   = is;
			}
			bool operator <(TDesc& right)
			{
				if(load_procent < right.load_procent)
					return true;
				return false;
			}
		};

		typedef std::vector<TDesc> TVectorDesc;
		typedef TVectorDesc::iterator TVectorDescIt;

		TVectorDesc mVecDesc;
  public:
    TManagerContextDownConnection_Slave();
    virtual ~TManagerContextDownConnection_Slave();
    
		bool FindMinimumLoad(unsigned int& id_session, unsigned char& load_procent);
 		bool FindLoadBySession(unsigned int id_session, unsigned char& load_procent);

		void SetLoadBySession(unsigned int id_Session,unsigned char load_procent);

	protected:
		virtual void AddSessionEvent(unsigned int id_session);
		virtual void DeleteSessionEvent(unsigned int id_session);
	private:
  };
}

#endif

