#define SD_RB_S_Count	75

union SD_RadarBlips
	{
	struct RB_Formatted
		{
		ulong RB_BlockSize;			// ������ ����� (0x0E1C)
		ulong RB_SubBlockSize;		// ������ �������� (0x0E18)
		uchar RB_BlockName[4];		// �������� ����� (RDR)
		ulong RB_SubBlock2Size;		// ������ ����������� �����

		// ��������� �����
		struct RB_Structure
			{
			ulong RB_S_Color;		// ���� (0-6 - ������������� �����, ��������� - RGB)
			float RB_S_Unused1;
			ulong RB_S_BlipType;	// ��� �����: 0 - none, 1 - car, 2 - char, 3 - object/pickup, 4 - coord, 5 - contact point
			ulong RB_S_Entity;
			float RB_S_RadarX;		// ��������� ����� �� ������ (�� ��� entity)
			float RB_S_RadarY;
			float RB_S_MapX;		// ��������� ����� �� ����� (�� ��� entity)
			float RB_S_MapY;
			float RB_S_MapZ;
			uchar RB_S_Unused2[2];
			uchar RB_S_Brightness;	// ������� (1 - ���������; ��� ������������� ������; �� ��� ��������)
			uchar RB_S_Unused3;
			uchar RB_S_ShortRange;	// �������� ��� ������ �� ������� ������
			uchar RB_S_Unused4;
			uint RB_S_Size;			// ������
			uint RB_S_ShowType;		// ������ �����������: 0 - ������ ��; 1 - ������ �� �����; 2 - ������ �� ������; 3 - �������� ��
			uint RB_S_SpriteNumber;	// ��� ������� (���� ����)
			// 4 - Avery, 5 - Bikers (����� B), 6 - Cortez, 7 - Diaz, 8 - Kent Paul, 9 - Rosenberg, 10 - Phil, 11 - Bikers (����),
			// 12 - Boatyard, 13 - Malibu, 14 - Cubans, 15 - Film studio, 16 - Ammu-Nation, 17 - Haitians, 18 - Hardware store,
			// 19 - Save house, 20 - Pole position, 21 - Ice cream, 22 - Kaufman cabs, 23 - Lovefist, 24 - Printworks,
			// 26 - Sunshine auto, 27 - Pay'n'spray, 28 - Clothes shop, 29 - Versetti estate, 30 - Phone mission, 31 - 39 - radio stations
			} RB_S[SD_RB_S_Count];

		} RB;

	uchar RB_Raw [sizeof (struct RB_Formatted)];
	};
