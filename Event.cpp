#include "Event.h"

EventHandler::EventHandler(std::shared_ptr<Window> window) : 
    m_windowHandle(window)
{

}

EventHandler* EventHandler::s_instance = nullptr;

/**
 * Static methods should be defined outside the class.
 */
EventHandler *EventHandler::GetInstance(std::shared_ptr<Window> value = nullptr)
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

static void EventHandler::dispatch(const Event& event)
{
    for(auto l : m_listeners)
    {
        l->newEvent(event);
    }
}

static void EventHandler::add(std::shared_ptr<EventListener> listener)
{
    s_listeners.insert(listener);
}


void EventListener::newEvent(const Event& e)
{
    m_eventQueue.push(e);
}
