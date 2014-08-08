/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "CryptMITM.h"
#include "MD5.h"
#include "SHA256.h"
#include "CryptoAES_Impl.h"

bool TCryptMITM::Calc(void* rsa, int size_rsa, 
											void* login_password, int size_login_password, 
											TContainer& c_result)
{
	// рассчитать MD5(LoginPassword)
	TContainer cMD5LP;
	TMD5 md5LP;
	md5LP.FastCalc(login_password, size_login_password, cMD5LP);
	// рассчитать SHA256(LoginPassword)
	TContainer cSHA256LP;
	TSHA256 sha256LP;
	sha256LP.FastCalc(login_password, size_login_password, cSHA256LP);
	// зашифровать RSA с помощью AES, используя в качестве ключа SHA256(LP)
	TCryptoAES_Impl crypt_aes;
	crypt_aes.SetPublicKey(cSHA256LP.GetPtr(), cSHA256LP.GetSize());

	if(crypt_aes.Encrypt(rsa, size_rsa, c_result)==false)
		return false;
	
	return true;
}
//-------------------------------------------------------------------------------------------------------