#include "Object.h"
#include "Event.h"

Object::Object()
{
    EventHandler::GetInstance()->addListener(m_eventListener);
}

void Object::update()
{
    while(m_eventListener->getEvents().size())
    {
        m_eventListener->getEvents().pop();
    }
}
