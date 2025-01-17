#pragma once
#include "hook_function.h"

#include "sfoils.h"

static const HookFunction g_hookFunctions[] =
{
	{ 0x4FC470, SFoilsFilterHook },
	{ 0x403AF2, SFoilsFilterHook },
	{ 0x459522, SFoilsFilterHook },
	{ 0x508DE6, SFoilsFilterHook },
	{ 0x4016F9, SFoilsHook1 },
	{ 0x40191A, SFoilsHook2 },
	{ 0x45EECD, SFoilsHangarShuttleHook },
	{ 0x45F1C9, SFoilsHangarShuttleHook },
	{ 0x45F408, SFoilsHangarShuttleHook },
	{ 0x45F6FD, SFoilsHangarShuttleHook },
	{ 0x45F9CC, SFoilsHangarShuttleHook },
	{ 0x4AFE19, SFoilsAIOutOfHyperspace1Hook },
	{ 0x4AFE2F, SFoilsAIOutOfHyperspace2Hook },
	{ 0x4AE401, SFoilsAIIntoHyperspace1Hook },
	{ 0x4BA892, SFoilsAIHyperspaceOrderHook },
	{ 0x41C85E, InitSFoilsLandingGearsHook },
	{ 0x409693, EnterHangarHook },
	{ 0x4097F8, EnterHangarHook },
	{ 0x40991A, EnterHyperspaceHook },
	{ 0x491313, NoFireMessageHook },
	{ 0x4BE53A, AILookForParkOrderHook },
	{ 0x4B4185, AIParkManrHook },
	{ 0x4B4E94, AIParkManrFunctionHook },
	{ 0x403B52, PlaySFoilSoundHook },
	{ 0x459546, PlaySFoilSoundHook },
	{ 0x4FC4DF, PlaySFoilSoundHook },
	{ 0x508E0D, PlaySFoilSoundHook },
	{ 0x4F69CC, HangarDoorsHook },
	{ 0x45EC7E, ShuttleHatchHook },
	{ 0x45B636, PlayerCraftHatchHook },
};

static const HookPatchItem g_keysSFoilsLandingGearsPatch[] =
{
	{ 0x100E0D, "26", "10" },
};

static const HookPatchItem g_disableSFoilModelFilterPatch[] =
{
	{ 0x0FB86A, "6683F90174196683F904", "50E8B0C60A005985C990" },
	{ 0x002EEC, "6683F901740A6683F904", "50E82E501A005985C990" },
	{ 0x058917, "668B443102663D01007406663D0400", "8D0431909050E8FEF514005885C090" },
	{ 0x1081DB, "668B440102663D01007405663BC3", "03C190909050E83AFD09005885C0" },
};

static const HookPatchItem g_defineSFoilsPatch[] =
{
	{ 0x000AF3, "4883F8310F872001000033C98A8840184000", "50E827741A0083C4045F5E5D5BC390909090" },
	{ 0x000D14, "4883F8310F87B101000033D28A90C42C4000", "50E816721A0083C4048BF8E94E0100009090" },
	{ 0x000CA7, "66C70536168C000E00", "66C70536168C000200" },
};

static const HookPatchItem g_defineHangarShuttleSFoilsPatch[] =
{
	{ 0x05E2C4, "8B15C4337B00668B4C320251E88B9A0200", "6AFF5757E8539C140083C40CEB6A909090" },
	{ 0x05E5C0, "8B0DC4337B00668B44310250E88F970200", "6A005357E85799140083C40CEB5F909090" },
	{ 0x05E7FF, "8B15C4337B0033C9668B4C320251", "6A015357E81897140083C40CEB6C" },
	{ 0x05EAF4, "8B0DC4337B00668B44310250E85B920200", "6AFF5757E82394140083C40CEB69909090" },
	{ 0x05EDBF, "8B15C4337B0033C9668B4C320251E88E8F0200", "8B4424286A015057E85491140083C40CEB5A90" },
};

static const HookPatchItem g_alignCameraBridgePatch[] =
{
	{ 0x08058C, "0F85F5000000", "909090909090" },
	{ 0x08059B, "7519", "9090" },
	{ 0x080D7C, "0F85E0000000", "909090909090" },
	{ 0x080D8A, "7517", "9090" },
	{ 0x08304B, "0F85E9000000", "909090909090" },
	{ 0x083059, "7517", "9090" },
};

static const HookPatchItem g_setSFoilsHyperspacePatch[] =
{
	{ 0x0AF214, "E807B0FEFF", "E8078D0F00" },
	{ 0x0AF22A, "E81152FFFF", "E8F18C0F00" },
	{ 0x0AD7FC, "E85F52FFFF", "E81FA70F00" },
	{ 0x0B9C8D, "E85EBCFFFF", "E88EE20E00" },
};

static const HookPatchItem g_initSFoilsLandingGearsPatch[] =
{
	{ 0x01BC59, "E802C10600", "E8D2C21800" },
};

static const HookPatchItem g_enterHangarPatch[] =
{
	{ 0x008A8E, "8A8732958B00", "E89DF4190090" },
	{ 0x008BF3, "8A8732958B00", "E838F3190090" },
};

static const HookPatchItem g_enterHyperspacePatch[] =
{
	{ 0x008D15, "8A8732958B00", "E816F2190090" },
};

static const HookPatchItem g_noFireMesagePatch[] =
{
	{ 0x09070D, "8A4127668B7104", "56E81D7811005E" },
};

static const HookPatchItem g_parkPatch[] =
{
	{ 0x0BD934, "8B0DB0A17C00894147", "50E8E6A50E00589090" },
	{ 0x0B3580, "A0F7538000", "E8AB490F00" },
	{ 0x0B428F, "FEC088415D", "E88C3C0F00" },
};

static const HookPatchItem g_playSoundPatch[] =
{
	{ 0x002F4D, "E83E840300", "E8DE4F1A00" },
	{ 0x058941, "E84A2AFEFF", "E8EAF51400" },
	{ 0x0FB8DA, "E8B1FAF3FF", "E851C60A00" },
	{ 0x108208, "E88331F3FF", "E823FD0900" },
};

static const HookPatchItem g_hangarDoorsPatch[] =
{
	{ 0x0F5DC7, "E8F423F1FF", "E854210B00" },
};

static const HookPatchItem g_hatchesPatch[] =
{
	{ 0x05E079, "A1D4948B00", "E8B29E1400" },
	{ 0x05AA31, "A108BC6800", "E8FAD41400" },
};

static const HookPatch g_patches[] =
{
	MAKE_HOOK_PATCH("Keys for SFoils and LandingGears", g_keysSFoilsLandingGearsPatch),
	MAKE_HOOK_PATCH("Disable S-Foil model filter", g_disableSFoilModelFilterPatch),
	MAKE_HOOK_PATCH("To call the hook that defines S-Foils", g_defineSFoilsPatch),
	MAKE_HOOK_PATCH("To call the hook that defines hangar shuttle S-Foils", g_defineHangarShuttleSFoilsPatch),
	MAKE_HOOK_PATCH("Align the camera with the bridge", g_alignCameraBridgePatch),
	MAKE_HOOK_PATCH("To call the hook that set S-Foils for hyperspace", g_setSFoilsHyperspacePatch),
	MAKE_HOOK_PATCH("Init S-Foils and Landing Gears", g_initSFoilsLandingGearsPatch),
	MAKE_HOOK_PATCH("To call the hook that set enter hangar state", g_enterHangarPatch),
	MAKE_HOOK_PATCH("To call the hook that set enter hyperspace state", g_enterHyperspacePatch),
	MAKE_HOOK_PATCH("To call the hook that shows the no fire message", g_noFireMesagePatch),
	MAKE_HOOK_PATCH("To call the hook that set the park state", g_parkPatch),
	MAKE_HOOK_PATCH("To call the hook that play S-Foil sound", g_playSoundPatch),
	MAKE_HOOK_PATCH("To call the hook that defines hangar doors", g_hangarDoorsPatch),
	MAKE_HOOK_PATCH("To call the hook that defines the hatches", g_hatchesPatch),
};
