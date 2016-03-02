/******************************************************************************
*  Project       : J1939 - PGN Specific Configuration
*  Module        : Message Configurations
*  File          : j1939_pgn_55808.h
*  Creation date :
*  Description   :Vehicle Electrical Power 1 Implementation
*  History       :
* Copyright 2010 Delphi Technologies, Inc., All rights reserved
******************************************************************************/

/*-------------------------------------------------------------------
* to avoid multiple definition if the file is included several times
*-------------------------------------------------------------------*/
#ifndef J1939_PGN_55808_DEF
#define J1939_PGN_55808_DEF

#include "j1939_pgn_config.h"
#include "j1939_bit_fields.h"

#define Command_length (4)

#define NegativeResponseServiceIdentifier           (0x7F)
#define ServiceIdNotSupported                       (0x11)
#define SubFunctionNotSupported_InvalidFormat       (0x12)
#define IncorrectMessageLength                      (0x13)
#define ConditionsNotCorrectOrRequestSequenceError  (0x22)


extern TbBOOLEAN  VbCopyAndExecuteKernelPending;

extern void J1939_RxInit_PGN_55808(J1939_Receive_Message_Control_T * rx_msg_ctrl_ptr);
extern void J1939_TxInit_PGN_55808(J1939_Transmit_Message_Control_T * tx_msg_ctrl_ptr);

#endif

/******************************************************************************
*                        REVISION HISTORY                                     *
*******************************************************************************
* Rev      Date          S/W Engineer          Description                    *
* ===     ============  ================      ====================            *
* 1        10/19/2011    Arpit, Anupindi       SOFC J1939 first release.      *
******************************************************************************/

