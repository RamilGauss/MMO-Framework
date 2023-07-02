
### Common  

Всегда есть TGuidComponent
При инстанцировании всегда генерируется Gui заново.
Оригинальный сохраняется. 
Инстанс объекта тоже имеет свой Guid. 

### Prefab  

#### In file

Root:  

- <span style="color:red">nsCommonWrapper::TPrefabRootComponent</span>  
- nsCommonWrapper::TGuidComponent  
- nsCommonWrapper::TNameComponent  
- nsCommonWrapper::TParentGuidComponent  
- nsCommonWrapper::TPrefabGuidComponent  

Childs:  
- nsCommonWrapper::TGuidComponent
- nsCommonWrapper::TNameComponent
- nsCommonWrapper::TParentGuidComponent
- nsCommonWrapper::TPrefabGuidComponent


#### After instantiate  

При инстанциировани происходит добавлении информации о вселенной, которой принадлежит сцена, в которую
инстанцируется префаб.
Но можно инстанцировать в сцену с одной вселенной, но сделать проекцию объектов префаба в другую вселенную.

Root, Others:  

- nsCommonWrapper::TPrefabOriginalGuidComponent  
- nsCommonWrapper::TPrefabInstanceGuidComponent  

- nsCommonWrapper::TSceneGuidComponent  
- nsCommonWrapper::TSceneInstanceGuidComponent  

- nsCommonWrapper::TUniverseGuidComponent  
- nsCommonWrapper::TUniverseIndexComponent  

### Scene  

#### In file  

Root:  

- <span style="color:red">nsCommonWrapper::TSceneRootComponent</span>  
- nsCommonWrapper::TGuidComponent  
- nsCommonWrapper::TParentGuidComponent  
- nsCommonWrapper::TNameComponent  
- nsCommonWrapper::TSceneGuidComponent  

Others:  

- nsCommonWrapper::TGuidComponent  
- nsCommonWrapper::TNameComponent  
- nsCommonWrapper::TParentGuidComponent  
- nsCommonWrapper::TSceneGuidComponent  

#### After instantiate  

Root, Others:

- nsCommonWrapper::TSceneOriginalGuidComponent  
- nsCommonWrapper::TSceneInstanceGuidComponent  

- nsCommonWrapper::TUniverseGuidComponent  
- nsCommonWrapper::TUniverseIndexComponent  

---


