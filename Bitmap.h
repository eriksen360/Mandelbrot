#pragma once
#include <cstdint>
#include <string>
#include <memory>
#include <fstream>

// Bitmap class - m_pixelsPtr is a pointer to an 8-bit arrray which holds pixels 
class Bitmap {
private:
	uint32_t m_height;
	uint32_t m_width;
	std::unique_ptr<uint8_t[]> m_pixelsPtr{ nullptr };

public:
	Bitmap(const uint32_t height = 0, const uint32_t width = 0);
	void setPixel(const uint32_t& xCoor, const uint32_t& yCoor, const uint8_t red, const uint8_t green, const uint8_t blue);
	bool writeToFile(std::string fileName) const;
	virtual ~Bitmap();
};