/*
 * Copyright (C) 2016 Gautier Hattenberger and Alexandre Bustico
 *
 * This file is part of paparazzi.
 *
 * paparazzi is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * paparazzi is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with paparazzi; see the file COPYING.  If not, see
 * <http://www.gnu.org/licenses/>.
 */

/**
 * @file arch/chibios/mcu_periph/ram_arch.h
 *
 * Specific RAM section for DMA usage on F7
 *
 *  F1
 *   ram0: 64ko   std
 *
 *  F4
 *   ram4: 64ko   ccm, fast, no dma
 *   ram0: 128Ko  std
 *
 *  F7
 *   ram0: std, fast, no dma
 *   ram3: dma
 */

#ifndef RAM_ARCH_H
#define RAM_ARCH_H

#if defined STM32F1
#define STD_SECTION   ".ram0"
#define FAST_SECTION  ".ram0"
#define DMA_SECTION   ".ram0"
#elif defined STM32F4
#define STD_SECTION   ".ram0"
#define FAST_SECTION  ".ram4"
#define DMA_SECTION   ".ram0"
#elif defined STM32F7
#define STD_SECTION   ".ram0"
#define FAST_SECTION  ".ram0"
#define DMA_SECTION   ".ram3"
#else
#error "section defined only for STM32F1, STM32F4 and STM32F7"
#endif

#define IN_STD_SECTION(var) var __attribute__ ((section(STD_SECTION), aligned(8)))
#define IN_FAST_SECTION(var) var __attribute__ ((section(FAST_SECTION), aligned(8)))
#define IN_DMA_SECTION(var) var __attribute__ ((section(DMA_SECTION), aligned(8)))

#endif

