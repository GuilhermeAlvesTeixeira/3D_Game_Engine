#pragma once
#include <vector>
#include <string>
#include <memory>

#include "scene/GameObject.h"

namespace eng 
{   
    class GameObject;

    class Scene 
    {   
        public:
            void Update(float deltaTime);
            void Clear();

            //factory methods
            GameObject* CreateObject(const std::string& name, GameObject* parent = nullptr);

            // só permita usar CreateObject<T> se T herdar de GameObject
            template<typename T, typename = typename std::enable_if_t<std::is_base_of_v<GameObject,T>>>
            T* CreateObject(const std::string& name, GameObject* parent = nullptr) 
            {
                auto obj = new T();
                obj->SetName(name);
                SetParent(obj, parent);
                return obj;
            }

            void SetParent(GameObject* obj, GameObject* parent);


        private:
            //GameObjects
            std::vector<std::unique_ptr<GameObject>> m_objects;

    };
}