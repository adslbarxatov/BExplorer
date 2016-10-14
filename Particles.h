// INCOMPLETED //

union SD_Particles
	{
	struct PR_Formatted
		{
		ulong PR_BlockSize;			// Размер блока
		ulong PR_SubBlockSize;		// Размер субблока
		ulong PR_ParticlesCount;	// Число объектов
		} PR;

	uchar PR_Raw [sizeof (struct PR_Formatted)];
	};

union SD_ParticleDescription
	{
	struct PRD_Formatted
		{
		uchar PRD_Unused1[48];
		float PRD_PositionX;	// Расположение
		float PRD_PositionY;
		float PRD_PositionZ;
		uchar PRD_Unused2[28];
		ulong PRD_ParticleType1;
		ulong PRD_ParticleType2;
		uchar PRD_Visibility;
		uchar PRD_Sparsity;
		uint PRD_SparsityCounter;
		uchar PRD_Unused3[4];
		float PRD_StrengthX;
		float PRD_StrengthY;
		float PRD_StrengthZ;
		uchar PRD_Unused4[4];
		float PRD_Scale;
		uchar PRD_Unused5[8];
		} PRD;

	uchar PRD_Raw[1];
	};
