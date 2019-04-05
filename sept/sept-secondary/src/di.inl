/*
 * Copyright (c) 2018 naehrwert
 * Copyright (C) 2018 CTCaer
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 
//Clock config.
static const cfg_op_t _display_config_1[4] = {
    {0x4E, 0x40000000}, //CLK_RST_CONTROLLER_CLK_SOURCE_DISP1
    {0x34, 0x4830A001}, //CLK_RST_CONTROLLER_PLLD_BASE
    {0x36, 0x20},       //CLK_RST_CONTROLLER_PLLD_MISC1
    {0x37, 0x2D0AAA}    //CLK_RST_CONTROLLER_PLLD_MISC
};

//Display A config.
static const cfg_op_t _display_config_2[94] = {
    {DC_CMD_STATE_ACCESS, 0},
    {DC_CMD_STATE_CONTROL, GENERAL_UPDATE},
    {DC_CMD_STATE_CONTROL, GENERAL_ACT_REQ},
    {DC_CMD_REG_ACT_CONTROL, 0x54},
    {DC_CMD_STATE_CONTROL, GENERAL_UPDATE},
    {DC_CMD_STATE_CONTROL, GENERAL_ACT_REQ},
    {DC_CMD_DISPLAY_WINDOW_HEADER, WINDOW_A_SELECT},
    {DC_CMD_DISPLAY_WINDOW_HEADER, WINDOW_B_SELECT},
    {DC_CMD_DISPLAY_WINDOW_HEADER, WINDOW_C_SELECT},
    {DC_DISP_DC_MCCIF_FIFOCTRL, 0},
    {DC_DISP_DISP_MEM_HIGH_PRIORITY, 0},
    {DC_DISP_DISP_MEM_HIGH_PRIORITY_TIMER, 0},
    {DC_CMD_DISPLAY_POWER_CONTROL, PW0_ENABLE | PW1_ENABLE | PW2_ENABLE | PW3_ENABLE | PW4_ENABLE | PM0_ENABLE | PM1_ENABLE},
    {DC_CMD_GENERAL_INCR_SYNCPT_CNTRL, SYNCPT_CNTRL_NO_STALL},
    {DC_CMD_CONT_SYNCPT_VSYNC, SYNCPT_VSYNC_ENABLE | 0x9}, // 9: SYNCPT
    {DC_CMD_STATE_CONTROL, GENERAL_UPDATE | WIN_A_UPDATE | WIN_B_UPDATE | WIN_C_UPDATE},
    {DC_CMD_STATE_CONTROL, GENERAL_ACT_REQ | WIN_A_ACT_REQ | WIN_B_ACT_REQ | WIN_C_ACT_REQ},
    {DC_CMD_STATE_ACCESS, 0},
    {DC_CMD_DISPLAY_WINDOW_HEADER, WINDOW_A_SELECT},
    {DC_WIN_WIN_OPTIONS, 0},
    {DC_CMD_DISPLAY_WINDOW_HEADER, WINDOW_A_SELECT},
    {DC_WIN_DV_CONTROL, 0},
    {DC_WIN_WIN_OPTIONS, 0},
    {DC_CMD_DISPLAY_WINDOW_HEADER, WINDOW_A_SELECT},
    {DC_CMD_DISPLAY_WINDOW_HEADER, WINDOW_A_SELECT},
    /* Setup default YUV colorspace conversion coefficients */
    {DC_WIN_CSC_YOF,   0xF0},
    {DC_WIN_CSC_KYRGB, 0x12A},
    {DC_WIN_CSC_KUR,   0},
    {DC_WIN_CSC_KVR,   0x198},
    {DC_WIN_CSC_KUG,   0x39B},
    {DC_WIN_CSC_KVG,   0x32F},
    {DC_WIN_CSC_KUB,   0x204},
    {DC_WIN_CSC_KVB,   0},
    /* End of color coefficients */
    {DC_CMD_DISPLAY_WINDOW_HEADER, WINDOW_B_SELECT},
    {DC_WIN_WIN_OPTIONS, 0},
    {DC_CMD_DISPLAY_WINDOW_HEADER, WINDOW_B_SELECT},
    {DC_WIN_DV_CONTROL, 0},
    {DC_WIN_WIN_OPTIONS, 0},
    {DC_CMD_DISPLAY_WINDOW_HEADER, WINDOW_B_SELECT},
    {DC_CMD_DISPLAY_WINDOW_HEADER, WINDOW_B_SELECT},
    /* Setup default YUV colorspace conversion coefficients */
    {DC_WIN_CSC_YOF,   0xF0},
    {DC_WIN_CSC_KYRGB, 0x12A},
    {DC_WIN_CSC_KUR,   0},
    {DC_WIN_CSC_KVR,   0x198},
    {DC_WIN_CSC_KUG,   0x39B},
    {DC_WIN_CSC_KVG,   0x32F},
    {DC_WIN_CSC_KUB,   0x204},
    {DC_WIN_CSC_KVB,   0},
    /* End of color coefficients */
    {DC_CMD_DISPLAY_WINDOW_HEADER, WINDOW_C_SELECT},
    {DC_WIN_WIN_OPTIONS, 0},
    {DC_CMD_DISPLAY_WINDOW_HEADER, WINDOW_C_SELECT},
    {DC_WIN_DV_CONTROL, 0},
    {DC_WIN_WIN_OPTIONS, 0},
    {DC_CMD_DISPLAY_WINDOW_HEADER, WINDOW_C_SELECT},
    {DC_CMD_DISPLAY_WINDOW_HEADER, WINDOW_C_SELECT},
    /* Setup default YUV colorspace conversion coefficients */
    {DC_WIN_CSC_YOF,   0xF0},
    {DC_WIN_CSC_KYRGB, 0x12A},
    {DC_WIN_CSC_KUR,   0},
    {DC_WIN_CSC_KVR,   0x198},
    {DC_WIN_CSC_KUG,   0x39B},
    {DC_WIN_CSC_KVG,   0x32F},
    {DC_WIN_CSC_KUB,   0x204},
    {DC_WIN_CSC_KVB,   0},
    /* End of color coefficients */
    {DC_CMD_DISPLAY_WINDOW_HEADER, WINDOW_A_SELECT},
    {DC_WIN_WIN_OPTIONS, 0},
    {DC_CMD_DISPLAY_WINDOW_HEADER, WINDOW_B_SELECT},
    {DC_WIN_WIN_OPTIONS, 0},
    {DC_CMD_DISPLAY_WINDOW_HEADER, WINDOW_C_SELECT},
    {DC_WIN_WIN_OPTIONS, 0},
    {DC_DISP_DISP_COLOR_CONTROL, BASE_COLOR_SIZE_888},
    {DC_DISP_DISP_INTERFACE_CONTROL, DISP_DATA_FORMAT_DF1P1C},
    {DC_COM_PIN_OUTPUT_POLARITY(1), 0x1000000},
    {DC_COM_PIN_OUTPUT_POLARITY(3), 0},
    {0x4E4, 0},
    {DC_COM_CRC_CONTROL, 0},
    {DC_CMD_STATE_CONTROL, GENERAL_UPDATE | WIN_A_UPDATE | WIN_B_UPDATE | WIN_C_UPDATE},
    {DC_CMD_STATE_CONTROL, GENERAL_ACT_REQ | WIN_A_ACT_REQ | WIN_B_ACT_REQ | WIN_C_ACT_REQ},
    {DC_CMD_DISPLAY_WINDOW_HEADER, WINDOW_A_SELECT},
    {0x716, 0x10000FF},
    {DC_CMD_DISPLAY_WINDOW_HEADER, WINDOW_B_SELECT},
    {0x716, 0x10000FF},
    {DC_CMD_DISPLAY_WINDOW_HEADER, WINDOW_C_SELECT},
    {0x716, 0x10000FF},
    {DC_CMD_DISPLAY_COMMAND_OPTION0, 0},
    {DC_CMD_DISPLAY_WINDOW_HEADER, WINDOW_A_SELECT},
    {DC_WIN_WIN_OPTIONS, 0},
    {DC_CMD_DISPLAY_WINDOW_HEADER, WINDOW_B_SELECT},
    {DC_WIN_WIN_OPTIONS, 0},
    {DC_CMD_DISPLAY_WINDOW_HEADER, WINDOW_C_SELECT},
    {DC_WIN_WIN_OPTIONS, 0},
    {DC_DISP_DISP_WIN_OPTIONS, 0},
    {DC_CMD_DISPLAY_COMMAND, 0},
    {DC_CMD_STATE_CONTROL, GENERAL_UPDATE | WIN_A_UPDATE | WIN_B_UPDATE | WIN_C_UPDATE},
    {DC_CMD_STATE_CONTROL, GENERAL_ACT_REQ | WIN_A_ACT_REQ | WIN_B_ACT_REQ | WIN_C_ACT_REQ}
};

//DSI Init config.
static const cfg_op_t _display_config_3[60] = { 
    {DSI_WR_DATA, 0},
    {DSI_INT_ENABLE, 0},
    {DSI_INT_STATUS, 0},
    {DSI_INT_MASK, 0},
    {DSI_INIT_SEQ_DATA_0, 0},
    {DSI_INIT_SEQ_DATA_1, 0},
    {DSI_INIT_SEQ_DATA_2, 0},
    {DSI_INIT_SEQ_DATA_3, 0},
    {DSI_DCS_CMDS, 0},
    {DSI_PKT_SEQ_0_LO, 0},
    {DSI_PKT_SEQ_1_LO, 0},
    {DSI_PKT_SEQ_2_LO, 0},
    {DSI_PKT_SEQ_3_LO, 0},
    {DSI_PKT_SEQ_4_LO, 0},
    {DSI_PKT_SEQ_5_LO, 0},
    {DSI_PKT_SEQ_0_HI, 0},
    {DSI_PKT_SEQ_1_HI, 0},
    {DSI_PKT_SEQ_2_HI, 0},
    {DSI_PKT_SEQ_3_HI, 0},
    {DSI_PKT_SEQ_4_HI, 0},
    {DSI_PKT_SEQ_5_HI, 0},
    {DSI_CONTROL, 0},
    {DSI_PAD_CONTROL_CD, 0},
    {DSI_SOL_DELAY, 0x18},
    {DSI_MAX_THRESHOLD, 0x1E0},
    {DSI_TRIGGER, 0},
    {DSI_INIT_SEQ_CONTROL, 0},
    {DSI_PKT_LEN_0_1, 0},
    {DSI_PKT_LEN_2_3, 0},
    {DSI_PKT_LEN_4_5, 0},
    {DSI_PKT_LEN_6_7, 0},
    {DSI_PAD_CONTROL_1, 0},
    {DSI_PHY_TIMING_0, 0x6070601},
    {DSI_PHY_TIMING_1, 0x40A0E05},
    {DSI_PHY_TIMING_2, 0x30109},
    {DSI_BTA_TIMING, 0x190A14},
    {DSI_TIMEOUT_0, DSI_TIMEOUT_LRX(0x2000) | DSI_TIMEOUT_HTX(0xFFFF)},
    {DSI_TIMEOUT_1, DSI_TIMEOUT_PR(0x765) | DSI_TIMEOUT_TA(0x2000)},
    {DSI_TO_TALLY, 0},
    {DSI_PAD_CONTROL_0, DSI_PAD_CONTROL_VS1_PULLDN(0) | DSI_PAD_CONTROL_VS1_PDIO(0)}, // Enable
    {DSI_POWER_CONTROL, DSI_POWER_CONTROL_ENABLE},
    {DSI_POWER_CONTROL, DSI_POWER_CONTROL_ENABLE},
    {DSI_POWER_CONTROL, 0},
    {DSI_POWER_CONTROL, 0},
    {DSI_PAD_CONTROL_1, 0},
    {DSI_PHY_TIMING_0, 0x6070601},
    {DSI_PHY_TIMING_1, 0x40A0E05},
    {DSI_PHY_TIMING_2, 0x30118},
    {DSI_BTA_TIMING, 0x190A14},
    {DSI_TIMEOUT_0, DSI_TIMEOUT_LRX(0x2000) | DSI_TIMEOUT_HTX(0xFFFF)},
    {DSI_TIMEOUT_1, DSI_TIMEOUT_PR(0x1343) | DSI_TIMEOUT_TA(0x2000)},
    {DSI_TO_TALLY, 0},
    {DSI_HOST_CONTROL, DSI_HOST_CONTROL_CRC_RESET | DSI_HOST_CONTROL_TX_TRIG_HOST | DSI_HOST_CONTROL_CS | DSI_HOST_CONTROL_ECC},
    {DSI_CONTROL, DSI_CONTROL_LANES(3) | DSI_CONTROL_HOST_ENABLE},
    {DSI_POWER_CONTROL, DSI_POWER_CONTROL_ENABLE},
    {DSI_POWER_CONTROL, DSI_POWER_CONTROL_ENABLE},
    {DSI_MAX_THRESHOLD, 0x40},
    {DSI_TRIGGER, 0},
    {DSI_TX_CRC, 0},
    {DSI_INIT_SEQ_CONTROL, 0}
};

//DSI config (if ver == 0x10).
static const cfg_op_t _display_config_4[43] = {
    {DSI_WR_DATA, 0x439},
    {DSI_WR_DATA, 0x9483FFB9},
    {DSI_TRIGGER, DSI_TRIGGER_HOST},
    {DSI_WR_DATA, 0xBD15},
    {DSI_TRIGGER, DSI_TRIGGER_HOST},
    {DSI_WR_DATA, 0x1939},
    {DSI_WR_DATA, 0xAAAAAAD8},
    {DSI_WR_DATA, 0xAAAAAAEB},
    {DSI_WR_DATA, 0xAAEBAAAA},
    {DSI_WR_DATA, 0xAAAAAAAA},
    {DSI_WR_DATA, 0xAAAAAAEB},
    {DSI_WR_DATA, 0xAAEBAAAA},
    {DSI_WR_DATA, 0xAA},
    {DSI_TRIGGER, DSI_TRIGGER_HOST},
    {DSI_WR_DATA, 0x1BD15},
    {DSI_TRIGGER, DSI_TRIGGER_HOST},
    {DSI_WR_DATA, 0x2739},
    {DSI_WR_DATA, 0xFFFFFFD8},
    {DSI_WR_DATA, 0xFFFFFFFF},
    {DSI_WR_DATA, 0xFFFFFFFF},
    {DSI_WR_DATA, 0xFFFFFFFF},
    {DSI_WR_DATA, 0xFFFFFFFF},
    {DSI_WR_DATA, 0xFFFFFFFF},
    {DSI_WR_DATA, 0xFFFFFFFF},
    {DSI_WR_DATA, 0xFFFFFFFF},
    {DSI_WR_DATA, 0xFFFFFFFF},
    {DSI_WR_DATA, 0xFFFFFF},
    {DSI_TRIGGER, DSI_TRIGGER_HOST},
    {DSI_WR_DATA, 0x2BD15},
    {DSI_TRIGGER, DSI_TRIGGER_HOST},
    {DSI_WR_DATA, 0xF39},
    {DSI_WR_DATA, 0xFFFFFFD8},
    {DSI_WR_DATA, 0xFFFFFFFF},
    {DSI_WR_DATA, 0xFFFFFFFF},
    {DSI_WR_DATA, 0xFFFFFF},
    {DSI_TRIGGER, DSI_TRIGGER_HOST},
    {DSI_WR_DATA, 0xBD15},
    {DSI_TRIGGER, DSI_TRIGGER_HOST},
    {DSI_WR_DATA, 0x6D915},
    {DSI_TRIGGER, DSI_TRIGGER_HOST},
    {DSI_WR_DATA, 0x439},
    {DSI_WR_DATA, 0xB9},
    {DSI_TRIGGER, DSI_TRIGGER_HOST}
};

//DSI config.
static const cfg_op_t _display_config_5[21] = {
    {DSI_PAD_CONTROL_1, 0},
    {DSI_PHY_TIMING_0, 0x6070601},
    {DSI_PHY_TIMING_1, 0x40A0E05},
    {DSI_PHY_TIMING_2, 0x30172},
    {DSI_BTA_TIMING, 0x190A14},
    {DSI_TIMEOUT_0, DSI_TIMEOUT_LRX(0x2000) | DSI_TIMEOUT_HTX(0xA40)},
    {DSI_TIMEOUT_1, DSI_TIMEOUT_PR(0x5A2F) | DSI_TIMEOUT_TA(0x2000)},
    {DSI_TO_TALLY, 0},
    {DSI_PKT_SEQ_0_LO, 0x40000208},
    {DSI_PKT_SEQ_2_LO, 0x40000308},
    {DSI_PKT_SEQ_4_LO, 0x40000308},
    {DSI_PKT_SEQ_1_LO, 0x40000308},
    {DSI_PKT_SEQ_3_LO, 0x3F3B2B08},
    {DSI_PKT_SEQ_3_HI, 0x2CC},
    {DSI_PKT_SEQ_5_LO, 0x3F3B2B08},
    {DSI_PKT_SEQ_5_HI, 0x2CC},
    {DSI_PKT_LEN_0_1, 0xCE0000},
    {DSI_PKT_LEN_2_3, 0x87001A2},
    {DSI_PKT_LEN_4_5, 0x190},
    {DSI_PKT_LEN_6_7, 0x190},
    {DSI_HOST_CONTROL, 0},
};

//Clock config.
static const cfg_op_t _display_config_6[3] = {
    {0x34, 0x4810C001}, //CLK_RST_CONTROLLER_PLLD_BASE
    {0x36, 0x20},       //CLK_RST_CONTROLLER_PLLD_MISC1
    {0x37, 0x2DFC00}    //CLK_RST_CONTROLLER_PLLD_MISC
};

//DSI config.
static const cfg_op_t _display_config_7[10] = {
    {DSI_TRIGGER, 0},
    {DSI_CONTROL, 0},
    {DSI_SOL_DELAY, 6},
    {DSI_MAX_THRESHOLD, 0x1E0},
    {DSI_POWER_CONTROL, DSI_POWER_CONTROL_ENABLE},
    {DSI_CONTROL, DSI_CONTROL_HS_CLK_CTRL | DSI_CONTROL_FORMAT(3) | DSI_CONTROL_LANES(3) | DSI_CONTROL_VIDEO_ENABLE},
    {DSI_HOST_CONTROL, DSI_HOST_CONTROL_HS | DSI_HOST_CONTROL_FIFO_SEL| DSI_HOST_CONTROL_CS | DSI_HOST_CONTROL_ECC},
    {DSI_CONTROL, DSI_CONTROL_HS_CLK_CTRL | DSI_CONTROL_FORMAT(3) | DSI_CONTROL_LANES(3) | DSI_CONTROL_VIDEO_ENABLE},
    {DSI_HOST_CONTROL, DSI_HOST_CONTROL_CS | DSI_HOST_CONTROL_ECC},
    {DSI_HOST_CONTROL, DSI_HOST_CONTROL_HS | DSI_HOST_CONTROL_CS | DSI_HOST_CONTROL_ECC}
};

//MIPI CAL config.
static const cfg_op_t _display_config_8[6] = {
    {0x18, 0},
    {2, 0xF3F10000},
    {0x16, 1},
    {0x18, 0},
    {0x18, 0x10010},
    {0x17, 0x300}
};

//DSI config.
static const cfg_op_t _display_config_9[4] = {
    {DSI_PAD_CONTROL_1, 0},
    {DSI_PAD_CONTROL_2, 0},
    {DSI_PAD_CONTROL_3, DSI_PAD_PREEMP_PD_CLK(0x3) | DSI_PAD_PREEMP_PU_CLK(0x3) | DSI_PAD_PREEMP_PD(0x03) | DSI_PAD_PREEMP_PU(0x3)},
    {DSI_PAD_CONTROL_4, 0}
};

//MIPI CAL config.
static const cfg_op_t _display_config_10[16] = {
    {0xE, 0x200200},
    {0xF, 0x200200},
    {0x19, 0x200002},
    {0x1A, 0x200002},
    {5, 0},
    {6, 0},
    {7, 0},
    {8, 0},
    {9, 0},
    {0xA, 0},
    {0x10, 0},
    {0x11, 0},
    {0x1A, 0},
    {0x1C, 0},
    {0x1D, 0},
    {0, 0x2A000001}
};

//Display A config.
static const cfg_op_t _display_config_11[113] = {
    {DC_CMD_STATE_ACCESS, 0},
    {DC_CMD_DISPLAY_WINDOW_HEADER, WINDOW_A_SELECT},
    {DC_WIN_WIN_OPTIONS, 0},
    {DC_CMD_DISPLAY_WINDOW_HEADER, WINDOW_A_SELECT},
    {DC_WIN_DV_CONTROL, 0},
    {DC_WIN_WIN_OPTIONS, 0},
    {DC_CMD_DISPLAY_WINDOW_HEADER, WINDOW_A_SELECT},
    {DC_CMD_DISPLAY_WINDOW_HEADER, WINDOW_A_SELECT},
    /* Setup default YUV colorspace conversion coefficients */
    {DC_WIN_CSC_YOF,   0xF0},
    {DC_WIN_CSC_KYRGB, 0x12A},
    {DC_WIN_CSC_KUR,   0},
    {DC_WIN_CSC_KVR,   0x198},
    {DC_WIN_CSC_KUG,   0x39B},
    {DC_WIN_CSC_KVG,   0x32F},
    {DC_WIN_CSC_KUB,   0x204},
    {DC_WIN_CSC_KVB,   0},
    /* End of color coefficients */
    {DC_CMD_DISPLAY_WINDOW_HEADER, WINDOW_B_SELECT},
    {DC_WIN_WIN_OPTIONS, 0},
    {DC_CMD_DISPLAY_WINDOW_HEADER, WINDOW_B_SELECT},
    {DC_WIN_DV_CONTROL, 0},
    {DC_WIN_WIN_OPTIONS, 0},
    {DC_CMD_DISPLAY_WINDOW_HEADER, WINDOW_B_SELECT},
    {DC_CMD_DISPLAY_WINDOW_HEADER, WINDOW_B_SELECT},
    /* Setup default YUV colorspace conversion coefficients */
    {DC_WIN_CSC_YOF,   0xF0},
    {DC_WIN_CSC_KYRGB, 0x12A},
    {DC_WIN_CSC_KUR,   0},
    {DC_WIN_CSC_KVR,   0x198},
    {DC_WIN_CSC_KUG,   0x39B},
    {DC_WIN_CSC_KVG,   0x32F},
    {DC_WIN_CSC_KUB,   0x204},
    {DC_WIN_CSC_KVB,   0},
    /* End of color coefficients */
    {DC_CMD_DISPLAY_WINDOW_HEADER, WINDOW_C_SELECT},
    {DC_WIN_WIN_OPTIONS, 0},
    {DC_CMD_DISPLAY_WINDOW_HEADER, WINDOW_C_SELECT},
    {DC_WIN_DV_CONTROL, 0},
    {DC_WIN_WIN_OPTIONS, 0},
    {DC_CMD_DISPLAY_WINDOW_HEADER, WINDOW_C_SELECT},
    {DC_CMD_DISPLAY_WINDOW_HEADER, WINDOW_C_SELECT},
    /* Setup default YUV colorspace conversion coefficients */
    {DC_WIN_CSC_YOF,   0xF0},
    {DC_WIN_CSC_KYRGB, 0x12A},
    {DC_WIN_CSC_KUR,   0},
    {DC_WIN_CSC_KVR,   0x198},
    {DC_WIN_CSC_KUG,   0x39B},
    {DC_WIN_CSC_KVG,   0x32F},
    {DC_WIN_CSC_KUB,   0x204},
    {DC_WIN_CSC_KVB,   0},
    /* End of color coefficients */
    {DC_CMD_DISPLAY_WINDOW_HEADER, WINDOW_A_SELECT},
    {DC_WIN_WIN_OPTIONS, 0},
    {DC_CMD_DISPLAY_WINDOW_HEADER, WINDOW_B_SELECT},
    {DC_WIN_WIN_OPTIONS, 0},
    {DC_CMD_DISPLAY_WINDOW_HEADER, WINDOW_C_SELECT},
    {DC_WIN_WIN_OPTIONS, 0},
    {DC_DISP_DISP_COLOR_CONTROL, BASE_COLOR_SIZE_888},
    {DC_DISP_DISP_INTERFACE_CONTROL, DISP_DATA_FORMAT_DF1P1C},
    {DC_COM_PIN_OUTPUT_POLARITY(1), 0x1000000},
    {DC_COM_PIN_OUTPUT_POLARITY(3), 0},
    {0x4E4, 0},
    {DC_COM_CRC_CONTROL, 0},
    {DC_CMD_STATE_CONTROL, GENERAL_UPDATE | WIN_A_UPDATE | WIN_B_UPDATE | WIN_C_UPDATE},
    {DC_CMD_STATE_CONTROL, GENERAL_ACT_REQ | WIN_A_ACT_REQ | WIN_B_ACT_REQ | WIN_C_ACT_REQ},
    {DC_CMD_DISPLAY_WINDOW_HEADER, WINDOW_A_SELECT},
    {0x716, 0x10000FF},
    {DC_CMD_DISPLAY_WINDOW_HEADER, WINDOW_B_SELECT},
    {0x716, 0x10000FF},
    {DC_CMD_DISPLAY_WINDOW_HEADER, WINDOW_C_SELECT},
    {0x716, 0x10000FF},
    {DC_CMD_DISPLAY_COMMAND_OPTION0, 0},
    {DC_CMD_DISPLAY_WINDOW_HEADER, WINDOW_A_SELECT},
    {DC_WIN_WIN_OPTIONS, 0},
    {DC_CMD_DISPLAY_WINDOW_HEADER, WINDOW_B_SELECT},
    {DC_WIN_WIN_OPTIONS, 0},
    {DC_CMD_DISPLAY_WINDOW_HEADER, WINDOW_C_SELECT},
    {DC_WIN_WIN_OPTIONS, 0},
    {DC_DISP_DISP_WIN_OPTIONS, 0},
    {DC_CMD_DISPLAY_COMMAND, 0},
    {DC_CMD_STATE_CONTROL, GENERAL_UPDATE | WIN_A_UPDATE | WIN_B_UPDATE | WIN_C_UPDATE},
    {DC_CMD_STATE_CONTROL, GENERAL_ACT_REQ | WIN_A_ACT_REQ | WIN_B_ACT_REQ | WIN_C_ACT_REQ},
    {DC_CMD_STATE_ACCESS, 0},
    /* Set Display timings */
    {DC_DISP_DISP_TIMING_OPTIONS, 0},
    {DC_DISP_REF_TO_SYNC, (1 << 16)}, // h_ref_to_sync = 0, v_ref_to_sync = 1.
    {DC_DISP_SYNC_WIDTH,  0x10048},
    {DC_DISP_BACK_PORCH,  0x90048},
    {DC_DISP_ACTIVE,      0x50002D0},
    {DC_DISP_FRONT_PORCH, 0xA0088}, // Sources say that this should be above the DC_DISP_ACTIVE cmd.
    /* End of Display timings */
    {DC_DISP_SHIFT_CLOCK_OPTIONS, SC1_H_QUALIFIER_NONE | SC0_H_QUALIFIER_NONE},
    {DC_COM_PIN_OUTPUT_ENABLE(1), 0},
    {DC_DISP_DATA_ENABLE_OPTIONS, DE_SELECT_ACTIVE | DE_CONTROL_NORMAL},
    {DC_DISP_DISP_INTERFACE_CONTROL, DISP_DATA_FORMAT_DF1P1C},
    {DC_DISP_DISP_CLOCK_CONTROL, 0},
    {DC_CMD_DISPLAY_COMMAND_OPTION0, 0},
    {DC_CMD_DISPLAY_WINDOW_HEADER, WINDOW_A_SELECT},
    {DC_WIN_WIN_OPTIONS, 0},
    {DC_CMD_DISPLAY_WINDOW_HEADER, WINDOW_B_SELECT},
    {DC_WIN_WIN_OPTIONS, 0},
    {DC_CMD_DISPLAY_WINDOW_HEADER, WINDOW_C_SELECT},
    {DC_WIN_WIN_OPTIONS, 0},
    {DC_DISP_DISP_WIN_OPTIONS, 0},
    {DC_CMD_DISPLAY_COMMAND, DISP_CTRL_MODE_C_DISPLAY},
    {DC_CMD_STATE_CONTROL, GENERAL_UPDATE},
    {DC_CMD_STATE_CONTROL, GENERAL_ACT_REQ},
    {DC_CMD_STATE_ACCESS, READ_MUX | WRITE_MUX},
    {DC_DISP_FRONT_PORCH, 0xA0088},
    {DC_CMD_STATE_ACCESS, 0},
    {DC_CMD_STATE_CONTROL, GENERAL_UPDATE},
    {DC_CMD_STATE_CONTROL, GENERAL_ACT_REQ},
    {DC_CMD_GENERAL_INCR_SYNCPT, 0x301},
    {DC_CMD_GENERAL_INCR_SYNCPT, 0x301},
    {DC_CMD_STATE_CONTROL, GENERAL_UPDATE},
    {DC_CMD_STATE_CONTROL, GENERAL_ACT_REQ},
    {DC_CMD_STATE_ACCESS, 0},
    {DC_DISP_DISP_CLOCK_CONTROL, PIXEL_CLK_DIVIDER_PCD1 | SHIFT_CLK_DIVIDER(4)},
    {DC_DISP_DISP_COLOR_CONTROL, BASE_COLOR_SIZE_888},
    {DC_CMD_DISPLAY_COMMAND_OPTION0, 0}
};

////Display A config.
static const cfg_op_t _display_config_12[17] = {
    {DC_DISP_FRONT_PORCH, 0xA0088},
    {DC_CMD_INT_MASK, 0},
    {DC_CMD_STATE_ACCESS, 0},
    {DC_CMD_INT_ENABLE, 0},
    {DC_CMD_CONT_SYNCPT_VSYNC, 0},
    {DC_CMD_DISPLAY_COMMAND, 0},
    {DC_CMD_STATE_CONTROL, GENERAL_UPDATE},
    {DC_CMD_STATE_CONTROL, GENERAL_ACT_REQ},
    {DC_CMD_STATE_CONTROL, GENERAL_UPDATE},
    {DC_CMD_STATE_CONTROL, GENERAL_ACT_REQ},
    {DC_CMD_GENERAL_INCR_SYNCPT, 0x301},
    {DC_CMD_GENERAL_INCR_SYNCPT, 0x301},
    {DC_CMD_STATE_CONTROL, GENERAL_UPDATE},
    {DC_CMD_STATE_CONTROL, GENERAL_ACT_REQ},
    {DC_CMD_DISPLAY_POWER_CONTROL, 0},
    {DC_CMD_STATE_CONTROL, GENERAL_UPDATE},
    {DC_CMD_STATE_CONTROL, GENERAL_ACT_REQ},
};

//DSI config.
static const cfg_op_t _display_config_13[16] = {
    {DSI_POWER_CONTROL, 0},
    {DSI_PAD_CONTROL_1, 0},
    {DSI_PHY_TIMING_0, 0x6070601},
    {DSI_PHY_TIMING_1, 0x40A0E05},
    {DSI_PHY_TIMING_2, 0x30109},
    {DSI_BTA_TIMING, 0x190A14},
    {DSI_TIMEOUT_0, DSI_TIMEOUT_LRX(0x2000) | DSI_TIMEOUT_HTX(0xFFFF) },
    {DSI_TIMEOUT_1, DSI_TIMEOUT_PR(0x765) | DSI_TIMEOUT_TA(0x2000)},
    {DSI_TO_TALLY, 0},
    {DSI_HOST_CONTROL, DSI_HOST_CONTROL_CRC_RESET | DSI_HOST_CONTROL_TX_TRIG_HOST | DSI_HOST_CONTROL_CS | DSI_HOST_CONTROL_ECC},
    {DSI_CONTROL, DSI_CONTROL_LANES(3) | DSI_CONTROL_HOST_ENABLE},
    {DSI_POWER_CONTROL, DSI_POWER_CONTROL_ENABLE},
    {DSI_MAX_THRESHOLD, 0x40},
    {DSI_TRIGGER, 0},
    {DSI_TX_CRC, 0},
    {DSI_INIT_SEQ_CONTROL, 0}
};

//DSI config (if ver == 0x10).
static const cfg_op_t _display_config_14[22] = {
    {DSI_WR_DATA, 0x439},
    {DSI_WR_DATA, 0x9483FFB9},
    {DSI_TRIGGER, DSI_TRIGGER_HOST},
    {DSI_WR_DATA, 0x2139},
    {DSI_WR_DATA, 0x191919D5},
    {DSI_WR_DATA, 0x19191919},
    {DSI_WR_DATA, 0x19191919},
    {DSI_WR_DATA, 0x19191919},
    {DSI_WR_DATA, 0x19191919},
    {DSI_WR_DATA, 0x19191919},
    {DSI_WR_DATA, 0x19191919},
    {DSI_WR_DATA, 0x19191919},
    {DSI_WR_DATA, 0x19},
    {DSI_TRIGGER, DSI_TRIGGER_HOST},
    {DSI_WR_DATA, 0xB39},
    {DSI_WR_DATA, 0x4F0F41B1},
    {DSI_WR_DATA, 0xF179A433},
    {DSI_WR_DATA, 0x2D81},
    {DSI_TRIGGER, DSI_TRIGGER_HOST},
    {DSI_WR_DATA, 0x439},
    {DSI_WR_DATA, 0xB9},
    {DSI_TRIGGER, DSI_TRIGGER_HOST}
};

//Display A config.
static const cfg_op_t cfg_display_one_color[8] = {
    {DC_CMD_DISPLAY_WINDOW_HEADER, WINDOW_A_SELECT}, //Enable window A.
    {DC_WIN_WIN_OPTIONS, 0},
    {DC_CMD_DISPLAY_WINDOW_HEADER, WINDOW_B_SELECT}, //Enable window B.
    {DC_WIN_WIN_OPTIONS, 0},
    {DC_CMD_DISPLAY_WINDOW_HEADER, WINDOW_C_SELECT}, //Enable window C.
    {DC_WIN_WIN_OPTIONS, 0},
    {DC_DISP_DISP_WIN_OPTIONS, DSI_ENABLE}, //DSI_ENABLE
    {DC_CMD_DISPLAY_COMMAND, DISP_CTRL_MODE_C_DISPLAY} //DISPLAY_CTRL_MODE: continuous display.
};

//Display A config.
static const cfg_op_t cfg_display_framebuffer[32] = {
    {DC_CMD_DISPLAY_WINDOW_HEADER, WINDOW_C_SELECT}, //Enable window C.
    {DC_WIN_WIN_OPTIONS, 0},
    {DC_CMD_DISPLAY_WINDOW_HEADER, WINDOW_B_SELECT}, //Enable window B.
    {DC_WIN_WIN_OPTIONS, 0},
    {DC_CMD_DISPLAY_WINDOW_HEADER, WINDOW_A_SELECT}, //Enable window A.
    {DC_WIN_WIN_OPTIONS, 0},
    {DC_DISP_DISP_WIN_OPTIONS, DSI_ENABLE}, //DSI_ENABLE
    {DC_WIN_COLOR_DEPTH, WIN_COLOR_DEPTH_B8G8R8A8}, //T_A8R8G8B8 //NX Default: T_A8B8G8R8, WIN_COLOR_DEPTH_R8G8B8A8
    {DC_WIN_WIN_OPTIONS, 0},
    {DC_WIN_WIN_OPTIONS, 0},
    {DC_WIN_POSITION, 0}, //(0,0)
    {DC_WIN_H_INITIAL_DDA, 0},
    {DC_WIN_V_INITIAL_DDA, 0},
    {DC_WIN_PRESCALED_SIZE, V_PRESCALED_SIZE(1280) | H_PRESCALED_SIZE(2880)}, //Pre-scaled size: 1280x2880 bytes.
    {DC_WIN_DDA_INC, V_DDA_INC(0x1000) | H_DDA_INC(0x1000)},
    {DC_WIN_SIZE, V_SIZE(1280) | H_SIZE(720)}, //Window size: 1280 vertical lines x 720 horizontal pixels.
    {DC_WIN_LINE_STRIDE, 0x6000C00}, //768*2x768*4 (= 0x600 x 0xC00) bytes, see TRM for alignment requirements.
    {DC_WIN_BUFFER_CONTROL, 0},
    {DC_WINBUF_SURFACE_KIND, 0}, //Regular surface.
    {DC_WINBUF_START_ADDR, 0xC0000000}, //Framebuffer address.
    {DC_WINBUF_ADDR_H_OFFSET, 0},
    {DC_WINBUF_ADDR_V_OFFSET, 0},
    {DC_WIN_WIN_OPTIONS, 0},
    {DC_DISP_DISP_WIN_OPTIONS, DSI_ENABLE}, //DSI_ENABLE
    {DC_WIN_WIN_OPTIONS, 0},
    {DC_DISP_DISP_WIN_OPTIONS, DSI_ENABLE}, //DSI_ENABLE
    {DC_WIN_WIN_OPTIONS, 0},
    {DC_DISP_DISP_WIN_OPTIONS, DSI_ENABLE}, //DSI_ENABLE
    {DC_WIN_WIN_OPTIONS, WIN_ENABLE}, //Enable window AD.
    {DC_CMD_DISPLAY_COMMAND, DISP_CTRL_MODE_C_DISPLAY}, //DISPLAY_CTRL_MODE: continuous display.
    {DC_CMD_STATE_CONTROL, GENERAL_UPDATE | WIN_A_UPDATE}, //General update; window A update.
    {DC_CMD_STATE_CONTROL, GENERAL_ACT_REQ | WIN_A_ACT_REQ} //General activation request; window A activation request.
};
