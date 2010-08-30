/*
 * TI's FM Stack
 *
 * Copyright 2001-2010 Texas Instruments, Inc. - http://www.ti.com/
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#include "fmc_debug.h"
#include "fmc_defs.h"
#include "fmc_types.h"
#include "fmc_utils.h"
#include "fm_rx.h"
#include "fm_tx.h"
#include "fmc_defs.h"
 

/* Global variable for all the debug functions bellow */
#define MAX_FMC_TMP_STR_SIZE    27
FMC_STATIC  char	tempStr[MAX_FMC_TMP_STR_SIZE+1];

const char *FMC_DEBUG_FmcStatusStr(FMC_UINT status)
{
	
	switch (status)
	{
			case FMC_STATUS_SUCCESS:			return "SUCCESS";
			case FMC_STATUS_FAILED:			return "FAILED";
			case FMC_STATUS_PENDING:			return "PENDING";
			case FMC_STATUS_INVALID_PARM:			return "INVALID_PARM";
			case FMC_STATUS_IN_PROGRESS:			return "IN_PROGRESS";
			case FMC_STATUS_NOT_APPLICABLE:			return "NOT_APPLICABLE";
			case FMC_STATUS_NOT_SUPPORTED:			return "NOT_SUPPORTED";
			case FMC_STATUS_INTERNAL_ERROR:			return "INTERNAL_ERROR";
			case FMC_STATUS_TRANSPORT_INIT_ERR:			return "TRANSPORT_INIT_ERR";
			case FMC_STATUS_HARDWARE_ERR:			return "HARDWARE_ERR";
			case FMC_STATUS_NO_VALUE_AVAILABLE:			return "NO_VALUE_AVAILABLE";
			case FMC_STATUS_CONTEXT_DOESNT_EXIST:			return "CONTEXT_DOESNT_EXIST";
			case FMC_STATUS_CONTEXT_NOT_DESTROYED:			return "CONTEXT_NOT_DESTROYED";
			case FMC_STATUS_CONTEXT_NOT_ENABLED:			return "CONTEXT_NOT_ENABLED";
			case FMC_STATUS_CONTEXT_NOT_DISABLED:			return "CONTEXT_NOT_DISABLED";
			case FMC_STATUS_NOT_DE_INITIALIZED:			return "NOT_DE_INITIALIZED";
			case FMC_STATUS_NOT_INITIALIZED:			return "NOT_INITIALIZED";
			case FMC_STATUS_TOO_MANY_PENDING_CMDS:			return "TOO_MANY_PENDING_CMDS";
			case FMC_STATUS_DISABLING_IN_PROGRESS:			return "DISABLING_IN_PROGRESS";
			case FMC_STATUS_NO_RESOURCES:			return "NO_RESOURCES";
			case FMC_STATUS_FM_COMMAND_FAILED:			return "FM_COMMAND_FAILED";
			case FMC_STATUS_AUDIO_OPERATION_UNAVAILIBLE_RESOURCES:			return "FMC_STATUS_AUDIO_OPERATION_UNAVAILIBLE_RESOURCES";
			default:											return FMC_UTILS_FormatNumber("INVALID Status:%x", status, tempStr,MAX_FMC_TMP_STR_SIZE);
	}
}

const char *FMC_DEBUG_FmTxStatusStr(FMC_UINT status)
{
	
	if (status <= FMC_STATUS_LAST)
	{
		return FMC_DEBUG_FmcStatusStr(status);
	}

	switch (status)
	{
		case FM_TX_STATUS_RDS_NOT_ENABLED: return "STATUS_RDS_NOT_ENABLED";
		case FM_TX_STATUS_TRANSMITTER_NOT_TUNED: return "STATUS_TRANSMITTER_NOT_TUNED";
		case FM_TX_STATUS_TRANSMISSION_IS_NOT_ON: return "STATUS_TRANSMISSION_IS_NOT_ON";
		case FM_TX_STATUS_FM_RX_ALREADY_ENABLED: return "STATUS_FM_RX_ALREADY_ENABLED";
		case FM_TX_STATUS_AUTO_MODE_NOT_ON: return "STATUS_AUTO_MODE_NOT_ON";
		case FM_TX_STATUS_RDS_AUTO_MODE_NOT_ON: return "STATUS_RDS_AUTO_MODE_NOT_ON";
		case FM_TX_STATUS_RDS_MANUAL_MODE_NOT_ON: return "STATUS_RDS_MANUAL_MODE_NOT_ON";
		case FM_TX_STATUS_CONFLICTING_RDS_CMD_IN_PROGRESS: return "STATUS_CONFLICTING_RDS_CMD_IN_PROGRESS";
		case FM_TX_STATUS_AUDIO_OPERATION_UNAVAILIBLE_RESOURCES: return "FM_TX_STATUS_AUDIO_OPERATION_UNAVAILIBLE_RESOURCES";
		default:											return FMC_UTILS_FormatNumber("INVALID Status:%x", status, tempStr,MAX_FMC_TMP_STR_SIZE);
	}
}

const char *FMC_DEBUG_FmTxCmdStr(FMC_UINT cmdType)
{
	
	switch (cmdType) {
		case FM_TX_CMD_DESTROY:	return "DESTROY";
		case FM_TX_CMD_ENABLE:	return "ENABLE";
		case FM_TX_CMD_DISABLE:	return "DISABLE";
		case FM_TX_CMD_START_TRANSMISSION:	return "START_TRANSMISSION";
		case FM_TX_CMD_STOP_TRANSMISSION:	return "STOP_TRANSMISSION";
		case FM_TX_CMD_TUNE:	return "TUNE";
		case FM_TX_CMD_GET_TUNED_FREQUENCY:	return "GET_TUNED_FREQUENCY";
		case FM_TX_CMD_SET_MONO_STEREO_MODE:	return "SET_MONO_STEREO_MODE";
		case FM_TX_CMD_GET_MONO_STEREO_MODE:	return "GET_MONO_STEREO_MODE";
		case FM_TX_CMD_SET_POWER_LEVEL:	return "SET_POWER_LEVEL";
		case FM_TX_CMD_GET_POWER_LEVEL:	return "GET_POWER_LEVEL";
		case FM_TX_CMD_SET_MUTE_MODE:	return "SET_MUTE_MODE";
		case FM_TX_CMD_GET_MUTE_MODE:	return "GET_MUTE_MODE";
		case FM_TX_CMD_ENABLE_RDS:	return "ENABLE_RDS";
		case FM_TX_CMD_DISABLE_RDS:	return "DISABLE_RDS";
		case FM_TX_CMD_SET_RDS_TRANSMISSION_MODE:	return "SET_RDS_TRANSMISSION_MODE";
		case FM_TX_CMD_GET_RDS_TRANSMISSION_MODE:	return "GET_RDS_TRANSMISSION_MODE";
		case FM_TX_CMD_SET_RDS_AF_CODE:	return "SET_RDS_AF_CODE";
		case FM_TX_CMD_GET_RDS_AF_CODE:	return "GET_RDS_AF_CODE";
		case FM_TX_CMD_SET_RDS_PI_CODE:	return "SET_RDS_PI_CODE";
		case FM_TX_CMD_GET_RDS_PI_CODE:	return "GET_RDS_PI_CODE";
		case FM_TX_CMD_SET_RDS_PTY_CODE:	return "SET_RDS_PTY_CODE";
		case FM_TX_CMD_GET_RDS_PTY_CODE:	return "GET_RDS_PTY_CODE";
		case FM_TX_CMD_SET_RDS_TEXT_REPERTOIRE:	return "SET_RDS_TEXT_REPERTOIRE";
		case FM_TX_CMD_GET_RDS_TEXT_REPERTOIRE:	return "GET_RDS_TEXT_REPERTOIRE";
		case FM_TX_CMD_SET_RDS_PS_DISPLAY_MODE:	return "SET_RDS_PS_DISPLAY_MODE";
		case FM_TX_CMD_GET_RDS_PS_DISPLAY_MODE:	return "GET_RDS_PS_DISPLAY_MODE";
		case FM_TX_CMD_SET_RDS_PS_DISPLAY_SPEED:	return "SET_RDS_TEXT_SCROLL_PARMS";
		case FM_TX_CMD_GET_RDS_PS_DISPLAY_SPEED:	return "GET_RDS_TEXT_SCROLL_PARMS";
		case FM_TX_CMD_SET_RDS_TEXT_PS_MSG:	return "SET_RDS_TEXT_PS_MSG";
		case FM_TX_CMD_GET_RDS_TEXT_PS_MSG:	return "GET_RDS_TEXT_PS_MSG";
		case FM_TX_CMD_SET_RDS_TEXT_RT_MSG:	return "SET_RDS_TEXT_RT_MSG";
		case FM_TX_CMD_GET_RDS_TEXT_RT_MSG:	return "GET_RDS_TEXT_RT_MSG";
		case FM_TX_CMD_SET_RDS_TRANSMITTED_MASK:	return "SET_RDS_TRANSMITTED_MASK";
		case FM_TX_CMD_GET_RDS_TRANSMITTED_MASK:	return "GET_RDS_TRANSMITTED_MASK";
		case FM_TX_CMD_SET_RDS_TRAFFIC_CODES:	return "SET_RDS_TRAFFIC_CODES";
		case FM_TX_CMD_GET_RDS_TRAFFIC_CODES:	return "GET_RDS_TRAFFIC_CODES";
		case FM_TX_CMD_SET_RDS_MUSIC_SPEECH_FLAG:	return "SET_RDS_MUSIC_SPEECH_FLAG";
		case FM_TX_CMD_GET_RDS_MUSIC_SPEECH_FLAG:	return "GET_RDS_MUSIC_SPEECH_FLAG";
		case FM_TX_CMD_SET_PRE_EMPHASIS_FILTER:	return "SET_PRE_EMPHASIS_FILTER";
		case FM_TX_CMD_GET_PRE_EMPHASIS_FILTER:	return "GET_PRE_EMPHASIS_FILTER";
		case FM_TX_CMD_SET_RDS_EXTENDED_COUNTRY_CODE:	return "SET_RDS_EXTENDED_COUNTRY_CODE";
		case FM_TX_CMD_GET_RDS_EXTENDED_COUNTRY_CODE:	return "GET_RDS_EXTENDED_COUNTRY_CODE";
		case FM_TX_CMD_WRITE_RDS_RAW_DATA:	return "WRITE_RDS_RAW_DATA";
		case FM_TX_CMD_CHANGE_AUDIO_SOURCE:	return "FM_TX_CMD_CHANGE_AUDIO_SOURCE";
		case FM_TX_CMD_CHANGE_DIGITAL_AUDIO_CONFIGURATION:	return "FM_TX_CMD_CHANGE_DIGITAL_AUDIO_CONFIGURATION";
		default:											return FMC_UTILS_FormatNumber("INVALID Cmd:%x", cmdType, tempStr,MAX_FMC_TMP_STR_SIZE);
		}
}
const char *FMC_DEBUG_FmRxCmdStr(FMC_UINT cmdType)
{
	
	
	switch (cmdType) {
		case FM_RX_CMD_ENABLE: return "FM_RX_CMD_ENABLE";
		case FM_RX_CMD_DISABLE:	return "FM_RX_CMD_DISABLE";
		case FM_RX_CMD_SET_BAND: return "FM_RX_CMD_SET_BAND";
		case FM_RX_CMD_GET_BAND:	return "FM_RX_CMD_GET_BAND";
		case FM_RX_CMD_SET_MONO_STEREO_MODE:	return "FM_RX_CMD_SET_MONO_STEREO_MODE";
		case FM_RX_CMD_GET_MONO_STEREO_MODE:	return "FM_RX_CMD_GET_MONO_STEREO_MODE";
		case FM_RX_CMD_SET_MUTE_MODE: return "FM_RX_CMD_SET_MUTE_MODE";
		case FM_RX_CMD_GET_MUTE_MODE:	return "FM_RX_CMD_GET_MUTE_MODE";
		case FM_RX_CMD_SET_RF_DEPENDENT_MUTE_MODE:	return "FM_RX_CMD_SET_RF_DEPENDENT_MUTE_MODE";
		case FM_RX_CMD_GET_RF_DEPENDENT_MUTE_MODE: return "FM_RX_CMD_GET_RF_DEPENDENT_MUTE_MODE";
		case FM_RX_CMD_SET_RSSI_THRESHOLD: return "FM_RX_CMD_SET_RSSI_THRESHOLD";
		case FM_RX_CMD_GET_RSSI_THRESHOLD:	return "FM_RX_CMD_GET_RSSI_THRESHOLD";
		case FM_RX_CMD_SET_DEEMPHASIS_FILTER:	return "FM_RX_CMD_SET_DEEMPHASIS_FILTER";
		case FM_RX_CMD_GET_DEEMPHASIS_FILTER:	return "FM_RX_CMD_GET_DEEMPHASIS_FILTER";
		case FM_RX_CMD_SET_VOLUME: return "FM_RX_CMD_SET_VOLUME";
		case FM_RX_CMD_GET_VOLUME:	return "FM_RX_CMD_GET_VOLUME";
		case FM_RX_CMD_TUNE:	return "FM_RX_CMD_TUNE";
		case FM_RX_CMD_GET_TUNED_FREQUENCY: return "FM_RX_CMD_GET_TUNED_FREQUENCY";
		case FM_RX_CMD_SEEK: return "FM_RX_CMD_SEEK";
		case FM_RX_CMD_STOP_SEEK: return "FM_RX_CMD_STOP_SEEK";
		case FM_RX_CMD_GET_RSSI: return "FM_RX_CMD_GET_RSSI";
		case FM_RX_CMD_ENABLE_RDS:	return "FM_RX_CMD_ENABLE_RDS";
		case FM_RX_CMD_DISABLE_RDS: return "FM_RX_CMD_DISABLE_RDS";
		case FM_RX_CMD_SET_RDS_SYSTEM: return "FM_RX_CMD_SET_RDS_SYSTEM";
		case FM_RX_CMD_GET_RDS_SYSTEM: return "FM_RX_CMD_GET_RDS_SYSTEM";
		case FM_RX_CMD_SET_RDS_GROUP_MASK: return "FM_RX_CMD_SET_RDS_GROUP_MASK";
		case FM_RX_CMD_GET_RDS_GROUP_MASK:	return "FM_RX_CMD_GET_RDS_GROUP_MASK";
		case FM_RX_CMD_SET_RDS_AF_SWITCH_MODE:	return "FM_RX_CMD_SET_RDS_AF_SWITCH_MODE";
		case FM_RX_CMD_GET_RDS_AF_SWITCH_MODE: return "FM_RX_CMD_GET_RDS_AF_SWITCH_MODE";
		case FM_RX_CMD_ENABLE_AUDIO: return "FM_RX_CMD_ENABLE_AUDIO";
		case FM_RX_CMD_DISABLE_AUDIO: return "FM_RX_CMD_DISABLE_AUDIO";
		case FM_RX_CMD_CHANGE_AUDIO_TARGET: return "FM_RX_CMD_CHANGE_AUDIO_TARGET";
		case FM_RX_CMD_CHANGE_DIGITAL_AUDIO_CONFIGURATION:	return "FM_RX_CMD_CHANGE_DIGITAL_AUDIO_CONFIGURATION";
		case FM_RX_CMD_DESTROY: return "FM_RX_CMD_DESTROY";
		default:											return FMC_UTILS_FormatNumber("INVALID Cmd:%x", cmdType, tempStr,MAX_FMC_TMP_STR_SIZE);
		}
}
const char *FMC_DEBUG_BandStr(FMC_UINT band)
{
	
	switch (band) {
		case FMC_BAND_EUROPE_US:	return "Europe / US";
		case FMC_BAND_JAPAN	:		return "Japan";
		default:						return FMC_UTILS_FormatNumber("INVALID Band:%x", band, tempStr,MAX_FMC_TMP_STR_SIZE);
	}
}

