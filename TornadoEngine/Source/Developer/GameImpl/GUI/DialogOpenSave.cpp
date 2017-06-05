/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "DialogOpenSave.h"
#include "Settings.h"
#include <boost/foreach.hpp>

TDialogOpenSave::TDialogOpenSave()
{
	mResultExec = eUndef;

	GetCB_Show()->Register( &TDialogOpenSave::ShowEvent,this);
}
//---------------------------------------------------------------------------------------------
TDialogOpenSave::~TDialogOpenSave()
{

}
//---------------------------------------------------------------------------------------------
void TDialogOpenSave::Init(TInitStruct& initStruct)
{
	mInitStruct = initStruct;

	MyGUI::Window* window = mMainWidget->castType<MyGUI::Window>(false);
	if( window!=nullptr )
		window->setCaption(mInitStruct.caption.data());

	bAction->setCaption(mInitStruct.nameButton.data());

	lbItems->removeAllItems();
	BOOST_FOREACH( std::string& item, mInitStruct.vecItems )
		lbItems->addItem(item);
	
	if( mInitStruct.currentItem==-1 )
		ebName->setCaption(mInitStruct.nameCurrentItem);
	else
		if( mInitStruct.readOnly_ebName && mInitStruct.vecItems.size() )
			ebName->setCaption(mInitStruct.vecItems[mInitStruct.currentItem]);
	
	ebName->setEditReadOnly(mInitStruct.readOnly_ebName);
}
//---------------------------------------------------------------------------------------------
void TDialogOpenSave::Activate()
{
	assignWidget(bAction, "bAction");
	assignWidget(ebName,  "ebName");
	assignWidget(lbItems, "lbItems");

	bAction->eventMouseButtonClick += MyGUI::newDelegate(this, &TDialogOpenSave::sl_Action);

	lbItems->eventListChangePosition += MyGUI::newDelegate(this, &TDialogOpenSave::sl_SelectItem);
	lbItems->eventListSelectAccept   += MyGUI::newDelegate(this, &TDialogOpenSave::sl_DoubleSelectItem);

	MyGUI::Window* window = mMainWidget->castType<MyGUI::Window>(false);
	if( window!=nullptr )
		window->eventWindowButtonPressed += MyGUI::newDelegate(this, &TDialogOpenSave::sl_Close);
}
//---------------------------------------------------------------------------------------------
void* TDialogOpenSave::GetParent()
{
	return nullptr;
}
//---------------------------------------------------------------------------------------------
const char* TDialogOpenSave::GetNameLayout()
{
	return "DialogOpenSave.layout";
}
//---------------------------------------------------------------------------------------------
void TDialogOpenSave::SetupTabChild()
{
	mVectorChild_Tab.push_back(lbItems);
	mVectorChild_Tab.push_back(ebName);
	mVectorChild_Tab.push_back(bAction);
}
//---------------------------------------------------------------------------------------------
void TDialogOpenSave::KeyEvent(MyGUI::Widget* _sender, MyGUI::KeyCode _key, MyGUI::Char _char)
{
	switch(_key.getValue())
	{
		case MyGUI::KeyCode::Return:
			//sl_Enter(_sender);
			break;
		default:;
	}
}
//---------------------------------------------------------------------------------------------
void TDialogOpenSave::sl_Action(MyGUI::Widget* _sender)
{
	Accept();
}
//---------------------------------------------------------------------------------------------
TDialogOpenSave::Result TDialogOpenSave::GetResult()
{
	return mResultExec;
}
//---------------------------------------------------------------------------------------------
void TDialogOpenSave::ShowEvent()
{
	mResultExec = eUndef;
}
//---------------------------------------------------------------------------------------------
void TDialogOpenSave::sl_Close(MyGUI::Window* _sender, const std::string& _name)
{
	Reject();
}
//---------------------------------------------------------------------------------------------
std::string TDialogOpenSave::GetResultName()
{
	std::string name = "";
	name = GetValueFromEditBox<std::string>(ebName);
	return name;
}
//---------------------------------------------------------------------------------------------
void TDialogOpenSave::sl_DoubleSelectItem(MyGUI::ListBox* _sender, size_t _index)
{
	SelectItem(_index);
	Accept();
}
//---------------------------------------------------------------------------------------------
void TDialogOpenSave::sl_SelectItem(MyGUI::ListBox* _sender, size_t _index)
{
	SelectItem(_index);
}
//---------------------------------------------------------------------------------------------
void TDialogOpenSave::SelectItem(int index)
{
	size_t len = ebName->getTextLength();
	ebName->eraseText(0, len);
	ebName->addText(mInitStruct.vecItems[index].data());
}
//---------------------------------------------------------------------------------------------
void TDialogOpenSave::Accept()
{
	mResultExec = eAccept;
	Hide();
}
//---------------------------------------------------------------------------------------------
void TDialogOpenSave::Reject()
{
	mResultExec = eReject;
	Hide();
}
//---------------------------------------------------------------------------------------------