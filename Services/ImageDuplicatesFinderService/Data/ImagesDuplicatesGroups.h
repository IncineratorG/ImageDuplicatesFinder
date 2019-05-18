#ifndef IMAGESDUPLICATESGROUPS_H
#define IMAGESDUPLICATESGROUPS_H

#include "ImageDuplicatesGroup.h"



class ImagesDuplicatesGroups
{
public:
    ImagesDuplicatesGroups();
    ImagesDuplicatesGroups(const ImagesDuplicatesGroups& other);

    void clear();

    void appendGroup(const ImageDuplicatesGroup& group);
    bool removeGroup(const int position);

    QList<ImageDuplicatesGroup> getGroupsList() const;
    int getGroupPosition(const ImageDuplicatesGroup& group);

private:
    QList<ImageDuplicatesGroup> m_groupsList;
};

#endif // IMAGESDUPLICATESGROUPS_H
