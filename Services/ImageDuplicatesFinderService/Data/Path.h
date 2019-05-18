#ifndef PATH_H
#define PATH_H

#include <QString>



class Path
{
public:
    Path();
    Path(const QString& path);
    Path(const Path& othre);

    QString toString() const;

private:
    QString m_path;
};

#endif // PATH_H
