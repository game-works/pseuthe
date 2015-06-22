/*********************************************************************
Matt Marchant 2015
http://trederia.blogspot.com

pseuthe Zlib license.

This software is provided 'as-is', without any express or
implied warranty. In no event will the authors be held
liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute
it freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented;
you must not claim that you wrote the original software.
If you use this software in a product, an acknowledgment
in the product documentation would be appreciated but
is not required.

2. Altered source versions must be plainly marked as such,
and must not be misrepresented as being the original software.

3. This notice may not be removed or altered from any
source distribution.
*********************************************************************/

#include <OrbController.hpp>
#include <ParticleSystem.hpp>
#include <MessageBus.hpp>
#include <Entity.hpp>

OrbController::OrbController(MessageBus& mb)
    : Component         (mb),
    m_particleSystem    (nullptr)
{}

//public
Component::Type OrbController::type() const
{
    return Component::Type::Script;
}

void OrbController::entityUpdate(Entity&, float)
{

}

void OrbController::handleMessage(const Message& msg)
{
    switch (msg.type)
    {
    case Message::Type::Physics:
        if (msg.physics.entityId[0] == getParentUID() || msg.physics.entityId[1] == getParentUID())
        {
            m_particleSystem->start(1u, 0.f, 0.02f);
        }
        break;
    default:break;
    }
}

void OrbController::onStart(Entity& entity)
{
    m_particleSystem = entity.getComponent<ParticleSystem>("echo");
}