#pragma once
#ifndef Boot_h
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <cstdint>
using namespace std;
const size_t sector_size = 512;
#define sector 0
struct BootSector {
	UINT8 JMP[3];//1//3b
	UINT8 OEM[8];//2//8byte
	UINT16 size_sector;//3
	uint8_t sector_per_cluster;//4
	uint16_t reserved;//5
	uint8_t Fat_cnt;//6
	uint16_t size_root;//7
	uint16_t sec_per_disk;//8
	char magnetic_disk_type;//9
	uint16_t sec_per_FAT;//10
	uint16_t sector_per_track;//11
	uint16_t heat_cnt;//12
	uint32_t hidden_sectors;//13
	uint32_t total_sector_disk;//14
	char unknown[31];//15
	uint32_t Serial_Number;//16
	char Volume_Name[11];//17
	char Fat_type[8];//18
	char loader[415];
	char mark[2];
}; 
class Boot {
	const char *drive="\\\\.\\E:";
public:
	Boot();
	//virtual ~Boot();
	BootSector *boot_sector;
	size_t sectorsize();
	size_t clustersize();
private:
	void sanityCheck();
};
#endif // Boot_h