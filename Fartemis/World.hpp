#ifndef FARTEMIS_WORLD_HPP
#define FARTEMIS_WORLD_HPP

#include <vector>
#include "Entity.hpp"

namespace Fartemis {

    class World {
    public:
        Entity&                     RegisterEntity();
        void                        Process();

    private:
        std::vector< Entity >       m_entities;

    };

};

#endif
