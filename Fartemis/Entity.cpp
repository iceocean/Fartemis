#include "Entity.hpp"

namespace Fartemis {

    Entity::~Entity() {
        for ( auto comp = m_components.begin(); comp != m_components.end(); ++comp ) {
            delete *comp;
        };
    };

    void Entity::Process() {
        for ( auto system = m_systems.begin(); system != m_systems.end(); ++system ) {
            (*system)( *this );
        };
    };

    void Entity::RegisterComponent( Component* a_component ) {
        m_components.push_back( a_component );
    };

    void Entity::RegisterSystem( void ( *a_system )( Entity& ) ) {
        m_systems.push_back( a_system );
    };

};
