
//=============================================================================
// include files
//=============================================================================
#include "io_config_stm.h"
#include "dd_stm_interface.h"
#include "dd_stm.h"
#include "dd_siu.h"
#include "dd_dma.h"

//=============================================================================
// STM_CR_INITIAL
//=============================================================================

const STM_CR_T STM_CR_INITIAL = 
{
   STM_CLOCK_PRESCALER, // Counter Prescaler.
   STM_FREEZE_DISABLE,  //freeze
   false                            //Timer Counter Enabled.
};

