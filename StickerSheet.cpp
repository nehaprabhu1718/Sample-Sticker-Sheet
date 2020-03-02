#include "StickerSheet.h"
#include "cs225/PNG.h"
#include "Image.h"
#include <iostream>
using namespace cs225;


    StickerSheet::StickerSheet(const Image &picture, unsigned max) { //done final version

      maxStickers = max;
      basePicture = picture;
      numStickers = 0;

      stickers = new Image *[max];
      xCoordinates = new unsigned [max];
      yCoordinates = new unsigned [max];

      for (unsigned i = 0; i < max; i++) {
        stickers[i] = NULL;
      }
    }

    void StickerSheet::copy(const StickerSheet &other) {

      basePicture = other.basePicture;
      numStickers = other.numStickers;
      maxStickers = other.maxStickers;

      stickers = new Image *[maxStickers];
      xCoordinates = new unsigned [maxStickers];
      yCoordinates = new unsigned [maxStickers];

      for (unsigned i = 0; i < maxStickers; i++) {
        stickers[i] = NULL;
      }

      for (unsigned i = 0; i < numStickers; i++) {
        if (other.stickers[i] != NULL) {

        stickers[i] = new Image();
        *stickers[i] = *other.stickers[i];

        xCoordinates[i] = other.xCoordinates[i];
        yCoordinates[i] = other.yCoordinates[i];

      }
    }
  }

    void StickerSheet::clear() { //done final version

      for (unsigned i = 0; i < numStickers; i++) {

        delete stickers[i];
        stickers[i] = NULL;

      }
      delete[] stickers;
      delete[] xCoordinates;
      delete[] yCoordinates;
      yCoordinates = NULL;
      xCoordinates = NULL;
      stickers = NULL;

    }

    StickerSheet::~StickerSheet() { //done final version
      clear();

    }

    StickerSheet::StickerSheet(const StickerSheet &other) { //done final version
      copy(other);

    }

    const StickerSheet & StickerSheet::operator=(const StickerSheet &other) { //done final version
      clear();
      copy(other);
      return *this;

    }

    void StickerSheet::changeMaxStickers(unsigned max) {
       //done final version



      if (numStickers < max) {
        Image **temp_stickers = new Image*[max];
        unsigned *otherX = new unsigned[max];
        unsigned *otherY = new unsigned[max];
        for (unsigned i = 0; i < max; i++) {
          temp_stickers[i] = NULL;
          otherX[i] = 0;
          otherY[i] = 0;
        }

        for (unsigned i = 0; i < max; i++) {

          if(i<numStickers){
            temp_stickers[i] = stickers[i];
            otherX[i] = xCoordinates[i];
            otherY[i] = yCoordinates[i];
          }
          else{
            temp_stickers[i] = NULL;
          }
        }
        delete[] stickers;
        delete[] xCoordinates;
        delete[] yCoordinates;

        stickers = temp_stickers;
        xCoordinates = otherX;
        yCoordinates = otherY;
      }

      if (numStickers > max) {
        Image **temp_stickers2 = new Image*[max];
        unsigned *otherX2 = new unsigned[max];
        unsigned *otherY2 = new unsigned[max];
        for (unsigned i = 0; i < max; i++) {
          temp_stickers2[i] = NULL;
          otherX2[i] = 0;
          otherY2[i] = 0;
        }

        for (unsigned i = 0; i < numStickers; i++) {
          if (i >= max) {
            delete stickers[i];
          }

          else {

            temp_stickers2[i] = stickers[i];
            otherX2[i] = xCoordinates[i];
            otherY2[i] = yCoordinates[i];
          }

        }
        delete stickers;
        delete xCoordinates;
        delete yCoordinates;

        stickers = temp_stickers2;
        xCoordinates = otherX2;
        yCoordinates = otherY2;
        numStickers = max;
      }
    maxStickers = max;
  }


    int StickerSheet::addSticker(Image &sticker, unsigned x, unsigned y) { //maybe problematic
      //int i;

    //  if (numStickers < maxStickers) {

        for (unsigned i = 0; i <  maxStickers; i++) {
          if(stickers[i] == NULL){
          stickers[i] = new Image(sticker);
          xCoordinates[i] = x;
          yCoordinates[i] = y;
          numStickers++;
          return i;
        }
      }
        //numStickers++;

        return -1;


    }
    bool StickerSheet::translate(unsigned index, unsigned x, unsigned y) { //done final version

      if (index < numStickers) {

        xCoordinates[index] = x;
        yCoordinates[index] = y;
        return true;

      }
        return false;
      }


    void StickerSheet::removeSticker(unsigned index) { //done final version

      /*if (index <numStickers) {
        for (unsigned i = index; i < numStickers - 1; i++) {

          //shifting to the next spot

           *stickers[i] = *stickers[i + 1];
           xCoordinates[i] = xCoordinates[i + 1];
           yCoordinates[i] = yCoordinates[i + 1];

        }

        //deleting the last position
        stickers[numStickers] = NULL;
        delete stickers[numStickers - 1];
        numStickers--;
      }
    }
    */
    if (index <= numStickers) {
      delete stickers[index];
      xCoordinates[index] = 0;
      yCoordinates[index] = 0;
      for (unsigned i = index; i < numStickers - 1; i++) {
        stickers[i] = stickers[i+1];
        xCoordinates[i] = xCoordinates[i + 1];
        yCoordinates[i] = yCoordinates[i + 1];
      }
      stickers[numStickers - 1] = NULL;
      xCoordinates[numStickers - 1] = 0;
      yCoordinates[numStickers - 1] = 0;
      numStickers--;
    }
  }

    Image* StickerSheet::getSticker(unsigned index) { //done final version

      if (index < numStickers) {
        return stickers[index];

      }
        return NULL;
      }

    Image StickerSheet::render() const { //done final version

      /*Image temp_image(basePicture);
      unsigned newwidth = basePicture.width();
      unsigned newheight = basePicture.height();


      for (unsigned i = 0; i < numStickers; i++) {

        if (stickers[i] !=  NULL) {

          if ((xCoordinates[i] + stickers[i]->width()) > newwidth) {
            newwidth = xCoordinates[i] + stickers[i]->width();
          }

          if ((yCoordinates[i] + stickers[i]->height()) > newheight) {
            newheight = yCoordinates[i] + stickers[i]->height();
          }
        }
      }


      temp_image.resize(newwidth,newheight);



      for (unsigned i = 0; i < numStickers; i++) {

        if (stickers[i] !=  NULL) {


          for (unsigned j = xCoordinates[i]; j < (xCoordinates[i] + stickers[i]->width()); j++) {
            for (unsigned k = yCoordinates[i]; k < (yCoordinates[i] + stickers[i]->height()); k++) {

              HSLAPixel & pixel1 = temp_image.getPixel(j, k);
              HSLAPixel & pixel2 = stickers[i]->getPixel(j - xCoordinates[i], k - yCoordinates[i]); //make it plus not minus

              if (pixel2.a != 0) {
                pixel1 = pixel2;
                //std::cout << "lol" << std::endl;
              }
            }
          }
        }
      }
      return temp_image;
    }
    */

    Image* sheet = new Image(basePicture);
    unsigned newwidth = sheet->width();
    unsigned newheight = sheet->height();


    for (unsigned i = 0; i < maxStickers; i++) {

      if (stickers[i] !=  NULL) {

        if ((xCoordinates[i] + stickers[i]->width()) > sheet->width()) {
          newwidth = xCoordinates[i] + stickers[i]->width();
        }

        if ((yCoordinates[i] + stickers[i]->height()) > sheet->height()) {
          newheight = yCoordinates[i] + stickers[i]->height();

        }
        sheet->resize(newwidth,newheight);
      }
    }
    for (unsigned i = 0; i < maxStickers; i++) {

      if (stickers[i] !=  NULL) {


        for (unsigned j = xCoordinates[i]; j < (xCoordinates[i] + stickers[i]->width()); j++) {
          for (unsigned k = yCoordinates[i]; k < (yCoordinates[i] + stickers[i]->height()); k++) {

            HSLAPixel & pixel1 = sheet->getPixel(j, k);
            HSLAPixel & pixel2 = stickers[i]->getPixel(j - xCoordinates[i], k - yCoordinates[i]); //make it plus not minus

            if (pixel2.a != 0) {
              pixel1 = pixel2;
              //std::cout << "lol" << std::endl;
            }
          }
        }
      }
    }
    Image sticker_sheet = *sheet;
    delete sheet;
    return sticker_sheet;
  }
