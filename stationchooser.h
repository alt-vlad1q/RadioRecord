#ifndef STATIONCHOOSER_H
#define STATIONCHOOSER_H

#include <QObject>
#include <QMediaPlayer>
#include <QMap>

class StationChooser : public QObject
{
    Q_OBJECT
public:
    explicit StationChooser(QObject *parent = nullptr);
    ~StationChooser();

    Q_INVOKABLE void setStation(QString name);

private:
    QMediaPlayer *m_player;
    QMap<QString, QUrl> m_stations;

};

#endif // STATIONCHOOSER_H
