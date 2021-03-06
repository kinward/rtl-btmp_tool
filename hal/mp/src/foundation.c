#define LOG_TAG "foundation"

#include "foundation.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

void
BuildVendorInterface(
	BASE_INTERFACE_MODULE **ppBaseInterface,
	BASE_INTERFACE_MODULE *pBaseInterfaceModuleMemory,

	//Parmater
	unsigned int InterfaceType,
	unsigned char	PortNo,
	unsigned long Baudrate,
	unsigned char *pData,
	//basic fuction
	BASE_FP_OPEN Open,
	BASE_FP_SEND Send,
	BASE_FP_RECV Recv,
	BASE_FP_CLOSE Close,
	BASE_FP_WAIT_MS WaitMs
	)
{
	// Set base interface module pointer.
	int i=0;
	*ppBaseInterface = pBaseInterfaceModuleMemory;

	(*ppBaseInterface)->InterfaceType = InterfaceType;
	(*ppBaseInterface)->PortNo = PortNo;
    (*ppBaseInterface)->Baudrate = Baudrate;

	if (pData != NULL)
	{
		for( i = 0 ; i < MAX_IP_ADDR_LEN; i++)
		{
			(*ppBaseInterface)->pData[i] = pData[i];
		}
	}
	// Set all base interface function pointers and arguments.
	(*ppBaseInterface)->Open = Open;
	(*ppBaseInterface)->Send = Send;
	(*ppBaseInterface)->Recv = Recv;
	(*ppBaseInterface)->WaitMs = WaitMs;
	(*ppBaseInterface)->Close = Close;

	(*ppBaseInterface)->SetUserDefinedDataPointer = base_interface_SetUserDefinedDataPointer;
	(*ppBaseInterface)->GetUserDefinedDataPointer = base_interface_GetUserDefinedDataPointer;

	return;
}

// Base uart interface builder
void
BuildTransportInterface(
        BASE_INTERFACE_MODULE *pBaseInterfaceModule,
        unsigned char PortNo,
        unsigned long Baudrate,
        BASE_FP_OPEN Open,
        BASE_FP_SEND Send,
        BASE_FP_RECV Recv,
        BASE_FP_CLOSE Close,
        BASE_FP_WAIT_MS WaitMs
        )
{
    pBaseInterfaceModule->InterfaceType = TYPE_USB;
    pBaseInterfaceModule->PortNo = PortNo;
    pBaseInterfaceModule->Baudrate = Baudrate;

    // Set all base interface function pointers and arguments.
    pBaseInterfaceModule->Open = Open;
    pBaseInterfaceModule->Send = Send;
    pBaseInterfaceModule->Recv = Recv;
    pBaseInterfaceModule->WaitMs = WaitMs;
    pBaseInterfaceModule->Close = Close;

    pBaseInterfaceModule->SetUserDefinedDataPointer = base_interface_SetUserDefinedDataPointer;
    pBaseInterfaceModule->GetUserDefinedDataPointer = base_interface_GetUserDefinedDataPointer;

    return;
}

void
base_interface_SetUserDefinedDataPointer(
        BASE_INTERFACE_MODULE *pBaseInterface,
        int UserDefinedData
        )
{
    // Set user defined data pointer of base interface structure with user defined data pointer argument.
    pBaseInterface->UserDefinedData = UserDefinedData;


    return;
}





void
base_interface_GetUserDefinedDataPointer(
        BASE_INTERFACE_MODULE *pBaseInterface,
        int *pUserDefinedData
        )
{
    // Get user defined data pointer from base interface structure to the caller user defined data pointer.
    *pUserDefinedData = pBaseInterface->UserDefinedData;


    return;
}





unsigned long
SignedIntToBin(
        long Value,
        unsigned char BitNum
        )
{
    unsigned char i;
    unsigned long Mask, Binary;



    // Generate Mask according to BitNum.
    Mask = 0;
    for(i = 0; i < BitNum; i++)
        Mask |= 0x1 << i;


    // Convert signed integer to binary with Mask.
    Binary = Value & Mask;


    return Binary;
}





long
BinToSignedInt(
        unsigned long Binary,
        unsigned char BitNum
        )
{
    int i;

    unsigned char SignedBit;
    unsigned long SignedBitExtension;

    long Value;



    // Get signed bit.
    SignedBit = (unsigned char)((Binary >> (BitNum - 1)) & BIT_0_MASK);


    // Generate signed bit extension.
    SignedBitExtension = 0;

    for(i = BitNum; i < LONG_BIT_NUM; i++)
        SignedBitExtension |= SignedBit << i;


    // Combine binary value and signed bit extension to signed integer value.
    Value = (long)(Binary | SignedBitExtension);


    return Value;
}





unsigned long
DivideWithCeiling(
        unsigned long Dividend,
        unsigned long Divisor
        )
{
    unsigned long Result;


    // Get primitive division result.
    Result = Dividend / Divisor;

    // Adjust primitive result with ceiling.
    if(Dividend % Divisor > 0)
        Result += 1;


    return Result;
}






