!------------------------------------------------------------------------------
!    This code is part of the MondoSCF suite of programs for linear scaling
!    electronic structure theory and ab initio molecular dynamics.
!
!    Copyright (2004). The Regents of the University of California. This
!    material was produced under U.S. Government contract W-7405-ENG-36
!    for Los Alamos National Laboratory, which is operated by the University
!    of California for the U.S. Department of Energy. The U.S. Government has
!    rights to use, reproduce, and distribute this software.  NEITHER THE
!    GOVERNMENT NOR THE UNIVERSITY MAKES ANY WARRANTY, EXPRESS OR IMPLIED,
!    OR ASSUMES ANY LIABILITY FOR THE USE OF THIS SOFTWARE.
!
!    This program is free software; you can redistribute it and/or modify
!    it under the terms of the GNU General Public License as published by the
!    Free Software Foundation; either version 2 of the License, or (at your
!    option) any later version. Accordingly, this program is distributed in
!    the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
!    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
!    PURPOSE. See the GNU General Public License at www.gnu.org for details.
!
!    While you may do as you like with this software, the GNU license requires
!    that you clearly mark derivative software.  In addition, you are encouraged
!    to return derivative works to the MondoSCF group for review, and possible
!    disemination in future releases.
!------------------------------------------------------------------------------
      SUBROUTINE CTraX107(Q)
         USE PoleNodeType
         USE PoleGlobals
         USE ERIGlobals
         TYPE(PoleNode) :: Q
!       -------------------------------- Lp=0, Mp = 0-------------------------------------
        W(1)=Cpq(0)*Q%C(0)+Cpq(1)*Q%C(1)+Cpq(3)*Q%C(3)+Cpq(6)*Q%C(6)
        W(2)=Cpq(10)*Q%C(10)+Cpq(15)*Q%C(15)+Cpq(21)*Q%C(21)+Cpq(28)*Q%C(28)
        COne=W(1)+W(2)
        W(1)=Cpq(2)*Q%C(2)+Cpq(4)*Q%C(4)+Cpq(5)*Q%C(5)
        W(2)=Cpq(7)*Q%C(7)+Cpq(8)*Q%C(8)+Cpq(9)*Q%C(9)+Cpq(11)*Q%C(11)
        W(3)=Cpq(12)*Q%C(12)+Cpq(13)*Q%C(13)+Cpq(14)*Q%C(14)
        W(4)=Cpq(16)*Q%C(16)+Cpq(17)*Q%C(17)+Cpq(18)*Q%C(18)+Cpq(19)*Q%C(19)
        W(5)=Cpq(20)*Q%C(20)+Cpq(22)*Q%C(22)+Cpq(23)*Q%C(23)
        W(6)=Cpq(24)*Q%C(24)+Cpq(25)*Q%C(25)+Cpq(26)*Q%C(26)+Cpq(27)*Q%C(27)
        W(7)=Cpq(29)*Q%C(29)+Cpq(30)*Q%C(30)+Cpq(31)*Q%C(31)
        W(8)=Cpq(32)*Q%C(32)+Cpq(33)*Q%C(33)+Cpq(34)*Q%C(34)+Cpq(35)*Q%C(35)
        W(9)=Spq(2)*Q%S(2)+Spq(4)*Q%S(4)+Spq(5)*Q%S(5)
        W(10)=Spq(7)*Q%S(7)+Spq(8)*Q%S(8)+Spq(9)*Q%S(9)+Spq(11)*Q%S(11)
        W(11)=Spq(12)*Q%S(12)+Spq(13)*Q%S(13)+Spq(14)*Q%S(14)
        W(12)=Spq(16)*Q%S(16)+Spq(17)*Q%S(17)+Spq(18)*Q%S(18)+Spq(19)*Q%S(19)
        W(13)=Spq(20)*Q%S(20)+Spq(22)*Q%S(22)+Spq(23)*Q%S(23)
        W(14)=Spq(24)*Q%S(24)+Spq(25)*Q%S(25)+Spq(26)*Q%S(26)+Spq(27)*Q%S(27)
        W(15)=Spq(29)*Q%S(29)+Spq(30)*Q%S(30)+Spq(31)*Q%S(31)
        W(16)=Spq(32)*Q%S(32)+Spq(33)*Q%S(33)+Spq(34)*Q%S(34)+Spq(35)*Q%S(35)
        W(17)=W(1)+W(2)+W(3)+W(4)+W(5)+W(6)+W(7)+W(8)
        W(18)=W(9)+W(10)+W(11)+W(12)+W(13)+W(14)+W(15)+W(16)
        CTwo=W(17)+W(18)
        SPKetC(0)=SPKetC(0)+COne+CTwo*Two
!       -------------------------------- Lp=1, Mp = 0-------------------------------------
        W(1)=-(Cpq(1)*Q%C(0))-Cpq(3)*Q%C(1)-Cpq(6)*Q%C(3)-Cpq(10)*Q%C(6)
        W(2)=-(Cpq(15)*Q%C(10))-Cpq(21)*Q%C(15)-Cpq(28)*Q%C(21)-Cpq(36)*Q%C(28)
        COne=W(1)+W(2)
        W(1)=-(Cpq(4)*Q%C(2))-Cpq(7)*Q%C(4)-Cpq(8)*Q%C(5)
        W(2)=-(Cpq(11)*Q%C(7))-Cpq(12)*Q%C(8)-Cpq(13)*Q%C(9)-Cpq(16)*Q%C(11)
        W(3)=-(Cpq(17)*Q%C(12))-Cpq(18)*Q%C(13)-Cpq(19)*Q%C(14)
        W(4)=-(Cpq(22)*Q%C(16))-Cpq(23)*Q%C(17)-Cpq(24)*Q%C(18)-Cpq(25)*Q%C(19)
        W(5)=-(Cpq(26)*Q%C(20))-Cpq(29)*Q%C(22)-Cpq(30)*Q%C(23)
        W(6)=-(Cpq(31)*Q%C(24))-Cpq(32)*Q%C(25)-Cpq(33)*Q%C(26)-Cpq(34)*Q%C(27)
        W(7)=-(Cpq(37)*Q%C(29))-Cpq(38)*Q%C(30)-Cpq(39)*Q%C(31)
        W(8)=-(Cpq(40)*Q%C(32))-Cpq(41)*Q%C(33)-Cpq(42)*Q%C(34)-Cpq(43)*Q%C(35)
        W(9)=-(Spq(4)*Q%S(2))-Spq(7)*Q%S(4)-Spq(8)*Q%S(5)
        W(10)=-(Spq(11)*Q%S(7))-Spq(12)*Q%S(8)-Spq(13)*Q%S(9)-Spq(16)*Q%S(11)
        W(11)=-(Spq(17)*Q%S(12))-Spq(18)*Q%S(13)-Spq(19)*Q%S(14)
        W(12)=-(Spq(22)*Q%S(16))-Spq(23)*Q%S(17)-Spq(24)*Q%S(18)-Spq(25)*Q%S(19)
        W(13)=-(Spq(26)*Q%S(20))-Spq(29)*Q%S(22)-Spq(30)*Q%S(23)
        W(14)=-(Spq(31)*Q%S(24))-Spq(32)*Q%S(25)-Spq(33)*Q%S(26)-Spq(34)*Q%S(27)
        W(15)=-(Spq(37)*Q%S(29))-Spq(38)*Q%S(30)-Spq(39)*Q%S(31)
        W(16)=-(Spq(40)*Q%S(32))-Spq(41)*Q%S(33)-Spq(42)*Q%S(34)-Spq(43)*Q%S(35)
        W(17)=W(1)+W(2)+W(3)+W(4)+W(5)+W(6)+W(7)+W(8)
        W(18)=W(9)+W(10)+W(11)+W(12)+W(13)+W(14)+W(15)+W(16)
        CTwo=W(17)+W(18)
        SPKetC(1)=SPKetC(1)+COne+CTwo*Two
!       -------------------------------- Lp=1, Mp = 1-------------------------------------
        W(1)=-(Cpq(2)*Q%C(0))-Cpq(4)*Q%C(1)
        W(2)=(Cpq(3)-Cpq(5))*Q%C(2)-Cpq(7)*Q%C(3)
        W(3)=(Cpq(6)-Cpq(8))*Q%C(4)+(Cpq(7)-Cpq(9))*Q%C(5)
        W(4)=-(Cpq(11)*Q%C(6))+(Cpq(10)-Cpq(12))*Q%C(7)
        W(5)=(Cpq(11)-Cpq(13))*Q%C(8)+(Cpq(12)-Cpq(14))*Q%C(9)
        W(6)=-(Cpq(16)*Q%C(10))+(Cpq(15)-Cpq(17))*Q%C(11)
        W(7)=(Cpq(16)-Cpq(18))*Q%C(12)+(Cpq(17)-Cpq(19))*Q%C(13)
        W(8)=(Cpq(18)-Cpq(20))*Q%C(14)-Cpq(22)*Q%C(15)
        W(9)=(Cpq(21)-Cpq(23))*Q%C(16)+(Cpq(22)-Cpq(24))*Q%C(17)
        W(10)=(Cpq(23)-Cpq(25))*Q%C(18)+(Cpq(24)-Cpq(26))*Q%C(19)
        W(11)=(Cpq(25)-Cpq(27))*Q%C(20)-Cpq(29)*Q%C(21)
        W(12)=(Cpq(28)-Cpq(30))*Q%C(22)+(Cpq(29)-Cpq(31))*Q%C(23)
        W(13)=(Cpq(30)-Cpq(32))*Q%C(24)+(Cpq(31)-Cpq(33))*Q%C(25)
        W(14)=(Cpq(32)-Cpq(34))*Q%C(26)+(Cpq(33)-Cpq(35))*Q%C(27)
        W(15)=-(Cpq(37)*Q%C(28))+(Cpq(36)-Cpq(38))*Q%C(29)
        W(16)=(Cpq(37)-Cpq(39))*Q%C(30)+(Cpq(38)-Cpq(40))*Q%C(31)
        W(17)=W(1)+W(2)+W(3)+W(4)+W(5)+W(6)+W(7)+W(8)
        W(18)=W(9)+W(10)+W(11)+W(12)+W(13)+W(14)+W(15)+W(16)
        W(19)=(Cpq(39)-Cpq(41))*Q%C(32)+(Cpq(40)-Cpq(42))*Q%C(33)
        W(20)=(Cpq(41)-Cpq(43))*Q%C(34)+(Cpq(42)-Cpq(44))*Q%C(35)
        W(21)=-(Spq(5)*Q%S(2))-Spq(8)*Q%S(4)
        W(22)=(Spq(7)-Spq(9))*Q%S(5)-Spq(12)*Q%S(7)
        W(23)=(Spq(11)-Spq(13))*Q%S(8)+(Spq(12)-Spq(14))*Q%S(9)
        W(24)=-(Spq(17)*Q%S(11))+(Spq(16)-Spq(18))*Q%S(12)
        W(25)=(Spq(17)-Spq(19))*Q%S(13)+(Spq(18)-Spq(20))*Q%S(14)
        W(26)=-(Spq(23)*Q%S(16))+(Spq(22)-Spq(24))*Q%S(17)
        W(27)=(Spq(23)-Spq(25))*Q%S(18)+(Spq(24)-Spq(26))*Q%S(19)
        W(28)=(Spq(25)-Spq(27))*Q%S(20)-Spq(30)*Q%S(22)
        W(29)=(Spq(29)-Spq(31))*Q%S(23)+(Spq(30)-Spq(32))*Q%S(24)
        W(30)=(Spq(31)-Spq(33))*Q%S(25)+(Spq(32)-Spq(34))*Q%S(26)
        W(31)=(Spq(33)-Spq(35))*Q%S(27)-Spq(38)*Q%S(29)
        W(32)=(Spq(37)-Spq(39))*Q%S(30)+(Spq(38)-Spq(40))*Q%S(31)
        W(33)=(Spq(39)-Spq(41))*Q%S(32)+(Spq(40)-Spq(42))*Q%S(33)
        W(34)=(Spq(41)-Spq(43))*Q%S(34)+(Spq(42)-Spq(44))*Q%S(35)
        W(35)=W(19)+W(20)+W(21)+W(22)+W(23)+W(24)+W(25)+W(26)
        W(36)=W(27)+W(28)+W(29)+W(30)+W(31)+W(32)+W(33)+W(34)
        CTwo=W(17)+W(18)+W(35)+W(36)
        W(1)=-(Q%C(0)*Spq(2))-Q%C(1)*Spq(4)-Q%C(2)*Spq(5)-Q%C(3)*Spq(7)
        W(2)=-(Q%C(4)*Spq(8))-Q%C(5)*(Spq(7)+Spq(9))
        W(3)=-(Q%C(6)*Spq(11))-Q%C(7)*Spq(12)
        W(4)=-(Q%C(8)*(Spq(11)+Spq(13)))-Q%C(9)*(Spq(12)+Spq(14))
        W(5)=-(Q%C(10)*Spq(16))-Q%C(11)*Spq(17)
        W(6)=-(Q%C(12)*(Spq(16)+Spq(18)))-Q%C(13)*(Spq(17)+Spq(19))
        W(7)=-(Q%C(14)*(Spq(18)+Spq(20)))-Q%C(15)*Spq(22)
        W(8)=-(Q%C(16)*Spq(23))-Q%C(17)*(Spq(22)+Spq(24))
        W(9)=-(Q%C(18)*(Spq(23)+Spq(25)))-Q%C(19)*(Spq(24)+Spq(26))
        W(10)=-(Q%C(20)*(Spq(25)+Spq(27)))-Q%C(21)*Spq(29)
        W(11)=-(Q%C(22)*Spq(30))-Q%C(23)*(Spq(29)+Spq(31))
        W(12)=-(Q%C(24)*(Spq(30)+Spq(32)))-Q%C(25)*(Spq(31)+Spq(33))
        W(13)=-(Q%C(26)*(Spq(32)+Spq(34)))-Q%C(27)*(Spq(33)+Spq(35))
        W(14)=-(Q%C(28)*Spq(37))-Q%C(29)*Spq(38)
        W(15)=-(Q%C(30)*(Spq(37)+Spq(39)))-Q%C(31)*(Spq(38)+Spq(40))
        W(16)=W(1)+W(2)+W(3)+W(4)+W(5)+W(6)+W(7)
        W(17)=W(8)+W(9)+W(10)+W(11)+W(12)+W(13)+W(14)+W(15)
        W(18)=-(Q%C(32)*(Spq(39)+Spq(41)))-Q%C(33)*(Spq(40)+Spq(42))
        W(19)=-(Q%C(34)*(Spq(41)+Spq(43)))-Q%C(35)*(Spq(42)+Spq(44))
        W(20)=(Cpq(3)+Cpq(5))*Q%S(2)+(Cpq(6)+Cpq(8))*Q%S(4)
        W(21)=(Cpq(7)+Cpq(9))*Q%S(5)+(Cpq(10)+Cpq(12))*Q%S(7)
        W(22)=(Cpq(11)+Cpq(13))*Q%S(8)+(Cpq(12)+Cpq(14))*Q%S(9)
        W(23)=(Cpq(15)+Cpq(17))*Q%S(11)+(Cpq(16)+Cpq(18))*Q%S(12)
        W(24)=(Cpq(17)+Cpq(19))*Q%S(13)+(Cpq(18)+Cpq(20))*Q%S(14)
        W(25)=(Cpq(21)+Cpq(23))*Q%S(16)+(Cpq(22)+Cpq(24))*Q%S(17)
        W(26)=(Cpq(23)+Cpq(25))*Q%S(18)+(Cpq(24)+Cpq(26))*Q%S(19)
        W(27)=(Cpq(25)+Cpq(27))*Q%S(20)+(Cpq(28)+Cpq(30))*Q%S(22)
        W(28)=(Cpq(29)+Cpq(31))*Q%S(23)+(Cpq(30)+Cpq(32))*Q%S(24)
        W(29)=(Cpq(31)+Cpq(33))*Q%S(25)+(Cpq(32)+Cpq(34))*Q%S(26)
        W(30)=(Cpq(33)+Cpq(35))*Q%S(27)+(Cpq(36)+Cpq(38))*Q%S(29)
        W(31)=(Cpq(37)+Cpq(39))*Q%S(30)+(Cpq(38)+Cpq(40))*Q%S(31)
        W(32)=(Cpq(39)+Cpq(41))*Q%S(32)+(Cpq(40)+Cpq(42))*Q%S(33)
        W(33)=(Cpq(41)+Cpq(43))*Q%S(34)+(Cpq(42)+Cpq(44))*Q%S(35)
        W(34)=W(18)+W(19)+W(20)+W(21)+W(22)+W(23)+W(24)+W(25)
        W(35)=W(26)+W(27)+W(28)+W(29)+W(30)+W(31)+W(32)+W(33)
        STwo=W(16)+W(17)+W(34)+W(35)
        SPKetC(2)=SPKetC(2)+CTwo*Two
        SPKetS(2)=SPKetS(2)+STwo*Two
      END SUBROUTINE CTraX107