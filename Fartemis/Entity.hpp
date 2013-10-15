#ifndef FARTEMIS_ENTITY_HPP
#define FARTEMIS_ENTITY_HPP

#include <vector>
#include "Component.hpp"

namespace Fartemis {

    class Entity {
    public:
        void                        Process();

        void                        RegisterComponent( Component* );
        void                        RegisterSystem( void ( * )( Entity& ) );

        template < class T >
        T*                          RequestComponent();

    private:
        std::vector< Component* >               m_components;

        std::vector< void ( * )( Entity& ) >    m_systems;
    };

    template < class T >
    T* Entity::RequestComponent() {
        for ( auto comp = m_components.begin(); comp != m_components.end(); ++comp ) {
            T* compRecast = static_cast< T* >( *comp );

            if ( compRecast->GetType() == &typeid( T ) ) {
                return compRecast;
            };
        };

        return nullptr;
    };

};

#endif
