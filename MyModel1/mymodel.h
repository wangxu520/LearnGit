#ifndef MYMODEL_H
#define MYMODEL_H
#include<QAbstractTableModel>
#include<QTimer>
class MyModel:public QAbstractTableModel
{
    Q_OBJECT
public:
    MyModel(QObject *parent = 0);
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
   // QVariant setData(const QModelIndex &index, const QVariant &value, int role);
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
private slots:
    void ChangedTime();
private:
    QTimer *time;
};

#endif // MYMODEL_H
