/*
 * TGASupport.cpp
 *
 *  Created on: 1 Jul 2012
 *      Author: ivantod
 */

#include "TGASupport.h"
#include "Colour.h"
#include <fstream>

TGASupport::TGASupport(std::string fileName) :
	tgaFileOut(fileName.c_str(), std::ios::binary) {

}

void TGASupport::prepareHeader(int xSize, int ySize) {
	tgaFileOut.put(0); // No id present.
	tgaFileOut.put(0); // No colour map is included.
	tgaFileOut.put(2); // Uncompressed RGB image.
	tgaFileOut.put(0).put(0).put(0).put(0).put(0); // Colour map info (5 bytes), we don't care at all.
	tgaFileOut.put(0).put(0); // X-origin (2 bytes), set it to zero.
	tgaFileOut.put(0).put(0); // Y-origin (2 bytes), set it to zero.
	tgaFileOut.put((unsigned char)(xSize & 0x00FF)).put((unsigned char)((xSize & 0xFF00) / 256));
	tgaFileOut.put((unsigned char)(ySize & 0x00FF)).put((unsigned char)((ySize & 0xFF00) / 256));
	tgaFileOut.put(24); // Image has 24-bit colour.
	tgaFileOut.put(0); // Image descriptior, we don't care.

}

void TGASupport::writePixel(float red, float green, float blue) {
	tgaFileOut.put((unsigned char) min(blue*255.0f, 255.0f))
			  .put((unsigned char) min(green*255.0f, 255.0f))
			  .put((unsigned char) min(red*255.0f, 255.0f));
}

void TGASupport::writePixel(Colour c) {
	tgaFileOut.put((unsigned char) min(c.blue*255.0f, 255.0f))
			  .put((unsigned char) min(c.green*255.0f, 255.0f))
			  .put((unsigned char) min(c.red*255.0f, 255.0f));
}

TGASupport::~TGASupport() {
	tgaFileOut.close();
}
