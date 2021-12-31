///////////////////////////////////////////////////////////
//  TTMediaPlayerEditDef.h
//  Created on:      21-七月-2010 15:52:03
//  Original author: yangxiaodong
///////////////////////////////////////////////////////////

#if !defined(EA_2A7585A9_05DC_6d66_81D7_9170BC5E86E7__INCLUDED_)
#define EA_2A7585A9_05DC_6d66_81D7_9170BC5E86E7__INCLUDED_


enum ADDTYPE
{
	ADD_UNKNOW			= 0,					// 未知类型 
	ADD_TITLEWORD,								// 标题字
	ADD_POLYGON,								// 多边形
	ADD_CIRCLE,									// 圆
	ADD_ANIMAL,									// 动画
	ADD_MATERIALPAN,							// 材质
	ADD_IMAGE,									// 图像
	ADD_ARTWORD,								// 艺术字
	ADD_SONG,									// 唱词
	ADD_SCROLLSCREEN,							// 滚屏
	ADD_CURVER,									// 曲线
	ADD_CLOCK,									// 时钟
};


enum MODIFYTYPE
{ 
	MODIFY_UNKNOW		= 0x00000000,			// 未知类型
	MODIFY_INDEX		= 0x00000001,			// 索引
	MODIFY_ALLINDEX		= 0x00000002,			// 所有
	MODIFY_CHANGETEXT	= 0x00000004,			// 修改文本
	MODIFY_ADDTEXT		= 0x00000008,			// 添加文本
	MODIFY_DELTEXT		= 0x00000010,			// 删除文本
	MODIFY_TIME			= 0x00000020,			// 时码
	MODIFY_COLOR		= 0x00000040,			// 颜色
	MODIFY_FONT			= 0x00000080,			// 字体
	MODIFY_POS			= 0x00000100,			// 修改位置
	MODIFY_GETINFO		= 0x80000000,			// 获取信息

};

enum MODIFYPOSTYPE
{
	MODIFY_POS_SET		= 0x00000001,			//设置位置
	MODIFY_POS_LEFT		= 0x00000002,			//移动到最左
	MODIFY_POS_TOP		= 0x00000004,			//移动到最上
	MODIFY_POS_BOTTOM	= 0x00000008,			//移动到最下
	MODIFY_POS_RIGHT	= 0x00000010,			//移动到最右
	MODIFY_POS_CENTER	= 0x00000020,			//移动到最中间
};


enum CLAPTYPE
{
	CLAP_UNKUNOW		= 0,					// 未知类型
	CLAP_BEGIN,									// 开始拍
	CLAP_STOP,									// 停止拍
	CLAP_ONE,									// 一键拍
	CLAP_NO_ONE,								// 非键拍
};

#endif // !defined(EA_2A7585A9_05DC_6d66_81D7_9170BC5E86E7__INCLUDED_)
