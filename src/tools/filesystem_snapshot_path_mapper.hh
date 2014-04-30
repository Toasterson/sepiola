/*
#| sepiola - Open Source Online Backup Client
#| Copyright (C) 2007-2014 stepping stone GmbH
#|
#| This program is free software; you can redistribute it and/or
#| modify it under the terms of the GNU General Public License
#| Version 2 as published by the Free Software Foundation.
#|
#| This program is distributed in the hope that it will be useful,
#| but WITHOUT ANY WARRANTY; without even the implied warranty of
#| MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#| GNU General Public License for more details.
#|
#| You should have received a copy of the GNU General Public License
#| along with this program; if not, write to the Free Software
#| Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#ifndef FILESYSTEM_SNAPSHOT_PATH_MAPPER_HH_
#define FILESYSTEM_SNAPSHOT_PATH_MAPPER_HH_

#include "utils/datatypes.hh"

class QString;

class FilesystemSnapshotPathMapper
{
public:

    /**
     * Constructs the FilesystemSnapshotPathMapper
     * @param The partition (mount point)
     * @param A BackupSelectionHash which contains all files (with relative file
     * path) on this partition
     */
    FilesystemSnapshotPathMapper(const QString& _partition, const BackupSelectionHash& includeRules);

    /**
     * Destroys the FilesystemSnapshotPathMapper
     */
    virtual ~FilesystemSnapshotPathMapper();

    // Getters
    /**
     * Returns the partition name (mount point)
     * @return The partition name (mount point)
     */
    const QString& getPartition() const;

    /**
     * Returns all files on the given partition
     * @return All files on the given partition
     */
    const BackupSelectionHash& getRelativeIncludes() const;

    /**
     * Returns the local snapshot path for the given partition
     * @return The local snapshot path for the given partition
     */
    const QString& getSnapshotPath() const;

    // Setters
    /**
     * Sets the partition name (mount point)
     * @param The partition name (mount point)
     */
    void setPartition(const QString& partition);

    /**
     * Sets the relative include rules (for the given partition)
     * @param The relative BackupSelectionHash
     */
    void setRelativeIncludes(const BackupSelectionHash& relativeIncludes);

    /**
     * Sets the local snapshot path for the given partition
     * @param The local snapshot path for the given partition
     */
    void setSnapshotPath(const QString& snapshotPath);

    /**
     * Add a single file to the relativeInclude list of this mapper object
     * @param The relative filename (relative concerning the partition)
     * @param Whether to backup this file or not
     */
    void addFileToRelativeIncludes( QString filename, bool backup );

private:
    QString partition;
    QString snapshotPath;
    BackupSelectionHash relativeIncludes;
};

#endif /* FILESYSTEM_SNAPSHOT_PATH_MAPPER_HH_ */
