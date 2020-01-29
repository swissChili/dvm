#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([FULL-PACKAGE-NAME], [VERSION], [BUG-REPORT-ADDRESS])
AC_CONFIG_SRCDIR([configure.ac])

PKG_CHECK_MODULES([LIBCOLLECT], [libcollect >= 1])

AC_CONFIG_FILES([Makefile])
AM_INIT_AUTOMAKE([foreign -Wall -Werror])

AC_PROG_CC
AC_PROG_LEX
AC_PROG_YACC

AC_OUTPUT
