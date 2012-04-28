---
layout: default
title: Main Page
---

Introduction
------------

FreeON is an experimental, open source (GPL) suite of programs for linear scaling quantum chemistry, formerly known as MondoSCF. It is highly modular, and has been written from scratch for N-scaling SCF theory in Fortran95 and C. Platform independent I/O is supported with HDF5. FreeON should compile with most modern Linux distributions. FreeON performs Hartree-Fock, pure Density Functional, and hybrid HF/DFT calculations (e.g. B3LYP) in a Cartesian-Gaussian LCAO basis. All algorithms are *O(N)* or ''O(N *log* N)'' for non-metallic systems. Periodic boundary conditions in 1, 2 and 3 dimensions have been implemented through the Lorentz field (Γ-point), and an internal coordinate geometry optimizer allows full (atom+cell) relaxation using analytic derivatives. Effective core potentials for energies and forces have been implemented, but Effective Core Potential (ECP) lattice forces do not work yet. Advanced features include *O(N)* static and dynamic response, as well as time reversible Born Oppenheimer Molecular Dynamics (MD).

Content of this wiki
--------------------

-   [API](API "wikilink") Documentation
-   [Input File Syntax](Input File Syntax "wikilink")
-   [Example Inputs](Example Inputs "wikilink")
-   [Vision Statement](Vision Statement "wikilink")

Features
--------

[coming soon]

Contact Us
----------

While you could e-mail one of the authors directly, we prefer if you used our mailing lists or our bug tracker instead. You will probably get a response quicker this way because your message will go to all of us as opposed to just one of us. We currently operate 2 mailing lists:

-   [freeon-users](http://lists.nongnu.org/mailman/listinfo/freeon-users), our public mailing list for users of FreeON.
-   [freeon-devel](http://lists.nongnu.org/mailman/listinfo/freeon-devel), our mailing list for developers of FreeON, and people who are interested in the development process of it.

Alternatively you can file a bug report or feature request with our bug tracker system:

-   [FreeON Bug Tracker](https://savannah.nongnu.org/bugs/?group=freeon)

When you connect to our bug tracker for the first time you might get an error related to the SSL certificate used by savannah.nongnu.org. Please follow the [instructions from savannah](http://savannah.nongnu.org/tls/tutorial/) to fix this error.

Developer Page
--------------

The FreeON source code is hosted by the [Free Software Foundation](http://www.fsf.org/) at

-   [<http://savannah.nongnu.org/projects/freeon>](http://savannah.nongnu.org/projects/freeon).

Related Electronic Structure Programs
-------------------------------------

Our group at Los Alamos National Laboratory is actively developing 3 independent electronic structure projects. You can find out more about the other 2 from their respective webpages:

-   [RSPt](http://www.rspt.net/) is an Open Source project and a code for band structure calculations. RSPt (Relativistic Spin Polarised (test)) is very robust and flexible and can be used to calculate the band structure and total energy for all elements, and combinations thereof, over a wide range of volumes and structures. The Full-Potential Linear Muffin-Tin Orbital (FP-LMTO) method allows for very small basis sets and fast calculations. Compared to LMTO-ASA there are no restrictions on the symmetry of the potential in FP-LMTO. RSPt allows for multiple energy sets (i.e. valence and semi-core states) with the same angular quantum numbers but different main quantum number.
-   [LATTE](http://savannah.nongnu.org/projects/latte) (Los Alamos Transferable Tight-binding for Energetics) enables quantum-based molecular dynamics simulations on many-core architectures of materials with mixed covalent and ionic bonding.

Authors
-------

The authors of FreeON, in alphabetical order:

|---|---|---|
|Nicolas Bock|\<[nicolasbock@freeon.org](http://mailto:nicolasbock@freeon.org)\>|Los Alamos National Laboratory, T-1|
|Matt Challacombe|\<[matt.challacombe@freeon.org](http://mailto:matt.challacombe@freeon.org)\>|Los Alamos National Laboratory, T-1|
|Chee Kwan Gan||Institute for High Performance Computing|
|Graeme Henkelman||University of Texas at Austin|
|Karoly Nemeth||Argonne National Laboratory|
|Anders Niklasson|\<[amn@lanl.gov](http://mailto:amn@lanl.gov)\>|Los Alamos National Laboratory, T-1|
|Anders Odell|\<[odell@mse.kth.se](http://mailto:odell@mse.kth.se)\>|KTH Stockholm|
|Eric Schwegler||Lawrence Livermore National Laboratory|
|C. J. Tymczak|\<[tymczakcj@tsu.edu](http://mailto:tymczakcj@tsu.edu)\>|Texas Southern University|
|Valery Weber||Universität Zürich|

Publications
------------

-   Linear Scaling Solution of the Time-Dependent Self-Consistent-Field Equations. Matt Challacombe, [arXiv preprint 1001.2586](http://arxiv.org/abs/1001.2586)
-   Representation independent algorithms for molecular response calculations in time-dependent self-consistent field theories. S. Tretiak, C. Isborn, AMN Niklasson and Matt Challacombe [Journal of Chemical Physics 130, 054111 (2009)](http://link.aip.org/link/?JCPSA6/130/054111/1)
-   Molecular orbital free algorithm for excited states in time-dependent perturbation theory. M. Lucero, AMN Niklasson, S. Tretiak and M. Challacombe, Journal of Chemical Physics, 129 064114 (2008)
-   Time-reversible ab initio molecular dynamics A. Niklasson, C.J. Tymczak and Matt Challacombe, Journal of Chemical Physics, 126 144103 (2007)
-   He conductivity in cool white dwarf atmospheres S. Mazevet, Matt Challacombe, P.M. Kowalski and D. Saumon Astrophysics and Space Science, 307 273 (2007)
-   Time-reversible Born-Oppenheimer molecular dynamics A. Niklasson, C.J. Tymczak and Matt Challacombe, Physical Review Letters, 97 123001 (2006)
-   Parallel algorithm for the computation of the Hartree-Fock exchange matrix: gas phase and periodic parallel ONX. V. Weber, Matt Challacombe, Journal of Chemical Physics, 125 104110 (2006)
-   Energy gradients with respect to atomic positions and cell parameters for the Kohn-Sham density-functional theory at the Gamma point V. Weber, C.J. Tymczak and Matt Challacombe, Journal of Chemical Physics, 124 224107 (2006)
-   Exchange energy gradients with respect to atomic positions and cell parameters within the Hartree-Fock {Gamma}-point approximation V. Weber, C. Daul and Matt Challacombe, Journal of Chemical Physics, 124 214105 (2006)
-   Nonorthogonal density-matrix perturbation theory. A. Niklasson, V. Weber and Matt Challacombe, Journal of Chemical Physics, 123 44107 (2005)
-   Higher-order response in O(N) by perturbed projection V. Weber, A. Niklasson, Matt Challacombe, Journal of Chemical Physics, 123 44106 (2005)
-   Geometry optimization of crystals by the quasi-independent curvilinear coordinate approximation K. Nemeth and Matt Challacombe, Journal of Chemical Physics, 123 1 (2005)
-   Linear scaling computation of the Fock matrix. VIII. Periodic boundaries for exact exchange at the Gamma point C.J. Tymczak, V. Weber, E. Schwegler and Matt Challacombe, Journal of Chemical Physics, 122 124105 (2005)
-   Linear scaling computation of the Fock matrix. VII. Periodic density functional theory at the Gamma point C.J. Tymczak and Matt Challacombe, Journal of Chemical Physics, 122 134102 (2005)
-   The quasi-independent curvilinear coordinate approximation for geometry optimization K. Nemeth and Matt Challacombe, Journal of Chemical Physics, 121 2877 (2004)
-   Ab initio linear scaling response theory: Electric polarizability by perturbed projection V. Weber, A. Niklasson and Matt Challacombe, Physical Review Letters, 92 193002 (2004)
-   Density matrix perturbation theory A. Niklasson and Matt Challacombe, Physical Review Letters, 92 193001 (2004)
-   All-electron density-functional studies of hydrostatic compression of pentaerythritol tetranitrate C(CH2ONO2)4 C.K. Gan, T. Sewell and Matt Challacombe, Physical Review B, 69 35116 (2004)
-   Linear scaling computation of Fock matrix. VII. Parallel computation of the Coulomb matrix , C. K. Gan, C. J. Tymczak, and Matt Challacombe, Journal of Chemical Physics, 121 (2004) 6608
-   Linear scaling computation of the Fock matrix. VI. Data parallel computation of the exchange-correlation matrix C.K. Gan and Matt Challacombe, Journal of Chemical Physics, 118 9128 (2003)
-   Trace resetting density matrix purification in O(N) self-consistent-field theory A. Niklasson, C.J. Tymczak and Matt Challacombe, Journal of Chemical Physics, 118 8611 (2003)
-   Linear scaling computation of the Fock matrix. V. Hierarchical Cubature for numerical integration of the exchange-correlation matrix Matt Challacombe, Journal of Chemical Physics, 113 10037 (2000)
-   Linear scaling computation of the Fock matrix. III. Formation of the exchange matrix with permutational symmetry E. Schwegler and Matt Challacombe, Theoretical Chemistry Accounts, 104 344 (2000)
-   General parallel sparse-blocked matrix multiply for linear scaling SCF theory Matt Challacombe, Computer Physics Communications, 128 93 (2000)
-   Linear scaling computation of the Fock matrix. IV. Multipole accelerated formation of the exchange matrix E. Schwegler and Matt Challacombe, Journal of Chemical Physics, 111 6223 (1999)
-   A simplified density matrix minimization for linear scaling self-consistent field theory Matt Challacombe, Journal of Chemical Physics, 110 2332 (1999)
-   A multipole acceptability criterion for electronic structure theory E. Schwegler, Matt Challacombe and M. Head-Gordon, Journal of Chemical Physics, 109 8764 (1998)
-   Periodic boundary conditions and the fast multipole method Matt Challacombe, C. White and M. Head-Gordon, Journal of Chemical Physics, 107 10131 (1997)
-   Linear scaling computation of the Fock matrix. II. Rigorous bounds on exchange integrals and incremental Fock build E. Schwegler, Matt Challacombe and M. Head-Gordon, Journal of Chemical Physics, 106 9708 (1997)
-   Linear scaling computation of the Fock matrix Matt Challacombe and E. Schwegler, Journal of Chemical Physics, 106 5526 (1997)
-   Linear scaling computation of the Hartree-Fock exchange matrix E. Schwegler and Matt Challacombe, Journal of Chemical Physics, 105 2726 (1996)
-   Fast assembly of the Coulomb matrix: a quantum chemical tree code Matt Challacombe, E. Schwegler and J. Almlof, Journal of Chemical Physics, 104 4685 (1996

Wikipedia
---------

We are also on wikipedia: [FreeON](http://en.wikipedia.org/wiki/FreeON)

Download
--------

From time to time we produce a tar file (sort of a release) and place it here: [Savannah FreeON Download Area](http://savannah.nongnu.org/files/?group=freeon)

How to cite us
--------------

    @misc{FreeON,
      author = {Bock, Nicolas and Challacombe, Matt and Gan, Chee~Kwan
        and Henkelman, Graeme and Nemeth, Karoly and Niklasson, A.~M.~N.
        and Odell, Anders and Schwegler, Eric and Tymczak, C.~J.
        and Weber, Valery},
      title = {{\\sc FreeON}},
      year = 2011,
      note = {\\mbox{L}os Alamos National Laboratory (LA-CC 01-2; LA-CC-04-086),
        Copyright University of California.},
      url = {http://freeon.org/}
    }