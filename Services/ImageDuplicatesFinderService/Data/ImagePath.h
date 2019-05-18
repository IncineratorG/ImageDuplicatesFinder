#ifndef IMAGEPATH_H
#define IMAGEPATH_H

#include <QString>



class ImagePath
{
public:
    ImagePath();
    ImagePath(const QString& path);
    ImagePath(const ImagePath& other);

    QString toString() const;

private:
    QString m_imagePath;
};

#endif // IMAGEPATH_H
