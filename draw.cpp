#include "draw.h"
Image drawCircle(Image& img, Point center,int radius, unsigned char color){
  Image image{img};
    for(int i=0;i<img.height();i++){
      for(int j=0;j<img.width();j++){
        if((center.get_y()-i)*(center.get_y()-i)+(center.get_x()-j)*(center.get_x()-j)<=radius*radius){
             image.adjust(i,j,color);
        }
        else{
          image.adjust(i,j,img.at(i,j));
        }
      }
    }
    return image;
}
Image drawLine(Image& img, Point p1, Point p2, unsigned char color) {
  int x1 = p1.get_x(), y1 = p1.get_y();
  int x2 = p2.get_x(), y2 = p2.get_y();
  int dx = x2 - x1, dy = y2 - y1;
  int in = 0;
  Image result = img;

  for (int i = 0; i < img.height(); ++i) {
    for (int j = 0; j < img.width(); ++j) {
      if(((x1<=i &&  i<=x2)||(x2<=i &&  i<=y1))&&((y1<=j &&  j<=y2)||(y2<=j &&  j<=y1)))
        in = 1;
      else
        in = 0;
      int vey = i - y1;
      int vex = j - x1;
      if (dx != 0 && dy != 0) {
        float rapx = static_cast<float>(vex) / dx;
        float rapy = static_cast<float>(vey) / dy;
        if (abs(rapx - rapy) < 0.1 && in == 1) {
          result.adjust(i, j, color);
        }
      } else if (dx == 0) {
        if (j == x1 && in == 1) {
          result.adjust(i, j, color);
        }
      } else if (dy == 0) {
        if (i == y1 && in == 1) {
          result.adjust(i, j, color);
        }
      }
    }
  }

  return result;
}
Image drawRectangle(Image& img, Rectangle r, unsigned char color){
  Point corner = r.get_corner();
  int width = r.get_width();
  int height = r.get_height();
  Image result{img};
  for(int i=0;i<img.height();i++){
    for(int j=0;j<img.width();j++){
      if(corner.get_y()-height <= i && corner.get_y()>=i &&  corner.get_x()+width >= j && corner.get_x()<=j){
        result.adjust(i,j,color);
      }
      else{
        result.adjust(i,j,img.at(i,j));
      }
    }
  }
  return result;
}
Image drawRectangle(Image& img, Point tl,Point br, unsigned char color){
  Image image{img};
  for(int i=0;i<img.height();i++){
    for(int j=0;j<img.width();j++){
      if(tl.get_x()<= j && j<=br.get_x() &&  tl.get_y()>=i && i>=br.get_y() ){
        image.adjust(i,j,color);
      }
      else{
        image.adjust(i,j,img.at(i,j));
      }

    }
  }
  return image;
}