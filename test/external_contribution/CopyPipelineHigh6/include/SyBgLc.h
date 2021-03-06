/*
 * Copyright (c) 2017, Intel Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */
using namespace std;

#include "CPipeline.h"

class SyBgLc : public CopyPipeline
{
public:
   SyBgLc(CmDevice *device, int threadCount, int lightness, int contrast);
   ~SyBgLc(void);

   int PreRun(
         CmKernel       *pKernel,
         SurfaceIndex   *pSI_SrcSurfL,
         SurfaceIndex   *pSI_SrcSurfA,
         SurfaceIndex   *pSI_SrcSurfB,
         SurfaceIndex   *pSI_DstSurfSymm,
         SurfaceIndex   *pSI_DstSurfA,
         SurfaceIndex   *pSI_DstSurfB,
         int             nPicWidth,
         int             nPicHeight
         );
   char* GetIsa() { return "Symm7x7_BgSuppress_LightContrast/SyBgLc_genx.isa"; }
   char* GetKernelName() { return "SyBgLc_GENX"; }

private:
   CmDevice*      m_pCmDev;
   CmKernel      *m_pKernel;
   int            m_coeffs[10];
   int            m_shift;
   uchar         *m_pLUT;
   int            m_max_Thread_Count;
};

