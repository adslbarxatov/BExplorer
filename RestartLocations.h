// COMPLETED

#define SD_RL_H_Count	8
#define SD_RL_P_Count	8

union SD_RestartLocations
	{
	struct RL_Formatted
		{
		ulong RL_BlockSize;			// Размер блока (0x0128)
		ulong RL_SubBlockSize;		// Размер субблока (0x0124)
		uchar RL_BlockName[4];		// Название блока (RST)
		ulong RL_SubBlock1Size;		// Размер оставшегося блока (0x011C)

		struct RL_Hospital			// Зоны восстановления типа "госпиталь"
			{
			float RL_H_X;			// Расположение
			float RL_H_Y;
			float RL_H_Z;
			float RL_H_Rotation;	// Поворот
			} RL_H[SD_RL_H_Count];

		struct RL_Police			// Зоны восстановления типа "полицейский участок"
			{
			float RL_P_X;			// Расположение
			float RL_P_Y;
			float RL_P_Z;
			float RL_P_Rotation;	// Поворот
			} RL_P[SD_RL_P_Count];

		uint RL_HospitalRPCount;	// Число госпиталей
		uint RL_PoliceRPCount;		// Число полицейских участков
		uchar RL_OverrideNextRestart;
		uchar RL_Unused1[3];
		float RL_OverrideX;
		float RL_OverrideY;
		float RL_OverrideZ;
		float RL_OverrideRotation;
		uchar RL_Unused2[2];
		uchar RL_OverrideHospitalLevel;
		uchar RL_OverridePoliceLevel;
		} RL;

	char RL_Raw [sizeof (struct RL_Formatted)];
	};
