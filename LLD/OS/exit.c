
//
// other includes
//

#include "dd_swt_interface.h"
#include "io_init.h"
#include "io_config_swt.h"
#include "dd_siu_interface.h"


//=============================================================================
// exit
//=============================================================================
void exit(void)
{
    // Set the watchdog timeout to 300ms for flash erase/program
    SWT_Set_Timeout_Value(SWT_TIMEOUT_VALUE_INIT) ;
    SWT_Service_WatchDog();

    EEPROM_Backup_MFG_NVM_Block( true );
    EEPROM_Backup_Vehicle_NVRAM_Block();
    
    // only LCI will do the instrumentation operation, backup cal 
    if(CPU_LCI == CPU_Info) {
       INST_Backup_Working_Page();
    }

    //Set TOD low now since all power down processing is complete
    HAL_GPIO_SET_TODO_Enable(false);

    INTC_EXCEPTION_Halt();
    // Wait in an infinite loop for the power supply to shutdown
    do {} while (true);
}
