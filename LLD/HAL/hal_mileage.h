#ifndef HAL_MILEAGE_H
#define HAL_MILEAGE_H
/* ============================================================================ *\
 * mileage.h
 * ============================================================================
 * Copyright 1999,2003 Delphi Technologies, Inc., All Rights Reserved
 * Delphi Confidential
 * ----------------------------------------------------------------------------
 * File Name:       v_vspeed.h-5:incl:2
 * Revision:        5
 * Creation date:   Monday, June 03, 2002 1:34:48 PM
 * Last changed:    %date_modified%
 * ----------------------------------------------------------------------------
 *
 * Description:
 *   This file contains mileage accumulation logic
 *
 * Tracability info
 *   SW REF 264.15X - Coding standards
 *
 * Deviations from standards
 *   None.
 *
\* ============================================================================ */


/* ============================================================================ *\
 * Standard header files.
\* ============================================================================ */
#include "io_type.h"


/* ============================================================================ *\
 * Other header files.
\* ============================================================================ */
/*  none  */


/* ============================================================================ *\
 * Exported preprocessor #define commands.
\* ============================================================================ */
/*  none  */


/* ============================================================================ *\
 * Exported type declarations.
\* ============================================================================ */
// typedef struct
// {
//    uint8_t  VssFailureProtectionAct          : 1;
//    uint8_t  CellPtrSaveActive                : 1;
//    uint8_t  MileageSaveActive                : 1;
//    uint8_t  NewEnginePowerOnMet              : 1;
//    uint8_t  RollingIdleMet                   : 1;
// } MileageFlagsType;


/* ============================================================================ *\
 * Exported variables.
\* ============================================================================ */
// extern MileageFlagsType           MileageFlags;
// extern Mileage_In_100M_L          Mileage;
// extern Mileage_In_100M_L          MileageSinceLastStore;
/* ============================================================================ *\
 * Exported Function prototypes
 * ============================================================================ */


/* ============================================================================ *\
 * FUNCTION: UpdateMileage
 * ============================================================================
 * RETURN VALUE:
 *   none
 *
 * PARAMETERS:
 *   none
 *
 * EXTERNAL REFERENCES:
 *   none
 *
 * ----------------------------------------------------------------------------
 * ABSTRACT:
 * ----------------------------------------------------------------------------
 * This function updates the mileage accumulation logic.
\* ============================================================================ */
void UpdateMileage( void );

/* ============================================================================ *\
 * FUNCTION: InitialiseMileage
 * ============================================================================
 * RETURN VALUE:
 *   none
 *
 * PARAMETERS:
 *   none
 *
 * EXTERNAL REFERENCES:
 *   none
 *
 * ----------------------------------------------------------------------------
 * ABSTRACT:
 * ----------------------------------------------------------------------------
 * This function initialises the mileage accumulation logic.
\* ============================================================================ */
void InitialiseMileage(void);

/* ============================================================================ *\
 * FUNCTION: PowerdownMileage
 * ============================================================================
 * RETURN VALUE:
 *   none
 *
 * PARAMETERS:
 *   none
 *
 * EXTERNAL REFERENCES:
 *   none
 *
 * ----------------------------------------------------------------------------
 * ABSTRACT:
 * ----------------------------------------------------------------------------
 * This function stores the mileage to EEPROM on power down.
\* ============================================================================ */
// FAR_COS void PowerdownMileage(void);

/* ============================================================================ *\
 * Exported INLINE functions and #define function-like macros.
\* ============================================================================ */

/* ============================================================================ *\
 * File revision history (top to bottom, first revision to last revision
 * ============================================================================
 *
 * Date         user id     SCR       (description on following lines)
 * ----------   -------     ---
 * 10/10/02     ndboer      -
 * + Baseline - Created from P2003AXZ02.
 *
\* ============================================================================ */
#endif /* HAL_MILEAGE_H */
