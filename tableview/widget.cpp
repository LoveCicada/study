#include "widget.h"
#include <QList>
#include <QDebug>
#include <QDateTime>

MusicInfoModel::MusicInfoModel(QObject *parent)
	:QStandardItemModel(parent)
{

}

void MusicInfoModel::intiData(QList<SongInfo>& _listSongInfo)
{
	for (int i = 0; i < SONGNUM; ++i)
	{
		SongInfo info;
		if (i % 2 == 0)
		{
			info.strName = QStringLiteral("歌手") + QString::number(i);
			info.strSinger = QStringLiteral("中国") + QString::number(i) + QStringLiteral("人");
			info.strAlbum = QStringLiteral("好歌曲") + QString::number(i) + QStringLiteral("哈");
		}
		else
		{
			info.strName = QStringLiteral("音乐人") + QString::number(i);
			info.strSinger = QStringLiteral("外国") + QString::number(i) + QStringLiteral("友人");
			info.strAlbum = QStringLiteral("好声音") + QString::number(i) + QStringLiteral("咯");
		}

		QDateTime time = QDateTime::currentDateTime();
		time = time.addSecs(60 * i);
		info.strDate = time.toString("hh::mm::ss");
		_listSongInfo.push_back(info);
	}
}

void MusicInfoModel::loadData(/*const QString& strKeyWord*/)
{
	clear();
	QStringList labels;
	labels << QString::fromLocal8Bit("音乐标题")
		<< QString::fromLocal8Bit("歌手")
		<< QString::fromLocal8Bit("专辑")
		<< QString::fromLocal8Bit("日期");
	setHorizontalHeaderLabels(labels);

	QList<SongInfo> listSongInfo;
	intiData(listSongInfo);

	//深色
	QColor itemBackbroundDarkColor(100, 100, 100);
	//浅色
	QColor itemBackbroundLightColor(121, 121, 121);
	QColor itemFontColor(255, 255, 255);

	for (SongInfo songItem : listSongInfo)
	{

		QBrush brush(itemBackbroundDarkColor);
		QList<QStandardItem*> listItems;
		QStandardItem* pTitle = new QStandardItem(songItem.strName);
		int id = 123456;
		pTitle->setData(id);
		pTitle->setBackground(brush);
		pTitle->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

		QStandardItem* pSinger = new QStandardItem(songItem.strSinger);
		pSinger->setBackground(brush);
		pSinger->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

		QStandardItem* pAlbum = new QStandardItem(songItem.strAlbum);
		pAlbum->setBackground(brush);
		pAlbum->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

		QStandardItem* pDate = new QStandardItem(songItem.strDate);
		pDate->setBackground(brush);
		pDate->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

		listItems << pTitle << pSinger << pAlbum << pDate;
		appendRow(listItems);
	}

	if (listSongInfo.size() < MINSONGNUM)
	{
		int addNum = MINSONGNUM - listSongInfo.size();
		for (int j = 0; j < addNum; ++j)
		{
			QBrush brush(itemBackbroundDarkColor);
			QList<QStandardItem*> listItems;
			QStandardItem* pTitle = new QStandardItem("");
			pTitle->setBackground(brush);
			pTitle->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

			QStandardItem* pSinger = new QStandardItem("");
			pSinger->setBackground(brush);
			pSinger->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

			QStandardItem* pAlbum = new QStandardItem("");
			pAlbum->setBackground(brush);
			pAlbum->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

			QStandardItem* pDate = new QStandardItem("");
			pDate->setBackground(brush);
			pDate->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

			listItems << pTitle << pSinger << pAlbum << pDate;
			appendRow(listItems);
		}
	}

}


//////////////////////////////////////////////////////

CXESortFilterProxyModel::CXESortFilterProxyModel(QObject *parent)
	:QSortFilterProxyModel(parent)
{

}

void CXESortFilterProxyModel::sort(int column, Qt::SortOrder order)
{
	

}




//////////////////////////////////////////////////////

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
	
	initCtrl();
	initData();
}

Widget::~Widget()
{

}

void Widget::initCtrl()
{
	m_pVLayout = new QVBoxLayout(this);

	m_pHLayoutNet = new QHBoxLayout(this);
	m_pNetSearchEdit = new QLineEdit();
	m_pNetSearchBtn = new QPushButton();
	m_pNetSearchBtn->setText(QStringLiteral("网上搜索"));
	m_pHLayoutNet->addWidget(m_pNetSearchEdit);
	m_pHLayoutNet->addWidget(m_pNetSearchBtn);

	m_pHLayoutLocalSel = new QHBoxLayout(this);
	m_pLocalSearchSelEdit = new QLineEdit();
	m_pLocalSearchSelBtn = new QPushButton();
	m_pLocalSearchSelBtn->setText(QStringLiteral("本地搜索选中"));
	m_pHLayoutLocalSel->addWidget(m_pLocalSearchSelEdit);
	m_pHLayoutLocalSel->addWidget(m_pLocalSearchSelBtn);

	m_pHLayoutLocalFilt = new QHBoxLayout(this);
	m_pLocalSearchFiltEdit = new QLineEdit();
	m_pLocalSearchFiltBtn = new QPushButton();
	m_pLocalSearchFiltBtn->setText(QStringLiteral("本地搜索过滤"));
	m_pHLayoutLocalFilt->addWidget(m_pLocalSearchFiltEdit);
	m_pHLayoutLocalFilt->addWidget(m_pLocalSearchFiltBtn);

	m_pHLayoutNSort = new QHBoxLayout(this);
	m_pSortNEdit = new QLineEdit();
	m_pSortNBtn = new QPushButton();
	m_pSortNBtn->setText(QStringLiteral("排序-递减"));
	m_pHLayoutNSort->addWidget(m_pSortNEdit);
	m_pHLayoutNSort->addWidget(m_pSortNBtn);

	m_pHLayoutPSort = new QHBoxLayout(this);
	m_pSortPEdit = new QLineEdit();
	m_pSortPBtn = new QPushButton();
	m_pSortPBtn->setText(QStringLiteral("排序-递增"));
	m_pHLayoutPSort->addWidget(m_pSortPEdit);
	m_pHLayoutPSort->addWidget(m_pSortPBtn);

	m_pHLayoutPSearch = new QHBoxLayout(this);
	m_pBeginEdit = new QLineEdit();
	m_pBeginEdit->setPlaceholderText(QStringLiteral("中国2"));
	m_pBeginEdit->setAlignment(Qt::AlignCenter);
	m_pLable = new QLabel(this);
	m_pLable->setText("--");
	m_pLable->setAlignment(Qt::AlignCenter);
	m_pEndEdit = new QLineEdit();
	m_pEndEdit->setPlaceholderText(QStringLiteral("中国7"));
	m_pEndEdit->setAlignment(Qt::AlignCenter);
	m_pSearchBtn = new QPushButton(this);
	m_pHLayoutPSearch->addWidget(m_pBeginEdit);
	m_pHLayoutPSearch->addWidget(m_pLable);
	m_pHLayoutPSearch->addWidget(m_pEndEdit);
	m_pHLayoutPSearch->addWidget(m_pSearchBtn);

	m_pHLayoutTimeSearch = new QHBoxLayout(this);
	m_pBeginTimeEdit = new QDateTimeEdit();
	m_pBeginTimeEdit->setDisplayFormat("hh:mm:ss");
	m_pBeginTimeEdit->setStyleSheet("background-color:rgba(63,63,63,255)");
	m_pBeginTimeEdit->setAlignment(Qt::AlignCenter);
	m_pTimeLabel = new QLabel(this);
	m_pTimeLabel->setText("--");
	m_pTimeLabel->setAlignment(Qt::AlignCenter);
	m_pEndTimeEdit = new QDateTimeEdit();
	m_pEndTimeEdit->setDisplayFormat("hh:mm:ss");
	m_pEndTimeEdit->setAlignment(Qt::AlignCenter);
	m_pSearchTimeBtn = new QPushButton(this);
	m_pHLayoutTimeSearch->addWidget(m_pBeginTimeEdit);
	m_pHLayoutTimeSearch->addWidget(m_pTimeLabel);
	m_pHLayoutTimeSearch->addWidget(m_pEndTimeEdit);
	m_pHLayoutTimeSearch->addWidget(m_pSearchTimeBtn);

	m_pVLayout->addLayout(m_pHLayoutNet);
	m_pVLayout->addLayout(m_pHLayoutLocalSel);
	m_pVLayout->addLayout(m_pHLayoutLocalFilt);
	m_pVLayout->addLayout(m_pHLayoutNSort);
	m_pVLayout->addLayout(m_pHLayoutPSort);
	m_pVLayout->addLayout(m_pHLayoutPSearch);
	m_pVLayout->addLayout(m_pHLayoutTimeSearch);

	m_pTableView = new CXETableView();
	m_pVLayout->addWidget(m_pTableView);

	connect(m_pLocalSearchSelBtn, &QPushButton::clicked, this, &Widget::searchAndSelcLocalSlot);
	connect(m_pLocalSearchFiltBtn, &QPushButton::clicked, this, &Widget::searchAndFilterLocalSlot);
	connect(m_pSortNBtn, &QPushButton::clicked, this, &Widget::sortNSlot);
	connect(m_pSortPBtn, &QPushButton::clicked, this, &Widget::sortPSlot);
	connect(m_pSearchBtn, &QPushButton::clicked, this, &Widget::searchSlot);

}

void Widget::initData()
{
	m_pInfoModel = new MusicInfoModel(this);
	m_pSelectModel = new QItemSelectionModel(m_pInfoModel);
	m_pFilterModel = new QSortFilterProxyModel(this);
	m_pFilterModel->setSourceModel(m_pInfoModel);
	m_pTableView->setModel(m_pFilterModel);

	m_pTableView->setSelectionModel(m_pSelectModel);
	m_pTableView->setSelectionMode(QAbstractItemView::SingleSelection);
	m_pTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	m_pTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

	m_pInfoModel->loadData();

	connect(m_pTableView, &QTableView::doubleClicked, this, &Widget::openSelect);
}

void Widget::searchOnlineSlot()
{

}

void Widget::searchAndSelcLocalSlot()
{
	QString strKeyword = m_pLocalSearchSelEdit->text();

	QItemSelection selection;
	int iFirstSelecRow = -1;

	for (int i = 0; i < m_pFilterModel->rowCount(); ++i)
	{
		QModelIndex songIndex = m_pFilterModel->index(i, 0);
		QModelIndex singerIndex = m_pFilterModel->index(i, 1);
		QModelIndex albumIndex = m_pFilterModel->index(i, 2);
		QString strSong = m_pFilterModel->data(songIndex).toString();
		QString strSinger = m_pFilterModel->data(singerIndex).toString();
		QString strAlbum = m_pFilterModel->data(albumIndex).toString();

		if (strSong.contains(strKeyword) || strSinger.contains(strKeyword)
			|| strAlbum.contains(strKeyword))
		{
			if (iFirstSelecRow == -1)
			{
				iFirstSelecRow = i;
			}

			QItemSelection rowSelc(songIndex, songIndex);
			selection.merge(rowSelc, QItemSelectionModel::Select);
		}
	}

	QItemSelectionModel* pSelcModel = m_pTableView->selectionModel();
	pSelcModel->clearSelection();
	pSelcModel->select(selection, QItemSelectionModel::Rows
		| QItemSelectionModel::Select);
	if (iFirstSelecRow != -1)
	{
		m_pTableView->scrollTo(m_pFilterModel->index(iFirstSelecRow, 0));
	}


}

void Widget::searchAndFilterLocalSlot()
{
	m_pFilterModel->setFilterKeyColumn(-1);

	QString strKeyword = m_pLocalSearchFiltEdit->text();
	m_pFilterModel->setFilterFixedString(strKeyword);
}

void Widget::sortNSlot()
{
	m_pFilterModel->sort(3, Qt::DescendingOrder);
}

void Widget::sortPSlot()
{
	m_pFilterModel->sort(3, Qt::AscendingOrder);
	
}

void Widget::searchSlot()
{
	static int i = 0;
	i++;

	QString strBegin = m_pBeginEdit->text();
	QString strEnd = m_pEndEdit->text();
	qDebug() << "strBegin = " << strBegin;
	qDebug() << "strEnd = " << strEnd;
}

void Widget::openSelect(const QModelIndex &index)
{
	if (!index.isValid())
		return;

	int nRow = index.row();
	qDebug() << "row = " << nRow;

	int nColumnCount = m_pFilterModel->columnCount();
	qDebug() << "nColumnCount = " << nColumnCount;

	qDebug() << "------------------";
	for (int i = 0; i < nColumnCount; ++i)
	{
		QModelIndex nIndex = index.sibling(nRow, i);
		QVariant qIndexData = nIndex.data();
		qDebug() << "qIndexData = " << qIndexData.toString();

		QVariant id = nIndex.data(Qt::UserRole + 1);
		if (!id.isValid())
			continue;
		qDebug() << "id = " << id;
		
	}
	qDebug() << "------------------";
}
