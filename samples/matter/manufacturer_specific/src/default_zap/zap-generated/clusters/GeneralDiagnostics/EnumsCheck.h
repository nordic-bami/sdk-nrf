/*
 *
 *    Copyright (c) 2022 Project CHIP Authors
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

// THIS FILE IS GENERATED BY ZAP
// This file is generated from clusters-Enums-Check.h.zapt

#pragma once

#include <clusters/GeneralDiagnostics/Enums.h>

namespace chip
{
namespace app
{
	namespace Clusters
	{
		static auto __attribute__((unused)) EnsureKnownEnumValue(GeneralDiagnostics::BootReasonEnum val)
		{
			using EnumType = GeneralDiagnostics::BootReasonEnum;
			switch (val) {
			case EnumType::kUnspecified:
			case EnumType::kPowerOnReboot:
			case EnumType::kBrownOutReset:
			case EnumType::kSoftwareWatchdogReset:
			case EnumType::kHardwareWatchdogReset:
			case EnumType::kSoftwareUpdateCompleted:
			case EnumType::kSoftwareReset:
				return val;
			default:
				return EnumType::kUnknownEnumValue;
			}
		}
		static auto __attribute__((unused)) EnsureKnownEnumValue(GeneralDiagnostics::HardwareFaultEnum val)
		{
			using EnumType = GeneralDiagnostics::HardwareFaultEnum;
			switch (val) {
			case EnumType::kUnspecified:
			case EnumType::kRadio:
			case EnumType::kSensor:
			case EnumType::kResettableOverTemp:
			case EnumType::kNonResettableOverTemp:
			case EnumType::kPowerSource:
			case EnumType::kVisualDisplayFault:
			case EnumType::kAudioOutputFault:
			case EnumType::kUserInterfaceFault:
			case EnumType::kNonVolatileMemoryError:
			case EnumType::kTamperDetected:
				return val;
			default:
				return EnumType::kUnknownEnumValue;
			}
		}
		static auto __attribute__((unused)) EnsureKnownEnumValue(GeneralDiagnostics::InterfaceTypeEnum val)
		{
			using EnumType = GeneralDiagnostics::InterfaceTypeEnum;
			switch (val) {
			case EnumType::kUnspecified:
			case EnumType::kWiFi:
			case EnumType::kEthernet:
			case EnumType::kCellular:
			case EnumType::kThread:
				return val;
			default:
				return EnumType::kUnknownEnumValue;
			}
		}
		static auto __attribute__((unused)) EnsureKnownEnumValue(GeneralDiagnostics::NetworkFaultEnum val)
		{
			using EnumType = GeneralDiagnostics::NetworkFaultEnum;
			switch (val) {
			case EnumType::kUnspecified:
			case EnumType::kHardwareFailure:
			case EnumType::kNetworkJammed:
			case EnumType::kConnectionFailed:
				return val;
			default:
				return EnumType::kUnknownEnumValue;
			}
		}
		static auto __attribute__((unused)) EnsureKnownEnumValue(GeneralDiagnostics::RadioFaultEnum val)
		{
			using EnumType = GeneralDiagnostics::RadioFaultEnum;
			switch (val) {
			case EnumType::kUnspecified:
			case EnumType::kWiFiFault:
			case EnumType::kCellularFault:
			case EnumType::kThreadFault:
			case EnumType::kNFCFault:
			case EnumType::kBLEFault:
			case EnumType::kEthernetFault:
				return val;
			default:
				return EnumType::kUnknownEnumValue;
			}
		}
	} // namespace Clusters
} // namespace app
} // namespace chip
