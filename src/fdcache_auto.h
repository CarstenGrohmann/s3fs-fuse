/*
 * s3fs - FUSE-based file system backed by Amazon S3
 *
 * Copyright(C) 2007 Randy Rizun <rrizun@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef S3FS_FDCACHE_AUTO_H_
#define S3FS_FDCACHE_AUTO_H_

#include "fdcache_entity.h"

//------------------------------------------------
// class AutoFdEntity
//------------------------------------------------
// A class that opens fdentiry and closes it automatically.
// This class object is used to prevent inconsistencies in
// the number of references in fdentiry.
// The methods are wrappers to the method of the FdManager class.
//
class AutoFdEntity
{
  private:
      FdEntity* pFdEntity;
      int       pseudo_fd;

  private:
      AutoFdEntity(AutoFdEntity& other);
      bool operator=(AutoFdEntity& other);

  public:
      AutoFdEntity();
      ~AutoFdEntity();

      bool Close();
      int Detach();
      bool Attach(const char* path, int existfd);
      int GetPseudoFd() const { return pseudo_fd; }

      FdEntity* Open(const char* path, headers_t* pmeta = NULL, off_t size = -1, time_t time = -1, int flags = O_RDONLY, bool force_tmpfile = false, bool is_create = true, bool no_fd_lock_wait = false);
      FdEntity* GetExistFdEntity(const char* path, int existfd = -1);
      FdEntity* OpenExistFdEntiy(const char* path, int flags = O_RDONLY);
};

#endif // S3FS_FDCACHE_AUTO_H_

/*
* Local variables:
* tab-width: 4
* c-basic-offset: 4
* End:
* vim600: expandtab sw=4 ts=4 fdm=marker
* vim<600: expandtab sw=4 ts=4
*/
