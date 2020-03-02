#include "Image.h"
#include "StickerSheet.h"

int main() {

  Image flower, heart, corn, output;
  flower.readFromFile("flower.png");
  heart.readFromFile("heart.png");
  corn.readFromFile("corn.png");

  StickerSheet sticker(flower, 4);
  sticker.addSticker(flower, 416, 36);
  sticker.addSticker(heart, 298, 70);
  sticker.addSticker(corn, 550, 60);

  output = sticker.render();
  output.writeToFile("myImage.png");

  return 0;


  //
  // Reminder:
  //   Before exiting main, save your creation to disk as myImage.png
  //

  return 0;
}
