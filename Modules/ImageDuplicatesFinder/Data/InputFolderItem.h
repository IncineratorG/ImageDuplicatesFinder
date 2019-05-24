#ifndef INPUTFOLDERITEM_H
#define INPUTFOLDERITEM_H

#include <QString>



class InputFolderItem
{
public:
    InputFolderItem();
    InputFolderItem(const QString& path, const bool processSubpath = true);
    InputFolderItem(const InputFolderItem& other);

    void setPath(const QString& path, const bool processSubpath = true);

    QString getPath() const;
    bool getProcessSubpath() const;

private:
    QString m_path;
    bool m_processSubpath;
};

#endif // INPUTFOLDERITEM_H
