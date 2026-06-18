#include "scene/Scene.h"

namespace eng 
{   
    void Scene::Update(float deltaTime) 
    {
        for(auto it = m_objects.begin(); it != m_objects.end();) {
            if((*it)->IsAlive()) 
            {
                (*it)->Update(deltaTime);
                ++it;
            }
            else 
            {
                it = m_objects.erase(it);
            }
        }
    }

    void Scene::Clear() 
    {
        m_objects.clear();
    }

    void Scene::SetParent(GameObject* obj, GameObject* parent) 
    {

    }


    GameObject* Scene::CreateObject(const std::string& name, GameObject* parent = nullptr)
    {
        auto obj = new GameObject();
        obj->SetName(name);
        SetParent(obj, parent);

        return obj;
    }

    // só permita usar CreateObject<T> se T herdar de GameObject
    template<typename T, typename = typename std::enable_if_t<std::is_base_of_v<GameObject,T>>>
    T* CreateObject(const std::string& name, GameObject* parent = nullptr) 
    {

    }

}