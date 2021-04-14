#pragma once
	
#pragma pack(2) // limit struct padding to 2 bytes
typedef struct BmpFileInfo {
	uint32_t headerSize = 40; // sizeof(BmpInfo) = 40
	uint32_t width;
	uint32_t height;
	uint16_t planes = 1;
	uint16_t bitsPerPixel = 24; // RGB color padlet
	uint32_t compression = 0;
	uint32_t dataSize = 0; // initialization, changes later
	uint32_t horizontalResolution = 2400;
	uint32_t verticalResolution = 2400;
	uint32_t colors = 0;
	uint32_t importantColors = 0;
} BmpFileInfo;
