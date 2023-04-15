/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef HARDWARE_GPIO_H_
#define HARDWARE_GPIO_H_

#define GPIO_IRQ_EDGE_RISE 1
#define GPIO_IRQ_EDGE_FALL 2

#include <hardware/irq.h>

typedef void(* gpio_irq_callback_t)(unsigned int gpio, unsigned long event_mask);  // NOLINT(runtime/int)

void gpio_pull_up(unsigned int gpio);
void gpio_set_irq_enabled(unsigned int gpio, unsigned long event_mask, bool enabled);  // NOLINT(runtime/int)
void gpio_init_mask(unsigned int gpio_mask);
void gpio_set_irq_callback(gpio_irq_callback_t callback);

#endif  // HARDWARE_GPIO_H_