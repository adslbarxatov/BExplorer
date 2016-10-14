// ������� ���������
struct SaveData
	{
	// Default parameters
	union SD_DefaultParameters SD_DP;

	// Script block
	union SD_ScriptBlock SD_SB;
	union SD_ScriptBlockAUnit *SD_SBA;	ulong SD_SBA_Count;
	union SD_ScriptBlockB SD_SBB;

	// Ped pool
	union SD_ScriptPool SD_SC;
	union SD_ScriptStructure *SD_SS;	ulong SD_SS_Count;
	union SD_PedPlayer SD_PPL;

	// Garages
	union SD_Garages SD_GR;

	// Wasted and busted
	union SD_TaxiShortcuts SD_TS;

	// Vehicles block
	union SD_Vehicles SD_VH;
	union SD_VehicleStructure *SD_VS;	ulong SD_VS_Count;

	// Objects pool
	union SD_ObjectPool SD_OP;
	union SD_ObjectStructure *SD_OS;	ulong SD_OS_Count;

	// Paths block
	union SD_Paths SD_PH;
	union SD_PathsDescription *SD_PHD;	ulong SD_PHD_Count;

	// Cranes
	union SD_Cranes SD_CR;

	// Pickups
	union SD_Pickups SD_PU;

	// Phone info
	union SD_PhoneInfo SD_PI;

	// Restart points
	union SD_RestartLocations SD_RL;

	// Radar blips
	union SD_RadarBlips SD_RB;

	// Zones buffer
	union SD_ZonesBuffer SD_ZB;

	// Gang data
	union SD_GangData SD_GD;

	// Car generators
	union SD_CarGenerators SD_CG;

	// Particles
	union SD_Particles SD_PR;
	union SD_ParticleDescription *SD_PRD;	ulong SD_PRD_Count;

	// Audio scripts
	union SD_AudioScripts SD_AU;
	union SD_AudioScriptStructure *SD_AS;	ulong SD_AS_Count;

	// Script path
	union SD_ScriptPath SD_SP;

	// Player info
	union SD_PlayerInfo SD_PL;

	// Stats
	union SD_Stats SD_ST;

	// Trigger zones
	union SD_TriggerZones SD_TZ;

	// Streaming block
	union SD_Streaming SD_SR;

	// Ped types
	union SD_PedTypes SD_PT;

	// Checksum
	union SD_CheckSum SD_CS;
	ulong SD_CheckSum;
	};

// ������� ��������� ���� ���������� GTA VC (.b) � ���������
// ��������� SaveData, �������� ��� ����������� ��������.
// � ������ ������ ���������� ������ ��������� �� ��������� �
// ���� �� ��������� ����� ������:
//
#define SD_LOAD_ERR_FileNotFound			-1	// ���� � ��������� ������ ���������� ��� �����������
#define SD_LOAD_ERR_MemoryAllocationFailure	-2	// ������ ��������� ������ ��� ���� �� ��������
//
#define SD_LOAD_ERR_LoadDP	-101	// ������ �������� ��������� default parameters: ������ ������ ��� ����������� ����� �����
#define SD_LOAD_ERR_LoadSB	-102	// ������ �������� ��������� script block: ~
#define SD_LOAD_ERR_LoadSBA	-103	// ������ �������� ��������� script block a: ~
#define SD_LOAD_ERR_LoadSBB	-104	// ������ �������� ��������� script block b: ~
#define SD_LOAD_ERR_LoadSC	-105	// ������ �������� ��������� script pool: ~
#define SD_LOAD_ERR_LoadSS	-106	// ������ �������� ��������� script structures: ~
#define SD_LOAD_ERR_LoadPPL	-107	// ������ �������� ��������� ped player: ~
#define SD_LOAD_ERR_LoadGR	-108	// ������ �������� ��������� garages: ~
#define SD_LOAD_ERR_LoadTS	-109	// ������ �������� ��������� wasted and busted: ~
#define SD_LOAD_ERR_LoadVS	-110	// ������ �������� ��������� vehicles:
#define SD_LOAD_ERR_LoadOP	-111	// ������ �������� ��������� object pool: ~
#define SD_LOAD_ERR_LoadOS	-112	// ������ �������� ��������� objects structures: ~
#define SD_LOAD_ERR_LoadPH	-113	// ������ �������� ��������� paths: ~
#define SD_LOAD_ERR_LoadPHD	-114	// ������ �������� ��������� paths description: ~
#define SD_LOAD_ERR_LoadCR	-115	// ������ �������� ��������� cranes: ~
#define SD_LOAD_ERR_LoadPU	-116	// ������ �������� ��������� pickups: ~
#define SD_LOAD_ERR_LoadPI	-117	// ������ �������� ��������� phoneinfo: ~
#define SD_LOAD_ERR_LoadRL	-118	// ������ �������� ��������� restart location: ~
#define SD_LOAD_ERR_LoadRB	-119	// ������ �������� ��������� radar blips: ~
#define SD_LOAD_ERR_LoadZB	-120	// ������ �������� ��������� zones buffer: ~
#define SD_LOAD_ERR_LoadGD	-121	// ������ �������� ��������� gang data: ~
#define SD_LOAD_ERR_LoadCG	-122	// ������ �������� ��������� car generators: ~
#define SD_LOAD_ERR_LoadPR	-123	// ������ �������� ��������� particles: ~
#define SD_LOAD_ERR_LoadPRD	-124	// ������ �������� ��������� particles: ~
#define SD_LOAD_ERR_LoadAU	-125	// ������ �������� ��������� audio scripts: ~
#define SD_LOAD_ERR_LoadAS	-126	// ������ �������� ��������� audio script structure: ~
#define SD_LOAD_ERR_LoadSP	-127	// ������ �������� ��������� script path: ~
#define SD_LOAD_ERR_LoadSPP	-128	// ������ �������� ��������� script path point: ~
#define SD_LOAD_ERR_LoadPL	-129	// ������ �������� ��������� player info: ~
#define SD_LOAD_ERR_LoadST	-130	// ������ �������� ��������� stats: ~
#define SD_LOAD_ERR_LoadTZ	-131	// ������ �������� ��������� trigger zones: ~
#define SD_LOAD_ERR_LoadSR	-132	// ������ �������� ��������� streaming block: ~
#define SD_LOAD_ERR_LoadPT	-133	// ������ �������� ��������� ped types: ~
#define SD_LOAD_ERR_LoadCS	-134	// ������ �������� ��������� checksum: ~
//
// � ������ ��������� ���������� ��� ������
#define SD_NO_ERRORS	0
//
int SaveData_Load (char *FilePath, struct SaveData *SD);

// ������������ ����� ��������� � ������
#define SD_MaxStrSize	257

// �������, ���������� �� ����� ��������� �� �������
char *SaveData_ErrorPrompt (int Error);

// ��������� �������������
// ��������� ����������� ��������� � ������� ��� ����������
// ���������� ��������� � ���������� ���������� ������� ���
// ��������� �� ������, ���������� �� ������ �� ��������� �����:
#define SD_INTRPR_ERR_ValueOutOfRange		-1001
#define SD_INTRPR_ERR_ModeNotSpecified		-1002
#define SD_INTRPR_ERR_CommandIsTooLong		-1003
#define SD_INTRPR_ERR_ValueIsIncorrect		-1004
#define SD_INTRPR_ERR_ModeIsIncorrect		-1005
#define SD_INTRPR_ERR_ValueRequired			-1006
#define SD_INTRPR_ERR_AssetIsUnavailable	-1007
#define SD_INTRPR_ERR_UnsupportedParameter	-1008
#define SD_INTRPR_ERR_GeneratorIsUnavailable	-1009
//
#define SD_INTRPR_ERR_StatsFileNotFound		-1101
#define SD_INTRPR_ERR_StatsFileIsIncorrect	-1102
#define SD_INTRPR_ERR_CannotCreateStatsFile	-1103
#define SD_INTRPR_ERR_CGFileNotFound		-1104
#define SD_INTRPR_ERR_CGFileIsIncorrect		-1105
#define SD_INTRPR_ERR_CannotCreateCGFile	-1106
//
char *SaveData_CommandInterpreter (struct SaveData *SD, char *cmd);

// ����������� �������� ����������
#define SD_LIMIT_dpyea_B	1980	// dp-year
#define SD_LIMIT_dpyea_T	2080
#define SD_LIMIT_dpmon_B	1		// dp-month
#define SD_LIMIT_dpmon_T	12
#define SD_LIMIT_dpday_B	1		// dp-day
#define SD_LIMIT_dpday_T	31
#define SD_LIMIT_dphou_B	0		// dp-hour
#define SD_LIMIT_dphou_T	23
#define SD_LIMIT_dpmin_B	0		// dp-minute
#define SD_LIMIT_dpmin_T	59
#define SD_LIMIT_dpsec_B	SD_LIMIT_dpmin_B	// dp-second
#define SD_LIMIT_dpsec_T	SD_LIMIT_dpmin_T
#define SD_LIMIT_dpiml_B	100		// dp-ingameminutelengthms
#define SD_LIMIT_dpiml_T	60000
#define SD_LIMIT_dpgho_B	SD_LIMIT_dphou_B	// dp-gamehour
#define SD_LIMIT_dpgho_T	SD_LIMIT_dphou_T
#define SD_LIMIT_dpgmi_B	SD_LIMIT_dpmin_B	// dp-gameminute
#define SD_LIMIT_dpgmi_T	SD_LIMIT_dpmin_T
#define SD_LIMIT_dpgsp_B	0.1f	// dp-gamespeed
#define SD_LIMIT_dpgsp_T	10.0f
#define SD_LIMIT_dpswn_B	-1		// dp-staticweathernumber
#define SD_LIMIT_dpswn_T	5
#define SD_LIMIT_dpccv_B	0.0f	// dp-carcameraview
#define SD_LIMIT_dpccv_T	5.0f
#define SD_LIMIT_dpinu_B	0		// dp-interiornumber
#define SD_LIMIT_dpinu_T	18
#define SD_LIMIT_sbcbr_B	0		// sbb-cabsradio
#define SD_LIMIT_sbcbr_T	1
#define SD_LIMIT_plcua_B	0.0f	// pl-currentarmor
#define SD_LIMIT_plcua_T	900.f
#define SD_LIMIT_plwnu_B	0		// pl-weaponnumber
#define SD_LIMIT_plwnu_T	36
#define SD_LIMIT_plwbu_B	0		// pl-weaponbullets
#define SD_LIMIT_plwbu_T	12000
#define SD_LIMIT_plmwl_B	0		// pl-maxwantedlevel
#define SD_LIMIT_plmwl_T	6
#define SD_LIMIT_plmcp_B	0		// pl-maxcriminalpoints
#define SD_LIMIT_plmcp_T	7200
//#define SD_LIMIT_grsgs_B	0		// pl-sungaragestatus
//#define SD_LIMIT_grsgs_T	63
#define SD_LIMIT_grcmo_B	0		// gr-carmodel (0, 130 - 236)
#define SD_LIMIT_grcmo_T	236
#define SD_LIMIT_grimm_B	0		// gr-immunity
#define SD_LIMIT_grimm_T	15
#define SD_LIMIT_grcol_B	0		// gr-color
#define SD_LIMIT_grcol_T	99
#define SD_LIMIT_grrad_B	0		// gr-radio
#define SD_LIMIT_grrad_T	23
#define SD_LIMIT_puass_B	100		// pu-assetmax
#define SD_LIMIT_puass_T	50000
#define SD_LIMIT_LastAssetNumber	9
#define SD_LIMIT_gdcmo_B	-1		// gd-carmodel (-1, 130 - 236)
#define SD_LIMIT_gdcmo_T	SD_LIMIT_grcmo_T
#define SD_LIMIT_gdpmo_B	9		// gd-pedmodel
#define SD_LIMIT_gdpmo_T	96
#define SD_LIMIT_gdwnu_B	SD_LIMIT_plwnu_B	// gd-weaponnumber
#define SD_LIMIT_gdwnu_T	SD_LIMIT_plwnu_T
#define SD_LIMIT_plcum_B	0.0f	// pl-currentmoney
#define SD_LIMIT_plcum_T	99000000.0f
#define SD_LIMIT_pliru_B	SD_LIMIT_sbcbr_B	// pl-infiniterun
#define SD_LIMIT_pliru_T	SD_LIMIT_sbcbr_T
#define SD_LIMIT_plfre_B	SD_LIMIT_sbcbr_B	// pl-fastreload
#define SD_LIMIT_plfre_T	SD_LIMIT_sbcbr_T
#define SD_LIMIT_plfpr_B	SD_LIMIT_sbcbr_B	// pl-fireproof
#define SD_LIMIT_plfpr_T	SD_LIMIT_sbcbr_T
#define SD_LIMIT_plmxh_B	100		// pl-maxhealth
#define SD_LIMIT_plmxh_T	200
#define SD_LIMIT_plmxa_B	SD_LIMIT_plmxh_B	// pl-maxarmor
#define SD_LIMIT_plmxa_T	250
#define SD_LIMIT_cgcmo_B	SD_LIMIT_gdcmo_B	// cg-carmodel (-1, 130 - 236)
#define SD_LIMIT_cgcmo_T	SD_LIMIT_grcmo_T
#define SD_LIMIT_cgx_B		-2000.0f		// cg-x
#define SD_LIMIT_cgx_T		2000.0f
#define SD_LIMIT_cgy_B		SD_LIMIT_cgx_B	// cg-y
#define SD_LIMIT_cgy_T		SD_LIMIT_cgx_T
#define SD_LIMIT_cgz_B		-20.0f			// cg-z
#define SD_LIMIT_cgz_T		500.0f
#define SD_LIMIT_cgrot_B	0.0f			// cg-rot
#define SD_LIMIT_cgrot_T	359.9f
#define SD_LIMIT_cgasp_B	-1				// cg-allowspawn
#define SD_LIMIT_cgasp_T	0
#define SD_LIMIT_cgcol_B	-1				// cg-color
#define SD_LIMIT_cgcol_T	SD_LIMIT_grcol_T
#define SD_LIMIT_cgala_B	0				// cg-alarm
#define SD_LIMIT_cgala_T	100
#define SD_LIMIT_cgloc_B	SD_LIMIT_cgala_B	// cg-lock
#define SD_LIMIT_cgloc_T	SD_LIMIT_cgala_T
#define SD_LIMIT_cgfsp_B	SD_LIMIT_sbcbr_B	// cg-forcespawn
#define SD_LIMIT_cgfsp_T	SD_LIMIT_sbcbr_T
#define SD_LIMIT_stinb_B	SD_LIMIT_sbcbr_B	// st-infinitebullets
#define SD_LIMIT_stinb_T	SD_LIMIT_sbcbr_T

// ������� ������ ���� ���������� GTA VC (.b) �� ������
// ����� �������������� ���������
// ���������� 0 � ������ ������ ��� ���� �� ��������� ��������
// ��� ������������� ������ ��� �������� �����:
#define SD_SAVE_ERR_CannotCreateFile		-2001	// �� ������ ������� ����
#define SD_SAVE_ERR_FileNotLoaded			-2002	// ���� �� ��� ��������
//
int SaveData_Save (char *FilePath, struct SaveData *SD);

// ����������� �������������� ������
int SaveData_LoadStats (struct SaveData *SD, char *FilePath);
int SaveData_SaveStats (struct SaveData *SD, char *FilePath);
int SaveData_LoadCG (struct SaveData *SD, char *FilePath);
int SaveData_SaveCG (struct SaveData *SD, char *FilePath);
int SaveData_LoadGarages (struct SaveData *SD, char *FilePath);
int SaveData_SaveGarages (struct SaveData *SD, char *FilePath);
