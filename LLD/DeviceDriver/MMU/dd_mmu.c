
#include "dd_mmu.h"
#include "hw_sprs_cu.h"
#include "io_config_mmu.h"
#include "dd_siu_hwinfo.h"

//=============================================================================
// MMU_MAS_Initialize_Device
//=============================================================================
void MMU_MAS_Initialize_Device( void )
{
 
   STORE_SPR_VALUE_VAR(SPR_PID0,    MMU_PID_INIT);
   STORE_SPR_VALUE_VAR(SPR_MMUCSR0, MMU_CSR0_INIT);
 	
   STORE_SPR_VALUE_VAR(MMU_MAS4_SPR, MMU_MAS_4_INITIAL.U32);
   STORE_SPR_VALUE_VAR(MMU_MAS6_SPR, MMU_MAS_6_INITIAL.U32);

  //MMU_TLB_ENTRY_0	

        STORE_SPR_VALUE_VAR(MMU_MAS0_SPR, MMU_MAS_0_FLASH_PML_BOOT_64K.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS1_SPR, MMU_MAS_1_FLASH_PML_BOOT_64K.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS2_SPR, MMU_MAS_2_FLASH_PML_BOOT_64K.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS3_SPR, MMU_MAS_3_FLASH_PML_BOOT_64K.U32);
        TLBWE();

  //MMU_TLB_ENTRY_1

        STORE_SPR_VALUE_VAR(MMU_MAS0_SPR, MMU_MAS_0_INTERNAL_RAM.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS1_SPR, MMU_MAS_1_INTERNAL_RAM.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS2_SPR, MMU_MAS_2_INTERNAL_RAM.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS3_SPR, MMU_MAS_3_INTERNAL_RAM.U32);
        TLBWE();

//MMU_TLB_ENTRY_2

        STORE_SPR_VALUE_VAR(MMU_MAS0_SPR, MMU_MAS_0_MMR_REGISTER_0.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS1_SPR, MMU_MAS_1_MMR_REGISTER_0.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS2_SPR, MMU_MAS_2_MMR_REGISTER_0.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS3_SPR, MMU_MAS_3_MMR_REGISTER_0.U32);
        TLBWE();

//MMU_TLB_ENTRY_3

        STORE_SPR_VALUE_VAR(MMU_MAS0_SPR, MMU_MAS_0_MMR_REGISTER_1.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS1_SPR, MMU_MAS_1_MMR_REGISTER_1.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS2_SPR, MMU_MAS_2_MMR_REGISTER_1.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS3_SPR, MMU_MAS_3_MMR_REGISTER_1.U32);
        TLBWE();
  
//MMU_TLB_ENTRY_4

        STORE_SPR_VALUE_VAR(MMU_MAS0_SPR, MMU_MAS_0_FLASH_CODE_1_256K.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS1_SPR, MMU_MAS_1_FLASH_CODE_1_256K.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS2_SPR, MMU_MAS_2_FLASH_CODE_1_256K.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS3_SPR, MMU_MAS_3_FLASH_CODE_1_256K.U32);
        TLBWE();

//MMU_TLB_ENTRY_5

        STORE_SPR_VALUE_VAR(MMU_MAS0_SPR, MMU_MAS_0_FLASH_CODE_2_256K.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS1_SPR, MMU_MAS_1_FLASH_CODE_2_256K.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS2_SPR, MMU_MAS_2_FLASH_CODE_2_256K.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS3_SPR, MMU_MAS_3_FLASH_CODE_2_256K.U32);
        TLBWE();

//MMU_TLB_ENTRY_6

        STORE_SPR_VALUE_VAR(MMU_MAS0_SPR, MMU_MAS_0_FLASH_CODE_3_256K.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS1_SPR, MMU_MAS_1_FLASH_CODE_3_256K.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS2_SPR, MMU_MAS_2_FLASH_CODE_3_256K.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS3_SPR, MMU_MAS_3_FLASH_CODE_3_256K.U32);
        TLBWE();

//MMU_TLB_ENTRY_7

        STORE_SPR_VALUE_VAR(MMU_MAS0_SPR, MMU_MAS_0_FLASH_CODE_4_1M.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS1_SPR, MMU_MAS_1_FLASH_CODE_4_1M.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS2_SPR, MMU_MAS_2_FLASH_CODE_4_1M.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS3_SPR, MMU_MAS_3_FLASH_CODE_4_1M.U32);
        TLBWE();

//MMU_TLB_ENTRY_8

        STORE_SPR_VALUE_VAR(MMU_MAS0_SPR, MMU_MAS_0_FLASH_EEPROM_64K.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS1_SPR, MMU_MAS_1_FLASH_EEPROM_64K.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS2_SPR, MMU_MAS_2_FLASH_EEPROM_64K.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS3_SPR, MMU_MAS_3_FLASH_EEPROM_64K.U32);
        TLBWE();

//MMU_TLB_ENTRY_9


//MMU_TLB_ENTRY_10


if (CPU_Info == CPU_LCI)
 {
// Working Page - LCI Below
//MMU_TLB_ENTRY_11	
        STORE_SPR_VALUE_VAR(MMU_MAS0_SPR, MMU_MAS_0_FLASH_CAL_1_WORKING_PAGE_64K.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS1_SPR, MMU_MAS_1_FLASH_CAL_1_WORKING_PAGE_64K.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS2_SPR, MMU_MAS_2_FLASH_CAL_1_WORKING_PAGE_64K.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS3_SPR, MMU_MAS_3_FLASH_CAL_1_WORKING_PAGE_64K.U32);
        TLBWE();
// Working Page - LCI Below
//MMU_TLB_ENTRY_12	
        STORE_SPR_VALUE_VAR(MMU_MAS0_SPR, MMU_MAS_0_FLASH_CAL_2_WORKING_PAGE_64K.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS1_SPR, MMU_MAS_1_FLASH_CAL_2_WORKING_PAGE_64K.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS2_SPR, MMU_MAS_2_FLASH_CAL_2_WORKING_PAGE_64K.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS3_SPR, MMU_MAS_3_FLASH_CAL_2_WORKING_PAGE_64K.U32);
        TLBWE();
 }
 else if (CPU_Info == CPU_VERTICAL)
 {
// Working Page - VertiCAL Below
//MMU_TLB_ENTRY_11	
        STORE_SPR_VALUE_VAR(MMU_MAS0_SPR, MMU_MAS_0_FLASH_CAL_1_WORKING_PAGE_VERTICAL_64K.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS1_SPR, MMU_MAS_1_FLASH_CAL_1_WORKING_PAGE_VERTICAL_64K.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS2_SPR, MMU_MAS_2_FLASH_CAL_1_WORKING_PAGE_VERTICAL_64K.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS3_SPR, MMU_MAS_3_FLASH_CAL_1_WORKING_PAGE_VERTICAL_64K.U32);
        TLBWE();
// Working Page - VertiCAL Below
//MMU_TLB_ENTRY_12	
        STORE_SPR_VALUE_VAR(MMU_MAS0_SPR, MMU_MAS_0_FLASH_CAL_2_WORKING_PAGE_VERTICAL_64K.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS1_SPR, MMU_MAS_1_FLASH_CAL_2_WORKING_PAGE_VERTICAL_64K.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS2_SPR, MMU_MAS_2_FLASH_CAL_2_WORKING_PAGE_VERTICAL_64K.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS3_SPR, MMU_MAS_3_FLASH_CAL_2_WORKING_PAGE_VERTICAL_64K.U32);
        TLBWE();
 }
 else //CPU_Info == CPU_PROD
 {
 //Reference Page below
//MMU_TLB_ENTRY_11	

        STORE_SPR_VALUE_VAR(MMU_MAS0_SPR, MMU_MAS_0_FLASH_CAL_1_64K.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS1_SPR, MMU_MAS_1_FLASH_CAL_1_64K.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS2_SPR, MMU_MAS_2_FLASH_CAL_1_64K.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS3_SPR, MMU_MAS_3_FLASH_CAL_1_64K.U32);
        TLBWE();

//Reference Page below
//MMU_TLB_ENTRY_12	

        STORE_SPR_VALUE_VAR(MMU_MAS0_SPR, MMU_MAS_0_FLASH_CAL_2_64K.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS1_SPR, MMU_MAS_1_FLASH_CAL_2_64K.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS2_SPR, MMU_MAS_2_FLASH_CAL_2_64K.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS3_SPR, MMU_MAS_3_FLASH_CAL_2_64K.U32);
        TLBWE();

 }

//MMU_TLB_ENTRY_13	

        STORE_SPR_VALUE_VAR(MMU_MAS0_SPR, MMU_MAS_0_TLB_ENTRY_13.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS1_SPR, MMU_MAS_1_TLB_ENTRY_13.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS2_SPR, MMU_MAS_2_TLB_ENTRY_13.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS3_SPR, MMU_MAS_3_TLB_ENTRY_13.U32);
        TLBWE();

//MMU_TLB_ENTRY_14	

        STORE_SPR_VALUE_VAR(MMU_MAS0_SPR, MMU_MAS_0_TLB_ENTRY_14.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS1_SPR, MMU_MAS_1_TLB_ENTRY_14.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS2_SPR, MMU_MAS_2_TLB_ENTRY_14.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS3_SPR, MMU_MAS_3_TLB_ENTRY_14.U32);
        TLBWE();

//LCI only
//MMU_TLB_ENTRY_15	
 if (CPU_Info == CPU_LCI)
 {
        STORE_SPR_VALUE_VAR(MMU_MAS0_SPR, MMU_MAS_0_FLASH_CAL_WORKING_PAGE_BACKUP_128K.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS1_SPR, MMU_MAS_1_FLASH_CAL_WORKING_PAGE_BACKUP_128K.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS2_SPR, MMU_MAS_2_FLASH_CAL_WORKING_PAGE_BACKUP_128K.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS3_SPR, MMU_MAS_3_FLASH_CAL_WORKING_PAGE_BACKUP_128K.U32);
        TLBWE();
  }
  else if (CPU_Info == CPU_VERTICAL)
 {
//VertiCAL only
//MMU_TLB_ENTRY_15	

        STORE_SPR_VALUE_VAR(MMU_MAS0_SPR, MMU_MAS_0_EXTERNAL_RAM_128K.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS1_SPR, MMU_MAS_1_EXTERNAL_RAM_128K.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS2_SPR, MMU_MAS_2_EXTERNAL_RAM_128K.U32);
        STORE_SPR_VALUE_VAR(MMU_MAS3_SPR, MMU_MAS_3_EXTERNAL_RAM_128K.U32);
        TLBWE();
  }
  else
 {
  //do nothing
  }
   
}

