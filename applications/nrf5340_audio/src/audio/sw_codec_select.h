/*
 * Copyright (c) 2018 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

#ifndef _SW_CODEC_SELECT_H_
#define _SW_CODEC_SELECT_H_

#include <zephyr/kernel.h>
#include <zephyr/net_buf.h>
#include "device_location.h"

#if (CONFIG_SW_CODEC_LC3)
#define LC3_MAX_FRAME_SIZE_MS	10
#define LC3_ENC_MONO_FRAME_SIZE (CONFIG_LC3_BITRATE_MAX * LC3_MAX_FRAME_SIZE_MS / (8 * 1000))

#define LC3_PCM_NUM_BYTES_MONO                                                                     \
	(CONFIG_AUDIO_SAMPLE_RATE_HZ * CONFIG_AUDIO_BIT_DEPTH_OCTETS * LC3_MAX_FRAME_SIZE_MS / 1000)
#define LC3_ENC_TIME_US 3000
#define LC3_DEC_TIME_US 1500
#else
#define LC3_ENC_MONO_FRAME_SIZE 0
#define LC3_PCM_NUM_BYTES_MONO	0
#define LC3_ENC_TIME_US		0
#define LC3_DEC_TIME_US		0
#endif /* CONFIG_SW_CODEC_LC3 */

/* Max will be used when multiple codecs are supported */
#define ENC_MAX_FRAME_SIZE   MAX(LC3_ENC_MONO_FRAME_SIZE, 0)
#define ENC_TIME_US	     MAX(LC3_ENC_TIME_US, 0)
#define DEC_TIME_US	     MAX(LC3_DEC_TIME_US, 0)
#define PCM_NUM_BYTES_MONO   MAX(LC3_PCM_NUM_BYTES_MONO, 0)
#define PCM_NUM_BYTES_STEREO (PCM_NUM_BYTES_MONO * 2)

enum sw_codec_select {
	SW_CODEC_NONE,
	SW_CODEC_LC3, /* Low Complexity Communication Codec */
};

enum sw_codec_channel_mode {
	SW_CODEC_MONO = 1,
	SW_CODEC_STEREO,
};

struct sw_codec_encoder {
	bool enabled;
	int bitrate;
	enum sw_codec_channel_mode channel_mode;
	uint8_t num_ch;
	enum audio_channel audio_ch;
	uint32_t sample_rate_hz;
};

struct sw_codec_decoder {
	bool enabled;
	enum sw_codec_channel_mode channel_mode; /* Mono or stereo. */
	uint8_t num_ch;				 /* Number of decoder channels. */
	enum audio_channel audio_ch;		 /* Used to choose which channel to use. */
	uint32_t sample_rate_hz;
};

/**
 * @brief  Sw_codec configuration structure.
 */
struct sw_codec_config {
	enum sw_codec_select sw_codec;	 /* sw_codec to be used, e.g. LC3, etc. */
	struct sw_codec_decoder decoder; /* Struct containing settings for decoder. */
	struct sw_codec_encoder encoder; /* Struct containing settings for encoder. */
	bool initialized;		 /* Status of codec. */
};

/**
 * @brief	Check if the software codec is initialized.
 *
 * @retval	true	SW codec is initialized.
 * @retval	false	SW codec is not initialized.
 */
bool sw_codec_is_initialized(void);

/**
 * @brief	Encode PCM data and output encoded data.
 *
 * @note	Takes in stereo PCM stream, will encode either one or two
 *		channels, based on channel_mode set during init.
 *
 * @param[in]	audio_frame	Pointer to the audio buffer.
 *
 * @return	0 if success, error codes depends on sw_codec selected.
 */
int sw_codec_encode(struct net_buf *audio_frame);

/**
 * @brief	Decode encoded data and output PCM data.
 *
 * @param[in]	audio_frame	Pointer to the audio buffer.
 * @param[out]	pcm_data	Pointer to the buffer to store the decoded PCM data.
 * @param[out]	pcm_size	Size of decoded data.
 *
 * @return	0 if success, error codes depends on sw_codec selected.
 */
int sw_codec_decode(struct net_buf const *const audio_frame, void **pcm_data, size_t *pcm_size);

/**
 * @brief	Uninitialize the software codec and free the allocated space.
 *
 * @note	Must be called before calling init for another sw_codec.
 *
 * @param[in]	sw_codec_cfg	Struct to tear down sw_codec.
 *
 * @return	0 if success, error codes depends on sw_codec selected.
 */
int sw_codec_uninit(struct sw_codec_config sw_codec_cfg);

/**
 * @brief	Initialize the software codec and statically or dynamically
 *		allocate memory to be used, depending on the selected codec
 *		and its configuration.
 *
 * @param[in]	sw_codec_cfg	Struct to set up sw_codec.
 *
 * @return	0 if success, error codes depends on sw_codec selected.
 */
int sw_codec_init(struct sw_codec_config sw_codec_cfg);

#endif /* _SW_CODEC_SELECT_H_ */
