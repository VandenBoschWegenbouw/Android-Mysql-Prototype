#ifndef WORKEDHOURSLIST_H
#define WORKEDHOURSLIST_H

#include <QObject>
#include <QVector>

struct WorkedHoursItem
{
    QString company;
    QString project;
    int hours;
};

class WorkedHoursList : public QObject
{
    Q_OBJECT
public:
    explicit WorkedHoursList(QObject *parent = nullptr);

    QVector<WorkedHoursItem> items() const;

    bool setItemAt(int index, const WorkedHoursItem &item);

signals:
    void preItemAppended();
    void postItemAppended();

    void preItemRemoved(int index);
    void postItemRemoved();

public slots:
    void appendItem();
    void appendItem(WorkedHoursItem item);
    void removeCompletedItems();

private:
    QVector<WorkedHoursItem> mItems;
};

#endif // WORKEDHOURSLIST_H
