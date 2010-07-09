/* close-uart.c. Implementation of the _close syscall for newlib with UART

   Copyright (C) 2004, Jacob Bower
   Copyright (C) 2010, Embecosm Limited <info@embecosm.com>
 
   Contributor Jeremy Bennett <jeremy.bennett@embecosm.com>
  
   This file is part of Newlib.

   The original work by Jacob Bower is provided as-is without any kind of
   warranty. Use it at your own risk!

   All subsequent work is bound by version 3 of the GPL as follows.
 
   This program is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by the Free
   Software Foundation; either version 3 of the License, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
   FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
   more details.

   You should have received a copy of the GNU General Public License along
   with this program.  If not, see <http:#www.gnu.org/licenses/>.             */
/* -------------------------------------------------------------------------- */
/* This program is commented throughout in a fashion suitable for processing
   with Doxygen.                                                              */
/* -------------------------------------------------------------------------- */

#include <errno.h>
#include <unistd.h>


extern int  errno;


/* -------------------------------------------------------------------------- */
/*!Close a file when using a UART.

   We only support stdin, stdout and stderr and these cannot be closed. Any
   other file is invalid.

   Remember that this function is *not* reentrant, so no static state should
   be held.

   @param[in] file  The fileno to close.

   @return  -1 to indicate failure, with an error code in the global variable
            errno.                                                            */
/* -------------------------------------------------------------------------- */
int
_close (int   file)
{
  errno = (file == STDIN_FILENO ||
	   file == STDERR_FILENO ||
	   file == STDOUT_FILENO) ? EIO : EBADF;
  
  return -1;			/* Always fails */

}	/* _close () */
