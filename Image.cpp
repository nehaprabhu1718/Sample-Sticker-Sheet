#include "Image.h"

using cs225::HSLAPixel;
using cs225::PNG;
using namespace cs225;

//using this-> because image is already initialized in test case.
//initially did PNG::image = new PNG();

void Image::lighten() {

  for (unsigned int i = 0; i < this->width(); i++) {
    for (unsigned int j = 0; j < this->height(); j++) {

      HSLAPixel &pixel = this->getPixel(i,j);
      if (pixel.l + 0.1 <= 1) {
        pixel.l = pixel.l + 0.1;
      } else {
        pixel.l = 1;
      }
    }
  }
}
void Image::lighten(double amount) {
  for (unsigned i = 0; i < this->width(); i++) {
    for (unsigned j = 0; j < this->height(); j++) {

      HSLAPixel &pixel = this->getPixel(i,j);
      if (pixel.l + amount <= 1) {
        pixel.l = pixel.l + amount;
      } else {
        pixel.l = 1;
      }
    }
  }
}
void Image::darken() {
  for (unsigned i = 0; i < this->width(); i++) {
    for (unsigned j = 0; j < this->height(); j++) {

      HSLAPixel & pixel = this->getPixel(i,j);
      if (pixel.l - 0.1 < 0) {
        pixel.l = 0;
      } else {
        pixel.l = pixel.l - 0.1;
      }
    }
  }
}
void Image::darken(double amount) {
  for (unsigned i = 0; i < this->width(); i++) {
    for (unsigned j = 0; j < this->height(); j++) {

      HSLAPixel & pixel = this->getPixel(i,j);
      if (pixel.l - amount < 0) {
        pixel.l = 0;
      } else {
        pixel.l = pixel.l - amount;
      }
    }
  }
}
void Image::saturate() {
  for (unsigned i = 0; i < this->width(); i++) {
    for (unsigned j = 0; j < this->height(); j++) {

      HSLAPixel &pixel = this->getPixel(i,j);
      if (pixel.s + 0.1 <= 1) {
        pixel.s = pixel.s + 0.1;
      } else {
        pixel.s = 1;
      }

    }
  }
}
void Image::saturate(double amount) {
  for (unsigned i = 0; i < this->width(); i++) {
    for (unsigned j = 0; j < this->height(); j++) {

      HSLAPixel &pixel = this->getPixel(i,j);
      if (pixel.s + amount <= 1) {
        pixel.s = pixel.s + amount;
      } else {
        pixel.s = 1;
      }
    }
  }
}
void Image::desaturate() {
  for (unsigned i = 0; i < this->width(); i++) {
    for (unsigned j = 0; j < this->height(); j++) {

      HSLAPixel &pixel = this->getPixel(i,j);
      if (pixel.s - 0.1 >= 0) {
        pixel.s = pixel.s - 0.1;
      } else {
        pixel.s = 0;
      }

    }
  }
}
void Image::desaturate(double amount) {
  for (unsigned i = 0; i < this->width(); i++) {
    for (unsigned j = 0; j < this->height(); j++) {

      HSLAPixel &pixel = this->getPixel(i,j);
      if (pixel.s - amount >= 0) {
        pixel.s = pixel.s - 0.1;
      } else {
        pixel.s = 0;
      }
    }
  }
}
//grayscale from lab_intro
void Image::grayscale(){
  for (unsigned i = 0; i < this->width(); i++) {
    for (unsigned j = 0; j < this->height(); j++) {

      HSLAPixel &pixel = this->getPixel(i,j);
      pixel.s = 0;

    }
  }
}
void Image::scale(double factor) {

  unsigned int newWidth = width() * factor;
  unsigned int newHeight = height() * factor;

  PNG* scaledImage = new PNG(*this);
  resize(newWidth, newHeight);

  for (unsigned int i = 0; i < this->width(); i++) {
    for (unsigned int j = 0; j < this->height(); j++) {

      unsigned int new_i = (1.0 * i) / factor;
      unsigned int new_j = (1.0 * j) / factor;

      HSLAPixel &pixel1 = this->getPixel(i,j);
      HSLAPixel &pixel2 = scaledImage->getPixel(new_i, new_j);

      pixel1 = pixel2;
    }
  }
  delete scaledImage;
}

void Image::scale(unsigned w, unsigned h) {

  double wRatio = 1.0*w/this->width();
  double hRatio = 1.0*h/this->height();

  if(wRatio < hRatio) {
    scale(wRatio);
  } else {
    scale(hRatio);
  }
}



void Image::rotateColor(double degrees) {
  for (unsigned i = 0; i < this->width(); i++) {
    for (unsigned j = 0; j < this->height(); j++) {

      HSLAPixel &pixel = this->getPixel(i,j);
      if (degrees > 0) {
        if (pixel.h + degrees < 360)
          pixel.h = pixel.h + degrees;
        else
          pixel.h = (pixel.h + degrees) - 360;
      }
      else {
        if (pixel.h + degrees > 0)
          pixel.h = pixel.h + degrees;
        else
          pixel.h = 360 + (pixel.h + degrees);
      }
    }
  }
}

//illinify from lab_intro
void Image::illinify() {
  for (unsigned i = 0; i < this->width(); i++) {
    for (unsigned j = 0; j < this->height(); j++) {

      HSLAPixel &pixel = this->getPixel(i,j);
      if (pixel.h <= 119 || pixel.h > 293.5) {
        pixel.h = 11;
      } else {
        pixel.h = 216;
      }
    }
  }
}
