#include "Boot.h"
short ReadSect
(const char *_dsk,    // disk to access
	BootSector *&_buff,         // buffer where sector will be stored
	unsigned int _nsect   // sector number, starting with 0
)
{
	DWORD dwRead;
	HANDLE hDisk = CreateFileA(_dsk, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, 0, 0);
	if (hDisk == INVALID_HANDLE_VALUE) // this may happen if another program is already reading from disk
	{
		CloseHandle(hDisk);
		return 1;
	}
	SetFilePointer(hDisk, _nsect * 512, 0, FILE_BEGIN); // which sector to read

	ReadFile(hDisk, _buff, 512, &dwRead, 0);  // read sector
	CloseHandle(hDisk);
	return 0;
}
Boot::Boot() {
	BootSector *boot=new BootSector();
	//char *buff = new char[512];
	ReadSect(drive, boot, sector);
	printf(" %02hhx %02hhx\n", (unsigned int)(unsigned char)boot->mark[0], (unsigned int)(unsigned char)boot->mark[1]);
	cout << (unsigned int)(boot->size_sector) << endl;
	printf("%02hhx %02hhx %02hhx\n", (unsigned int)boot->JMP[0], (unsigned int)boot->JMP[1], (unsigned int)boot->JMP[2]);
	printf("%02hhx\n", (unsigned int)boot->sector_per_cluster);
	printf("%04hhx\n", (unsigned int)boot->sector_per_track);
	/*for (int i = 0; i < 512; ++i) {
		if ((i+1) % 16 == 0) {
			printf(" %02hhX\n", (unsigned int)(unsigned char)buff[i]);
		}else printf(" %02hhX ", (unsigned int)(unsigned char)buff[i]);
	}*/
}