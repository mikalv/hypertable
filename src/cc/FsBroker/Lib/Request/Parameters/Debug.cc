/* -*- c++ -*-
 * Copyright (C) 2007-2016 Hypertable, Inc.
 *
 * This file is part of Hypertable.
 *
 * Hypertable is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or any later version.
 *
 * Hypertable is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 */

/// @file
/// Definitions for Debug request parameters.
/// This file contains definitions for Debug, a class for encoding and
/// decoding paramters to the <i>debug</i> file system broker function.

#include <Common/Compat.h>

#include "Debug.h"

#include <Common/Logger.h>
#include <Common/Serialization.h>

using namespace Hypertable;
using namespace Hypertable::FsBroker::Lib::Request::Parameters;

uint8_t Debug::encoding_version() const {
  return 1;
}

size_t Debug::encoded_length_internal() const {
  return 4;
}

void Debug::encode_internal(uint8_t **bufp) const {
  Serialization::encode_i32(bufp, m_command);
}

void Debug::decode_internal(uint8_t version, const uint8_t **bufp,
			    size_t *remainp) {
  (void)version;
  m_command = (int32_t)Serialization::decode_i32(bufp, remainp);
}
