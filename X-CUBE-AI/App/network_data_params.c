/**
  ******************************************************************************
  * @file    network_data_params.c
  * @author  AST Embedded Analytics Research Platform
  * @date    2026-04-04T23:37:12+0200
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */

#include "network_data_params.h"


/**  Activations Section  ****************************************************/
ai_handle g_network_activations_table[1 + 2] = {
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
  AI_HANDLE_PTR(NULL),
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
};




/**  Weights Section  ********************************************************/
AI_ALIGNED(32)
const ai_u64 s_network_weights_array_u64[415] = {
  0x7d8122205b07f96cU, 0xfe0d02fc7ffde70cU, 0xbc5706592604ea0cU, 0x355227d6c41adf81U,
  0xbfdc468ff8167daU, 0xbfda47f0001ed2eU, 0x1dfff424000bf610U, 0xfc7fad2e03dfcd21U,
  0xc11efe5b518fefbU, 0x35db03f205f0de7fU, 0xf9e127578e2f4a7fU, 0x5603fc2214fefc46U,
  0xbf07273ac500157fU, 0x2f2afc6d79527081U, 0x7fdf3085400fc387U, 0x67f46c6ff2f45c4U,
  0xf8f4e6230204ff0dU, 0x7f02da81fced1e12U, 0x9020cd002f9fbcdU, 0x35f2f1faad3900f0U,
  0x4e00a0281d206f2U, 0x81facccffade0504U, 0x81eed31302f8be1aU, 0x61cc1ae781070b8aU,
  0xe90107afedd43227U, 0x1eb0000ffe7fc01U, 0x482701dcf8e2e081U, 0x4e160309ff422381U,
  0x2d013881f8ba5496U, 0x7f4f01b7b7ac0bbbU, 0x2f4fefdc82bf038U, 0x4ad73ce2f981cae0U,
  0xfef0cbfb11e9fe81U, 0x83472172da81ee4bU, 0x1fef40102f5bdU, 0x890c81fc00fee7ffU,
  0x238196d90bfef9fbU, 0x4fd7eb0bfcd67f02U, 0x181940d021a36feU, 0xf6fa960804ed0701U,
  0xb9f20206fec3U, 0xfd07fda08a03da81U, 0x53013dd3810df9b2U, 0xfdef3cf29fed1c7fU,
  0xda0303280607ea81U, 0xc34f010b7f0004feU, 0x41e1fffd28e6fd00U, 0x497f1b3ac744e9b4U,
  0xe816020f0eda7ffbU, 0x7f79d0fd02722efeU, 0xe18bc40032cc41f2U, 0x2b825a6f193424adU,
  0x7fdc0036479c0581U, 0xffed04fc621505ecU, 0x81fffc040702f702U, 0xffe5fd01f3ffU,
  0xf30ae799548100edU, 0xc381813dbbc4e89eU, 0x6f723050d31c00aU, 0xfdfd81feffc1fb03U,
  0xfffdff00c500dbfdU, 0xf81fbfffc04ed01U, 0xe5030212f4fb06eeU, 0xd2ff03eca3338101U,
  0x254157f11fd98102U, 0xfc087f312a0b0ed1U, 0x3bc2d0cc0515e6dfU, 0x23af3eeac007f21U,
  0x811b0ef624813c06U, 0x30e4cc628e05dac0U, 0xab1a2a1cfbc9aa9dU, 0x300a20e0a7f3d3dU,
  0xf9fe02e1fffe7ff8U, 0xec010d61f58101eaU, 0xed577f4cdc38fb22U, 0x88405fffa02198dU,
  0x3f5dffdf581effdU, 0xbd9905237f3b166bU, 0x5fff4bc7ffc0d73U, 0xd22905012df32af5U,
  0x81e6024a64d3c8e1U, 0xedfd120713d2f507U, 0xf01ed7f02ff81beU, 0x6fd4c2300ee08feU,
  0xafd7e4e8fefbfbeaU, 0xf60a0729acfb81faU, 0x819e7afe81b1e1e2U, 0xbe666fbcd892f50dU,
  0xfffffe730000000eU, 0xfffff68f0000013eU, 0x128fffffa8fU, 0x282fffff815U,
  0x1effffffe79U, 0x12effffffc0U, 0xfffffc5dfffffe34U, 0xfffffe12fffff9c9U,
  0xfffffa19fffffa10U, 0xfffffc7efffffec2U, 0xeffffff8aU, 0xfffffe52fffffb9aU,
  0xffffff1000000310U, 0xfffffd50fffffaa0U, 0xfffff978fffff891U, 0x323fffff813U,
  0xffffff8dfffffd52U, 0xfffffe5b00000337U, 0xfffffaee0000016eU, 0xffffff8e00000536U,
  0xfffffd0dfffffe9aU, 0xfffffa3cfffffb93U, 0xfffffef8ffffff49U, 0x133fffffcdbU,
  0xfffffc24fffffdeeU, 0xfffffa5afffffb1aU, 0xfffffd82fffffb24U, 0xfffffa6e00000229U,
  0xfffffc3c00000008U, 0xfffffae4fffffc40U, 0xfffffde2fffffe31U, 0xffffff36fffff82bU,
  0xd3afc292a7ff90bU, 0x36273bf4f86ff9U, 0x1d474bff0aff06f7U, 0x13fe00fa0eed0347U,
  0x29023d30f4513b04U, 0x2040f8ff01021e03U, 0xfe06fdeef4fee30dU, 0x7cc301f4e41c2409U,
  0x6e308e9ee13edfcU, 0xfd54be2105ede2fbU, 0xf24c0df2f438f918U, 0xfd3c1c7fb61b5a05U,
  0xfffd1704ed032704U, 0xf93b2d355f2e0532U, 0x22fbf20ff41df5e1U, 0x1a033cef1b32c602U,
  0x1fc023524010304U, 0xebd71905fcf700ffU, 0xffd3fff1168713e9U, 0xffa0b59affc4cafdU,
  0xf6080e020401f8fbU, 0xffe8c6fc8117ed8aU, 0xe20003c406ff0906U, 0xffe9c210dbf1fb00U,
  0x1cf65dfbfd311513U, 0xfc000000017f0febU, 0xfaff0641fbffede6U, 0xdfffef816fb0100U,
  0xf732ff203e130001U, 0x1600ff0400062806U, 0xff25fb010502f466U, 0x16d20231e6ffff15U,
  0xfb0712a1ecfbfc1fU, 0x1928b5241c02b114U, 0xbf3a09bc2ad6e714U, 0xb1bff83c81120316U,
  0xf6b416f1d30416e7U, 0xe0181ed3ecee1be9U, 0xcfecdf2febffe2d6U, 0x30d802e91f100cd7U,
  0xff73c84339fc103eU, 0xb3f5f4936e2304aU, 0x1d3325d9f6a72615U, 0x2781e8054de69d48U,
  0xc6e56344dd1d550dU, 0x185b01a4b6df19bfU, 0xb717ed07e1f9e9fbU, 0x210ada090c5122fcU,
  0xff00a5ebe802f0d4U, 0x260af8f7d43a0306U, 0x260a08ea2601f7U, 0xfe0e4d140b5b470aU,
  0x1981c2f5cb04f322U, 0x41c3fff6adb0d4aU, 0x1508d2a881ffefdcU, 0x64723d91b05fa04U,
  0xff12fcbcd2fec800U, 0x16fe81f3fc1e0101U, 0xb2be01eedc21fd04U, 0x1221b3b030c1dc9U,
  0x2e3b701db01feffU, 0x1f200126b0e1e0eU, 0x2b000514fd11d0efU, 0x211d940b0c1100U,
  0xf9f70213c722e4fdU, 0x1d56174301040981U, 0xc145f5f2fd1fccfaU, 0xf8e5ed33f52beb18U,
  0x161a0908daf5fec9U, 0xc4110d154fcb0f24U, 0x20f4f35a13ffe722U, 0x1611e0f1f31e07c9U,
  0x7ffd1a05fc4aef4fU, 0x1000c0000004901U, 0x1b014501eb01fcfeU, 0x790201fe16f10100U,
  0x17010068f63a0101U, 0x2700feff00011f00U, 0x6df100ea1bf611U, 0x33e001f5fb000147U,
  0x73f304e4014bef7dU, 0x5dff010001fe1309U, 0x57fc080401231608U, 0x707222f422f43200U,
  0x5b0aff7bec0cfc5eU, 0x1cfbfa3d3c28fc31U, 0x267f04fb0414faedU, 0x16ef57e91000f94dU,
  0xf3013d23000f00U, 0x8cf611fb01fd0000U, 0xe700001ecd0581U, 0xfecacabdffc9e305U,
  0xf800fd0108000628U, 0xfeaeecfebb0cd3c9U, 0xd6ff2ade01010703U, 0xd9a31f8aedf6ffU,
  0xfe02e602190416ffU, 0xcf6e90205058de2U, 0x319dc0a2b43180fU, 0x1f22dfdca2022feU,
  0xccf0e10312fdfd0eU, 0xc0f80c380c00fb1eU, 0x14021d03e118c904U, 0xee0f1d200be88102U,
  0x126edf5a80ac1ecU, 0xf51d2cfd811902ffU, 0x5260332fc0cc4dfU, 0x1081a0203b111ecU,
  0x15fbf1fed503b8e6U, 0x315090d34cb0817U, 0x1cfdcb11ebffc0ffU, 0x6f8fcdaa91807ffU,
  0x228f9ccd700be03U, 0x170d02fce7220205U, 0x61a020be735c226U, 0xff613a75023d4eb2U,
  0x3e4e3ffe605fb8dU, 0x3111a1b7ff7ed2aU, 0x2600fd08080eede1U, 0xfc0d1ddd0e090605U,
  0x6f9fad48106e505U, 0xf14c3925181b02e3U, 0x151805f7361bc011U, 0xfceced420364fe06U,
  0xd162e08dae5d0d9U, 0xfded0119469efe19U, 0x2afbbd7f0104c722U, 0x1c0cfbdff11809d4U,
  0x7ffc6d0400660063U, 0x2000d00006256ffU, 0x2401524bf301f6fbU, 0x7d0101ff0de8ff00U,
  0x161f0073f6430101U, 0x1800ff0000003001U, 0xff73e600fc10ef5fU, 0x4add00fcf500ff43U,
  0x8102b7f4fab6feb1U, 0x200eeff00a2af01U, 0xe901b2b509ff0a03U, 0x99020103d5000100U,
  0xf1c9ffa1cebf0100U, 0xd001020000ffd900U, 0x19204fefbe814c3U, 0xd12500f60500feb1U,
  0xf2e7fee3f49314e7U, 0x3e5e5de070781f1U, 0xd0dd9c120dfd0b03U, 0xe9050506df16fcf3U,
  0xde00e5ec1fa0e0ffU, 0xd0db1a0401f9f103U, 0x4e61315ffe60aeeU, 0xac1efe1a1be7f2e7U,
  0x7ffc1e05075eee5dU, 0x1010f0001045003U, 0x300046fbe902fa00U, 0x710000ff15ef0100U,
  0x23ff0160fb3b0002U, 0xf00ff0002022201U, 0x6eef00f31af616U, 0x3de001eff9000046U,
  0xd40fc2dd04c902U, 0xf90784fb0807f602U, 0xfaf2edc0c619e507U, 0x493012ea100601U,
  0xd18fe05d8001aeaU, 0x7021a2f7f0b324bU, 0x3d00d006fc2709e7U, 0x1b1b4f98e702edfbU,
  0xc37001c047bf719U, 0x23223700fb7f03U, 0x28505cf807fffef3U, 0xbff00fa01ed012fU,
  0x31fa261ef34e2302U, 0x173af20000001a02U, 0xfc0901f1e8f8fe19U, 0x6bd300efe7181b0dU,
  0x11df3ab8105e5fdU, 0x9b113cba5030202U, 0xffe1fe11fc16e6f7U, 0xffd61ad304c302acU,
  0x2040301f40296a6U, 0x10f123389011cU, 0x2101c9370500df04U, 0xef16ddd4d00e12e2U,
  0x8905f40907a50eabU, 0xfcff05fd0002abf3U, 0xf7fdb60711fc0c06U, 0x81fe0002f311feffU,
  0xf103fda915ba01fdU, 0xe2fd03fd04fee7feU, 0x8d23ff0be00ffbU, 0xba2aff1b0aff01beU,
  0xca081829002403U, 0xb5cc23c50b0b0102U, 0xf9a7030031c6deacU, 0xff89a08200e581fcU,
  0xfa02160111001245U, 0x1c7d1b7c10d05bfU, 0xacff3adffbda120aU, 0xfbcba31d9ded04ffU,
  0x2041369e1e3feU, 0x5b7dcbffc95ff01U, 0x3a200e327e71c0dU, 0xffe6dcc8fbbbd810U,
  0x70b140206000308U, 0x5c6f0dcc83ebceeU, 0xe4fe13811dfc15fbU, 0xb4e8132f17f7d002U,
  0x56fc5d02ff4c084eU, 0x2010000007f2ef9U, 0x2000394ef100f4fcU, 0x570100fd0ff9ff00U,
  0xe1800571a200000U, 0x16feff0001012dffU, 0xfe6bf0020109ef4fU, 0x3be2010bf701003eU,
  0xfdfff5a09600e0fcU, 0x5448407fffd00ffU, 0xd9f2fff3c014e00cU, 0x20c134601dd1008U,
  0xfd01fcffd601f5eaU, 0xff2a111762be1626U, 0x2302a164f202f001U, 0x6100681ce0e0affU,
  0xfc1e18e909e91007U, 0x1c17d40a1a009cd9U, 0xed41d9ff4e1ce521U, 0xf8ff1168814a1604U,
  0x12f60f040dfd05adU, 0xde14393e36dd0d40U, 0xd7fef035e819a02fU, 0xed0d1c223960a1feU,
  0xffe9fd3cfffd15ffU, 0xd4f23306090dff02U, 0xf8ef00fa238413dbU, 0x1c5e2c601d1dc02U,
  0xdd09040110fe071dU, 0xfed7c78109e683U, 0xaeff32e201d70712U, 0xfee7920ec9fd1efdU,
  0xec01adee0690f8e3U, 0x50defe9f5a8a0f5U, 0xece8a9caff021118U, 0xf8030206f8f2ffe1U,
  0x7d608ecee930201U, 0xf5f118000303d3feU, 0x4f3f2f4fbf00b81U, 0xae2500e91604faf7U,
  0xfce900fafafb0d00U, 0x1cf9d505fc0d03cdU, 0xed3afc00022e0a0aU, 0x446470bee423602U,
  0x2d0bd4030a04fde4U, 0xc5020c3251f7ef33U, 0x10011f10f40fe705U, 0x122b130d17ea81faU,
  0x1250000005dU, 0x70000014cU, 0x41c0000038eU, 0x3100000055U,
  0xffffffc5000000abU, 0x1db0000005fU, 0xfffffe87fffffeebU, 0xfffffde8fffffe7bU,
  0x113ffffffc4U, 0xffffffbc0000013dU, 0x5ffffffe80U, 0x1aaffffff74U,
  0x4510000017fU, 0x125ffffffd1U, 0x2caffffff43U, 0xffffff6f000000ccU,
  0x1d19fbfc0eb5120dU, 0xc20370fa30b180bU, 0x853a041d0bbe8115U, 0x5a9da0c1510decdU,
  0x1e19d5d3d10b11b6U, 0xd422eb16ee0c8be6U, 0x1b20a41c8c183481U, 0x953e60a15ab23eeU,
  0x97b7fbb61765f314U, 0xb9a1bca3421125b6U, 0xeb8d07c712eeed22U, 0xbcea29c281192e2fU,
  0xf1e70001d1f90e0aU, 0xcf404daebc7810bU, 0x17f405da8af2258eU, 0xe1fa0f0e119bf5e9U,
  0xb5b8a4a82c008c91U, 0x37d9f1455c81d20aU, 0x57f18cc6cf52c427U, 0x32c04c38ab1ff658U,
  0x3cffffff97U, 0x54ffffffdaU, 0x48U,
};


ai_handle g_network_weights_table[1 + 2] = {
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
  AI_HANDLE_PTR(s_network_weights_array_u64),
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
};

