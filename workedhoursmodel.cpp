#include "workedhoursmodel.h"


#include "workedhourslist.h"

WorkedHoursModel::WorkedHoursModel(QObject *parent)
    : QAbstractListModel(parent)
    , mList(nullptr)
{
}

int WorkedHoursModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid() || !mList)
        return 0;

    return mList->items().size();
}

QVariant WorkedHoursModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || !mList)
        return QVariant();

    const WorkedHoursItem item = mList->items().at(index.row());
    switch (role) {
//    case DoneRole:
//        return QVariant(item.done);
//    case DescriptionRole:
//        return QVariant(item.description);

        case CompanyRole:
            return QVariant(item.company);
    case ProjectRole:
        return QVariant(item.project);
    case HoursRole:
        return QVariant(item.hours);
    }

    return QVariant();
}

bool WorkedHoursModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!mList)
        return false;

    WorkedHoursItem item = mList->items().at(index.row());
    switch (role) {
//    case DoneRole:
//        item.done = value.toBool();
//        break;
//    case DescriptionRole:
//        item.description = value.toString();
//        break;
        case CompanyRole:
            item.company = value.toString();
        break;
        case ProjectRole:
            item.project = value.toString();
        break;
        case HoursRole:
            item.hours = value.toInt();
        break;
    }

    if (mList->setItemAt(index.row(), item)) {
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags WorkedHoursModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> WorkedHoursModel::roleNames() const
{
    QHash<int, QByteArray> names;
    names[CompanyRole] = "company";
    names[ProjectRole] = "project";
    names[HoursRole] = "hours";
    return names;
}

WorkedHoursList *WorkedHoursModel::list() const
{
    return mList;
}

void WorkedHoursModel::setList(WorkedHoursList *list)
{
    beginResetModel();

    if (mList)
        mList->disconnect(this);

    mList = list;

    if (mList) {
        connect(mList, &WorkedHoursList::preItemAppended, this, [=]() {
            const int index = mList->items().size();
            beginInsertRows(QModelIndex(), index, index);
        });
        connect(mList, &WorkedHoursList::postItemAppended, this, [=]() {
            endInsertRows();
        });

        connect(mList, &WorkedHoursList::preItemRemoved, this, [=](int index) {
            beginRemoveRows(QModelIndex(), index, index);
        });
        connect(mList, &WorkedHoursList::postItemRemoved, this, [=]() {
            endRemoveRows();
        });
    }

    endResetModel();
}
