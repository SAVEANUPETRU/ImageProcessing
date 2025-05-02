#include "imageprocessing.h"
#include <cmath>
ImageProcessing::~ImageProcessing() = default;
Brightness::Brightness(int _alpha, int _beta){
  alpha = _alpha;
  beta = _beta;
}
Brightness::Brightness(){
  alpha = 1;
  beta = 0;
}
void Brightness::process(const Image& src, Image& dst){
  dst = src*alpha + beta;
}
GammaCorrection::GammaCorrection(float _gamma){
  gamma = _gamma;
}
GammaCorrection::GammaCorrection(){
  gamma = 1;
}
void GammaCorrection::process(const Image& src, Image& dst){
  int height = src.height(), width = src.width();
  dst = src;
  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width; ++j) {
      float value = float(src.at(i, j));
      value = pow(value,gamma);
      if (value > 255) value = 255;
      if (value < 0) value = 0;

      dst.adjust(j, i, static_cast<unsigned char>(value));
    }
  }
}
Convolution::Convolution(float _kernel[3][3], unsigned char (*_scale)(float)) {
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
      kernel[i][j] = _kernel[i][j];

  scale = _scale;
}
void Convolution::process(const Image& src, Image& dst) {
  int height = src.height();
  int width = src.width();
  dst = Image(height, width);

  int k = 1;

  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width; ++j) {
      float acc = 0.0;

      for (int u = 0; u < 3; ++u) {
        for (int v = 0; v < 3; ++v) {
          int x = i + u - k;
          int y = j + v - k;

          if (x >= 0 && x < height && y >= 0 && y < width)
            acc += kernel[u][v] * src.at(x, y);
        }
      }

      dst.adjust(j, i,  static_cast<unsigned char>(scale(acc)));
    }
  }
}
