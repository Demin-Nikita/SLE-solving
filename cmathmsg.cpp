/* cmathmsg.c
   CMATH error message translator.  */


   /************************************************/
   /*                                              */
   /*  CMATH.  Copyright (c) 1989 Design Software  */
   /*                                              */
   /************************************************/

#include "cmath.h"
#if (STDLIBH)
#include <stdlib.h>
#endif
#include <stdio.h>
#include <math.h>
#if (STRINGH)
#include <string.h>
#endif

#ifndef NULL
#define  NULL  0
#endif

/*-----------------------------------------------------------------*/

#if (PROTOTYPE)

char* cmathmsg(int routine, int flag) {

#else

char* cmathmsg(routine, flag)

#endif

/* Purpose ...
   -------
   Translate the error flag returned by a particular CMATH routine
   into an English error message.

   Input ...
   -----
   routine  : An integer value specifying the CMATH routine.
              You should use the macro definitions supplied
              in the cmath.h header file.  The name of the
              constant for each CMATH routine is written in
              UPPER CASE and is suffixed by "_C".  For example
              the constant for the routine decomp() is DECOMP_C.
   flag     : The integer value of the error flag (or status
              indicator) as returned by the CMATH routine.

   Output ...
   ------
   cmathmsg() : returns a pointer to a string containing the text
                of the error message.

   Version ... 1.0,  15-August-1989
   -------

   This C code written by ...  Peter & Nigel,
   ----------------------      Design Software,
                               42 Gubberley St,
                               Kenmore, 4069,
                               Australia.

*/

  /* begin cmathmsg() */
    static char s[64];

    switch (routine)
    {
    case BANDFAC_C:
        switch (flag)
        {
        case 0:  strcpy_s(s, "bandfac () : normal return.");
            break;
        case 1:  strcpy_s(s, "bandfac () : invalid input parameter(s).");
            break;
        case 2:  strcpy_s(s, "bandfac () : pivot of matrix = 0.0");
            break;
        case 3:  strcpy_s(s, "bandfac () : last diagonal term = 0.0");
            break;
        default:  strcpy_s(s, "bandfac () : no such error.");
        }
        break;

    case BSPLINIT_C:
        switch (flag)
        {
        case 0:  strcpy_s(s, "bsplinit () : normal return.");
            break;
        case 1:  strcpy_s(s, "bsplinit () : unable to reserve memory.");
            break;
        default:  strcpy_s(s, "bsplinit () : no such error.");
        }
        break;

    case BISECT_C:
        switch (flag)
        {
        default:  strcpy_s(s, "bisect () :  no such error.");
            break;
        }
        break;

    case INTERV_C:
        switch (flag)
        {
        case 0:  strcpy_s(s, "interv () : normal return.");
            break;
        case -1:  strcpy_s(s, "interv () : parameter value < knot[0].");
            break;
        case 1:  strcpy_s(s, "interv () : parameter value >= knot[maxi].");
            break;
        default:  strcpy_s(s, "interv () : no such error.");
        }
        break;


    case BSPLVB_C:
        switch (flag)
        {
        case 0:  strcpy_s(s, "bsplvb () : normal return.");
            break;
        case 1:  strcpy_s(s, "bsplvb () : invalid value for index.");
            break;
        default:  strcpy_s(s, "bsplvb () : no such error.");
        }
        break;

    case BSPLEND_C:
        switch (flag)
        {
        default:  strcpy_s(s, "bsplend () :  no such error.");
            break;
        }
        break;

    case BSPLINE_C:
        switch (flag)
        {
        case 0:  strcpy_s(s, "bspline () : normal return.");
            break;
        case 1:  strcpy_s(s, "bspline () : unable to assign memory.");
            break;
        case 2:  strcpy_s(s, "bspline () : parameter out of knot range.");
            break;
        case 3:  strcpy_s(s, "bspline () : error in banded matrix solution.");
            break;
        default:  strcpy_s(s, "bspline () : no such error.");
        }
        break;

    case BSEVAL_C:
        switch (flag)
        {
        case 0:  strcpy_s(s, "bseval () : normal return.");
            break;
        case 1:  strcpy_s(s, "bseval () : parameter value not valid.");
            break;
        case 2:  strcpy_s(s, "bseval () : invalid value for index.");
            break;
        default:  strcpy_s(s, "bseval () : no such error.");
        }
        break;

    case BSDCPNTS_C:
        switch (flag)
        {
        case  0:  strcpy_s(s, "bsdcpnt () : normal return.");
            break;
        case  1:  strcpy_s(s, "bsdcpnt () : NULL pointer to matrix.");
            break;
        default:  strcpy_s(s, "bsdcpnt () : no such error.");
        }
        break;

    case DECOMP_C:
        switch (flag)
        {
        case 0: strcpy_s(s, "decomp() : normal return");
            break;
        case 1: strcpy_s(s, "decomp() : could not allocate workspace");
            break;
        case 2: strcpy_s(s, "decomp() : illegal user input");
            break;
        case 3: strcpy_s(s, "decomp() : matrix is singular");
            break;
        default: strcpy_s(s, "decomp() : no such error");
        };
        break;

    case CDECOMP_C:
        switch (flag)
        {
        case 0: strcpy_s(s, "cdecomp() : normal return");
            break;
        case 1: strcpy_s(s, "cdecomp() : could not allocate workspace");
            break;
        case 2: strcpy_s(s, "cdecomp() : illegal user input");
            break;
        case 3: strcpy_s(s, "cdecomp() : matrix is singular");
            break;
        default: strcpy_s(s, "cdecomp() : no such error");
        };
        break;

    case SVD_C:
        if (flag > 0)
        {
            strcpy_s(s, "svd() : too many iterations required");
        }
        else
        {
            switch (flag)
            {
            case 0: strcpy_s(s, "svd() : normal return");
                break;
            case -1: strcpy_s(s, "svd() : could not allocate workspace");
                break;
            case -2: strcpy_s(s, "svd() : invalid user input");
                break;
            default: strcpy_s(s, "svd() : no such error");
            };
        }
        break;

    case SVDSOLVE_C:
        switch (flag)
        {
        case 0: strcpy_s(s, "svdsolve() : normal return");
            break;
        case -1: strcpy_s(s, "svdsolve() : could not allocate workspace");
            break;
        case -2: strcpy_s(s, "svdsolve() : invalid user input");
            break;
        default: strcpy_s(s, "svdsolve() : no such error");
        };
        break;

    case TRIDIAG_C:
        switch (flag)
        {
        case 0: strcpy_s(s, "tridiag() : normal return");
            break;
        case 1: strcpy_s(s, "tridiag() : elimination failure");
            break;
        case 2: strcpy_s(s, "tridiag() : illegal user input");
            break;
        default: strcpy_s(s, "tridiag() : no such error");
        };
        break;

    case TRISOLVE_C:
        switch (flag)
        {
        case 0: strcpy_s(s, "trisolve() : normal return");
            break;
        case 1: strcpy_s(s, "trisolve() : back-substitution failure");
            break;
        default: strcpy_s(s, "trisolve() : no such error");
        };
        break;

    case INVERT_C:
        switch (flag)
        {
        case 0: strcpy_s(s, "invert() : normal return");
            break;
        case 1: strcpy_s(s, "invert() : matrix is singular");
            break;
        case 2: strcpy_s(s, "invert() : could not allocate workspace");
            break;
        case 3: strcpy_s(s, "invert() : invalid user input");
            break;
        default: strcpy_s(s, "invert() : no such error");
        };
        break;

    case QR_C:
        if (flag > 0)
        {
            strcpy_s(s, "qr() : too many iterations required");
        }
        else
        {
            switch (flag)
            {
            case 0: strcpy_s(s, "qr() : normal return");
                break;
            case -1: strcpy_s(s, "qr() : could not allocate workspace");
                break;
            case -2: strcpy_s(s, "qr() : invalid user input");
                break;
            default: strcpy_s(s, "qr() : no such error");
            };
        }
        break;

    case QRV_C:
        if (flag > 0)
        {
            strcpy_s(s, "qrv() : too many iterations required");
        }
        else
        {
            switch (flag)
            {
            case 0: strcpy_s(s, "qrv() : normal return");
                break;
            case -1: strcpy_s(s, "qrv() : could not allocate workspace");
                break;
            case -2: strcpy_s(s, "qrv() : invalid user input");
                break;
            default: strcpy_s(s, "qrv() : no such error");
            };
        }
        break;

    case QRVECTOR_C:
        switch (flag)
        {
        case 0: strcpy_s(s, "qrvector() : normal return");
            break;
        case 1: strcpy_s(s, "qrvector() : invalid user input");
            break;
        case 2: strcpy_s(s, "qrvector() : could not find conjugate");
            break;
        default: strcpy_s(s, "qrvector() : no such error");
        };
        break;

    case ZEROIN_C:
        switch (flag)
        {
        case 0: strcpy_s(s, "zeroin() : normal return");
            break;
        case 1: strcpy_s(s, "zeroin() : could not bracket a zero");
            break;
        case 2: strcpy_s(s, "zeroin() : invalid user input");
            break;
        default: strcpy_s(s, "zeroin() : no such error");
        };
        break;

    case ZEROV_C:
        switch (flag)
        {
        case 0: strcpy_s(s, "zerov() : normal return");
            break;
        case 1: strcpy_s(s, "zerov() : invalid user input");
            break;
        case 2: strcpy_s(s, "zerov() : could not allocate workspace");
            break;
        case 3: strcpy_s(s, "zerov() : minimizer did not converge");
            break;
        case 4: strcpy_s(s, "zerov() : local minimum is not a zero");
            break;
        case 5: strcpy_s(s, "zerov() : Newton-Raphson diverging");
            break;
        case 6: strcpy_s(s, "zerov() : singular Jacobian");
            break;
        default: strcpy_s(s, "zerov() : no such error");
        };
        break;

    case POLYROOT_C:
        switch (flag)
        {
        case 0: strcpy_s(s, "polyroot() : normal return");
            break;
        case 1: strcpy_s(s, "polyroot() : a root did not converge");
            break;
        case 2: strcpy_s(s, "polyroot() : could not allocate workspace");
            break;
        case 3: strcpy_s(s, "polyroot() : invalid user input");
            break;
        case 4: strcpy_s(s, "polyroot() : invalid order for polynomial");
            break;
        default: strcpy_s(s, "polyroot() : no such error");
        };
        break;

    case SPLINE_C:
        switch (flag)
        {
        case 0: strcpy_s(s, "spline() : normal return");
            break;
        case 1: strcpy_s(s, "spline() : n < 2, cannot interpolate");
            break;
        case 2: strcpy_s(s, "spline() : x[i] not in ascending order");
            break;
        default: strcpy_s(s, "spline() : no such error");
        };
        break;

    case FITSPL_C:
        switch (flag)
        {
        case 0: strcpy_s(s, "fitspl() : normal return");
            break;
        case 1: strcpy_s(s, "fitspl() : illegal values for ns, nd");
            break;
        case 2: strcpy_s(s, "fitspl() : xs[i] not in ascending order");
            break;
        case 3: strcpy_s(s, "fitspl() : all weights are not positive");
            break;
        case 4: strcpy_s(s, "fitspl() : could not allocate workspace");
            break;
        case 5: strcpy_s(s, "fitspl() : minimizer did not converge");
            break;
        default: strcpy_s(s, "fitspl() : no such error");
        };
        break;

    case FITPOLY_C:
        switch (flag)
        {
        case 0: strcpy_s(s, "fitpoly() : normal return");
            break;
        case 1: strcpy_s(s, "fitpoly() : illegal values for ns, m");
            break;
        case 2: strcpy_s(s, "fitpoly() : x[i] not in range [a, b]");
            break;
        case 3: strcpy_s(s, "fitpoly() : all weights are not positive");
            break;
        case 4: strcpy_s(s, "fitpoly() : could not allocate workspace");
            break;
        case 5: strcpy_s(s, "fitpoly() : solution failed");
            break;
        default: strcpy_s(s, "fitpoly() : no such error");
        };
        break;

    case LSP_C:
        if (flag > 0)
        {
            strcpy_s(s, "lsp() : too many iterations required");
        }
        else
        {
            switch (flag)
            {
            case 0: strcpy_s(s, "lsp() : normal return");
                break;
            case -1: strcpy_s(s, "lsp() : could not allocate workspace");
                break;
            case -2: strcpy_s(s, "lsp() : invalid user input");
                break;
            default: strcpy_s(s, "lsp() : no such error");
            };
        }
        break;

    case CHEBY_C:
        switch (flag)
        {
        case 0: strcpy_s(s, "cheby() : normal return");
            break;
        case 1: strcpy_s(s, "cheby() : invalid user input");
            break;
        default: strcpy_s(s, "cheby() : no such error");
        };
        break;

    case CHEBYC_C:
        switch (flag)
        {
        case 0: strcpy_s(s, "chebyc() : normal return");
            break;
        case 1: strcpy_s(s, "chebyc() : invalid user input");
            break;
        case 2: strcpy_s(s, "chebyc() : cannot allocate workspace");
            break;
        default: strcpy_s(s, "chebyc() : no such error");
        };
        break;

    case CHEBYD_C:
        switch (flag)
        {
        case 0: strcpy_s(s, "chebyd() : normal return");
            break;
        case 1: strcpy_s(s, "chebyd() : invalid user input");
            break;
        default: strcpy_s(s, "chebyd() : no such error");
        };
        break;

    case CHEBYI_C:
        switch (flag)
        {
        case 0: strcpy_s(s, "chebyi() : normal return");
            break;
        case 1: strcpy_s(s, "chebyi() : invalid user input");
            break;
        default: strcpy_s(s, "chebyi() : no such error");
        };
        break;

    case QK21INIT_C:
        strcpy_s(s, "qk21init() : no such error");
        break;

    case QK21_C:
        strcpy_s(s, "qk21() : no such error");
        break;

    case QAGS_C:
        switch (flag)
        {
        case 0: strcpy_s(s, "qags() : normal return");
            break;
        case 1: strcpy_s(s, "qags() : maximum subdivisions reached");
            break;
        case 2: strcpy_s(s, "qags() : round-off error detected");
            break;
        case 3: strcpy_s(s, "qags() : badly behaved integrand");
            break;
        case 4: strcpy_s(s, "qags() : integral has not converged");
            break;
        case 5: strcpy_s(s, "qags() : integral divergent");
            break;
        case 6: strcpy_s(s, "qags() : invalid user input");
            break;
        default: strcpy_s(s, "qags() : no such error");
        };
        break;

    case QINF_C:
        switch (flag)
        {
        case 0: strcpy_s(s, "qinf() : normal return");
            break;
        case 1: strcpy_s(s, "qinf() : maximum subdivisions reached");
            break;
        case 2: strcpy_s(s, "qinf() : round-off error detected");
            break;
        case 3: strcpy_s(s, "qinf() : badly behaved integrand");
            break;
        case 4: strcpy_s(s, "qinf() : integral has not converged");
            break;
        case 5: strcpy_s(s, "qinf() : integral divergent");
            break;
        case 6: strcpy_s(s, "qinf() : invalid user input");
            break;
        default: strcpy_s(s, "qinf() : no such error");
        };
        break;

    case QUANC8_C:
        if (flag < 0)
            strcpy_s(s, "quanc8() : result unreliable");
        else
        {
            switch (flag)
            {
            case 0: strcpy_s(s, "quanc8() : normal return");
                break;
            case 1: strcpy_s(s, "quanc8() : invalid user input");
                break;
            default: strcpy_s(s, "quanc8() : no such error");
            };
        }
        break;

    case RKFINIT_C:
        switch (flag)
        {
        case 0: strcpy_s(s, "rkfinit() : normal return");
            break;
        case 1: strcpy_s(s, "rkfinit() : could not allocate workspace");
            break;
        case 2: strcpy_s(s, "rkfinit() : illegal value for n");
            break;
        default: strcpy_s(s, "rkfinit() : no such error");
        };
        break;

    case RKF45_C:
        switch (flag)
        {
        case -2: strcpy_s(s, "rkf45() : normal return");
            break;
        case  2: strcpy_s(s, "rkf45() : normal return");
            break;
        case  3: strcpy_s(s, "rkf45() : relerr too small");
            break;
        case  4: strcpy_s(s, "rkf45() : too many steps");
            break;
        case  5: strcpy_s(s, "rkf45() : abserr needs to be nonzero");
            break;
        case  6: strcpy_s(s, "rkf45() : stepsize has become too small");
            break;
        case  7: strcpy_s(s, "rkf45() : rkf45 is inefficient");
            break;
        case  8: strcpy_s(s, "rkf45() : invalid user input");
            break;
        default: strcpy_s(s, "rkf45() : no such error");
        };
        break;

    case RKFEND_C:
        strcpy_s(s, "rkfend() : no such error");
        break;

    case STINT0_C:
        switch (flag)
        {
        case 0: strcpy_s(s, "stint0() : normal return");
            break;
        case 1: strcpy_s(s, "stint0() : illegal value for n");
            break;
        case 2: strcpy_s(s, "stint0() : could not allocate workspace");
            break;
        default: strcpy_s(s, "stint0() : no such error");
        };
        break;

    case STINT1_C:
        if (flag > 0)
        {
            strcpy_s(s, "stint1() : normal return");
        }
        else
        {
            switch (flag)
            {
            case -1: strcpy_s(s, "stint1() : 1 step, step size too small");
                break;
            case -2: strcpy_s(s, "stint1() : 2 steps, step size too small");
                break;
            case -3: strcpy_s(s, "stint1() : 3 steps, step size too small");
                break;
            case -4: strcpy_s(s, "stint1() : 4 steps, step size too small");
                break;
            case -5: strcpy_s(s, "stint1() : requested precision too small");
                break;
            case -6: strcpy_s(s, "stint1() : corrector did not converge");
                break;
            default: strcpy_s(s, "stint1() : no such error");
            };
        }
        break;

    case STINT2_C:
        strcpy_s(s, "stint2() : errors unavailable, check source code");
        break;

    case STINT3_C:
        strcpy_s(s, "stint3() : no such error");
        break;

    case NELMIN_C:
        switch (flag)
        {
        case 0: strcpy_s(s, "nelmin() : normal return");
            break;
        case 1: strcpy_s(s, "nelmin() : invalid user input");
            break;
        case 2: strcpy_s(s, "nelmin() : too many steps taken");
            break;
        case 3: strcpy_s(s, "nelmin() : could not allocate workspace");
            break;
        default: strcpy_s(s, "nelmin() : no such error");
        };
        break;

    case CONJGG_C:
        switch (flag)
        {
        case 0: strcpy_s(s, "conjgg() : normal return");
            break;
        case 1: strcpy_s(s, "conjgg() : too many 1-D searches needed");
            break;
        case 2: strcpy_s(s, "conjgg() : could not bracket a minimum");
            break;
        case 3: strcpy_s(s, "conjgg() : could not allocate workspace");
            break;
        case 4: strcpy_s(s, "conjgg() : invalid user input");
            break;
        default: strcpy_s(s, "conjgg() : no such error");
        };
        break;

    case FFT_C:
        switch (flag)
        {
        case 0: strcpy_s(s, "fft() : normal return");
            break;
        case 1: strcpy_s(s, "fft() : invalid user input");
            break;
        case 2: strcpy_s(s, "fft() : n is not an integer power of 2");
            break;
        case 3: strcpy_s(s, "fft() : direct not +1 or -1");
            break;
        default: strcpy_s(s, "fft() : no such error");
        };
        break;

    case DFT_C:
        switch (flag)
        {
        case 0: strcpy_s(s, "dft() : normal return");
            break;
        case 1: strcpy_s(s, "dft() : invalid user input");
            break;
        case 2: strcpy_s(s, "dft() : n2 is not an integer power of 2");
            break;
        case 3: strcpy_s(s, "dft() : direct not +1 or -1");
            break;
        default: strcpy_s(s, "dft() : no such error");
        };
        break;

    case CHIRP_C:
        switch (flag)
        {
        case 0: strcpy_s(s, "chirp() : normal return");
            break;
        case 1: strcpy_s(s, "chirp() : invalid user input");
            break;
        case 2: strcpy_s(s, "chirp() : n2 not a power of 2 or too small");
            break;
        default: strcpy_s(s, "chirp() : no such error");
        };
        break;

    case CDIVSN_C:
        strcpy_s(s, "cdivsn() : no such error");
        break;

    case CMULTN_C:
        strcpy_s(s, "cmultn() : no such error");
        break;

    case CSQROOT_C:
        strcpy_s(s, "csqroot() : no such error");
        break;

    case CABSLT_C:
        strcpy_s(s, "cabslt() : no such error");
        break;

    case INDEXX_C:
        strcpy_s(s, "indexx() : no such error");
        break;

    case CMATHMSG_C:
        strcpy_s(s, "cmathmsg() : no such error");
        break;

    default: strcpy_s(s, "CMATH : no such routine");
    }
    return (s);
}
