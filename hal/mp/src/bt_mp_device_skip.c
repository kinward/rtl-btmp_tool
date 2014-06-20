#include "bluetoothmp.h"
#include "bt_mp_device_skip.h"

int BTDevice_SetPacketType_NOSUPPORT(BT_DEVICE *pBtDevice,BT_PKT_TYPE PktType){return FUNCTION_NO_SUPPORT;}
int BTDevice_SetWhiteningCoeff_NOSUPPORT(BT_DEVICE *pBtDevice, uint8_t WhiteningCoeffValue){return FUNCTION_NO_SUPPORT;}
int BTDevice_SetPayloadType_NOSUPPORT(BT_DEVICE *pBtDevice,BT_PAYLOAD_TYPE PayloadType){return FUNCTION_NO_SUPPORT;}
int BTDevice_SetTxChannel_NOSUPPORT(BT_DEVICE *pBtDevice, uint8_t ChannelNumber){return FUNCTION_NO_SUPPORT;}
int BTDevice_SetRxChannel_NOSUPPORT(BT_DEVICE *pBtDevice, uint8_t ChannelNumber){return FUNCTION_NO_SUPPORT;}
int BTDevice_SetPowerGain_NOSUPPORT(BT_DEVICE *pBtDevice, uint8_t PowerGainValue){return FUNCTION_NO_SUPPORT;}
int BTDevice_SetPowerDac_NOSUPPORT(BT_DEVICE *pBtDevice, uint8_t DacValue){return FUNCTION_NO_SUPPORT;}
int BTDevice_SetTestMode_NOSUPPORT(BT_DEVICE *pBtDevice,BT_TEST_MODE TestMode){return FUNCTION_NO_SUPPORT;}
int BTDevice_SetFWPowerTrackEnable_NOSUPPORT(BT_DEVICE *pBtDevice, uint8_t FWPowerTrackEnable){return FUNCTION_NO_SUPPORT;}
int BTDevice_SetHitTarget_NOSUPPORT(BT_DEVICE *pBtDevice, uint64_t HitTarget){return FUNCTION_NO_SUPPORT;}
int BTDevice_SetHoppingMode_NOSUPPORT(BT_DEVICE *pBtDevice, BT_PKT_TYPE pktType, uint8_t bHoppingFixChannel, uint8_t Channel, uint8_t WhiteningCoeffValue){return FUNCTION_NO_SUPPORT;}
int BTDevice_SetHCIReset_NOSUPPORT(BT_DEVICE *pBtDevice,int Delay_mSec){return FUNCTION_NO_SUPPORT;}
int BTDevice_SetPowerGainIndex_NOSUPPORT(BT_DEVICE *pBtDevice,int Index){return FUNCTION_NO_SUPPORT;}
int BTDevice_GetBTClockTime_NOSUPPORT(BT_DEVICE *pBtDevice,unsigned long btClockTime){return FUNCTION_NO_SUPPORT;}

