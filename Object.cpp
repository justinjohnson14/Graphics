#include "Object.h"
#include "Event.h"

Object::Object()
{
    EventHandler::GetInstance()->addListener(m_eventListener);
}

void Object::update()
{
    for (auto e : m_eventListener->getEvents())
    {
        //Do something with events
    }
}
