// #include "object.hpp"

// namespace rpg
// {

//     void Object::Update()
//     {
//         for (auto component : m_components)
//         {
//             component->Update();
//         }
//     }

//     void Object::Render()
//     {
//         for (auto component : m_components)
//         {
//             component->Render();
//         }
//     }

//     template <typename T>
//     T Object::AddComponent()
//     {
//         IComponent newComponent = new T{*this};

//         m_components.push_back(&newComponent);
//         newComponent.Begin();

//         return newComponent;
//     }

//     template <typename T>
//     T &Object::GetComponent()
//     {
//         for (auto component : m_components)
//         {
//             if (typeid(component) == typeid(T))
//             {
//                 return component;
//             }
//         }
//         return nullptr;
//     }

// } // namespace rpg