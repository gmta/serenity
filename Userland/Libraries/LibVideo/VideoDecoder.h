/*
 * Copyright (c) 2022, Gregory Bertilson <zaggy1024@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <AK/ByteBuffer.h>
#include <AK/NonnullOwnPtr.h>

#include "DecoderError.h"
#include "VideoFrame.h"

namespace Video {

class VideoDecoder {
public:
    virtual ~VideoDecoder() {};

    virtual DecoderErrorOr<void> receive_sample(Span<u8 const> sample) = 0;
    DecoderErrorOr<void> receive_sample(ByteBuffer const& sample) { return receive_sample(sample.span()); }
    virtual DecoderErrorOr<NonnullOwnPtr<VideoFrame>> get_decoded_frame() = 0;
};

}
