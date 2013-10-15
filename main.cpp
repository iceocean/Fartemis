#include <iostream>
#include "Fartemis/Fartemis.hpp"

class TransformComponent : public Fartemis::Component {
public:
    TransformComponent( float a_x, float a_y ) :
        Component( typeid( TransformComponent ) ),
        x( a_x ),
        y( a_y ) {};

    float x, y;
};

class VelocityComponent : public Fartemis::Component {
public:
    VelocityComponent( float a_x, float a_y ) :
        Component( typeid( VelocityComponent ) ),
        x( a_x ),
        y( a_y ) {};

    float x, y;
};

void MovementSystem( Fartemis::Entity& );
void DebugOutputSystem( Fartemis::Entity& );

int main( int argc, char** argv ) {
    Fartemis::World world;

    Fartemis::Entity& entity = world.RegisterEntity();

    entity.RegisterComponent( new TransformComponent( 0.0f, 0.0f ) );
    entity.RegisterComponent( new VelocityComponent( 1.0f, 1.0f ) );

    entity.RegisterSystem( &MovementSystem );
    entity.RegisterSystem( &DebugOutputSystem );

    for ( int i = 0; i < 5; ++i ) {
        world.Process();
    };

    std::cin.get();
    return 0;
};

void MovementSystem( Fartemis::Entity& a_entity ) {
    TransformComponent* transform = a_entity.RequestComponent< TransformComponent >();
    VelocityComponent* velocity = a_entity.RequestComponent< VelocityComponent >();

    if ( transform != nullptr && velocity != nullptr ) {
        transform->x += velocity->x;
        transform->y += velocity->y;
    };
};

void DebugOutputSystem( Fartemis::Entity& a_entity ) {
    TransformComponent* transform = a_entity.RequestComponent< TransformComponent >();
    
    if ( transform != nullptr ) {
        std::cout << transform->x << ", " << transform->y << '\n';
    };
};
