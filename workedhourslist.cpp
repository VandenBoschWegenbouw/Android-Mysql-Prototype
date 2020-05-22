#include "workedhourslist.h"

WorkedHoursList::WorkedHoursList(QObject *parent) : QObject(parent)
{
}

QVector<WorkedHoursItem> WorkedHoursList::items() const
{
    return mItems;
}

bool WorkedHoursList::setItemAt(int index, const WorkedHoursItem &item)
{
    if (index < 0 || index >= mItems.size())
        return false;

    const WorkedHoursItem &oldItem = mItems.at(index);
    if (item.company == oldItem.company && item.project == oldItem.project && item.hours == oldItem.hours)
        return false;

    mItems[index] = item;
    return true;
}

void WorkedHoursList::appendItem()
{
    emit preItemAppended();

    WorkedHoursItem item;
    item.company = "Code company";
    item.project = "Code project";
    item.hours = 999;
    mItems.append(item);

    emit postItemAppended();
}

void WorkedHoursList::appendItem(WorkedHoursItem item) {
    emit preItemAppended();

    mItems.append(item);

    emit postItemAppended();
}

void WorkedHoursList::removeCompletedItems()
{
    for (int i = 0; i < mItems.size(); ) {
        if (false) {
            emit preItemRemoved(i);

            mItems.removeAt(i);

            emit postItemRemoved();
        } else {
            ++i;
        }
    }
}
