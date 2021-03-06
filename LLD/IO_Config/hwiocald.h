#ifndef HWIOCALD_H
#define HWIOCALD_H


//=============================================================================
// include files
//=============================================================================
#include "hal.h"
#include "t_gentypes.h"
#include "timepcvc.h"
#include "v_power.h"
#include "lux_type.h"
#include "j1939_cald.h"

//=============================================================================
// type define
//=============================================================================


//=============================================================================
// extern variables
//=============================================================================
//crank
extern const uint8_t                KyHWIO_ToothOfFirstLoResEvent;
extern const uint8_t                KyHWIO_ToothOfCAMRefEvent;
extern const T_CRANK_ANGLE          KyHWIO_phi_ToothAngleForCamRead;
extern const uint8_t                KyHWIO_CrankSyncStartTooth;
extern const uint8_t                KyHWIO_Num_58X_Teeth_Before_Sync;
extern const bool                   KeHWIO_Cam1OccurredTrue;
extern const bool                   KeHWIO_Cam2OccurredTrue;
extern const uint8_t                KyHWIO_Num58xGapsBeforeSeqn;
extern const T_CRANK_ANGLE          KfHWIO_phi_TopDeadCenter;
extern const uint8_t                KyHWIO_NumberOfCylinders;
extern const uint8_t                KyHWIO_NumValidPeriodsBeforeSyncStart;
extern const bool                   KbHWIO_Fast_Sync_Enable;
extern const uint8_t                KyHWIO_NumValidPeriodsBeforeFastSyncStart;
extern const uint8_t                KyHWIO_Num58xGapsUsingCamForSync;
//fast startup
extern const uint8_t                KyHWIO_NumDeltaToothUsingFastStartUp;
//crank limp home mode         
extern const T_COUNT_BYTE           KyHWIO_Number_Of_CAM_Pulses;
extern const T_COUNT_BYTE           KyHWIO_Crank_Angle_Per_CAM_Pulse[];
extern const T_COUNT_BYTE           KyHWIO_CAM_Pulse_Duty_Min[];
extern const T_COUNT_BYTE           KyHWIO_CAM_Pulse_Duty_Max[];
extern const T_CRANK_ANGLE          KyHWIO_Delta_Angle_From_Edge_To_Tooth_1;
extern const T_RPMa                 KfVIOS_n_BackupModeEventScheduleThrsh;

extern const bool                   KbHWIO_MoreOrLess_Logic_Enable;
extern const uint16_t               KyHWIO_MaxErrorTeethMore;
extern const uint16_t               KyHWIO_MaxErrorTeethLess;

//pfi
extern const T_CRANK_ANGLE          KfHWIO_phi_BoundaryFraction;

//knock
extern const T_COUNT_BYTE           KyHWIO_Knock_Preshift;
extern const uint32_t               DSP_LOW_PASS_FILTER_IIR_COEFF[] ;
extern const uint32_t               DSP_KNOCK_CENTER_FREQUENCY_IIR_COEFF1[];
extern  const uint32_t              DSP_KNOCK_CENTER_FREQUENCY_IIR_COEFF2[];
extern  const uint32_t              DSP_KNOCK_CENTER_FREQUENCY_IIR_COEFF3[];

//spark
extern const T_MILLISECONDSb        KfSPRK_t_DwellInit;
extern const T_MILLISECONDSb        KfSPRK_t_CrankMinDwellInit ;
extern const T_MILLISECONDSb        KfSPRK_t_CrankMaxDwellInit ;

//DI high active or not
extern const   bool                 KbHWIO_ELOAD1_Active_High;
extern const   bool                 KbHWIO_ELOAD2_Active_High;
extern const   bool                 KbHWIO_BRKLMP_Active_High;
extern const   bool                 KbHWIO_EnableLogMaxHWWDTime;

extern const   bool                 K_MainPowerRelayPresent;

extern const T_DEG_Ca               KfVIOS_T_RunCoolHi;
extern const T_DEG_Ca               KfVIOS_T_RunCoolLo;
extern const T_COUNT_BYTE           KcVIOS_RunRefCold;
extern const T_COUNT_BYTE           KcVIOS_RunRefWarm;
extern const T_COUNT_BYTE           KcVIOS_RunRefHot;
extern const T_RPMa                 KfVIOS_n_CrankToRunThrsh;
extern const T_RPMa                 KfVIOS_n_RunToCrankThrsh;
extern const TwTIME_t_R7p8125ms     KfVIOS_t_PowerdownDelayTime;

extern const PowerSource_FPR_Type   K_PowerConfig_FPR;
extern const PowerSourceType        K_PowerConfig_CCP;
extern const PowerSourceType        K_PowerConfig_FANA;
extern const PowerSourceType        K_PowerConfig_FANB;
extern const PowerSourceType        K_PowerConfig_ACClutch;
extern const PowerSourceType        K_PowerConfig_SparkCoil;
extern const PowerSourceType        K_PowerConfig_O2Heater;
extern const PowerSourceType        K_PowerConfig_Injector;
extern const PowerSourceType        K_PowerConfig_ETC;

extern const Volts_Plus_Fraction    K_VOLT_KeyOnThreshold;
extern const Volts_Plus_Fraction    K_VOLT_KeyoffThreshold;
extern const TwTIME_t_R7p8125ms     K_VAL_tFuelInjAdjust;
extern const TwTIME_t_R7p8125ms     K_VAL_tFuelPumpAdjust;
extern const TwTIME_t_R7p8125ms     K_VAL_tFuelPumpPreWork;
extern const bool                   KbCAN_CHERY_Fuel_Adjust_Enable;

extern const bool                   KbVIOS_O2APumpingCurrentEnabled;
extern const bool                   KbVIOS_O2BPumpingCurrentEnabled;

extern const bool                   KbHWIO_EraseMFGafterMFGCorrupted;

extern const uint16_t               KwFILE_COND_ROM_CalbrtnChecksum;
extern const T_COUNT_BYTE           KySYST_BrainDeadBOOT_RecovEnbld;
//J1939
extern const uint8_t             KfHWIO_J193973_SA; 
#endif
