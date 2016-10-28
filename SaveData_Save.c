// ���������� ��������������
#define _CRT_SECURE_NO_WARNINGS

// ����������� ������ ���������
#include "B_explorer.h"

// �������
#define SD_SAVE_FROM_VAR(ReadFrom,BytesCount)	wrotebytes += fwrite (ReadFrom, 1, BytesCount, FO);	\
	for (i = 0; i < BytesCount; i++)	\
		{	\
		checksum += (uchar)ReadFrom[i];	\
		}

// ������� ���������� �����
// � FilePath - ���� � �����
// � SD - ��������� ����������
int SaveData_Save (char *FilePath, struct SaveData *SD)
	{
	// ����������
	FILE *FO;
	ulong checksum = 0, i, wrotebytes = 0;

	// �������� ����������
	if (SD->SD_DP.DP.DP_BlockSize == 0)
		{
		return SD_INTRPR_ERR_FileNotLoaded;
		}

	// ������� �������� �����
	if ((FO = fopen (FilePath, "wb")) == NULL)
		{
		return SD_SAVE_ERR_CannotCreateFile;
		}

	// ������
	SD_SAVE_FROM_VAR (SD->SD_DP.DP_Raw, sizeof (union SD_DefaultParameters))
	SD_SAVE_FROM_VAR (SD->SD_SB.SB_Raw, sizeof (union SD_ScriptBlock))
	SD_SAVE_FROM_VAR (SD->SD_SBA->SBA_Variable_Raw, SD->SD_SBA_Count * sizeof (union SD_ScriptBlockAUnit))
	SD_SAVE_FROM_VAR (SD->SD_SBB.SBB_Raw, sizeof (union SD_ScriptBlockB))
	SD_SAVE_FROM_VAR (SD->SD_SC.SC_Raw, sizeof (union SD_ScriptPool))
	SD_SAVE_FROM_VAR (SD->SD_SS->SS_Raw, SD->SD_SS_Count * sizeof (union SD_ScriptStructure))
	SD_SAVE_FROM_VAR (SD->SD_PPL.PPL_Raw, sizeof (union SD_PedPlayer))
	SD_SAVE_FROM_VAR (SD->SD_GR.GR_Raw, sizeof (union SD_Garages))
	SD_SAVE_FROM_VAR (SD->SD_TS.TS_Raw, sizeof (union SD_TaxiShortcuts))

	//////////////////////////////////////////////////////////////////
	// Vehicles
	SD_SAVE_FROM_VAR (SD->SD_VH.VH_Raw, sizeof (union SD_Vehicles))
	for (i = 0; i < SD->SD_VS_Count; i++)
		{
		switch (SD->SD_VS[i].VS.VS_VehicleType)
			{
			case 0:	// General
				SD_SAVE_FROM_VAR (SD->SD_VS[i].VS_Raw, SD_VS_GVS_Size)
				break;

			case 1:	// Boat
				SD_SAVE_FROM_VAR (SD->SD_VS[i].VS_Raw, SD_VS_BoS_Size)
				break;

			case 5:	// Bike
				SD_SAVE_FROM_VAR (SD->SD_VS[i].VS_Raw, SD_VS_BiS_Size)
				break;
			// ������� �������� ��������� ������ ��������
			}
		}
	//////////////////////////////////////////////////////////////////

	SD_SAVE_FROM_VAR (SD->SD_OP.OP_Raw, sizeof (union SD_ObjectPool))
	SD_SAVE_FROM_VAR (SD->SD_OS->OS_Raw, SD->SD_OS_Count * sizeof (union SD_ObjectStructure))
	SD_SAVE_FROM_VAR (SD->SD_PH.PH_Raw, sizeof (union SD_Paths))
	SD_SAVE_FROM_VAR (SD->SD_PHD->PHD_Raw, SD->SD_PHD_Count)
	SD_SAVE_FROM_VAR (SD->SD_CR.CR_Raw, sizeof (union SD_Cranes))
	SD_SAVE_FROM_VAR (SD->SD_PU.PU_Raw, sizeof (union SD_Pickups))
	SD_SAVE_FROM_VAR (SD->SD_PI.PI_Raw, sizeof (union SD_PhoneInfo))
	SD_SAVE_FROM_VAR (SD->SD_RL.RL_Raw, sizeof (union SD_RestartLocations))
	SD_SAVE_FROM_VAR (SD->SD_RB.RB_Raw, sizeof (union SD_RadarBlips))
	SD_SAVE_FROM_VAR (SD->SD_ZB.ZB_Raw, sizeof (union SD_ZonesBuffer))
	SD_SAVE_FROM_VAR (SD->SD_GD.GD_Raw, sizeof (union SD_GangData))
	SD_SAVE_FROM_VAR (SD->SD_CG.CG_Raw, sizeof (union SD_CarGenerators))
	SD_SAVE_FROM_VAR (SD->SD_PR.PR_Raw, sizeof (union SD_Particles))
	SD_SAVE_FROM_VAR (SD->SD_PRD->PRD_Raw, SD->SD_PRD_Count * sizeof (union SD_ParticleDescription))
	SD_SAVE_FROM_VAR (SD->SD_AU.AU_Raw, sizeof (union SD_AudioScripts))
	SD_SAVE_FROM_VAR (SD->SD_AS->AS_Raw, SD->SD_AS_Count * sizeof (union SD_AudioScriptStructure))
	SD_SAVE_FROM_VAR (SD->SD_SP.SP_Raw, sizeof (union SD_ScriptPath))
	SD_SAVE_FROM_VAR (SD->SD_PL.PL_Raw, sizeof (union SD_PlayerInfo))
	SD_SAVE_FROM_VAR (SD->SD_ST.ST_Raw, sizeof (union SD_Stats))
	SD_SAVE_FROM_VAR (SD->SD_TZ.TZ_Raw, sizeof (union SD_TriggerZones))
	SD_SAVE_FROM_VAR (SD->SD_SR.SR_Raw, sizeof (union SD_Streaming))
	SD_SAVE_FROM_VAR (SD->SD_PT.PT_Raw, sizeof (union SD_PedTypes))

	// ���������� (padding) ����
	SD->SD_CS.CS.CS_Sum = BFileSize - sizeof (union SD_CheckSum) - wrotebytes - sizeof (ulong);	// ��������� ������� ����������� �����
	SD_SAVE_FROM_VAR (SD->SD_CS.CS_Raw, sizeof (union SD_CheckSum));	// ������ ������� � ������� ��������� CheckSum

	for (i = 0; i < SD->SD_CS.CS.CS_Sum; i++)	// ������ �����
		{
		fprintf (FO, "%c", 0);
		}

	// Check sum
	SD->SD_CheckSum = SD->SD_CS.CS.CS_Sum = checksum;
	SD_SAVE_FROM_VAR (SD->SD_CS.CS_Raw, sizeof (union SD_CheckSum));

	// ����������
	fclose (FO);
	return SD_SAVE_SUCCESS;
	}
