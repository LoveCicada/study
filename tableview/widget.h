#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTableView>
#include <QStandardItemModel>
#include <QItemSelectionModel>
#include <QSortFilterProxyModel>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include "CXETableView.h"

#define SONGNUM 20
#define MINSONGNUM 20

struct SongInfo
{
public:
	QString strName;
	QString strSinger;
	QString strAlbum;
	QString strDate;
};

class MusicInfoModel : public QStandardItemModel
{
	Q_OBJECT

public:
	MusicInfoModel(QObject *parent = Q_NULLPTR);

	void intiData(QList<SongInfo>& _listSongInfo);
	void loadData(/*const QString& strKeyWord*/);
};

class CXESortFilterProxyModel : public QSortFilterProxyModel
{
	Q_OBJECT

public:
	CXESortFilterProxyModel(QObject *parent = Q_NULLPTR);

	void sort(int column, Qt::SortOrder order);
};




class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

	void initCtrl();
	void initData();

private slots:
	void searchOnlineSlot();            //网上搜索
	void searchAndSelcLocalSlot();      //本地搜索并选择
	void searchAndFilterLocalSlot();	//本地搜索并过滤
	void sortNSlot();
	void sortPSlot();
	void searchSlot();
	void openSelect(const QModelIndex &index);
private:
	//ctrl
	QHBoxLayout* m_pHLayoutNet;
	QLineEdit* m_pNetSearchEdit;
	QPushButton* m_pNetSearchBtn;

	QHBoxLayout* m_pHLayoutLocalSel;
	QLineEdit* m_pLocalSearchSelEdit;
	QPushButton* m_pLocalSearchSelBtn;

	QHBoxLayout* m_pHLayoutLocalFilt;
	QLineEdit* m_pLocalSearchFiltEdit;
	QPushButton* m_pLocalSearchFiltBtn;
	
	//逆序
	QHBoxLayout* m_pHLayoutNSort;
	QLineEdit* m_pSortNEdit;
	QPushButton* m_pSortNBtn;

	//正序
	QHBoxLayout* m_pHLayoutPSort;
	QLineEdit* m_pSortPEdit;
	QPushButton* m_pSortPBtn;

	QHBoxLayout* m_pHLayoutPSearch;
	QLineEdit* m_pBeginEdit;
	QLabel* m_pLable;
	QLineEdit* m_pEndEdit;
	QPushButton* m_pSearchBtn;

	QVBoxLayout* m_pVLayout;
	CXETableView* m_pTableView;


	//data
	QItemSelectionModel* m_pSelectModel;
	MusicInfoModel* m_pInfoModel;
	QSortFilterProxyModel* m_pFilterModel;
};

#endif // WIDGET_H
