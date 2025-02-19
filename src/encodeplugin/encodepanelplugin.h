// Copyright (C) 2019 ~ 2020 Uniontech Software Technology Co.,Ltd
// SPDX-FileCopyrightText: 2022 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef ENCODEPANELPLUGIN_H
#define ENCODEPANELPLUGIN_H

#include "mainwindowplugininterface.h"
#include "encodepanel.h"
#include "termwidget.h"

#include <QTextCodec>

/*******************************************************************************
 1. @类名:    EncodePanelPlugin
 2. @作者:    ut001121 zhangmeng
 3. @日期:    2020-08-11
 4. @说明:
*******************************************************************************/

class MainWindow;
class TermWidget;
class EncodePanelPlugin : public MainWindowPluginInterface
{
    Q_OBJECT
public:
    explicit EncodePanelPlugin(QObject *parent = nullptr);

    /**
     * @brief 初始化编码插件
     * @author ut001121 zhangmeng
     * @param mainWindow
     */
    void initPlugin(MainWindow *mainWindow) override;
    /**
     * @brief 标题菜单
     * @author ut001121 zhangmeng
     * @param mainWindow
     * @return
     */
    QAction *titlebarMenu(MainWindow *mainWindow) override;

    /**
     * @brief 获取编码面板
     * @author ut001121 zhangmeng
     * @return
     */
    EncodePanel *getEncodePanel();
    /**
     * @brief 初始化编码面板
     * @author ut001121 zhangmeng
     */
    void initEncodePanel();
    /**
     * @brief 设置当前终端的编码
     * @author ut001121 zhangmeng
     * @param term
     */
    inline void setCurrentTermEncode(TermWidget *term);

private slots:
    void slotShowPluginChanged(const QString name);
    void slotQuakeHidePlugin();

private:
    MainWindow *m_mainWindow = nullptr;
    EncodePanel *m_encodePanel = nullptr;
};

#endif  // THEMEPANELPLUGIN_H
