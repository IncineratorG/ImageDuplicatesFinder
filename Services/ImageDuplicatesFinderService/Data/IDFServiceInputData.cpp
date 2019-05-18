#include "IDFServiceInputData.h"



IDFServiceInputData::IDFServiceInputData() {

}

IDFServiceInputData::IDFServiceInputData(const QList<IDFServiceInputDataItem>& inputDataList)
    : m_inputDataList(inputDataList)
{

}

IDFServiceInputData::IDFServiceInputData(const IDFServiceInputData& other)
    : m_inputDataList(other.m_inputDataList)
{

}

void IDFServiceInputData::appendInputDataItem(const IDFServiceInputDataItem& item) {
    m_inputDataList.append(item);
}

void IDFServiceInputData::setInputDataList(const QList<IDFServiceInputDataItem>& inputDataList) {
    m_inputDataList = inputDataList;
}

QList<IDFServiceInputDataItem> IDFServiceInputData::getInputDataList() const {
    return m_inputDataList;
}

Paths IDFServiceInputData::toPaths() {
    Paths paths;

    for (int i = 0; i < m_inputDataList.size(); ++i) {
        const IDFServiceInputDataItem& item = m_inputDataList.at(i);

        const QString pathString = item.getPath();
        const bool processSubpaths = item.getProcessSubpath();

        if (!processSubpaths)
            paths.appendPath(Path(pathString));

        toPaths_r(QDir(pathString), paths);
    }

    return paths;
}

void IDFServiceInputData::toPaths_r(const QDir& directory, Paths& paths) {
    paths.appendPath(Path(directory.absolutePath()));

    const QFileInfoList& directoryInfoList = directory.entryInfoList(QDir::NoDotAndDotDot | QDir::Dirs | QDir::Dirs);
    for (int i = 0; i < directoryInfoList.size(); ++i) {
        const QFileInfo& fileInfo = directoryInfoList.at(i);

        if (fileInfo.isHidden())
            continue;

        if (fileInfo.isDir())
            toPaths_r(QDir(fileInfo.absoluteFilePath()), paths);
    }
}
