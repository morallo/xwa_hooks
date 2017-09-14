#pragma once
#include "hook_function.h"

#include "d3dinfos.h"

static const HookFunction g_hookFunctions[] =
{
	{ 0x441755, InitD3DInfosHook },
};

static const HookPatchItem g_removeD3DInfosCountLimitPatch[] =
{
	{ 0x040B50, "5657BAC3296600", "E8CB731600C390" },
};

static const HookPatch g_patches[] =
{
	MAKE_HOOK_PATCH("To call the hook that removes D3DInfos count limit", g_removeD3DInfosCountLimitPatch),
};
