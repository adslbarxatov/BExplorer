// INCOMPLETED //

#define SD_PPL_WD_Count	10

union SD_PedPlayer
	{
	struct PPL_Formatted
		{
		ulong PPL_BlockSize;		// ������ ����� (0x0708)
		ulong PPL_SubBlock1Size;	// ������ �������� 1 (0x0703)
		ulong PPL_NumberOfPlayers;	// ����� ������� (1)

		// �� ����, ���������� ������ ����� ������������ ��� ������. �� � �� ������ ����� 1 �������
		uchar PPL_Unused1[6];
		ulong PPL_PlayerIndex;						// ����� ������
		uchar PPL_PlayerPedStructureDump1[52];		// �������� ����� ��������� ������
		float PPL_X;								// ��������� ������
		float PPL_Y;
		float PPL_Z;
		uchar PPL_PlayerPedStructureDump2[788];		// �������� ����� ��������� ������
		float PPL_CurrentHealth;					// ������� �������� (�� ���������� ��� ����)
		float PPL_CurrentArmor;						// ������� ��������� �����
		uchar PPL_PlayerPedStructureDump3[172];		// �������� ����� ��������� ������

		// ��������� ��������� ������
		struct PPL_WeaponData
			{
			ulong PPL_WD_WeaponNumber;	// ����� ������ �� �������
			uchar PPL_WD_Unused1[4];
			ulong PPL_WD_HolderSize;	// ������ ������
			ulong PPL_WD_BulletsCount;	// ����� ����
			uchar PPL_WD_Unused2[8];
			} PPL_WD[SD_PPL_WD_Count];

		uchar PPL_PlayerPedStructureDump4[12];	// �������� ����� ��������� ������
		uchar PPL_SelectedWeapon;				// ������� ��������� ������
		uchar PPL_PlayerPedStructureDump5[255];	// �������� ����� ��������� ������
		float PPL_MaxStamina;					// ������������ ������������
		uchar PPL_PlayerPedStructureDump6[28];	// �������� ����� ��������� ������
		slong PPL_TargettableObjects[4];		// �������, �� ������� �������� ����������
		uchar PPL_PlayerPedStructureDump7[164];	// �������� ����� ��������� ������
		ulong PPL_MaxWantedLevel;				// ������������ ������� ������� (������������� 4)
		ulong PPL_MaxCriminalPoints;			// ������������ �������� �������� ������� (������������� 1800)
		uchar PPL_SuitName[22];					// ������� ������
		} PPL;

	uchar PPL_Raw [sizeof (struct PPL_Formatted)];
	};
