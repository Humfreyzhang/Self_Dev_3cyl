
#include "dd_intc.h"


void OS_RTI_1ms_INT(void);
void OS_PIT_2_10ms_INT(void);
void OS_SW_INTC_Control(void);
void SWI_Knock_INT( void );
void CRANK_Process_Crank_Event(void);
void CAN_RX_10ms_B15_INT(void);
void SPARK_Set_Next_Interrupt_EST1( void ) ;
void DSPI_B_RFDF_DMA_MAJ_INT(void);
void CAM_W_Edge_Interrupt_Handler( void );
void CAM_X_Edge_Interrupt_Handler( void );
void FI_TPU_CH26_Interrupt_Handler(void);
void FI_TPU_CH27_Interrupt_Handler(void);
void FI_TPU_CH28_Interrupt_Handler(void);
void FI_TPU_CH29_Interrupt_Handler(void);
void KNOCK_ETPU_Interrupt_Service(void);
void HAL_CAN_RX_B00_INT(void);
void HAL_CAN_TX_B01_INT(void);
void HAL_CAN_TX_B02_INT(void);
void HAL_CAN_TX_B03_INT(void);
void HAL_CAN_TX_B04_INT(void);
void HAL_CAN_TX_B05_INT(void);
void HAL_CAN_RX_B06_INT(void);
void HAL_CAN_TX_B07_INT(void);
void HAL_CAN_RX_B08_INT(void);
void HAL_CAN_RX_B09_INT(void);
void HAL_CAN_RX_B10_INT(void);
void HAL_CAN_RX_B11_INT(void);
void HAL_CAN_RX_B12_INT(void);
void HAL_CAN_RX_B13_INT(void);
void HAL_CAN_RX_B14_INT(void);
void HAL_CAN_RX_B31_16_INT(void);
void HAL_CAN_RX_B63_32_INT(void);
void  DMA_DECFIL_DRAIN_BUF_A_Transfer_Complete(void );
void IO_ETC_PWM_INT_Handler(void);
void STM0_SOH_20MS_INT(void);
void DD_SCIB_INT(void);
void Service_ECSM_Error(void);

//=============================================================================
//
// The following preprocessor definitions must reside at the top of cxio_schedule.h
// This will allow other users of this file to include only the items they are
// interrested in.
//
//=============================================================================


  #define  INTC_CHANNEL_SOFTWARE_CH0  USED_IRQ
  #define  INTC_CHANNEL_SOFTWARE_CH1  USED_IRQ
  #define  INTC_CHANNEL_SOFTWARE_CH2  UNUSED_IRQ
  #define  INTC_CHANNEL_SOFTWARE_CH3  UNUSED_IRQ
  #define  INTC_CHANNEL_SOFTWARE_CH4  UNUSED_IRQ
  #define  INTC_CHANNEL_SOFTWARE_CH5  UNUSED_IRQ
  #define  INTC_CHANNEL_SOFTWARE_CH6  UNUSED_IRQ
  #define  INTC_CHANNEL_SOFTWARE_CH7  UNUSED_IRQ
  #define  INTC_CHANNEL_SW_WATCHDOG_IR  UNUSED_IRQ
  #define   INTC_CHANNEL_ECSM_RAM_FLASH_ERROR  UNUSED_IRQ
  #define   INTC_CHANNEL_DMA_ERROR_CH31_0  UNUSED_IRQ
  #define   INTC_CHANNEL_DMA_CH0_QADC_CFIFO_0_FILL  UNUSED_IRQ
  #define   INTC_CHANNEL_DMA_CH1_QADC_RFIFO_0_DRAIN  UNUSED_IRQ
  #define   INTC_CHANNEL_DMA_CH2_QADC_CFIFO_1_FILL  UNUSED_IRQ
  #define   INTC_CHANNEL_DMA_CH3_QADC_RFIFO_1_DRAIN  UNUSED_IRQ
  #define   INTC_CHANNEL_DMA_CH4_QADC_CFIFO_2_FILL  UNUSED_IRQ
  #define   INTC_CHANNEL_DMA_CH5_QADC_RFIFO_2_DRAIN  UNUSED_IRQ
  #define  INTC_CHANNEL_DMA_CH6_QADC_CFIFO_3_FILL  UNUSED_IRQ
  #define   INTC_CHANNEL_DMA_CH7_QADC_RFIFO_3_DRAIN  UNUSED_IRQ
  #define   INTC_CHANNEL_DMA_CH8_QADC_CFIFO_4_FILL  UNUSED_IRQ
  #define   INTC_CHANNEL_DMA_CH9_QADC_RFIFO_4_DRAIN  UNUSED_IRQ
  #define   INTC_CHANNEL_DMA_CH10_QADC_CFIFO_5_FILL  UNUSED_IRQ
  #define   INTC_CHANNEL_DMA_CH11_QADC_RFIFO_5_DRAIN  UNUSED_IRQ
  #define   INTC_CHANNEL_DMA_CH12_DSPI_B_TX_FIFO_FILL  UNUSED_IRQ
  #define  INTC_CHANNEL_DMA_CH13_DSPI_B_RX_FIFO_DRAIN  USED_IRQ
  #define    INTC_CHANNEL_DMA_CH14_DSPI_C_TX_FIFO_FILL  UNUSED_IRQ
  #define    INTC_CHANNEL_DMA_CH15_DSPI_C_RX_FIFO_DRAIN  UNUSED_IRQ
  #define   INTC_CHANNEL_DMA_CH16_DEC_FILTER_FILL  UNUSED_IRQ
  #define   INTC_CHANNEL_DMA_CH17_DEC_FILTER_DRAIN  USED_IRQ
  #define   INTC_CHANNEL_DMA_CH18_SCI_A_TX  UNUSED_IRQ
  #define   INTC_CHANNEL_DMA_CH19_SCI_A_RX  UNUSED_IRQ
  #define    INTC_CHANNEL_DMA_CH20_MIOS_CH0  UNUSED_IRQ
  #define   INTC_CHANNEL_DMA_CH21_MIOS_CH1  UNUSED_IRQ
  #define   INTC_CHANNEL_DMA_CH22_MIOS_CH2  UNUSED_IRQ
  #define   INTC_CHANNEL_DMA_CH23_MIOS_CH3  UNUSED_IRQ
  #define   INTC_CHANNEL_DMA_CH24_MIOS_CH4  UNUSED_IRQ
  #define   INTC_CHANNEL_DMA_CH25_MIOS_CH8  UNUSED_IRQ
  #define   INTC_CHANNEL_DMA_CH26_MIOS_CH9  UNUSED_IRQ
  #define  INTC_CHANNEL_DMA_CH27_TPU_A_CH0  UNUSED_IRQ
  #define   INTC_CHANNEL_DMA_CH28_TPU_A_CH1  UNUSED_IRQ
  #define   INTC_CHANNEL_DMA_CH29_TPU_A_CH2  UNUSED_IRQ
  #define   INTC_CHANNEL_DMA_CH30_TPU_A_CH14  UNUSED_IRQ
  #define    INTC_CHANNEL_DMA_CH31_TPU_A_CH15  UNUSED_IRQ
  #define   INTC_CHANNEL_FMPLL_LOSS_CLOCK  UNUSED_IRQ
   #define   INTC_CHANNEL_FMPLL_LOSS_LOCK  UNUSED_IRQ
   #define   INTC_CHANNEL_SIU_OVERRUN  UNUSED_IRQ
   #define   INTC_CHANNEL_SIU_EXTERNAL_CH0  UNUSED_IRQ
   #define   INTC_CHANNEL_SIU_EXTERNAL_CH1  UNUSED_IRQ
   #define   INTC_CHANNEL_SIU_EXTERNAL_CH2  UNUSED_IRQ
   #define   INTC_CHANNEL_SIU_EXTERNAL_CH3  UNUSED_IRQ
   #define   INTC_CHANNEL_SIU_EXTERNAL_CH15_4  UNUSED_IRQ
   #define   INTC_CHANNEL_MIOS_CH0  UNUSED_IRQ
   #define   INTC_CHANNEL_MIOS_CH1  UNUSED_IRQ
  #define   INTC_CHANNEL_MIOS_CH2  UNUSED_IRQ
   #define   INTC_CHANNEL_MIOS_CH3  UNUSED_IRQ
   #define   INTC_CHANNEL_MIOS_CH4  UNUSED_IRQ
   #define   INTC_CHANNEL_MIOS_CH5  UNUSED_IRQ
   #define   INTC_CHANNEL_MIOS_CH6  UNUSED_IRQ
   #define   INTC_CHANNEL_MIOS_CH7  UNUSED_IRQ
   // #define   INTC_CHANNEL_MIOS_CH8  UNUSED_IRQ
   #define   INTC_CHANNEL_MIOS_CH8  USED_IRQ
   #define   INTC_CHANNEL_MIOS_CH9  UNUSED_IRQ
   #define   INTC_CHANNEL_MIOS_CH10  UNUSED_IRQ
   #define   INTC_CHANNEL_MIOS_CH11  UNUSED_IRQ
   #define   INTC_CHANNEL_MIOS_CH12  UNUSED_IRQ
   #define   INTC_CHANNEL_MIOS_CH13  UNUSED_IRQ
   #define   INTC_CHANNEL_MIOS_CH14  UNUSED_IRQ
   #define   INTC_CHANNEL_MIOS_CH15  UNUSED_IRQ
   #define   INTC_CHANNEL_TPU_GLOBAL_EXCEPTION  UNUSED_IRQ
   #define   INTC_CHANNEL_TPU_A_CH0  USED_IRQ //TPU0 crank
   #define   INTC_CHANNEL_TPU_A_CH1  USED_IRQ//TPU1 cam W
   #define   INTC_CHANNEL_TPU_A_CH2  UNUSED_IRQ
   #define   INTC_CHANNEL_TPU_A_CH3  UNUSED_IRQ
   #define   INTC_CHANNEL_TPU_A_CH4  UNUSED_IRQ
   #define   INTC_CHANNEL_TPU_A_CH5  UNUSED_IRQ
   #define   INTC_CHANNEL_TPU_A_CH6  UNUSED_IRQ
   #define   INTC_CHANNEL_TPU_A_CH7  UNUSED_IRQ
   #define   INTC_CHANNEL_TPU_A_CH8  UNUSED_IRQ
   #define   INTC_CHANNEL_TPU_A_CH9  UNUSED_IRQ
   #define   INTC_CHANNEL_TPU_A_CH10  UNUSED_IRQ
   #define   INTC_CHANNEL_TPU_A_CH11  UNUSED_IRQ
   #define   INTC_CHANNEL_TPU_A_CH12  UNUSED_IRQ
   #define   INTC_CHANNEL_TPU_A_CH13  UNUSED_IRQ
   #define   INTC_CHANNEL_TPU_A_CH14  UNUSED_IRQ
   #define   INTC_CHANNEL_TPU_A_CH15  UNUSED_IRQ
   #define   INTC_CHANNEL_TPU_A_CH16  USED_IRQ//TPU1 cam X
   #define   INTC_CHANNEL_TPU_A_CH17   USED_IRQ   //TPU17 Spark
   #define   INTC_CHANNEL_TPU_A_CH18  UNUSED_IRQ
   #define   INTC_CHANNEL_TPU_A_CH19  UNUSED_IRQ
   #define   INTC_CHANNEL_TPU_A_CH20  UNUSED_IRQ
   #define   INTC_CHANNEL_TPU_A_CH21  UNUSED_IRQ
   #define   INTC_CHANNEL_TPU_A_CH22  UNUSED_IRQ
   #define   INTC_CHANNEL_TPU_A_CH23  UNUSED_IRQ
   #define   INTC_CHANNEL_TPU_A_CH24  UNUSED_IRQ
   #define   INTC_CHANNEL_TPU_A_CH25  UNUSED_IRQ
   #define   INTC_CHANNEL_TPU_A_CH26  UNUSED_IRQ 
   #define   INTC_CHANNEL_TPU_A_CH27  UNUSED_IRQ 
   #define   INTC_CHANNEL_TPU_A_CH28  UNUSED_IRQ 
   #define   INTC_CHANNEL_TPU_A_CH29  UNUSED_IRQ
   #define   INTC_CHANNEL_TPU_A_CH30  USED_IRQ
   #define   INTC_CHANNEL_TPU_A_CH31  UNUSED_IRQ
   #define   INTC_CHANNEL_QADC_OVERFLOW  UNUSED_IRQ
   #define   INTC_CHANNEL_QADC_CFIFO_CH0_INCOHERENT  UNUSED_IRQ
   #define   INTC_CHANNEL_QADC_CFIFO_CH0_PAUSE  UNUSED_IRQ
   #define   INTC_CHANNEL_QADC_CFIFO_CH0_EOQ  UNUSED_IRQ
   #define   INTC_CHANNEL_QADC_CFIFO_CH0_FILL  UNUSED_IRQ
   #define   INTC_CHANNEL_QADC_RFIFO_CH0_DRAIN  UNUSED_IRQ
   #define   INTC_CHANNEL_QADC_CFIFO_CH1_INCOHERENT  UNUSED_IRQ
   #define   INTC_CHANNEL_QADC_CFIFO_CH1_PAUSE  UNUSED_IRQ
   #define   INTC_CHANNEL_QADC_CFIFO_CH1_EOQ  UNUSED_IRQ
   #define   INTC_CHANNEL_QADC_CFIFO_CH1_FILL  UNUSED_IRQ
   #define   INTC_CHANNEL_QADC_RFIFO_CH1_DRAIN  UNUSED_IRQ
   #define   INTC_CHANNEL_QADC_CFIFO_CH2_INCOHERENT  UNUSED_IRQ
   #define   INTC_CHANNEL_QADC_CFIFO_CH2_PAUSE  UNUSED_IRQ
   #define   INTC_CHANNEL_QADC_CFIFO_CH2_EOQ  UNUSED_IRQ
   #define   INTC_CHANNEL_QADC_CFIFO_CH2_FILL  UNUSED_IRQ
   #define   INTC_CHANNEL_QADC_RFIFO_CH2_DRAIN  UNUSED_IRQ
   #define   INTC_CHANNEL_QADC_CFIFO_CH3_INCOHERENT  UNUSED_IRQ
   #define   INTC_CHANNEL_QADC_CFIFO_CH3_PAUSE  UNUSED_IRQ
   #define   INTC_CHANNEL_QADC_CFIFO_CH3_EOQ  UNUSED_IRQ
   #define   INTC_CHANNEL_QADC_CFIFO_CH3_FILL  UNUSED_IRQ
   #define   INTC_CHANNEL_QADC_RFIFO_CH3_DRAIN  UNUSED_IRQ
   #define   INTC_CHANNEL_QADC_CFIFO_CH4_INCOHERENT  UNUSED_IRQ
   #define   INTC_CHANNEL_QADC_CFIFO_CH4_PAUSE  UNUSED_IRQ
   #define   INTC_CHANNEL_QADC_CFIFO_CH4_EOQ  UNUSED_IRQ
   #define   INTC_CHANNEL_QADC_CFIFO_CH4_FILL  UNUSED_IRQ
   #define   INTC_CHANNEL_QADC_RFIFO_CH4_DRAIN  UNUSED_IRQ
   #define   INTC_CHANNEL_QADC_CFIFO_CH5_INCOHERENT  UNUSED_IRQ
   #define   INTC_CHANNEL_QADC_CFIFO_CH5_PAUSE  UNUSED_IRQ
   #define   INTC_CHANNEL_QADC_CFIFO_CH5_EOQ  UNUSED_IRQ
   #define   INTC_CHANNEL_QADC_CFIFO_CH5_FILL  UNUSED_IRQ
   #define   INTC_CHANNEL_QADC_RFIFO_CH5_DRAIN  UNUSED_IRQ
   #define   INTC_CHANNEL_DSPI_B_OVERFLOW  UNUSED_IRQ
   #define   INTC_CHANNEL_DSPI_B_TFIFO_EOQ  UNUSED_IRQ
   #define   INTC_CHANNEL_DSPI_B_TFIFO_FILL  UNUSED_IRQ
   #define   INTC_CHANNEL_DSPI_B_TX_COMPLETE  UNUSED_IRQ
   #define   INTC_CHANNEL_DSPI_B_RFIFO_DRAIN  UNUSED_IRQ
   #define   INTC_CHANNEL_DSPI_C_OVERFLOW  UNUSED_IRQ
   #define   INTC_CHANNEL_DSPI_C_TFIFO_EOQ  UNUSED_IRQ
   #define   INTC_CHANNEL_DSPI_C_TFIFO_FILL  UNUSED_IRQ
   #define   INTC_CHANNEL_DSPI_C_TX_COMPLETE  UNUSED_IRQ
   #define   INTC_CHANNEL_DSPI_C_RFIFO_DRAIN  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_141  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_142  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_143  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_144  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_145  UNUSED_IRQ
   #define   INTC_CHANNEL_SCI_A  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_147  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_148  UNUSED_IRQ
   #define   INTC_CHANNEL_SCI_B  USED_IRQ
   #define   INTC_CHANNEL_RESERVED_150  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_151  UNUSED_IRQ
   #define   INTC_CHANNEL_FLEXCAN_A_BUS_OFF  UNUSED_IRQ
   #define   INTC_CHANNEL_FLEXCAN_A_ERROR  UNUSED_IRQ
   #define   INTC_CHANNEL_FLEXCAN_A_WAKEUP  UNUSED_IRQ
   #define   INTC_CHANNEL_FLEXCAN_A_BUFFER_0  USED_IRQ
   #define   INTC_CHANNEL_FLEXCAN_A_BUFFER_1  USED_IRQ
   #define   INTC_CHANNEL_FLEXCAN_A_BUFFER_2  USED_IRQ
   #define   INTC_CHANNEL_FLEXCAN_A_BUFFER_3  USED_IRQ
   #define   INTC_CHANNEL_FLEXCAN_A_BUFFER_4  USED_IRQ
   #define   INTC_CHANNEL_FLEXCAN_A_BUFFER_5  USED_IRQ
   #define   INTC_CHANNEL_FLEXCAN_A_BUFFER_6  USED_IRQ
   #define   INTC_CHANNEL_FLEXCAN_A_BUFFER_7  UNUSED_IRQ
   #define   INTC_CHANNEL_FLEXCAN_A_BUFFER_8  USED_IRQ
   #define   INTC_CHANNEL_FLEXCAN_A_BUFFER_9  USED_IRQ
   #define   INTC_CHANNEL_FLEXCAN_A_BUFFER_10  USED_IRQ
   #define   INTC_CHANNEL_FLEXCAN_A_BUFFER_11  USED_IRQ
   #define   INTC_CHANNEL_FLEXCAN_A_BUFFER_12  USED_IRQ
   #define   INTC_CHANNEL_FLEXCAN_A_BUFFER_13  USED_IRQ
   #define   INTC_CHANNEL_FLEXCAN_A_BUFFER_14  USED_IRQ
   #define   INTC_CHANNEL_FLEXCAN_A_BUFFER_15  UNUSED_IRQ
   #define   INTC_CHANNEL_FLEXCAN_A_BUFFER_31_16  USED_IRQ
   #define   INTC_CHANNEL_FLEXCAN_A_BUFFER_63_32  USED_IRQ
   #define   INTC_CHANNEL_FLEXCAN_C_BUS_OFF  UNUSED_IRQ
   #define   INTC_CHANNEL_FLEXCAN_C_ERROR  UNUSED_IRQ
   #define   INTC_CHANNEL_FLEXCAN_C_WAKEUP  UNUSED_IRQ
   #define   INTC_CHANNEL_FLEXCAN_C_BUFFER_0  UNUSED_IRQ
   #define   INTC_CHANNEL_FLEXCAN_C_BUFFER_1  UNUSED_IRQ
   #define   INTC_CHANNEL_FLEXCAN_C_BUFFER_2  UNUSED_IRQ
   #define   INTC_CHANNEL_FLEXCAN_C_BUFFER_3  UNUSED_IRQ
   #define   INTC_CHANNEL_FLEXCAN_C_BUFFER_4  UNUSED_IRQ
   #define   INTC_CHANNEL_FLEXCAN_C_BUFFER_5  UNUSED_IRQ
   #define   INTC_CHANNEL_FLEXCAN_C_BUFFER_6  UNUSED_IRQ
   #define   INTC_CHANNEL_FLEXCAN_C_BUFFER_7  UNUSED_IRQ
   #define   INTC_CHANNEL_FLEXCAN_C_BUFFER_8  UNUSED_IRQ
   #define   INTC_CHANNEL_FLEXCAN_C_BUFFER_9  UNUSED_IRQ
   #define   INTC_CHANNEL_FLEXCAN_C_BUFFER_10  UNUSED_IRQ
   #define    INTC_CHANNEL_FLEXCAN_C_BUFFER_11  UNUSED_IRQ
   #define   INTC_CHANNEL_FLEXCAN_C_BUFFER_12  UNUSED_IRQ
   #define   INTC_CHANNEL_FLEXCAN_C_BUFFER_13  UNUSED_IRQ
   #define   INTC_CHANNEL_FLEXCAN_C_BUFFER_14  UNUSED_IRQ
   #define   INTC_CHANNEL_FLEXCAN_C_BUFFER_15  UNUSED_IRQ
   #define   INTC_CHANNEL_FLEXCAN_C_BUFFER_31_16  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_193  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_194  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_195  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_196  UNUSED_IRQ
   #define   INTC_CHANNEL_DEC_FILTER_A_INPUT_FILL  UNUSED_IRQ
   #define   INTC_CHANNEL_DEC_FILTER_A_OUTPUT_DRAIN  UNUSED_IRQ
   #define   INTC_CHANNEL_DEC_FILTER_A_ERROR  UNUSED_IRQ
   #define   INTC_CHANNEL_SYSTEM_TIMER_MODULE_0  USED_IRQ
   #define   INTC_CHANNEL_SYSTEM_TIMER_MODULE_1_3  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_202  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_203  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_204  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_205  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_206  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_207  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_208  UNUSED_IRQ
   #define   INTC_CHANNEL_MIOS_CH23  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_210  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_211  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_212  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_213  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_214  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_215  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_216  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_217  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_218  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_219  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_220  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_221  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_222  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_223  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_224  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_225  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_226  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_227  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_228  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_229  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_230  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_231  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_232  USED_IRQ
   #define   INTC_CHANNEL_RESERVED_233  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_234  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_235  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_236  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_237  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_238  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_239  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_240  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_241  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_242  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_243  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_244  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_245  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_246  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_247  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_248  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_249  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_250  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_251  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_252  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_253  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_254  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_255  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_256  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_257  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_258  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_259  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_260  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_261  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_262  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_263  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_264  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_265  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_266  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_267  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_268  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_269  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_270  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_271  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_272  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_273  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_274  UNUSED_IRQ
   #define    INTC_CHANNEL_RESERVED_275  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_276  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_277  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_278  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_279  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_280  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_281  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_282  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_283  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_284  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_285  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_286  UNUSED_IRQ
   #define    INTC_CHANNEL_RESERVED_287  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_288  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_289  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_290  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_291  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_292  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_293  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_294  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_295  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_296  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_297  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_298  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_299  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_300  UNUSED_IRQ
   #define   INTC_CHANNEL_PIT_0  UNUSED_IRQ   
   #define   INTC_CHANNEL_PIT_1  UNUSED_IRQ
   #define   INTC_CHANNEL_PIT_2  USED_IRQ  // Enable PIT_2 to trigger 10ms based J1939 tasks
   #define   INTC_CHANNEL_PIT_3  UNUSED_IRQ
   #define   INTC_CHANNEL_RTI      USED_IRQ   // Enable PIT_RTI
   #define   INTC_CHANNEL_PMC  UNUSED_IRQ
   #define   INTC_CHANNEL_ECC_CORRECTION  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_308  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_309  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_310  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_311  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_312  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_313  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_314  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_315  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_316  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_317  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_318  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_319  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_320  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_321  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_322  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_323  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_324  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_325  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_326  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_327  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_328  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_329  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_330  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_331  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_332  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_333  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_334  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_335  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_336  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_337  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_338  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_339  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_340  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_341  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_342  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_343  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_344  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_345  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_346  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_347  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_348  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_349  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_350  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_351  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_352  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_353  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_354  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_355  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_356  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_357  UNUSED_IRQ
   #define   INTC_CHANNEL_STM_1  UNUSED_IRQ
   #define   INTC_CHANNEL_STM_2  UNUSED_IRQ
   #define   INTC_CHANNEL_STM_3  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_361  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_362  UNUSED_IRQ
   #define   INTC_CHANNEL_RESERVED_363  UNUSED_IRQ
   #define   NO_OF_INTC_CHANNEL 512 



#if  INTC_CHANNEL_RTI == USED_IRQ
#define INTC_CHANNEL_RTI_HANDLER      OS_RTI_1ms_INT
#define INTC_CHANNEL_RTI_PRIORITY      INTC_PRIORITY_7
#endif


#if  INTC_CHANNEL_PIT_2 == USED_IRQ
#define INTC_CHANNEL_PIT_2_HANDLER      OS_PIT_2_10ms_INT
#define INTC_CHANNEL_PIT_2_PRIORITY      INTC_PRIORITY_7
#endif

#if INTC_CHANNEL_TPU_A_CH0 == USED_IRQ
#define INTC_CHANNEL_TPU_A_CH0_HANDLER      CRANK_Process_Crank_Event
#define INTC_CHANNEL_TPU_A_CH0_PRIORITY      INTC_PRIORITY_6
#endif


#if INTC_CHANNEL_TPU_A_CH17 == USED_IRQ
#define INTC_CHANNEL_TPU_A_CH17_HANDLER      SPARK_Set_Next_Interrupt_EST1
#define INTC_CHANNEL_TPU_A_CH17_PRIORITY      INTC_PRIORITY_6
#endif

#if  INTC_CHANNEL_SOFTWARE_CH0 == USED_IRQ
#define INTC_CHANNEL_SOFTWARE_CH0_HANDLER      OS_SW_INTC_Control
#define INTC_CHANNEL_SOFTWARE_CH0_PRIORITY      INTC_PRIORITY_6
#endif

#if  INTC_CHANNEL_SOFTWARE_CH1 == USED_IRQ
#define INTC_CHANNEL_SOFTWARE_CH1_HANDLER      SWI_Knock_INT
#define INTC_CHANNEL_SOFTWARE_CH1_PRIORITY      INTC_PRIORITY_6
#endif

#if  INTC_CHANNEL_DMA_CH13_DSPI_B_RX_FIFO_DRAIN == USED_IRQ
#define INTC_CHANNEL_DMA_CH13_DSPI_B_RX_FIFO_DRAIN_HANDLER     DSPI_B_RFDF_DMA_MAJ_INT
#define INTC_CHANNEL_DMA_CH13_DSPI_B_RX_FIFO_DRAIN_PRIORITY      INTC_PRIORITY_6
#endif


#if  INTC_CHANNEL_TPU_A_CH1 == USED_IRQ
#define INTC_CHANNEL_TPU_A_CH1_HANDLER     CAM_W_Edge_Interrupt_Handler
#define INTC_CHANNEL_TPU_A_CH1_PRIORITY      INTC_PRIORITY_6
#endif


#if  INTC_CHANNEL_TPU_A_CH16 == USED_IRQ
#define INTC_CHANNEL_TPU_A_CH16_HANDLER     CAM_X_Edge_Interrupt_Handler
#define INTC_CHANNEL_TPU_A_CH16_PRIORITY      INTC_PRIORITY_6
#endif

#if  INTC_CHANNEL_TPU_A_CH30== USED_IRQ
#define INTC_CHANNEL_TPU_A_CH30_HANDLER     KNOCK_ETPU_Interrupt_Service
#define INTC_CHANNEL_TPU_A_CH30_PRIORITY      INTC_PRIORITY_6
#endif

#if  INTC_CHANNEL_FLEXCAN_A_BUFFER_0 ==  USED_IRQ
#define INTC_CHANNEL_FLEXCAN_A_BUFFER_0_HANDLER      HAL_CAN_RX_B00_INT
#define INTC_CHANNEL_FLEXCAN_A_BUFFER_0_PRIORITY      INTC_PRIORITY_6
#endif

#if  INTC_CHANNEL_FLEXCAN_A_BUFFER_1 ==  USED_IRQ
#define INTC_CHANNEL_FLEXCAN_A_BUFFER_1_HANDLER      HAL_CAN_TX_B01_INT
#define INTC_CHANNEL_FLEXCAN_A_BUFFER_1_PRIORITY      INTC_PRIORITY_6
#endif


#if  INTC_CHANNEL_FLEXCAN_A_BUFFER_2 ==  USED_IRQ
#define INTC_CHANNEL_FLEXCAN_A_BUFFER_2_HANDLER      HAL_CAN_TX_B02_INT
#define INTC_CHANNEL_FLEXCAN_A_BUFFER_2_PRIORITY      INTC_PRIORITY_6
#endif


#if  INTC_CHANNEL_FLEXCAN_A_BUFFER_3 ==  USED_IRQ
#define INTC_CHANNEL_FLEXCAN_A_BUFFER_3_HANDLER      HAL_CAN_TX_B03_INT
#define INTC_CHANNEL_FLEXCAN_A_BUFFER_3_PRIORITY      INTC_PRIORITY_6
#endif


#if  INTC_CHANNEL_FLEXCAN_A_BUFFER_4 ==  USED_IRQ
#define INTC_CHANNEL_FLEXCAN_A_BUFFER_4_HANDLER      HAL_CAN_TX_B04_INT
#define INTC_CHANNEL_FLEXCAN_A_BUFFER_4_PRIORITY      INTC_PRIORITY_6
#endif


#if  INTC_CHANNEL_FLEXCAN_A_BUFFER_5 ==  USED_IRQ
#define INTC_CHANNEL_FLEXCAN_A_BUFFER_5_HANDLER      HAL_CAN_TX_B05_INT
#define INTC_CHANNEL_FLEXCAN_A_BUFFER_5_PRIORITY      INTC_PRIORITY_6
#endif


#if  INTC_CHANNEL_FLEXCAN_A_BUFFER_6 ==  USED_IRQ
#define INTC_CHANNEL_FLEXCAN_A_BUFFER_6_HANDLER      HAL_CAN_RX_B06_INT
#define INTC_CHANNEL_FLEXCAN_A_BUFFER_6_PRIORITY      INTC_PRIORITY_6
#endif


#if  INTC_CHANNEL_FLEXCAN_A_BUFFER_7 ==  USED_IRQ
#define INTC_CHANNEL_FLEXCAN_A_BUFFER_7_HANDLER      HAL_CAN_TX_B07_INT
#define INTC_CHANNEL_FLEXCAN_A_BUFFER_7_PRIORITY      INTC_PRIORITY_6
#endif

#if  INTC_CHANNEL_FLEXCAN_A_BUFFER_8 ==  USED_IRQ
#define INTC_CHANNEL_FLEXCAN_A_BUFFER_8_HANDLER      HAL_CAN_RX_B08_INT
#define INTC_CHANNEL_FLEXCAN_A_BUFFER_8_PRIORITY      INTC_PRIORITY_6
#endif

#if  INTC_CHANNEL_FLEXCAN_A_BUFFER_9 ==  USED_IRQ
#define INTC_CHANNEL_FLEXCAN_A_BUFFER_9_HANDLER      HAL_CAN_RX_B09_INT
#define INTC_CHANNEL_FLEXCAN_A_BUFFER_9_PRIORITY      INTC_PRIORITY_6
#endif

#if  INTC_CHANNEL_FLEXCAN_A_BUFFER_10 ==  USED_IRQ
#define INTC_CHANNEL_FLEXCAN_A_BUFFER_10_HANDLER      HAL_CAN_RX_B10_INT
#define INTC_CHANNEL_FLEXCAN_A_BUFFER_10_PRIORITY      INTC_PRIORITY_6
#endif

#if  INTC_CHANNEL_FLEXCAN_A_BUFFER_11 ==  USED_IRQ
#define INTC_CHANNEL_FLEXCAN_A_BUFFER_11_HANDLER      HAL_CAN_RX_B11_INT
#define INTC_CHANNEL_FLEXCAN_A_BUFFER_11_PRIORITY      INTC_PRIORITY_6
#endif

#if  INTC_CHANNEL_FLEXCAN_A_BUFFER_12 ==  USED_IRQ
#define INTC_CHANNEL_FLEXCAN_A_BUFFER_12_HANDLER      HAL_CAN_RX_B12_INT
#define INTC_CHANNEL_FLEXCAN_A_BUFFER_12_PRIORITY      INTC_PRIORITY_6
#endif

#if  INTC_CHANNEL_FLEXCAN_A_BUFFER_13 ==  USED_IRQ
#define INTC_CHANNEL_FLEXCAN_A_BUFFER_13_HANDLER      HAL_CAN_RX_B13_INT
#define INTC_CHANNEL_FLEXCAN_A_BUFFER_13_PRIORITY      INTC_PRIORITY_6
#endif

#if  INTC_CHANNEL_FLEXCAN_A_BUFFER_14 ==  USED_IRQ
#define INTC_CHANNEL_FLEXCAN_A_BUFFER_14_HANDLER      HAL_CAN_RX_B14_INT
#define INTC_CHANNEL_FLEXCAN_A_BUFFER_14_PRIORITY      INTC_PRIORITY_6
#endif

#if  INTC_CHANNEL_FLEXCAN_A_BUFFER_31_16 ==  USED_IRQ
#define INTC_CHANNEL_FLEXCAN_A_BUFFER_31_16_HANDLER      HAL_CAN_RX_B31_16_INT
#define INTC_CHANNEL_FLEXCAN_A_BUFFER_31_16_PRIORITY      INTC_PRIORITY_6
#endif

#if  INTC_CHANNEL_FLEXCAN_A_BUFFER_63_32 ==  USED_IRQ
#define INTC_CHANNEL_FLEXCAN_A_BUFFER_63_32_HANDLER      HAL_CAN_RX_B63_32_INT
#define INTC_CHANNEL_FLEXCAN_A_BUFFER_63_32_PRIORITY      INTC_PRIORITY_6
#endif

#if  INTC_CHANNEL_DMA_CH17_DEC_FILTER_DRAIN ==  USED_IRQ
#define INTC_CHANNEL_DMA_CH17_DEC_FILTER_DRAIN_HANDLER      DMA_DECFIL_DRAIN_BUF_A_Transfer_Complete
#define INTC_CHANNEL_DMA_CH17_DEC_FILTER_DRAIN_PRIORITY      INTC_PRIORITY_6
#endif

//special for LCI Andorra use
#if  INTC_CHANNEL_RESERVED_232 ==  USED_IRQ
#define INTC_CHANNEL_RESERVED_232_HANDLER      DMA_DECFIL_DRAIN_BUF_A_Transfer_Complete
#define INTC_CHANNEL_RESERVED_232_PRIORITY      INTC_PRIORITY_6
#endif

#if  INTC_CHANNEL_MIOS_CH8 == USED_IRQ
#define INTC_CHANNEL_MIOS_CH8_HANDLER      IO_ETC_PWM_INT_Handler
#define INTC_CHANNEL_MIOS_CH8_PRIORITY     INTC_PRIORITY_6
#endif

#if  INTC_CHANNEL_SYSTEM_TIMER_MODULE_0 ==  USED_IRQ
#define INTC_CHANNEL_SYSTEM_TIMER_MODULE_0_HANDLER      STM0_SOH_20MS_INT
#define INTC_CHANNEL_SYSTEM_TIMER_MODULE_0_PRIORITY      INTC_PRIORITY_7
#endif

#if INTC_CHANNEL_SCI_B  == USED_IRQ
#define INTC_CHANNEL_SCI_B_HANDLER                     DD_SCIB_INT
#define INTC_CHANNEL_SCI_B_PRIORITY                    INTC_PRIORITY_5
#endif

#if INTC_CHANNEL_ECSM_RAM_FLASH_ERROR  == USED_IRQ
#define INTC_CHANNEL_ECSM_RAM_FLASH_ERROR_HANDLER                     Service_ECSM_Error
#define INTC_CHANNEL_ECSM_RAM_FLASH_ERROR_PRIORITY                    INTC_PRIORITY_5
#endif

