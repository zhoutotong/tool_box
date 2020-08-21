#include "protocol_tool.hpp"

ProtocolTool::ProtocolTool(QWidget *parent) : QWidget(parent)
  , mMsgTreeWidget(nullptr)
  , mProtocolTableWidget(nullptr)
{

    QVBoxLayout *layout = new QVBoxLayout(this);


    // 主视布局
    mMsgTreeWidget = new QTreeWidget(this);
    mMsgTreeWidget->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
    mProtocolTableWidget = new QTableWidget(this);
    mProtocolTableWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);


    QSplitter *midSplitter = new QSplitter(this);
    midSplitter->addWidget(mMsgTreeWidget);
    midSplitter->addWidget(mProtocolTableWidget);

    layout->addWidget(midSplitter);

    // 处理协议基本消息
    const QStringList msgListHeader = {"帧ID", "类型", "格式"};
    mMsgTreeWidget->setHeaderLabels(msgListHeader);
    mMsgTreeWidget->setColumnCount(msgListHeader.size());
    mMsgTreeWidget->addAction(new QAction("test"));

    // 处理协议帧内容
    const QStringList protocolTableHeader = {"名称", "类型", "起始位", "位宽", "偏置", "精度", "最大值", "最小值"};
    mProtocolTableWidget->setColumnCount(protocolTableHeader.size());
    mProtocolTableWidget->setHorizontalHeaderLabels(protocolTableHeader);
    for(int i = 0; i < protocolTableHeader.size(); i++)
    {
        mProtocolTableWidget->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
    }
}

ProtocolTool::~ProtocolTool()
{

}