AC_PREREQ(2.59)

AC_INIT([FreeON],
        [1.0.10],
        [freeon-users@nongnu.org],
        [],
        [http://www.freeon.org])

AC_COPYRIGHT([
This code is part of the FreeON suite of programs for linear scaling
electronic structure theory and ab initio molecular dynamics.

Copyright (2004). The Regents of the University of California. This
material was produced under U.S. Government contract W-7405-ENG-36
for Los Alamos National Laboratory, which is operated by the University
of California for the U.S. Department of Energy. The U.S. Government has
rights to use, reproduce, and distribute this software.  NEITHER THE
GOVERNMENT NOR THE UNIVERSITY MAKES ANY WARRANTY, EXPRESS OR IMPLIED,
OR ASSUMES ANY LIABILITY FOR THE USE OF THIS SOFTWARE.

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by the
Free Software Foundation; either version 2 of the License, or (at your
option) any later version. Accordingly, this program is distributed in
the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE. See the GNU General Public License at www.gnu.org for details.

While you may do as you like with this software, the GNU license requires
that you clearly mark derivative software.  In addition, you are encouraged
to return derivative works to the FreeON group for review, and possible
disemination in future releases.
])

# Check the build system.
AC_CANONICAL_TARGET

# Initialize automake.
AM_INIT_AUTOMAKE([dist-bzip2 no-dist-gzip silent-rules])
AM_SILENT_RULES([yes])

# Define the aclocal macro directory.
AC_CONFIG_MACRO_DIR([m4])

AC_ARG_ENABLE([git-tag],
  [AS_HELP_STRING([--enable-git-tag],
  [Adds the HEAD git tag to the binary, which might be useful when using
   FreeON directly from git.])],
  [use_git_tag=$enableval],
  [use_git_tag="no"])

if test "${use_git_tag}" = "yes"; then
  # Check for localversion.
  if test -f ${srcdir}/localversion; then
    . ${srcdir}/localversion
  else
    branch="unknown"
    localversion="not_set"
  fi
else
  branch="master"
  localversion="release"
fi

AC_SUBST([LOCAL_VERSION], [${branch}:${localversion}])
AC_MSG_NOTICE([configuring local version ${branch}:${localversion}])

# Fix up the header definitions for hdf.
AC_OUTPUT_COMMANDS([
  echo "checking MondoConfig.h"
  grep "#define" config.h | grep -v LOCAL_VERSION > tempconf
  if test ! -f MondoConfig.h; then
    mv -f tempconf MondoConfig.h
    echo "MondoConfig.h did not exist"
  elif (diff -u MondoConfig.h tempconf > MondoConfig.diff); then
    rm -f tempconf
    echo "MondoConfig.h is unchanged"
  else
    mv -f tempconf MondoConfig.h
    echo "MondoConfig.h updated"
    cat MondoConfig.diff
  fi
])

# Store user supplied compiler flags.
user_CFLAGS=${CFLAGS}
user_CXXFLAGS=${CXXFLAGS}
user_FFLAGS=${FFLAGS}
user_FCFLAGS=${FCFLAGS}

# Check whether to build for parallel (MPI).
AC_MSG_CHECKING([whether to build fully parallel MPI version])
AC_ARG_ENABLE([MPI],
  [AS_HELP_STRING([--enable-MPI],
  [Enable MPI, i.e. build fully parallel version.])],
  [use_MPI="${enableval}"],
  [use_MPI="no"])

if test "${use_MPI}" = "yes"; then
  AC_MSG_RESULT([yes, building fully parallel version with MPI])
  AC_DEFINE([PARALLEL], [1], [Build fully parallel version])
  AC_DEFINE([MPI2], [1], [Use MPI2 API])
else
  AC_MSG_RESULT([no])
fi

# Check whether we are building parallelization across clones only.
AC_MSG_CHECKING([whether to build MPI version, parallelized across clones only])
AC_ARG_ENABLE([parallel-clones],
  [AS_HELP_STRING([--enable-parallel-clones],
  [Enables MPI parallelism only across clones. This is useful for NEB
   calculations.])],
  [use_parallel_clones="${enableval}"],
  [use_parallel_clones="no"])

if test "${use_parallel_clones}" = "yes"; then
  AC_MSG_RESULT([yes, parallelizing only across clones with MPI])
  AC_DEFINE([PARALLEL_CLONES], [1], [Build parallel version only across clones])
  AC_DEFINE([MPI2], [1], [Use MPI2 API])
else
  AC_MSG_RESULT([no])
fi

AM_CONDITIONAL(HAVE_MPIRUN, [test "${use_MPI}" = "yes" -o "${use_parallel_clones}" = "yes"])

# Sanity check on parallelism.
if test "${use_MPI}" = "yes" -a "${use_parallel_clones}" = "yes"; then
  AC_MSG_FAILURE([can not build with both MPI and parallel-clones enabled])
fi

# Define what compiler executable names to look for.
if test "${use_MPI}" = "yes" -o "${use_parallel_clones}" = "yes"; then
  C_COMPILERS="mpicc"
  CXX_COMPILERS="mpicxx"
  FC_COMPILERS="mpif90"
  F77_COMPILERS="mpif90"
else
  C_COMPILERS="gcc icc pgc"
  CXX_COMPILERS="g++ icc pgc"
  FC_COMPILERS="gfortran ifort pgf90"
  F77_COMPILERS="gfortran ifort pgf90"
fi

# Find compilers.
AC_PROG_CC_STDC([${C_COMPILERS}])
AC_PROG_CXX([${CXX_COMPILERS}])
AC_PROG_FC([${FC_COMPILERS}])
AC_PROG_F77([${F77_COMPILERS}])

AC_USE_SYSTEM_EXTENSIONS

if test -z "${CC}"; then
  AC_MSG_FAILURE([no C compiler found: set the CC variable])
fi

if test -z "${CXX}"; then
  AC_MSG_FAILURE([no C++ compiler found: set the CXX variable])
fi

if test -z "${FC}"; then
  AC_MSG_FAILURE([no F90 compiler found: set the FC variable])
fi

if test -z "${F77}"; then
  AC_MSG_FAILURE([no F77 compiler found: set the F77 variable])
fi

# Identify compiler.
AC_ARG_VAR([CC_COMPILERNAME],
  [Gives the configure script a hint as to what kind of compiler the CC
   compiler is.  Normally this is autodetected, but can sometimes fail.
   Possible values are GCC, Intel, PGI.])

if test -n "${CC_COMPILERNAME}"; then
  if test "${CC_COMPILERNAME}" = "GCC" -o \
          "${CC_COMPILERNAME}" = "Intel" -o \
          "${CC_COMPILERNAME}" = "PGI"; then
    AC_MSG_NOTICE([using user-defined CC_COMPILERNAME:  ${CC_COMPILERNAME}])
  else
    AC_MSG_FAILURE([unknown CC compiler: ${CC_COMPILERNAME}])
  fi
else
  # Try to find out what compiler this is.
  CC_RESULT=`(${CC} --version 2> /dev/null) | head -n1 | awk '{print $1}' 2> /dev/null`
  if test "`echo ${CC_RESULT} | sed -e 's/^.*gcc.*/gcc/'`" = "gcc"; then
    AC_MSG_NOTICE([CC:  identified GNU gcc compiler])
    CC_COMPILERNAME="GCC"
  elif test "${CC_RESULT}" = "icc"; then
    AC_MSG_NOTICE([CC:  identified Intel icc compiler])
    CC_COMPILERNAME="Intel"
  else
    # Check for Portland Group compiler.
    CC_RESULT=`(${CC} -V 2> /dev/null) | grep pgcc | awk '{print $1}'`
    if test "${CC_RESULT}" = "pgcc"; then
      AC_MSG_NOTICE([CC:  identified Portland Group pgcc compiler])
      CC_COMPILERNAME="PGI"
    else
      # Fall back to looking at the compiler executable name.
      AC_MSG_NOTICE([CC:  could not automatically detect compiler (${CC_RESULT})])
      case ${CC} in
        *gcc*) CC_COMPILERNAME="GCC" ;;
        *icc*) CC_COMPILERNAME="Intel" ;;
        *pgc*) CC_COMPILERNAME="PGI" ;;
        *)     CC_COMPILERNAME="unknown" ;;
      esac
    fi
  fi
fi

AC_ARG_VAR([CXX_COMPILERNAME],
  [Gives the configure script a hint as to what kind of compiler the CXX
   compiler is.  Normally this is autodetected, but can sometimes fail.
   Possible values are GCC, Intel, PGI.])

if test -n "${CXX_COMPILERNAME}"; then
  if test "${CXX_COMPILERNAME}" = "GCC" -o \
          "${CXX_COMPILERNAME}" = "Intel" -o \
          "${CXX_COMPILERNAME}" = "PGI"; then
    AC_MSG_NOTICE([using user-defined CXX_COMPILERNAME:  ${CXX_COMPILERNAME}])
  else
    AC_MSG_FAILURE([unknown CXX compiler: ${CXX_COMPILERNAME}])
  fi
else
  # Try to find out what compiler this is.
  CXX_RESULT=`(${CXX} --version 2> /dev/null) | head -n1 | awk '{print $1}' 2> /dev/null`
  if test "`echo ${CXX_RESULT} | sed -e 's/^.*g++.*/g++/'`" = "g++"; then
    AC_MSG_NOTICE([CXX: identified GNU gcc compiler])
    CXX_COMPILERNAME="GCC"
  elif test "${CXX_RESULT}" = "icc"; then
    AC_MSG_NOTICE([CXX: identified Intel icc compiler])
    CXX_COMPILERNAME="Intel"
  else
    # Check for Portland Group compiler.
    CXX_RESULT=`(${CXX} -V 2> /dev/null) | grep pgcc | awk '{print $1}'`
    if test "${CXX_RESULT}" = "pgcc"; then
      AC_MSG_NOTICE([CXX: identified Portland Group pgcc compiler])
      CXX_COMPILERNAME="PGI"
    else
      # Fall back to looking at the compiler executable name.
      AC_MSG_NOTICE([CXX: could not automatically detect compiler (${CXX_RESULT})])
      case ${CXX} in
        *gcc*) CXX_COMPILERNAME="GCC" ;;
        *icc*) CXX_COMPILERNAME="Intel" ;;
        *pgc*) CXX_COMPILERNAME="PGI" ;;
        *)     CXX_COMPILERNAME="unknown" ;;
      esac
    fi
  fi
fi

AC_ARG_VAR([F77_COMPILERNAME],
  [Gives the configure script a hint as to what kind of compiler the F77
   compiler is.  Normally this is autodetected, but can sometimes fail.
   Possible values are GCC, Intel, PGI.])

if test -n "${F77_COMPILERNAME}"; then
  if test "${F77_COMPILERNAME}" = "GCC" -o \
          "${F77_COMPILERNAME}" = "Intel" -o \
          "${F77_COMPILERNAME}" = "PGI"; then
    AC_MSG_NOTICE([using user-defined F77_COMPILERNAME: ${F77_COMPILERNAME}])
  else
    AC_MSG_FAILURE([unknown F77 compiler: ${F77_COMPILERNAME}])
  fi
else
  # Try to find out what compiler this is.
  F77_RESULT=`(${F77} --version 2> /dev/null) | head -n1 | awk '{print $1}' 2> /dev/null`
  if test "${F77_RESULT}" = "GNU"; then
    AC_MSG_NOTICE([F77: identified GNU gcc compiler])
    F77_COMPILERNAME="GCC"
  elif test "${F77_RESULT}" = "ifort"; then
    AC_MSG_NOTICE([F77: identified Intel ifort compiler])
    F77_COMPILERNAME="Intel"
  else
    # Check for Portland Group compiler.
    F77_RESULT=`(${F77} -V 2> /dev/null) | grep pgf | awk '{print $1}'`
    if test -n "${F77_RESULT}"; then
      AC_MSG_NOTICE([F77: identified Portland Group pgf* compiler])
      F77_COMPILERNAME="PGI"
    else
      # Fall back to looking at the compiler executable name.
      AC_MSG_NOTICE([F77: could not automatically detect compiler (${F77_RESULT})])
      case ${F77} in
        *gfortran*) F77_COMPILERNAME="GCC" ;;
        *ifort*)    F77_COMPILERNAME="Intel" ;;
        *pgf*)      F77_COMPILERNAME="PGI" ;;
        *)          F77_COMPILERNAME="unknown" ;;
      esac
    fi
  fi
fi

AC_ARG_VAR([FC_COMPILERNAME],
  [Gives the configure script a hint as to what kind of compiler the FC
   compiler is.  Normally this is autodetected, but can sometimes fail.
   Possible values are GCC, Intel, PGI.])

if test -n "${FC_COMPILERNAME}"; then
  if test "${FC_COMPILERNAME}" = "GCC" -o \
          "${FC_COMPILERNAME}" = "Intel" -o \
          "${FC_COMPILERNAME}" = "PGI"; then
    AC_MSG_NOTICE([using user-defined FC_COMPILERNAME:  ${FC_COMPILERNAME}])
  else
    AC_MSG_FAILURE([unknown FC compiler: ${FC_COMPILERNAME}])
  fi
else
  # Try to find out what compiler this is.
  FC_RESULT=`(${FC} --version 2> /dev/null) | head -n1 | awk '{print $1}' 2> /dev/null`
  if test "${FC_RESULT}" = "GNU"; then
    AC_MSG_NOTICE([FC:  identified GNU gcc compiler])
    FC_COMPILERNAME="GCC"
  elif test "${FC_RESULT}" = "ifort"; then
    AC_MSG_NOTICE([FC:  identified Intel ifort compiler])
    FC_COMPILERNAME="Intel"
  else
    # Check for Portland Group compiler.
    FC_RESULT=`(${FC} -V 2> /dev/null) | grep pgf | awk '{print $1}'`
    if test -n "${FC_RESULT}"; then
      AC_MSG_NOTICE([FC:  identified Portland Group pgf* compiler])
      FC_COMPILERNAME="PGI"
    else
      # Fall back to looking at the compiler executable name.
      AC_MSG_NOTICE([FC:  could not automatically detect compiler (${FC_RESULT})])
      case ${FC} in
        *gfortran*) FC_COMPILERNAME="GCC" ;;
        *ifort*)    FC_COMPILERNAME="Intel" ;;
        *pgf*)      FC_COMPILERNAME="PGI" ;;
        *)          FC_COMPILERNAME="unknown" ;;
      esac
    fi
  fi
fi

# Get compiler version.
case "${CC_COMPILERNAME}" in
  GCC)   cc_compiler_version_string="`${CC} --version | head -n1`" ;;
  Intel) cc_compiler_version_string="`${CC} --version | head -n1`" ;;
  PGI)   cc_compiler_version_string="`${CC} -V | head -n2 | tail -n1`" ;;
  *)     cc_compiler_version_string="unset" ;;
esac

case "${CXX_COMPILERNAME}" in
  GCC)   cxx_compiler_version_string="`${CXX} --version | head -n1`" ;;
  Intel) cxx_compiler_version_string="`${CXX} --version | head -n1`" ;;
  PGI)   cxx_compiler_version_string="`${CXX} -V | head -n2 | tail -n1`" ;;
  *)     cxx_compiler_version_string="unset" ;;
esac

case "${F77_COMPILERNAME}" in
  GCC)   f77_compiler_version_string="`${F77} --version | head -n1`" ;;
  Intel) f77_compiler_version_string="`${F77} --version | head -n1`" ;;
  PGI)   f77_compiler_version_string="`${F77} -V | head -n2 | tail -n1`" ;;
  *)     f77_compiler_version_string="unset" ;;
esac

case "${FC_COMPILERNAME}" in
  GCC)   fc_compiler_version_string="`${FC} --version | head -n1`" ;;
  Intel) fc_compiler_version_string="`${FC} --version | head -n1`" ;;
  PGI)   fc_compiler_version_string="`${FC} -V | head -n2 | tail -n1`" ;;
  *)     fc_compiler_version_string="unset" ;;
esac

# Define compiler version strings.
AC_DEFINE_UNQUOTED(CC_VERSION_STRING,  ["${cc_compiler_version_string}"],  [The C compiler version string])
AC_DEFINE_UNQUOTED(CXX_VERSION_STRING, ["${cxx_compiler_version_string}"], [The CXX compiler version string])
AC_DEFINE_UNQUOTED(F77_VERSION_STRING, ["${f77_compiler_version_string}"], [The f77 compiler version string])
AC_DEFINE_UNQUOTED(FC_VERSION_STRING,  ["${fc_compiler_version_string}"],  [The f90 compiler version string])

AC_MSG_NOTICE([C compiler version:   ${cc_compiler_version_string}])
AC_MSG_NOTICE([CXX compiler version: ${cxx_compiler_version_string}])
AC_MSG_NOTICE([F77 compiler version: ${f77_compiler_version_string}])
AC_MSG_NOTICE([FC compiler version:  ${fc_compiler_version_string}])

# Put the C-compiler into standard C mode.
AC_GNU_SOURCE

# Check for naming convention for Fortran-C interface.
AC_F77_WRAPPERS()
AC_FC_WRAPPERS()

# Find OpenMP flags for C.
AC_LANG_PUSH(C)
AC_OPENMP
AC_LANG_POP(C)

# Find OpenMP flags for Fortran.
AC_LANG_PUSH(Fortran)
AC_OPENMP
AC_LANG_POP(Fortran)

# Put the F90-compiler into free form.
AC_LANG_PUSH(Fortran)
AC_FC_SRCEXT(F90)
AC_FC_FREEFORM
AC_LANG_POP(Fortran)

# Switch back to C.
AC_LANG(C)

# Check for libtool.
AC_PROG_LIBTOOL

# Set the preprocessor.
CPP=cpp

# Set $(MAKE).
AC_PROG_MAKE_SET

# Store additional optimization flags.
optimization_flags=""

# No optimizations?
AC_MSG_CHECKING([whether to add compiler optimizations])
AC_ARG_ENABLE([optimizations],
  [AS_HELP_STRING([--enable-optimizations],
    [Enables default compiler optimizations.])],
  [use_optimizations="${enableval}"],
  [use_optimizations="no"])

AM_CONDITIONAL(USE_COMPILER_OPTIMIZATIONS, [test "${use_optimizations}" = "yes"])

if [[ "${use_optimizations}" = "yes" ]]; then
  AC_MSG_RESULT([adding compiler optimizations for build_cpu ${build_cpu}])

  # Set the optimization flags.
  if test -z "${user_CFLAGS}"; then
    case ${build_cpu} in
      *386)
        case ${CC_COMPILERNAME} in
          GCC)   CFLAGS="-g -O2 -march=native -ffast-math -ftree-vectorize -pipe" ;;
          Intel) CFLAGS="-g -O3 -no-prec-div -xHost" ;;
          PGI)   CFLAGS="-g -fast" ;;
          *)     CFLAGS="-g -O" ;;
        esac ;;
      *686)
        case ${CC_COMPILERNAME} in
          GCC)   CFLAGS="-g -O2 -march=native -msse -msse2 -mfpmath=sse -ffast-math -ftree-vectorize -pipe" ;;
          Intel) CFLAGS="-g -O3 -no-prec-div -xHost" ;;
          PGI)   CFLAGS="-g -fast" ;;
          *)     CFLAGS="-g -O" ;;
        esac ;;
      *x86_64)
        case ${CC_COMPILERNAME} in
          GCC)   CFLAGS="-g -O2 -march=native -msse -msse2 -mfpmath=sse -ffast-math -ftree-vectorize -pipe" ;;
          Intel) CFLAGS="-g -O3 -no-prec-div -xHost" ;;
          PGI)   CFLAGS="-g -fast" ;;
          *)     CFLAGS="-g -O" ;;
        esac ;;
      *powerpc)
        case ${CC_COMPILERNAME} in
          GCC) CFLAGS="-g -O2 -mcpu=G5" ;;
          *)   CFLAGS="-g -O" ;;
        esac ;;
      *) AC_MSG_NOTICE([unknown build_cpu ${build_cpu}])
         CFLAGS="-g -O" ;;
    esac

    # Test whether these flags actually produce runnable code.
    AC_LANG(C)
    AC_RUN_IFELSE([AC_LANG_PROGRAM([], [int i = 1;])],
      [],
      [AC_MSG_NOTICE([resetting CFLAGS])
       CFLAGS="-O"])

    AC_MSG_NOTICE([Setting default optimization for ${CC_COMPILERNAME} compiler: CFLAGS  = ${CFLAGS}])
    optimization_flags="${optimization_flags} CFLAGS=\"${CFLAGS}\""
  else
    AC_MSG_NOTICE([User supplied:  CFLAGS  = ${user_CFLAGS}])
  fi

  if test -z "${user_FFLAGS}"; then
    case ${build_cpu} in
      *386)
        case ${F77_COMPILERNAME} in
          GCC)   FFLAGS="-g -O2 -march=native -ffast-math -ftree-vectorize -pipe" ;;
          Intel) FFLAGS="-g -O3 -no-prec-div -xHost" ;;
          PGI)   FFLAGS="-g -fast" ;;
          *)     FFLAGS="-g -O" ;;
        esac ;;
      *686)
        case ${F77_COMPILERNAME} in
          GCC)   FFLAGS="-g -O2 -march=native -msse -msse2 -mfpmath=sse -ffast-math -ftree-vectorize -pipe" ;;
          Intel) FFLAGS="-g -O3 -no-prec-div -xHost" ;;
          PGI)   FFLAGS="-g -fast" ;;
          *)     FFLAGS="-g -O" ;;
        esac ;;
      *x86_64)
        case ${F77_COMPILERNAME} in
          GCC)   FFLAGS="-g -O2 -march=native -msse -msse2 -mfpmath=sse -ffast-math -ftree-vectorize -pipe" ;;
          Intel) FFLAGS="-g -O3 -no-prec-div -xHost" ;;
          PGI)   FFLAGS="-g -fast" ;;
          *)     FFLAGS="-g -O" ;;
        esac ;;
      *powerpc)
        case ${CC_COMPILERNAME} in
          GCC) FFLAGS="-g -O2 -mcpu=G5" ;;
          *)   FFLAGS="-g -O" ;;
        esac ;;
      *) AC_MSG_NOTICE([unknown build_cpu ${build_cpu}])
         FFLAGS="-g -O" ;;
    esac

    # Test whether these flags actually produce runnable code.
    AC_LANG(Fortran 77)
    AC_RUN_IFELSE([AC_LANG_PROGRAM([], [
      INTEGER I
      I = 1
])],
      [],
      [AC_MSG_NOTICE([resetting FFLAGS])
       FFLAGS="-O"])

    AC_MSG_NOTICE([Setting default optimization for ${F77_COMPILERNAME} compiler: FFLAGS  = ${FFLAGS}])
    optimization_flags="${optimization_flags} FFLAGS=\"${FFLAGS}\""
  else
    AC_MSG_NOTICE([User supplied:  FFLAGS  = ${user_FFLAGS}])
  fi

  if test -z "${user_FCFLAGS}"; then
    case ${build_cpu} in
      *386)
        case ${FC_COMPILERNAME} in
          GCC)   FCFLAGS="-g -O2 -march=native -ffast-math -ftree-vectorize -pipe" ;;
          Intel) FCFLAGS="-g -O3 -no-prec-div -xHost" ;;
          PGI)   FCFLAGS="-g -fast" ;;
          *)     FCFLAGS="-g -O" ;;
        esac ;;
      *686)
        case ${FC_COMPILERNAME} in
          GCC)   FCFLAGS="-g -O2 -march=native -msse -msse2 -mfpmath=sse -ffast-math -ftree-vectorize -pipe" ;;
          Intel) FCFLAGS="-g -O3 -no-prec-div -xHost" ;;
          PGI)   FCFLAGS="-g -fast" ;;
          *)     FCFLAGS="-g -O" ;;
        esac ;;
      *x86_64)
        case ${FC_COMPILERNAME} in
          GCC)   FCFLAGS="-g -O2 -march=native -msse -msse2 -mfpmath=sse -ffast-math -ftree-vectorize -pipe" ;;
          Intel) FCFLAGS="-g -O3 -no-prec-div -xHost" ;;
          PGI)   FCFLAGS="-g -fast" ;;
          *)     FCFLAGS="-g -O" ;;
        esac ;;
      *powerpc)
        case ${CC_COMPILERNAME} in
          GCC) FCFLAGS="-g -O2 -mcpu=G5" ;;
          *)   FCFLAGS="-g -O" ;;
        esac ;;
      *) AC_MSG_NOTICE([unknown build_cpu ${build_cpu}])
         FCFLAGS="-g -O" ;;
    esac

    # Test whether these flags actually produce runnable code.
    AC_LANG(Fortran)
    AC_RUN_IFELSE([AC_LANG_PROGRAM([], [
      integer :: i
      i = 1
])],
      [],
      [AC_MSG_NOTICE([resetting FCFLAGS])
       FCFLAGS="-O"])

    AC_MSG_NOTICE([Setting default optimization for ${FC_COMPILERNAME} compiler: FCFLAGS = ${FCFLAGS}])
    optimization_flags="${optimization_flags} FCFLAGS=\"${FCFLAGS}\""
  else
    AC_MSG_NOTICE([User supplied:  FCFLAGS = ${user_FCFLAGS}])
  fi
else
  AC_MSG_RESULT([no])
fi


# Debugging flags?
AC_ARG_ENABLE([debug-flags],
  [AS_HELP_STRING([--enable-debug-flags],
    [Enables debug flag such as bounds checks])],
  [use_debug_flags="${enableval}"],
  [use_debug_flags="no"])

if test "${use_debug_flags}" = "yes"; then

  if test -z "${user_CFLAGS}"; then
    case ${CC_COMPILERNAME} in
      GCC)   CFLAGS="-O0 -g3 -ggdb3 -Wall -pipe" ;;
      Intel) CFLAGS="-O0 -fp-port -fno-omit-frame-pointer -g -debug" ;;
      *)     CFLAGS="-O0 -g" ;;
    esac
    AC_MSG_NOTICE([Setting default optimization for ${CC_COMPILERNAME} compiler: CFLAGS   = ${CFLAGS}])
    optimization_flags="${optimization_flags} CFLAGS=\"${CFLAGS}\""
  else
    AC_MSG_NOTICE([User supplied:  CFLAGS   = ${user_CFLAGS}])
  fi

  if test -z "${user_CXXFLAGS}"; then
    case ${CXX_COMPILERNAME} in
      GCC)   CXXFLAGS="-O0 -g3 -ggdb3 -Wall -pipe" ;;
      Intel) CXXFLAGS="-O0 -fp-port -fno-omit-frame-pointer -g -debug" ;;
      *)     CXXFLAGS="-O0 -g" ;;
    esac
    AC_MSG_NOTICE([Setting default optimization for ${CXX_COMPILERNAME} compiler: CXXFLAGS = ${CXXFLAGS}])
    optimization_flags="${optimization_flags} CXXFLAGS=\"${CXXFLAGS}\""
  else
    AC_MSG_NOTICE([User supplied:  CXXFLAGS = ${user_CXXFLAGS}])
  fi

  if test -z "${user_FFLAGS}"; then
    case ${F77_COMPILERNAME} in
      GCC)   FFLAGS="-O0 -g3 -ggdb3 -fbounds-check -Wall -pipe" ;;
      Intel) FFLAGS="-O0 -fltconsistency -fp-port -fno-omit-frame-pointer -debug -debug-parameters all -check all -g -traceback" ;;
      *)     FFLAGS="-O0 -g" ;;
    esac
    AC_MSG_NOTICE([Setting default optimization for ${F77_COMPILERNAME} compiler: FFLAGS   = ${FFLAGS}])
    optimization_flags="${optimization_flags} FFLAGS=\"${FFLAGS}\""
  else
    AC_MSG_NOTICE([User supplied:  FFLAGS   = ${user_FFLAGS}])
  fi

  if test -z "${user_FCFLAGS}"; then
    case ${FC_COMPILERNAME} in
      GCC)   FCFLAGS="-O0 -g3 -ggdb3 -fbounds-check -Wall -pipe" ;;
      Intel) FCFLAGS="-O0 -fltconsistency -fp-port -fno-omit-frame-pointer -debug -debug-parameters all -check all -g -traceback" ;;
      *)     FCFLAGS="-O0 -g" ;;
    esac
    AC_MSG_NOTICE([Setting default optimization for ${FC_COMPILERNAME} compiler: FCFLAGS  = ${FCFLAGS}])
    optimization_flags="${optimization_flags} FCFLAGS=\"${FCFLAGS}\""
  else
    AC_MSG_NOTICE([User supplied:  FCFLAGS  = ${user_FCFLAGS}])
  fi
fi

AM_CONDITIONAL([AUTOMATIC_FFLAGS], [test -z "${user_FFLAGS}"])

# Check whether to check for case differences in names (for debugging).
AC_MSG_CHECKING([whether to check for case differences in names])
AC_ARG_ENABLE([case-check],
  [AS_HELP_STRING([--enable-case-check],
  [Enables extra checks on case consistency of object names in fortran.
   Normally fortran is case insensitive, this options enables extra checks
   that make names case sensitive. This currently only works with Intel's
   fortran compiler, ifort.])],
  [use_case_check="${enableval}"],
  [use_case_check="no"])

if test ${use_case_check} = "yes"; then
  AC_MSG_RESULT([yes])

  case ${F77_COMPILERNAME} in
    Intel) FFLAGS="${FFLAGS} -names as_is" ;;
    *)     AC_MSG_NOTICE([unsupported compiler for case-check]) ;;
  esac

  case ${FC_COMPILERNAME} in
    Intel) FCFLAGS="${FCFLAGS} -names as_is" ;;
    *)     AC_MSG_NOTICE([unsupported compiler for case-check]) ;;
  esac

else
  AC_MSG_RESULT([no])
fi

# Set line-length limits.
AC_MSG_CHECKING([how to set line length limits of f90 compiler])
case ${FC_COMPILERNAME} in
  GCC)
    AC_MSG_RESULT([gfortran detected, setting unlimited line-length limit (-ffree-line-length-none)])
    FFLAGS="${FFLAGS} -ffixed-line-length-none"
    FCFLAGS="${FCFLAGS} -ffree-line-length-none"
    ;;
  Intel)
    AC_MSG_RESULT([Intel detected, setting long line-length limit (-132)])
    FFLAGS="${FFLAGS} -132"
    FCFLAGS="${FCFLAGS} -132"
    ;;
  *)
    AC_MSG_RESULT([don't know])
    ;;
esac

# Change language to C.
AC_LANG(C)

# Check for some standard headers.
AC_HEADER_STDC
AC_CHECK_HEADERS(sys/resource.h sys/time.h unistd.h sys/ioctl.h sys/types.h math.h sys/wait.h)

AC_MSG_CHECKING([for random number generator seed])
AC_ARG_ENABLE([random-seed],
  [AS_HELP_STRING([--disable-random-seed],
  [Disable the random seed used in the random number generator. When this is
   disabled the random number generator is always seeded with the same seed and
   therefore returns a predictable sequence of random numbers.])],
  [random_seed="${enableval}"],
  [random_seed="yes"])

if test ${random_seed} = "yes"; then
  AC_DEFINE(HAVE_RANDOM_SEED, 1, [Use random seed.])
  AC_MSG_RESULT([use random seed])
else
  AC_MSG_RESULT([do _not_ use random seed, deterministic random number generator])
fi

# Check for phipac.
AC_MSG_CHECKING([whether to use PHiPAC])
AC_ARG_ENABLE([phipac],
  [AS_HELP_STRING([--enable-phipac],
  [Enable the use of phipac optimized dgemms.])],
  [use_phipac="${enableval}"],
  [use_phipac="no"])

if test "${use_phipac}" = "yes"; then
  AC_MSG_RESULT([yes])
  AC_DEFINE(PHIPAC, 1, [Use PHiPAC.])
else
  AC_MSG_RESULT([no])
fi

# Check for MD (TRBO) debugging.
declare -i md_debug_SCFs
AC_ARG_WITH([md-debug],
  [AS_HELP_STRING([--with-md-debug],
  [Using the --with-md-debug=N command line argument, the number of SCFs used
   can be hardwired to something else than 2.])],
  [md_debug_SCFs=${withval}-1],
  [md_debug_SCFs=1])

AC_MSG_CHECKING([whether to debug MD])
AC_ARG_ENABLE([md-debug],
  [AS_HELP_STRING([--enable-md-debug],
  [Enable additional MD debugging. This calculates the converged electronic
   density in addition to the density under incomplete convergence. For
   incomplete convergence, 2 SCFs are used by default.])],
  [enable_md_debug="${enableval}"],
  [enable_md_debug="no"])

if test "${enable_md_debug}" = "yes"; then
  AC_DEFINE_UNQUOTED(MD_DEBUG, [${md_debug_SCFs}], [Do some MD debugging.])
  AC_MSG_RESULT([yes, using $((md_debug_SCFs+1)) SCFs])
else
  AC_MSG_RESULT([no])
fi

# Test some stuff for C-code.
AC_LANG(C)

AC_CHECK_LIB([m], [round], [], [AC_MSG_FAILURE([we need the round() function])])

AC_SEARCH_LIBS([clock_gettime], [rt],
  [],
  [AC_MSG_FAILURE([need clock_gettime()])])

# Check for supported clocks. Thanks to Jonathan Lifflander
# <jliffl2@illinois.edu> for suggesting this test.
for CLOCKTYPE in \
  CLOCK_MONOTONIC_RAW \
  CLOCK_MONOTONIC \
  CLOCK_REALTIME; do
  AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[#include <time.h>]],
    [[struct timespec p; clock_gettime(${CLOCKTYPE}, &p);]])],
    [break], [CLOCKTYPE="unset"])
done
if test "${CLOCKTYPE}" = "unset"; then
  AC_MSG_FAILURE([no known clock type])
fi
AC_DEFINE_UNQUOTED([CLOCKTYPE], [${CLOCKTYPE}], [The clock type to use with clock_gettime()])

# Switch tests to fortran.
AC_LANG(Fortran)

# Find whether the compiler is gfortran and too old...
AC_MSG_CHECKING([for possible compiler problems])
AC_LINK_IFELSE([
PROGRAM test_compiler

  TYPE TestType
    INTEGER, ALLOCATABLE, DIMENSION(:) :: I
  END TYPE TestType

END PROGRAM test_compiler
  ],
  [AC_MSG_RESULT([good, none found])],
  [AC_MSG_RESULT([failed test])
  AC_MSG_FAILURE([The compiler does not understand the ALLOCATABLE attribute
                  inside a type definition. If you are using gcc, we suggest
                  you use a version >= 4.2.0])])

# Check for BLAS.
PKG_CHECK_MODULES([BLAS], [blas], [],
  AC_SEARCH_LIBS([dgemm], [blas], [],
    [AC_MSG_FAILURE([specify the location of dgemm()])])
  )

# Check for LAPACK.
PKG_CHECK_MODULES([LAPACK], [lapack], [],
  AC_SEARCH_LIBS([dsyev], [lapack], [],
    [AC_MSG_FAILURE([specify the library that contains dsyev()])])
  )

AC_ARG_VAR([H5CC], [h5cc compiler wrapper command])

AC_MSG_CHECKING([for hdf5 version])
HDF5_VERSION=$(eval ${H5CC:=h5cc} -showconfig | grep 'HDF5 Version:' | $AWK '{print $[]3}')
AC_MSG_RESULT([${HDF5_VERSION}])
AC_DEFINE_UNQUOTED(HDF5_VERSION, [${HDF5_VERSION}], [The hdf5 library version.])

case "${HDF5_VERSION}" in
  1.8.*) ;;
  *) AC_MSG_FAILURE([unsupported hdf5 library version: ${HDF5_VERSION}])
esac

# Set language to C.
AC_LANG(C)

# Check for math library (ceil).
AC_SEARCH_LIBS([ceil], [m],
             [],
             [AC_MSG_NOTICE([The external hdf5 library might require ceil()])])

# Check for the pthread library.
AC_CHECK_HEADERS(pthread.h)
AC_SEARCH_LIBS([pthread_create], [pthread],
             [],
             [AC_MSG_NOTICE([The external hdf5 library might require the pthread library.])])

# Check for HDF5 libraries.
AC_CHECK_HEADER([hdf5.h],
                [],
                [AC_MSG_FAILURE([I need the hdf5.h header file])])
AC_SEARCH_LIBS([H5get_libversion], [hdf5],
               [],
               [AC_MSG_FAILURE([I need the hdf5 library])])


# Set language to C.
AC_LANG(C)

# Check for math library (ceil).
AC_CHECK_LIB([m],
             [ceil],
             [],
             [AC_MSG_NOTICE([The external hdf5 library might require ceil()])])

# Check for the pthread library.
AC_CHECK_HEADERS(pthread.h)
AC_CHECK_LIB([pthread],
             [pthread_create],
             [],
             [AC_MSG_NOTICE([The external hdf5 library might require the pthread library.])])

# Check for HDF5 libraries.
AC_CHECK_HEADER([hdf5.h],
                [],
                [AC_MSG_FAILURE([I need the hdf5.h header file])])
AC_CHECK_LIB([hdf5],
             [H5get_libversion],
             [],
             [AC_MSG_FAILURE([I need the hdf5 library])])

# Set language to C.
AC_LANG(C)

# Check for zlib compression.
AC_CHECK_HEADERS([zlib.h])
AC_CHECK_LIB([z], [compress2])
AC_CHECK_FUNC([compress2])
AC_LINK_IFELSE([AC_LANG_PROGRAM([char compress2 ();],
  [return compress2 ();])],
  [],
  [AC_MSG_NOTICE([I do not have a working zlib installed.])])

# Check for mkstemp or mkostemp.
AC_MSG_CHECKING([whether we have mkstemp()])
AC_LINK_IFELSE([AC_LANG_PROGRAM([#include <stdlib.h>],
  [int result = mkstemp("/tmp/testtemp");])],
  [AC_MSG_RESULT([yes])
   AC_DEFINE([HAVE_MKSTEMP], [1], [working mkstemp()])],
  [AC_MSG_RESULT([no])])

AC_MSG_CHECKING([whether we have mkostemp()])
AC_LINK_IFELSE([AC_LANG_PROGRAM([#include <stdlib.h>],
  [int result = mkostemp("/tmp/testtemp", 0);])],
  [AC_MSG_RESULT([yes])
   AC_DEFINE([HAVE_MKOSTEMP], [1], [working mkostemp()])],
  [AC_MSG_RESULT([no])])

# Find flags for static linking.
AC_MSG_CHECKING([whether to link binaries statically])
AC_ARG_ENABLE([static-binaries],
  [AS_HELP_STRING([--enable-static-binaries],
  [Disable static linking of FreeON executables.])],
  [static_linking="${enableval}"],
  [static_linking="no"])

AC_MSG_RESULT([${static_linking}])
AM_CONDITIONAL(USE_DYNAMIC_LINKING, [test "${static_linking}" = "no"])

static_linking_flags=""

if test "${static_linking}" = "yes"; then

  if test -z "${LDFLAGS}"; then
    LDFLAGS="-all-static"
  else
    LDFLAGS="${LDFLAGS} -all-static"
  fi

else

  case "${FC_COMPILERNAME}" in
    "Intel") LDFLAGS="${LDFLAGS} -shared-intel" ;;
  esac

fi

AC_MSG_CHECKING([whether we should remove preprocessed files])
AC_ARG_ENABLE([delete-preprocessed-files],
  [AS_HELP_STRING([--disable-delete-preprocessed-files],
  [Disable the deleting of preprocessed files. This is useful for debugging...])],
  [remove_preprocessed_files="${enableval}"],
  [if test "${use_optimizations}" = "no"; then
     remove_preprocessed_files="no"
   else
     remove_preprocessed_files="yes"
   fi])
AC_MSG_RESULT([${remove_preprocessed_files}])
AC_SUBST(REMOVE_PREPROCESSED_FILES, ${remove_preprocessed_files})

AC_MSG_CHECKING([whether to use the old DIIS (for debugging)])
AC_ARG_ENABLE([old-DIIS],
  [AS_HELP_STRING([--enable-old-DIIS],
  [Enable an old version of DIIS (1.3) for debugging.])],
  [use_old_DIIS="${enableval}"],
  [use_old_DIIS="no"])
AC_MSG_RESULT([${use_old_DIIS}])
AM_CONDITIONAL(OLD_DIIS, [test "${use_old_DIIS}" = "yes"])

AC_MSG_CHECKING([whether to use the really old DIIS (for debugging)])
AC_ARG_ENABLE([really-old-DIIS],
  [AS_HELP_STRING([--enable-really-old-DIIS],
  [Enable an old version of DIIS (2004-01-16) for debugging.])],
  [use_really_old_DIIS="${enableval}"],
  [use_really_old_DIIS="no"])
AC_MSG_RESULT([${use_really_old_DIIS}])
AM_CONDITIONAL(REALLY_OLD_DIIS, [test "${use_really_old_DIIS}" = "yes"])

AC_MSG_CHECKING([whether to print out some extra NEB debugging information])
AC_ARG_ENABLE([NEB-debug],
  [AS_HELP_STRING([--enable-NEB-debug],
  [Print out some extra (quite a lot) debugging information in the NEB.])],
  [use_NEB_debug="${enableval}"],
  [use_NEB_debug="no"])
AC_MSG_RESULT([${use_NEB_debug}])
if test "${use_NEB_debug}" = "yes"; then
  AC_DEFINE(NEB_DEBUG, [1], [Print out additional debugging information in NEB])
fi

if test "${use_parallel_clones}" = "yes"; then
  AC_MSG_CHECKING([whether to use Cartesian communicators])
  AC_ARG_ENABLE([cartesian-communicator],
    [AS_HELP_STRING([--disable-cartesian-communicator],
    [Use Cartesian communicator in StartUp(). Use with caution, we saw random
     hangs in the backend when this is turned on.])],
    [use_cartesian_communicator="${enableval}"],
    [use_cartesian_communicator="yes"])
  AC_MSG_RESULT([${use_cartesian_communicator}])
  if test "${use_cartesian_communicator}" = "yes"; then
    AC_DEFINE(CARTESIAN_COMMUNICATOR, [1], [Use Cartesian communicator in StartUp()])
  fi
fi

# Define location of temporary FreeON files.
AC_ARG_VAR([FREEON_SCRATCH],
  [Specify default FREEON_SCRATCH directory])
if test -z "${FREEON_SCRATCH}"; then
  FREEON_SCRATCH="/tmp"
fi
AC_DEFINE_UNQUOTED(HAVE_FREEON_SCRATCH, ["${FREEON_SCRATCH}"], [Define default FREEON_SCRATCH directory.])

# Set some preprocessor command line options.
FORTRAN_CPPFLAGS="-P -C -xc -traditional -I\$(srcdir) -I\$(top_builddir)/Modules"
FORTRAN_DEFAULT_INCLUDES="-I\$(srcdir) -I\$(top_builddir)/Modules"

# Set this stuff in the makefiles.
AC_SUBST(CPP, ${CPP})
AC_SUBST(AM_CPPFLAGS, ${AM_CPPFLAGS})
AC_SUBST(FORTRAN_CPPFLAGS, ${FORTRAN_CPPFLAGS})
AC_SUBST(FORTRAN_DEFAULT_INCLUDES, ${FORTRAN_DEFAULT_INCLUDES})

AC_DEFINE_UNQUOTED(HAVE_FREEON_PLAT,    ["${build}"], [Define build platform.])
AC_DEFINE_UNQUOTED(HAVE_FREEON_HOST,    ["`hostname`"], [Define hostname.])
AC_DEFINE_UNQUOTED(HAVE_FREEON_MACH,    ["${build_cpu}"], [Define build cpu.])
AC_DEFINE_UNQUOTED(HAVE_FREEON_SYST,    ["${build_os}"], [Define build system (os).])
AC_DEFINE_UNQUOTED(HAVE_FREEON_VRSN,    ["`uname -r`"], [Define build os version.])

# Enable fix for gfortran.
if test "${FC_COMPILERNAME}" = "GCC"; then
  AC_DEFINE(GFORTRAN, 1, [Enable fix for gfortran.])
fi

# Output all of it....
AC_CONFIG_FILES([
Doxyfile
config_localversion.h
Makefile
FreeON/Makefile
Modules/Makefile
SCFeqs/Makefile
OneE/Makefile
QCTC/Makefile
HiCu/Makefile
TwoE/Makefile
TwoE/GRD/Makefile
TwoE/HRR/Makefile
TwoE/INT/Makefile
TwoE/MSC/Makefile
TwoE/VRR/Makefile
ONX/Makefile
Validate/Makefile
Validate/SinglePoint/Makefile
Validate/SinglePoint/Restricted/Makefile
tools/Makefile
BasisSets/Makefile
tests/Makefile
])

AC_CONFIG_HEADERS([config.h])

# User doing the configuration
AC_DEFINE_UNQUOTED(CONFIG_USER, ["`whoami`@`hostname`"], [The user running the configure script.])
if test -n "$ORGANIZATION"; then
  AC_DEFINE_UNQUOTED(CONFIG_USER, ["$CONFIG_USER at $ORGANIZATION"], [The user running the configure script.])
fi

# Date this was built.
AC_DEFINE_UNQUOTED(CONFIG_BUILD_DATE, ["`date`"], [The date FreeON was built.])

# Define the maximum number of SCF cycles.
AC_DEFINE(HAVE_MAX_SCF, [256], [The maximum number of SCF cycles. After going
                         through this many SCF cycles, the SCF process is
                         declared converged.])

# For memory debugging.
AC_DEFINE(LOG_MEMORY_USAGE,
          [CALL MondoLog(DEBUG_NONE, __FILE__, "memory at "//TRIM(IntToChar(__LINE__))//": "//TRIM(IntToChar(GetMemoryUsage()))//" kiB")],
          [A helper macro to print out memory usage.])

# Store the compiler flags used somewhere.
AC_DEFINE_UNQUOTED(CFLAGS_STRING,  ["${CFLAGS}"],  [The C-compiler flags used])
AC_DEFINE_UNQUOTED(FFLAGS_STRING,  ["${FFLAGS}"],  [The F77-compiler flags used])
AC_DEFINE_UNQUOTED(FCFLAGS_STRING, ["${FCFLAGS}"], [The F90-compiler flags used])

# Store information on how we were configured.
AC_DEFINE_UNQUOTED(CONFIGURE_ARGUMENTS, ["${ac_configure_args}"], [The command line arguments to the configure script])

# For AInv.
#AC_DEFINE(SPATIAL_THRESHOLDING, [1], [Use spatial thresholding in AInv])

# Print out a summary of options used to compile.
AC_MSG_NOTICE([***   Summary   ***])
AC_MSG_NOTICE([CC                       = ${CC}])
AC_MSG_NOTICE([CXX                      = ${CXX}])
AC_MSG_NOTICE([FC                       = ${FC}])
AC_MSG_NOTICE([F77                      = ${F77}])
AC_MSG_NOTICE([CFLAGS                   = ${CFLAGS}])
AC_MSG_NOTICE([CXXFLAGS                 = ${CXXFLAGS}])
AC_MSG_NOTICE([FCFLAGS                  = ${FCFLAGS}])
AC_MSG_NOTICE([FFLAGS                   = ${FFLAGS}])
AC_MSG_NOTICE([LDFLAGS                  = ${LDFLAGS}])
AC_MSG_NOTICE([LIBS                     = ${LIBS}])
AC_MSG_NOTICE([CPPFLAGS                 = ${CPPFLAGS}])
AC_MSG_NOTICE([FORTRAN_CPPFLAGS         = ${FORTRAN_CPPFLAGS}])
AC_MSG_NOTICE([FORTRAN_DEFAULT_INCLUDES = ${FORTRAN_DEFAULT_INCLUDES}])
AC_MSG_NOTICE([HDF5_CPPFLAGS            = ${HDF5_CPPFLAGS}])
AC_MSG_NOTICE([FREEON_SCRATCH           = ${FREEON_SCRATCH}])
AC_MSG_NOTICE([])
AC_MSG_NOTICE([Using external lapack library])
AC_MSG_NOTICE([Using external hdf5 library])
if test "${use_optimizations}" = "no"; then
  AC_MSG_NOTICE([I disabled compiler optimization flags])
fi
if test "${remove_preprocessed_files}" = "yes"; then
  AC_MSG_NOTICE([I will remove preprocessed files])
else
  AC_MSG_NOTICE([I will _not_ remove preprocessed files])
fi
if test "${use_phipac}" = "yes"; then
  AC_MSG_NOTICE([Using phipac])
else
  AC_MSG_NOTICE([we are _not_ using phipac])
fi
if test "${enable_md_debug}" = "yes"; then
  AC_MSG_NOTICE([The TRBO MD will use only $((md_debug_SCFs+1)) SCFs per time step.])
else
  AC_MSG_NOTICE([no extra TRBO MD debugging])
fi
AC_MSG_NOTICE([*** End Summary ***])

# Pass the optimization flags to the hdf configure script.
#ac_configure_args="${ac_configure_args} ${optimization_flags}"

# Move CFLAGS to CONFIGURE_CFLAGS so we can possibly override them in the makefiles.
AC_SUBST([CONFIGURE_CFLAGS], [${CFLAGS}])
AC_SUBST([CONFIGURE_FFLAGS], [${FFLAGS}])
AC_SUBST([CONFIGURE_FCFLAGS], [${FCFLAGS}])

CFLAGS=
FFLAGS=
FCFLAGS=

AC_OUTPUT
