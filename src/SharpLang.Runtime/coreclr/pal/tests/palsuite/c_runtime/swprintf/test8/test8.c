//
// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information. 
//

/*============================================================================
**
** Source:  test8.c
**
** Purpose: Tests swprintf with decimal numbers
**
**
**==========================================================================*/



#include <palsuite.h>
#include "../swprintf.h"

/*
 * Uses memcmp & wcslen
 */

int __cdecl main(int argc, char *argv[])
{
    int neg = -42;
    int pos = 42;
    INT64 l = 42;
    
    if (PAL_Initialize(argc, argv) != 0)
    {
        return FAIL;
    }


    DoNumTest(convert("foo %d"), pos, convert("foo 42"));
    DoNumTest(convert("foo %ld"), 0xFFFF, convert("foo 65535"));
    DoNumTest(convert("foo %hd"), 0xFFFF, convert("foo -1"));
    DoNumTest(convert("foo %Ld"), pos, convert("foo 42"));
    DoI64Test(convert("foo %I64d"), l, "0x0000000000000042",
              convert("foo 42"));
    DoNumTest(convert("foo %3d"), pos, convert("foo  42"));
    DoNumTest(convert("foo %-3d"), pos, convert("foo 42 "));
    DoNumTest(convert("foo %.1d"), pos, convert("foo 42"));
    DoNumTest(convert("foo %.3d"), pos, convert("foo 042"));
    DoNumTest(convert("foo %03d"), pos, convert("foo 042"));
    DoNumTest(convert("foo %#d"), pos, convert("foo 42"));
    DoNumTest(convert("foo %+d"), pos, convert("foo +42"));
    DoNumTest(convert("foo % d"), pos, convert("foo  42"));
    DoNumTest(convert("foo %+d"), neg, convert("foo -42"));
    DoNumTest(convert("foo % d"), neg, convert("foo -42"));

    PAL_Terminate();
    return PASS;
}

