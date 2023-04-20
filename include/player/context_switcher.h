/* Copyright (c) 2023 Jose Gisbert
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef PLAYER_CONTEXT_SWITCHER_H_
#define PLAYER_CONTEXT_SWITCHER_H_

#define NON_EXISTENT_PIN 1000

#include <cstdint>
#include <unordered_map>

#include "button/button_event_handler.h"
#include "clock/clock.h"
#include "player/player_context.h"

class ContextSwitcher : ButtonEventHandler {
  Clock& clock_;
  std::unordered_map<std::uint32_t, PlayerContext> player_context_map_;
  std::uint32_t last_button_pressed_ = NON_EXISTENT_PIN;
  void SaveLastPlayerContext();
  void ResumeClockWithCurrentPlayerContext(std::uint32_t button_pressed);
 public:  // editorconfig-checker-disable-line
  // TODO(jisbert): Can be clock passed like this const Clock& clock
  ContextSwitcher(Clock& clock, std::unordered_map<std::uint32_t, std::uint32_t> button_to_led_map_, std::uint32_t initial_time);  // NOLINT(*)
  void HandlePressed(std::uint32_t button_pressed) final;
};

#endif  // PLAYER_CONTEXT_SWITCHER_H_