#ifndef SEQUENTIALIMAGESPATHSFINDER_H
#define SEQUENTIALIMAGESPATHSFINDER_H

#include "AbstractImagesPathsFinder.h"



class SequentialImagesPathsFinder : public AbstractImagesPathsFinder
{
public:
    SequentialImagesPathsFinder();

    void setPaths(std::shared_ptr<Paths> paths);
    std::shared_ptr<ImagesPaths> getImagesPaths();

    QString getOperationName();

    void run();

private:
    std::shared_ptr<Paths> m_paths;
    std::shared_ptr<ImagesPaths> m_imagesPaths;

    const QString OPERATION_NAME;

    void doWork();

    bool isImage(const Path& path) const;
    bool isImage(const QString& path) const;
};

#endif // SEQUENTIALIMAGESPATHSFINDER_H
