#ifndef KONFIGIDS_H
#define KONFIGIDS_H
// ---------------------------------------------------------------------------
//
// IDs f�r Konfigurationsparameter
// -------------------------------
//
//
//
// Version v1.0
//
// Autor:	Dipl.-Ing. (FH) Holger Busse
//			Dipl.-Ing. Sebastian Drey�ig
//
// (c) 2008 - 2018 KATHREIN Sachsen GmbH
// ---------------------------------------------------------------------------

// $Id: konfigids.h,v 1.60 2018/01/30 11:03:13 hbusse Exp $

// ===========================================================================
// Includes

#include "globtype.h"

// ===========================================================================
// Makros

#define CFGID_SIGN_SHIFT 31
#define CFGID_SIGN_MASK (0x1UL << CFGID_SIGN_SHIFT)
#define CFGID_SIGN_UNSIGNED (0UL << CFGID_SIGN_SHIFT)
#define CFGID_SIGN_SIGNED (1UL << CFGID_SIGN_SHIFT)

#define CFGID_DATATYPE_SHIFT 28
#define CFGID_DATATYPE_MASK (0x7UL << CFGID_DATATYPE_SHIFT)
#define CFGID_DATATYPE_BOOL (0UL << CFGID_DATATYPE_SHIFT)
#define CFGID_DATATYPE_BYTE (1UL << CFGID_DATATYPE_SHIFT)
#define CFGID_DATATYPE_WORD (2UL << CFGID_DATATYPE_SHIFT)
#define CFGID_DATATYPE_DWORD (3UL << CFGID_DATATYPE_SHIFT)
#define CFGID_DATATYPE_VARIANT (7UL << CFGID_DATATYPE_SHIFT)

#define CFGID_TYPESIZE_SHIFT 22
#define CFGID_TYPESIZE_MASK (0x3FUL << CFGID_TYPESIZE_SHIFT)
#define CFGID_TYPESIZE_BOOL (1UL << CFGID_TYPESIZE_SHIFT)
#define CFGID_TYPESIZE_BYTE (1UL << CFGID_TYPESIZE_SHIFT)
#define CFGID_TYPESIZE_WORD (2UL << CFGID_TYPESIZE_SHIFT)
#define CFGID_TYPESIZE_DWORD (4UL << CFGID_TYPESIZE_SHIFT)

#define CFGID_UNIT_SHIFT 16
#define CFGID_UNIT_MASK (0x3FUL << CFGID_UNIT_SHIFT)
#define CFGID_UNIT_NONE (0UL << CFGID_UNIT_SHIFT)     // keine spezielle Einheit
#define CFGID_UNIT_025DBM (1UL << CFGID_UNIT_SHIFT)   // 0,25dBm
#define CFGID_UNIT_025DB (2UL << CFGID_UNIT_SHIFT)    // 0,25dB
#define CFGID_UNIT_025DBIC (3UL << CFGID_UNIT_SHIFT)  // 0,25dBic
#define CFGID_UNIT_MSECOND (4UL << CFGID_UNIT_SHIFT)  // Millisekunde
#define CFGID_UNIT_SECOND (5UL << CFGID_UNIT_SHIFT)   // Sekunde
#define CFGID_UNIT_025DBMERP (6UL << CFGID_UNIT_SHIFT)  // 0,25dBm(erp)
#define CFGID_UNIT_KHZ (7UL << CFGID_UNIT_SHIFT)        // Kilohertz
#define CFGID_UNIT_PERCENT (8UL << CFGID_UNIT_SHIFT)    // Prozent

#define CFGID_GROUP_SHIFT 12
#define CFGID_GROUP_MASK (0xFUL << CFGID_GROUP_SHIFT)
#define CFGID_GROUP_GLOBAL (0UL << CFGID_GROUP_SHIFT)
#define CFGID_GROUP_RFINTERFACE (1UL << CFGID_GROUP_SHIFT)
#define CFGID_GROUP_TAGCOMM (2UL << CFGID_GROUP_SHIFT)
#define CFGID_GROUP_OBSERVEDLIST (3UL << CFGID_GROUP_SHIFT)
#define CFGID_GROUP_HOSTCOMM (4UL << CFGID_GROUP_SHIFT)
#define CFGID_GROUP_ETSI (5UL << CFGID_GROUP_SHIFT)
#define CFGID_GROUP_COMMSTANDARD (6UL << CFGID_GROUP_SHIFT)
#define CFGID_GROUP_KRAI (7UL << CFGID_GROUP_SHIFT)
#define CFGID_GROUP_GPIO (8UL << CFGID_GROUP_SHIFT)
#define CFGID_GROUP_LED (9UL << CFGID_GROUP_SHIFT)
#define CFGID_GROUP_RESERVED (0xFUL << CFGID_GROUP_SHIFT)

#define CFGID_NMBR_SHIFT 0
#define CFGID_NMBR_MASK (0xFFFUL << CFGID_NMBR_SHIFT)

#define CFGID_DATATYPEANDSIZE_BOOL (CFGID_DATATYPE_BOOL | CFGID_TYPESIZE_BOOL)
#define CFGID_DATATYPEANDSIZE_BYTE (CFGID_DATATYPE_BYTE | CFGID_TYPESIZE_BYTE)
#define CFGID_DATATYPEANDSIZE_WORD (CFGID_DATATYPE_WORD | CFGID_TYPESIZE_WORD)
#define CFGID_DATATYPEANDSIZE_DWORD \
  (CFGID_DATATYPE_DWORD | CFGID_TYPESIZE_DWORD)

// ---------------------------------------------------------------------------

// Gruppe GLOBAL

#define cfgidGlobalDefaultParameterSet                 \
  ((TDWord)(CFGID_GROUP_GLOBAL | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 0))

// Gruppe RFINTERFACE

#define cfgidRFInterfaceERPPower1                           \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DBM | 0))
#define cfgidRFInterfaceERPPower2                           \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DBM | 1))
#define cfgidRFInterfaceERPPower3                           \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DBM | 2))
#define cfgidRFInterfaceERPPower4                           \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DBM | 3))
#define cfgidRFInterfaceERPPower5                           \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DBM | 4))
#define cfgidRFInterfaceERPPower6                           \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DBM | 5))
#define cfgidRFInterfaceERPPower7                           \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DBM | 6))
#define cfgidRFInterfaceERPPower8                           \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DBM | 7))
#define cfgidRFInterfaceTimeToPowerOff                       \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED |  \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_SECOND | \
            20))  // Generation 2
#define cfgidRFInterfaceModulationType                      \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE |  \
            21))  // Generation 2
#define cfgidRFInterfaceDisableAntennaTest                  \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BOOL | CFGID_UNIT_NONE |  \
            22))  // Generation 2
#define cfgidRFInterfaceActivateSelfJammerCancelation       \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BOOL | CFGID_UNIT_NONE |  \
            23))  // Generation 3
#define cfgidRFInterfaceActivateTunableMatchingNetwork      \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BOOL | CFGID_UNIT_NONE |  \
            24))  // Generation 3
#define cfgidRFInterfaceScanIntervalSelfJammerCancelation     \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED |   \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | \
            25))  // Generation 3
#define cfgidRFInterfaceMultiplexingAntennaport1            \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 30))
#define cfgidRFInterfaceMultiplexingAntennaport2            \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 31))
#define cfgidRFInterfaceMultiplexingAntennaport3            \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 32))
#define cfgidRFInterfaceMultiplexingAntennaport4            \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 33))
#define cfgidRFInterfaceMultiplexingAntennaport5            \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 34))
#define cfgidRFInterfaceMultiplexingAntennaport6            \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 35))
#define cfgidRFInterfaceMultiplexingAntennaport7            \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 36))
#define cfgidRFInterfaceMultiplexingAntennaport8            \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 37))
#define cfgidRFInterfaceMultiplexingExposureTime1           \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 50))
#define cfgidRFInterfaceMultiplexingExposureTime2           \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 51))
#define cfgidRFInterfaceMultiplexingExposureTime3           \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 52))
#define cfgidRFInterfaceMultiplexingExposureTime4           \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 53))
#define cfgidRFInterfaceMultiplexingExposureTime5           \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 54))
#define cfgidRFInterfaceMultiplexingExposureTime6           \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 55))
#define cfgidRFInterfaceMultiplexingExposureTime7           \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 56))
#define cfgidRFInterfaceMultiplexingExposureTime8           \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 57))
#define cfgidRFInterfaceCableLoss1                          \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DB | 70))
#define cfgidRFInterfaceCableLoss2                          \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DB | 71))
#define cfgidRFInterfaceCableLoss3                          \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DB | 72))
#define cfgidRFInterfaceCableLoss4                          \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DB | 73))
#define cfgidRFInterfaceCableLoss5                          \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DB | 74))
#define cfgidRFInterfaceCableLoss6                          \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DB | 75))
#define cfgidRFInterfaceCableLoss7                          \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DB | 76))
#define cfgidRFInterfaceCableLoss8                          \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DB | 77))
#define cfgidRFInterfaceAntennaGain1                      \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_SIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DBIC | 90))
#define cfgidRFInterfaceAntennaGain2                      \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_SIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DBIC | 91))
#define cfgidRFInterfaceAntennaGain3                      \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_SIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DBIC | 92))
#define cfgidRFInterfaceAntennaGain4                      \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_SIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DBIC | 93))
#define cfgidRFInterfaceAntennaGain5                      \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_SIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DBIC | 94))
#define cfgidRFInterfaceAntennaGain6                      \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_SIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DBIC | 95))
#define cfgidRFInterfaceAntennaGain7                      \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_SIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DBIC | 96))
#define cfgidRFInterfaceAntennaGain8                      \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_SIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DBIC | 97))
#define cfgidRFInterfaceRSSIThreshold1                      \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 110))
#define cfgidRFInterfaceRSSIThreshold2                      \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 111))
#define cfgidRFInterfaceRSSIThreshold3                      \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 112))
#define cfgidRFInterfaceRSSIThreshold4                      \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 113))
#define cfgidRFInterfaceRSSIThreshold5                      \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 114))
#define cfgidRFInterfaceRSSIThreshold6                      \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 115))
#define cfgidRFInterfaceRSSIThreshold7                      \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 116))
#define cfgidRFInterfaceRSSIThreshold8                      \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 117))
#define cfgidRFInterfaceMultiPowerTagAccess1                \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BOOL | CFGID_UNIT_NONE |  \
            130))  // Generation 2
#define cfgidRFInterfaceMultiPowerTagAccess2                \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BOOL | CFGID_UNIT_NONE |  \
            131))  // Generation 2
#define cfgidRFInterfaceMultiPowerTagAccess3                \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BOOL | CFGID_UNIT_NONE |  \
            132))  // Generation 2
#define cfgidRFInterfaceMultiPowerTagAccess4                \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BOOL | CFGID_UNIT_NONE |  \
            133))  // Generation 2
#define cfgidRFInterfaceMultiPowerTagAccess5                \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BOOL | CFGID_UNIT_NONE |  \
            134))  // Generation 2
#define cfgidRFInterfaceMultiPowerTagAccess6                \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BOOL | CFGID_UNIT_NONE |  \
            135))  // Generation 2
#define cfgidRFInterfaceMultiPowerTagAccess7                \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BOOL | CFGID_UNIT_NONE |  \
            136))  // Generation 2
#define cfgidRFInterfaceMultiPowerTagAccess8                \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BOOL | CFGID_UNIT_NONE |  \
            137))  // Generation 2
#define cfgidRFInterfaceMaxAllowedAntennaOutputPower1           \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED |     \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DBMERP | \
            150))  // Generation 2
#define cfgidRFInterfaceMaxAllowedAntennaOutputPower2           \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED |     \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DBMERP | \
            151))  // Generation 2
#define cfgidRFInterfaceMaxAllowedAntennaOutputPower3           \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED |     \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DBMERP | \
            152))  // Generation 2
#define cfgidRFInterfaceMaxAllowedAntennaOutputPower4           \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED |     \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DBMERP | \
            153))  // Generation 2
#define cfgidRFInterfaceMaxAllowedAntennaOutputPower5           \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED |     \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DBMERP | \
            154))  // Generation 2
#define cfgidRFInterfaceMaxAllowedAntennaOutputPower6           \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED |     \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DBMERP | \
            155))  // Generation 2
#define cfgidRFInterfaceMaxAllowedAntennaOutputPower7           \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED |     \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DBMERP | \
            156))  // Generation 2
#define cfgidRFInterfaceMaxAllowedAntennaOutputPower8           \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED |     \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DBMERP | \
            157))  // Generation 2
#define cfgidRFInterfaceEnableRSSIThresholdAtSpecificCmds   \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BOOL | CFGID_UNIT_NONE | 170))
#define cfgidRFInterfaceFlashWriteAdditionalPower           \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DB | 171))
#define cfgidRFInterfaceFlashReadAdditionalPower            \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DB | 172))
#define cfgidRFInterfaceASyncInventoryBreakInventoryCount   \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_NONE |  \
            173))  // Generation 2
#define cfgidRFInterfaceASyncInventoryBreakMinLength          \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED |   \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | \
            174))  // Generation 2
#define cfgidRFInterfaceASyncInventoryBreakMaxLength          \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED |   \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | \
            175))  // Generation 2
#define cfgidRFInterfaceASyncPowerRampUseRampedPowerAtSyncCmds \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED |    \
            CFGID_DATATYPEANDSIZE_BOOL | CFGID_UNIT_NONE |     \
            189))  // Generation 2
#define cfgidRFInterfaceASyncPowerRampPowerStepSize1        \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DB | \
            190))  // Generation 2
#define cfgidRFInterfaceASyncPowerRampPowerStepSize2        \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DB | \
            191))  // Generation 2
#define cfgidRFInterfaceASyncPowerRampPowerStepSize3        \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DB | \
            192))  // Generation 2
#define cfgidRFInterfaceASyncPowerRampPowerStepSize4        \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DB | \
            193))  // Generation 2
#define cfgidRFInterfaceASyncPowerRampPowerStepSize5        \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DB | \
            194))  // Generation 2
#define cfgidRFInterfaceASyncPowerRampPowerStepSize6        \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DB | \
            195))  // Generation 2
#define cfgidRFInterfaceASyncPowerRampPowerStepSize7        \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DB | \
            196))  // Generation 2
#define cfgidRFInterfaceASyncPowerRampPowerStepSize8        \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DB | \
            197))  // Generation 2
#define cfgidRFInterfaceASyncPowerRampMaxPowerIncrease1     \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DB | \
            210))  // Generation 2
#define cfgidRFInterfaceASyncPowerRampMaxPowerIncrease2     \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DB | \
            211))  // Generation 2
#define cfgidRFInterfaceASyncPowerRampMaxPowerIncrease3     \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DB | \
            212))  // Generation 2
#define cfgidRFInterfaceASyncPowerRampMaxPowerIncrease4     \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DB | \
            213))  // Generation 2
#define cfgidRFInterfaceASyncPowerRampMaxPowerIncrease5     \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DB | \
            214))  // Generation 2
#define cfgidRFInterfaceASyncPowerRampMaxPowerIncrease6     \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DB | \
            215))  // Generation 2
#define cfgidRFInterfaceASyncPowerRampMaxPowerIncrease7     \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DB | \
            216))  // Generation 2
#define cfgidRFInterfaceASyncPowerRampMaxPowerIncrease8     \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DB | \
            217))  // Generation 2
#define cfgidRFInterfaceASyncPowerRampEmptyInventoryBeforeStep1 \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED |     \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_NONE |      \
            230))  // Generation 2
#define cfgidRFInterfaceASyncPowerRampEmptyInventoryBeforeStep2 \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED |     \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_NONE |      \
            231))  // Generation 2
#define cfgidRFInterfaceASyncPowerRampEmptyInventoryBeforeStep3 \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED |     \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_NONE |      \
            232))  // Generation 2
#define cfgidRFInterfaceASyncPowerRampEmptyInventoryBeforeStep4 \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED |     \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_NONE |      \
            233))  // Generation 2
#define cfgidRFInterfaceASyncPowerRampEmptyInventoryBeforeStep5 \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED |     \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_NONE |      \
            234))  // Generation 2
#define cfgidRFInterfaceASyncPowerRampEmptyInventoryBeforeStep6 \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED |     \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_NONE |      \
            235))  // Generation 2
#define cfgidRFInterfaceASyncPowerRampEmptyInventoryBeforeStep7 \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED |     \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_NONE |      \
            236))  // Generation 2
#define cfgidRFInterfaceASyncPowerRampEmptyInventoryBeforeStep8 \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED |     \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_NONE |      \
            237))  // Generation 2
#define cfgidRFInterfaceASyncPowerRampEmptyInventoryTagCount1 \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED |   \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_NONE |    \
            250))  // Generation 2
#define cfgidRFInterfaceASyncPowerRampEmptyInventoryTagCount2 \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED |   \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_NONE |    \
            251))  // Generation 2
#define cfgidRFInterfaceASyncPowerRampEmptyInventoryTagCount3 \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED |   \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_NONE |    \
            252))  // Generation 2
#define cfgidRFInterfaceASyncPowerRampEmptyInventoryTagCount4 \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED |   \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_NONE |    \
            253))  // Generation 2
#define cfgidRFInterfaceASyncPowerRampEmptyInventoryTagCount5 \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED |   \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_NONE |    \
            254))  // Generation 2
#define cfgidRFInterfaceASyncPowerRampEmptyInventoryTagCount6 \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED |   \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_NONE |    \
            255))  // Generation 2
#define cfgidRFInterfaceASyncPowerRampEmptyInventoryTagCount7 \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED |   \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_NONE |    \
            256))  // Generation 2
#define cfgidRFInterfaceASyncPowerRampEmptyInventoryTagCount8 \
  ((TDWord)(CFGID_GROUP_RFINTERFACE | CFGID_SIGN_UNSIGNED |   \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_NONE |    \
            257))  // Generation 2

// Gruppe TAGCOMM

#define cfgidTagCommUsePilottone                        \
  ((TDWord)(CFGID_GROUP_TAGCOMM | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BOOL | CFGID_UNIT_NONE | 0))
#define cfgidTagCommInitialQ                            \
  ((TDWord)(CFGID_GROUP_TAGCOMM | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 1))
#define cfgidTagCommSession                             \
  ((TDWord)(CFGID_GROUP_TAGCOMM | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 2))
#define cfgidTagCommMaxErrors                           \
  ((TDWord)(CFGID_GROUP_TAGCOMM | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 3))
#define cfgidTagCommCommunicationProfile                \
  ((TDWord)(CFGID_GROUP_TAGCOMM | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 4))
#define cfgidTagCommCommunicationStandard               \
  ((TDWord)(CFGID_GROUP_TAGCOMM | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 5))
#define cfgidTagCommIntelligentWrite                    \
  ((TDWord)(CFGID_GROUP_TAGCOMM | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BOOL | CFGID_UNIT_NONE | 6))
#define cfgidTagCommVerifyWrite                         \
  ((TDWord)(CFGID_GROUP_TAGCOMM | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BOOL | CFGID_UNIT_NONE | 7))
#define cfgidTagCommQueryTarget                         \
  ((TDWord)(CFGID_GROUP_TAGCOMM | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 8))
#define cfgidTagCommQuerySel                            \
  ((TDWord)(CFGID_GROUP_TAGCOMM | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 9))
#define cfgidTagCommForcePowerOffAfterEPCWrite                \
  ((TDWord)(CFGID_GROUP_TAGCOMM | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_MSECOND | \
            10))  // Generation 2
#define cfgidTagCommTransmitGetEPCsPreSelect            \
  ((TDWord)(CFGID_GROUP_TAGCOMM | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BOOL | CFGID_UNIT_NONE | 11))
#define cfgidTagCommTransmitSelectIfNoFilterIsOn        \
  ((TDWord)(CFGID_GROUP_TAGCOMM | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BOOL | CFGID_UNIT_NONE | 12))
#define cfgidTagCommNumberOfEPCWords                       \
  ((TDWord)(CFGID_GROUP_TAGCOMM | CFGID_SIGN_UNSIGNED |    \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            13))  // Generation 2
#define cfgidTagCommUseBlockWrite                       \
  ((TDWord)(CFGID_GROUP_TAGCOMM | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BOOL | CFGID_UNIT_NONE | 14))
#define cfgidTagCommDisableReceivingNXPReadProtectedTags \
  ((TDWord)(CFGID_GROUP_TAGCOMM | CFGID_SIGN_UNSIGNED |  \
            CFGID_DATATYPEANDSIZE_BOOL | CFGID_UNIT_NONE | 15))
#define cfgidTagCommASyncRandomTimeslices                  \
  ((TDWord)(CFGID_GROUP_TAGCOMM | CFGID_SIGN_UNSIGNED |    \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            16))  // Generation 2
#define cfgidTagCommNumberOfBlacklistEntries               \
  ((TDWord)(CFGID_GROUP_TAGCOMM | CFGID_SIGN_UNSIGNED |    \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_NONE | \
            17))  // Generation 2
#define cfgidTagCommDisableTemporaryTagListOnTagPasswordAccess \
  ((TDWord)(CFGID_GROUP_TAGCOMM | CFGID_SIGN_UNSIGNED |        \
            CFGID_DATATYPEANDSIZE_BOOL | CFGID_UNIT_NONE | 18))

// Gruppe OBSERVEDLIST

#define cfgidObservedListGlimpsedTimeoutCount                \
  ((TDWord)(CFGID_GROUP_OBSERVEDLIST | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE |   \
            0))  // Generation 2
#define cfgidObservedListObservedThresholdCount              \
  ((TDWord)(CFGID_GROUP_OBSERVEDLIST | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 1))
#define cfgidObservedListObservedTimeoutCount                \
  ((TDWord)(CFGID_GROUP_OBSERVEDLIST | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 2))
#define cfgidObservedListRSSILowPassTau                      \
  ((TDWord)(CFGID_GROUP_OBSERVEDLIST | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_NONE |   \
            3))  // Generation 2
#define cfgidObservedListMaxNumberOfCommandAttempts          \
  ((TDWord)(CFGID_GROUP_OBSERVEDLIST | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE |   \
            4))  // Generation 3

// Gruppe HOSTCOMM

#define cfgidHostCommExtendedResultFlag                  \
  ((TDWord)(CFGID_GROUP_HOSTCOMM | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 0))
#define cfgidHostCommAntennaIndependentOperation         \
  ((TDWord)(CFGID_GROUP_HOSTCOMM | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BOOL | CFGID_UNIT_NONE | 1))
#define cfgidHostCommASyncAdditionalRSSIDataDeliveryDelta \
  ((TDWord)(CFGID_GROUP_HOSTCOMM | CFGID_SIGN_UNSIGNED |  \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 2))
#define cfgidHostCommUseMillisecondsAsTimestamp          \
  ((TDWord)(CFGID_GROUP_HOSTCOMM | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BOOL | CFGID_UNIT_NONE | 3))
#define cfgidHostCommASyncHeartbeatInterval              \
  ((TDWord)(CFGID_GROUP_HOSTCOMM | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_NONE | 4))

// Gruppe ETSI

#define cfgidETSIPortChannelListGlobalValue1               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            0))  // Generation 2
#define cfgidETSIPortChannelListGlobalValue2               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            1))  // Generation 2
#define cfgidETSIPortChannelListGlobalValue3               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            2))  // Generation 2
#define cfgidETSIPortChannelListGlobalValue4               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            3))  // Generation 2
#define cfgidETSIPortChannelListGlobalValue5               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            4))  // Generation 2
#define cfgidETSIPortChannelListGlobalValue6               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            5))  // Generation 2
#define cfgidETSIPortChannelListGlobalValue7               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            6))  // Generation 2
#define cfgidETSIPortChannelListGlobalValue8               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            7))  // Generation 2
#define cfgidETSIPortChannelListGlobalValue9               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            8))  // Generation 2
#define cfgidETSIPortChannelListGlobalValue10              \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            9))  // Generation 2
#define cfgidETSIPortChannelListGlobalValue11              \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            10))  // Generation 2
#define cfgidETSIPortChannelListGlobalValue12              \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            11))  // Generation 2
#define cfgidETSIPortChannelListGlobalValue13              \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            12))  // Generation 2
#define cfgidETSIPortChannelListGlobalValue14              \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            13))  // Generation 2
#define cfgidETSIPortChannelListGlobalValue15              \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            14))  // Generation 2
#define cfgidETSIPortChannelListGlobalValue16              \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            15))  // Generation 2
#define cfgidETSIPortChannelListPort1Value1                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            16))  // Generation 2
#define cfgidETSIPortChannelListPort1Value2                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            17))  // Generation 2
#define cfgidETSIPortChannelListPort1Value3                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            18))  // Generation 2
#define cfgidETSIPortChannelListPort1Value4                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            19))  // Generation 2
#define cfgidETSIPortChannelListPort1Value5                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            20))  // Generation 2
#define cfgidETSIPortChannelListPort1Value6                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            21))  // Generation 2
#define cfgidETSIPortChannelListPort1Value7                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            22))  // Generation 2
#define cfgidETSIPortChannelListPort1Value8                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            23))  // Generation 2
#define cfgidETSIPortChannelListPort1Value9                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            24))  // Generation 2
#define cfgidETSIPortChannelListPort1Value10               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            25))  // Generation 2
#define cfgidETSIPortChannelListPort1Value11               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            26))  // Generation 2
#define cfgidETSIPortChannelListPort1Value12               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            27))  // Generation 2
#define cfgidETSIPortChannelListPort1Value13               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            28))  // Generation 2
#define cfgidETSIPortChannelListPort1Value14               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            29))  // Generation 2
#define cfgidETSIPortChannelListPort1Value15               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            30))  // Generation 2
#define cfgidETSIPortChannelListPort1Value16               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            31))  // Generation 2
#define cfgidETSIPortChannelListPort2Value1                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            32))  // Generation 2
#define cfgidETSIPortChannelListPort2Value2                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            33))  // Generation 2
#define cfgidETSIPortChannelListPort2Value3                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            34))  // Generation 2
#define cfgidETSIPortChannelListPort2Value4                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            35))  // Generation 2
#define cfgidETSIPortChannelListPort2Value5                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            36))  // Generation 2
#define cfgidETSIPortChannelListPort2Value6                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            37))  // Generation 2
#define cfgidETSIPortChannelListPort2Value7                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            38))  // Generation 2
#define cfgidETSIPortChannelListPort2Value8                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            39))  // Generation 2
#define cfgidETSIPortChannelListPort2Value9                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            40))  // Generation 2
#define cfgidETSIPortChannelListPort2Value10               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            41))  // Generation 2
#define cfgidETSIPortChannelListPort2Value11               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            42))  // Generation 2
#define cfgidETSIPortChannelListPort2Value12               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            43))  // Generation 2
#define cfgidETSIPortChannelListPort2Value13               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            44))  // Generation 2
#define cfgidETSIPortChannelListPort2Value14               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            45))  // Generation 2
#define cfgidETSIPortChannelListPort2Value15               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            46))  // Generation 2
#define cfgidETSIPortChannelListPort2Value16               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            47))  // Generation 2
#define cfgidETSIPortChannelListPort3Value1                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            48))  // Generation 2
#define cfgidETSIPortChannelListPort3Value2                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            49))  // Generation 2
#define cfgidETSIPortChannelListPort3Value3                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            50))  // Generation 2
#define cfgidETSIPortChannelListPort3Value4                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            51))  // Generation 2
#define cfgidETSIPortChannelListPort3Value5                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            52))  // Generation 2
#define cfgidETSIPortChannelListPort3Value6                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            53))  // Generation 2
#define cfgidETSIPortChannelListPort3Value7                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            54))  // Generation 2
#define cfgidETSIPortChannelListPort3Value8                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            55))  // Generation 2
#define cfgidETSIPortChannelListPort3Value9                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            56))  // Generation 2
#define cfgidETSIPortChannelListPort3Value10               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            57))  // Generation 2
#define cfgidETSIPortChannelListPort3Value11               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            58))  // Generation 2
#define cfgidETSIPortChannelListPort3Value12               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            59))  // Generation 2
#define cfgidETSIPortChannelListPort3Value13               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            60))  // Generation 2
#define cfgidETSIPortChannelListPort3Value14               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            61))  // Generation 2
#define cfgidETSIPortChannelListPort3Value15               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            62))  // Generation 2
#define cfgidETSIPortChannelListPort3Value16               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            63))  // Generation 2
#define cfgidETSIPortChannelListPort4Value1                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            64))  // Generation 2
#define cfgidETSIPortChannelListPort4Value2                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            65))  // Generation 2
#define cfgidETSIPortChannelListPort4Value3                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            66))  // Generation 2
#define cfgidETSIPortChannelListPort4Value4                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            67))  // Generation 2
#define cfgidETSIPortChannelListPort4Value5                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            68))  // Generation 2
#define cfgidETSIPortChannelListPort4Value6                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            69))  // Generation 2
#define cfgidETSIPortChannelListPort4Value7                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            70))  // Generation 2
#define cfgidETSIPortChannelListPort4Value8                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            71))  // Generation 2
#define cfgidETSIPortChannelListPort4Value9                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            72))  // Generation 2
#define cfgidETSIPortChannelListPort4Value10               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            73))  // Generation 2
#define cfgidETSIPortChannelListPort4Value11               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            74))  // Generation 2
#define cfgidETSIPortChannelListPort4Value12               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            75))  // Generation 2
#define cfgidETSIPortChannelListPort4Value13               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            76))  // Generation 2
#define cfgidETSIPortChannelListPort4Value14               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            77))  // Generation 2
#define cfgidETSIPortChannelListPort4Value15               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            78))  // Generation 2
#define cfgidETSIPortChannelListPort4Value16               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            79))  // Generation 2
#define cfgidETSIPortChannelListPort5Value1                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            80))  // Generation 2
#define cfgidETSIPortChannelListPort5Value2                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            81))  // Generation 2
#define cfgidETSIPortChannelListPort5Value3                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            82))  // Generation 2
#define cfgidETSIPortChannelListPort5Value4                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            83))  // Generation 2
#define cfgidETSIPortChannelListPort5Value5                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            84))  // Generation 2
#define cfgidETSIPortChannelListPort5Value6                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            85))  // Generation 2
#define cfgidETSIPortChannelListPort5Value7                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            86))  // Generation 2
#define cfgidETSIPortChannelListPort5Value8                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            87))  // Generation 2
#define cfgidETSIPortChannelListPort5Value9                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            88))  // Generation 2
#define cfgidETSIPortChannelListPort5Value10               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            89))  // Generation 2
#define cfgidETSIPortChannelListPort5Value11               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            90))  // Generation 2
#define cfgidETSIPortChannelListPort5Value12               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            91))  // Generation 2
#define cfgidETSIPortChannelListPort5Value13               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            92))  // Generation 2
#define cfgidETSIPortChannelListPort5Value14               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            93))  // Generation 2
#define cfgidETSIPortChannelListPort5Value15               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            94))  // Generation 2
#define cfgidETSIPortChannelListPort5Value16               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            95))  // Generation 2
#define cfgidETSIPortChannelListPort6Value1                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            96))  // Generation 2
#define cfgidETSIPortChannelListPort6Value2                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            97))  // Generation 2
#define cfgidETSIPortChannelListPort6Value3                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            98))  // Generation 2
#define cfgidETSIPortChannelListPort6Value4                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            99))  // Generation 2
#define cfgidETSIPortChannelListPort6Value5                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            100))  // Generation 2
#define cfgidETSIPortChannelListPort6Value6                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            101))  // Generation 2
#define cfgidETSIPortChannelListPort6Value7                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            102))  // Generation 2
#define cfgidETSIPortChannelListPort6Value8                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            103))  // Generation 2
#define cfgidETSIPortChannelListPort6Value9                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            104))  // Generation 2
#define cfgidETSIPortChannelListPort6Value10               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            105))  // Generation 2
#define cfgidETSIPortChannelListPort6Value11               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            106))  // Generation 2
#define cfgidETSIPortChannelListPort6Value12               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            107))  // Generation 2
#define cfgidETSIPortChannelListPort6Value13               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            108))  // Generation 2
#define cfgidETSIPortChannelListPort6Value14               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            109))  // Generation 2
#define cfgidETSIPortChannelListPort6Value15               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            110))  // Generation 2
#define cfgidETSIPortChannelListPort6Value16               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            111))  // Generation 2
#define cfgidETSIPortChannelListPort7Value1                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            112))  // Generation 2
#define cfgidETSIPortChannelListPort7Value2                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            113))  // Generation 2
#define cfgidETSIPortChannelListPort7Value3                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            114))  // Generation 2
#define cfgidETSIPortChannelListPort7Value4                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            115))  // Generation 2
#define cfgidETSIPortChannelListPort7Value5                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            116))  // Generation 2
#define cfgidETSIPortChannelListPort7Value6                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            117))  // Generation 2
#define cfgidETSIPortChannelListPort7Value7                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            118))  // Generation 2
#define cfgidETSIPortChannelListPort7Value8                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            119))  // Generation 2
#define cfgidETSIPortChannelListPort7Value9                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            120))  // Generation 2
#define cfgidETSIPortChannelListPort7Value10               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            121))  // Generation 2
#define cfgidETSIPortChannelListPort7Value11               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            122))  // Generation 2
#define cfgidETSIPortChannelListPort7Value12               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            123))  // Generation 2
#define cfgidETSIPortChannelListPort7Value13               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            124))  // Generation 2
#define cfgidETSIPortChannelListPort7Value14               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            125))  // Generation 2
#define cfgidETSIPortChannelListPort7Value15               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            126))  // Generation 2
#define cfgidETSIPortChannelListPort7Value16               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            127))  // Generation 2
#define cfgidETSIPortChannelListPort8Value1                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            128))  // Generation 2
#define cfgidETSIPortChannelListPort8Value2                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            129))  // Generation 2
#define cfgidETSIPortChannelListPort8Value3                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            130))  // Generation 2
#define cfgidETSIPortChannelListPort8Value4                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            131))  // Generation 2
#define cfgidETSIPortChannelListPort8Value5                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            132))  // Generation 2
#define cfgidETSIPortChannelListPort8Value6                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            133))  // Generation 2
#define cfgidETSIPortChannelListPort8Value7                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            134))  // Generation 2
#define cfgidETSIPortChannelListPort8Value8                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            135))  // Generation 2
#define cfgidETSIPortChannelListPort8Value9                \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            136))  // Generation 2
#define cfgidETSIPortChannelListPort8Value10               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            137))  // Generation 2
#define cfgidETSIPortChannelListPort8Value11               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            138))  // Generation 2
#define cfgidETSIPortChannelListPort8Value12               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            139))  // Generation 2
#define cfgidETSIPortChannelListPort8Value13               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            140))  // Generation 2
#define cfgidETSIPortChannelListPort8Value14               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            141))  // Generation 2
#define cfgidETSIPortChannelListPort8Value15               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            142))  // Generation 2
#define cfgidETSIPortChannelListPort8Value16               \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            143))  // Generation 2
#define cfgidETSIChannelSwitchingMode                      \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            150))  // Generation 2
#define cfgidETSIPowerCheckOverAllAllowedChannels          \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BOOL | CFGID_UNIT_NONE | \
            151))  // Generation 2
#define cfgidETSIActiveChannels                            \
  ((TDWord)(CFGID_GROUP_ETSI | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_NONE | \
            152))  // Generation 3

// Gruppe COMMSTANDARD

#define cfgidCommStandardCenterFreqCH0                       \
  ((TDWord)(CFGID_GROUP_COMMSTANDARD | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_DWORD | CFGID_UNIT_KHZ | 0))
#define cfgidCommStandardChannelWidth                        \
  ((TDWord)(CFGID_GROUP_COMMSTANDARD | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_KHZ | 1))
#define cfgidCommStandardMaxChannelTime                      \
  ((TDWord)(CFGID_GROUP_COMMSTANDARD | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 2))
#define cfgidCommStandardMinChannelWaitTime                  \
  ((TDWord)(CFGID_GROUP_COMMSTANDARD | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 3))
#define cfgidCommStandardFirstChannel                        \
  ((TDWord)(CFGID_GROUP_COMMSTANDARD | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 4))
#define cfgidCommStandardLastChannel                         \
  ((TDWord)(CFGID_GROUP_COMMSTANDARD | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 5))
#define cfgidCommStandardUseLBT                              \
  ((TDWord)(CFGID_GROUP_COMMSTANDARD | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BOOL | CFGID_UNIT_NONE | 6))
#define cfgidCommStandardLBTThreshold                        \
  ((TDWord)(CFGID_GROUP_COMMSTANDARD | CFGID_SIGN_SIGNED |   \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_025DBM | \
            7))  // Generation 3

// Gruppe KRAI

#define cfgidKRAIAntennaPropertyAntennaport1         \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 0))
#define cfgidKRAIAntennaPropertyAntennaport2         \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 1))
#define cfgidKRAIAntennaPropertyAntennaport3         \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 2))
#define cfgidKRAIAntennaPropertyAntennaport4         \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 3))
#define cfgidKRAIAntennaPropertyAntennaport5         \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 4))
#define cfgidKRAIAntennaPropertyAntennaport6         \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 5))
#define cfgidKRAIAntennaPropertyAntennaport7         \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 6))
#define cfgidKRAIAntennaPropertyAntennaport8         \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 7))
#define cfgidKRAIJumpercableCableLossAntennaport1    \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DB | 20))
#define cfgidKRAIJumpercableCableLossAntennaport2    \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DB | 21))
#define cfgidKRAIJumpercableCableLossAntennaport3    \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DB | 22))
#define cfgidKRAIJumpercableCableLossAntennaport4    \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DB | 23))
#define cfgidKRAIJumpercableCableLossAntennaport5    \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DB | 24))
#define cfgidKRAIJumpercableCableLossAntennaport6    \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DB | 25))
#define cfgidKRAIJumpercableCableLossAntennaport7    \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DB | 26))
#define cfgidKRAIJumpercableCableLossAntennaport8    \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_025DB | 27))
#define cfgidKRAILED1OutputFunctionAntennaport1      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 40))
#define cfgidKRAILED2OutputFunctionAntennaport1      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 41))
#define cfgidKRAILED3OutputFunctionAntennaport1      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 42))
#define cfgidKRAILED4OutputFunctionAntennaport1      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 43))
#define cfgidKRAILED5OutputFunctionAntennaport1      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 44))
#define cfgidKRAILED6OutputFunctionAntennaport1      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 45))
#define cfgidKRAILED7OutputFunctionAntennaport1      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 46))
#define cfgidKRAILED8OutputFunctionAntennaport1      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 47))
#define cfgidKRAILED1TimeToSwitchOffAntennaport1     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 50))
#define cfgidKRAILED2TimeToSwitchOffAntennaport1     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 51))
#define cfgidKRAILED3TimeToSwitchOffAntennaport1     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 52))
#define cfgidKRAILED4TimeToSwitchOffAntennaport1     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 53))
#define cfgidKRAILED5TimeToSwitchOffAntennaport1     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 54))
#define cfgidKRAILED6TimeToSwitchOffAntennaport1     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 55))
#define cfgidKRAILED7TimeToSwitchOffAntennaport1     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 56))
#define cfgidKRAILED8TimeToSwitchOffAntennaport1     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 57))
#define cfgidKRAILED1OutputFunctionAntennaport2      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 70))
#define cfgidKRAILED2OutputFunctionAntennaport2      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 71))
#define cfgidKRAILED3OutputFunctionAntennaport2      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 72))
#define cfgidKRAILED4OutputFunctionAntennaport2      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 73))
#define cfgidKRAILED5OutputFunctionAntennaport2      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 74))
#define cfgidKRAILED6OutputFunctionAntennaport2      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 75))
#define cfgidKRAILED7OutputFunctionAntennaport2      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 76))
#define cfgidKRAILED8OutputFunctionAntennaport2      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 77))
#define cfgidKRAILED1TimeToSwitchOffAntennaport2     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 80))
#define cfgidKRAILED2TimeToSwitchOffAntennaport2     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 81))
#define cfgidKRAILED3TimeToSwitchOffAntennaport2     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 82))
#define cfgidKRAILED4TimeToSwitchOffAntennaport2     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 83))
#define cfgidKRAILED5TimeToSwitchOffAntennaport2     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 84))
#define cfgidKRAILED6TimeToSwitchOffAntennaport2     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 85))
#define cfgidKRAILED7TimeToSwitchOffAntennaport2     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 86))
#define cfgidKRAILED8TimeToSwitchOffAntennaport2     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 87))
#define cfgidKRAILED1OutputFunctionAntennaport3      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 100))
#define cfgidKRAILED2OutputFunctionAntennaport3      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 101))
#define cfgidKRAILED3OutputFunctionAntennaport3      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 102))
#define cfgidKRAILED4OutputFunctionAntennaport3      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 103))
#define cfgidKRAILED5OutputFunctionAntennaport3      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 104))
#define cfgidKRAILED6OutputFunctionAntennaport3      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 105))
#define cfgidKRAILED7OutputFunctionAntennaport3      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 106))
#define cfgidKRAILED8OutputFunctionAntennaport3      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 107))
#define cfgidKRAILED1TimeToSwitchOffAntennaport3     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 110))
#define cfgidKRAILED2TimeToSwitchOffAntennaport3     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 111))
#define cfgidKRAILED3TimeToSwitchOffAntennaport3     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 112))
#define cfgidKRAILED4TimeToSwitchOffAntennaport3     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 113))
#define cfgidKRAILED5TimeToSwitchOffAntennaport3     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 114))
#define cfgidKRAILED6TimeToSwitchOffAntennaport3     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 115))
#define cfgidKRAILED7TimeToSwitchOffAntennaport3     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 116))
#define cfgidKRAILED8TimeToSwitchOffAntennaport3     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 117))
#define cfgidKRAILED1OutputFunctionAntennaport4      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 130))
#define cfgidKRAILED2OutputFunctionAntennaport4      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 131))
#define cfgidKRAILED3OutputFunctionAntennaport4      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 132))
#define cfgidKRAILED4OutputFunctionAntennaport4      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 133))
#define cfgidKRAILED5OutputFunctionAntennaport4      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 134))
#define cfgidKRAILED6OutputFunctionAntennaport4      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 135))
#define cfgidKRAILED7OutputFunctionAntennaport4      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 136))
#define cfgidKRAILED8OutputFunctionAntennaport4      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 137))
#define cfgidKRAILED1TimeToSwitchOffAntennaport4     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 140))
#define cfgidKRAILED2TimeToSwitchOffAntennaport4     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 141))
#define cfgidKRAILED3TimeToSwitchOffAntennaport4     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 142))
#define cfgidKRAILED4TimeToSwitchOffAntennaport4     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 143))
#define cfgidKRAILED5TimeToSwitchOffAntennaport4     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 144))
#define cfgidKRAILED6TimeToSwitchOffAntennaport4     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 145))
#define cfgidKRAILED7TimeToSwitchOffAntennaport4     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 146))
#define cfgidKRAILED8TimeToSwitchOffAntennaport4     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 147))
#define cfgidKRAILED1OutputFunctionAntennaport5      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 160))
#define cfgidKRAILED2OutputFunctionAntennaport5      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 161))
#define cfgidKRAILED3OutputFunctionAntennaport5      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 162))
#define cfgidKRAILED4OutputFunctionAntennaport5      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 163))
#define cfgidKRAILED5OutputFunctionAntennaport5      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 164))
#define cfgidKRAILED6OutputFunctionAntennaport5      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 165))
#define cfgidKRAILED7OutputFunctionAntennaport5      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 166))
#define cfgidKRAILED8OutputFunctionAntennaport5      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 167))
#define cfgidKRAILED1TimeToSwitchOffAntennaport5     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 170))
#define cfgidKRAILED2TimeToSwitchOffAntennaport5     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 171))
#define cfgidKRAILED3TimeToSwitchOffAntennaport5     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 172))
#define cfgidKRAILED4TimeToSwitchOffAntennaport5     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 173))
#define cfgidKRAILED5TimeToSwitchOffAntennaport5     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 174))
#define cfgidKRAILED6TimeToSwitchOffAntennaport5     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 175))
#define cfgidKRAILED7TimeToSwitchOffAntennaport5     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 176))
#define cfgidKRAILED8TimeToSwitchOffAntennaport5     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 177))
#define cfgidKRAILED1OutputFunctionAntennaport6      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 190))
#define cfgidKRAILED2OutputFunctionAntennaport6      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 191))
#define cfgidKRAILED3OutputFunctionAntennaport6      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 192))
#define cfgidKRAILED4OutputFunctionAntennaport6      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 193))
#define cfgidKRAILED5OutputFunctionAntennaport6      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 194))
#define cfgidKRAILED6OutputFunctionAntennaport6      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 195))
#define cfgidKRAILED7OutputFunctionAntennaport6      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 196))
#define cfgidKRAILED8OutputFunctionAntennaport6      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 197))
#define cfgidKRAILED1TimeToSwitchOffAntennaport6     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 200))
#define cfgidKRAILED2TimeToSwitchOffAntennaport6     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 201))
#define cfgidKRAILED3TimeToSwitchOffAntennaport6     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 202))
#define cfgidKRAILED4TimeToSwitchOffAntennaport6     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 203))
#define cfgidKRAILED5TimeToSwitchOffAntennaport6     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 204))
#define cfgidKRAILED6TimeToSwitchOffAntennaport6     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 205))
#define cfgidKRAILED7TimeToSwitchOffAntennaport6     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 206))
#define cfgidKRAILED8TimeToSwitchOffAntennaport6     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 207))
#define cfgidKRAILED1OutputFunctionAntennaport7      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 220))
#define cfgidKRAILED2OutputFunctionAntennaport7      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 221))
#define cfgidKRAILED3OutputFunctionAntennaport7      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 222))
#define cfgidKRAILED4OutputFunctionAntennaport7      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 223))
#define cfgidKRAILED5OutputFunctionAntennaport7      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 224))
#define cfgidKRAILED6OutputFunctionAntennaport7      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 225))
#define cfgidKRAILED7OutputFunctionAntennaport7      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 226))
#define cfgidKRAILED8OutputFunctionAntennaport7      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 227))
#define cfgidKRAILED1TimeToSwitchOffAntennaport7     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 230))
#define cfgidKRAILED2TimeToSwitchOffAntennaport7     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 231))
#define cfgidKRAILED3TimeToSwitchOffAntennaport7     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 232))
#define cfgidKRAILED4TimeToSwitchOffAntennaport7     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 233))
#define cfgidKRAILED5TimeToSwitchOffAntennaport7     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 234))
#define cfgidKRAILED6TimeToSwitchOffAntennaport7     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 235))
#define cfgidKRAILED7TimeToSwitchOffAntennaport7     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 236))
#define cfgidKRAILED8TimeToSwitchOffAntennaport7     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 237))
#define cfgidKRAILED1OutputFunctionAntennaport8      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 250))
#define cfgidKRAILED2OutputFunctionAntennaport8      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 251))
#define cfgidKRAILED3OutputFunctionAntennaport8      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 252))
#define cfgidKRAILED4OutputFunctionAntennaport8      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 253))
#define cfgidKRAILED5OutputFunctionAntennaport8      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 254))
#define cfgidKRAILED6OutputFunctionAntennaport8      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 255))
#define cfgidKRAILED7OutputFunctionAntennaport8      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 256))
#define cfgidKRAILED8OutputFunctionAntennaport8      \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | 257))
#define cfgidKRAILED1TimeToSwitchOffAntennaport8     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 260))
#define cfgidKRAILED2TimeToSwitchOffAntennaport8     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 261))
#define cfgidKRAILED3TimeToSwitchOffAntennaport8     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 262))
#define cfgidKRAILED4TimeToSwitchOffAntennaport8     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 263))
#define cfgidKRAILED5TimeToSwitchOffAntennaport8     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 264))
#define cfgidKRAILED6TimeToSwitchOffAntennaport8     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 265))
#define cfgidKRAILED7TimeToSwitchOffAntennaport8     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 266))
#define cfgidKRAILED8TimeToSwitchOffAntennaport8     \
  ((TDWord)(CFGID_GROUP_KRAI | CFGID_SIGN_UNSIGNED | \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | 267))

// Gruppe GPIO

#define cfgidGPIOInvertInput1                              \
  ((TDWord)(CFGID_GROUP_GPIO | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BOOL | CFGID_UNIT_NONE | \
            0))  // Generation 3
#define cfgidGPIOInvertInput2                              \
  ((TDWord)(CFGID_GROUP_GPIO | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BOOL | CFGID_UNIT_NONE | \
            1))  // Generation 3
#define cfgidGPIOInvertInput3                              \
  ((TDWord)(CFGID_GROUP_GPIO | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BOOL | CFGID_UNIT_NONE | \
            2))  // Generation 3
#define cfgidGPIOInvertInput4                              \
  ((TDWord)(CFGID_GROUP_GPIO | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BOOL | CFGID_UNIT_NONE | \
            3))  // Generation 3
#define cfgidGPIOInvertInput5                              \
  ((TDWord)(CFGID_GROUP_GPIO | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BOOL | CFGID_UNIT_NONE | \
            4))  // Generation 3
#define cfgidGPIOInvertInput6                              \
  ((TDWord)(CFGID_GROUP_GPIO | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BOOL | CFGID_UNIT_NONE | \
            5))  // Generation 3
#define cfgidGPIOInvertInput7                              \
  ((TDWord)(CFGID_GROUP_GPIO | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BOOL | CFGID_UNIT_NONE | \
            6))  // Generation 3
#define cfgidGPIOInvertInput8                              \
  ((TDWord)(CFGID_GROUP_GPIO | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BOOL | CFGID_UNIT_NONE | \
            7))  // Generation 3
#define cfgidGPIODebounceTimeInput1                           \
  ((TDWord)(CFGID_GROUP_GPIO | CFGID_SIGN_UNSIGNED |          \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | \
            20))  // Generation 3
#define cfgidGPIODebounceTimeInput2                           \
  ((TDWord)(CFGID_GROUP_GPIO | CFGID_SIGN_UNSIGNED |          \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | \
            21))  // Generation 3
#define cfgidGPIODebounceTimeInput3                           \
  ((TDWord)(CFGID_GROUP_GPIO | CFGID_SIGN_UNSIGNED |          \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | \
            22))  // Generation 3
#define cfgidGPIODebounceTimeInput4                           \
  ((TDWord)(CFGID_GROUP_GPIO | CFGID_SIGN_UNSIGNED |          \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | \
            23))  // Generation 3
#define cfgidGPIODebounceTimeInput5                           \
  ((TDWord)(CFGID_GROUP_GPIO | CFGID_SIGN_UNSIGNED |          \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | \
            24))  // Generation 3
#define cfgidGPIODebounceTimeInput6                           \
  ((TDWord)(CFGID_GROUP_GPIO | CFGID_SIGN_UNSIGNED |          \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | \
            25))  // Generation 3
#define cfgidGPIODebounceTimeInput7                           \
  ((TDWord)(CFGID_GROUP_GPIO | CFGID_SIGN_UNSIGNED |          \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | \
            26))  // Generation 3
#define cfgidGPIODebounceTimeInput8                           \
  ((TDWord)(CFGID_GROUP_GPIO | CFGID_SIGN_UNSIGNED |          \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | \
            27))  // Generation 3
#define cfgidGPIOInvertOutput1                             \
  ((TDWord)(CFGID_GROUP_GPIO | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BOOL | CFGID_UNIT_NONE | \
            40))  // Generation 3
#define cfgidGPIOInvertOutput2                             \
  ((TDWord)(CFGID_GROUP_GPIO | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BOOL | CFGID_UNIT_NONE | \
            41))  // Generation 3
#define cfgidGPIOInvertOutput3                             \
  ((TDWord)(CFGID_GROUP_GPIO | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BOOL | CFGID_UNIT_NONE | \
            42))  // Generation 3
#define cfgidGPIOInvertOutput4                             \
  ((TDWord)(CFGID_GROUP_GPIO | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BOOL | CFGID_UNIT_NONE | \
            43))  // Generation 3
#define cfgidGPIOInvertOutput5                             \
  ((TDWord)(CFGID_GROUP_GPIO | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BOOL | CFGID_UNIT_NONE | \
            44))  // Generation 3
#define cfgidGPIOInvertOutput6                             \
  ((TDWord)(CFGID_GROUP_GPIO | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BOOL | CFGID_UNIT_NONE | \
            45))  // Generation 3
#define cfgidGPIOInvertOutput7                             \
  ((TDWord)(CFGID_GROUP_GPIO | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BOOL | CFGID_UNIT_NONE | \
            46))  // Generation 3
#define cfgidGPIOInvertOutput8                             \
  ((TDWord)(CFGID_GROUP_GPIO | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BOOL | CFGID_UNIT_NONE | \
            47))  // Generation 3
#define cfgidGPIOFunctionOutput1                           \
  ((TDWord)(CFGID_GROUP_GPIO | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            60))  // Generation 3
#define cfgidGPIOFunctionOutput2                           \
  ((TDWord)(CFGID_GROUP_GPIO | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            61))  // Generation 3
#define cfgidGPIOFunctionOutput3                           \
  ((TDWord)(CFGID_GROUP_GPIO | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            62))  // Generation 3
#define cfgidGPIOFunctionOutput4                           \
  ((TDWord)(CFGID_GROUP_GPIO | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            63))  // Generation 3
#define cfgidGPIOFunctionOutput5                           \
  ((TDWord)(CFGID_GROUP_GPIO | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            64))  // Generation 3
#define cfgidGPIOFunctionOutput6                           \
  ((TDWord)(CFGID_GROUP_GPIO | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            65))  // Generation 3
#define cfgidGPIOFunctionOutput7                           \
  ((TDWord)(CFGID_GROUP_GPIO | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            66))  // Generation 3
#define cfgidGPIOFunctionOutput8                           \
  ((TDWord)(CFGID_GROUP_GPIO | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            67))  // Generation 3
#define cfgidGPIOFunctionFirstAntennaPortOutput1           \
  ((TDWord)(CFGID_GROUP_GPIO | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            80))  // Generation 3
#define cfgidGPIOFunctionFirstAntennaPortOutput2           \
  ((TDWord)(CFGID_GROUP_GPIO | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            81))  // Generation 3
#define cfgidGPIOFunctionFirstAntennaPortOutput3           \
  ((TDWord)(CFGID_GROUP_GPIO | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            82))  // Generation 3
#define cfgidGPIOFunctionFirstAntennaPortOutput4           \
  ((TDWord)(CFGID_GROUP_GPIO | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            83))  // Generation 3
#define cfgidGPIOFunctionFirstAntennaPortOutput5           \
  ((TDWord)(CFGID_GROUP_GPIO | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            84))  // Generation 3
#define cfgidGPIOFunctionFirstAntennaPortOutput6           \
  ((TDWord)(CFGID_GROUP_GPIO | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            85))  // Generation 3
#define cfgidGPIOFunctionFirstAntennaPortOutput7           \
  ((TDWord)(CFGID_GROUP_GPIO | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            86))  // Generation 3
#define cfgidGPIOFunctionFirstAntennaPortOutput8           \
  ((TDWord)(CFGID_GROUP_GPIO | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            87))  // Generation 3
#define cfgidGPIOFunctionLastAntennaPortOutput1            \
  ((TDWord)(CFGID_GROUP_GPIO | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            100))  // Generation 3
#define cfgidGPIOFunctionLastAntennaPortOutput2            \
  ((TDWord)(CFGID_GROUP_GPIO | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            101))  // Generation 3
#define cfgidGPIOFunctionLastAntennaPortOutput3            \
  ((TDWord)(CFGID_GROUP_GPIO | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            102))  // Generation 3
#define cfgidGPIOFunctionLastAntennaPortOutput4            \
  ((TDWord)(CFGID_GROUP_GPIO | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            103))  // Generation 3
#define cfgidGPIOFunctionLastAntennaPortOutput5            \
  ((TDWord)(CFGID_GROUP_GPIO | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            104))  // Generation 3
#define cfgidGPIOFunctionLastAntennaPortOutput6            \
  ((TDWord)(CFGID_GROUP_GPIO | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            105))  // Generation 3
#define cfgidGPIOFunctionLastAntennaPortOutput7            \
  ((TDWord)(CFGID_GROUP_GPIO | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            106))  // Generation 3
#define cfgidGPIOFunctionLastAntennaPortOutput8            \
  ((TDWord)(CFGID_GROUP_GPIO | CFGID_SIGN_UNSIGNED |       \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            107))  // Generation 3
#define cfgidGPIOFunctionTimeToSwitchOffOutput1               \
  ((TDWord)(CFGID_GROUP_GPIO | CFGID_SIGN_UNSIGNED |          \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | \
            120))  // Generation 3
#define cfgidGPIOFunctionTimeToSwitchOffOutput2               \
  ((TDWord)(CFGID_GROUP_GPIO | CFGID_SIGN_UNSIGNED |          \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | \
            121))  // Generation 3
#define cfgidGPIOFunctionTimeToSwitchOffOutput3               \
  ((TDWord)(CFGID_GROUP_GPIO | CFGID_SIGN_UNSIGNED |          \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | \
            122))  // Generation 3
#define cfgidGPIOFunctionTimeToSwitchOffOutput4               \
  ((TDWord)(CFGID_GROUP_GPIO | CFGID_SIGN_UNSIGNED |          \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | \
            123))  // Generation 3
#define cfgidGPIOFunctionTimeToSwitchOffOutput5               \
  ((TDWord)(CFGID_GROUP_GPIO | CFGID_SIGN_UNSIGNED |          \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | \
            124))  // Generation 3
#define cfgidGPIOFunctionTimeToSwitchOffOutput6               \
  ((TDWord)(CFGID_GROUP_GPIO | CFGID_SIGN_UNSIGNED |          \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | \
            125))  // Generation 3
#define cfgidGPIOFunctionTimeToSwitchOffOutput7               \
  ((TDWord)(CFGID_GROUP_GPIO | CFGID_SIGN_UNSIGNED |          \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | \
            126))  // Generation 3
#define cfgidGPIOFunctionTimeToSwitchOffOutput8               \
  ((TDWord)(CFGID_GROUP_GPIO | CFGID_SIGN_UNSIGNED |          \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | \
            127))  // Generation 3

// Gruppe LED

#define cfgidLEDColourLED1                                  \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |         \
            CFGID_DATATYPEANDSIZE_DWORD | CFGID_UNIT_NONE | \
            0))  // Generation 3
#define cfgidLEDColourLED2                                  \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |         \
            CFGID_DATATYPEANDSIZE_DWORD | CFGID_UNIT_NONE | \
            1))  // Generation 3
#define cfgidLEDColourLED3                                  \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |         \
            CFGID_DATATYPEANDSIZE_DWORD | CFGID_UNIT_NONE | \
            2))  // Generation 3
#define cfgidLEDColourLED4                                  \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |         \
            CFGID_DATATYPEANDSIZE_DWORD | CFGID_UNIT_NONE | \
            3))  // Generation 3
#define cfgidLEDColourLED5                                  \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |         \
            CFGID_DATATYPEANDSIZE_DWORD | CFGID_UNIT_NONE | \
            4))  // Generation 3
#define cfgidLEDColourLED6                                  \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |         \
            CFGID_DATATYPEANDSIZE_DWORD | CFGID_UNIT_NONE | \
            5))  // Generation 3
#define cfgidLEDColourLED7                                  \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |         \
            CFGID_DATATYPEANDSIZE_DWORD | CFGID_UNIT_NONE | \
            6))  // Generation 3
#define cfgidLEDColourLED8                                  \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |         \
            CFGID_DATATYPEANDSIZE_DWORD | CFGID_UNIT_NONE | \
            7))  // Generation 3
#define cfgidLEDColourLED9                                  \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |         \
            CFGID_DATATYPEANDSIZE_DWORD | CFGID_UNIT_NONE | \
            8))  // Generation 3
#define cfgidLEDColourLED10                                 \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |         \
            CFGID_DATATYPEANDSIZE_DWORD | CFGID_UNIT_NONE | \
            9))  // Generation 3
#define cfgidLEDColourLED11                                 \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |         \
            CFGID_DATATYPEANDSIZE_DWORD | CFGID_UNIT_NONE | \
            10))  // Generation 3
#define cfgidLEDColourLED12                                 \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |         \
            CFGID_DATATYPEANDSIZE_DWORD | CFGID_UNIT_NONE | \
            11))  // Generation 3
#define cfgidLEDFunctionLED1                               \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |        \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            20))  // Generation 3
#define cfgidLEDFunctionLED2                               \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |        \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            21))  // Generation 3
#define cfgidLEDFunctionLED3                               \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |        \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            22))  // Generation 3
#define cfgidLEDFunctionLED4                               \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |        \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            23))  // Generation 3
#define cfgidLEDFunctionLED5                               \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |        \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            24))  // Generation 3
#define cfgidLEDFunctionLED6                               \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |        \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            25))  // Generation 3
#define cfgidLEDFunctionLED7                               \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |        \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            26))  // Generation 3
#define cfgidLEDFunctionLED8                               \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |        \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            27))  // Generation 3
#define cfgidLEDFunctionLED9                               \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |        \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            28))  // Generation 3
#define cfgidLEDFunctionLED10                              \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |        \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            29))  // Generation 3
#define cfgidLEDFunctionLED11                              \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |        \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            30))  // Generation 3
#define cfgidLEDFunctionLED12                              \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |        \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            31))  // Generation 3
#define cfgidLEDFunctionFirstAntennaPortLED1               \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |        \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            40))  // Generation 3
#define cfgidLEDFunctionFirstAntennaPortLED2               \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |        \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            41))  // Generation 3
#define cfgidLEDFunctionFirstAntennaPortLED3               \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |        \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            42))  // Generation 3
#define cfgidLEDFunctionFirstAntennaPortLED4               \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |        \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            43))  // Generation 3
#define cfgidLEDFunctionFirstAntennaPortLED5               \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |        \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            44))  // Generation 3
#define cfgidLEDFunctionFirstAntennaPortLED6               \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |        \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            45))  // Generation 3
#define cfgidLEDFunctionFirstAntennaPortLED7               \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |        \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            46))  // Generation 3
#define cfgidLEDFunctionFirstAntennaPortLED8               \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |        \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            47))  // Generation 3
#define cfgidLEDFunctionFirstAntennaPortLED9               \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |        \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            48))  // Generation 3
#define cfgidLEDFunctionFirstAntennaPortLED10              \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |        \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            49))  // Generation 3
#define cfgidLEDFunctionFirstAntennaPortLED11              \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |        \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            50))  // Generation 3
#define cfgidLEDFunctionFirstAntennaPortLED12              \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |        \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            51))  // Generation 3
#define cfgidLEDFunctionLastAntennaPortLED1                \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |        \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            60))  // Generation 3
#define cfgidLEDFunctionLastAntennaPortLED2                \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |        \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            61))  // Generation 3
#define cfgidLEDFunctionLastAntennaPortLED3                \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |        \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            62))  // Generation 3
#define cfgidLEDFunctionLastAntennaPortLED4                \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |        \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            63))  // Generation 3
#define cfgidLEDFunctionLastAntennaPortLED5                \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |        \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            64))  // Generation 3
#define cfgidLEDFunctionLastAntennaPortLED6                \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |        \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            65))  // Generation 3
#define cfgidLEDFunctionLastAntennaPortLED7                \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |        \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            66))  // Generation 3
#define cfgidLEDFunctionLastAntennaPortLED8                \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |        \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            67))  // Generation 3
#define cfgidLEDFunctionLastAntennaPortLED9                \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |        \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            68))  // Generation 3
#define cfgidLEDFunctionLastAntennaPortLED10               \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |        \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            69))  // Generation 3
#define cfgidLEDFunctionLastAntennaPortLED11               \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |        \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            70))  // Generation 3
#define cfgidLEDFunctionLastAntennaPortLED12               \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |        \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_NONE | \
            71))  // Generation 3
#define cfgidLEDFunctionTimeToSwitchOffLED1                   \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |           \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | \
            80))  // Generation 3
#define cfgidLEDFunctionTimeToSwitchOffLED2                   \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |           \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | \
            81))  // Generation 3
#define cfgidLEDFunctionTimeToSwitchOffLED3                   \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |           \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | \
            82))  // Generation 3
#define cfgidLEDFunctionTimeToSwitchOffLED4                   \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |           \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | \
            83))  // Generation 3
#define cfgidLEDFunctionTimeToSwitchOffLED5                   \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |           \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | \
            84))  // Generation 3
#define cfgidLEDFunctionTimeToSwitchOffLED6                   \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |           \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | \
            85))  // Generation 3
#define cfgidLEDFunctionTimeToSwitchOffLED7                   \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |           \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | \
            86))  // Generation 3
#define cfgidLEDFunctionTimeToSwitchOffLED8                   \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |           \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | \
            87))  // Generation 3
#define cfgidLEDFunctionTimeToSwitchOffLED9                   \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |           \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | \
            88))  // Generation 3
#define cfgidLEDFunctionTimeToSwitchOffLED10                  \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |           \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | \
            89))  // Generation 3
#define cfgidLEDFunctionTimeToSwitchOffLED11                  \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |           \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | \
            90))  // Generation 3
#define cfgidLEDFunctionTimeToSwitchOffLED12                  \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |           \
            CFGID_DATATYPEANDSIZE_WORD | CFGID_UNIT_MSECOND | \
            91))  // Generation 3
#define cfgidLEDBrightness                                    \
  ((TDWord)(CFGID_GROUP_LED | CFGID_SIGN_UNSIGNED |           \
            CFGID_DATATYPEANDSIZE_BYTE | CFGID_UNIT_PERCENT | \
            100))  // Generation 3

// Gruppe RESERVED

#define cfgidSkidataAllowAllTags                           \
  ((TDWord)(CFGID_GROUP_RESERVED | CFGID_SIGN_UNSIGNED |   \
            CFGID_DATATYPEANDSIZE_BOOL | CFGID_UNIT_NONE | \
            100))  // Generation 2

// ===========================================================================

#endif
