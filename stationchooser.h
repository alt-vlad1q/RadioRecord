#ifndef STATIONCHOOSER_H
#define STATIONCHOOSER_H

#include <QObject>
#include <QMediaPlayer>
#include <QMap>
#include <QScopedPointer>

class StationChooser : public QObject
{
    Q_OBJECT
public:
    explicit StationChooser(QObject *parent = nullptr);
    ~StationChooser();

    Q_INVOKABLE void setStation(QString name);
    Q_INVOKABLE void stop();

private:
    QScopedPointer<QMediaPlayer> m_player;
    QMap<QString, QUrl> m_stations;

};

#endif // STATIONCHOOSER_H
