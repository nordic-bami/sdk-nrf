#
# Copyright (c) 2024 Nordic Semiconductor
#
# SPDX-License-Identifier: LicenseRef-Nordic-5-Clause

if(SB_CONFIG_MCUBOOT_BUILD_DIRECT_XIP_VARIANT)
  set(image mcuboot_secondary_app)
  ExternalNcsVariantProject_Add(APPLICATION ${DEFAULT_IMAGE} VARIANT ${image})

  set_property(GLOBAL APPEND PROPERTY
      PM_APP_IMAGES
      "${image}"
  )
endif()
