#ifndef WIDGET_H
#define WIDGET_H
#include "event.h"

class Widget {

public:
  Widget(int _x, int _y, int _width, int _height);
  Widget();

  //event handling
  virtual void handleEvent(Event *e)=0;

  //drawing functions
  virtual void display()=0;
  virtual void clear();

  //set our parameters
  virtual int x();
  virtual void x(int _x);
  virtual int y();
  virtual void y(int _y);
  virtual int width();
  virtual void width(int _width);
  virtual int height();
  virtual void height(int _height);
  virtual Widget *parent();
  virtual void parent(Widget *_parent);

 protected:
    int _x;
    int _y;
    int _width;
    int _height;
    Widget *_parent;
};

#endif // Widget_h
