#include "size.h"
Size::Size(){
  height = 0;
  width = 0;
}
Size::Size(int height, int width){
  this->height = height;
  this->width = width;
}
int Size::getheight(){
  return height;
}
int Size::getwidth(){
  return width;
}
int Size::getsize(){
	return width*height;
}
