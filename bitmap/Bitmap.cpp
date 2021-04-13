#include "Bitmap.h"
#include "BitMapFileHeader.h"
#include "BitMapFileInfo.h"

// every pixel on the screen contains three bytes (R, G and B)
Bitmap::Bitmap(const uint32_t height, const uint32_t width) : m_height(height), m_width(width),
	m_pixelsPtr(new uint8_t[width * height * 3]{100}) {
	
}

bool Bitmap::writeToFile(std::string fileName) const {

	BmpFileHeader fileHeader;
	BmpFileInfo fileInfo; 

	// set Bitmap total file size. Offset is distance from start of file to where to start reading data
	fileHeader.fileSize = sizeof(BmpFileHeader) + sizeof(BmpFileInfo) + (fileInfo.width * fileInfo.height * 3);
	fileHeader.dataOffset = sizeof(BmpFileHeader) + sizeof(BmpFileInfo);
	fileInfo.width = m_width;
	fileInfo.height = m_height;

	// open and write to new binary file
	std::fstream bitMapFile;
	bitMapFile.open(fileName, std::ios::out|std::ios::binary);
	if (!bitMapFile.is_open()) {
		return false;
	}

	// Write header and info data. The smart_ptr must be cast to regular pointer type before being passed as an argument
	bitMapFile.write((char*)&fileHeader, sizeof(BmpFileHeader)); 
	bitMapFile.write((char*)&fileInfo, sizeof(BmpFileInfo));
	bitMapFile.write((char*)m_pixelsPtr.get(), m_width*m_height*3);

	// check file is closed properly
	bitMapFile.close();
	if (bitMapFile.is_open()) { return false; }
	return true;
}

void Bitmap::setPixel(const uint32_t& xCoor, const uint32_t& yCoor, const uint8_t red, const uint8_t green, const uint8_t blue) {
	// each pixel takes up 3 bytes so each increment of our pointer must be three bytes
	uint8_t* pixelPtr = m_pixelsPtr.get();
	pixelPtr += 3*yCoor * m_width + 3*xCoor; 

	// bitmap is little endian file format, color coding must be passed B -> G -> R.
	// these are relative addresses, might be pixelPtr[0xFF4A], pixelPtr[0xFF4B], pixelPtr[0xFF4C]
	pixelPtr[0] = blue; 
	pixelPtr[1] = green;
	pixelPtr[2] = red;
}

Bitmap::~Bitmap() {}
