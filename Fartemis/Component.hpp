#ifndef FARTEMIS_COMPONENT_HPP
#define FARTEMIS_COMPONENT_HPP

namespace Fartemis {

    class Component {
    public:
        Component( const std::type_info& a_type ) : m_type( &a_type ) {};
        virtual ~Component() {};

        inline const std::type_info* GetType() { return m_type; };

    private:
        const std::type_info*       m_type;

    };

};

#endif
