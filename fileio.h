#ifndef FILEIO_H
#define FILEIO_H


class FileIO
{
public:
    FileIO();
    ~FileIO();
    void getFigureFileDirectory();
    QStringList getGCodesFromFile(QString);

private:
};

#endif // FILEIO_H
