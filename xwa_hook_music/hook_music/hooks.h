#pragma once
#include "hook_function.h"

#include "music.h"

static const HookFunction g_hookFunctions[] =
{
	{ 0x592C32, MusicPlayHook },
	{ 0x592E57, MusicReleaseHook },
	{ 0x592D6F, GetMusicPositionHook },
	{ 0x592DEE, MusicLockHook },
	{ 0x592D58, MusicUnlockHook },
	{ 0x53DFE1, ComInitializeHook },
	{ 0x5A8889, ComInitializeHook },
};

static const HookPatchItem g_musicFreezePatch[] =
{
	// timeSetEvent, skip loop
	{ 0x191F44, "0F84C4000000", "90E9C4000000" },
	{ 0x192015, "7504", "EB04" },

	// s_V0x07B0F04->Play
	{ 0x19201B, "6A016A006A00A1040F7B00508B0D040F7B008B11FF5230", "909090909090909090909090909090909090E8EE5E0100" },

	// s_V0x07B0F04->Release
	{ 0x192252, "C705080F7B0001000000", "E8D95C01009090909090" },

	// s_V0x07B0F04->GetCurrentPosition
	{ 0x19216A, "E8EC020000", "E8C15D0100" },

	// s_V0x07B0F04->Lock
	{ 0x1921B8, "6A0068CC0E7B0068240F7B0068F80E7B0068200F7B006800200000A114876000C1E00D508B0D040F7B00518B15040F7B008B02FF502C", "90909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090E8425D0100" },

	// s_V0x07B0F04->Unlock
	{ 0x19212C, "8B0DCC0E7B00518B15240F7B0052A1F80E7B00508B0D200F7B00518B15040F7B0052A1040F7B008B08FF514C", "909090909090909090909090909090909090909090909090909090909090909090909090909090E8D85D0100" },

	// CoInitialize
	{ 0x13D3DC, "57FF15D8925A00", "E84FAB06009090" },
	{ 0x1A7C84, "6A00FF15D8925A00", "E8A7020000909090" },
};

static const HookPatch g_patches[] =
{
	MAKE_HOOK_PATCH("To call the hook that fixes the music freeze", g_musicFreezePatch),
};