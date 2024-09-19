#include "Event.h"

Event::Event(const Event::eventType& type, int key, int scancode, int action, int mods)
    : m_key(key), m_scancode(scancode), m_action(action), m_mods(mods)
{
    EventHandler::GetInstance()->dispatch(*this);
}

Event::Event(const Event::eventType& type, double xpos, double ypos)
    : m_mousex(xpos), m_mousey(ypos)
{

}

EventHandler* EventHandler::s_instance = nullptr;

/**
 * Static methods should be defined outside the class.
 */
EventHandler *EventHandler::GetInstance(Window* value)
{
    /**
     * This is a safer way to create an instance. instance = new Singleton is
     * dangeruous in case two instance threads wants to access at the same time
     */
    if(s_instance==nullptr){
        s_instance = new EventHandler(value);
    }
    return s_instance;
}

void EventHandler::dispatch(const Event event)
{
    for(auto l : m_listeners)
    {
        l->newEvent(event);
    }
}

void EventHandler::addListener(EventListener* listener)
{
    m_listeners.push_back(listener);
}


void EventListener::newEvent(const Event& e)
{
    m_eventQueue.push(e);
}
