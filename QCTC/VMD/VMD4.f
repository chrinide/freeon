        SUBROUTINE VMD4(NQ,Px,Py,Pz,Omega,Upq,Tol,                       
     $          rQx,rQy,rQz,rQt,RhoCo,HGKet)
       IMPLICIT REAL*8(a-h,o-z)
       IMPLICIT INTEGER(i-n)
       REAL*8 rQx(*)
       REAL*8 rQy(*)
       REAL*8 rQz(*)
       REAL*8 rQt(*)
       REAL*8 RhoCo(*)
       REAL*8 HGKet(*)
       PARAMETER (Mesh=968)
       REAL*8 F4_0(0:Mesh),F4_1(0:Mesh),F4_2(0:Mesh),F4_3(0:Mesh)        
       INCLUDE "Gamma_4.Inc"                                                            
       INCLUDE "Gamma_Asymptotics.Inc"
       IF(rQt(1).LT.Tol)THEN
          RETURN
       ELSEIF(rQt(NQ).GT.Tol)THEN
          N=NQ
       ELSE
          K=0
          L=NQ
          N=NQ/2
  102     CONTINUE
          IF(rQt(N).LT.Tol)THEN
             L=N
          ELSE
             K=N
          ENDIF
          N=(K+L)/2
          IF((K.LT.N).AND.(N.LT.L))GOTO 102
       ENDIF
       DO 100 iq=1,N
          jadd=(iq-1)*35                                                       
          QPx=rQx(iq)-Px
          QPy=rQy(iq)-Py
          QPz=rQz(iq)-Pz
          T=Omega*(QPx*QPx+QPy*QPy+QPz*QPz)
          o1=Upq
          o2=-2.0D0*Omega
          IF(T.LT.Switch)THEN
             j=AINT(T*Grid)                                              
             T2=T*T                                                      
             T3=T2*T                                                     
             G4=(F4_0(j)+T*F4_1(j)+T2*F4_2(j)+T3*F4_3(j))                
             ET=DEXP(-T)
             TwoT=2.0D0*T
             G3=0.142857142857143D+00*(TwoT*G4+ET)                       
             G2=0.200000000000000D+00*(TwoT*G3+ET)                       
             G1=0.333333333333333D+00*(TwoT*G2+ET)                       
             G0=TwoT*G1+ET                                               
             Aux0=o1*G0                                                  
             o1=o2*o1
             Aux1=o1*G1                                                  
             o1=o2*o1
             Aux2=o1*G2                                                  
             o1=o2*o1
             Aux3=o1*G3                                                  
             o1=o2*o1
             Aux4=o1*G4                                                  
          ELSE                                                           
             t1=1.0D0/T                                                  
             t1x2=Upq*DSQRT(T1)                                          
             t1=o2*t1                                                    
             Aux0=F0Asymp*t1x2                                           
             t1x2=t1x2*t1                                                
             Aux1=F1Asymp*t1x2                                           
             t1x2=t1x2*t1                                                
             Aux2=F2Asymp*t1x2                                           
             t1x2=t1x2*t1                                                
             Aux3=F3Asymp*t1x2                                           
             t1x2=t1x2*t1                                                
             Aux4=F4Asymp*t1x2                                           
          ENDIF                                                          
          r1=Aux4                                                        
          r2=QPx*r1                                                      
          r3=QPy*r1                                                      
          r4=QPz*r1                                                      
          r1=Aux3                                                        
          r5=QPx*r2+r1                                                   
          r7=QPy*r3+r1                                                   
          r10=QPz*r4+r1                                                  
          r2=QPx*r1                                                      
          r6=QPx*r3                                                      
          r9=QPy*r4                                                      
          r8=QPx*r4                                                      
          r3=QPy*r1                                                      
          r4=QPz*r1                                                      
          r1=Aux2                                                        
          r11=QPx*r5+.20000D+01*r2                                       
          r14=QPy*r7+.20000D+01*r3                                       
          r20=QPz*r10+.20000D+01*r4                                      
          r5=QPx*r2+r1                                                   
          r13=QPx*r7                                                     
          r19=QPy*r10                                                    
          r18=QPx*r10                                                    
          r7=QPy*r3+r1                                                   
          r10=QPz*r4+r1                                                  
          r2=QPx*r1                                                      
          r12=QPx*r6+r3                                                  
          r17=QPy*r9+r4                                                  
          r15=QPx*r8+r4                                                  
          r6=QPx*r3                                                      
          r16=QPx*r9                                                     
          r9=QPy*r4                                                      
          r8=QPx*r4                                                      
          r3=QPy*r1                                                      
          r4=QPz*r1                                                      
          r1=Aux1                                                        
          r21=QPx*r11+.30000D+01*r5                                      
          r25=QPy*r14+.30000D+01*r7                                      
          r35=QPz*r20+.30000D+01*r10                                     
          r11=QPx*r5+.20000D+01*r2                                       
          r24=QPx*r14                                                    
          r34=QPy*r20                                                    
          r33=QPx*r20                                                    
          r14=QPy*r7+.20000D+01*r3                                       
          r20=QPz*r10+.20000D+01*r4                                      
          r5=QPx*r2+r1                                                   
          r23=QPx*r13+r7                                                 
          r32=QPy*r19+r10                                                
          r30=QPx*r18+r10                                                
          r13=QPx*r7                                                     
          r31=QPx*r19                                                    
          r19=QPy*r10                                                    
          r18=QPx*r10                                                    
          r7=QPy*r3+r1                                                   
          r10=QPz*r4+r1                                                  
          r2=QPx*r1                                                      
          r22=QPx*r12+.20000D+01*r6                                      
          r29=QPy*r17+.20000D+01*r9                                      
          r26=QPx*r15+.20000D+01*r8                                      
          r12=QPx*r6+r3                                                  
          r28=QPx*r17                                                    
          r17=QPy*r9+r4                                                  
          r15=QPx*r8+r4                                                  
          r6=QPx*r3                                                      
          r27=QPx*r16+r9                                                 
          r16=QPx*r9                                                     
          r9=QPy*r4                                                      
          r8=QPx*r4                                                      
          r3=QPy*r1                                                      
          r4=QPz*r1                                                      
          r1=Aux0                                                        
          HGKet(1)=HGKet(1)+r1*RhoCo(jadd+1)                             
          HGKet(1)=HGKet(1)+r2*RhoCo(jadd+2)                             
          HGKet(1)=HGKet(1)+r3*RhoCo(jadd+3)                             
          HGKet(1)=HGKet(1)+r4*RhoCo(jadd+4)                             
          HGKet(1)=HGKet(1)+r5*RhoCo(jadd+5)                             
          HGKet(1)=HGKet(1)+r6*RhoCo(jadd+6)                             
          HGKet(1)=HGKet(1)+r7*RhoCo(jadd+7)                             
          HGKet(1)=HGKet(1)+r8*RhoCo(jadd+8)                             
          HGKet(1)=HGKet(1)+r9*RhoCo(jadd+9)                             
          HGKet(1)=HGKet(1)+r10*RhoCo(jadd+10)                           
          HGKet(1)=HGKet(1)+r11*RhoCo(jadd+11)                           
          HGKet(1)=HGKet(1)+r12*RhoCo(jadd+12)                           
          HGKet(1)=HGKet(1)+r13*RhoCo(jadd+13)                           
          HGKet(1)=HGKet(1)+r14*RhoCo(jadd+14)                           
          HGKet(1)=HGKet(1)+r15*RhoCo(jadd+15)                           
          HGKet(1)=HGKet(1)+r16*RhoCo(jadd+16)                           
          HGKet(1)=HGKet(1)+r17*RhoCo(jadd+17)                           
          HGKet(1)=HGKet(1)+r18*RhoCo(jadd+18)                           
          HGKet(1)=HGKet(1)+r19*RhoCo(jadd+19)                           
          HGKet(1)=HGKet(1)+r20*RhoCo(jadd+20)                           
          HGKet(1)=HGKet(1)+r21*RhoCo(jadd+21)                           
          HGKet(1)=HGKet(1)+r22*RhoCo(jadd+22)                           
          HGKet(1)=HGKet(1)+r23*RhoCo(jadd+23)                           
          HGKet(1)=HGKet(1)+r24*RhoCo(jadd+24)                           
          HGKet(1)=HGKet(1)+r25*RhoCo(jadd+25)                           
          HGKet(1)=HGKet(1)+r26*RhoCo(jadd+26)                           
          HGKet(1)=HGKet(1)+r27*RhoCo(jadd+27)                           
          HGKet(1)=HGKet(1)+r28*RhoCo(jadd+28)                           
          HGKet(1)=HGKet(1)+r29*RhoCo(jadd+29)                           
          HGKet(1)=HGKet(1)+r30*RhoCo(jadd+30)                           
          HGKet(1)=HGKet(1)+r31*RhoCo(jadd+31)                           
          HGKet(1)=HGKet(1)+r32*RhoCo(jadd+32)                           
          HGKet(1)=HGKet(1)+r33*RhoCo(jadd+33)                           
          HGKet(1)=HGKet(1)+r34*RhoCo(jadd+34)                           
          HGKet(1)=HGKet(1)+r35*RhoCo(jadd+35)                           
  100  CONTINUE
       RETURN
       END
  
