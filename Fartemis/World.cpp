#include "World.hpp"

namespace Fartemis {

    Entity& World::RegisterEntity() {
        m_entities.push_back( Entity() );
        return m_entities.back();
    };

    void World::Process() {
        for ( auto entity = m_entities.begin(); entity != m_entities.end(); ++entity ) {
            entity->Process();
        };
    };

};
