#ifndef INPUTFOLDERSMODELITEM_H
#define INPUTFOLDERSMODELITEM_H

#include <QString>



class InputFoldersModelItem
{
public:
    InputFoldersModelItem();
    InputFoldersModelItem(const QString& path, const bool processSubpath = true);
    InputFoldersModelItem(const InputFoldersModelItem& other);

    void setPath(const QString& path, const bool processSubpath = true);

    QString getPath() const;
    bool getProcessSubpath() const;

private:
    QString m_path;
    bool m_processSubpath;
};

#endif // INPUTFOLDERSMODELITEM_H
