#include "Object.h"
#include "Event.h"

Object::Object()
{
    model = new Model();

    model->load("./res/models/Truss/Truss.obj");
}

void Object::update()
{
}
