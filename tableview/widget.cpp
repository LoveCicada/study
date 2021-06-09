#include "widget.h"
#include <QList>

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
			info.strName = QStringLiteral("����") + QString::number(i);
			info.strSinger = QStringLiteral("�й�") + QString::number(i) + QStringLiteral("��");
			info.strAlbum = QStringLiteral("�ø���") + QString::number(i) + QStringLiteral("��");
		}
		else
		{
			info.strName = QStringLiteral("������") + QString::number(i);
			info.strSinger = QStringLiteral("���") + QString::number(i) + QStringLiteral("����");
			info.strAlbum = QStringLiteral("������") + QString::number(i) + QStringLiteral("��");
		}

		_listSongInfo.push_back(info);
	}
}

void MusicInfoModel::loadData(/*const QString& strKeyWord*/)
{
	clear();
	QStringList labels;
	labels<< QString::fromLocal8Bit("���ֱ���") 
		<< QString::fromLocal8Bit("����") 
		<< QString::fromLocal8Bit("ר��");
	setHorizontalHeaderLabels(labels);

	QList<SongInfo> listSongInfo;
	intiData(listSongInfo);

	//��ɫ
	QColor itemBackbroundDarkColor(100, 100, 100);
	//ǳɫ
	QColor itemBackbroundLightColor(121, 121, 121);
	QColor itemFontColor(255, 255, 255);

	for (SongInfo songItem : listSongInfo)
	{

		QBrush brush(itemBackbroundDarkColor);
		QList<QStandardItem*> listItems;
		QStandardItem* pTitle = new QStandardItem(songItem.strName);
		pTitle->setBackground(brush);
		QStandardItem* pSinger = new QStandardItem(songItem.strSinger);
		pSinger->setBackground(brush);
		QStandardItem* pAlbum = new QStandardItem(songItem.strAlbum);
		pAlbum->setBackground(brush);
		listItems << pTitle << pSinger << pAlbum;
		appendRow(listItems);
	}

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
	m_pNetSearchBtn->setText(QStringLiteral("��������"));
	m_pHLayoutNet->addWidget(m_pNetSearchEdit);
	m_pHLayoutNet->addWidget(m_pNetSearchBtn);

	m_pHLayoutLocalSel = new QHBoxLayout(this);
	m_pLocalSearchSelEdit = new QLineEdit();
	m_pLocalSearchSelBtn = new QPushButton();
	m_pLocalSearchSelBtn->setText(QStringLiteral("��������ѡ��"));
	m_pHLayoutLocalSel->addWidget(m_pLocalSearchSelEdit);
	m_pHLayoutLocalSel->addWidget(m_pLocalSearchSelBtn);

	m_pHLayoutLocalFilt = new QHBoxLayout(this);
	m_pLocalSearchFiltEdit = new QLineEdit();
	m_pLocalSearchFiltBtn = new QPushButton();
	m_pLocalSearchFiltBtn->setText(QStringLiteral("������������"));
	m_pHLayoutLocalFilt->addWidget(m_pLocalSearchFiltEdit);
	m_pHLayoutLocalFilt->addWidget(m_pLocalSearchFiltBtn);

	m_pVLayout->addLayout(m_pHLayoutNet);
	m_pVLayout->addLayout(m_pHLayoutLocalSel);
	m_pVLayout->addLayout(m_pHLayoutLocalFilt);

	m_pTableView = new CXETableView();
	m_pVLayout->addWidget(m_pTableView);

	connect(m_pLocalSearchSelBtn, &QPushButton::clicked, this, &Widget::searchAndSelcLocalSlot);
	connect(m_pLocalSearchFiltBtn, &QPushButton::clicked, this, &Widget::searchAndFilterLocalSlot);
}

void Widget::initData()
{
	m_pInfoModel = new MusicInfoModel(this);
	m_pFilterModel = new QSortFilterProxyModel(this);
	m_pFilterModel->setSourceModel(m_pInfoModel);
	m_pTableView->setModel(m_pFilterModel);

	m_pInfoModel->loadData();
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
