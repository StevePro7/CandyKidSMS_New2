#include "boss_object.h"
#include "..\banks\bank3.h"

// FIXED bank.
// Boss Manager.
const unsigned char *boss_object_tiles[] =
{
	boss64_00__tiles__psgcompr,
	boss64_01__tiles__psgcompr,
	boss64_02__tiles__psgcompr,
	boss64_03__tiles__psgcompr,
	boss64_04__tiles__psgcompr,
	boss64_05__tiles__psgcompr,
};

const unsigned char *boss_object_color[] =
{
	boss64_00__palette__bin,
	boss64_01__palette__bin,
	boss64_02__palette__bin,
	boss64_03__palette__bin,
	boss64_04__palette__bin,
	boss64_05__palette__bin,
};

const unsigned char boss_object_bank[] =
{
	boss64_00__tiles__psgcompr_bank,
	boss64_01__tiles__psgcompr_bank,
	boss64_02__tiles__psgcompr_bank,
	boss64_03__tiles__psgcompr_bank,
	boss64_04__tiles__psgcompr_bank,
	boss64_05__tiles__psgcompr_bank,
};