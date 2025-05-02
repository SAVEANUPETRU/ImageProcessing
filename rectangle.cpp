#include "rectangle.h"
#include <iostream>
using namespace std;
Rectangle::Rectangle(Point &p,Point &q){
  x = p.get_x();
  y = p.get_y();
  width = q.get_x()-p.get_x();
  height = p.get_y()-q.get_y();
}
Rectangle::Rectangle(){
  width=height=0;
  x=y=0;
}
Rectangle::Rectangle(int x,int y,int width,int height){
  this->x=x;
  this->y=y;
  this->width=width;
  this->height=height;
}
ostream& operator<<(ostream& os, const Rectangle& r){
  os<<"Left corner: "<<r.x<<" "<<r.y<<" "<<r.width<<" "<<r.height<<endl;
  return os;
}
istream& operator>>(istream& is, Rectangle& r){
  is>>r.x>>r.y>>r.width>>r.height;
  return is;
}
Rectangle Rectangle::operator+(Point& p){
  return Rectangle(this->x+p.get_x(),this->y+p.get_y(),this->width,this->height);
}
Rectangle Rectangle::operator-(Point& p){
  return Rectangle(this->x-p.get_x(),this->y-p.get_y(),this->width,this->height);
}
Rectangle Rectangle::operator&(const Rectangle& other) const {
  int x1 = max(this->x, other.x);
  int y1 = min(this->y, other.y);
  int x2 = min(this->x + this->width, other.x + other.width);
  int y2 = max(this->y - this->height, other.y - other.height);

  if (x2 < x1 || y2 > y1)
    return Rectangle(x1, y1, 0, 0);

  return Rectangle(x1, y1, x2 - x1, y1 - y2);
}

Rectangle Rectangle::operator|(const Rectangle& other) const {
  int x1 = min(this->x, other.x);
  int y1 = max(this->y, other.y);
  int x2 = max(this->x + this->width, other.x + other.width);
  int y2 = min(this->y - this->height, other.y - other.height);

  return Rectangle(x1, y1, x2 - x1, y1 - y2);
}

Point Rectangle::get_corner() const {
  return Point(this->x,this->y);
}
int Rectangle::get_height() const {
  return height;
}
int Rectangle::get_width() const {
  return width;
}