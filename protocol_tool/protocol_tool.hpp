#ifndef _PROTOCOL_TOOL_
#define _PROTOCOL_TOOL_

#include <QWidget>
#include <QTableWidget>
#include <QListWidget>
#include <QTreeWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSplitter>
#include <QHeaderView>
#include <QAction>

class ProtocolTool : public QWidget
{
    Q_OBJECT
public:
    explicit ProtocolTool(QWidget *parent = nullptr);
    ~ProtocolTool();

private:
    QTreeWidget *mMsgTreeWidget;
    QTableWidget *mProtocolTableWidget;

};

#endif