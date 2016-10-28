// Подключение заголовков
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

// Определение типов и констант
#define schar		__int8
#define sint		__int16
#define slong		__int32
#define uchar		unsigned schar
#define uint		unsigned sint
#define ulong		unsigned slong

#define BFileSize	0x31464

// Подключение определений структур
#include "DefaultParameters.h"
#include "ScriptBlock.h"
#include "ScriptPool.h"
#include "PedPlayer.h"
#include "Garages.h"
#include "TaxiShortcuts.h"
#include "Vehicles.h"
#include "ObjectPool.h"
#include "Paths.h"
#include "Cranes.h"
#include "Pickups.h"
#include "PhoneInfo.h"
#include "RestartLocations.h"
#include "RadarBlips.h"
#include "ZonesBuffer.h"
#include "GangData.h"
#include "CarGenerators.h"
#include "Particles.h"
#include "AudioScripts.h"
#include "ScriptPaths.h"
#include "PlayerInfo.h"
#include "Stats.h"
#include "TriggerZones.h"
#include "Streaming.h"
#include "PedTypes.h"
#include "CheckSum.h"

// Главная структура
#include "SaveData.h"
