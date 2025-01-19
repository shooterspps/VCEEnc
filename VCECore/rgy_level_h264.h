﻿// -----------------------------------------------------------------------------------------
// NVEnc by rigaya
// -----------------------------------------------------------------------------------------
// The MIT License
//
// Copyright (c) 2014-2016 rigaya
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// --------------------------------------------------------------------------------------------

#ifndef __RGY_LEVEL_H264_H__
#define __RGY_LEVEL_H264_H__

#include "rgy_level.h"

int calc_auto_level_h264(int width, int height, int ref, bool interlaced, int fps_num, int fps_den, int profile, int vbv_max, int vbv_buf);
void get_vbv_value_h264(int *vbv_max, int *vbv_buf, int level, int profile);

class RGYCodecLevelH264 : public RGYCodecLevel {
public:
    RGYCodecLevelH264() : RGYCodecLevel() { m_codec = RGY_CODEC_H264; };
    virtual ~RGYCodecLevelH264() {};
    virtual int calc_auto_level(int width, int height, int ref, bool interlaced, int fps_num, int fps_den, int profile, bool high_tier, int max_bitrate, int vbv_buf, int tile_col, int tile_row) override;
    virtual int get_max_bitrate(int level, int profile, bool high_tier) override;
    virtual int get_max_vbv_buf(int level, int profile) override;
    virtual int get_max_ref(int width, int height, int level, bool interlaced) override;
protected:
};

#endif //__RGY_LEVEL_H264_H__
