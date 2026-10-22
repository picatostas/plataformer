#pragma once

// RGB colour (0-255 per channel) plus a set of named presets.
class ColorPalette
{
public:
	ColorPalette();
	ColorPalette(unsigned char r, unsigned char g, unsigned char b);
	~ColorPalette(void);
	unsigned char r, g, b;

public:
	static ColorPalette Pink();
	static ColorPalette Yellow();
	static ColorPalette Orange();
	static ColorPalette Red();
	static ColorPalette Blue();
	static ColorPalette SkyBlue();
	static ColorPalette Green();
	static ColorPalette Forest_Green();
	static ColorPalette Deep_Green();
	static ColorPalette Lime();
	static ColorPalette Purple();
	static ColorPalette Brown();
	static ColorPalette Steel();
	static ColorPalette Gold();
	static ColorPalette White();
	static ColorPalette Gray();
	static ColorPalette Dark_Gray();
};
