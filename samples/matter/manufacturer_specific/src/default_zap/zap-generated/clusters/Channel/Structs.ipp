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
// This file is generated from clusters-Structs.ipp.zapt

#include <clusters/Channel/Structs.h>

#include <app/data-model/StructDecodeIterator.h>
#include <app/data-model/WrappedStructEncoder.h>

namespace chip
{
namespace app
{
	namespace Clusters
	{
		namespace Channel
		{
			namespace Structs
			{

				namespace ProgramCastStruct
				{
					CHIP_ERROR Type::Encode(TLV::TLVWriter &aWriter, TLV::Tag aTag) const
					{
						DataModel::WrappedStructEncoder encoder{ aWriter, aTag };
						encoder.Encode(to_underlying(Fields::kName), name);
						encoder.Encode(to_underlying(Fields::kRole), role);
						return encoder.Finalize();
					}

					CHIP_ERROR DecodableType::Decode(TLV::TLVReader &reader)
					{
						detail::StructDecodeIterator __iterator(reader);
						while (true) {
							uint8_t __context_tag = 0;
							CHIP_ERROR err = __iterator.Next(__context_tag);
							VerifyOrReturnError(err != CHIP_ERROR_END_OF_TLV,
									    CHIP_NO_ERROR);
							ReturnErrorOnFailure(err);

							if (__context_tag == to_underlying(Fields::kName)) {
								err = DataModel::Decode(reader, name);
							} else if (__context_tag == to_underlying(Fields::kRole)) {
								err = DataModel::Decode(reader, role);
							}

							ReturnErrorOnFailure(err);
						}
					}

				} // namespace ProgramCastStruct

				namespace ProgramCategoryStruct
				{
					CHIP_ERROR Type::Encode(TLV::TLVWriter &aWriter, TLV::Tag aTag) const
					{
						DataModel::WrappedStructEncoder encoder{ aWriter, aTag };
						encoder.Encode(to_underlying(Fields::kCategory), category);
						encoder.Encode(to_underlying(Fields::kSubCategory), subCategory);
						return encoder.Finalize();
					}

					CHIP_ERROR DecodableType::Decode(TLV::TLVReader &reader)
					{
						detail::StructDecodeIterator __iterator(reader);
						while (true) {
							uint8_t __context_tag = 0;
							CHIP_ERROR err = __iterator.Next(__context_tag);
							VerifyOrReturnError(err != CHIP_ERROR_END_OF_TLV,
									    CHIP_NO_ERROR);
							ReturnErrorOnFailure(err);

							if (__context_tag == to_underlying(Fields::kCategory)) {
								err = DataModel::Decode(reader, category);
							} else if (__context_tag ==
								   to_underlying(Fields::kSubCategory)) {
								err = DataModel::Decode(reader, subCategory);
							}

							ReturnErrorOnFailure(err);
						}
					}

				} // namespace ProgramCategoryStruct

				namespace SeriesInfoStruct
				{
					CHIP_ERROR Type::Encode(TLV::TLVWriter &aWriter, TLV::Tag aTag) const
					{
						DataModel::WrappedStructEncoder encoder{ aWriter, aTag };
						encoder.Encode(to_underlying(Fields::kSeason), season);
						encoder.Encode(to_underlying(Fields::kEpisode), episode);
						return encoder.Finalize();
					}

					CHIP_ERROR DecodableType::Decode(TLV::TLVReader &reader)
					{
						detail::StructDecodeIterator __iterator(reader);
						while (true) {
							uint8_t __context_tag = 0;
							CHIP_ERROR err = __iterator.Next(__context_tag);
							VerifyOrReturnError(err != CHIP_ERROR_END_OF_TLV,
									    CHIP_NO_ERROR);
							ReturnErrorOnFailure(err);

							if (__context_tag == to_underlying(Fields::kSeason)) {
								err = DataModel::Decode(reader, season);
							} else if (__context_tag == to_underlying(Fields::kEpisode)) {
								err = DataModel::Decode(reader, episode);
							}

							ReturnErrorOnFailure(err);
						}
					}

				} // namespace SeriesInfoStruct

				namespace ChannelInfoStruct
				{
					CHIP_ERROR Type::Encode(TLV::TLVWriter &aWriter, TLV::Tag aTag) const
					{
						DataModel::WrappedStructEncoder encoder{ aWriter, aTag };
						encoder.Encode(to_underlying(Fields::kMajorNumber), majorNumber);
						encoder.Encode(to_underlying(Fields::kMinorNumber), minorNumber);
						encoder.Encode(to_underlying(Fields::kName), name);
						encoder.Encode(to_underlying(Fields::kCallSign), callSign);
						encoder.Encode(to_underlying(Fields::kAffiliateCallSign),
							       affiliateCallSign);
						encoder.Encode(to_underlying(Fields::kIdentifier), identifier);
						encoder.Encode(to_underlying(Fields::kType), type);
						return encoder.Finalize();
					}

					CHIP_ERROR DecodableType::Decode(TLV::TLVReader &reader)
					{
						detail::StructDecodeIterator __iterator(reader);
						while (true) {
							uint8_t __context_tag = 0;
							CHIP_ERROR err = __iterator.Next(__context_tag);
							VerifyOrReturnError(err != CHIP_ERROR_END_OF_TLV,
									    CHIP_NO_ERROR);
							ReturnErrorOnFailure(err);

							if (__context_tag == to_underlying(Fields::kMajorNumber)) {
								err = DataModel::Decode(reader, majorNumber);
							} else if (__context_tag ==
								   to_underlying(Fields::kMinorNumber)) {
								err = DataModel::Decode(reader, minorNumber);
							} else if (__context_tag == to_underlying(Fields::kName)) {
								err = DataModel::Decode(reader, name);
							} else if (__context_tag == to_underlying(Fields::kCallSign)) {
								err = DataModel::Decode(reader, callSign);
							} else if (__context_tag ==
								   to_underlying(Fields::kAffiliateCallSign)) {
								err = DataModel::Decode(reader, affiliateCallSign);
							} else if (__context_tag ==
								   to_underlying(Fields::kIdentifier)) {
								err = DataModel::Decode(reader, identifier);
							} else if (__context_tag == to_underlying(Fields::kType)) {
								err = DataModel::Decode(reader, type);
							}

							ReturnErrorOnFailure(err);
						}
					}

				} // namespace ChannelInfoStruct

				namespace ProgramStruct
				{
					CHIP_ERROR Type::Encode(TLV::TLVWriter &aWriter, TLV::Tag aTag) const
					{
						DataModel::WrappedStructEncoder encoder{ aWriter, aTag };
						encoder.Encode(to_underlying(Fields::kIdentifier), identifier);
						encoder.Encode(to_underlying(Fields::kChannel), channel);
						encoder.Encode(to_underlying(Fields::kStartTime), startTime);
						encoder.Encode(to_underlying(Fields::kEndTime), endTime);
						encoder.Encode(to_underlying(Fields::kTitle), title);
						encoder.Encode(to_underlying(Fields::kSubtitle), subtitle);
						encoder.Encode(to_underlying(Fields::kDescription), description);
						encoder.Encode(to_underlying(Fields::kAudioLanguages), audioLanguages);
						encoder.Encode(to_underlying(Fields::kRatings), ratings);
						encoder.Encode(to_underlying(Fields::kThumbnailUrl), thumbnailUrl);
						encoder.Encode(to_underlying(Fields::kPosterArtUrl), posterArtUrl);
						encoder.Encode(to_underlying(Fields::kDvbiUrl), dvbiUrl);
						encoder.Encode(to_underlying(Fields::kReleaseDate), releaseDate);
						encoder.Encode(to_underlying(Fields::kParentalGuidanceText),
							       parentalGuidanceText);
						encoder.Encode(to_underlying(Fields::kRecordingFlag), recordingFlag);
						encoder.Encode(to_underlying(Fields::kSeriesInfo), seriesInfo);
						encoder.Encode(to_underlying(Fields::kCategoryList), categoryList);
						encoder.Encode(to_underlying(Fields::kCastList), castList);
						encoder.Encode(to_underlying(Fields::kExternalIDList), externalIDList);
						return encoder.Finalize();
					}

					CHIP_ERROR DecodableType::Decode(TLV::TLVReader &reader)
					{
						detail::StructDecodeIterator __iterator(reader);
						while (true) {
							uint8_t __context_tag = 0;
							CHIP_ERROR err = __iterator.Next(__context_tag);
							VerifyOrReturnError(err != CHIP_ERROR_END_OF_TLV,
									    CHIP_NO_ERROR);
							ReturnErrorOnFailure(err);

							if (__context_tag == to_underlying(Fields::kIdentifier)) {
								err = DataModel::Decode(reader, identifier);
							} else if (__context_tag == to_underlying(Fields::kChannel)) {
								err = DataModel::Decode(reader, channel);
							} else if (__context_tag == to_underlying(Fields::kStartTime)) {
								err = DataModel::Decode(reader, startTime);
							} else if (__context_tag == to_underlying(Fields::kEndTime)) {
								err = DataModel::Decode(reader, endTime);
							} else if (__context_tag == to_underlying(Fields::kTitle)) {
								err = DataModel::Decode(reader, title);
							} else if (__context_tag == to_underlying(Fields::kSubtitle)) {
								err = DataModel::Decode(reader, subtitle);
							} else if (__context_tag ==
								   to_underlying(Fields::kDescription)) {
								err = DataModel::Decode(reader, description);
							} else if (__context_tag ==
								   to_underlying(Fields::kAudioLanguages)) {
								err = DataModel::Decode(reader, audioLanguages);
							} else if (__context_tag == to_underlying(Fields::kRatings)) {
								err = DataModel::Decode(reader, ratings);
							} else if (__context_tag ==
								   to_underlying(Fields::kThumbnailUrl)) {
								err = DataModel::Decode(reader, thumbnailUrl);
							} else if (__context_tag ==
								   to_underlying(Fields::kPosterArtUrl)) {
								err = DataModel::Decode(reader, posterArtUrl);
							} else if (__context_tag == to_underlying(Fields::kDvbiUrl)) {
								err = DataModel::Decode(reader, dvbiUrl);
							} else if (__context_tag ==
								   to_underlying(Fields::kReleaseDate)) {
								err = DataModel::Decode(reader, releaseDate);
							} else if (__context_tag ==
								   to_underlying(Fields::kParentalGuidanceText)) {
								err = DataModel::Decode(reader, parentalGuidanceText);
							} else if (__context_tag ==
								   to_underlying(Fields::kRecordingFlag)) {
								err = DataModel::Decode(reader, recordingFlag);
							} else if (__context_tag ==
								   to_underlying(Fields::kSeriesInfo)) {
								err = DataModel::Decode(reader, seriesInfo);
							} else if (__context_tag ==
								   to_underlying(Fields::kCategoryList)) {
								err = DataModel::Decode(reader, categoryList);
							} else if (__context_tag == to_underlying(Fields::kCastList)) {
								err = DataModel::Decode(reader, castList);
							} else if (__context_tag ==
								   to_underlying(Fields::kExternalIDList)) {
								err = DataModel::Decode(reader, externalIDList);
							}

							ReturnErrorOnFailure(err);
						}
					}

				} // namespace ProgramStruct

				namespace PageTokenStruct
				{
					CHIP_ERROR Type::Encode(TLV::TLVWriter &aWriter, TLV::Tag aTag) const
					{
						DataModel::WrappedStructEncoder encoder{ aWriter, aTag };
						encoder.Encode(to_underlying(Fields::kLimit), limit);
						encoder.Encode(to_underlying(Fields::kAfter), after);
						encoder.Encode(to_underlying(Fields::kBefore), before);
						return encoder.Finalize();
					}

					CHIP_ERROR DecodableType::Decode(TLV::TLVReader &reader)
					{
						detail::StructDecodeIterator __iterator(reader);
						while (true) {
							uint8_t __context_tag = 0;
							CHIP_ERROR err = __iterator.Next(__context_tag);
							VerifyOrReturnError(err != CHIP_ERROR_END_OF_TLV,
									    CHIP_NO_ERROR);
							ReturnErrorOnFailure(err);

							if (__context_tag == to_underlying(Fields::kLimit)) {
								err = DataModel::Decode(reader, limit);
							} else if (__context_tag == to_underlying(Fields::kAfter)) {
								err = DataModel::Decode(reader, after);
							} else if (__context_tag == to_underlying(Fields::kBefore)) {
								err = DataModel::Decode(reader, before);
							}

							ReturnErrorOnFailure(err);
						}
					}

				} // namespace PageTokenStruct

				namespace ChannelPagingStruct
				{
					CHIP_ERROR Type::Encode(TLV::TLVWriter &aWriter, TLV::Tag aTag) const
					{
						DataModel::WrappedStructEncoder encoder{ aWriter, aTag };
						encoder.Encode(to_underlying(Fields::kPreviousToken), previousToken);
						encoder.Encode(to_underlying(Fields::kNextToken), nextToken);
						return encoder.Finalize();
					}

					CHIP_ERROR DecodableType::Decode(TLV::TLVReader &reader)
					{
						detail::StructDecodeIterator __iterator(reader);
						while (true) {
							uint8_t __context_tag = 0;
							CHIP_ERROR err = __iterator.Next(__context_tag);
							VerifyOrReturnError(err != CHIP_ERROR_END_OF_TLV,
									    CHIP_NO_ERROR);
							ReturnErrorOnFailure(err);

							if (__context_tag == to_underlying(Fields::kPreviousToken)) {
								err = DataModel::Decode(reader, previousToken);
							} else if (__context_tag == to_underlying(Fields::kNextToken)) {
								err = DataModel::Decode(reader, nextToken);
							}

							ReturnErrorOnFailure(err);
						}
					}

				} // namespace ChannelPagingStruct

				namespace AdditionalInfoStruct
				{
					CHIP_ERROR Type::Encode(TLV::TLVWriter &aWriter, TLV::Tag aTag) const
					{
						DataModel::WrappedStructEncoder encoder{ aWriter, aTag };
						encoder.Encode(to_underlying(Fields::kName), name);
						encoder.Encode(to_underlying(Fields::kValue), value);
						return encoder.Finalize();
					}

					CHIP_ERROR DecodableType::Decode(TLV::TLVReader &reader)
					{
						detail::StructDecodeIterator __iterator(reader);
						while (true) {
							uint8_t __context_tag = 0;
							CHIP_ERROR err = __iterator.Next(__context_tag);
							VerifyOrReturnError(err != CHIP_ERROR_END_OF_TLV,
									    CHIP_NO_ERROR);
							ReturnErrorOnFailure(err);

							if (__context_tag == to_underlying(Fields::kName)) {
								err = DataModel::Decode(reader, name);
							} else if (__context_tag == to_underlying(Fields::kValue)) {
								err = DataModel::Decode(reader, value);
							}

							ReturnErrorOnFailure(err);
						}
					}

				} // namespace AdditionalInfoStruct

				namespace LineupInfoStruct
				{
					CHIP_ERROR Type::Encode(TLV::TLVWriter &aWriter, TLV::Tag aTag) const
					{
						DataModel::WrappedStructEncoder encoder{ aWriter, aTag };
						encoder.Encode(to_underlying(Fields::kOperatorName), operatorName);
						encoder.Encode(to_underlying(Fields::kLineupName), lineupName);
						encoder.Encode(to_underlying(Fields::kPostalCode), postalCode);
						encoder.Encode(to_underlying(Fields::kLineupInfoType), lineupInfoType);
						return encoder.Finalize();
					}

					CHIP_ERROR DecodableType::Decode(TLV::TLVReader &reader)
					{
						detail::StructDecodeIterator __iterator(reader);
						while (true) {
							uint8_t __context_tag = 0;
							CHIP_ERROR err = __iterator.Next(__context_tag);
							VerifyOrReturnError(err != CHIP_ERROR_END_OF_TLV,
									    CHIP_NO_ERROR);
							ReturnErrorOnFailure(err);

							if (__context_tag == to_underlying(Fields::kOperatorName)) {
								err = DataModel::Decode(reader, operatorName);
							} else if (__context_tag ==
								   to_underlying(Fields::kLineupName)) {
								err = DataModel::Decode(reader, lineupName);
							} else if (__context_tag ==
								   to_underlying(Fields::kPostalCode)) {
								err = DataModel::Decode(reader, postalCode);
							} else if (__context_tag ==
								   to_underlying(Fields::kLineupInfoType)) {
								err = DataModel::Decode(reader, lineupInfoType);
							}

							ReturnErrorOnFailure(err);
						}
					}

				} // namespace LineupInfoStruct
			} // namespace Structs
		} // namespace Channel
	} // namespace Clusters
} // namespace app
} // namespace chip
