#include "targetver.h"
#include "slam.h"
#include "config.h"
#include <map>
#include <utility>

class FlightModelsList
{
public:
	FlightModelsList()
	{
		for (const auto& line : GetFileLines("FlightModels\\Spacecraft0.LST"))
		{
			this->_spacecraftList.push_back(GetStringWithoutExtension(line));
		}

		for (const auto& line : GetFileLines("FlightModels\\Equipment0.LST"))
		{
			this->_equipmentList.push_back(GetStringWithoutExtension(line));
		}
	}

	std::string GetLstLine(int modelIndex)
	{
		const int xwaObjectStats = 0x05FB240;
		const int dataIndex1 = *(short*)(xwaObjectStats + modelIndex * 0x18 + 0x14);
		const int dataIndex2 = *(short*)(xwaObjectStats + modelIndex * 0x18 + 0x16);

		switch (dataIndex1)
		{
		case 0:
			if ((unsigned int)dataIndex2 < this->_spacecraftList.size())
			{
				return this->_spacecraftList[dataIndex2];
			}

			break;

		case 1:
			if ((unsigned int)dataIndex2 < this->_equipmentList.size())
			{
				return this->_equipmentList[dataIndex2];
			}

			break;
		}

		return std::string();
	}

private:
	std::vector<std::string> _spacecraftList;
	std::vector<std::string> _equipmentList;
};

FlightModelsList g_flightModelsList;

#pragma pack(push, 1)

struct XwaCraft
{
	char unk000[246];
	short IsSlamEnabled;
	char unk0F8[769];
};

static_assert(sizeof(XwaCraft) == 1017, "size of XwaCraft must be 1017");

struct XwaMobileObject
{
	char Unk0000[221];
	XwaCraft* pCraft;
	char Unk00E1[4];
};

static_assert(sizeof(XwaMobileObject) == 229, "size of XwaMobileObject must be 229");

struct XwaObject
{
	char Unk0000[2];
	unsigned short ModelIndex;
	char Unk0004[31];
	XwaMobileObject* pMobileObject;
};

static_assert(sizeof(XwaObject) == 39, "size of XwaObject must be 39");

#pragma pack(pop)

int HasShipSlam(int modelIndex)
{
	const std::string shipPath = g_flightModelsList.GetLstLine(modelIndex);

	auto lines = GetFileLines(shipPath + "Slam.txt");

	if (!lines.size())
	{
		lines = GetFileLines(shipPath + ".ini", "Slam");
	}

	if (lines.size())
	{
		return GetFileKeyValueInt(lines, "HasSlam");
	}
	else
	{
		// ModelIndex_012_0_11_MissileBoat
		if (modelIndex == 0x0C)
		{
			return 1;
		}
	}

	return 0;
}

class ModelIndexSlam
{
public:
	int HasSlam(int modelIndex)
	{
		auto it = this->_slam.find(modelIndex);

		if (it != this->_slam.end())
		{
			return it->second;
		}
		else
		{
			int value = HasShipSlam(modelIndex);
			this->_slam.insert(std::make_pair(modelIndex, value));
			return value;
		}
	}

private:
	std::map<int, int> _slam;
};

ModelIndexSlam g_modelIndexSlam;

int SlamHook(int* params)
{
	params[-1] = 0x004FDBFF;

	const int playerIndex = params[76];
	const int objectIndex = params[69];

	XwaObject* XwaObjects = *(XwaObject**)0x007B33C4;
	const auto ShowMessage = (void(*)(int, int))0x00497D40;

	const unsigned short modelIndex = XwaObjects[objectIndex].ModelIndex;
	int hasSlam = modelIndex == 0 ? 0 : g_modelIndexSlam.HasSlam(modelIndex);

	XwaObjects[objectIndex].pMobileObject->pCraft->IsSlamEnabled = hasSlam == 0 ? 0 : 1;

	if (hasSlam == 0)
	{
		// MSG_NOT_EQUIPPED_SLAM
		ShowMessage(294, playerIndex);
	}
	else
	{
		// MSG_OVERDRIVE_ON
		ShowMessage(371, playerIndex);
	}

	return 0;
}
