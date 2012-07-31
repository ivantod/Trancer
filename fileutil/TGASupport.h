/*
 * TGASupport.h
 *
 *  Created on: 1 Jul 2012
 *      Author: ivantod
 */

#ifndef TGASUPPORT_H_
#define TGASUPPORT_H_

#include <fstream>
#include <string>
#include "Colour.h"

using namespace std;

class TGASupport {

private:
	std::ofstream tgaFileOut;

public:
	TGASupport(std::string fileName);
	virtual ~TGASupport();

	void prepareHeader(int xSize, int ySize);

	void writePixel(float r, float g, float b);

	void writePixel(Colour c);
};

#endif /* TGASUPPORT_H_ */
