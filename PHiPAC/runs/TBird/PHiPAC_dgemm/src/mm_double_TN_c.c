/*
**
** PHiPAC Matrix-Matrix Code for the operation:
**    C = alpha*transpose(A)*B + beta*C
**
** Automatically Generated by mm_cgen ($Revision: 1.2 $) using the command:
**    ./mm_cgen -prec double -opA T -opB N -alpha c -ignore_m1 -sp 1 -holdstripe B -l0 5 15 1 -file ./src/mm_double_TN_c.c -routine_name mm_double_TN_c -beta c 
**
** Run './mm_cgen -help' for help.
**
** Generated on: Saturday August 18 2001, 07:05:09 MDT
** Created by: Jeff Bilmes <bilmes@cs.berkeley.edu>
**             http://www.icsi.berkeley.edu/~bilmes/phipac
**
**
** Routine Usage: General (M,K,N) = (M, K, N) matrix multiply
**    mm_double_TN_c(const int M, const int K, const int N, const double *const A, const double *const B, double *const C, const int Astride, const int Bstride, const int Cstride, const double alpha, const double beta)
** where
**  transpose(A) is an MxK matrix
**  B is an KxN matrix
**  C is an MxN matrix
**  Astride is the number of entries between the start of each row of A
**  Bstride is the number of entries between the start of each row of B
**  Cstride is the number of entries between the start of each row of C
**
**
** "Copyright (c) 1995 The Regents of the University of California.  All
** rights reserved."  Permission to use, copy, modify, and distribute
** this software and its documentation for any purpose, without fee, and
** without written agreement is hereby granted, provided that the above
** copyright notice and the following two paragraphs appear in all copies
** of this software.
**
** IN NO EVENT SHALL THE UNIVERSITY OF CALIFORNIA BE LIABLE TO ANY PARTY FOR
** DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES ARISING OUT
** OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF THE UNIVERSITY OF
** CALIFORNIA HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
** THE UNIVERSITY OF CALIFORNIA SPECIFICALLY DISCLAIMS ANY WARRANTIES,
** INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
** AND FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS
** ON AN "AS IS" BASIS, AND THE UNIVERSITY OF CALIFORNIA HAS NO OBLIGATION TO
** PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.
**
*/

/*
 * General (M,K,N) = (M, K, N) matrix multiply
 */

#define NO_MB

void
mm_double_TN_c(const int M, const int K, const int N, const double *const A, const double *const B, double *const C, const int Astride, const int Bstride, const int Cstride, const double alpha, const double beta)
{
   const double *a;
   const double *b;
   double *c;
   const double *ap;
   const double *bp;
   double *cp;
   const int C_sbs_stride = Cstride*5;
   const int k_marg_el = K % 15;
   const int k_norm = (K - k_marg_el)*Astride;
   const int m_marg_el = M % 5;
   const int m_norm = M - m_marg_el;
   const int n_marg_el = N & 0;
   const int n_norm = N - n_marg_el;
   double *const c_endp = C+m_norm*Cstride;
   register double c0_0,c1_0,c2_0,c3_0,c4_0;
   if (beta == 0.0) {
      double *cprb,*cpre,*cp,*cpe;
      cpre = C + M*Cstride;
      for (cprb = C; cprb != cpre; cprb += Cstride) {
         cpe = cprb + N;
         for (cp = cprb; cp != cpe; cp++) {
            *cp = 0.0;
         }
      }
   } else if (beta != 1.0) {
      double *cprb,*cpre,*cp,*cpe;
      cpre = C + M*Cstride;
      for (cprb = C; cprb != cpre; cprb += Cstride) {
         cpe = cprb + N;
         for (cp = cprb; cp != cpe; cp++) {
            *cp *= (beta);
         }
      }
   }
   for (c=C,a=A; c!= c_endp; c+=C_sbs_stride,a+=5) {
      const double* const ap_endp = a + k_norm;
      double* const cp_endp = c + n_norm;
      for (b=B,cp=c; cp!=cp_endp; b+=1,cp+=1) {
         register double _b0;
         register double _a0,_a1,_a2,_a3,_a4;
         double *_cp;
         ap=a;
         bp=b;
         c0_0 = 0.0; 
         c1_0 = 0.0; 
         c2_0 = 0.0; 
         c3_0 = 0.0; 
         c4_0 = 0.0; 
         for (;ap!=ap_endp; ) {
            /* Fixed M,K,N = 5,15,1 fully-unrolled matrix matrix multiply. */
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            _a4 = ap[4];
            c4_0 += _a4*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            _a4 = ap[4];
            c4_0 += _a4*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            _a4 = ap[4];
            c4_0 += _a4*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            _a4 = ap[4];
            c4_0 += _a4*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            _a4 = ap[4];
            c4_0 += _a4*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            _a4 = ap[4];
            c4_0 += _a4*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            _a4 = ap[4];
            c4_0 += _a4*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            _a4 = ap[4];
            c4_0 += _a4*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            _a4 = ap[4];
            c4_0 += _a4*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            _a4 = ap[4];
            c4_0 += _a4*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            _a4 = ap[4];
            c4_0 += _a4*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            _a4 = ap[4];
            c4_0 += _a4*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            _a4 = ap[4];
            c4_0 += _a4*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            _a4 = ap[4];
            c4_0 += _a4*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            _a4 = ap[4];
            c4_0 += _a4*_b0; 
            ap += Astride;

         }
         if (k_marg_el & 0x8) {
            /* Fixed M,K,N = 5,8,1 fully-unrolled matrix matrix multiply. */
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            _a4 = ap[4];
            c4_0 += _a4*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            _a4 = ap[4];
            c4_0 += _a4*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            _a4 = ap[4];
            c4_0 += _a4*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            _a4 = ap[4];
            c4_0 += _a4*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            _a4 = ap[4];
            c4_0 += _a4*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            _a4 = ap[4];
            c4_0 += _a4*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            _a4 = ap[4];
            c4_0 += _a4*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            _a4 = ap[4];
            c4_0 += _a4*_b0; 
            ap += Astride;

         }
         if (k_marg_el & 0x4) {
            /* Fixed M,K,N = 5,4,1 fully-unrolled matrix matrix multiply. */
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            _a4 = ap[4];
            c4_0 += _a4*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            _a4 = ap[4];
            c4_0 += _a4*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            _a4 = ap[4];
            c4_0 += _a4*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            _a4 = ap[4];
            c4_0 += _a4*_b0; 
            ap += Astride;

         }
         if (k_marg_el & 0x2) {
            /* Fixed M,K,N = 5,2,1 fully-unrolled matrix matrix multiply. */
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            _a4 = ap[4];
            c4_0 += _a4*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            _a4 = ap[4];
            c4_0 += _a4*_b0; 
            ap += Astride;

         }
         if (k_marg_el & 0x1) {
            /* Fixed M,K,N = 5,1,1 fully-unrolled matrix matrix multiply. */
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            _a4 = ap[4];
            c4_0 += _a4*_b0; 
            ap += Astride;

         }
         _cp=cp;_cp[0]+=alpha*c0_0;
         _cp+=Cstride;_cp[0]+=alpha*c1_0;
         _cp+=Cstride;_cp[0]+=alpha*c2_0;
         _cp+=Cstride;_cp[0]+=alpha*c3_0;
         _cp+=Cstride;_cp[0]+=alpha*c4_0;
      }
   }
   if (m_marg_el & 0x4) {
      const double* const ap_endp = a + k_norm;
      double* const cp_endp = c + n_norm;
      for (b=B,cp=c; cp!=cp_endp; b+=1,cp+=1) {
         register double _b0;
         register double _a0,_a1,_a2,_a3;
         double *_cp;
         ap=a;
         bp=b;
         c0_0 = 0.0; 
         c1_0 = 0.0; 
         c2_0 = 0.0; 
         c3_0 = 0.0; 
         for (;ap!=ap_endp; ) {
            /* Fixed M,K,N = 4,15,1 fully-unrolled matrix matrix multiply. */
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            ap += Astride;

         }
         if (k_marg_el & 0x8) {
            /* Fixed M,K,N = 4,8,1 fully-unrolled matrix matrix multiply. */
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            ap += Astride;

         }
         if (k_marg_el & 0x4) {
            /* Fixed M,K,N = 4,4,1 fully-unrolled matrix matrix multiply. */
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            ap += Astride;

         }
         if (k_marg_el & 0x2) {
            /* Fixed M,K,N = 4,2,1 fully-unrolled matrix matrix multiply. */
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            ap += Astride;

         }
         if (k_marg_el & 0x1) {
            /* Fixed M,K,N = 4,1,1 fully-unrolled matrix matrix multiply. */
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            _a2 = ap[2];
            c2_0 += _a2*_b0; 
            _a3 = ap[3];
            c3_0 += _a3*_b0; 
            ap += Astride;

         }
         _cp=cp;_cp[0]+=alpha*c0_0;
         _cp+=Cstride;_cp[0]+=alpha*c1_0;
         _cp+=Cstride;_cp[0]+=alpha*c2_0;
         _cp+=Cstride;_cp[0]+=alpha*c3_0;
      }
      c += Cstride*4;
      a += 4;
   }
   if (m_marg_el & 0x2) {
      const double* const ap_endp = a + k_norm;
      double* const cp_endp = c + n_norm;
      for (b=B,cp=c; cp!=cp_endp; b+=1,cp+=1) {
         register double _b0;
         register double _a0,_a1;
         double *_cp;
         ap=a;
         bp=b;
         c0_0 = 0.0; 
         c1_0 = 0.0; 
         for (;ap!=ap_endp; ) {
            /* Fixed M,K,N = 2,15,1 fully-unrolled matrix matrix multiply. */
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            ap += Astride;

         }
         if (k_marg_el & 0x8) {
            /* Fixed M,K,N = 2,8,1 fully-unrolled matrix matrix multiply. */
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            ap += Astride;

         }
         if (k_marg_el & 0x4) {
            /* Fixed M,K,N = 2,4,1 fully-unrolled matrix matrix multiply. */
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            ap += Astride;

         }
         if (k_marg_el & 0x2) {
            /* Fixed M,K,N = 2,2,1 fully-unrolled matrix matrix multiply. */
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            ap += Astride;

         }
         if (k_marg_el & 0x1) {
            /* Fixed M,K,N = 2,1,1 fully-unrolled matrix matrix multiply. */
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            _a1 = ap[1];
            c1_0 += _a1*_b0; 
            ap += Astride;

         }
         _cp=cp;_cp[0]+=alpha*c0_0;
         _cp+=Cstride;_cp[0]+=alpha*c1_0;
      }
      c += Cstride*2;
      a += 2;
   }
   if (m_marg_el & 0x1) {
      const double* const ap_endp = a + k_norm;
      double* const cp_endp = c + n_norm;
      for (b=B,cp=c; cp!=cp_endp; b+=1,cp+=1) {
         register double _b0;
         register double _a0;
         double *_cp;
         ap=a;
         bp=b;
         c0_0 = 0.0; 
         for (;ap!=ap_endp; ) {
            /* Fixed M,K,N = 1,15,1 fully-unrolled matrix matrix multiply. */
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            ap += Astride;

         }
         if (k_marg_el & 0x8) {
            /* Fixed M,K,N = 1,8,1 fully-unrolled matrix matrix multiply. */
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            ap += Astride;

         }
         if (k_marg_el & 0x4) {
            /* Fixed M,K,N = 1,4,1 fully-unrolled matrix matrix multiply. */
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            ap += Astride;

         }
         if (k_marg_el & 0x2) {
            /* Fixed M,K,N = 1,2,1 fully-unrolled matrix matrix multiply. */
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            ap += Astride;
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            ap += Astride;

         }
         if (k_marg_el & 0x1) {
            /* Fixed M,K,N = 1,1,1 fully-unrolled matrix matrix multiply. */
            
            _b0 = bp[0]; 
            bp += Bstride;
            _a0 = ap[0];
            c0_0 += _a0*_b0; 
            ap += Astride;

         }
         _cp=cp;_cp[0]+=alpha*c0_0;
      }
   }
}
