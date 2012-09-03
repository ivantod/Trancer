/*
 * Colour.h
 *
 *  Created on: 1 Jul 2012
 *      Author: ivantod
 */

#ifndef COLOUR_H_
#define COLOUR_H_

struct Colour {
	enum OFFSET {
		OFFSET_RED = 0,
		OFFSET_GREEN = 1,
		OFFSET_BLUE = 2,
		OFFSET_MAX = 3,
	};

	float red, green, blue;

	inline float& getChannel(OFFSET offset) {
		return reinterpret_cast<float*>(this)[offset];
	}

	inline float getChannel(OFFSET offset) const {
		return reinterpret_cast<const float*>(this)[offset];
	}

	inline Colour& operator+=(const Colour &c2 ) {
		this->red +=  c2.red;
		this->green += c2.green;
		this->blue += c2.blue;
		return *this;
	}

	inline Colour operator/=(const float a) {
		this->red /= a;
		this->blue /= a;
		this->green /= a;
		return *this;
	}
};

inline Colour operator*(const Colour &c, float coeff) {
	Colour retCol = { c.red * coeff, c.green * coeff, c.blue * coeff };
	return retCol;
}

inline Colour operator*=(const Colour &c, float coeff) {
	Colour retCol = { c.red * coeff, c.green * coeff, c.blue * coeff };
	return retCol;
}

inline Colour operator*(const Colour &c1, const Colour &c2) {
	Colour retCol = { c1.red * c2.red, c1.green * c2.green, c1.blue * c2.blue };
	return retCol;
}

inline Colour operator+(const Colour &c1, const Colour &c2) {
	Colour retCol = { c1.red + c2.red, c1.green + c2.green, c1.blue + c2.blue };
	return retCol;
}

#endif /* COLOUR_H_ */
