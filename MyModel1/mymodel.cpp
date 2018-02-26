#include "mymodel.h"
#include<qDebug>
#include<QFont>
#include<QBrush>
#include"time.h"
#include<QDateTime>
MyModel::MyModel(QObject *parent):
    QAbstractTableModel(parent)
{
    qDebug()<<"what is your name?";
    time = new QTimer(this);
    time->setInterval(1000);
    connect(time,SIGNAL(timeout()),this,SLOT(ChangedTime()));
    time->start();
}
void MyModel::ChangedTime()
{
    QModelIndex index = createIndex(0,0);
    emit dataChanged(index,index);
}
int MyModel::rowCount(const QModelIndex &parent) const
{
    qDebug()<<"Row";
    return 2;
}

int MyModel::columnCount(const QModelIndex &parent) const
{
    qDebug()<<"Col";
    return 3;
}
QVariant MyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal) {
            switch (section)
            {
            case 0:
                return QString("first");
            case 1:
                return QString("second");
            case 2:
                return QString("third");
            }
        }
    }
    return QVariant();
}
//显示模型数据
QVariant MyModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    int col = index.column();

    if (role == Qt::DisplayRole)
    {
        if (row == 0 && col == 0)
        {
            return QDateTime::currentDateTime().toString();
        }
    }
    return QVariant();
//    int row = index.row();
//     int col = index.column();
//     // generate a log message when this method gets called
//     qDebug() << QString("row %1, col%2, role %3")
//             .arg(row).arg(col).arg(role);

//     switch(role){
//     case Qt::DisplayRole:
//         if (row == 0 && col == 1) return QString("<--left");
//         if (row == 1 && col == 1) return QString("right-->");

//         return QString("Row%1, Column%2")
//                 .arg(row + 1)
//                 .arg(col +1);
//         break;
//     case Qt::FontRole:
//         if (row == 0 && col == 0) //change font only for cell(0,0)
//         {
//             QFont boldFont;
//             boldFont.setBold(true);
//             return boldFont;
//         }
//         break;
//     case Qt::BackgroundRole:

//         if (row == 1 && col == 2)  //change background only for cell(1,2)
//         {
//             QBrush redBackground(Qt::red);
//             return redBackground;
//         }
//         break;
//     case Qt::TextAlignmentRole:

//         if (row == 1 && col == 1) //change text alignment only for cell(1,1)
//         {
//             return Qt::AlignRight + Qt::AlignVCenter;
//         }
//         break;
//     case Qt::CheckStateRole:

//         if (row == 1 && col == 0) //add a checkbox to cell(1,0)
//         {
//             return Qt::Checked;
//         }
//     }
//     return QVariant();
}

