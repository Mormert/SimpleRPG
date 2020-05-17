

#ifndef OBJECT_HPP
#define OBJECT_HPP

#define REGISTER_DEC_TYPE(NAME) \
    static DerivedRegister<NAME> reg
// Replaces: static DerivedRegister<TestObject> reg;

#define REGISTER_DEF_TYPE(NAME) \
    DerivedRegister<NAME> NAME::reg(#NAME)
// Replaces: DerivedRegister<TestObject> TestObject::reg("TestObject");

#include "component.hpp"

#include <vector>
#include <map>
#include <fstream>

namespace rpg
{
    // Base class for all objects
    class Object
    {
    private:
        std::vector<Component *> m_components;

    public:
        // Called in update pass, delegates to update pass in the components
        void Update();

        // Called in render pass, delegates to render pass in the components
        void Render();

        // Deletes all components on destructor
        virtual ~Object();

        // Example: rpg::Object myObject;
        // myObject.AddComponent(new rpg::TestComponent{});
        // Returns Object&, so the function is chainable
        template <typename T>
        Object &AddComponent(T *component);

        // Example: rpg::TestComponent *myComponent =
        // myObject.GetComponent<rpg::TestComponent>();
        // Dont forget to check for nulltpr if the object
        // does not have any component of the type T
        template <typename T>
        T *GetComponent();

        virtual void ObjectInitFromFile(std::ifstream &fileIn);
    };

    template <typename T>
    Object *CreateType()
    {
        return new T;
    };

    typedef std::map<std::string, Object *(*)()> map_type;

    class ObjectFactory
    {
    public:
        static Object *CreateInstance(std::string const &s);

    protected:
        static map_type *GetMap();

    private:
        static map_type *map;
    };

    template <typename T>
    class DerivedRegister : public ObjectFactory
    {
    public:
        DerivedRegister(std::string const &s)
        {
            GetMap()->insert(std::make_pair(s, &CreateType<T>));
        }
    };

} // namespace rpg

#include "object.inl"

#endif