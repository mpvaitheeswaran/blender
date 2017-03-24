/*
 * Copyright 2011-2013 Blender Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/* Templated common declaration part of all CPU kernels. */

void KERNEL_FUNCTION_FULL_NAME(filter_divide_shadow)(int sample,
                                                     TilesInfo *tiles,
                                                     int x,
                                                     int y,
                                                     float *unfilteredA,
                                                     float *unfilteredB,
                                                     float *sampleV,
                                                     float *sampleVV,
                                                     float *bufferV,
                                                     int* prefilter_rect,
                                                     int buffer_pass_stride,
                                                     int buffer_denoising_offset,
                                                     bool use_gradients,
                                                     bool use_split_variance);

void KERNEL_FUNCTION_FULL_NAME(filter_get_feature)(int sample,
                                                   TilesInfo *tiles,
                                                   int m_offset,
                                                   int v_offset,
                                                   int x,
                                                   int y,
                                                   float *mean,
                                                   float *variance,
                                                   int* prefilter_rect,
                                                   int buffer_pass_stride,
                                                   int buffer_denoising_offset,
                                                   bool use_cross_denoising,
                                                   bool use_split_variance);

void KERNEL_FUNCTION_FULL_NAME(filter_combine_halves)(int x, int y,
                                                      float *mean,
                                                      float *variance,
                                                      float *a,
                                                      float *b,
                                                      int* prefilter_rect,
                                                      int r);

void KERNEL_FUNCTION_FULL_NAME(filter_construct_transform)(int sample,
                                                           float* buffer,
                                                           int x,
                                                           int y,
                                                           int storage_ofs,
                                                           float *transform,
                                                           int *rank,
                                                           int* rect,
                                                           int radius,
                                                           float pca_threshold);

void KERNEL_FUNCTION_FULL_NAME(filter_divide_combined)(int x, int y,
                                                       int sample,
                                                       float *buffers,
                                                       int offset,
                                                       int stride,
                                                       int pass_stride,
                                                       int no_denoising_offset);



void KERNEL_FUNCTION_FULL_NAME(filter_nlm_calc_difference)(int dx,
                                                           int dy,
                                                           float *weightImage,
                                                           float *variance,
                                                           float *differenceImage,
                                                           int* rect,
                                                           int w,
                                                           int channel_offset,
                                                           float a,
                                                           float k_2);

void KERNEL_FUNCTION_FULL_NAME(filter_nlm_blur)(float *differenceImage,
                                                float *outImage,
                                                int* rect,
                                                int w,
                                                int f);

void KERNEL_FUNCTION_FULL_NAME(filter_nlm_calc_weight)(float *differenceImage,
                                                       float *outImage,
                                                       int* rect,
                                                       int w,
                                                       int f);

void KERNEL_FUNCTION_FULL_NAME(filter_nlm_update_output)(int dx,
                                                         int dy,
                                                         float *differenceImage,
                                                         float *image,
                                                         float *outImage,
                                                         float *accumImage,
                                                         int* rect,
                                                         int w,
                                                         int f);

void KERNEL_FUNCTION_FULL_NAME(filter_nlm_construct_gramian)(int dx,
                                                             int dy,
                                                             float *differenceImage,
                                                             float *buffer,
                                                             float *color_pass,
                                                             float *variance_pass,
                                                             float *transform,
                                                             int *rank,
                                                             float *XtWX,
                                                             float3 *XtWY,
                                                             int *rect,
                                                             int *filter_rect,
                                                             int w,
                                                             int h,
                                                             int f);

void KERNEL_FUNCTION_FULL_NAME(filter_nlm_normalize)(float *outImage,
                                                     float *accumImage,
                                                     int* rect,
                                                     int w);

void KERNEL_FUNCTION_FULL_NAME(filter_finalize)(int x,
                                                int y,
                                                int storage_ofs,
                                                int w,
                                                int h,
                                                float *buffer,
                                                int *rank,
                                                float *XtWX,
                                                float3 *XtWY,
                                                int *buffer_params,
                                                int sample);

#undef KERNEL_ARCH
