

Root      (Guid = {0000000000-00000000-00000000-000000000000}) NoneGuid
|
|
|---Scene_0
|	|-Entity_0-Entity...
|	|-Entity_1...
|
|---Scene_1
|	|-Entity_0
|...
|...
|---Scene_N
		...


General Components:
1. GuidComponent - std::string or uuid (???)
2. TransformComponent - Matrix16, view as global, safe as local
3. NameComponent - std::string
4. ParentGuidComponent (optional) - std::string or uuid (???)

RootComponent - 

SceneComponent - std::string or uuid (???)

SceneManager->Load() - делает копию
SceneManager->Instantiate() - делает копию

PrefabManager->Load() - копия, но с другими Guid


Widgets:
1. SizeComponent - int width, int height
2. AlignComponent - 