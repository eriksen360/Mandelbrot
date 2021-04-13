#pragma once
#include <cstdint>

#pragma pack(2) // limit struct padding to 2 bytes
typedef struct BmpFileHeader {
	char bitMapSignatureByte[2]{ 'B', 'M' }; // informs application that this is a bitmap file
	uint32_t fileSize;
	uint32_t reserved = 0;
	uint32_t dataOffset;   // How long into the files does the data begin
} BmpFileHeader;