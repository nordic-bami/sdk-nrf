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
// This file is generated from clusters-Attributes.h.zapt

#pragma once

#include <app/ConcreteAttributePath.h>
#include <app/data-model/DecodableList.h>
#include <app/data-model/List.h>
#include <app/data-model/Nullable.h>
#include <app/util/basic-types.h>
#include <lib/core/TLV.h>
#include <lib/support/BitMask.h>

#include <clusters/shared/Attributes.h>
#include <clusters/shared/Enums.h>
#include <clusters/shared/Structs.h>

#include <clusters/BallastConfiguration/AttributeIds.h>
#include <clusters/BallastConfiguration/ClusterId.h>
#include <clusters/BallastConfiguration/Enums.h>
#include <clusters/BallastConfiguration/Structs.h>

namespace chip
{
namespace app
{
	namespace Clusters
	{
		namespace BallastConfiguration
		{
			namespace Attributes
			{

				namespace PhysicalMinLevel
				{
					struct TypeInfo {
						using Type = uint8_t;
						using DecodableType = uint8_t;
						using DecodableArgType = uint8_t;

						static constexpr ClusterId GetClusterId()
						{
							return Clusters::BallastConfiguration::Id;
						}
						static constexpr AttributeId GetAttributeId()
						{
							return Attributes::PhysicalMinLevel::Id;
						}
						static constexpr bool MustUseTimedWrite() { return false; }
					};
				} // namespace PhysicalMinLevel
				namespace PhysicalMaxLevel
				{
					struct TypeInfo {
						using Type = uint8_t;
						using DecodableType = uint8_t;
						using DecodableArgType = uint8_t;

						static constexpr ClusterId GetClusterId()
						{
							return Clusters::BallastConfiguration::Id;
						}
						static constexpr AttributeId GetAttributeId()
						{
							return Attributes::PhysicalMaxLevel::Id;
						}
						static constexpr bool MustUseTimedWrite() { return false; }
					};
				} // namespace PhysicalMaxLevel
				namespace BallastStatus
				{
					struct TypeInfo {
						using Type = chip::BitMask<
							chip::app::Clusters::BallastConfiguration::BallastStatusBitmap>;
						using DecodableType = chip::BitMask<
							chip::app::Clusters::BallastConfiguration::BallastStatusBitmap>;
						using DecodableArgType = chip::BitMask<
							chip::app::Clusters::BallastConfiguration::BallastStatusBitmap>;

						static constexpr ClusterId GetClusterId()
						{
							return Clusters::BallastConfiguration::Id;
						}
						static constexpr AttributeId GetAttributeId()
						{
							return Attributes::BallastStatus::Id;
						}
						static constexpr bool MustUseTimedWrite() { return false; }
					};
				} // namespace BallastStatus
				namespace MinLevel
				{
					struct TypeInfo {
						using Type = uint8_t;
						using DecodableType = uint8_t;
						using DecodableArgType = uint8_t;

						static constexpr ClusterId GetClusterId()
						{
							return Clusters::BallastConfiguration::Id;
						}
						static constexpr AttributeId GetAttributeId()
						{
							return Attributes::MinLevel::Id;
						}
						static constexpr bool MustUseTimedWrite() { return false; }
					};
				} // namespace MinLevel
				namespace MaxLevel
				{
					struct TypeInfo {
						using Type = uint8_t;
						using DecodableType = uint8_t;
						using DecodableArgType = uint8_t;

						static constexpr ClusterId GetClusterId()
						{
							return Clusters::BallastConfiguration::Id;
						}
						static constexpr AttributeId GetAttributeId()
						{
							return Attributes::MaxLevel::Id;
						}
						static constexpr bool MustUseTimedWrite() { return false; }
					};
				} // namespace MaxLevel
				namespace IntrinsicBallastFactor
				{
					struct TypeInfo {
						using Type = chip::app::DataModel::Nullable<uint8_t>;
						using DecodableType = chip::app::DataModel::Nullable<uint8_t>;
						using DecodableArgType =
							const chip::app::DataModel::Nullable<uint8_t> &;

						static constexpr ClusterId GetClusterId()
						{
							return Clusters::BallastConfiguration::Id;
						}
						static constexpr AttributeId GetAttributeId()
						{
							return Attributes::IntrinsicBallastFactor::Id;
						}
						static constexpr bool MustUseTimedWrite() { return false; }
					};
				} // namespace IntrinsicBallastFactor
				namespace BallastFactorAdjustment
				{
					struct TypeInfo {
						using Type = chip::app::DataModel::Nullable<uint8_t>;
						using DecodableType = chip::app::DataModel::Nullable<uint8_t>;
						using DecodableArgType =
							const chip::app::DataModel::Nullable<uint8_t> &;

						static constexpr ClusterId GetClusterId()
						{
							return Clusters::BallastConfiguration::Id;
						}
						static constexpr AttributeId GetAttributeId()
						{
							return Attributes::BallastFactorAdjustment::Id;
						}
						static constexpr bool MustUseTimedWrite() { return false; }
					};
				} // namespace BallastFactorAdjustment
				namespace LampQuantity
				{
					struct TypeInfo {
						using Type = uint8_t;
						using DecodableType = uint8_t;
						using DecodableArgType = uint8_t;

						static constexpr ClusterId GetClusterId()
						{
							return Clusters::BallastConfiguration::Id;
						}
						static constexpr AttributeId GetAttributeId()
						{
							return Attributes::LampQuantity::Id;
						}
						static constexpr bool MustUseTimedWrite() { return false; }
					};
				} // namespace LampQuantity
				namespace LampType
				{
					struct TypeInfo {
						using Type = chip::CharSpan;
						using DecodableType = chip::CharSpan;
						using DecodableArgType = chip::CharSpan;

						static constexpr ClusterId GetClusterId()
						{
							return Clusters::BallastConfiguration::Id;
						}
						static constexpr AttributeId GetAttributeId()
						{
							return Attributes::LampType::Id;
						}
						static constexpr bool MustUseTimedWrite() { return false; }
						static constexpr size_t MaxLength() { return 16; }
					};
				} // namespace LampType
				namespace LampManufacturer
				{
					struct TypeInfo {
						using Type = chip::CharSpan;
						using DecodableType = chip::CharSpan;
						using DecodableArgType = chip::CharSpan;

						static constexpr ClusterId GetClusterId()
						{
							return Clusters::BallastConfiguration::Id;
						}
						static constexpr AttributeId GetAttributeId()
						{
							return Attributes::LampManufacturer::Id;
						}
						static constexpr bool MustUseTimedWrite() { return false; }
						static constexpr size_t MaxLength() { return 16; }
					};
				} // namespace LampManufacturer
				namespace LampRatedHours
				{
					struct TypeInfo {
						using Type = chip::app::DataModel::Nullable<uint32_t>;
						using DecodableType = chip::app::DataModel::Nullable<uint32_t>;
						using DecodableArgType =
							const chip::app::DataModel::Nullable<uint32_t> &;

						static constexpr ClusterId GetClusterId()
						{
							return Clusters::BallastConfiguration::Id;
						}
						static constexpr AttributeId GetAttributeId()
						{
							return Attributes::LampRatedHours::Id;
						}
						static constexpr bool MustUseTimedWrite() { return false; }
					};
				} // namespace LampRatedHours
				namespace LampBurnHours
				{
					struct TypeInfo {
						using Type = chip::app::DataModel::Nullable<uint32_t>;
						using DecodableType = chip::app::DataModel::Nullable<uint32_t>;
						using DecodableArgType =
							const chip::app::DataModel::Nullable<uint32_t> &;

						static constexpr ClusterId GetClusterId()
						{
							return Clusters::BallastConfiguration::Id;
						}
						static constexpr AttributeId GetAttributeId()
						{
							return Attributes::LampBurnHours::Id;
						}
						static constexpr bool MustUseTimedWrite() { return false; }
					};
				} // namespace LampBurnHours
				namespace LampAlarmMode
				{
					struct TypeInfo {
						using Type = chip::BitMask<
							chip::app::Clusters::BallastConfiguration::LampAlarmModeBitmap>;
						using DecodableType = chip::BitMask<
							chip::app::Clusters::BallastConfiguration::LampAlarmModeBitmap>;
						using DecodableArgType = chip::BitMask<
							chip::app::Clusters::BallastConfiguration::LampAlarmModeBitmap>;

						static constexpr ClusterId GetClusterId()
						{
							return Clusters::BallastConfiguration::Id;
						}
						static constexpr AttributeId GetAttributeId()
						{
							return Attributes::LampAlarmMode::Id;
						}
						static constexpr bool MustUseTimedWrite() { return false; }
					};
				} // namespace LampAlarmMode
				namespace LampBurnHoursTripPoint
				{
					struct TypeInfo {
						using Type = chip::app::DataModel::Nullable<uint32_t>;
						using DecodableType = chip::app::DataModel::Nullable<uint32_t>;
						using DecodableArgType =
							const chip::app::DataModel::Nullable<uint32_t> &;

						static constexpr ClusterId GetClusterId()
						{
							return Clusters::BallastConfiguration::Id;
						}
						static constexpr AttributeId GetAttributeId()
						{
							return Attributes::LampBurnHoursTripPoint::Id;
						}
						static constexpr bool MustUseTimedWrite() { return false; }
					};
				} // namespace LampBurnHoursTripPoint
				namespace GeneratedCommandList
				{
					struct TypeInfo
						: public Clusters::Globals::Attributes::GeneratedCommandList::TypeInfo {
						static constexpr ClusterId GetClusterId()
						{
							return Clusters::BallastConfiguration::Id;
						}
					};
				} // namespace GeneratedCommandList
				namespace AcceptedCommandList
				{
					struct TypeInfo
						: public Clusters::Globals::Attributes::AcceptedCommandList::TypeInfo {
						static constexpr ClusterId GetClusterId()
						{
							return Clusters::BallastConfiguration::Id;
						}
					};
				} // namespace AcceptedCommandList
				namespace AttributeList
				{
					struct TypeInfo
						: public Clusters::Globals::Attributes::AttributeList::TypeInfo {
						static constexpr ClusterId GetClusterId()
						{
							return Clusters::BallastConfiguration::Id;
						}
					};
				} // namespace AttributeList
				namespace FeatureMap
				{
					struct TypeInfo : public Clusters::Globals::Attributes::FeatureMap::TypeInfo {
						static constexpr ClusterId GetClusterId()
						{
							return Clusters::BallastConfiguration::Id;
						}
					};
				} // namespace FeatureMap
				namespace ClusterRevision
				{
					struct TypeInfo
						: public Clusters::Globals::Attributes::ClusterRevision::TypeInfo {
						static constexpr ClusterId GetClusterId()
						{
							return Clusters::BallastConfiguration::Id;
						}
					};
				} // namespace ClusterRevision

				struct TypeInfo {
					struct DecodableType {
						static constexpr ClusterId GetClusterId()
						{
							return Clusters::BallastConfiguration::Id;
						}

						CHIP_ERROR Decode(TLV::TLVReader &reader,
								  const ConcreteAttributePath &path);

						Attributes::PhysicalMinLevel::TypeInfo::DecodableType physicalMinLevel =
							static_cast<uint8_t>(0);
						Attributes::PhysicalMaxLevel::TypeInfo::DecodableType physicalMaxLevel =
							static_cast<uint8_t>(0);
						Attributes::BallastStatus::TypeInfo::DecodableType ballastStatus =
							static_cast<
								chip::BitMask<chip::app::Clusters::BallastConfiguration::
										      BallastStatusBitmap>>(0);
						Attributes::MinLevel::TypeInfo::DecodableType minLevel =
							static_cast<uint8_t>(0);
						Attributes::MaxLevel::TypeInfo::DecodableType maxLevel =
							static_cast<uint8_t>(0);
						Attributes::IntrinsicBallastFactor::TypeInfo::DecodableType
							intrinsicBallastFactor;
						Attributes::BallastFactorAdjustment::TypeInfo::DecodableType
							ballastFactorAdjustment;
						Attributes::LampQuantity::TypeInfo::DecodableType lampQuantity =
							static_cast<uint8_t>(0);
						Attributes::LampType::TypeInfo::DecodableType lampType;
						Attributes::LampManufacturer::TypeInfo::DecodableType lampManufacturer;
						Attributes::LampRatedHours::TypeInfo::DecodableType lampRatedHours;
						Attributes::LampBurnHours::TypeInfo::DecodableType lampBurnHours;
						Attributes::LampAlarmMode::TypeInfo::DecodableType lampAlarmMode =
							static_cast<
								chip::BitMask<chip::app::Clusters::BallastConfiguration::
										      LampAlarmModeBitmap>>(0);
						Attributes::LampBurnHoursTripPoint::TypeInfo::DecodableType
							lampBurnHoursTripPoint;
						Attributes::GeneratedCommandList::TypeInfo::DecodableType
							generatedCommandList;
						Attributes::AcceptedCommandList::TypeInfo::DecodableType
							acceptedCommandList;
						Attributes::AttributeList::TypeInfo::DecodableType attributeList;
						Attributes::FeatureMap::TypeInfo::DecodableType featureMap =
							static_cast<uint32_t>(0);
						Attributes::ClusterRevision::TypeInfo::DecodableType clusterRevision =
							static_cast<uint16_t>(0);
					};
				};
			} // namespace Attributes
		} // namespace BallastConfiguration
	} // namespace Clusters
} // namespace app
} // namespace chip
