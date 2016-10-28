// INCOMPLETED //

#define SD_VS_GVS_Size 0x5E6
#define SD_VS_BoS_Size 0x4CA
#define SD_VS_BiS_Size 0x4F6

union SD_Vehicles
	{
	struct VH_Formatted
		{
		ulong VH_BlockSize;				// ������ �����
		ulong VH_SubBlockSize;			// ������ ��������

		ulong VH_GeneralVehiclesCount;	// ����� �������� �����
		ulong VH_BoatsCount;			// ����� �����
		ulong VH_BikesCount;			// ����� ����������
		} VH;

	uchar VH_Raw [sizeof (struct VH_Formatted)];
	};

union SD_VehicleStructure
	{
	struct VS_Formatted
		{
		ulong VS_VehicleType;		// ��� ����������: 0 - general, 1 - boat, 5 - bike
		uint VS_VehicleID;
		ulong VS_VehicleIndex;

		uchar VS_DataFlow1[42];

		float VS_X;
		float VS_Y;
		float VS_Z;

		uchar VS_DataFlow2[28];

		uint VS_VehicleID2;

		uchar VS_DataFlow3[SD_VS_GVS_Size /* max */ - 94];
		} VS;

	uchar VS_Raw [1];
	};
