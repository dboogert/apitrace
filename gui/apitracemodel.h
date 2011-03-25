#ifndef APITRACEMODEL_H
#define APITRACEMODEL_H


#include <QAbstractItemModel>
#include <QModelIndex>
#include <QVariant>

class ApiTraceCall;
class LoaderThread;
namespace Trace {
    class Call;
}

class ApiTraceModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    ApiTraceModel(QObject *parent = 0);
    ~ApiTraceModel();

    QVariant data(const QModelIndex &index, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const;
    bool hasChildren(const QModelIndex &parent) const;
    QModelIndex parent(const QModelIndex &index) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    bool insertRows(int position, int rows,
                    const QModelIndex &parent = QModelIndex());
    bool removeRows(int position, int rows,
                    const QModelIndex &parent = QModelIndex());

public slots:
    void loadTraceFile(const QString &fileName);
    void appendCalls(const QList<Trace::Call*> traceCalls);

private:
    QList<ApiTraceCall*> m_calls;
    LoaderThread        *m_loader;
};

#endif
