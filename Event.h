#pragma once

#include "Window.h"

class Event {
public:
    virtual~ Event();

    const enum eventType {
        Default,
        KeyEvent,
        MouseEvent,
        WindowResizeEvent,
    }

    Event(const eventType&, int, int, int, int);
    Event(const eventType&, double, double);

    int m_key=0, m_scancode=0, m_action=0, m_mods=0;
    double m_mousex=0, m_mousey=0;
private:
};

/**
 * The Singleton class defines the `GetInstance` method that serves as an
 * alternative to constructor and lets clients access the same instance of this
 * class over and over.
 */
class EventHandler
{

    /**
     * The Singleton's constructor should always be private to prevent direct
     * construction calls with the `new` operator.
     */

protected:
    EventHandler(std::shared_ptr<Window> window): m_windowHandle(window);
    {
    }

    static EventHandler* s_instance;

public:

    /**
     * Singletons should not be cloneable.
     */
    EventHandler(EventHandler &other) = delete;
    /**
     * Singletons should not be assignable.
     */
    void operator=(const EventHandler &) = delete;
    /**
     * This is the static method that controls the access to the singleton
     * instance. On the first run, it creates a singleton object and places it
     * into the static field. On subsequent runs, it returns the client existing
     * object stored in the static field.
     */

    static EventHandler *GetInstance(std::shared_ptr<Window>);
    /**
     * Finally, any singleton should define some business logic, which can be
     * executed on its instance.
     */

    static void addListener(std::shared_ptr<EventListener>);
    static void dispatch(const Event&);

    static std::vector<EventListener> m_listeners;
};

class EventListener{
public:
    void newEvent(const Event&);
    std::queue<Event> getEvents() {return m_eventQueue;}
private:
    std::queue<Event> m_eventQueue;
};

