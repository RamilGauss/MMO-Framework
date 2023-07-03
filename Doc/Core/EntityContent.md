
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

Childs:  
- nsCommonWrapper::TGuidComponent
- nsCommonWrapper::TNameComponent
- nsCommonWrapper::TParentGuidComponent  


#### After instantiate  

При инстанциировани происходит добавлении информации о вселенной, которой принадлежит сцена, в которую
инстанцируется префаб.
Но можно инстанцировать в сцену с одной вселенной, но сделать проекцию объектов префаба в другую вселенную.

Root:  

- nsCommonWrapper::TPrefabParentGuidComponent
- nsCommonWrapper::TLocalMatrixComponent  

Root, Others:  

- nsCommonWrapper::TPrefabGuidComponent  
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

Others:  

- nsCommonWrapper::TGuidComponent  
- nsCommonWrapper::TNameComponent  
- nsCommonWrapper::TParentGuidComponent  

#### After instantiate  

Root, Others:

- nsCommonWrapper::TSceneGuidComponent  
- nsCommonWrapper::TSceneOriginalGuidComponent  
- nsCommonWrapper::TSceneInstanceGuidComponent  

- nsCommonWrapper::TUniverseGuidComponent  
- nsCommonWrapper::TUniverseIndexComponent  

---


