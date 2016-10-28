#define SD_GR_GC_Count	48
#define SD_GR_GS_Count	32

// ��������� ������ � ������
// �������� �� ����������� ��-�� ������������� ��� ������� GaragesInterchange
struct GarageCars
	{
	ulong GR_GC_ModelID;		// ������ ����
	float GR_GC_X;				// ��������� ���� � ������
	float GR_GC_Y;
	float GR_GC_Z;
	float GR_GC_vX;				// ������� ����
	float GR_GC_vY;
	float GR_GC_vZ;
	ulong GR_GC_Immunity;		// ������: b3 = damageproof, b2 = explosionproof, b1 = fireproof, b0 = bulletproof
	uchar GR_GC_PrimaryColor;	// ����� ����
	uchar GR_GC_SecondaryColor;
	uchar GR_GC_RadioStation;	// ������� ����������� (0 - 9, 10 - ���������)
	uchar GR_GC_Variation1;		// �������������� �����������
	uchar GR_GC_Variation2;
	uchar GR_GC_BombType;		// ��� ���� (0 - ���, 1 - �������, 2 - �� ������, 3 - ����������������, 4 - �������� 1, 5 - �������� 2)
	uchar GR_GC_Unused1[2];
	};

union SD_Garages
	{
	struct GR_Formatted
		{
		ulong GR_BlockSize;				// ������ ����� (0x1EC8)
		ulong GR_SubBlockSize;			// ������ �������� (0x1EC4)
		ulong GR_NumberOfGarages;		// ����� �������� �������
		ulong GR_FreeBombs;				// ���������� ��������� ����, 0 ��� 1
		ulong GR_FreeRespray;			// ���������� ��������, 0 ��� 1
		ulong GR_Unused1;
		ulong GR_SecuricarsCollected;	// �� ������������
		ulong GR_PoliceCarsCollected;	// �� ������������
		ulong GR_SunGarage1Status;		// ���������� Sunshine; 000001b = ���� #1 ��������, 100100b = �������� ���� #3 � #6
		ulong GR_SunGarage2Status;		// ^ ����� 2
		ulong GR_SunGarage3Status;		// ^ ����� 3
		ulong GR_SunGarage4Status;		// ^ ����� 4
		ulong GR_GarageFullMsgLastShow;	// ����� ���������� ����������� ��������� � ������ ������

		// ��������� ����� � �������
		struct GarageCars GR_GC[SD_GR_GC_Count];

		// ��������� �������
		struct GarageStructure
			{
			uchar GR_GS_Type;			// ��� ������
			// 2 - ����� ��� ��������� ��� � ��������
			// 3 - ����� ��� ��������� ��� �� ������� ��� �������
			// 4 - ����� ��� ��������� ��� �� ���������������
			// 5 - ����� ��� ��������
			// 7 - ���������� ����� ����� ��� ��������������
			// 8-10 - Sunshine auto collection 1-3
			// 16 - El Swanko Casa
			// 17, 18 - Human Condo 1, 2
			// 19 - Copland garage
			// 22 - Sunshine auto collection 4
			// 23 - 'Sir, yes, sir' garage
			// 24 - Human Condo 3
			// 25 - Ocean Heights
			// 26 - Links View
			// 27-30 - Sunshine auto 1-4
			// 31 - Versetti Estate
			// 32 - unused save garage
			uchar GR_GS_Status;				// ���������: 0 - ������, 1 - ������, 2 - �����������, 3 - �����������
			uchar GR_GS_MaxCarsInside;		// �������� ���� � ������
			uchar GR_GS_Unused01;
			uchar GR_GS_MissionKeepCar;		// ������ ����������� ��� ������
			uchar GR_GS_IsDeactive;			// ����� ���������
			uchar GR_GS_ResprayHappened;	// ���� ������������ ��������
			uchar GR_GS_Unused02;
			ulong GR_GS_TargetCarModel;		// ������� ������ ����
			ulong GR_GS_DoorObjectPointer;	// ��������� �� ������-�����
			ulong GR_GS_CrusherTopObjectPointer;	// ��������� �� ������-�����
			uchar GR_GS_Unused1[5];
			uchar GR_GS_SwingDoor;			// ��� �����: ���������� (1) ��� ��������� (0)
			uchar GR_GS_CameraFollow;		// ���������� ������ (0) ��� ��� ������� (1)
			uchar GR_GS_Unused2;
			float GR_GS_EntranceBotLeft_X;	// ������������ ����������� ������������
			float GR_GS_EntranceBotLeft_Y;
			float GR_GS_EntranceBotLeft_Z;
			float GR_GS_QuatRot_X;			// ������� ������������
			float GR_GS_QuatRot_Y;
			float GR_GS_QuatRot_Z;
			float GR_GS_QuatRot_W;
			float GR_GS_CeilingZCoord;		// ������ ������� �����
			uchar GR_GS_Unused3[8];
			float GR_GS_LowerX;				// ��������� ����������
			float GR_GS_UpperX;
			float GR_GS_LowerY;
			float GR_GS_UpperY;
			float GR_GS_DoorCurrentHeight;	// ��������� ����� � �������� � �������� ��������� �� ���� ������
			float GR_GS_DoorMaxHeight;
			float GR_GS_DoorX;				// ���������� �����
			float GR_GS_DoorY;
			float GR_GS_CrusherTopX;		// ���������� ������
			float GR_GS_CrusherTopY;
			float GR_GS_DoorZ;				// ���������� �����
			float GR_GS_CrusherTopZ;		// ���������� ������
			ulong GR_GS_TimeToOpenDoor;		// ����� �� �������� �����
			ulong GR_GS_TargettedCar;		// ��������� ������
			uchar GR_GS_Unused4[44];
			} GR_GS[SD_GR_GS_Count];

		uchar GR_Unused2[536];
		} GR;

	uchar GR_Raw [sizeof (struct GR_Formatted)];
	};
