#pragma once

#include <list>
#include <string>

namespace nsSharedDev
{
    class IJsonSerializer
    {
    public:
        virtual int Foo() = 0;
    };

    enum class ModuleName
    {
        DATA_BASE,
        GRAPHIC,
        MMO,
        NETWORK,
        PHYSIC,
        SOUND,
        TIMER,
    };

    enum class ParentContainerName
    {
        COMPONENT,
        FEATURE,
        COLLISION_HANDLER,
        NETWORK_HANDLER,
        MENU_ITEM,
    };

    class IContainerForInheritance
    {
    public:
        ParentContainerName parentTypeName;
        IJsonSerializer* mJson = nullptr;
    };
}

//--------------------------------------------------------------------
// Generated files
// 
namespace nsProjectA
{
    class TJsonSerializer : public nsSharedDev::IJsonSerializer
    {
    public:
        int Foo() override
        {
            return 42;
        }
    };

    class ComponentContainer : public nsSharedDev::IContainerForInheritance
    {
    public:
        ComponentContainer()
        {
            parentTypeName = nsSharedDev::ParentContainerName::COMPONENT;
            mJson = new nsProjectA::TJsonSerializer();
        }
    };

    static ComponentContainer componentContainer;
}

// Dev.h
std::list<nsSharedDev::ModuleName> GetModuleList()
{
    static std::list<nsSharedDev::ModuleName> moduleList =
    {nsSharedDev::ModuleName::GRAPHIC, nsSharedDev::ModuleName::PHYSIC};

    return moduleList;
}

nsSharedDev::IContainerForInheritance* GetContainer(nsSharedDev::ParentContainerName parentContainerName)
{
    switch (parentContainerName) {
        case nsSharedDev::ParentContainerName::COMPONENT:
            return &nsProjectA::componentContainer;
        default:;
    }
    return nullptr;
}
//--------------------------------------------------------------------
struct IComponent {};
struct A : IComponent { int x; };

class INetworkHandler
{
public:
    virtual void Handle(int header, IComponent* p) {}
    virtual void Handle(IComponent* p) {}
};
struct MouseEvent {};
class IMouseHandler
{
public:
    virtual void Handle(MouseEvent* p) = 0;
};
struct KeyBoardEvent {};
class IKeyBoardHandler
{
public:
    virtual void Handle(KeyBoardEvent* p) = 0;
};

class THandler : public INetworkHandler
{
public:
    void Handle(int header, IComponent* p) override
    {

    }
};

// Handler нужны только когда тип обрабатываемого типа заранее известен. 
// Если это void*, то лучше пробразывать через entity (???). 
// Но тогда нужен eraser для этих сущностей. Creater -> Consumers -> Eraser


class TReflection
{
public:
    void* New(int typeIdentifier);
    void* New(const std::string& typeName);

    void Delete(void* p);
};

//Json, MyGUI, Binary, TypeInformation, EntMngExtension, Reflection

//Json, TypeInformation, EntMngExtension

class Parent {};
class Member {};

namespace Y
{
    class Parent {};
    class Member {};
}

namespace X
{
    class Parent {};
    class Member {};

    class Child : public Parent
    {
        X::Member member;
    };
}