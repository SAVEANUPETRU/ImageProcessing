#include "point.h"
Point::Point(){
  x = 0;
  y = 0;
}
Point::Point(int x, int y){
  this->x = x;
  this->y = y;
}
ostream& operator<<(ostream& os, const Point& dt){
  os<<"("<<dt.x<<","<<dt.y<<")"<<endl;
  return os;
}
istream& operator>>(istream& is, Point& dt){
  is>>dt.x>>dt.y;
  return is;
}
int Point::get_x(){
  return x;
}
int Point::get_y(){
  return y;
}
