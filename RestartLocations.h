// COMPLETED

#define SD_RL_H_Count	8
#define SD_RL_P_Count	8

union SD_RestartLocations
	{
	struct RL_Formatted
		{
		ulong RL_BlockSize;			// ������ ����� (0x0128)
		ulong RL_SubBlockSize;		// ������ �������� (0x0124)
		uchar RL_BlockName[4];		// �������� ����� (RST)
		ulong RL_SubBlock1Size;		// ������ ����������� ����� (0x011C)

		struct RL_Hospital			// ���� �������������� ���� "���������"
			{
			float RL_H_X;			// ������������
			float RL_H_Y;
			float RL_H_Z;
			float RL_H_Rotation;	// �������
			} RL_H[SD_RL_H_Count];

		struct RL_Police			// ���� �������������� ���� "����������� �������"
			{
			float RL_P_X;			// ������������
			float RL_P_Y;
			float RL_P_Z;
			float RL_P_Rotation;	// �������
			} RL_P[SD_RL_P_Count];

		uint RL_HospitalRPCount;	// ����� ����������
		uint RL_PoliceRPCount;		// ����� ����������� ��������
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
